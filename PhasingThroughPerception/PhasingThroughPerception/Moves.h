#ifndef MOVES
#define MOVES_H_INCLUDED

#include "Physics.h"

void boarHitJump() {
	heroHealth -= 0.1;

	if (boarHitjumpY) {
		if (CheckCollisionJump() == 1) {
			boarHitjump = false;
			boarHitjumpModifier = 0;
			boarHitjumpY = false;
			return;
		}

		hero.y += 4.5 - boarHitjumpModifier;
		boarHitjumpModifier += 0.18;
	}
	else {

		int temp = CheckCollision();
		if (temp == 1) {
			if (boardirection) {
				hero.x += 4;
			}
			else {
				hero.x -= 4;
			}
		}
		else if (temp == 0) {
			boarHitjump = false;
			boarHitjumpModifier = 0;
			boarHitjumpY = false;
		}
		else {
			boarHitjumpY = true;
		}

		hero.y += 4.5 - boarHitjumpModifier;
		boarHitjumpModifier += 0.16;

	}

}

void rhinoHitJump() {
	heroHealth--;

	if (rhinoHitjumpY) {
		if (CheckCollisionJump() == 1) {
			rhinoHitjump = false;
			rhinoHitjumpModifier = 0;
			rhinoHitjumpY = false;
			return;
		}

		hero.y += 8 - rhinoHitjumpModifier;
		rhinoHitjumpModifier += 0.18;
	}
	else {

		int temp = CheckCollision();
		if (temp == 1) {
			if (!rhinodirection) {
				hero.x -= 5.5;
			}
			else {
				hero.x += 5.5;

			}
		}
		else if (temp == 0) {
			rhinoHitjump = false;
			rhinoHitjumpModifier = 0;
			rhinoHitjumpY = false;
		}
		else {
			rhinoHitjumpY = true;
		}

		hero.y += 7 - rhinoHitjumpModifier;
		rhinoHitjumpModifier += 0.1;

		if (hero.y < level) {
			hero.y = level;
			rhinoHitjump = false;
			rhinoHitjumpModifier = 0;
			rhinoHitjumpY = false;
		}
	}

}



void Jump() {

	if (jumpY) {
		if (CheckCollisionJump() == 0) {
			jump = false;
			jumpModifier = 0;
			jumpY = false;
			roll = false;
			return;
		}

		hero.y += 7 - jumpModifier;
		jumpModifier += 0.18;
	}
	else if (hero.y <= reach_y) {

		int temp = CheckCollision();
		if (temp == 1) {
			if (roll) {
				hero.y += 1;
				if (!direction) {
					hero.x += 6;
				}
				else {
					hero.x -= 6;
				}
			}
			else {
				if (!direction) {
					hero.x += 2;
				}
				else {
					hero.x -= 2;
				}
			}
		}
		else if (temp == 0) {
			jump = false;
			jumpModifier = 0;
			jumpY = false;
			roll = false;
		}
		else {
			jumpY = true;
		}

		hero.y += 7 - jumpModifier;
		jumpModifier += 0.18;

	}
}

void Forward() {
	direction = false;
	if (jump || jumpY || boarHitjump || boarHitjumpY || rhinoHitjump || rhinoHitjumpY) {
		return;
	}

	hero.x += move_speed;

}

void Backward() {
	direction = true;
	if (jump || jumpY || boarHitjump || boarHitjumpY || rhinoHitjump || rhinoHitjumpY) {
		return;
	}

	hero.x -= move_speed;

}



#endif
