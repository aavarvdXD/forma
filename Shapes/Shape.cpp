#include "Shape.h"

Shape::Shape(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

void Shape::setFillColor(const QColor &color) {
    prepareGeometryChange();
    m_fill = color;
    update();
}

void Shape::setStrokeColor(const QColor &color) {
    m_stroke = color;
    update();
}

void Shape::setStrokeWidth(qreal width) {
    prepareGeometryChange();
    m_strokeWidth = width;
    update();
}

void Shape::setRect(const QRectF &rect) {
    prepareGeometryChange();
    m_rect = rect.normalized();
    update();
}

QRectF Shape::boundingRect() const {
    const qreal half = m_strokeWidth / 2.0 + 1.0;
    return m_rect.adjusted(-half, -half, half, half);
}

QPainterPath Shape::shape() const {
    QPainterPath path;
    path.addRect(m_rect);
    return path;
}