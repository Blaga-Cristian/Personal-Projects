#ifndef SYSINFOWIDGET_H
#define SYSINFOWIDGET_H

#include "QtCharts/qchartview.h"
#include <QWidget>
#include <QTimer>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>

class SysInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SysInfoWidget(QWidget *parent = nullptr,
                           int startDelayMs = 500,
                           int updateSeriesDelayMs = 500);

protected:
    QChartView& chartView();

protected slots:
    virtual void updateSeries() = 0;

private:
    QTimer mRefreshTimer;
    QChartView mChartView;
};

#endif // SYSINFOWIDGET_H
