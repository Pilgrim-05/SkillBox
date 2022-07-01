#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbAdd_clicked();

    void on_pbSub_clicked();

    void on_pbMult_clicked();

    void on_pbDiv_clicked();

private:
    Ui::MainWindow *ui;
    QLineEdit *lineEdit = nullptr;
    QLineEdit *lineEdit_2 = nullptr;
    QLineEdit *lineEditResult = nullptr;
};
#endif // MAINWINDOW_H
