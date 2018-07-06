#ifndef BRICK_H
#define BRICK_H

#include <QGraphicsRectItem>
#include <QObject>

class Brick: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Brick(int x, int y); // "x" and "y" may need to be swapped
    int brickNumber = 0;
};

#endif // BRICK_H
