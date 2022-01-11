#pragma once
class Health
{
public:
	virtual void healthMin() {};
	virtual void healthPlus() {};
	virtual void health() {};
private:
	int health;
};

