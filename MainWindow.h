#pragma once

#include <QMainWindow>

class QUndoStack;
class CanvasScene;
class CanvasView;

class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        explicit MainWindow(QWidget* parent = nullptr);

    private slots:
        void activateSelectTool();
        void activateRectangleTool();
        void activateEllipseTool();

    private:
        void buildToolBar();
        void buildMenus();

        QUndoStack* m_undoStack;
        CanvasScene* m_scene;
        CanvasView* m_view;
};