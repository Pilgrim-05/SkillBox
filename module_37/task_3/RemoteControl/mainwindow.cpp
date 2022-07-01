#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lblVal->setText(QString::number(valume) + "%");
    ui->lblCh->setText(QString::number(chanel));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbUpVal_clicked()
{
    if(onOff){
        if(valume < 100)
            valume += 10;
        ui->lblVal->setText(QString::number(valume) + "%");
    }
}


void MainWindow::on_pbDownVal_clicked()
{
    if(onOff){
        if(valume > 0)
        {
            valume -= 10;
            ui->lblVal->setText(QString::number(valume) + "%");
        }
        if(valume <= 0)
            ui->lblVal->setText(mute);
    }

}

void MainWindow::on_pbOnOff_clicked()
{
    if(onOff)
    {
        onOff = false;
        ui->lblOnOff->setText("Off");
    }else
    {
        onOff = true;
        ui->lblOnOff->setText("On");
    }

}

void MainWindow::on_pbMute_clicked()
{
    if(onOff)
    {
        if(ui->lblVal->text() != mute)
            ui->lblVal->setText(mute);
        else
            ui->lblVal->setText(QString::number(valume) + "%");
    }
}


void MainWindow::on_pbPreCh_clicked()
{
    if(onOff)
    {
        if(chanel >= 50)
            chanel = 1;
        else
            ++chanel;
        ui->lblCh->setText(QString::number(chanel));
    }
}


void MainWindow::on_pbPosCh_clicked()
{
    if(onOff)
    {
        if(chanel <= 1)
            chanel = 50;
        else
            --chanel;
        ui->lblCh->setText(QString::number(chanel));
    }
}

void MainWindow::on_pb_1_clicked()
{
    changeChanal(1);
}


void MainWindow::on_pb_2_clicked()
{
    changeChanal(2);
}


void MainWindow::on_pb_3_clicked()
{
    changeChanal(3);
}


void MainWindow::on_pb_4_clicked()
{
    changeChanal(4);
}


void MainWindow::on_pb_5_clicked()
{
    changeChanal(5);
}

void MainWindow::on_pb_6_clicked()
{
    changeChanal(6);
}

void MainWindow::on_pb_7_clicked()
{
    changeChanal(7);
}

void MainWindow::on_pb_8_clicked()
{
    changeChanal(8);
}

void MainWindow::on_pb_9_clicked()
{
    changeChanal(9);
}

void MainWindow::on_pb_0_clicked()
{
    changeChanal(0);
}

void MainWindow::changeChanal(const int ch)
{
    QString strTmp = QString::number(chanel) + QString::number(ch);
    if(strTmp.toInt() <= 50)
    {
        chanel = strTmp.toInt();
    }else if(ch != 0)
        chanel = ch;
    onOff = true;
    ui->lblOnOff->setText("On");
    ui->lblCh->setText(QString::number(chanel));
}



