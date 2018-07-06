#ifndef BALL_H
#define BALL_H

#include <QGraphicsRectItem>
#include <QObject>

class Ball: public QObject, public QGraphicsRectItem {
   Q_OBJECT
public:
    Ball();
private:
    int speed = 14;
    int xVel = speed;
    int yVel = speed;
    void randHorDir();
    void randVerDir();
    void ballWentBelowPaddle();
public slots:
    void move(); // also handles collisions
};

#endif // BALL_H
