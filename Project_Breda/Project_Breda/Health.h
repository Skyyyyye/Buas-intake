#pragma once
#include "Entity.h"

class Health :
	public Entity
{
public:
	Health();
private:

protected:
	int health = 100;
	int EHealth[50];
};

