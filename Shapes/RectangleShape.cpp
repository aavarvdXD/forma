#include "RectangleShape.h"
#include <QPainter>

RectangleShape::RectangleShape(const QRectF &rect, QGraphicsItem *parent)
    : Shape(parent)
{
    setRect(rect);
}

void RectangleShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setRenderHint(QPainter::Antialiasing, true);

    QPen pen(m_stroke, m_strokeWidth);
    painter->setPen(pen);
    painter->setBrush(m_fill);
    painter->drawRect(m_rect);

    if (isSelected()) {
        QPen selectionPen(Qt::DashLine);
        selectionPen.setColor(QColor(0, 120, 255));
        painter->setBrush(Qt::NoBrush);
        painter->setPen(selectionPen);
        painter->drawRect(boundingRect());
    }
}

QPainterPath RectangleShape::toPath() const {
    QPainterPath path;
    path.addRect(m_rect);
    return path;
}