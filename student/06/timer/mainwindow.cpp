#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    seconds_(0),
    minutes_(0)
{
    ui->setupUi(this);
    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &MainWindow::updateTime);
    ui->lcdNumberSec->display(seconds_);
    ui->lcdNumberMin->display(minutes_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    if (!timer_->isActive()) {
        timer_->start(1000);
    }
}

void MainWindow::on_stopButton_clicked()
{
    if (timer_->isActive()) {
        timer_->stop();
    }
}

void MainWindow::on_resetButton_clicked()
{
    timer_->stop();
    seconds_ = 0;
    minutes_ = 0;
    ui->lcdNumberSec->display(seconds_);
    ui->lcdNumberMin->display(minutes_);
}

void MainWindow::updateTime()
{
    ++seconds_;
    if (seconds_ >= 60) {
        seconds_ = 0;
        ++minutes_;
    }

    ui->lcdNumberSec->display(seconds_);
    ui->lcdNumberMin->display(minutes_);
}
