#ifndef BOSS
#define BOSS_H_INCLUDED

#include "Craft.h"
bool InitializeLevel1();
//Demon

//Demon Power1 Varibales
double demonPow1cooldown = 0; // 3
bool demonPow1active = false;
int demonPow1point = hero.x;
int demonPow1radiusx = 20;
std::vector<unsigned int> demonpower1images;
int demonPow1frame = 0;
//Demon Power 1 variables ends

//Demon Power2 Varibales
double demonPow2cooldown = 0;
bool demonPow2active = false;
int demonPow2pointx = hero.x + 300;

int demonPow2pointy = 268 + rand() % (hero.height) + 20;
bool demonPow2hit = false;
double demonPow2push = 12;
std::vector<unsigned int> demonpower2imagesf, demonpower2imagesb;
int demonPow2frame = 0;
//Demon Power2 variables ends

//Demon Power3 Variables

double demonPow3cooldown = 0; // 2
bool demonPow3active = false;
int demonPow3point = hero.x;
int demonPow3radiusx = 50;
std::vector<unsigned int> demonpower3images;
int demonPow3frame = 0;
double demonPow3jumpmodifier = 5;
//Demon Power2 variables ends

void intializeDemon(int x) {
	boss.clear();
	GameObject demon(x, level, 60, 60, 630, 10);
	demon.numberOfFrames = 10;
	demon.loadImageF("images\\Boss\\Demon\\forward\\", 10);
	demon.loadImageB("images\\Boss\\Demon\\backward\\", 10);
	demon.maxHealth = 1000;
	demon.health = 1000;
	boss["demon"] = demon;
	demonpower1images = loadImage(demonpower1images, "images\\Boss\\Demon\\power1\\", 13);
	demonpower3images = loadImage(demonpower3images, "images\\Boss\\Demon\\power3\\", 11);
	demonpower2imagesf = loadImage(demonpower2imagesf, "images\\Boss\\Demon\\power2f\\", 6);
	demonpower2imagesb = loadImage(demonpower2imagesb, "images\\Boss\\Demon\\power2b\\", 6);
}

int demonBehavior(GameObject& demon) {

	if (hero.x > demon.x + demon.width && abs(hero.x - demon.x - demon.width) <= demon.bossvision) {
		demon.bosssense = true;
		portal = true;
	}

	if (hero.x < demon.x && abs(hero.x - demon.x) <= demon.bossvision) {
		demon.bosssense = true;
		portal = true;
	}

	return demon.bosssense;
}

void initiatedemonPower1() {
	int random = rand() % 30;
	int side = rand() % 2;
	int point = hero.x + hero.width / 2;

	if (side == 0) {
		point = point - random;
	}
	else {
		point = point + random;
	}


	TimeStamp t(1.5);
	counters["demonpower1"] = t;
	demonPow1active = true;
	demonPow1point = point;
	PowerSound1();
}

void demonPower1() {
	//here I wll show power

	//here I will make damages

	if (demonPow1active) {
		bool over = counters["demonpower1"].Counter();
		if (over) {
			demonPow1active = false;
			demonPow1point = hero.x;
			counters.erase("demonpower1");

		}
		else {

			demonPow1point -= change;

			int powerleft = demonPow1point - demonPow1radiusx;
			int poweright = demonPow1point + demonPow1radiusx;

			bool collisionX = hero.x > powerleft && hero.x < poweright ||
				hero.x + hero.width > powerleft && hero.x + hero.width < poweright;

			if (collisionX) {
				heroHealth -= 1;
			}
			demonPow1frame = demonPow1frame % 13;
			iShowImage(powerleft - 15, level, poweright - powerleft + 30, 600, demonpower1images[demonPow1frame]);
			demonPow1frame++;
		}
	}
	else {
		if (demonPow1cooldown <= 0) {
			initiatedemonPower1();
			demonPow1cooldown = 300;
		}
		else {
			demonPow1cooldown--;
		}
	}

}

void demonPower2() {


	demonPow2active = true;

	if (!demonPow2hit) {
		demonPow2pointx -= 5;
		demonPow2pointx -= change;
		bool collisionx = demonPow2pointx < hero.x + hero.width;
		bool collisiony = demonPow2pointy > hero.y;
		if (collisionx && collisiony) {
			demonPow2hit = true;
		}
		demonPow2frame = demonPow2frame % 6;
		if (demonPow2frame < 1) {
			demonPow2frame = 1;
		}
		iShowImage(demonPow2pointx, demonPow2pointy, 90, 90, demonpower2imagesf[demonPow2frame]);
		demonPow2frame++;
	}
	else {
		hero.x -= demonPow2push;
		demonPow2push -= .2;
		heroHealth -= 0.5;
		if (demonPow2push < 0) {
			demonPow2active = false;
			demonPow2pointx = hero.x + 300;
			demonPow2pointy = level + rand() % (hero.height) + 20;
			demonPow2hit = false;
			demonPow2push = 12;
		}
	}

}

void demonPower2Actual() {
	if (demonPow2cooldown <= 0) {

		if (!demonPow2hit) {
			demonPow2pointx -= change;
			if (hero.x < boss["demon"].x) {
				demonPow2pointx -= 5;
			}
			else {
				demonPow2pointx += 5;
			}
			bool collisionxnegative = demonPow2pointx < hero.x + hero.width && hero.x - demonPow2pointx < hero.width&& hero.x < boss["demon"].x;
			bool collisiony = demonPow2pointy > hero.y;
			bool collisionxpostive = demonPow2pointx > hero.x && demonPow2pointx - hero.x < hero.width&& hero.x > boss["demon"].x;
			bool collisionx = collisionxnegative || collisionxpostive;


			if (collisionx && collisiony) {
				//replace jump with dodge
				if (!jump) {
					demonPow2hit = true;
				}
			}
			else if (demonPow2pointx < hero.x - hero.width && hero.x < boss["demon"].x || demonPow2pointx > hero.x && hero.x > boss["demon"].x) {
				demonPow2active = false;
				demonPow2pointx = hero.x + 300;
				demonPow2pointy = level + rand() % (hero.height);
				demonPow2hit = false;
				demonPow2push = 12;
				demonPow2frame = 0;
				demonPow2cooldown = 30;
			}



			demonPow2frame = demonPow2frame % 6;
			if (demonPow2frame < 1) {
				demonPow2frame = 1;
			}

			if (hero.x < boss["demon"].x) {
				iShowImage(demonPow2pointx, demonPow2pointy, 90, 90, demonpower2imagesf[demonPow2frame]);
			}
			else {
				iShowImage(demonPow2pointx, demonPow2pointy, 90, 90, demonpower2imagesb[demonPow2frame]);
			}

			demonPow2frame++;

		}
		else {
			//std::cout << "called" << std::endl;
			if (hero.x < boss["demon"].x) {
				hero.x -= demonPow2push;
			}
			else {
				hero.x += demonPow2push;
			}
			demonPow2push -= .2;
			heroHealth -= 0.5;
			if (demonPow2push < 0) {
				demonPow2active = false;
				demonPow2pointx = hero.x + 300;
				demonPow2pointy = level + rand() % (hero.height);
				demonPow2hit = false;
				demonPow2push = 12;
				demonPow2frame = 0;
				demonPow2cooldown = 30;
			}
		}
	}
	else {
		demonPow2active = false;
		demonPow2cooldown--;
	}
}

void initiatedemonPower3() {
	int random = rand() % 50;
	int side = rand() % 2;
	int point = hero.x + hero.width / 2;

	if (side == 0) {
		point = point - random;
	}
	else {
		point = point + random;
	}

	PowerSound3();
	TimeStamp t(1);
	counters["demonpower3"] = t;
	demonPow3active = true;
	demonPow3point = point;
}

void demonPower3() {
	//here I wll show power

	//here I will make damages

	if (demonPow3active) {
		bool over = counters["demonpower3"].Counter();
		if (over) {
			demonPow3active = false;
			demonPow3point = hero.x;
			demonPow3jumpmodifier = 5;
			counters.erase("demonpower3");
		}
		else {

			demonPow3point -= change;


			int powerleft = demonPow3point - demonPow3radiusx;
			int poweright = demonPow3point + demonPow3radiusx;

			bool collisionX = hero.x > powerleft && hero.x < poweright ||
				hero.x + hero.width > powerleft && hero.x + hero.width < poweright;

			if (collisionX) {
				heroHealth -= .5;
				hero.y += demonPow3jumpmodifier;
				if (demonPow3jumpmodifier < .1) {
					demonPow3jumpmodifier -= .1;
				}
			}
			demonPow3frame = demonPow3frame % 11;
			iShowImage(powerleft - 15, level, poweright - powerleft + 30, 180, demonpower3images[demonPow3frame]);
			demonPow3frame++;
		}
	}
	else {
		if (demonPow3cooldown == 0) {
			initiatedemonPower3();
			demonPow3cooldown = 200;
		}
		else {
			demonPow3cooldown--;
		}
	}

}

void updateDemonBehavior0() {
	for (auto i = boss.begin(); i != boss.end(); i++) {
		if (i->first == "demon" && demonBehavior(i->second)) {
			if (demonPow2active) {
				demonPower2();
			}
			else if (abs(hero.x - boss["demon"].x) < 400) {
				demonPower2();
			}
			else if (demonPow1active) {
				demonPower1();
			}
			else if (demonPow3active) {
				demonPower3();
			}
			else {
				int random = rand() % 2;
				if (random == 0) {
					demonPower1();
				}
				else {
					demonPower3();
				}
			}
		}
	}
}

void updateDemonBehavior() {
	//reduce the cooldowns make the boss harder

	for (auto i = boss.begin(); i != boss.end(); i++) {
		if (i->first == "demon" && demonBehavior(i->second)) {
			if (demonPow2active) {
				demonPower2Actual();
			}
			else if (demonPow1active) {
				demonPower1();
			}
			else if (demonPow3active) {
				demonPower3();
			}
			else {

				int random = rand() % 3;
				if (random == 0) {
					demonPower1();
				}
				else if (random == 1) {
					demonPower3();
				}
				else {
					demonPow2frame = 0;
					demonPow2pointx = boss["demon"].x;
					demonPow2active = true;
					demonPower2Actual();
				}
			}
		}
	}
}


//Takane 

std::vector<unsigned int> tanakeNormalAttackF, tanakeNormalAttackB;
std::vector<unsigned int> tanakehardSlashF, tanakehardSlashB, tanakehardSlashProF, tanakehardSlashProB;
std::vector<unsigned int> tanakeSuperF, tanakeSuperB;
int tanakeNormalAttackFrame = 0;
int tanakeHardSlashFrames1 = 0;
int tanakeHardSlashFrames2 = 0;
bool tanakeHardSlashActive = false;
int tanakeHardSlashProx = 0;
int tanakeHardSlashProy = 0;
int tanakeHardSlashCooldown = 250;
int tanakeSuperFrame = 0;
bool tanakeSuperActive = false;
int tanakeSuperCooldown = 600;

void intializeTanake(int x) {
	boss.clear();
	GameObject tanake(x, level, 60, 60, 700, 10);
	tanake.numberOfFrames = 6;
	tanake.loadImageF("images\\Boss\\Tanake\\runF\\", 5);
	tanake.loadImageB("images\\Boss\\Tanake\\runB\\", 5);
	tanakeNormalAttackF = loadImage(tanakeNormalAttackF, "images\\Boss\\Tanake\\attackF\\", 13);
	tanakeNormalAttackB = loadImage(tanakeNormalAttackB, "images\\Boss\\Tanake\\attackB\\", 13);
	tanakehardSlashB = loadImage(tanakehardSlashB, "images\\Boss\\Tanake\\hardslash\\hardslashB\\", 34);
	tanakehardSlashF = loadImage(tanakehardSlashF, "images\\Boss\\Tanake\\hardslash\\hardslashF\\", 34);
	tanakehardSlashProF = loadImage(tanakehardSlashProF, "images\\Boss\\Tanake\\hardslash\\projectileF\\", 4);
	tanakehardSlashProB = loadImage(tanakehardSlashProB, "images\\Boss\\Tanake\\hardslash\\projectileB\\", 4);
	tanakeSuperF = loadImage(tanakeSuperF, "images\\Boss\\Tanake\\super\\superF\\", 26);
	tanakeSuperB = loadImage(tanakeSuperB, "images\\Boss\\Tanake\\super\\superB\\", 26);
	tanake.maxHealth = 500;
	tanake.health = 500;
	boss["tanake"] = tanake;
	
}

int tanakeBehavior(GameObject& tanake) {

	if (hero.x > tanake.x + tanake.width && abs(hero.x - tanake.x - tanake.width) <= tanake.bossvision) {
		tanake.bosssense = true;
	}

	if (hero.x < tanake.x && abs(hero.x - tanake.x) <= tanake.bossvision) {
		tanake.bosssense = true;
	}

	if (tanake.stunned) {
		return false;
	}

	return tanake.bosssense;
}

void walkandAttack() {

	bool tanakeAttack = false;
	if (hero.x < boss["tanake"].x && boss["tanake"].x - hero.x < 80) {
		tanakeAttack = true;
	}
	else if (hero.x >= boss["tanake"].x && hero.x - boss["tanake"].x < 80) {
		tanakeAttack = true;
	}

	if (tanakeAttack) {
		tanakeNormalAttackFrame = tanakeNormalAttackFrame % 39;

		if (hero.x < boss["tanake"].x) {

			iShowImageSmart(boss["tanake"].x, boss["tanake"].y, tanakeNormalAttackB[tanakeNormalAttackFrame / 3]);
		}
		else {
			iShowImageSmart(boss["tanake"].x, boss["tanake"].y, tanakeNormalAttackF[tanakeNormalAttackFrame / 3]);
		}
		if (!dodge) {
			heroHealth -= .5;
		}
		tanakeNormalAttackFrame++;

	}
	else {

		int printframe = boss["tanake"].frame / 2;
		if (printframe == 0) {
			printframe++;
		}

		if (hero.x < boss["tanake"].x) {
			boss["tanake"].x -= 5;
			iShowImageSmart(boss["tanake"].x, boss["tanake"].y, boss["tanake"].imagesB[printframe]);
		}
		else {
			boss["tanake"].x += 5;
			iShowImageSmart(boss["tanake"].x, boss["tanake"].y, boss["tanake"].imagesF[printframe]);
		}
		boss["tanake"].frame++;
		boss["tanake"].frame = boss["tanake"].frame % 12;

	}

}

void hardSlash() {
	if (tanakeHardSlashFrames1 < 34 * 4) {
		if (hero.x < boss["tanake"].x) {
			iShowImageSmart(boss["tanake"].x, boss["tanake"].y, tanakehardSlashB[tanakeHardSlashFrames1 / 4]);
		}
		else {
			iShowImageSmart(boss["tanake"].x, boss["tanake"].y, tanakehardSlashF[tanakeHardSlashFrames1 / 4]);
		}
		tanakeHardSlashFrames1++;
	}
	else {
		if (hero.x < boss["tanake"].x) {
			iShowImageSmart(boss["tanake"].x, boss["tanake"].y, tanakeNormalAttackB[0]);
		}
		else {
			iShowImageSmart(boss["tanake"].x, boss["tanake"].y, tanakeNormalAttackB[0]);
		}
	}
	if (tanakeHardSlashFrames1 > 20 * 4) {


		tanakeHardSlashProx -= change;
		if (hero.x < boss["tanake"].x) {
			tanakeHardSlashProx -= 10;
			iShowImageSmart(tanakeHardSlashProx, tanakeHardSlashProy, tanakehardSlashProB[tanakeHardSlashFrames2], 3);
		}
		else {
			tanakeHardSlashProx += 10;
			iShowImageSmart(tanakeHardSlashProx, tanakeHardSlashProy, tanakehardSlashProF[tanakeHardSlashFrames2], 3);
		}


		tanakeHardSlashFrames2++;
		tanakeHardSlashFrames2 = tanakeHardSlashFrames2 % 5;

		bool collisionx = abs(hero.x - tanakeHardSlashProx) < hero.width;
		bool collisiony = tanakeHardSlashProy > hero.y;

		if (collisionx && collisiony) {
			animateBlood(hero.x, tanakeHardSlashProy, 10);
			heroHealth -= 30;
		}

		if (hero.x < boss["tanake"].x && tanakeHardSlashProx < hero.x - hero.width || hero.x > boss["tanake"].x && tanakeHardSlashProx > hero.x + hero.width) {
			tanakeHardSlashActive = false;
			tanakeHardSlashCooldown = 450;
		}

	}
}

void tanakeSuper() {

	if (tanakeSuperFrame >= 6 * 3) {
		heroHealth -= 10;
		if (hero.x < boss["tanake"].x) {
			boss["tanake"].x = hero.x - 5;
		}
		else {
			boss["tanake"].x = hero.x + hero.width + 5;
		}
		animateBlood(hero.x, hero.y + hero.height / 2);
	}

	if (hero.x < boss["tanake"].x) {
		iShowImageSmart(boss["tanake"].x, boss["tanake"].y, tanakeSuperF[tanakeSuperFrame / 3]);
	}
	else {
		iShowImageSmart(boss["tanake"].x, boss["tanake"].y, tanakeSuperB[tanakeSuperFrame / 3]);
	}

	tanakeSuperFrame++;
	if (tanakeSuperFrame > 25 * 3) {
		tanakeSuperFrame = 0;
		tanakeSuperActive = false;

	}

}

void updateTanakeBehavior() {
	boss["tanake"].x -= change;
	if (boss["tanake"].health < 20) {
		tanakeDefeated = true;
		gameState = 2;
		InitializeLevel1();
		XP += 150;
	}
	if (tanakeBehavior(boss["tanake"])) {
		if (tanakeSuperActive) {
			tanakeSuper();
		}
		else if (tanakeHardSlashActive) {
			hardSlash();
		}
		else if (tanakeSuperCooldown-- <= 0) {
			tanakeSuperActive = true;
			tanakeSuperCooldown = 2000;
			tanakeSuper();
		}
		else if (tanakeHardSlashCooldown-- <= 0) {
			tanakeHardSlashFrames1 = 0;
			tanakeHardSlashFrames2 = 0;
			tanakeHardSlashActive = true;
			tanakeHardSlashProy = boss["tanake"].y + 50;
			if (hero.x > boss["tanake"].x) {
				tanakeHardSlashProx = boss["tanake"].x + 30;
			}
			else {
				tanakeHardSlashProx = boss["tanake"].x - 50;
			}
			hardSlash();
		}
		else {
			walkandAttack();
		}
	}
	else {
		if (hero.x < boss["tanake"].x) {
			iShowImageSmart(boss["tanake"].x, boss["tanake"].y, tanakeNormalAttackB[0]);
		}
		else {
			iShowImageSmart(boss["tanake"].x, boss["tanake"].y, tanakeNormalAttackF[0]);
		}
	}
}


void intitializeBossLevel() {

	boss.clear();

	gameState = 3;

	::level = 768 - 500;

	bossLevel = loadImage(bossLevel, "images\\Boss\\BossLevel\\", 1); // 30

	hero.loadImageF("images\\Hero1\\run\\forward\\", 8);

	hero.loadImageB("images\\Hero1\\run\\backward\\", 8);

	jumpForwardImage = iLoadImage("images\\Hero1\\jump\\forward\\8.png");

	jumpBackwardImage = iLoadImage("images\\Hero1\\jump\\backward\\8.png");
	sliceF = loadImage(sliceF, "images\\Hero1\\slice\\forward\\", 9);
	sliceB = loadImage(sliceB, "images\\Hero1\\slice\\backward\\", 9);
	sliceUpF = loadImage(sliceUpF, "images\\Hero1\\sliceUpward\\forward\\", 12);
	sliceUpB = loadImage(sliceUpB, "images\\Hero1\\sliceUpward\\backward\\", 12);
	sliceDownF = loadImage(sliceDownF, "images\\Hero1\\rockHit\\forward\\", 7);
	sliceDownB = loadImage(sliceDownB, "images\\Hero1\\rockHit\\backward\\", 7);
	slice360F = loadImage(slice360F, "images\\Hero1\\360slice\\forward\\", 8);
	slice360B = loadImage(slice360B, "images\\Hero1\\360slice\\backward\\", 8);
	ultMoveF = loadImage(ultMoveF, "images\\Hero1\\ultMove\\forward\\", 9);
	ultMoveB = loadImage(ultMoveB, "images\\Hero1\\ultMove\\backward\\", 9);
	dodgeMoveF = loadImage(dodgeMoveF, "images\\Hero1\\hitTaken\\forward\\", 7);
	dodgeMoveB = loadImage(dodgeMoveB, "images\\Hero1\\hitTaken\\backward\\", 7);
	rollF = loadImage(rollF, "images\\Hero1\\jump\\forward\\", 9);
	rollB = loadImage(rollB, "images\\Hero1\\jump\\backward\\", 9);

	invImg = iLoadImage("images\\inv1.png");
	equipImg = iLoadImage("images\\equipped.png");

	//remember to initialize Bosss
	
	if (!tanakeDefeated) {
		intializeTanake(1800);
	}
	else if (!DemonDefeated) {
		intializeDemon(1800);
	}

}

void MovesAndVisualsBoss() {

	if (jump) {
		Jump();
	}
	else {
		Gravity();
	}

	if (index > 240) {
		index = 240;
	}
	else if (index < 0) {
		index = 0;
	}

	if (!rainOn) {
		if (rand() % rainOncnt == 0) {
			//std::cout << rainOncnt + 1 << std::endl;
			rainOncnt = 8000;
			rainOn = true;
		}
		else {
			rainOncnt--;
		}
	}

	if (rainOn) {
		if (rand() % rainOffcnt == 0) {
			//std::cout << rainOffcnt + 1 << std::endl;
			rainOncnt = 5000;
			rainOn = false;
		}
		else {
			rainOffcnt--;
		}
	}





	//std::cout << TIME << std::endl;

	// code for moving background relative to hero movement starts
	change = hero.x - 600;
	dx += change;
	hero.x = 600;



	if (change == 0) {
		hero.running = false;
	}
	else {
		hero.running = true;
		//RunningSound();
	}

	if (dx >= 0 && dx <= 1100) {
		//iShowImage(-dx, 0, 2732, 768, bossLevel[index / 8]);
		iShowImage(-dx, 0, 2732, 768, bossLevel[0]);

	}

	else {
		if (dx < 0) {
			change = 0;
			dx = 0;
		}
		else if (dx > 1100) {
			change = 0;
			dx = 1100;
		}

		//iShowImage(-dx, 0, 2732, 768, bossLevel[index / 8]);
		iShowImage(-dx, 0, 2732, 768, bossLevel[0]);
	}


	if(jump){

		if (!roll) {
			if (direction == false) {
				iShowImageSmart(hero.x, hero.y, jumpForwardImage);
				if (x >= 40) {
					jump = false;
				}
			}
			else if (direction == true) {

				iShowImageSmart(hero.x, hero.y, jumpBackwardImage);
				if (x >= 40) {
					jump = false;
				}
			}
		}
		
		else if (roll) {

			slice = false; sliceDown = false, sliceUp = false, slice360 = false, dodge = false, ultMove = false;
			x = x % (rollF.size() * 4);
			
			if (direction) {
				
				iShowImageSmart(hero.x, hero.y, rollB[x / 4]);
			}
			else if (direction == false) {
			
				iShowImageSmart(hero.x, hero.y, rollF[x / 4]);
			}
			x++;

			
			checkAttackCollision(0);
			if (x >= 40) {
				/*roll = false;
				jump = false;*/
				x = 10;
			}
		}
	}

	else if (slice) {
		sliceUp = false, sliceDown = false, slice360 = false, ultMove = false, dodge = false;
		x = x % (sliceF.size() * 4);

		if (direction) {
			iShowImageSmart(hero.x, hero.y, sliceB[x / 4], 3);
		}
		else if (direction == false) {
			iShowImageSmart(hero.x, hero.y, sliceF[x / 4], 3);
		}
		x++;

		checkAttackCollision(sliceDamage);
		if (x >= 40) {
			slice = false;
			x = 0;
		}
		SliceSound();
	}

	else if (sliceUp) {
		slice = false; sliceDown = false, slice360 = false, ultMove = false, dodge = false;
		x = x % (sliceUpF.size() * 6);

		if (direction) {
			iShowImageSmart(hero.x, hero.y, sliceUpB[x / 6], 3);
		}
		else if (direction == false) {
			iShowImageSmart(hero.x, hero.y, sliceUpF[x / 6], 3);
		}
		x++;

		checkAttackCollision(sliceUpDamage);
		if (x >= 78) {
			sliceUp = false;
			x = 0;
		}
		SliceSound();
	}

	else if (sliceDown) {
		slice = false; sliceUp = false, slice360 = false, ultMove = false, dodge = false;
		x = x % (sliceDownF.size() * 3);

		if (direction) {
			iShowImageSmart(hero.x, hero.y, sliceDownB[x / 3], 3);
		}
		else if (direction == false) {
			iShowImageSmart(hero.x, hero.y, sliceDownF[x / 3], 3);
		}
		x++;

		if (x >= 24) {
			sliceDown = false;
			x = 0;
		}
		SliceSound();
	}

	else if (slice360) {
		slice = false; sliceDown = false, sliceUp = false, ultMove = false, dodge = false;
		x = x % (slice360F.size() * 4);

		if (direction) {
			iShowImageSmart(hero.x, hero.y, slice360B[x / 4], 3);
		}
		else if (direction == false) {
			iShowImageSmart(hero.x, hero.y, slice360F[x / 4], 3);
		}
		x++;

		checkAttackCollision(slice360Damage);
		if (x >= 36) {
			slice360 = false;
			x = 0;
		}
		SliceSound();
	}

	else if (dodge) {
		slice = false; sliceDown = false, sliceUp = false, slice360 = false, ultMove = false;
		x = x % (dodgeMoveF.size() * 3);
		if (direction) {
			hero.x += 3;
		}
		else {
			hero.x -= 3;
		}
		if (direction) {
			iShowImageSmart(hero.x, hero.y, dodgeMoveB[x / 3], 3);
		}
		else if (direction == false) {
			iShowImageSmart(hero.x, hero.y, dodgeMoveF[x / 3], 3);
		}
		x++;


		checkAttackCollision(0);
		if (x >= 24) {
			dodge = false;
			x = 0;
		}
		//SliceSound();
	}

	else if (ultMove) {
		slice = false; sliceDown = false, sliceUp = false, slice360 = false, dodge = false;
		x = x % (ultMoveF.size() * 4);

		if (direction) {
			iShowImageSmart(hero.x, hero.y, ultMoveB[x / 4], 3);
		}
		else if (direction == false) {
			iShowImageSmart(hero.x, hero.y, ultMoveF[x / 4], 3);
		}
		x++;

		checkAttackCollision(ultMoveDamage);
		if (x >= 40) {
			ultMove = false;
			x = 0;
		}
		SliceSound();
	}

	else {
		showHero(direction, 12);
	}



	if (rainOn) {
		Rain();
	}

	//health
	iSetColor(0, 0, 0);
	iFilledRectangle(48, 698, 204, 34);
	iSetColor(232, 21, 21);
	ll printhealth = (heroHealth / maxHealth) * 200;
	iFilledRectangle(50, 700, printhealth, 30);

	// boss health

	iSetColor(0, 0, 0);
	iFilledRectangle(1366 - 200 - 48, 698, 204, 34);
	iSetColor(232, 21, 21);
	printhealth = (boss["tanake"].health / boss["tanake"].maxHealth) * 200;
	
	iFilledRectangle(1366 - 200 - 46, 700, printhealth, 30);

	/*if (heroHealth < 10) {
		gameState = 0;
	}*/


	//inventory
	if (inventory == 1) {
		iShowImage(534, 233, 300, 300, invImg);
		iShowImageSmart(571, 426, equipImg);

	}
	//inventory

	//items
	resetItemeffects();
	updateItems();

	if (bombAnimation) {
		animateBomb();
	}

	//Boss codes
	if (tanakeDefeated) {
		updateDemonBehavior();
		showBoss(change);
	}
	else {
		updateTanakeBehavior();
	}
	if (bloodAnimation) {
		animateBlood();
	}

	index++;
	index = index % (240);
}



#endif