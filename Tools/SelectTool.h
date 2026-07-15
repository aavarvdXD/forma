#pragma once

#include "Tool.h"

class SelectTool : public Tool {
    public:
        bool mousePressEvent(QGraphicsSceneMouseEvent *event, CanvasScene *scene) override;
        bool mouseMoveEvent(QGraphicsSceneMouseEvent *event, CanvasScene *scene) override;
        bool mouseReleaseEvent(QGraphicsSceneMouseEvent *event, CanvasScene *scene) override;

        QString name() const override { return QStringLiteral("Select"); }
};