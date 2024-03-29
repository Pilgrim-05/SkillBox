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
    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString filePath = nullptr;

    QImage blurImage(QImage src, int blurRadius);
};
#endif // MAINWINDOW_H
