#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "field.h"
#include <QPaintEvent>
#include <QTimer>
#include "polygon.h"
class Widget : public QWidget
{
    Q_OBJECT
protected:
    QTimer * _ticTimer;
public:
    Widget(int width, int height,QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *event);
    Field mField;
    Polygon mPolygon = Polygon(QList<QPointF>({QPointF(40,40),QPointF(100,40),QPointF(120,120),QPointF(200,200),QPointF(40,130)}));

public slots:
    void everyTic();


};
#endif // WIDGET_H
