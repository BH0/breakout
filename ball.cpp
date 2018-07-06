#include "ball.h"
#include "player.h"
#include "game.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include <stdlib.h>

extern Game * game;

Ball::Ball() { // try to make sure this becomes a circle (elipse)
    setRect(300, 300, 16, 16);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(90);
}

/// Randomize Ball's Direction
void Ball::randHorDir() {
    int randDirection = rand() % 100;
    if (randDirection >= 50) {
        xVel = -xVel;
    } else {
        xVel = xVel;
    }
}
void Ball::randVerDir() {
    int randDirection = rand() % 100;
    if (randDirection >= 50) {
        yVel = -yVel;
    } else {
        yVel = yVel;
    }
}

/// Reset / Game Over
void Ball::ballWentBelowPaddle() {
    game->score->setScore(0);
    game->createBall();
    delete this;
}

void Ball::move() {
    /// Collisions (With Paddle & Brick)
    QList<QGraphicsItem * > colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++) {
        if (typeid(*(colliding_items[i])) == typeid(Brick)) {
            randHorDir();
            randVerDir();
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            game->score->increase();
            game->brickCount -= 1;
            return;
        } else if (typeid(*(colliding_items[i])) == typeid(Player)) {
            yVel = -yVel;
            randHorDir();
        }
    }

    /// Movement (and Collision with Scene Boundaries)
    setPos(x() + xVel, y() + yVel);
    if (pos().x() <= -300 || pos().x() >= 300 ) { // probably should not have these values hard-coded
        xVel = -xVel;
    }
    if (pos().y() > 80) {
        ballWentBelowPaddle();
    }
    if (pos().y() < -300) {
        yVel = -yVel;
    }
}

