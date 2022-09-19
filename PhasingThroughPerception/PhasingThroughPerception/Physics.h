#ifndef PHYSICS
#define PHYSICS_H_INCLUDED

#include "Audio.h"


int Collision(GameObject& one, GameObject& two)
{

	// collision x-axis?
	//two points for x : x , x+width
	bool collisionX = one.x >= two.x && one.x <= two.x + two.width ||
		one.x + one.width >= two.x && one.x + one.width <= two.x + two.width;
	bool spLX = false;
	if (collisionX) {
		//attempt to enter
		spLX = one.x + one.width - move_speed <= two.x ||
			one.x + move_speed >= two.x + two.width;
	}


	// collision y-axis?
	//two points for y : y , y+height
	bool collisionY = one.y >= two.y && one.y <= two.y + two.height ||
		one.y + one.height >= two.y && one.y + one.height <= two.y + two.height;

	bool spLY = false;

	//if (collisionY) {
	//	cout << "Y TRUE" << endl;
	//}

	//if (collisionX) {
	//	cout << "X TRUE" << endl;
	//}

	if (collisionX && collisionY) {
		//attempt to enter
		//cout << "COLLISIONXY TRUE" << endl;
		spLY = one.y + move_speed <= two.y + two.height;
	}

	/*if (spLY) {
		cout << "SPLY TRUE" << endl;
	}*/

	// collision only if on both axes

	// 1 determine the ability to move


	if (spLX && collisionY) {

		if (hero.x < two.x) {
			hero.x = two.x - move_speed - hero.width;
		}
		else {
			hero.x = two.x + two.width + move_speed;
		}
		return 0;
	}


	if (spLY && collisionX) {
		hero.y = two.y + two.height;
		return 0;
	}

	if (!spLX && !spLY && hero.y != level) {
		//std::cout << "Time for Gravity" << std::endl;
	}


	return 1;

}

int CheckCollision() {

	for (auto itr = objects.begin(); itr != objects.end(); itr++) {
		for (auto i = objects[itr->first].begin(); i != objects[itr->first].end(); i++) {
			if (itr->first == "atree") {
				continue;
			}
			int value = Collision(hero, *i);
			if (value == 0) {
				return 0;
			}
		}
	}

	if (hero.y < level) {
		hero.y = level;
		return 0;
	}

	return 1;

}
/*
int CheckObjCollision(GameObject& obj) {

	for (auto itr = objects.begin(); itr != objects.end(); itr++) {
		for (auto i = objects[itr->first].begin(); i != objects[itr->first].end(); i++) {
			if (itr->first == "tree") {
				continue;
			}
			int value = Collision(obj, *i);
			if (value == 0) {
				return 0;
			}
		}
	}

	if (hero.y < level) {
		hero.y = level;
		return 0;
	}

	return 1;

}
*/


int CollisionJumpY(GameObject& obj) {

	bool insidex = obj.x + obj.width >= hero.x && obj.x <= hero.x ||
		obj.x + obj.width >= hero.x + hero.width && obj.x <= hero.x + hero.width;

	if (hero.y <= obj.y + obj.height && insidex) {
		return 0;
	}
	return 1;
}

int CheckCollisionJump() {

	if (hero.y <= level) {
		hero.y = level;
		return 0;
	}

	for (auto itr = objects.begin(); itr != objects.end(); itr++) {
		for (auto i = objects[itr->first].begin(); i != objects[itr->first].end(); i++) {
			if (CollisionJumpY(*i) == 0) {
				return 0;
			}
		}
	}

	return 1;

}


void Gravity() {
	if (CheckCollisionJump() == 1) {
		hero.y += 1 - gravitymodifier;
		gravitymodifier += 0.18;
	}
	else {
		gravitymodifier = 0;
	}

}


#endif
