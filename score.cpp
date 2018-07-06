#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem * parent) {
    score = 0;
    setPlainText(QString("Bricks broken: " + QString::number(score)));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 24));
}

void Score::increase() {
    score += 1;
    setPlainText(QString("Bricks broken: " + QString::number(score)));
}

int Score::getScore() {
    return score;
}

void Score::setScore(int value) {
    score = value;
    setPlainText(QString("Bricks broken: " + QString::number(score)));
}
