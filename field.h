#ifndef FIELD_H
#define FIELD_H
//#include "item.h"
#include "physicsengine.h"
#include <QPainter>
#include <QObject>
class Field : public QObject
{
    Q_OBJECT
protected:

    //QList<Item*> _items;
    //bool isIntersectsAny(QList<Item *> &list, Item *item);
public:
    Field(int width, int height);
    void draw(QPainter &painter);
    const int mWidth;
    const int mHeight;
    PhysicsEngine _engine;
    //void addItem(Item *item);
public slots:
    void onTic();

};

#endif // FIELD_H
