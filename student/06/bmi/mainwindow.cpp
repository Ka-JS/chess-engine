#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_countButton_clicked()
{
    bool weightOk;
    bool heightOk;

    QString weightText = ui->weightLineEdit->text();
    QString heightText = ui->heightLineEdit->text();

    double weight = weightText.toDouble(&weightOk);
    double heightCm = heightText.toDouble(&heightOk);

    if (!weightOk or !heightOk or heightCm == 0) {
        ui->resultLabel->setText("Cannot count");
        ui->infoTextBrowser->clear();
        return;
    }

    double height = heightCm / 100.0;
    double bmi = weight / (height * height);

    ui->resultLabel->setText(QString::number(bmi, 'f', 4));

    QString info;
    if (bmi < 18.5)
        info = "Underweight";
    else if (bmi > 25.0)
        info = "Overweight";
    else
        info = "Normal range";

    ui->infoTextBrowser->setText(info);
}

