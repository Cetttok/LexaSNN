#include "field.h"
#include <QDebug>
const QColor COLOR_FIELD = Qt::white;
const QColor COLOR_BALL = Qt::blue;
const QColor COLOR_POLYGON = Qt::black;

Field::Field(int width, int height) : mWidth(width), mHeight(height),_engine(Ball(QPointF(100,100),5,QPointF(2,0.1)),
              PhysicsPolygon(QList<QPointF>(
                  {QPointF(50,150),QPointF(150,150),QPointF(150,50),QPointF(50,50)}
                                // {QPointF(200, 100), QPointF(150, 173), QPointF(50, 173), QPointF(0, 100), QPointF(50, 27), QPointF(150, 27)}
                                 ),QPointF(0.1,0.1),0.01)){
    //_items = QList<Item*>();
    ;
}

void Field::draw(QPainter &painter)
{
    painter.fillRect(0,0, mWidth, mHeight, COLOR_FIELD);
    QPen penPolygon = QPen(COLOR_POLYGON);
    QPen penBall= QPen(COLOR_BALL);

    _engine.polygon()->draw(painter, penPolygon);
    _engine.ball()->draw(painter,penBall);
}

void Field::onTic()
{
    //qDebug() << "tic";
    _engine.makeTic();

}
// bool Field::isIntersectsAny(QList<Item*> &list, Item * item){
//     QRectF rect = item->getRect();
//     for (Item * anotherItem : list){
//         if (anotherItem ->isIntersectsWithRect(rect)){
//             if (!(item == anotherItem)){
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// void Field::addItem(Item *item)
// {
//     _items.append(item);
// }
