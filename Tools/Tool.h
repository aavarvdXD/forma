#pragma once

#include <QString>

#include "Tool.h"

class QGraphicsSceneMouseEvent;

class CanvasScene;

class Tool {
    public:
        virtual ~Tool() = default;

        virtual bool mousePressEvent(QGraphicsSceneMouseEvent* event, CanvasScene* scene) = 0;
        virtual bool mouseMoveEvent(QGraphicsSceneMouseEvent* event, CanvasScene* scene) = 0;
        virtual bool mouseReleaseEvent(QGraphicsSceneMouseEvent* event, CanvasScene* scene) = 0;

        virtual QString name() const = 0;
};