#ifndef SHIP_CELL
#define SHIP_CELL

#include "cell.h"
#include "dead_cell_base.h"
#include "dead_cell_hover.h"
#include "alive_cell_base.h"
#include "alive_cell_hover.h"
#include "invisible_cell.h"
#include "error_cell.h"

class ShipCell : public Cell{
private:
    CellState *currentState;

    DeadCellBase *deadBaseState;
    DeadCellHover *deadHoverState;
    AliveCellBase *aliveBaseState;
    AliveCellHover *aliveHoverState;
    InvisibleCell *invisibleState;
    ErrorCell *errorState;

    bool alive;

    bool visible;
public:
    ShipCell(int x, int y, double board_x, double board_y, double board_width);
    void kill();
    bool isAlive();
    bool canBeMoved(int x, int y);
    void moveTo(int x, int y);

    void setInvisible();
    void setVisible();
    void act(RenderWindow &window);
    void activateHover();
    void activateNormalState();
};

#endif // SHIP_CELL

