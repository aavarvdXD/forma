#pragma once
#include "Shape.h"

class EllipseShape : public Shape {
    public:
        explicit EllipseShape(const QRectF& rect, QGraphicsItem* parent = nullptr);

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

        QPainterPath toPath() const override;

        QString typeName() const override { return QStringLiteral("Ellipse"); }
};