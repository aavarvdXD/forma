#include "AddShapeCommand.h"
#include "../Canvas/CanvasScene.h"
#include "../Shapes/Shape.h"

AddShapeCommand::AddShapeCommand(CanvasScene *scene, Shape *shape, const QUndoCommand *parent)
    : QUndoCommand(parent)
    , m_scene(scene)
    , m_shape(shape)
{
    setText(QObject::tr("Add %1").arg(shape->typeName()));
}

AddShapeCommand::~AddShapeCommand() {
    if (!m_inScene) delete m_shape;
}

void AddShapeCommand::undo() {
    m_scene->removeItem(m_shape);
    m_inScene = false;
}

void AddShapeCommand::redo() {
    m_scene->addItem(m_shape);
    m_inScene = true;
}