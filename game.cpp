#include <QTimer>
// #include <QMediaPlayer>
#include <QGraphicsTextItem>
#include <QFont>

#include "game.h"

Game::Game(QWidget * parent) {

    /// Prepare Scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, width, height);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width, height);

    /// Player's Paddle
    // (not sure if I should move the code under the instation into the class itself
    player = new Player();
    player->setRect(0, 0, 100, 25);
    player->setPos(300, 380);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    /// Ball
    createBall();

    score = new Score();
    scene->addItem(score);

    /// Create Bricks
    for (int x = 1; x < numberOfBricks; x++) {
        for (int y = 1; y < numberOfBricks; y++) {
            Brick * brick = new Brick(x * 80, y * 40);
            scene->addItem(brick);
        }
    }

    /// Render Game (Scene)
    show();
}

void Game::createBall() {
    ball = new Ball();
    scene->addItem(ball);
}

void Game::endGame() {
    qDebug("Ending game");
    // QApplication::quit();
}
