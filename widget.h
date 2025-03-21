#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "field.h"
#include <QPaintEvent>
#include <QTimer>
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

public slots:
    void everyTic();


};
#endif // WIDGET_H
