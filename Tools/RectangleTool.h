#pragma once

#include "Tool.h"
#include <QPointF>

class rectangleShape;

class RectangleTool : public Tool {
    public:
        bool mousePressEvent(QGraphicsSceneMouseEvent *event, CanvasScene *scene) override;
        bool mouseMoveEvent(QGraphicsSceneMouseEvent *event, CanvasScene *scene) override;
        bool mouseReleaseEvent(QGraphicsSceneMouseEvent *event, CanvasScene *scene) override;

        QString name() const override { return QStringLiteral("Rectangle"); }

    private:
};