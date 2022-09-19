#ifndef LEVEL1
#define LEVEL1_H_INCLUDED

#include "Animals.h" 
bool firstime = true;

char buff[50];
char tempArr[100];
std::string tempL;

void intializeGuide(){
	guideImage = loadImage(guideImage, "images\\materials\\",3);
}

bool showGuide = false;
int guideFrame = 0;
void Guide() {
	if (guideFrame > 3) {
		guideFrame = 0;
	}
	if (showGuide) {
		iShowImage(0, 0, 1366, 768, guideImage[guideFrame]);
	}
}


void XPBAR() {

	if (stamina < 0) {
		stamina = 0;
	}

	if (XP + 20 > maxXP) {

		XP -= maxXP;
		maxXP = maxXP + maxXP * 0.1;
		maxStamina = maxStamina + maxStamina * 0.1;
		maxHealth = maxHealth + maxHealth * 0.1;
		characterlevel++;
	}
	/*iSetColor(0, 0, 0);
	iFilledRectangle(1000, 698, 204, 34);
	
	XP(15px / 170px) 90 85 96
	*/

	iSetColor(139, 244, 37);
	ll printXP = (XP / maxXP) * 190;
	iFilledRectangle(90 +58, 655, printXP, 20);
	stamina += 0.1;
	if (stamina > maxStamina) {
		stamina = maxStamina;
	}
}

void staminaBar() {
	// stamina(25px / 220px) 53 153 238

	iSetColor(53, 153, 238);
	ll printStamina = (stamina / maxStamina) * 220;
	iFilledRectangle(35 +58, 685, printStamina, 30);
}

void intilalizeDestractableObjectsday() {

	objects.clear();

	addObj("atree", GameObject(800, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("aflower", GameObject(800, level + 5, 20, 20, "images\\level1\\objects\\flower1.png"));

	addObj("atree", GameObject(1270, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(1630, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("rock", GameObject(2015, level - 12, 65, 95, "images\\level1\\objects\\rock7.png"));
	addObj("atree", GameObject(2400, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(2756, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));
	addObj("rock", GameObject(3320, level - 12, 60, 95, "images\\level1\\objects\\rock8.png"));


	addObj("atree", GameObject(3750, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(4450, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(4900, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(5138, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(5500, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(5755, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));
	//addObj("rock", GameObject(6475, level - 9, 250, 350, "images\\level1\\objects\\rock6.png"));



	addObj("atree", GameObject(7195, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//1
	//addObj("aflower", GameObject(6945, level + 5, 20, 20, "images\\level1\\objects\\flower1.png"));
	addObj("atree", GameObject(7480, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//2
	addObj("atree", GameObject(7750, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//3
	//addObj("rock", GameObject(2015, level - 12, 65, 95, "images\\level1\\objects\\rock7.png"));
	addObj("atree", GameObject(8380, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));//4
	addObj("atree", GameObject(8708, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//5
	addObj("rock", GameObject(9968, level - 12, 60, 95, "images\\level1\\objects\\rock8.png"));


	addObj("atree", GameObject(10435, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));//6
	addObj("atree", GameObject(11182, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));//7
	addObj("atree", GameObject(11808, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png")); //8
	//addObj("atree", GameObject(12133, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//9
	//addObj("atree", GameObject(12518, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//10
	//addObj("atree", GameObject(12988, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//11
	addObj("rock", GameObject(12618, level - 12, 65, 95, "images\\level1\\objects\\rock6.png"));



	
	initializeLion(2300);
	int random = 600 + rand() % (backgroundWidth * backgroundRepeat - 683 * backgroundRepeat);

	while (abs(hero.x - random) <= 700)
	{
		random = 600 + rand() % (backgroundWidth * backgroundRepeat - 683 * backgroundRepeat);
	}


	initializeRhino(random);

	random = 600 + rand() % (backgroundWidth * backgroundRepeat - 683 * backgroundRepeat);

	while (abs(hero.x - random) <= 700)
	{
		random = 600 + rand() % (backgroundWidth * backgroundRepeat - 683 * backgroundRepeat);
	}


	initializeBoar(random);

	initializeTiger(2300);
}
void intilalizeDestractableObjectsnight() {
	
	objects.clear();
	destructed.clear();

	addObj("atree", GameObject(800, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("aflower", GameObject(800, level + 5, 20, 20, "images\\level1\\objects\\flower1.png"));

	addObj("atree", GameObject(1270, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(1630, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("rock", GameObject(2015, level - 12, 65, 95, "images\\level1\\objects\\rock7.png"));
	addObj("atree", GameObject(2400, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(2756, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));
	addObj("rock", GameObject(3320, level - 12, 60, 95, "images\\level1\\objects\\rock8.png"));


	addObj("atree", GameObject(3750, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(4450, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(4900, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(5138, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(5500, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));
	addObj("atree", GameObject(5755, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));
	addObj("rock", GameObject(6475, level - 9, 250, 350, "images\\level1\\objects\\rock6.png"));



	addObj("atree", GameObject(7195, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//1
	//addObj("aflower", GameObject(6945, level + 5, 20, 20, "images\\level1\\objects\\flower1.png"));
	addObj("atree", GameObject(7480, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//2
	addObj("atree", GameObject(7750, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//3
	//addObj("rock", GameObject(2015, level - 12, 65, 95, "images\\level1\\objects\\rock7.png"));
	addObj("atree", GameObject(8380, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));//4
	addObj("atree", GameObject(8708, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//5
	addObj("rock", GameObject(9968, level - 12, 60, 95, "images\\level1\\objects\\rock8.png"));


	addObj("atree", GameObject(10435, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));//6
	addObj("atree", GameObject(11182, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png"));//7
	addObj("atree", GameObject(11808, level + 10, 260, 85, "images\\level1\\objects\\tree_noBG.png")); //8
	//addObj("atree", GameObject(12133, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//9
	//addObj("atree", GameObject(12518, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//10
	//addObj("atree", GameObject(12988, level + 10, 260, 90, "images\\level1\\objects\\tree_noBG.png"));//11
	addObj("rock", GameObject(12618, level - 12, 65, 95, "images\\level1\\objects\\rock6.png"));


	int random = 600 + rand() % (backgroundWidth * backgroundRepeat - 683 * backgroundRepeat);

	while (abs(hero.x - random) <= 700)
	{
		random = 600 + rand() % (backgroundWidth * backgroundRepeat - 683 * backgroundRepeat);
	}

	initializeRhino(random);

	random = 600 + rand() % (backgroundWidth * backgroundRepeat - 683 * backgroundRepeat);

	while (abs(hero.x - random) <= 700)
	{
		random = 600 + rand() % (backgroundWidth * backgroundRepeat - 683 * backgroundRepeat);
	}

	initializeLion(random);

	random = 600 + rand() % (backgroundWidth * backgroundRepeat - 683 * backgroundRepeat);

	while (abs(hero.x - random) <= 700)
	{
		random = 600 + rand() % (backgroundWidth * backgroundRepeat - 683 * backgroundRepeat);
	}

	initializeTiger(random);

	//initializeBoar(random);


}

void MovesAndVisual1() {
	if (jump) {
		Jump();
	}
	else {
		Gravity();
	}

	if (index > 2*480) {
		index = 2*480;
	}
	else if (index < 0) {
		index = 0;
	}

	if ((ll)TIME % 150 == 0) {
		if (prevSwitch != (ll)TIME) {
			dayTime = !dayTime;
			prevSwitch = (ll)TIME;
			if (dayTime) {
				intilalizeDestractableObjectsday();
			}
			else {
				intilalizeDestractableObjectsnight();
			}
		}
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

	//Animals codes
	
	updateAnimalBehavior();

	//Boss codes

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
		
	}

	if (hero.running == true) {
		//RunningSound();
	}

	if (dx >= 0 && dx <= backgroundWidth * backgroundRepeat - 1366 * backgroundRepeat) {

		if (dayTime) {
			//iShowImage(-dx, 0, 6830, 768, bgLevel1[index/8]);
			for (int i = 0; i < backgroundRepeat; i++) {
				if (i % 2 == 0) {
					iShowImage(-dx + backgroundWidth * i, 0, 6830, 768, bgLevel1day[0]);
				}
				else {
					iShowImage(-dx + backgroundWidth * i, 0, 6830, 768, bgLevel1dayB[0]);
				}
			}
		}
		else {
			//iShowImage(-dx, 0, 6830, 768, bgLevel1[index/8]);
			for (int i = 0; i < backgroundRepeat; i++) {
				if (i % 2 == 0) {
					iShowImage(-dx + backgroundWidth * i, 0, 6830, 768, bgLevel1night[0]);
				}
				else {
					iShowImage(-dx + backgroundWidth * i, 0, 6830, 768, bgLevel1nightB[0]);
				}
			}
		}

		showObj(change);
	}
	else {
		if (dx < 0) {
			dx = 0;
		}
		else if (dx > backgroundWidth * backgroundRepeat - 1366 * backgroundRepeat) {
			dx = backgroundWidth * backgroundRepeat - 1366 * backgroundRepeat;
		}

		//iShowImage(-dx, 0, 6830, 768, bgLevel1[index/8]);
		if (dayTime) {

			for (int i = 0; i < backgroundRepeat; i++) {
				if (i % 2 == 0) {
					iShowImage(-dx + backgroundWidth * i, 0, 6830, 768, bgLevel1day[0]);
				}
				else {
					iShowImage(-dx + backgroundWidth * i, 0, 6830, 768, bgLevel1dayB[0]);
				}
			}
		}
		else {
			for (int i = 0; i < backgroundRepeat; i++) {
				if (i % 2 == 0) {
					iShowImage(-dx + backgroundWidth * i, 0, 6830, 768, bgLevel1night[0]);
				}
				else {
					iShowImage(-dx + backgroundWidth * i, 0, 6830, 768, bgLevel1nightB[0]);
				}
			}
		}
		showObj(0);
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
		x = x % (sliceF.size()*4);
		
		if (direction ) {
			iShowImageSmart(hero.x, hero.y, sliceB[x/4], 3);
		}
		else if(direction == false ) {
			iShowImageSmart(hero.x, hero.y, sliceF[x/4], 3);
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
		slice = false; sliceDown = false, sliceUp = false, slice360 = false , ultMove=false;
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
		
		//std::cout << x << std::endl;
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

	//code for health bar

	//RGBcolor health(25px/235px) 244 45 66 //stamina(25px/220px) 53 153 238 //XP(15px/170px) 90 85 96
	//health 18, 738	stamin18,707		XP 71,678  
	/*iSetColor(0, 0, 0);
	iFilledRectangle(48, 698, 204, 34);*/
	iSetColor(244, 45, 66);
	ll printhealth = (heroHealth / maxHealth) * 245;
	iFilledRectangle(35 +58, 715, printhealth, 30);

	//code for XP bar
	staminaBar();
	XPBAR();

	iShowImageSmart(20, 648, healthBarImg);
	
	strcpy(tempArr, "LV ");
	strcat(tempArr, to_char(characterlevel));
	iText(105, 658, tempArr,GLUT_BITMAP_HELVETICA_12);
	


	/*if (heroHealth < 10) {
		gameState = 0;
	}*/


	//inventory
	if (inventory == 1) {
		iShowImageSmart(invX, invY, invImg);
		iShowImageSmart(invX, invY - 110, craftQImg);
		iShowImageSmart(355, 505, guideImg);
		if (invItems.size() > 0) {
			showInvMats();
		}
		if (craftQ.size() > 0) {
			showCraftQ();
			iShowImageSmart(invX, invY - 110, buttonAImg);
		}
		else {
			iShowImageSmart(invX, invY - 110, buttonDImg);
		}
		showBagpack();
		if (backpackLv == 0) {
			slotAvail = 1;
			bLimit = 2;
			equipLimit = 4;
			iShowImageSmart(456, 217, iLoadImage("images\\locked.png"));
			iShowImageSmart(524, 217, iLoadImage("images\\locked.png"));
			iShowImageSmart(592, 217, iLoadImage("images\\locked.png"));
		}
		else if (backpackLv == 1) {
			slotAvail = 2;
			bLimit = 4;
			equipLimit = 8;
			iShowImageSmart(524, 217, iLoadImage("images\\locked.png"));
			iShowImageSmart(592, 217, iLoadImage("images\\locked.png"));
		}
		else if (backpackLv == 2) {
			slotAvail = 3;
			bLimit = 6;
			equipLimit = 12;
			iShowImageSmart(592, 217, iLoadImage("images\\locked.png"));
		}
		else if (backpackLv == 3) {
			slotAvail = 4;
			bLimit = 8;
			equipLimit = 16;
		}

		showEqp();

		if (guide) {
			//iShowImageSmart(0, 0, loadingScr);
			iSetColor(255, 0, 0);
			iFilledRectangle(1300, 700, 66, 68);
			iSetColor(0, 0, 0);
			iLine(1317, 719, 1349, 750);
			iLine(1317, 750, 1349, 719);
		}

		iSetColor(0, 0, 0);
		iText(410, 540, "BagpackLv: ");
		iText(490, 540, itoa(backpackLv, buff, 10));
		iText(410, 525, "SwordLv: ");
		iText(490, 525, itoa(swordLv, buff, 10));
		iText(410, 510, "ArmorLv: ");
		iText(490, 510, itoa(armorLv, buff, 10));
	}
	//inventory

	//items
	resetItemeffects();
	updateItems();

	if (bombAnimation) {
		animateBomb();
	}

	index++;
	index = index % (2*480) ;
	
}


bool InitializeLevel1() {
	boss.clear();
	objects.clear();
	destructed.clear();
	hero.imagesB.clear();
	hero.imagesF.clear();
	level = 65;
	heroHealth = maxHealth;
	TIME = 0;
	bgLevel1day = loadImage(bgLevel1day, "images\\level1\\Day\\", 1); //60
	bgLevel1dayB = loadImage(bgLevel1dayB, "images\\level1\\DayB\\", 1); //60
	bgLevel1night = loadImage(bgLevel1night, "images\\level1\\Night\\", 1); //60
	bgLevel1nightB = loadImage(bgLevel1nightB, "images\\level1\\NightB\\", 1); //60
	
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
	
	healthBarImg = iLoadImage("images\\level1HealthBar.png");
	invImg = iLoadImage("images\\level1inv.png");
	equipImg = iLoadImage("images\\equipped.png");
	craftQImg = iLoadImage("images\\CraftQ.png");
	buttonAImg = iLoadImage("images\\buttonAct.png");
	buttonDImg = iLoadImage("images\\buttonDeact.png");

	guideImg = iLoadImage("images\\guide1.png");

	initializeMats();
	intilalizeDestractableObjectsday();

	return true;
}




#endif
