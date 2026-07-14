#pragma once

#include <QGraphicsItem>
#include <QColor>
#include <QPainterPath>

class Shape : public QGraphicsItem {
    public:
        explicit Shape(QGraphicsItem* parent = nullptr);
        ~Shape() override = default;

        void setFillColor(const QColor& color);
        QColor fillColor() const { return m_fill; }

        void setStrokeColor(const QColor& color);
        QColor strokeColor() const { return m_stroke; }

        void setStrokeWidth(qreal width);
        qreal strokeWidth() const { return m_strokeWidth; }

        void setRect(const QRectF& rect);
        QRectF rect() const { return m_rect; }

        QRectF boundingRect() const override;
        QPainterPath shape() const override;

        virtual QPainterPath toPath() const = 0;

        virtual QString typeName() const = 0;

    protected:
        QRectF m_rect;
        QColor m_fill{Qt::white};
        QColor m_stroke{Qt::black};
        qreal m_strokeWidth{1.5};
};