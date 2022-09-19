#ifndef HERO
#define HERO_H_INCLUDED

#include "Visuals.h"

bool attackCollision(GameObject& one, GameObject& two, int extend, bool dir) {
	// collision x-axis?
	//two points for x : x , x+width

	bool collisionX = false;
	if (!dir) {
		collisionX = one.x + one.width + extend >= two.x && one.x + one.width <= two.x + two.width;
	}
	else {
		collisionX = one.x - extend <= two.x + two.width && one.x >= two.x;
	}

	return collisionX;



}

void checkAttackCollision0(int extend = 400, bool dir = ::direction) {
	for (auto itr = objects.begin(); itr != objects.end(); itr++) {
		for (auto i = objects[itr->first].begin(); i != objects[itr->first].end(); i++) {
			if (itr->first == "rhino") {
				bool value = attackCollision(hero, *i, extend, dir);
				if (value) {
					(*i).health -= shootDamage;
				}
			}
			else if (itr->first == "boar") {
				bool value = attackCollision(hero, *i, extend, dir);
				if (value) {
					(*i).health -= shootDamage;
				}
			}
		}
	}

}

void checkAttackCollision(int damage, int extend = 50, bool dir = ::direction) {
	for (auto itr = objects.begin(); itr != objects.end(); itr++) {
		for (auto i = objects[itr->first].begin(); i != objects[itr->first].end(); i++) {
			if (itr->first == "rhino") {
				bool value = attackCollision(hero, *i, extend, dir);
				if (value) {
					(*i).health -= damage;
				}
			}
			else if (itr->first == "boar") {
				bool value = attackCollision(hero, *i, extend, dir);
				if (value) {
					(*i).health -= damage;
				}
			}
			else if (itr->first == "lion") {
				bool value = attackCollision(hero, *i, extend, dir);
				if (value) {
					(*i).health -= damage;
				}
			}
			else if (itr->first == "tiger") {
				bool value = attackCollision(hero, *i, extend, dir);
				if (value) {
					(*i).health -= damage;
				}
			}
		}
	}

	for (auto itr = boss.begin(); itr != boss.end(); itr++) {
		bool value = attackCollision(hero, boss[itr->first], extend, dir);
		//std::cout << itr->first << std::endl;
		if (value) {
			boss[itr->first].health -= damage;
		}
	}

}

void initiateSmoke(int pos) {
	items["smoke"] = Item(pos, 800, 6);
}

void initiateStun(int pos) {
	items["stun"] = Item(pos, 400, 3);
}

void initiateBomb(int pos) {
	items["bomb"] = Item(pos, 400, 2);
}
void initiatehPotion(int pos) {
	items["HealthPotion"] = Item(pos, 400, 2);
}
void initiatestaminaPotion(int pos) {
	items["staminPotion"] = Item(pos, 400, 2);
}
void initiatcursedOil(int pos) {
	items["cursedOil"] = Item(pos, 400, 2);
}
void initiatecheetahBlood(int pos) {
	items["booldofCheetah"] = Item(pos, 400, 2);
}


void updateItems() {
	for (auto itr = items.begin(); itr != items.end(); itr++) {

		bool value = (*itr).second.t.Counter();
		itr->second.pos -= change;

		if (itr->first == "stun") {
			if (value) {
				stunFrame = 0;
				items.erase(itr);
				break;
			}
			animateStun(itr->second);
			for (auto i = objects["rhino"].begin(); i != objects["rhino"].end(); i++) {
				if (abs((*i).x - itr->second.pos) <= itr->second.radius) {
					(*i).stunned = true;
				}
			}

			for (auto i = objects["boar"].begin(); i != objects["boar"].end(); i++) {
				if (abs((*i).x - itr->second.pos) <= itr->second.radius) {
					(*i).stunned = true;
				}
			}

			for (auto i = objects["tiger"].begin(); i != objects["tiger"].end(); i++) {
				if (abs((*i).x - itr->second.pos) <= itr->second.radius) {
					(*i).stunned = true;
				}
			}

			for (auto i = objects["lion"].begin(); i != objects["lion"].end(); i++) {
				if (abs((*i).x - itr->second.pos) <= itr->second.radius) {
					(*i).stunned = true;
				}
			}

			if (boss.find("tanake") != boss.end()) {
				boss["tanake"].stunned = true;
			}

		}
		else if (itr->first == "bomb") {
			if (value) {

				if (boss.find("tanake") != boss.end()) {
					if (hero.x <= boss["tanake"].x) {
						boss["tanake"].x += 300;
					}
					else {
						boss["tanake"].x -= 300;
					}
				}

				for (auto ir = objects.begin(); ir != objects.end(); ir++) {
					for (auto i = objects[ir->first].begin(); i != objects[ir->first].end(); i++) {
						if (abs((*i).x - itr->second.pos) <= itr->second.radius) {
							(*i).health -= 200;
						}
					}
				}
			
				bombX = (itr->second).pos;
				bombAnimation = true;
				items.erase(itr);
				break;
			}
			else {
				iShowImage(itr->second.pos+60, level, 30, 30, bombIcon);
			}

		}else if(itr->first == "smoke"){
			if (value) {
				smokeFrame = 0;
				items.erase(itr);
				break;
			}

			animateSmoke(itr->second);

			//std::cout << itr->second.pos << std::endl;
			
			for (auto i = objects["rhino"].begin(); i != objects["rhino"].end(); i++) {
				if (itr->second.pos<= (*i).x && hero.x <= itr->second.pos || itr->second.pos >= (*i).x && hero.x >= itr->second.pos) {
					(*i).stunned = true;
				}
			}

			for (auto i = objects["boar"].begin(); i != objects["boar"].end(); i++) {
				if (itr->second.pos<= (*i).x && hero.x <= itr->second.pos || itr->second.pos >=(*i).x && hero.x >= itr->second.pos) {
					(*i).stunned = true;
				}
			}

			if (boss.find("tanake") != boss.end()) {
				boss["tanake"].stunned = true;
			}

		}
	}
}


void resetItemeffects() {
	for (auto itr = objects.begin(); itr != objects.end(); itr++) {
		for (auto i = objects[itr->first].begin(); i != objects[itr->first].end(); i++) {
			(*i).stunned = false;
		}
	}
	if (boss.find("tanake") != boss.end()) {
		boss["tanake"].stunned = false;
	}
}


#endif