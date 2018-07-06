/// Player ? Paddle

#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
// #include <QMediaPlayer>

class Player: public QObject, public QGraphicsRectItem {
  Q_OBJECT
public:
        Player(QGraphicsItem * parent = 0);
        int speed = 12;
        void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER_H
