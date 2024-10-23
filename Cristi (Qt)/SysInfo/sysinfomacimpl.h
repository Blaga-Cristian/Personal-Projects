#ifndef SYSINFOMACIMPL_H
#define SYSINFOMACIMPL_H

#include "sysinfo.h"

class SysInfoMacImpl : public SysInfo
{
public:
    SysInfoMacImpl();

    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;
};

#endif // SYSINFOMACIMPL_H
