#ifndef REDBUTTON_H
#define REDBUTTON_H

#include <QPushButton>
#include <QPixmap>

class RedButton : public QPushButton
{
public:
    RedButton() = default;
    RedButton(QPushButton *parent);
    ~RedButton(){};
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;


public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
};

#endif // REDBUTTON_H
