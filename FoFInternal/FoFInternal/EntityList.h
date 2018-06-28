#pragma once

class Entity
{
public:
	Entity(int i_health = 0, int i_x = 0, int i_y = 0, int i_z = 0)
	{
		health = i_health;
		x = i_x;
		y = i_y;
		z = i_z;
	}
	int health;
	float x;
	float y;
	float z;
private:

};