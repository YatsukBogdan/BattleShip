#ifndef SHOOT
#define SHOOT

#include "field.h"

class Shoot{
private:
    Field *shooter;
public:
    bool shoot();
    void setShooter(Field *shooter);
};

#endif // SHOOT

