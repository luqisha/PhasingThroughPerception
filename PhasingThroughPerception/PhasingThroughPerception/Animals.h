#ifndef ANIMALS
#define ANIMALS_H_INCLUDED

#include "Boss.h"
long long cnt = 0; //unregonized declaration


void initializeRhino(int x, bool dead = false) {
	if (!dead) {
		GameObject rhino(x, level, 60, 155);
		rhino.numberOfFrames = 21;
		rhino.loadImageF("images\\Animals\\Rhino\\runF\\", 21);
		rhino.loadImageB("images\\Animals\\Rhino\\runB\\", 21);
		rhino.maxHealth = 250;
		rhino.health = 250;
		rhino.icon = iLoadImage("images\\Animals\\Rhino\\rhinoIcon.png");
		objects["rhino"].push_back(rhino);
	}
	else {
		XP += 50;
		GameObject rhino(x, level, 60, 155);
		rhino.deadImageF = iLoadImage("images\\Animals\\Rhino\\DF.png");
		rhino.deadImageB = iLoadImage("images\\Animals\\Rhino\\DB.png");;
		rhino.deadDirection = !direction;
		destructed["rhino"].push_back(rhino);
	}
}

void initializeBoar(int x, bool dead = false) {


	//if (!dead) {
	//		GameObject boar(x, level, 50, 60);
	//		boar.numberOfFrames = 7;
	//		boar.loadImageF("images\\Animals\\Boar\\runF\\", 7);
	//		boar.loadImageB("images\\Animals\\Boar\\runB\\", 7);

	//		boar.maxHealth = 40;
	//		boar.health = 40;
	//		objects["boar"].push_back(boar);
	//}
	//else {
	//		GameObject boar(x, level, 50, 60);
	//		boar.deadImageF = iLoadImage("images\\Animals\\Boar\\others\\sleep1F.png");
	//		boar.deadImageB = iLoadImage("images\\Animals\\Boar\\others\\sleep1B.png");
	//		boar.deadDirection = !direction;
	//		destructed["boar"].push_back(boar);
	//}

	if (!dead) {
		GameObject boar(x, level, 50, 60);
		boar.numberOfFrames = 30;
		boar.loadImageF("images\\Animals\\Boar\\Level1\\runF\\", 30);
		boar.loadImageB("images\\Animals\\Boar\\Level1\\runB\\", 30);

		boar.maxHealth = 40;
		boar.health = 40;
		objects["boar"].push_back(boar);
	}
	else {
		XP += 20;
		GameObject boar(x, level, 50, 60);
		boar.deadImageF = iLoadImage("images\\Animals\\Boar\\others\\dead.png");
		boar.deadImageB = iLoadImage("images\\Animals\\Boar\\others\\dead.png");
		boar.deadDirection = !direction;
		destructed["boar"].push_back(boar);
	}


}

bool rhinoBehavior(GameObject& rhino) {

	/*if (hero.x > rhino.x+rhino.width && abs(hero.x - rhino.x - rhino.width) <= rhino.rhinovision) {
		rhino.rhinosense = true;
	}

	if ( hero.x < rhino.x && abs(hero.x - rhino.x) <= rhino.rhinovision) {
		rhino.rhinosense = true;
	}

	if (hero.x < rhino.x && abs(hero.x - rhino.x) >= rhino.rhinovision+600) {
		rhino.rhinosense = false;
	}

	if (hero.x > rhino.x + rhino.width && abs(hero.x - rhino.x - rhino.width) >= rhino.rhinovision+600) {
		rhino.rhinosense = false;
	}*/

	if (rhino.x - hero.x - hero.width <= rhino.rhinovision) {
		rhino.rhinosense = true;
	}

	if (rhino.stunned) {
		return false;
	}

	return rhino.rhinosense;
}

int boarBehavior(GameObject boar) {

	//cout << boar.x << endl;

	if (abs(hero.x - boar.x) <= boar.boarvision) {
		boar.boarsense = true;
	}

	if (abs(hero.x - boar.x) >= boar.boarvision + 300) {
		boar.boarsense = false;
	}

	if (boar.stunned) {
		return false;
	}

	return boar.boarsense;
}

double prevBoarSoundCall = 0;

void updateBoarBehavior() {
	for (auto i = objects["boar"].begin(); i != objects["boar"].end(); i++) {
		if ((*i).health < 10) {
			mciSendString("close music\\boar.wav", NULL, 0, 0);
			initializeBoar((*i).x, true);
			::boarHitjump = false;
			::boarHitjumpModifier = 0;
			::boarHitjumpY = false;
			objects["boar"].erase(i);
			break;
		}
		//boar behavior starts
		if (boarBehavior(*i)) {
			if (prevBoarSoundCall == 0 || abs(prevBoarSoundCall - TIME) > 5) {
				prevBoarSoundCall = TIME;
				BoarSound();
			}
			bool boarCollisionX = hero.x + 4 >= (*i).x && hero.x - 4 <= (*i).x + (*i).width ||
				hero.x + hero.width + 4 >= (*i).x && hero.x + hero.width - 4 <= (*i).x + (*i).width;

			if (boarHitjump) {
				if (++cnt % objects["boar"].size() == 0) {
					boarHitJump();
					cnt == 0;
				}
			}

			else if (boarCollisionX && !jump) {
				::boardirection = (*i).x < hero.x;
				::boarHitjump = true;
				boarHitJump();
				continue;
			}
			if ((*i).x < hero.x) {
				if ((*i).boarspeed <= (*i).boarTopSpeed) {
					(*i).boarspeed += (*i).boarAcceleration;
				}
				(*i).x += (*i).boarspeed;
			}
			else {
				if ((*i).boarspeed >= -(*i).boarTopSpeed) {
					(*i).boarspeed -= (*i).boarAcceleration;
				}
				(*i).x += (*i).boarspeed;
			}
		}
		else {
			(*i).boarspeed = 0;
		}
	}

}

double prevCallRhinoSound = 0;

void updateRhinoBehavior() {
	for (auto i = objects["rhino"].begin(); i != objects["rhino"].end(); i++) {

		if ((*i).health < 50) {
			mciSendString("close music\\rhino.wav", NULL, 0, 0);
			::rhinoHitjump = false;
			::rhinoHitjumpModifier = 0;
			::rhinoHitjumpY = false;
			initializeRhino((*i).x, true);
			objects["rhino"].erase(i);
			break;
		}

		//rhino behavior starts
		::rhinodirection = (*i).x < hero.x;
		bool rhinoCollisionX = hero.x + hero.width + 4 >= (*i).x && hero.x <= (*i).x ||
			hero.x - 4 < (*i).x + (*i).width && hero.x >= (*i).x;

		//add or CollissionX to if Condition if you dont want quick turn
		if (rhinoBehavior(*i) || rhinoCollisionX) {
			if(abs(prevCallRhinoSound - TIME)>5 || prevCallRhinoSound == 0){
				prevCallRhinoSound = TIME;
				RhinoSound();
			}
			
			if (rhinoHitjump) {

				if (++cnt % objects["rhino"].size() == 0) {
					rhinoHitJump();
					cnt == 0;
				}
			}
			else if (rhinoCollisionX) {

				::rhinoHitjump = true;
				rhinoHitJump();
				continue;
			}
			if (rhinodirection) {
				if ((*i).rhinospeed <= (*i).rhinoTopSpeed) {
					(*i).rhinospeed += (*i).rhinoAcceleration;
				}
				(*i).x += (*i).rhinospeed;
			}
			else {
				if ((*i).rhinospeed >= -(*i).rhinoTopSpeed) {
					(*i).rhinospeed -= (*i).rhinoAcceleration;
				}
				(*i).x += (*i).rhinospeed;

			}
		}
		else {
			(*i).rhinospeed = 0;
			mciSendString("close music\\rhino.wav", NULL, 0, 0);
		}
	}
}

void initializeLion(int x, bool dead = false) {
	if (!dead) {
		GameObject lion(x, level, 60, 130);
		lion.numberOfFrames = 37;
		lion.loadImageF("images\\Animals\\Lion\\runF\\", 37);
		lion.loadImageB("images\\Animals\\Lion\\runB\\", 37);
		lion.maxHealth = 250;
		lion.health = 250;
		lion.icon = iLoadImage("images\\Animals\\Lion\\lionIcon.png");
		lion.loadattackImageF("images\\Animals\\Lion\\attackF\\", 14);
		lion.loadattackImageB("images\\Animals\\Lion\\attackB\\", 14);
		objects["lion"].push_back(lion);
	}
	else {
		XP += 60;
		GameObject lion(x, level, 60, 130);
		lion.deadImageF = iLoadImage("images\\Animals\\Lion\\DF.png");
		lion.deadImageB = iLoadImage("images\\Animals\\Lion\\DB.png");;
		lion.deadDirection = !direction;
		destructed["lion"].push_back(lion);
	}

}

int lionBehavior(GameObject& lion) {



	if (abs(lion.x - hero.x - hero.width) <= lion.lionvision || abs(lion.x + lion.width - hero.x - hero.width) <= lion.lionvision) {
		lion.lionsense = true;
	}


	if (lion.stunned) {
		return false;
	}

	return lion.lionsense;

}

double prevLionSoundCall = 0;
void updateLionBehavior() {
	for (auto i = objects["lion"].begin(); i != objects["lion"].end(); i++) {

		if ((*i).health < 50) {
			mciSendString("close music\\lion.wav", NULL, 0, 0);
			initializeLion((*i).x, true);
			objects["lion"].erase(i);
			break;
		}

		//lion behavior starts
		bool liondirection = (*i).x < hero.x;
		bool lionCollisionX = hero.x + hero.width + 4 >= (*i).x && hero.x + hero.width < (*i).x + (*i).width ||
			hero.x + hero.width - 4 <= (*i).x + (*i).width && hero.x + hero.width >= (*i).x;
		bool lionCollisionY = hero.y < (*i).y + (*i).height;
		if (lionCollisionX && lionCollisionY) {
			if (hero.x < (*i).x) {
				hero.x -= 4;
			}
			else {
				hero.x += 4;
			}
		}
		//add or CollissionX to if Condition if you dont want quick turn
		if (lionBehavior(*i)) {
			//lion hit modeling
			if (prevLionSoundCall == 0 || abs(prevLionSoundCall - TIME)> 0.8) {
				prevLionSoundCall = TIME;
				LionSound();
			}

			bool hitX = (hero.x + hero.width + 40) >= (*i).x && hero.x <= (*i).x ||
				(*i).x + (*i).width + 40 >= hero.x && hero.x >= (*i).x + (*i).width;
			bool hitY = (hero.y - 4) < ((*i).y + (*i).height);

			(*i).lionHittable = hitX && hitY;

			if ((*i).lionHittable) {
				heroHealth -= .5;
			}
			else {

				//lion movement
				if (liondirection) {
					if ((*i).lionspeed <= (*i).lionTopSpeed + 2.5) {
						(*i).lionspeed += (*i).lionAcceleration;
					}
					(*i).x += (*i).lionspeed;
				}
				else {
					if ((*i).lionspeed >= -(*i).lionTopSpeed) {
						(*i).lionspeed -= (*i).lionAcceleration;
					}
					(*i).x += (*i).lionspeed;

				}
			}
		}
		else {
			(*i).lionspeed = 0;
		}
	}
}

void initializeTiger(int x, bool dead = false) {
	if (!dead) {
		GameObject tiger(x, level, 60, 130);
		tiger.numberOfFrames = 30;
		tiger.loadImageF("images\\Animals\\Tiger\\runF\\", 30);
		tiger.loadImageB("images\\Animals\\Tiger\\runB\\", 30);
		tiger.maxHealth = 250;
		tiger.health = 250;
		tiger.icon = iLoadImage("images\\Animals\\Tiger\\tigerIcon.png");
		tiger.loadattackImageF("images\\Animals\\Tiger\\attackF\\", 34);
		tiger.loadattackImageB("images\\Animals\\Tiger\\attackB\\", 34);
		objects["tiger"].push_back(tiger);
	}
	else {
		XP += 60;
		GameObject tiger(x, level, 60, 130);
		tiger.deadImageF = iLoadImage("images\\Animals\\Tiger\\DF.png");
		tiger.deadImageB = iLoadImage("images\\Animals\\Tiger\\DB.png");;
		tiger.deadDirection = !direction;
		destructed["tiger"].push_back(tiger);
	}

}

int tigerBehavior(GameObject& tiger) {



	if (abs(tiger.x - hero.x - hero.width) <= tiger.tigervision || abs(tiger.x + tiger.width - hero.x - hero.width) <= tiger.tigervision) {
		tiger.tigersense = true;
	}


	if (tiger.stunned) {
		return false;
	}

	return tiger.tigersense;

}

double prevTigerSoundCall = 0;

void updateTigerBehavior() {
	for (auto i = objects["tiger"].begin(); i != objects["tiger"].end(); i++) {

		if ((*i).health < 50) {
			mciSendString("close music\\tiger1.wav", NULL, 0, 0);
			initializeTiger((*i).x, true);
			objects["tiger"].erase(i);
			break;
		}

		//tiger behavior starts
		bool tigerdirection = (*i).x < hero.x;
		bool tigerCollisionX = hero.x + hero.width + 4 >= (*i).x && hero.x + hero.width < (*i).x + (*i).width ||
			hero.x + hero.width - 4 <= (*i).x + (*i).width && hero.x + hero.width >= (*i).x;
		bool tigerCollisionY = hero.y < (*i).y + (*i).height;
		if (tigerCollisionX && tigerCollisionY) {
			if (hero.x < (*i).x) {
				hero.x -= 4;
			}
			else {
				hero.x += 4;
			}
		}
		//add or CollissionX to if Condition if you dont want quick turn
		if (tigerBehavior(*i)) {
			//tiger hit modeling
			if (prevTigerSoundCall == 0 || abs(prevTigerSoundCall - TIME) > 0.8) {
				prevTigerSoundCall = TIME;
				TigerSound();
			}

			bool hitX = (hero.x + hero.width + 40) >= (*i).x && hero.x <= (*i).x ||
				(*i).x + (*i).width + 40 >= hero.x && hero.x >= (*i).x + (*i).width;
			bool hitY = (hero.y - 4) < ((*i).y + (*i).height);

			(*i).tigerHittable = hitX && hitY;

			if ((*i).tigerHittable) {
				heroHealth -= .4;
			}
			else {

				//tiger movement
				if (tigerdirection) {
					if ((*i).tigerspeed <= (*i).tigerTopSpeed + 2.5) {
						(*i).tigerspeed += (*i).tigerAcceleration;
					}
					(*i).x += (*i).tigerspeed;
				}
				else {
					if ((*i).tigerspeed >= -(*i).tigerTopSpeed) {
						(*i).tigerspeed -= (*i).tigerAcceleration;
					}
					(*i).x += (*i).tigerspeed;

				}
			}
		}
		else {
			(*i).tigerspeed = 0;
		}
	}
}

void updateAnimalBehavior() {
	updateBoarBehavior();
	updateRhinoBehavior();
	updateLionBehavior();
	updateTigerBehavior();
}

#endif