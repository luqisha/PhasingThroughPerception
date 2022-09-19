#ifndef SAVEANDLOAD
#define SAVEANDLOAD_H_INCLUDED

#include <fstream>
#include "level0.h"


void SaveGame() {

	std::fstream file("SaveGame.text", std::ios::out); //using namespace use krtesi na kothao tai std use krtesi

	file << gameState << std::endl;
	file << riCount << std::endl;
	file << dx << std::endl;
	file << direction << std::endl;;
	file << menu_click << std::endl;
	file << inmenu << std::endl;
	file << maxHealth << std::endl;
	file << heroHealth << std::endl;
	file << sliceDamage << std::endl;
	file << heroState << std::endl;
	file << portal << std::endl;
	file << dayTime << std::endl;
	file << rainOn << std::endl;
	file << sliceUpDamage << std::endl;
	file << slice360Damage << std::endl;
	file << ultMoveDamage << std::endl;
	file << bombEquip << std::endl;
	file << smokeEquip << std::endl;
	file << stunEquip << std::endl;
	file << TIME << std::endl;
	file << shootReset << std::endl;
	file << maxXP << std::endl;
	file << characterlevel << std::endl;
	file << XP << std::endl;
	file << maxStamina << std::endl;
	file << stamina << std::endl;

	file << slotIncrease << std::endl;
	file << qSlotIncrease << std::endl;

	file << swordLv << std::endl;
	file << backpackLv << std::endl;
	file << armorLv << std::endl;
	




	int invItemSize = invItems.size();
	file << invItemSize << std::endl;
	for (auto iterator = invItems.begin(); iterator != invItems.end(); iterator++) {
		file << iterator->name << std::endl;
		//file << iterator->img << std::endl;
		file << iterator->x << std::endl;
		file << iterator->y << std::endl;
		file << iterator->n << std::endl;
		file << iterator->slotID << std::endl;
		file << iterator->UniqueWeight << std::endl;
	}

	int craftQSize = craftQ.size();
	file << craftQSize << std::endl;
	for (auto iterator = craftQ.begin(); iterator != craftQ.end(); iterator++) {
		file << iterator->name << std::endl;
		//file << iterator->img << std::endl;
		file << iterator->x << std::endl;
		file << iterator->y << std::endl;
		file << iterator->n << std::endl;
		file << iterator->slotID << std::endl;
		file << iterator->UniqueWeight << std::endl;
	}



	int eqpSize = eqp.size();
	file << eqpSize << std::endl;
	for (auto iterator = eqp.begin(); iterator != eqp.end(); iterator++) {
		file << iterator->name << std::endl;
		//file << iterator->img << std::endl;
		file << iterator->x << std::endl;
		file << iterator->y << std::endl;
		file << iterator->n << std::endl;
		file << iterator->slotID << std::endl;
	}
	file.close();

}

void LoadGame() {
	std::fstream file("SaveGame.text", std::ios::in);

	file >> gameState;

	if (gameState == 1) {
		InitializeLevel0();
	}
	else if (gameState == 2) {
		InitializeLevel1();
	}

	else if (gameState == 3) {
		intitializeBossLevel();
	}


	file >> riCount;
	file >> dx;
	file >> direction;
	file >> menu_click;
	file >> inmenu;
	file >> maxHealth;
	file >> heroHealth;
	file >> sliceDamage;
	file >> heroState;
	file >> portal;
	file >> dayTime;
	file >> rainOn;
	file >> sliceUpDamage;
	file >> slice360Damage;
	file >> ultMoveDamage;
	file >> bombEquip;
	file >> smokeEquip;
	file >> stunEquip;
	file >> TIME;
	file >> shootReset;
	file >> maxXP;
	file >> characterlevel;
	file >> XP;
	file >> maxStamina;
	file >> stamina;

	file >> slotIncrease;
	file >> qSlotIncrease;

	file >> swordLv ;
	file >> backpackLv ;
	file >> armorLv ;


	std::string name1;

	unsigned int img1;
	int x1;
	int y1;
	int n1;
	int sID;
	int UW;

	
	invItems.clear();
	craftQ.clear();
	eqp.clear();

	int invItemSize;
	file >> invItemSize;
	for (int iterator = 1; iterator <= invItemSize; iterator++) {
		Materials m;

		file >> name1;
		//file >> img1;
		file >> x1;
		file >> y1;
		file >> n1;
		file >> sID;
		file >> UW;

		m.name = name1;

		//m.img = iLoadImage("");
		m.x = x1;
		m.y = y1;
		m.n = n1;
		m.slotID = sID;
		m.UniqueWeight = UW;

		invItems.push_back(m);

	}

	int craftQSize;
	file >> craftQSize;
	for (int iterator = 1; iterator <= craftQSize; iterator++) {

		Materials m;

		file >> name1;
		//file >> img1;
		file >> x1;
		file >> y1;
		file >> n1;
		file >> sID;
		file >> UW;

		m.name = name1;
		//m.img = img1;
		m.x = x1;
		m.y = y1;
		m.n = n1;
		m.slotID = sID;
		m.UniqueWeight = UW;

		craftQ.push_back(m);

	}

	int eqpSize;
	file >> eqpSize;
	for (int iterator = 1; iterator <= eqpSize; iterator++) {
		Equipments e;
		file >> name1;
		//file >> img1;
		file >> x1;
		file >> y1;
		file >> n1;
		file >> sID;

		e.name = name1;
		//e.img = img1;
		e.x = x1;
		e.y = y1;
		e.n = n1;
		e.slotID = sID;


		eqp.push_back(e);

	}

	file.close();

}

#endif
