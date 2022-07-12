#include "redbutton.h"

#include <QTimer>
#include <QMediaPlayer>
#include <QPainter>
#include <QPaintEvent>

RedButton::RedButton(QPushButton *parent)
{
    setParent(parent);
    setToolTip("Стоп");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonDownPixmap = QPixmap("../img/btn_2.png");
    mButtonUpPixmap = QPixmap("../img/btn_1.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    auto *bip = new QMediaPlayer(this);


    QObject::connect(this, &QPushButton::clicked, [bip]()
    {
        bip->setMedia(QUrl::fromLocalFile("../audio/duck.mp3"));
        bip->setVolume(80);
        bip->play();
    });

    QObject::connect(this, &QPushButton::clicked, this, &RedButton::setDown);

}

void RedButton::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize RedButton::sizeHint() const
{
    return QSize(400, 400);
}

QSize RedButton::minimumSizeHint() const
{
    return sizeHint();
}

void RedButton::keyPressEvent(QKeyEvent *e)
{
    setDown();
}

void RedButton::setUp()
{
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}

void RedButton::setDown()
{
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(100, this, &RedButton::setUp);
}
