#include <QApplication>
#include "redbutton.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RedButton redBtn(nullptr);
    redBtn.setFixedSize(400, 400);
    redBtn.move(750, 350);

    redBtn.show();

    return a.exec();
}
