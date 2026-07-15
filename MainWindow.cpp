#include "MainWindow.h"
#include "Canvas/CanvasScene.h"
#include "Tools/SelectTool.h"
#include "Tools/RectangleTool.h"
#include "Tools/EllipseTool.h"
#include "Canvas/CanvasView.h"

#include <QUndoStack>
#include <QToolBar>
#include <QMenuBar>
#include <QAction>
#include <QActionGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_undoStack = new QUndoStack(this);
    m_scene = new CanvasScene(m_undoStack, this);
    m_scene->setActiveTool(std::make_unique<SelectTool>());

    m_view = new CanvasView(m_scene, this);
    setCentralWidget(m_view);

    setWindowTitle(tr("Forma"));
    resize(1200, 800);

    buildToolBar();
    buildMenus();
}

void MainWindow::buildToolBar() {
    auto* toolBar = addToolBar(tr("Tools"));
    toolBar->setMovable(false);

    auto* toolGroup = new QActionGroup(this);
    toolGroup->setExclusive(true);

    auto* selectAction = toolBar->addAction(tr("Select"));
    selectAction->setCheckable(true);
    selectAction->setChecked(true);
    toolGroup->addAction(selectAction);
    connect(selectAction, &QAction::triggered, this, &MainWindow::activateSelectTool);

    auto* rectAction = toolBar->addAction(tr("Rectangle"));
    rectAction->setCheckable(true);
    toolGroup->addAction(rectAction);
    connect(rectAction, &QAction::triggered, this, &MainWindow::activateRectangleTool);

    auto* ellipseAction = toolBar->addAction(tr("Ellipse"));
    ellipseAction->setCheckable(true);
    toolGroup->addAction(ellipseAction);
    connect(ellipseAction, &QAction::triggered, this, &MainWindow::activateEllipseTool);

    toolBar->addSeparator();

    QAction* undoAction = m_undoStack->createUndoAction(this, tr("Undo"));
    undoAction->setShortcut(QKeySequence::Undo);
    toolBar->addAction(undoAction);

    QAction* redoAction = m_undoStack->createRedoAction(this, tr("Redo"));
    redoAction->setShortcut(QKeySequence::Redo);
    toolBar->addAction(redoAction);
}

void MainWindow::buildMenus() {
    auto* editMenu = menuBar()->addMenu(tr("&Edit"));

    QAction* undoAction = m_undoStack->createUndoAction(this, tr("Undo"));
    undoAction->setShortcut(QKeySequence::Undo);
    editMenu->addAction(undoAction);

    QAction* redoAction = m_undoStack->createRedoAction(this, tr("Redo"));
    redoAction->setShortcut(QKeySequence::Redo);
    editMenu->addAction(redoAction);
}

void MainWindow::activateSelectTool() {
    m_scene->setActiveTool(std::make_unique<SelectTool>());
}

void MainWindow::activateRectangleTool() {
    m_scene->setActiveTool(std::make_unique<RectangleTool>());
}

void MainWindow::activateEllipseTool() {
    m_scene->setActiveTool(std::make_unique<EllipseTool>());
}