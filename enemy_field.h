#ifndef ENEMY_FIELD
#define ENEMY_FIELD

#include "field.h"

class EnemyField : public Field{
public:
    EnemyField();
    void act(RenderWindow &window);
    void fill();
    void draw(RenderWindow &window);

    void reset();
    void setShipsInvisible();
    bool shootBoard();
    void resizeBoard();
};

#endif // ENEMY_FIELD

