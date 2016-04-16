#ifndef SHIP
#define SHIP

class Ship {

public:
	Ship(int x, int y, int size, bool vertical);

private:
	int x;
	int y;
	int size;
	bool vertical;//true - vertical, false - horizontal

};

#endif
