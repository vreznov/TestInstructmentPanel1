﻿#include "kinstructmentpanel.h"

KInstructmentPanel::KInstructmentPanel()
{
    KInit();
}

void KInstructmentPanel::KInit()
{
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    background = QBrush(QColor(64, 32, 64));
    circleBrush = QBrush(gradient);
    circlePen = QPen(Qt::black);
    circlePen.setWidth(1);
    textPen = QPen(Qt::white);
    textFont.setPixelSize(50);
}

void KInstructmentPanel::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(event->rect(), background);
    painter.translate(100, 100);
//! [1]
    elapsed++;
//! [2]
    painter.save();
    painter.setBrush(circleBrush);
    painter.setPen(circlePen);
    painter.rotate(elapsed * 0.030);

    qreal r = elapsed / 1000.0;
    int n = 30;
    for (int i = 0; i < n; ++i) {
        painter.rotate(30);
        qreal factor = (i + r) / n;
        qreal radius = 0 + 120.0 * factor;
        qreal circleRadius = 1 + factor * 20;
        painter.drawEllipse(QRectF(radius, -circleRadius,
                                    circleRadius * 2, circleRadius * 2));
    }
    painter.restore();
//! [2]

//! [3]
    painter.setPen(textPen);
    painter.setFont(textFont);
    painter.drawText(QRect(-50, -50, 100, 100), Qt::AlignCenter, QStringLiteral("Qt"));

    painter.end();
}

