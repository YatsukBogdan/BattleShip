#ifndef YOUR_FIELD
#define YOUR_FIELD

#include "field.h"
#include "ship.h"

using namespace std;

class YourField : public Field{
public:
    YourField();

    void act(RenderWindow &window);
    void act_game(RenderWindow &window);
    bool shootBoard();

    void draw(RenderWindow &window);

    void reset();
    bool isAllShipsPlaced();
    void resizeBoard();

    void fill();
};

#endif // YOUR_FIELD

