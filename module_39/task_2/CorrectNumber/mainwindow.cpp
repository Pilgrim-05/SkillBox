#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText)
    {
        QRegularExpression exp("^(\\+)+([0-9]){11}$");
        if(exp.match(currentText).hasMatch())
            setOkNumber();
        else
            setNonOkNumber();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkNumber()
{
    ui->label->setText("Correct");
    ui->label->setStyleSheet("QLabel {color : green;}");
}

void MainWindow::setNonOkNumber()
{
    ui->label->setText("InCorrect");
    ui->label->setStyleSheet("QLabel {color : red;}");
}
