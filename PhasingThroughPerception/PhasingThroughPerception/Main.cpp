
#include "menu.h"

double PREVTIME = 0;
double ASSUMETIMEINCREASE = 0;

void iDraw()
{
	//PART OF TIME FUCNTION SECTION 1 START

	SYSTEMTIME time;
	GetSystemTime(&time);
	LONG time_ms1 = (time.wSecond * 1000) + time.wMilliseconds;


	if (TIME < 0) {
		TIME = 0;
		std::cout << "NEGATIVE TIME ERROR" << std::endl;
	}

	PREVTIME = TIME;

	//PART OF TIME FUCNTION SECTION 1 END

	iClear();

	music();
	MainMenu();
	DemonWalkSound();
	Guide();
	

	//PART OF TIME FUNTION SECTION 2 START
	GetSystemTime(&time);
	LONG time_ms2 = (time.wSecond * 1000) + time.wMilliseconds;

	double diff = abs(time_ms2 - time_ms1);
	TIME += diff / 1000;
	if (abs(TIME - PREVTIME) > 1) {
		TIME = PREVTIME + ASSUMETIMEINCREASE;
		std::cout << "TIME EROOR HANDLED" << std::endl;
	}
	else {
		ASSUMETIMEINCREASE = diff / 1000;
	}
	//PART OF TIME FUNTION SECTION 2 END
}


/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

	if (gameState == 2 || gameState == 3) {
		mouseX = mx;
		mouseY = my;
	}
	
}


/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int x, int y)
{
	if ((x > 51 + menux && x < 380 + menux) && (y > 32 + menuy && y < 88 + menuy)) {
		menubutton[0] = 1;
	}
	else {
		menubutton[0] = 0;
	}
	if ((x > 51 + menux && x < 380 + menux) && (y > 32 + menuy - 100 && y < 88 + menuy - 100)) {
		menubutton[1] = 1;
	}
	else {
		menubutton[1] = 0;
	}
	if ((x > 51 + menux && x < 380 + menux) && (y > 32 + menuy - 200 && y < 88 + menuy - 200)) {
		menubutton[2] = 1;
	}
	else {
		menubutton[2] = 0;
	}
	if ((x > 51 + menux && x < 380 + menux) && (y > 32 + menuy - 300 && y < 88 + menuy - 300)) {
		menubutton[3] = 1;
	}
	else {
		menubutton[3] = 0;
	}
	if ((x > 51 + menux && x < 380 + menux) && (y > 32 + menuy - 400 && y < 88 + menuy - 400)) {
		menubutton[4] = 1;
	}
	else {
		menubutton[4] = 0;
	}

	if (gameState == 1) {
		mouseX = x;
		mouseY = y;
	}

}


/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (mmmm == 0 || mmmm == 1 || mmmm == 2 || mmmm == 3) {
		mmmm++;
	}

	else if ((mx > 51 + menux && mx < 380 + menux) && (my > 32 + menuy - 200 && my < 88 + menuy - 200) && fixbuttonpro == 5) {
		if (mscheck == 0 && msbugfix == 0) {
			mscheck = 1;
		}
		else if (mscheck == 1 && msbugfix == 0) {
			mscheck = 0;
		}
		if (msbugfix == 0) {
			msbugfix = 1;
		}
		else if (msbugfix == 1) {
			msbugfix = 0;
		}
		if (mscheck == 1) {
			mbscheck = 1;
		}
	}

	if ((mx > 51 + menux && mx < 380 + menux) && (my > 32 + menuy - 300 && my < 88 + menuy - 300) && fixbuttonpro == 5) {
		if (mscheck == 1) {
			mbscheck = 1;
		}
		else if (mbscheck == 0 && msbugfix == 0) {
			mbscheck = 1;
		}
		else if (mbscheck == 1 && msbugfix == 0) {
			mbscheck = 0;
		}
		if (msbugfix == 0) {
			msbugfix = 1;
		}
		else if (msbugfix == 1) {
			msbugfix = 0;
		}
	}
	if ((mx > 51 + menux && mx < 380 + menux) && (my > 32 + menuy - 200 && my < 88 + menuy - 200) && fixbuttonpro == 6) {
		if (amscheck == 0 && amsbugfix == 0) {
			amscheck = 1;
		}
		else if (amscheck == 1 && amsbugfix == 0) {
			amscheck = 0;
		}
		if (amsbugfix == 0) {
			amsbugfix = 1;
		}
		else if (amsbugfix == 1) {
			amsbugfix = 0;
		}
	}
	if ((mx > 51 + menux && mx < 380 + menux) && (my > 32 + menuy - 300 && my < 88 + menuy - 300) && fixbuttonpro == 6) {
		if (amscheck == 0 && amsbugfix == 0) {
			amscheck = 1;
		}
		else if (amscheck == 1 && amsbugfix == 0) {
			amscheck = 0;
		}
		if (amsbugfix == 0) {
			amsbugfix = 1;
		}
		else if (amsbugfix == 1) {
			amsbugfix = 0;
		}
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gameState == 1 || gameState == 2 || gameState == 3 && inmenu) {
			MenuConditions(mx, my);
		}

		if (gameState == 1 && inmenu == false && inventory != 1) {
			shoot = true;
		}

		if (gameState == 1 && inmenu == false && inventory == 1) {
			if (heroState == 1 && mx >= 571 && mx <= 630 && my >= 426 && my <= 476) {
				heroState = 2;
			}
			else if (heroState == 2 && mx >= 571 && mx <= 630 && my >= 426 && my <= 476) {
				heroState = 1;
			}
		}

		if (gameState == 2 && inmenu == false && inventory == 1) {
			matClick(mx, my);
			qClick(mx, my);
		}

		if (gameState == 2 && inmenu == false && inventory == 1) {
			if (mx > 355 && mx < 395 && my > 505 && my < 555) {
				guide = true;
			}
			if (guide == true) {
				if ((mx > 1300 && mx < 1366) && (my > 700 && my < 768)) {
					guide = false;
				}
			}
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		if (gameState == 2 && inmenu == false && inventory == 1) {
			matClick(mx, my, true);
		}

		if (gameState == 2 || gameState == 3 && inmenu == false && inventory == 1) {
			if (mx > 378 && mx < 395 + 60 && my > 214 && my < 262 && backpackLv > -1) {
				drag = true;
				testB(1, false);
				dragID = 1;
			}
			else if (mx > 446 && mx < 446 + 60 && my > 214 && my < 262 && backpackLv > 0) {
				drag = true;
				testB(2, false);
				dragID = 2;
			}
			else if (mx > 514 && mx < 514 + 60 && my > 214 && my < 262 && backpackLv > 1) {
				drag = true;
				testB(3, false);
				dragID = 3;
			}
			else if (mx > 582 && mx < 582 + 60 && my > 214 && my < 262 && backpackLv > 2) {
				drag = true;
				testB(4, false);
				dragID = 4;
			}
			//std::cout << drag << std::endl;
		}

	}

	if (drag) {
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
			if (mx > 574 && mx < 574 + 60 && my > 383 && my < 383 + 50) {
				if (testB(dragID, true)) {
					mouseX = -100;
					mouseY = -100;
					dragID = 0;
					drag = false;
				}
			}
			else if (mx > 574 && mx < 574 + 60 && my > 322 && my < 322 + 50) {
				if (testB(dragID, true)) {
					mouseX = -100;
					mouseY = -100;
					dragID = 0;
					drag = false;
				}
			}
			else {
				std::cout << "falsing drag" << std::endl;
				testB(dragID, true, true);
				mouseX = -100;
				mouseY = -100;
				drag = false;
			}
		}
	}
}


/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == ' ' && gn != 0) {
		gn = 0;
		buttonpos[0] = 1000;
	}

	if (!gameState && (key == 'r' || key == 'R')) {
		gameState = 1;
		restartlevel();
	}

	if (key == '7') {
		initiateBomb(hero.x);
	}

	if (key == '8') {
		initiateStun(hero.x);
	}

	if (key == '9') {
		initiateSmoke(hero.x);
	}

	if (gameState == 1) {
		if (key == ' ')
		{
			if (rhinoHitjump) {
				return;
			}

			jump = true;
			reach_y = hero.y + Hmax;

		}
	}

	if (gameState == 2 || gameState == 3) {
		if (key == ' ')
		{
			if (rhinoHitjump) {
				return;
			}
			if (jump) {
				roll = true;
			}
			else {
				jump = true;
				reach_y = hero.y + Hmax;
			}

		}
	}


	if (key == 'a' || key == 'A')
	{
		if (CheckCollision() == 1) {
			Backward();
		}	
	}

	if (key == 'g' || key == 'G' && eqp.size() > 0) {
		if (smokeEquip && testG("smokeBomb")) {			
			initiateSmoke(hero.x);
		}
		else if (bombEquip && testG("Bomb")) {
			initiateBomb(hero.x);
		}
		else if (stunEquip && testG("stunBomb")) {
			initiateStun(hero.x);
		}
		else if(hpotionEquip && testG("healthPotion")) {
			initiatehPotion(hero.x);
		}
		else if (stpotionEquip && testG("staminaPotion")) {
			initiatestaminaPotion(hero.x);
		}
		else if (coilEquip && testG("cursedOil")) {
			initiatcursedOil(hero.x);
		}
		else if (cheetahbloodEquip && testG("bloodofCheetah")) {
			initiatecheetahBlood(hero.x);
		}
	
	}

	if (key == 'd' || key == 'D')
	{
		/* calling check collision inside the fuction
			Produced a bug
			Bug makes it go inside objects
		*/

		if (CheckCollision() == 1) {
			Forward();
		}	
	}
	if (key == 'e' || key == 'E') {
		stamina -= 2;
		if (gameState == 2) {
			Craft();
			sliceDown = true;
		}
		else if (gameState == 3) {
			sliceDown = true;
		}	
	}

	if (key == 'f' || key == 'F') {
		if (gameState == 1 )
			shoot = true;
		else
			slice = true;
	}

	if (key == 'c' || key == 'C') {
		if (gameState == 2 || gameState == 3) {
			if (stamina > 0) {
				sliceUp = true;
				stamina -= 2;
			}
		}
	}

	if (key == 'v' || key == 'V') {
		if (gameState == 2 || gameState == 3) {
			if (stamina > 0) {
				slice360 = true;
				stamina -= 2;
			}
		}
			
	}

	if (key == 'x' || key == 'X') {
		if (gameState == 2 || gameState == 3) {
			if(stamina > 0) {
				ultMove = true;
				stamina -= 5;
			}
		}
	}


	if (key == 's' || key == 'S') {
		if (gameState == 2 || gameState == 3) {
			dodge = true;
			stamina -= 2;
		}
	}

	if (gameState == 1) {
		if (key == '1' && gameState == 1) {
			heroState = 1;
		}

		if (key == '2' && gameState == 1) {
			heroState = 2;
		}
	}
	else if (gameState == 2 || gameState == 3) {

		if (key == '1' && eqp.size() > 0) {
			std::cout << "Equipping 1" << std::endl;
			equips(1);

		}

		else if (key == '2' && eqp.size() > 1) {
			std::cout << "Equipping 2" << std::endl;
			equips(2);

		}

	}

	if (key == 'i' || key == 'I') {
		inventory = inventory * -1;
	}

	if (key == 'o' || key == 'O') {
		SaveGame();
	}

	if (key == 'l' || key == 'L') {
		LoadGame();
	}

	if (key == 'q' || key == 'Q') {
		heroHealth = maxHealth;
	}

	if (key == 'b' || key == 'B') {
		gameState = 3;
		loadline = 0;
		loaddot = 0;
	}

	//place your codes for other keys here
}


/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{	
		if (gameState == 1) {
			gameState = 2;
		}
		else if (gameState == 2) {
			loadline = 0;
			loaddot = 0;
			gameState = 3;
		}
		
	}

	if (key == GLUT_KEY_F1)
	{
		showGuide = !showGuide;
	}

	if (key == GLUT_KEY_F2)
	{
		SaveGame();
	}

	if (key == GLUT_KEY_DOWN && showGuide)
	{
		guideFrame++;
	}

	if (key == GLUT_KEY_UP && inCutScene) {
		cutsceneFrame++;
		jump = false;
	}
	
}

void updateMusic() {
	musicOn = !mscheck;
	BGmusicOn = mbscheck;
}


int main() {

	iSetTimer(100, RandomAlgorithm);
	iSetTimer(250, RunningSound);
	iSetTimer(25, updateMusic);
	iSetTimer(500, deleteCheck);

	iInitialize(1366, 768, "Phasing Through Perception");
	
	statebuttonpos();

	intializeGuide();
	InitializeMenu();
	InitializeLevel0();
	initializeCutScene1();
	initializeCutScene2();
	intializeCutScene3();
	//InitializeLevel1();
	//intitializeBossLevel();

	blood = loadImage(blood, "images\\effects\\blood\\", 6);
	smoke = loadImage(smoke, "images\\effects\\dust\\", 7);
	stun = loadImage(stun, "images\\effects\\stun\\", 7);
	bomb = loadImage(bomb, "images\\effects\\explosion\\", 5);
	bombIcon = iLoadImage("images\\effects\\bomb.png");


	iStart();

	return 0;
}

