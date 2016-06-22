#ifndef FIELD_CREATOR
#define FIELD_CREATOR

#include "your_field.h"
#include "enemy_field.h"

class FieldCreator {
public:
    Field *FactoryMethod(int type);
};

#endif // FIELD_CREATOR

