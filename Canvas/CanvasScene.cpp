#include "CanvasScene.h"
#include "../Tools/Tool.h"

CanvasScene::CanvasScene(QUndoStack *undoStack, QObject *parent)
    : QGraphicsScene(parent)
    , m_undoStack(undoStack)
{
    setSceneRect(-2000, -2000, 4000, 4000);
}

CanvasScene::~CanvasScene() = default;

void CanvasScene::setActiveTool(std::unique_ptr<Tool> tool) {
    m_activeTool = std::move(tool);
}

void CanvasScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (m_activeTool && m_activeTool->mousePressEvent(event, this)) return;
    QGraphicsScene::mousePressEvent(event);
}

void CanvasScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (m_activeTool && m_activeTool->mouseMoveEvent(event, this)) return;
    QGraphicsScene::mouseMoveEvent(event);
}

void CanvasScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (m_activeTool && m_activeTool->mouseReleaseEvent(event, this)) return;
    QGraphicsScene::mouseReleaseEvent(event);
}