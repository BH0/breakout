#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QWidget>
#include <QGraphicsScene>

#include "player.h"
#include "score.h"
#include "brick.h"
#include "ball.h"

class Game: public QGraphicsView {
public:
    int width = 600, height = 600;
    int numberOfBricks = 5;
    int brickCount = numberOfBricks * 2;

    Game(QWidget * parent = 0);
    void createBall();
    void endGame();

    QGraphicsScene * scene;
    Player * player;
    Ball * ball;
    Score * score;
};

#endif // GAME_H
