#ifndef KINSTRUCTMENTPANEL_H
#define KINSTRUCTMENTPANEL_H

#include <QOpenGLWidget> //Qt5.4之前使用QGLWidget 之后使用QOpenGLWidget
#include <QPaintEvent>
#include <QPen>
class KInstructmentPanel : QOpenGLWidget
{
public:
    KInstructmentPanel();

private:
    void KInit();

    QBrush background;
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
    int elapsed = 0.0;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;  //重载虚函数
};

#endif // KINSTRUCTMENTPANEL_H
