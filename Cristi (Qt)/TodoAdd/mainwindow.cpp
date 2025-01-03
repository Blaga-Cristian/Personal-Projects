#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"
#include "QinputDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mTasks()
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);

    updateStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task Name"),
                                         QLineEdit::Normal,
                                         tr("Untitled text"),
                                         &ok);
    if(ok && !name.isEmpty())
    {
        qDebug() << "User has successfully added a task!";
        Task* task = new Task(name);
        connect(task, &Task::removed,
                this, &MainWindow::removeTask);
        connect(task, &Task::statusChanged,
                this, &MainWindow::taskStatusChanged);
        mTasks.append(task);
        ui->tasksLayout->addWidget(task);
        updateStatus();
    }
}

void MainWindow::removeTask(Task* task)
{
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->setParent(0);
    delete task;
    updateStatus();
}

void MainWindow::taskStatusChanged(Task* /*task*/)
{
    updateStatus();
}

void MainWindow::updateStatus()
{
    int completedCount = 0;
    for(auto t : mTasks)
        completedCount += t->isCompleted();
    int todoCount = (int)mTasks.size() - completedCount;

    ui->statusLabel->setText(
        QString("Status: %1 todo / %2 completed")
            .arg(todoCount).arg(completedCount));
}
