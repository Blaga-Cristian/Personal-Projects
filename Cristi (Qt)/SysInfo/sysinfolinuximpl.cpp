#include "sysinfolinuximpl.h"

#include <QProcess>
#include <QFile>


SysInfoLinuxImpl::SysInfoLinuxImpl() :
    SysInfo()
{}

void SysInfoLinuxImpl::init()
{
    mCpuLoadLastValues = cpuRawData();
}

double SysInfoLinuxImpl::memoryUsed()
{
    QProcess p;
    p.start("awk", QStringList() << "/MemAvailable/ { print $2 }" << "proc/meminfo");
    p.waitForFinished();
    qulonglong memoryAvailable = p.readAllStandardOutput().toLong();
    p.start("awk", QStringList() << "/MemFree/ {print $2 }" << "proc/meminfo");
    qulonglong memoryFree = p.readAllStandardOutput().toLong();
    double percent = (double)memoryFree /
                     (double)memoryAvailable * 100.0;
    return qBound(0.0, percent, 100.0);
}

QVector<qulonglong> SysInfoLinuxImpl::cpuRawData()
{
    QFile file("/proc/stat");
    file.open(QIODevice::ReadOnly);

    QByteArray line = file.readLine();
    file.close();
    qulonglong totalUser = 0, totalUserNice = 0,
        totalSystem = 0, totalIdle = 0;
    std::scanf(line.data(), "cpu %llu %llu %llu %llu",
                &totalUser, &totalUserNice,
                &totalSystem, &totalIdle);

    return {totalUser, totalUserNice, totalSystem, totalIdle};
}

double SysInfoLinuxImpl::cpuLoadAverage()
{
    QVector<qulonglong> firstSample = mCpuLoadLastValues;
    QVector<qulonglong> secondSample = cpuRawData();
    mCpuLoadLastValues = secondSample;

    double overall = (secondSample[0] - firstSample[0]) +
                     (secondSample[1] - firstSample[1]) +
                     (secondSample[2] - firstSample[2]);

    double total = overall + (secondSample[3] - firstSample[3]);

    double percent = (overall / total) * 100.0;

    return qBound(0.0, percent, 100.0);
}
