#pragma once

#include <QUndoCommand>

class CanvasScene;
class Shape;

class AddShapeCommand : public QUndoCommand {
    public:
        AddShapeCommand(CanvasScene* scene, Shape* shape, const QUndoCommand* parent = nullptr);
        ~AddShapeCommand() override;

        void undo() override;
        void redo() override;

    private:
        CanvasScene* m_scene;
        Shape* m_shape;
        bool m_inScene{false};
};