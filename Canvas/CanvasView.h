#pragma once

#include <QGraphicsView>

class CanvasView : public QGraphicsView {
    Q_OBJECT
    public:
        explicit CanvasView(QGraphicsScene* scene, QWidget* parent = nullptr);

    private:
        qreal m_zoom{1.0};

    protected:
        void wheelEvent(QWheelEvent* event) override;
};