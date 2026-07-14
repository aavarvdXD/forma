#include "EllipseShape.h"
#include <QPainter>

EllipseShape::EllipseShape(const QRectF &rect, QGraphicsItem *parent)
    : Shape(parent)
{
    setRect(rect);
}

void EllipseShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setRenderHint(QPainter::Antialiasing, true);

    QPen pen(m_stroke, m_strokeWidth);
    painter->setPen(pen);
    painter->setBrush(m_fill);
    painter->drawEllipse(m_rect);

    if (isSelected()) {
        QPen selectionPen(Qt::DashLine);
        selectionPen.setColor(QColor(0, 120, 255));
        painter->setBrush(Qt::NoBrush);
        painter->setPen(selectionPen);
        painter->drawEllipse(boundingRect());
    }
}

QPainterPath EllipseShape::toPath() const {
    QPainterPath path;
    path.addEllipse(m_rect);
    return path;
}