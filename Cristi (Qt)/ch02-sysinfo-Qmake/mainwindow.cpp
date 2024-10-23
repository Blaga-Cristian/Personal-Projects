#include "mainwindow.h"
#include "qlayout.h"
#include "sysinfo.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mCpuWidget(this)
    , mMemoryWidget(this)
{
    ui->setupUi(this);
    SysInfo::instance().init();

    if(!ui->centralwidget->layout()){
        QHBoxLayout* layout = new QHBoxLayout(ui->centralwidget);
        ui->centralwidget->setLayout(layout);
    }

    ui->centralwidget->layout()->addWidget(&mCpuWidget);
    ui->centralwidget->layout()->addWidget(&mMemoryWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
