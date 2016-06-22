#include "field_creator.h"

Field *FieldCreator::FactoryMethod(int type){
    switch(type){
        case 1:
            return new YourField();
        case 2:
            return new EnemyField();
    }
}
