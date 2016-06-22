#ifndef BOARD_CELL
#define BOARD_CELL

#include "cell.h"

class BoardCell : public Cell {
private:
    Color base;
    Color hover;
    Color miss_base;
    Color miss_hover;

    bool missed;
public:
    BoardCell(int x, int y, double board_x, double board_y, double board_width);

    void setMissed();
    bool isMissed();
    void act(RenderWindow &window);
    void activateHover();
    void activateNormalState();
};

#endif // BOARD_CELL
