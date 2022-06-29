#include <QApplication>
#include <QSlider>
#include <QPixmap>
#include <QVBoxLayout>
#include <QPainter>
#include <QPaintEvent>

class MyCircle : public QWidget
{
public:
    MyCircle() = default;
    MyCircle(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize minimumSizeHint() const override;

    void setYellow();
    void setRed();
    void setGreen();

private:
    QPixmap mCurrentCircle;
    QPixmap mYellowCircle;
    QPixmap mGreenCircle;
    QPixmap mRedCircle;
};

MyCircle::MyCircle(QWidget *parent)
{
  setParent(parent);
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  mRedCircle = QPixmap("../img/red.png");
  mYellowCircle = QPixmap("../img/yellow.png");
  mGreenCircle = QPixmap("../img/green.png");
  mCurrentCircle = mRedCircle;
  setGeometry(mCurrentCircle.rect());

}

void MyCircle::setYellow() {
   mCurrentCircle = mYellowCircle;
   update();
}

void MyCircle::setRed() {
   mCurrentCircle = mRedCircle;
   update();
}

void MyCircle::setGreen() {
   mCurrentCircle = mGreenCircle;
   update();
}

QSize MyCircle::minimumSizeHint() const
{
    return QSize(200, 200);
}

void MyCircle::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentCircle);
}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget *win = new QWidget;
    QVBoxLayout *VLayout = new QVBoxLayout(win);
    MyCircle *crc = new MyCircle(win);
    QSlider *sl = new QSlider(Qt::Horizontal, win);

    win->setFixedSize(200, 230);

    VLayout->addWidget(crc);
    VLayout->addWidget(sl);

    sl->setValue(0);
    sl->setMinimum(0);
    sl->setMaximum(100);

    win->show();

    QObject::connect(sl, &QSlider::valueChanged, [sl, crc](int newValue)
    {
        if(newValue >= 0 && newValue < 33)
            crc->setRed();
        if(newValue >= 33 && newValue < 66)
            crc->setYellow();
        if(newValue >= 66 && newValue < 101)
            crc->setGreen();
    });

    app.exec();

    return 0;
}
