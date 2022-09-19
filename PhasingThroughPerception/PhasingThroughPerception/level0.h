#ifndef LEVEL0
#define LEVEL0_H_INCLUDED

#include "level1.h" 

int shootReset = 0, shootImageF = 0, shootImageB = 0;
int bg = 0, backGround = 0, middleGround = 0, ground = 0;
bool shoot = false;
int randT;


void MovesAndVisual0() {

	gameP = 1;
	if (jump) {
		Jump();
	}
	else if (boarHitjump)
	{
		boarHitJump();
	}
	else {
		Gravity();
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


	// code for moving background relative to hero movement starts
	change = hero.x - 600;
	dx += change;
	hero.x = 600;

	if (change == 0) {
		hero.running = false;
	}
	else {
		hero.running = true;
	}

	if (hero.running == true) {
		//RunningSound();
	}

	if (dx >= 0 && dx <= 4098) {

		iShowImage(-(dx * 0.4), 0, 5464, 768, backGround);
		iShowImage(-(dx * 0.5), 0, 5464, 768, middleGround);
		iShowImage(-dx, 0, 5464, 768, ground);
		showObj(change);
	}

	else {
		if (dx < 0) {
			dx = 0;
		}
		else if (dx > 4098) {
			dx = 4098;
		}


		iShowImage(-dx, 0, 5464, 768, backGround);
		iShowImage(-dx, 0, 5464, 768, middleGround);
		iShowImage(-dx, 0, 5464, 768, ground);
		showObj(0);

	}
	// code for moving background relative to hero movement ends


	//switch equipments
	if (heroState == 1) {
		hero.imagesF = runEmtF;
		hero.imagesB = runEmtB;

		jumpForwardImage = hero.imagesF[7];
		jumpBackwardImage = hero.imagesB[7];
	}
	else if (heroState == 2) {
		hero.imagesF = runPistolF;
		hero.imagesB = runPistolB;

		jumpForwardImage = hero.imagesF[7];
		jumpBackwardImage = hero.imagesB[7];

		iShowImage(mouseX - 12, mouseY - 12, 25, 25, crosshair);
	}
	//switch equipments


	//portal
	if (portal) {
		iShowImageSmart(-dx + 565, level - 25, portalImg[pindex]);

		if (pindex == 4) pindex = 0;
		pindex++;
	}
	//portal


	//boar behavior
	updateAnimalBehavior();
	//boar behavior code ends


	//boss behavior
	updateDemonBehavior0();
	showBoss(change);
	//boss behavior code ends


	// code for hero movement rendering starts	

	if (jump == true) {
		if (direction == false) {
			iShowImageSmart(hero.x, hero.y, jumpForwardImage);
			if (jumpingCounter == 5) {
				jumpingCounter = 0;
				jump = false;
			}
		}
		else if (direction == true) {

			iShowImageSmart(hero.x, hero.y, jumpBackwardImage);
			if (jumpingCounter == 5) {
				jumpingCounter = 0;
				jump = false;
			}
		}
	}
	else if (shoot && heroState == 2) {

		direction = hero.x > mouseX;
		checkAttackCollision0(500);

		if (direction == false) {
			iShowImageSmart(hero.x, hero.y, shootImageF);
		}
		else {
			iShowImageSmart(hero.x, hero.y, shootImageB);
		}
		shootReset++;
		if (shootReset == 1) {
			ShootSound();
		}

		if (shootReset == 20) {
			shootReset = 0;
			shoot = false;
		}

	}

	else if (shoot && heroState != 2) {
		shootReset++;

		showHero(direction, 12);
		iSetColor(255, 0, 0);
		iText(525, 590, "No Weapon Equipped. Press 2 to equip.", GLUT_BITMAP_TIMES_ROMAN_24);

		if (shootReset == 20) {
			shootReset = 0;
			shoot = false;
		}
	}

	else {
		showHero(direction, 12);
	}
	// code for hero movement rendering ends

	if (portal && dx <= 700) {
		iShowImageSmart(hero.x + 5, hero.y + 100, portalTextImg);
	}

	//inventory
	if (inventory == 1) {
		iShowImageSmart(534, 233, invImg);
		if (heroState == 2) {
			iShowImageSmart(748, 495, equipImg);
		}
	}
	//inventory

	//call rain
	if (rainOn) {
		Rain();
	}

	//code for health bar

	//RGBcolor health(25px/235px) 244 45 66 //stamina(25px/220px) 53 153 238 //XP(15px/170px) 90 85 96
	//health 18, 738	stamin18,707		XP 71,678 
	iSetColor(244, 45, 66);
	ll printhealth = (heroHealth / maxHealth) * 245;
	iFilledRectangle(35 +58, 715, printhealth, 30);

	//code for XP bar
	staminaBar();
	XPBAR();
	iShowImageSmart(20, 648, healthBarImg);

	/*if (heroHealth < 10) {
		gameState = 0;
	}*/

	//next level
	if (portal && !dx && direction) {
		gameState = 2;
	}

	//items
	resetItemeffects();
	updateItems();

	iText(490, 90, "~debug: Press END to skip to level 1.", GLUT_BITMAP_TIMES_ROMAN_24);
}


void InitializeLevel0() {

	objects.clear();
	destructed.clear();

	level = 165;
	double heroHealth = 200;
	randT = rand() % 3;

	hero.loadImageF("images\\Hero0\\forward\\", 16);
	hero.loadImageB("images\\Hero0\\backward\\", 16);
	jumpForwardImage = iLoadImage("images\\Hero0\\forward\\7.png");
	jumpBackwardImage = iLoadImage("images\\Hero0\\backward\\7.png");
	shootImageF = iLoadImage("images\\Hero0\\shoot\\0.png");
	shootImageB = iLoadImage("images\\Hero0\\shoot\\1.png");

	backGround = iLoadImage("images\\level0\\bg\\background.png");
	middleGround = iLoadImage("images\\level0\\bg\\middlegroundo.png");
	ground = iLoadImage("images\\level0\\bg\\groundo.png");

	runPistolF = loadImage(runPistolF, "images\\Hero0\\forward\\", 16);
	runPistolB = loadImage(runPistolB, "images\\Hero0\\backward\\", 16);
	runEmtF = loadImage(runEmtF, "images\\Hero0\\runEmt\\forward\\", 16);
	runEmtB = loadImage(runEmtB, "images\\Hero0\\runEmt\\backward\\", 16);

	crosshair = iLoadImage("images\\crosshair1.png");
	
	healthBarImg = iLoadImage("images\\level0HealthBar.png");
	invImg = iLoadImage("images\\level0inv.png");
	equipImg = iLoadImage("images\\equipped.png");

	portalImg = loadImage(portalImg, "images\\portal\\", 4);
	portalTextImg = iLoadImage("images\\level0\\portalText.png");


	addObj("plane", GameObject(50, level, 104, 464, "images\\level0\\objects\\crashed.png"));
	addObj("atree", GameObject(800, level + 10, 300, 150, "images\\level0\\objects\\tree1.png"));
	addObj("atree", GameObject(1300, level + 10, 280, 140, "images\\level0\\objects\\tree2.png"));
	addObj("atree", GameObject(2200, level + 13, 280, 150, "images\\level0\\objects\\tree3.png"));
	addObj("rock", GameObject(2700, level - 13, 60, 100, "images\\level0\\objects\\rock1.png"));
	addObj("atree", GameObject(3400, level + 13, 280, 140, "images\\level0\\objects\\tree3.png"));
	addObj("rock", GameObject(2650, level - 15, 30, 40, "images\\level0\\objects\\rock3.png"));
	addObj("rock", GameObject(4800, level - 13, 300, 400, "images\\level0\\objects\\rock1.png"));
	initializeBoar(2000);
	//initializeTiger(2000);
	//initializeRhino(1900);
	//initializeLion(2500);
	intializeDemon(4000);

}


#endif