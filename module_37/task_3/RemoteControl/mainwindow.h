#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pbUpVal_clicked();

    void on_pbDownVal_clicked();

    void on_pbOnOff_clicked();

    void on_pbMute_clicked();

    void on_pbPreCh_clicked();

    void on_pbPosCh_clicked();

    void on_pb_1_clicked();

    void on_pb_2_clicked();

    void on_pb_3_clicked();

    void on_pb_4_clicked();

    void on_pb_5_clicked();

    void on_pb_6_clicked();

    void on_pb_7_clicked();

    void on_pb_8_clicked();

    void on_pb_9_clicked();

    void on_pb_0_clicked();

private:
    Ui::MainWindow *ui;
    int valume = 40;
    int chanel = 1;
    QString mute = "Mute";
    bool onOff = false;

    void changeChanal(const int ch);
};
#endif // MAINWINDOW_H
