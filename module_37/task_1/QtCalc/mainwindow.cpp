#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <iostream>

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

void MainWindow::on_pbAdd_clicked()
{
    bool isNum_1;
    bool isNum_2;
    double num_1 = ui->lineEdit->text().toDouble(&isNum_1);
    double num_2 = ui->lineEdit_2->text().toDouble(&isNum_2);

    if(isNum_1 && isNum_2)
        ui->lineEditResult->setText(QString::number(num_1 + num_2));
    else
        ui->lineEditResult->setText("ERROR");
}

void MainWindow::on_pbSub_clicked()
{
    bool isNum_1;
    bool isNum_2;
    double num_1 = ui->lineEdit->text().toDouble(&isNum_1);
    double num_2 = ui->lineEdit_2->text().toDouble(&isNum_2);

    if(isNum_1 && isNum_2)
        ui->lineEditResult->setText(QString::number(num_1 - num_2));
    else
        ui->lineEditResult->setText("ERROR");
}

void MainWindow::on_pbMult_clicked()
{
    bool isNum_1;
    bool isNum_2;
    double num_1 = ui->lineEdit->text().toDouble(&isNum_1);
    double num_2 = ui->lineEdit_2->text().toDouble(&isNum_2);

    if(isNum_1 && isNum_2)
        ui->lineEditResult->setText(QString::number(num_1 * num_2));
    else
        ui->lineEditResult->setText("ERROR");
}

void MainWindow::on_pbDiv_clicked()
{
    bool isNum_1;
    bool isNum_2;
    double num_1 = ui->lineEdit->text().toDouble(&isNum_1);
    double num_2 = ui->lineEdit_2->text().toDouble(&isNum_2);

    if(isNum_1 && isNum_2 && num_2)
        ui->lineEditResult->setText(QString::number(num_1 / num_2));
    else
        ui->lineEditResult->setText("ERROR");
}

