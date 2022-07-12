#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QPainter>


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

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->label->setPixmap(QPixmap::fromImage(blurImage(QImage(filePath), value).scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio)));
}

void MainWindow::on_pushButton_clicked()
{
    filePath = QFileDialog::getOpenFileName(nullptr, "Open jpg File", "./", "jpg files(*.jpg)");

    ui->label->setPixmap(QPixmap::fromImage(QImage(filePath).scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio)));
}

QImage MainWindow::blurImage(QImage src, int blurRadius)
{
    if(src.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(src));
    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(src.size(), QImage::Format::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(),
                 QRectF(0, 0, src.width(), src.height()));

    return result;
}
