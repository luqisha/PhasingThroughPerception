#ifndef VISUALS
#define VISUALS_H_INCLUDED

#include "Moves.h"

void showHero(bool x, int skip) {
	delay++;
	if (hero.running == false) {

		if (delay > 10) {
			if (x == false)
			{
				iShowImageSmart(hero.x, hero.y, hero.imagesF[0]);
			}
			else {
				iShowImageSmart(hero.x, hero.y, hero.imagesB[0]);
			}
		}
		else {
			/*
			Debug info : Same thing as last else just implemented to hold delay
			*/

			/*
			Debug info : for the reason the numberofFrames gets reseted.
			*/
			if (hero.numberOfFrames == 0) {
				hero.numberOfFrames = hero.imagesF.size();
			}

			hero.frame = abs(hero.frame % (hero.numberOfFrames * skip)) + 1;
			hero.frame = abs(hero.frame % (hero.numberOfFrames * skip)) + 1;

			hero.frame = min(hero.frame, hero.numberOfFrames * skip);
			int printframe = hero.frame / skip;
			/*
				Debug info : if the printframe becomes 0 for skip frames then
							 the hero's standing frame keeps flashing
							 This can be solved by detecting 0th frame and
							 incrementing it.
			*/
			if (printframe == 0) {
				printframe++;
			}
			if (x == false)
			{
				iShowImageSmart(hero.x, hero.y, hero.imagesF[printframe]);
				hero.frame++;
			}
			else {
				iShowImageSmart(hero.x, hero.y, hero.imagesB[printframe]);
				hero.frame++;
			}
		}

	}
	else {
		/*
			Debug info : for the reason the numberofFrames gets reseted.
		*/
		if (hero.numberOfFrames == 0) {
			hero.numberOfFrames = hero.imagesF.size();
		}
		delay = 0;
		hero.frame = abs(hero.frame % (hero.numberOfFrames * skip)) + 1;
		hero.frame = abs(hero.frame % (hero.numberOfFrames * skip)) + 1;

		hero.frame = min(hero.frame, hero.numberOfFrames * skip);
		int printframe = hero.frame / skip;
		/*
			Debug info : if the printframe becomes 0 for skip frames then
						 the hero's standing frame keeps flashing
						 This can be solved by detecting 0th frame and
						 incrementing it.
		*/
		if (printframe == 0) {
			printframe++;
		}
		if (x == false)
		{
			iShowImageSmart(hero.x, hero.y, hero.imagesF[printframe]);
			hero.frame++;
		}
		else {
			iShowImageSmart(hero.x, hero.y, hero.imagesB[printframe]);
			hero.frame++;
		}
	}

}

void showBoar(GameObject& obj, bool x, int skip, bool stand) {

	//health
	iSetColor(0, 0, 0);
	iFilledRectangle(obj.x - 1, obj.y + obj.height + 4, obj.width + 1, 9);
	iSetColor(232, 21, 21);
	ll printhealth = (obj.health / obj.maxHealth) * obj.width;
	iFilledRectangle(obj.x, obj.y + obj.height + 5, printhealth, 7);

	if (stand || obj.stunned) {

		if (x == false)
		{
			iShowImage(obj.x, obj.y, obj.width, obj.height, obj.imagesF[0]);
		}
		else {
			iShowImage(obj.x, obj.y, obj.width, obj.height, obj.imagesB[0]);
		}

	}
	else {
		/*
			Debug info : for the reason the numberofFrames gets reseted.
		*/
		if (obj.numberOfFrames == 0) {
			obj.numberOfFrames = obj.imagesF.size();
		}

		obj.frame = abs(obj.frame % (obj.numberOfFrames * skip)) + 1;
		obj.frame = abs(obj.frame % (obj.numberOfFrames * skip)) + 1;

		obj.frame = min(obj.frame, obj.numberOfFrames * skip);
		int printframe = obj.frame / skip;
		if (printframe == 0) {
			printframe++;
		}

		/*
			Debug info : if the printframe becomes 0 for skip frames then
						 the hero's standing frame keeps flashing
						 This can be solved by detecting 0th frame and
						 incrementing it.
		*/


		if (x == false)
		{
			iShowImage(obj.x, obj.y, obj.width, obj.height, obj.imagesF[printframe]);
			obj.frame++;
		}
		else {
			iShowImage(obj.x, obj.y, obj.width, obj.height, obj.imagesB[printframe]);
			obj.frame++;
		}
	}

}

void showRhino(GameObject& obj, bool x, int skip, bool stand) {

	//health
	iSetColor(0, 0, 0);
	iFilledRectangle(obj.x +5, obj.y + obj.height + 20, obj.width + 1, 9);
	iSetColor(232, 21, 21);
	ll printhealth = (obj.health / obj.maxHealth) * obj.width;
	iFilledRectangle(obj.x +6, obj.y + obj.height + 21, printhealth, 7);
	iShowImage(obj.x + 3, obj.y + obj.height + 10, 40, 40, obj.icon);



	if (stand || obj.stunned) {
		//std::cout << "HIT" << std::endl;

		if (x == false)
		{
			iShowImageSmart(obj.x, obj.y, obj.imagesF[0], 2);
		}
		else {
			iShowImageSmart(obj.x, obj.y, obj.imagesB[0], 2);
		}

	}
	else {
		/*
			Debug info : for the reason the numberofFrames gets reseted.
		*/
		if (obj.numberOfFrames == 0) {
			obj.numberOfFrames = obj.imagesF.size();
		}

		obj.frame = abs(obj.frame % (obj.numberOfFrames * skip)) + 1;
		obj.frame = abs(obj.frame % (obj.numberOfFrames * skip)) + 1;

		obj.frame = min(obj.frame, obj.numberOfFrames * skip);
		int printframe = obj.frame / skip;
		/*
			Debug info : if the printframe becomes 0 for skip frames then
						 the hero's standing frame keeps flashing
						 This can be solved by detecting 0th frame and
						 incrementing it.
		*/

		if (printframe == 0) {
			printframe++;
		}
		if (x == false)
		{
			iShowImageSmart(obj.x, obj.y, obj.imagesF[printframe], 2);

			obj.frame++;
		}
		else {
			iShowImageSmart(obj.x, obj.y, obj.imagesB[printframe], 2);

			obj.frame++;
		}
	}

}

void showDemon(GameObject& demon, bool x) {

	//health
	iSetColor(0, 0, 0);
	iFilledRectangle(demon.x - 4, demon.y + demon.height + 40, demon.width + 1, 9);
	iSetColor(232, 21, 21);
	ll printhealth = (demon.health / demon.maxHealth) * demon.width;
	iFilledRectangle(demon.x - 4, demon.y + demon.height + 40, printhealth, 7);

	if (demon.bosssense && abs(hero.x - demon.x) > 300) {
		if (x == false) {
			demon.x -= 1;
		}
		else {
			demon.x += 1;
		}
		demon.frame = demon.frame % 80;
		if (demon.frame < 1) {
			demon.frame = 1;
		}
		if (x == false) {
			iShowImageSmart(demon.x, demon.y, demon.imagesB[demon.frame / 8]);
		}
		else {
			iShowImageSmart(demon.x, demon.y, demon.imagesF[demon.frame / 8]);
		}
		demon.frame++;
	}
	else {
		if (x == false) {
			iShowImageSmart(demon.x, demon.y, demon.imagesB[0]);
		}
		else {
			iShowImageSmart(demon.x, demon.y, demon.imagesF[0]);
		}
	}
}

void showLion(GameObject& obj, bool x, int skip, bool stand) {

	//health
	iSetColor(0, 0, 0);
	iFilledRectangle(obj.x + 15, obj.y + obj.height + 20, obj.width-30, 9);
	iSetColor(232, 21, 21);
	ll printhealth = (obj.health / obj.maxHealth) * (obj.width-30);
	iFilledRectangle(obj.x + 14, obj.y + obj.height + 21, printhealth, 7);
	iShowImage(obj.x-3 , obj.y + obj.height + 16, 20, 20, obj.icon);

	if (obj.lionHittable) {
		obj.lionHitFrame++;
		if (obj.lionHitFrame > 42 || obj.lionHitFrame < 0) {
			obj.lionHitFrame = 0;
		}
		int printframe = obj.lionHitFrame / 3;
		if (x == false) {
			iShowImageSmart(obj.x, obj.y, obj.attackF[printframe], 5);
		}
		else {
			iShowImageSmart(obj.x, obj.y, obj.attackB[printframe], 5);
		}
		

	}else if (stand || obj.stunned) {
		

		if (x == false)
		{
			iShowImageSmart(obj.x, obj.y, obj.imagesF[0], 5);
		}
		else {
			iShowImageSmart(obj.x, obj.y, obj.imagesB[0], 5);
		}

	}
	else {
		/*
			Debug info : for the reason the numberofFrames gets reseted.
		*/
		

		if (obj.numberOfFrames == 0) {
			obj.numberOfFrames = obj.imagesF.size();
		}

		obj.frame = abs(obj.frame % (obj.numberOfFrames * skip)) + 1;
		/*obj.frame = abs(obj.frame % (obj.numberOfFrames * skip)) + 1;

		obj.frame = min(obj.frame, obj.numberOfFrames * skip);*/
		int printframe = obj.frame / skip;
		//std::cout << printframe << std::endl;
		/*
			Debug info : if the printframe becomes 0 for skip frames then
						 the hero's standing frame keeps flashing
						 This can be solved by detecting 0th frame and
						 incrementing it.
		*/

		if (printframe == 0) {
			printframe++;
		}
		if (x == false)
		{
			iShowImageSmart(obj.x, obj.y, obj.imagesF[printframe], 5);

			obj.frame++;
		}
		else {
			iShowImageSmart(obj.x, obj.y, obj.imagesB[printframe], 5);

			obj.frame++;
		}
	}

}

void showTiger(GameObject& obj, bool x, int skip, bool stand) {

	//health
	iSetColor(0, 0, 0);
	iFilledRectangle(obj.x + 8, obj.y + obj.height + 5, obj.width - 45, 9);
	iSetColor(232, 21, 21);
	ll printhealth = (obj.health / obj.maxHealth) * (obj.width - 45);
	iFilledRectangle(obj.x + 7, obj.y + obj.height +6, printhealth, 7);
	iShowImage(obj.x - 3, obj.y + obj.height, 20, 20, obj.icon);

	if (obj.tigerHittable) {
		obj.tigerHitFrame++;
		if (obj.tigerHitFrame > 68 || obj.tigerHitFrame < 0) {
			obj.tigerHitFrame = 0;
		}
		int printframe = obj.tigerHitFrame / 2;
		
		if (x == false) {
			iShowImageSmart(obj.x, obj.y, obj.attackF[printframe], 5);
		}
		else {
			iShowImageSmart(obj.x, obj.y, obj.attackB[printframe], 5);
		}


	}
	else if (stand || obj.stunned) {


		if (x == false)
		{
			iShowImageSmart(obj.x, obj.y, obj.imagesF[0], 5);
		}
		else {
			iShowImageSmart(obj.x, obj.y, obj.imagesB[0], 5);
		}

	}
	else {
		/*
			Debug info : for the reason the numberofFrames gets reseted.
		*/


		if (obj.numberOfFrames == 0) {
			obj.numberOfFrames = obj.imagesF.size();
		}

		obj.frame = abs(obj.frame % (obj.numberOfFrames * skip)) + 1;
		/*obj.frame = abs(obj.frame % (obj.numberOfFrames * skip)) + 1;

		obj.frame = min(obj.frame, obj.numberOfFrames * skip);*/
		int printframe = obj.frame / skip;
		//std::cout << printframe << std::endl;
		/*
			Debug info : if the printframe becomes 0 for skip frames then
						 the hero's standing frame keeps flashing
						 This can be solved by detecting 0th frame and
						 incrementing it.
		*/

		if (printframe == 0) {
			printframe++;
		}
		if (x == false)
		{
			iShowImageSmart(obj.x, obj.y, obj.imagesF[printframe], 5);

			obj.frame++;
		}
		else {
			iShowImageSmart(obj.x, obj.y, obj.imagesB[printframe], 5);

			obj.frame++;
		}
	}

}

void showObj(int change) {
	for (auto itr = objects.begin(); itr != objects.end(); itr++) {

		for (auto i = objects[itr->first].begin(); i != objects[itr->first].end(); i++) {

			if (itr->first == "boar") {
				(*i).x -= change;
				bool x = hero.x < (*i).x;
				showBoar((*i), x, 7, (abs(hero.x - (*i).x) > 600));
			}
			else if (itr->first == "rhino") {

				(*i).x -= change;

				bool x = hero.x < (*i).x;
				showRhino((*i), x, 7  , !(*i).rhinosense);

			}
			else if (itr->first == "lion") {

				(*i).x -= change;

				bool x = hero.x < (*i).x;
				showLion((*i), x, 4, !(*i).lionsense);

			}
			else if (itr->first == "tiger") {
				(*i).x -= change;

				bool x = hero.x < (*i).x;
				showTiger((*i), x, 3, !(*i).tigersense);
			}
			else {
				(*i).x -= change;
				(*i).show(false, 1);
			}

		}
	}

	


	for (auto itr = destructed.begin(); itr != destructed.end(); itr++) {

		for (auto i = destructed[itr->first].begin(); i != destructed[itr->first].end(); i++) {
			(*i).x -= change;
			if (itr->first == "boar") {
				(*i).showDead();
			}else if (itr->first == "rhino") {
				(*i).showDead();
			}
			else if (itr->first == "lion") {
				(*i).showDead();
			}
			else if (itr->first == "tiger") {
				(*i).showDead();
			}

		}
	}

}

void showBoss(int change) {
	boss["demon"].x -= change;
	showDemon(boss["demon"], hero.x > boss["demon"].x);

	/*for (auto itr = boss.begin(); itr != boss.end(); itr++) {
		boss[itr->first].x -= change;
		showDemon(boss[itr->first]);
	}*/
}

void animateBlood(int x = bloodX, int y = bloodY, int skip = 3) {
	bloodAnimation = true;
	bloodX = x;
	bloodY = y;
	iShowImageSmart(bloodX, bloodY, blood[bloodFrame / skip], 4);
	bloodFrame++;
	if (bloodFrame >= (6 * skip + 1)) {
		bloodAnimation = false;
		bloodFrame = 0;
		bloodX = -(int)1e9;
	}
}

void animateSmoke(Item& item) {
	iShowImageSmart(item.pos, level, smoke[smokeFrame / 18]);
	smokeFrame++;
	if (smokeFrame >= 108) {
		smokeFrame = 54;
	}
}

void animateStun(Item& item) {
	if (stunFrame <= 36) {
		iShowImageSmart(item.pos - 100, level, stun[stunFrame / 6]);
	}
	stunFrame++;
}

void animateBomb() {
	if (bombFrame >= 30) {
		bombFrame = 0;
		bombAnimation = false;
		bombX = -(int)1e9;
		return;
	}
	iShowImageSmart(bombX - 100, level, bomb[bombFrame / 6]);
	bombFrame++;
}

void Rain() {
	int x = 0;
	int y = 0;
	iSetColor(105, 122, 140);
	for (int i = 0; i < 80; i++) {
		x = rand() % 1366;
		y = level + rand() % 768;
		iRotate(x, y, -45);
		iFilledRectangle(x, y, 2, 20);
		//iFill(x, y, x + 15, y + 15);
		iUnRotate();
	}

	RainSound();
}

int cutsceneFrame = 0;
int cutscenedelay = 1;
void initializeCutScene1() {
	act1 = loadImage(act1, "images\\Story\\Act 1\\", 14);
	cutsceneFrame = 0;
	cutscenedelay = 1;
}

void initializeCutScene2() {
	act2 = loadImage(act2, "images\\Story\\Act 2\\", 9);
	cutsceneFrame = 0;
	cutscenedelay = 1;
}

void intializeCutScene3() {
	act3 = loadImage(act3, "images\\Story\\Act 3\\", 4);
	act4 = loadImage(act4, "images\\Story\\Act 4\\", 6);
	cutsceneFrame = 0;
	cutscenedelay = 1;
	
}

int cutscene(int n){
	inCutScene = true;
	if (n == 1) {
		if (++cutscenedelay % 150 == 0) {
			cutsceneFrame++;
		}
		if (cutsceneFrame > 14) {
			inCutScene = false;
			cutsceneFrame = 0;
			cutscenedelay = 1;
			return 0;
		}

		iShowImage(0, 0, 1366, 768, act1[cutsceneFrame]);
	}
	else if (n == 2) {
		
		if (++cutscenedelay % 150 == 0) {
			cutsceneFrame++;
		}
		if (cutsceneFrame > 9) {
			inCutScene = false;
			cutsceneFrame = 0;
			cutscenedelay = 1;
			return 0;
		}

		iShowImage(0, 0, 1366, 768, act2[cutsceneFrame]);
		
	}
	else if (n == 3) {
		if (!tanakeDefeated) {
			if (++cutscenedelay % 150 == 0) {
				cutsceneFrame++;
			}
			if (cutsceneFrame > 4) {
				inCutScene = false;
				cutsceneFrame = 0;
				cutscenedelay = 1;
				return 0;
			}

			iShowImage(0, 0, 1366, 768, act3[cutsceneFrame]);
		}
		else if (!DemonDefeated) {
			if (++cutscenedelay % 150 == 0) {
				cutsceneFrame++;
			}
			if (cutsceneFrame > 4) {
				inCutScene = false;
				cutsceneFrame = 0;
				cutscenedelay = 1;
				return 0;
			}

			iShowImage(0, 0, 1366, 768, act4[cutsceneFrame]);
		}
	}

	return 1;
}

#endif
