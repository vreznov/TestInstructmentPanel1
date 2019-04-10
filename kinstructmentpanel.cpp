#include "kinstructmentpanel.h"

KInstructmentPanel::KInstructmentPanel(QWidget *parent, Qt::WindowFlags f ) : QOpenGLWidget(parent, f)
{
    KInit();
}

void KInstructmentPanel::KInit()
{
    //https://www.cnblogs.com/lifexy/p/9238878.html
    QConicalGradient Conical(0,0,0);    //设置点在中心,角度为30
    Conical.setColorAt(0,Qt::red);
    Conical.setColorAt(0.3,Qt::blue);
    Conical.setColorAt(1,Qt::green);

    background = QBrush(QColor(125, 125, 125));
    circleBrush = QBrush(Conical);
//    circlePen = QPen(Qt::red);
//    circlePen.setWidth(10);
    circlePen = QPen(circleBrush, 10);
    circlePen.setWidth(10);
    textPen = QPen(Qt::white);
    textFont.setPixelSize(20);
}

void KInstructmentPanel::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(event->rect(), background);
    painter.translate(100, 100);
//! [1]

//! [2]
    painter.save();
    painter.setBrush(circleBrush);
    painter.setPen(circlePen);
    painter.rotate(90);
    // 画背景
    painter.drawArc(-80, -80, 160, 160, 30 * 16, 300 * 16);

    painter.restore();
//! [2] 文字
    QRectF rect(-50, 60, 100, 20);
    painter.drawRect(rect);
    painter.setPen(textPen);
    painter.setFont(textFont);
    painter.drawText(rect, Qt::AlignCenter, QStringLiteral("Km /h"));

//! [3] 刻度

//! [4] 指针
    //判断角度大小，限制在一定的角度范围内
//    if(elapsed < -60) elapsed = -60;
//    if(elapsed > 300) elapsed = 300;
    //旋转指针
    painter.rotate(elapsed);
    QPainterPath path;
    path.moveTo(0, -20);
    path.lineTo(-10, 0);
    path.lineTo(0, 60);
    path.lineTo(10, 0);
    path.lineTo(0, -20);
    painter.drawPath(path);

    painter.end();
}

