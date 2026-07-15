#pragma once

#include <QGraphicsScene>
#include <memory>

class QUndoStack;
class Tool;

class CanvasScene : public QGraphicsScene {
    Q_OBJECT
    public:
        explicit CanvasScene(QUndoStack* undoStack, QObject* parent = nullptr);
        ~CanvasScene() override;
        void setActiveTool(std::unique_ptr<Tool> tool);
        Tool* activeTool() const { return m_activeTool.get(); }

        QUndoStack* undoStack() const { return m_undoStack; }

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
        void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
        void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

    private:
        std::unique_ptr<Tool> m_activeTool;
        QUndoStack* m_undoStack;
};