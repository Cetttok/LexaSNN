#include "field.h"
#include <QDebug>
const QColor COLOR_FIELD = Qt::white;


Field::Field(int width, int height) : mWidth(width), mHeight(height){
    _items = QList<Item*>();
}

void Field::draw(QPainter &painter)
{
    painter.fillRect(0,0, mWidth, mHeight, COLOR_FIELD);
    for (Item * item : _items){
        item->draw(painter);
    }
}

void Field::onTic()
{
    qDebug() << "tic";
    for (Item * item : _items){
        item->move(1);
        if (isIntersectsAny(_items,item)){
            item->rotateSpeed();
        }
    }

}
bool Field::isIntersectsAny(QList<Item*> &list, Item * item){
    QRect rect = item->getRect();
    for (Item * anotherItem : list){
        if (anotherItem ->isIntersectsWithRect(rect)){
            if (!(item == anotherItem)){
                return true;
            }
        }
    }
    return false;
}
void Field::addItem(Item *item)
{
    _items.append(item);
}
