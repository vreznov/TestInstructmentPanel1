#ifndef KINSTRUCTMENTPANEL_H
#define KINSTRUCTMENTPANEL_H

#include <QOpenGLWidget> //Qt5.4之前使用QGLWidget 之后使用QOpenGLWidget
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
class KInstructmentPanel : public QOpenGLWidget
{
public:
    KInstructmentPanel(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());

    int elapsed = -0;
private:
    void KInit();

    QBrush background;
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;  //重载虚函数
};

#endif // KINSTRUCTMENTPANEL_H
