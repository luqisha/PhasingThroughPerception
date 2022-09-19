#ifndef CRAFT
#define CRAFT_H_INCLUDED

#include "Hero.h"

//crafting components variables
int slotX = invX + 380, slotY = invY + 295;
int qX = invX + 35, qY = invY - 80;
int eqpX = invX + 10, eqpY = invY + 100;

int slotIncrease = 1;
int qSlotIncrease = 1;
char buff1[100];

bool drag = false;
int dragID = 0;


Materials wood;
Materials silver;
Materials steel;
Materials rhinoHide;
Materials rhinoHorn;
Materials rhinoLiver;
Materials boarHide;
Materials animalFat;
Materials oil;
Materials meat;
Materials lionFang;
Materials lionSkin;
Materials lionHeart;
Materials venom;
Materials tigerFang;
Materials tigerBone;

Equipments cursedOil;
Equipments bloodofCheetah;
Equipments smokeBomb;
Equipments Bomb;
Equipments stunBomb;
Equipments healthPotion;
Equipments staminaPotion;
Equipments armor1, armor2, armor3;
Equipments sword1, sword2, sword3;
Equipments backpack1, backpack2;


std::vector <Materials> invItems;
std::vector <Materials> craftQ;
std::vector <Equipments> bPack;
std::vector <Equipments> eqp;


//crafting functions

void makeHashes() {

	equipmentsHash[10820] = cursedOil;
	equipmentsHash[27677] = bloodofCheetah;
	equipmentsHash[41767] = smokeBomb;
	equipmentsHash[11631] = Bomb;
	equipmentsHash[9514] = stunBomb;
	equipmentsHash[45475] = healthPotion;
	equipmentsHash[39011] = staminaPotion;
	equipmentsHash[22453] = armor1;
	equipmentsHash[17305] = armor2;
	equipmentsHash[13617] = armor3;
	equipmentsHash[13763] = sword1;
	equipmentsHash[17095] = sword2;
	equipmentsHash[21321] = sword3;
	equipmentsHash[28745] = backpack1;
	equipmentsHash[42498] = backpack2;

}

void initializeMats() {

	wood = Materials("wood", iLoadImage("images\\level1\\objects\\materials\\wood.png"), 2.5);
	silver = Materials("silver", iLoadImage("images\\level1\\objects\\materials\\silver.png"), 4.5);
	steel = Materials("steel", iLoadImage("images\\level1\\objects\\materials\\steel.png"), 6.5);
	rhinoHide = Materials("rhinoHide", iLoadImage("images\\level1\\objects\\materials\\rhinoHide.png"), 8.5);
	rhinoHorn = Materials("rhinoHorn", iLoadImage("images\\level1\\objects\\materials\\rhinoHorn.png"), 10.5);
	rhinoLiver = Materials("rhinoLiver", iLoadImage("images\\level1\\objects\\materials\\rhinoLiver.png"), 12.5);
	boarHide = Materials("boarHide", iLoadImage("images\\level1\\objects\\materials\\boarHide.png"), 14.5);
	animalFat = Materials("animalFat", iLoadImage("images\\level1\\objects\\materials\\animalFat.png"), 16.5);
	oil = Materials("oil", iLoadImage("images\\level1\\objects\\materials\\oil.png"), 18.5);
	meat = Materials("meat", iLoadImage("images\\level1\\objects\\materials\\meat.png"), 20.5);
	lionFang = Materials("lionFang", iLoadImage("images\\level1\\objects\\materials\\lionFang.png"), 22.5);
	lionSkin = Materials("lionSkin", iLoadImage("images\\level1\\objects\\materials\\lionSkin.png"), 24.5);
	lionHeart = Materials("lionHeart", iLoadImage("images\\level1\\objects\\materials\\lionHeart.png"), 26.5);
	venom = Materials("venom", iLoadImage("images\\level1\\objects\\materials\\venom.png"), 28.5);
	tigerFang = Materials("tigerFang", iLoadImage("images\\level1\\objects\\materials\\tigerFang.png"), 30.5);
	tigerBone = Materials("tigerBone", iLoadImage("images\\level1\\objects\\materials\\tigerBone.png"), 32.5);

	cursedOil = Equipments("cursedOil", iLoadImage("images\\level1\\objects\\Equipments\\cursedOil.png"));
	bloodofCheetah = Equipments("bloodofCheetah", iLoadImage("images\\level1\\objects\\Equipments\\bloodofCheetah.png"));
	smokeBomb = Equipments("smokeBomb", iLoadImage("images\\level1\\objects\\Equipments\\smokeBomb.png"));
	Bomb = Equipments("Bomb", iLoadImage("images\\level1\\objects\\Equipments\\Bomb.png"));
	stunBomb = Equipments("stunBomb", iLoadImage("images\\level1\\objects\\Equipments\\stunBomb.png"));
	healthPotion = Equipments("healthPotion", iLoadImage("images\\level1\\objects\\Equipments\\healthPotion.png"));
	staminaPotion = Equipments("staminaPotion", iLoadImage("images\\level1\\objects\\Equipments\\staminaPotion.png"));

	armor1.name = "armor1";
	armor2.name = "armor2";
	armor3.name = "armor3";
	sword1.name = "sword1";
	sword2.name = "sword2";
	sword3.name = "sword3";
	backpack1.name = "backpack1";
	backpack2.name = "backpack2";

	makeHashes();

}

void setCoordinate(int slot, std::vector<Equipments>::iterator vecit) {
	if (slot == 1) {
		vecit->x = 382;
		vecit->y = 216;
	}
	else if (slot == 2) {
		vecit->x = 450;
		vecit->y = 216;
	}
	else if (slot == 3) {
		vecit->x = 518;
		vecit->y = 216;
	}
	else if (slot == 4) {
		vecit->x = 586;
		vecit->y = 216;
	}
}

Equipments craftAlgo() {
	std::string namez;
	Equipments X;
	ll hash = 0;
	for (auto itr4 = craftQ.begin();itr4 != craftQ.end(); itr4++) {
		hash = hash + ((convertToASCIIsum(itr4->name) * itr4->UniqueWeight) / itr4->n);

	}
	//std::cout << hash << std::endl;

	if (equipmentsHash.find(hash) == equipmentsHash.end()) {
		std::cout << "Not Combination Found" << std::endl;
		X.name = "garbage";
		return X;
	}
	else {
		return equipmentsHash.find(hash)->second;
	}

}


//adding to vector functions starts
void addMaterial(Materials item, int quantity) {
	int test = false;
	//std::cout << "Name Test : "<< item.name << std::endl;
	if (invItems.size() <= 20) {

		if (invItems.size() == 0) {
			item.n += quantity;
			item.slotID = slotIncrease;
			invItems.push_back(item);
			slotIncrease++;
		}
		else {

			for (auto itr = invItems.begin(); itr < invItems.end(); itr++) {

				//std::cout << itt-> name << " ; ";
				if (itr->name == item.name) {
					itr->n += quantity;
					test = true;
					break;
				}
			}

			if (!test) {
				item.n += quantity;
				item.slotID = slotIncrease;
				invItems.push_back(item);
				slotIncrease++;
			}
		}
	}
	else {
		std::cout << "InvItems Max Size Reached " << std::endl;
	}

}

void addtoQ(int id, bool refund = false) {
	bool qtest = false;
	//std::cout << craftQ.size() << std::endl;
	if (craftQ.size() <= 8) {

		Materials item;
		for (auto itr = invItems.begin(); itr< invItems.end(); itr++) {
			if (refund && itr->slotID == id) {
				for (auto it0 = craftQ.begin(); it0 != craftQ.end(); it0++) {
					if (it0->name == itr->name && it0->n > 0) {
						it0->n--;
						itr->n++;
					}
				}
			}

			else if (itr->slotID == id && itr->n > 0 && craftQ.size() < 8) {
				itr->n--;
				//std::cout << craftQ.size() << std::endl;
				item.name = itr->name;
				if (craftQ.size() == 0) {
					item.name = itr->name;
					item.img = itr->img;
					item.UniqueWeight = itr->UniqueWeight;
					item.n++;
					//item.slotID = qSlotIncrease;
					craftQ.push_back(item);
					//qSlotIncrease++;
				}
				else {

					for (auto it1 = craftQ.begin(); it1 < craftQ.end(); it1++) {

						if (it1->name == item.name) {
							it1->n++;
							qtest = true;
							break;
						}
					}

					if (!qtest && craftQ.size() < 8) {
						item.name = itr->name;
						item.img = itr->img;
						item.UniqueWeight = itr->UniqueWeight;
						item.n++;
						//item.slotID = qSlotIncrease;
						craftQ.push_back(item);
						//qSlotIncrease++;
					}
				}
			}
		}
	}
	else {
		std::cout << "Craft Queue Max Item Reached" << std::endl;
	}

}

void addtoBagpack(Equipments item) {
	int test = false;
	if (currentBItem < bLimit ) {

		if (bPack.size() == 0) {
			item.n++;
			currentBItem++;
			bPack.push_back(item);
		}
		else {

			for (auto it2 = bPack.begin(); it2 < bPack.end(); it2++) {

				if (it2->name == item.name) {
					it2->n++;
					currentBItem++;
					test = true;
					break;
				}
			}

			if (!test && bPack.size() < slotAvail) {
				item.n++;
				currentBItem++;
				bPack.push_back(item);	
			}
		}
	}
	
	else {
		std::cout << "Backpack Max Item Reached " << std::endl;
	}
	//std::cout << bPack.size() << std::endl;
}

void addEqp(Equipments item) {
	int test = false;
	if (equippedItemCount < equipLimit) {

		if (eqp.size() == 0) {
			eqp.push_back(item);
			equippedItemCount+= item.n;
		}
		else {

			for (auto it3 = eqp.begin(); it3 < eqp.end(); it3++) {

				if (it3->name == item.name) {
					it3->n += item.n;
					equippedItemCount += item.n;
					test = true;
					break;
				}
			}

			if (!test && eqp.size() < 2) {
				eqp.push_back(item);
				equippedItemCount += item.n;
			}
		}
	}

	else {
		std::cout << "Equipments Max Size Reached " << std::endl;
	}
	//std::cout << eqp.size() << std::endl;
}
//adding to vector functions ends


//showing vector elements fuctions starts
void showInvMats() {
	int xModifier, yModifier, slotCount = 0;

	for (auto itr1 = invItems.begin(); itr1 < invItems.end(); itr1++) {
		slotCount = itr1->slotID;

		xModifier = (slotCount - 1) % 4;
		yModifier = (slotCount - 1) / 4;

		if (itr1->n > 0)
		{
			iShowImageSmart(slotX + xModifier * 75, slotY - yModifier * 65, itr1->img);

			iSetColor(255, 255, 255);
			strcpy(buff1, (itr1->name).c_str());
			strcat(buff1, " : ");
			strcat(buff1, to_char(itr1->n));
			iText((slotX + xModifier * 75) - 5, (slotY - yModifier * 65) - 15, buff1, GLUT_BITMAP_HELVETICA_10);
		}
		//std::cout << slotCount << std::endl;

		if (slotCount == invItems.size()) {
			break;
		}
	}
}

void showCraftQ() {
	int qSlotCount = 1;
	for (auto itr2 = craftQ.begin(); itr2 < craftQ.end(); itr2++) {
		itr2->slotID = qSlotCount;
		//std::cout << "crafQ N count" << itr2->n << std::endl;
		if (itr2->n > 0) {
			iShowImageSmart(qX, qY, itr2->img);

			iSetColor(255, 255, 255);
			strcpy(buff1, (itr2->name).c_str());
			strcat(buff1, " : ");
			strcat(buff1, to_char(itr2->n));
			iText(qX, qY - 15, buff1, GLUT_BITMAP_HELVETICA_10);
		}
		//std::cout << slotCount << std::endl;

		qX = qX + 73;

		if (qSlotCount == craftQ.size()) {
			qX = invX + 35;
			qY = invY - 80;
			break;
		}

		qSlotCount++;
	}
}

void showBagpack() {

	int bpslotCount = 1;
	for (auto itr3 = bPack.begin(); itr3 < bPack.end(); itr3++) {

		itr3->slotID = bpslotCount;

		if (itr3 -> equipClick == false) {
			setCoordinate(bpslotCount, itr3);
			if (itr3->n > 0)
			{
				iShowImageSmart(itr3->x, itr3->y, itr3->img);

				iSetColor(255, 255, 255);
				strcpy(buff1, (itr3->name).c_str());
				strcat(buff1, " : ");
				strcat(buff1, to_char(itr3->n));
				iText(itr3->x - 5, itr3->y - 14, buff1, GLUT_BITMAP_HELVETICA_10);
			}
		}
		else if(drag && itr3->equipClick == true) {
			iShowImageSmart(mouseX, mouseY, itr3->img);
		}
		
		/*if (bpslotCount == bPack.size()) {
			break;
		}*/

		bpslotCount++;
	}
}

void showEqp() {

	int slotCount = 1;

	for (auto itr4 = eqp.begin(); itr4 < eqp.end(); itr4++) {

		itr4->slotID = slotCount;

		if (slotCount == 1) {
			itr4->x = 578;
			itr4->y = 383;
		}
		else if (slotCount == 2) {
			itr4->x = 578;
			itr4->y = 323;
		}

		if (itr4->n > 0)
		{
			iShowImageSmart(itr4->x, itr4->y, itr4->img);

			iSetColor(255, 255, 255);
			strcpy(buff1, (itr4->name).c_str());
			strcat(buff1, " : ");
			strcat(buff1, to_char(itr4->n));
			iText(itr4->x - 5, itr4->y - 11, buff1, GLUT_BITMAP_HELVETICA_10);
		}

		if (slotCount == eqp.size()) {
			break;
		}
		slotCount++;
	}

}
//showing vector elements fuctions ends

void CraftMechanics(int extend = 50, bool dir = ::direction) {

	for (auto itr = objects.begin(); itr != objects.end(); itr++) {
		for (auto i = objects[itr->first].begin(); i != objects[itr->first].end(); i++) {
			if (itr->first == "atree") {
				bool value = attackCollision(hero, *i, extend, dir);
				if (value) {
					addMaterial(wood, 10);
					addMaterial(oil, 10);
					addMaterial(venom, 10);
					addMaterial(silver, 10);
					addMaterial(steel, 10);
					addMaterial(rhinoHide, 10);
					addMaterial(rhinoHorn, 10);
					addMaterial(rhinoLiver, 10);
					addMaterial(boarHide, 10);
					addMaterial(animalFat, 10);
					addMaterial(meat, 10);
					addMaterial(lionFang, 10);
					addMaterial(lionSkin, 10);
					addMaterial(lionHeart, 10);
					addMaterial(tigerFang, 10);
					addMaterial(tigerBone, 10);

					objects["atree"].erase(i);
					break;

				}
			}
			else if (itr->first == "rock") {
				bool value = attackCollision(hero, *i, extend, dir);
				if (value) {
					if (rand() % 2 == 0) {
						addMaterial(steel, 1);
						objects["rock"].erase(i);
						break;
					}
					else {
						addMaterial(silver, 1);
						objects["rock"].erase(i);
						break;
					}
				}
			}
		}
	}

	for (auto itr = destructed.begin(); itr != destructed.end(); itr++) {
		for (auto i = destructed[itr->first].begin(); i != destructed[itr->first].end(); i++) {
			if (itr->first == "rhino") {
				bool value = attackCollision(hero, *i, extend, dir);
				if (value) {
					addMaterial(rhinoHide, 1);
					addMaterial(rhinoHorn, 1);
					addMaterial(rhinoLiver, 1);
					addMaterial(meat, 1);
					addMaterial(animalFat, 3);
					destructed["rhino"].erase(i);
					break;
				}
			}
			else if (itr->first == "boar") {
				bool value = attackCollision(hero, *i, extend, dir);
				if (value) {
					addMaterial(animalFat, 1);
					addMaterial(boarHide, 1);
					addMaterial(meat, 1);

					destructed["boar"].erase(i);
					break;
				}
			}
			else if (itr->first == "lion") {
				bool value = attackCollision(hero, *i, extend, dir);
				if (value) {
					addMaterial(lionFang, 1);
					addMaterial(lionSkin, 1);
					addMaterial(lionHeart, 1);
					addMaterial(venom, 1);

					destructed["lion"].erase(i);
					break;
				}

			}
			else if (itr->first == "tiger") {
				bool value = attackCollision(hero, *i, extend, dir);
				if (value) {
					addMaterial(tigerFang, 1);
					addMaterial(tigerBone, 1);
					addMaterial(oil, 1);

					destructed["tiger"].erase(i);
					break;
				}

			}
		}
	}

}

bool testG(std::string itemname) {
	std::vector<Equipments>::iterator iter1;
	for (iter1 = eqp.begin(); iter1 != eqp.end(); iter1++) {
		if (iter1->name == itemname) {
			iter1->n--;
			equippedItemCount --;
			return true;
		}
	}
	if (iter1 == bPack.end()) {
		return false;
	}
}

bool testB(int ID, bool equipDrop, bool reset = false) {
	std::vector<Equipments>::iterator iter2;
	Equipments ToBeEquipped;
	
	if (reset) {
		for (iter2 = bPack.begin(); iter2 != bPack.end(); iter2++) {
			if (iter2->slotID == ID) {
				iter2->equipClick = false;
			}
		}
	}
	else if (!equipDrop) {
		for (iter2 = bPack.begin(); iter2 != bPack.end(); iter2++) {
			if (iter2->slotID == ID) {
				iter2->equipClick = true;
				return true;
			}
		}
		if (iter2 == bPack.end()) {
			return false;
		}
	}
	else {
		for (iter2 = bPack.begin(); iter2 != bPack.end(); iter2++) {
			if (iter2->slotID == ID) {
				ToBeEquipped.name = iter2->name;
				ToBeEquipped.img = iter2->img;
				ToBeEquipped.n = iter2->n;

				addEqp(ToBeEquipped);
				currentBItem -= iter2->n;
				iter2-> n = 0;
				iter2->equipClick = false;
				return true;
			}
		}
		if (iter2 == bPack.end()) {
			return false;
		}
	}
	
}

void equips(int q) {
	std::string equipItem;

	for (auto eItr = eqp.begin(); eItr != eqp.end(); eItr++) {

		if (eItr == eqp.end()) {
			std::cout << "Nothing Equipped" << std::endl;
		}
		else if (eItr->slotID == q) {
			equipItem = eItr->name;

			if (equipItem == "smokeBomb") {
				stunEquip = false;
				bombEquip = false;
				smokeEquip = true;
				hpotionEquip = false;
				stpotionEquip = false;
				cheetahbloodEquip = false;
				coilEquip = false;
			}
			else if (equipItem == "stunBomb") {
				stunEquip = true;
				bombEquip = false;
				smokeEquip = false;
				hpotionEquip = false;
				stpotionEquip = false;
				cheetahbloodEquip = false;
				coilEquip = false;
			}
			else if (equipItem == "Bomb") {
				stunEquip = false;
				bombEquip = true;
				smokeEquip = false;
				hpotionEquip = false;
				stpotionEquip = false;
				cheetahbloodEquip = false;
				coilEquip = false;
			}
			else if (equipItem == "healthPotion") {
				stunEquip = false;
				bombEquip = false;
				smokeEquip = false;
				hpotionEquip = true;
				stpotionEquip = false;
				cheetahbloodEquip = false;
				coilEquip = false;
			}
			else if (equipItem == "staminaPotion") {
				stunEquip = false;
				bombEquip = false;
				smokeEquip = false;
				hpotionEquip = false;
				stpotionEquip = true;
				cheetahbloodEquip = false;
				coilEquip = false;
			}
			else if (equipItem == "bloodofCheetah") {
				stunEquip = false;
				bombEquip = false;
				smokeEquip = false;
				hpotionEquip = false;
				stpotionEquip = false;
				cheetahbloodEquip = true;
				coilEquip = false;
			}
			else if (equipItem == "cursedOil") {
				stunEquip = false;
				bombEquip = false;
				smokeEquip = false;
				hpotionEquip = false;
				stpotionEquip = false;
				cheetahbloodEquip = false;
				coilEquip = true;

			}
			/*else {
				stunEquip = false;
				bombEquip = false;
				smokeEquip = false;
				hpotionEquip = false;
				stpotionEquip = false;
				cheetahbloodEquip = false;
				coilEquip = false;
				std::cout << "Equip False" << std::endl;
			}*/
		}
	}

	equipItem.clear();
}

void deleteCheck() {

	if (eqp.size() == 0) {
		stunEquip = false;
		bombEquip = false;
		smokeEquip = false;
		hpotionEquip = false;
		stpotionEquip = false;
		cheetahbloodEquip = false;
		coilEquip = false;
		//std::cout << "Equip False" << std::endl;
	}
	else {
		for (auto dc = eqp.begin(); dc != eqp.end(); dc++) {
			if (dc->n < 1) {
				eqp.erase(dc);
				break;
			}
		}
	}
	
	for (auto dc = bPack.begin(); dc != bPack.end(); dc++) {
		if (dc->n < 1) {
			bPack.erase(dc);
			break;
		}
	}
	if (craftQ.size() != 0) {
		for (auto dc = craftQ.begin(); dc != craftQ.end(); dc++) {
			if (dc->n < 1) {
				craftQ.erase(dc);
				break;
			}
		}
	}
	
}

void matClick(int mx, int my, bool refund = false) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (mx > invX + 380 + (75 * j) && mx < invX + 380 + (75 * j) + 45 && my > invY - (i * 65) + 295 && my < invY - (i * 65) + 295 + 45) {
				if (refund) {
					addtoQ(((j + 1) + 4 * (i)), true);
				}
				else {
					addtoQ( (j + 1) + 4 * i ); // col + maxColVal*(row - 1) ; considering row, col starts from 1
				}
			}
		}
	}
}

void qClick(int mx, int my) {
	Equipments X;
	if (mx > 948 && mx < 1003 && my > 128 && my < 148) {
		X = craftAlgo();
		
		if (X.name == "garbage") {
			qSlotIncrease = 1;
			craftQ.clear();
		}
		else if (X.name == "backpack1") {
			backpackLv = 1;
			qSlotIncrease = 1;
			craftQ.clear();
		}
		else if (X.name == "backpack2") {
			backpackLv = 2;
			qSlotIncrease = 1;
			craftQ.clear();
		}
		else if (X.name == "backpack3") {
			backpackLv = 3;
			qSlotIncrease = 1;
			craftQ.clear();
		}
		else if (X.name == "armor1") {
			armorLv = 1;
			qSlotIncrease = 1;
			craftQ.clear();
		}
		else if (X.name == "armor2") {
			armorLv = 2;
			qSlotIncrease = 1;
			craftQ.clear();
		}
		else if (X.name == "armor3") {
			armorLv = 3;
			qSlotIncrease = 1;
			craftQ.clear();
		}
		else if (X.name == "sword1") {
			swordLv = 1;
			qSlotIncrease = 1;
			craftQ.clear();
		}
		else if (X.name == "sword2") {
			swordLv = 2;
			qSlotIncrease = 1;
			craftQ.clear();
		}
		else if (X.name == "sword3") {
			swordLv = 3;
			qSlotIncrease = 1;
			craftQ.clear();
		}
		else {
			std::cout << "CRAFTED: " << X.name << std::endl;
			addtoBagpack(X);
			qSlotIncrease = 1;
			craftQ.clear();
		}
		
	}
	else if (mx > 948 && mx < 1003 && my > 102 && my < 122) {
		std::cout << "CLEAR" << std::endl;
		qSlotIncrease = 1;
		craftQ.clear();
	}
}

void vectprint() {
	for (auto vItr = invItems.begin(); vItr < invItems.end(); vItr++) {
		std::cout << vItr->slotID << vItr->name << "`";
	}
	std::cout << "\n";
}

void Craft() {
	CraftMechanics();
	//vectprint();
}


#endif
