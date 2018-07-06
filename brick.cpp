#include "brick.h"
#include <QGraphicsScene>

Brick::Brick(int x, int y)
{
    setRect(x, y, 64, 32); // "64" & "32" were just guesses, may not be correct sizes
}

