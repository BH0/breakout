/// Player / Paddle
#include "Player.h"
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsScene>

#include "player.h"

Player::Player(QGraphicsItem * parent) {

}

void Player::keyPressEvent(QKeyEvent * event) {
    if (event->key() == Qt::Key_Left) {
        if (pos().x() >= 0) {
            setPos(x() - speed, y());
        }
    }
    if (event->key() == Qt::Key_Right) {
        if (pos().x() <= 600) { // "400" should be width-variable
            setPos(x() + speed, y());
        }
    }
}
