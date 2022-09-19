#ifndef MENU
#define MENU_H_INCLUDED


#include "SaveAndLoad.h"

bool inLoad = false;

void statebuttonpos()
{
	for (int hhhhh = 0; hhhhh < 20; hhhhh++) {
		if (fixbuttonpro == hhhhh)
			hhhhh++;
		else if (fixbuttonpro == hhhhh)
			hhhhh++;
		else if (fixbuttonpro == hhhhh)
			hhhhh++;
		else if (fixbuttonpro == hhhhh)
			hhhhh++;
		else if (fixbuttonpro == hhhhh)
			hhhhh++;
		else if (fixbuttonpro == hhhhh)
			hhhhh++;
		else if (fixbuttonpro == hhhhh)
			hhhhh++;
		else if (fixbuttonpro == hhhhh)
			hhhhh++;

		buttonpos[hhhhh] = 1000;
	}
}
void InitializeMenu()
{
	menupics[0] = iLoadImage("images\\menu\\0.png");
	menupics[1] = iLoadImage("images\\menu\\1.png");
	menupics[2] = iLoadImage("images\\menu\\2.png");
	menupics[3] = iLoadImage("images\\menu\\3.png");
	menupics[4] = iLoadImage("images\\menu\\4.png");
	menupics[5] = iLoadImage("images\\menu\\5.png");
	menupics[6] = iLoadImage("images\\menu\\6.png");
	menupics[7] = iLoadImage("images\\menu\\7.png");
	button[0] = iLoadImage("images\\buttons\\newgame.png");
	button[1] = iLoadImage("images\\buttons\\newgamea.png");
	button[2] = iLoadImage("images\\buttons\\savedgames.png");
	button[3] = iLoadImage("images\\buttons\\savedgamesa.png");
	button[4] = iLoadImage("images\\buttons\\settings.png");
	button[5] = iLoadImage("images\\buttons\\settingsa.png");
	button[6] = iLoadImage("images\\buttons\\credits.png");
	button[7] = iLoadImage("images\\buttons\\creditsa.png");
	button[8] = iLoadImage("images\\buttons\\ashiqul.png");
	button[9] = iLoadImage("images\\buttons\\audio.png");
	button[10] = iLoadImage("images\\buttons\\audioa.png");
	button[11] = iLoadImage("images\\buttons\\cmbs.png");
	button[12] = iLoadImage("images\\buttons\\cmbsa.png");
	button[13] = iLoadImage("images\\buttons\\graphics.png");
	button[14] = iLoadImage("images\\buttons\\graphicsa.png");
	button[15] = iLoadImage("images\\buttons\\high.png");
	button[16] = iLoadImage("images\\buttons\\higha.png");
	button[17] = iLoadImage("images\\buttons\\low.png");
	button[18] = iLoadImage("images\\buttons\\lowa.png");
	button[19] = iLoadImage("images\\buttons\\mbs.png");
	button[20] = iLoadImage("images\\buttons\\mbsa.png");
	button[22] = iLoadImage("images\\buttons\\msa.png");
	button[21] = iLoadImage("images\\buttons\\ms.png");
	button[23] = iLoadImage("images\\buttons\\swapnil.png");
	button[24] = iLoadImage("images\\buttons\\swarna.png");
	button[25] = iLoadImage("images\\buttons\\nirjoy.png");
	button[26] = iLoadImage("images\\buttons\\cms.png");
	button[27] = iLoadImage("images\\buttons\\cmsa.png");
	button[28] = iLoadImage("images\\buttons\\exit.png");
	button[29] = iLoadImage("images\\buttons\\exita.png");
	button[30] = iLoadImage("images\\buttons\\back.png");
	button[31] = iLoadImage("images\\buttons\\backcircle.png");
	button[32] = iLoadImage("images\\buttons\\toggleon.png");
	button[33] = iLoadImage("images\\buttons\\toggleoff.png");
	button[34] = iLoadImage("images\\buttons\\1.png");
	button[35] = iLoadImage("images\\buttons\\2.png");
	button[36] = iLoadImage("images\\buttons\\3.png");
	button[37] = iLoadImage("images\\buttons\\4.png");
	button[38] = iLoadImage("images\\buttons\\5.png");
	button[39] = iLoadImage("images\\buttons\\6.png");
	button[40] = iLoadImage("images\\buttons\\controls.png");
	button[41] = iLoadImage("images\\buttons\\controlsa.png");
	button[42] = iLoadImage("images\\buttons\\image.png");
}
void backbutton()
{
	iShowImage(10, 690, 68, 68, button[31]);
	iShowImage(8 + backpos, 695, 58, 58, button[30]);
	backposcon++;
	if (backposcon == 10) {
		backpos--;
		backposcon = 0;
	}
	if (backpos == 0)
		backpos = 14;

}
void mainpagegif()
{
	statebuttonpos();
	if (menugif < 10) {
		iShowImage(0, 0, 1366, 768, menupics[0]);
		menugif++;
	}
	else if (menugif < 20) {
		iShowImage(0, 0, 1366, 768, menupics[1]);
		menugif++;
	}
	else if (menugif < 30) {
		iShowImage(0, 0, 1366, 768, menupics[2]);
		menugif++;
	}
	else if (menugif < 40) {
		iShowImage(0, 0, 1366, 768, menupics[3]);
		menugif++;
	}
	else if (menugif < 50) {
		iShowImage(0, 0, 1366, 768, menupics[4]);
		menugif++;
	}
	else if (menugif < 60) {
		iShowImage(0, 0, 1366, 768, menupics[5]);
		menugif++;
	}
	else if (menugif < 70) {
		iShowImage(0, 0, 1366, 768, menupics[6]);
		menugif++;
	}
	else if (menugif < 80) {
		iShowImage(0, 0, 1366, 768, menupics[7]);
		menugif++;
		if (menugif == 79)
			menugif = 0;
	}
}
void gamename()
{
	static int mmm = 0;
	mmm++;
	//iSetColor(0,0,0);
	mainpagegif();
	//iFilledRectangle(0,0,1766,768);
	iShowImage(0, -200, 1360, 1200, button[34]);
	if (mmm == 12) {
		gn++;
		mmm = 0;
	}
	if (gn == 39)
		gn = 34;
	iSetColor(255, 255, 255);
	iText(543, 100, "Press (Space) to continue", GLUT_BITMAP_TIMES_ROMAN_24);
}
void mainpage() {
	statebuttonpos();
	fixbuttonpro = 0;
	mainpagegif();
	if (buttonpos[0] > 0) {
		buttonpos[0] = buttonpos[0] * 100 / 110 - 1;
	}
	if (menubutton[0] == 0 || buttonpos[0] > 5) {
		iShowImage(menux, menuy + buttonpos[0], 106 * 4, 30 * 4, button[0]);
	}
	else if (menubutton[0] == 1) {
		iShowImage(menux, menuy, 106 * 4 + 20, 30 * 4 + 6, button[1]);
	}
	if (menubutton[1] == 0 || buttonpos[0] > 5) {
		iShowImage(menux - buttonpos[0], menuy - 100, 106 * 4, 30 * 4, button[2]);
	}
	else if (menubutton[1] == 1) {
		iShowImage(menux, menuy - 100, 106 * 4 + 20, 30 * 4 + 6, button[3]);
	}
	if (menubutton[2] == 0 || buttonpos[0] > 5) {
		iShowImage(menux + buttonpos[0], menuy - 200, 106 * 4, 30 * 4, button[4]);
	}
	else if (menubutton[2] == 1) {
		iShowImage(menux, menuy - 200, 106 * 4 + 20, 30 * 4 + 6, button[5]);
	}
	if (menubutton[3] == 0 || buttonpos[0] > 5) {
		iShowImage(menux, menuy - 300 - buttonpos[0], 106 * 4, 30 * 4, button[6]);
	}
	else if (menubutton[3] == 1) {
		iShowImage(menux, menuy - 300, 106 * 4 + 20, 30 * 4 + 6, button[7]);
	}
	if (menubutton[4] == 0 || buttonpos[0] > 5) {
		iShowImage(menux, menuy - 400 - buttonpos[0], 106 * 4, 30 * 4, button[28]);
	}
	else if (menubutton[4] == 1) {
		iShowImage(menux, menuy - 400, 106 * 4 + 20, 30 * 4 + 6, button[29]);
	}
	if (gn != 0) {
		gamename();
	}

	inmenu = true;
}

void ingame()
{
	statebuttonpos();
	fixbuttonpro = 1;
	inmenu = false;

	if (gameState == 0) {
		failedText();
		iText(600, 184, "~ Press R to restart ~", GLUT_BITMAP_TIMES_ROMAN_24);

	}

	else if (gameState == 1) {
		inCutScene = false;
		if (skipCutScene1) {
			MovesAndVisual0();
		}
		else {
			skipCutScene1 = !cutscene(1);
		}

	}
	else if (gameState == 2) {

		if (loadline <= 100 * 3) {
			inLoad = true;
			//std::cout << "Initial Loading" << std::endl;
			loadingscreen();
		}

		else if (riCount == 0) {
			resetVar();
			initializeDone = InitializeLevel1();
			riCount = 2;
		}

		else if (loadline <= 193 * 3) {
			//std::cout << "Post Initialize Loading" << std::endl;
			loadingscreen();

		}
		else {
			inLoad = false;
			//std::cout << "IN LEVEL1" << std::endl;

			inCutScene = false;
			if (!skipCutScene2) {

				skipCutScene2 = !cutscene(2);
			}
			else {
				MovesAndVisual1();
			}
		}


	}
	else if (gameState == 3) {
		if (loadline <= 100 * 3) {
			//std::cout << "Initial Loading" << std::endl;
			loadingscreen();
		}

		else if (riCount == 2) {
			resetVar();
			intitializeBossLevel();
			riCount++;
		}

		else if (loadline <= 193 * 3) {

			loadingscreen();
		}
		else if (!skipCutScene3) {
			skipCutScene3 = !cutscene(3);
		}
		else {

			MovesAndVisualsBoss();

		}
	}

}

void settings()
{
	fixbuttonpro = 2;
	statebuttonpos();
	mainpagegif();
	if (buttonpos[2] > 0) {
		buttonpos[2] = buttonpos[2] * 100 / 110 - 1;
	}
	if (menubutton[2] == 0 || buttonpos[2] > 5) {
		iShowImage(menux, menuy - 200 + buttonpos[2], 106 * 4, 30 * 4, button[9]);
	}
	else if (menubutton[2] == 1) {
		iShowImage(menux, menuy - 200, 106 * 4 + 20, 30 * 4 + 6, button[10]);
	}
	if (menubutton[3] == 0 || buttonpos[2] > 5) {
		iShowImage(menux - buttonpos[2], menuy - 300, 106 * 4, 30 * 4, button[13]);
	}
	else if (menubutton[3] == 1) {
		iShowImage(menux, menuy - 300, 106 * 4 + 20, 30 * 4 + 6, button[14]);
	}
	if (menubutton[4] == 0 || buttonpos[2] > 5) {
		iShowImage(menux, menuy - 400 - buttonpos[2], 106 * 4, 30 * 4, button[40]);
	}
	else if (menubutton[4] == 1) {
		iShowImage(menux, menuy - 400, 106 * 4 + 20, 30 * 4 + 6, button[41]);
	}
	backbutton();

}
void audio()
{
	fixbuttonpro = 5;
	statebuttonpos();
	mainpagegif();
	//std::cout << mscheck << " " << mbscheck << std::endl;
	if (buttonpos[5] > 0) {
		buttonpos[5] = buttonpos[5] * 100 / 110 - 1;
	}
	if (menubutton[2] == 0 || buttonpos[5] > 5) {
		if (mscheck == 0) {
			iShowImage(menux, menuy - 200 + buttonpos[5], 106 * 4, 30 * 4, button[21]);
		}
		else if (mscheck == 1) {
			iShowImage(menux, menuy - 200 + buttonpos[5], 106 * 4, 30 * 4, button[26]);
		}
	}
	else if (menubutton[2] == 1) {
		if (mscheck == 0) {
			iShowImage(menux, menuy - 200, 106 * 4, 30 * 4, button[22]);
		}
		else if (mscheck == 1) {
			iShowImage(menux, menuy - 200, 106 * 4, 30 * 4, button[27]);
		}
	}
	if (menubutton[3] == 0 || buttonpos[5] > 5) {
		if (mscheck == 0 && mbscheck == 0) {
			iShowImage(menux - buttonpos[5], menuy - 300, 106 * 4, 30 * 4, button[20]);
		}
		else if (mscheck == 1 || mbscheck == 1) {
			iShowImage(menux - buttonpos[5], menuy - 300, 106 * 4, 30 * 4, button[11]);
		}

	}
	else if (menubutton[3] == 1) {
		if (mscheck == 0 && mbscheck == 0) {
			iShowImage(menux, menuy - 300, 106 * 4, 30 * 4, button[19]);
		}
		else if (mscheck == 1 || mbscheck == 1) {
			iShowImage(menux, menuy - 300, 106 * 4, 30 * 4, button[12]);
		}
	}
	backbutton();
}
void graphics()
{
	fixbuttonpro = 6;
	statebuttonpos();
	mainpagegif();
	printf("%d\t%d\t%d\n", amscheck, menubutton[2], menubutton[3]);
	if (buttonpos[6] > 0) {
		buttonpos[6] = buttonpos[6] * 100 / 110 - 1;
	}
	if (menubutton[3] == 1 || buttonpos[6] > 5) {
		if (amscheck == 0) {
			iShowImage(menux - buttonpos[6], menuy - 300, 106 * 4, 30 * 4, button[16]);
			iShowImage(menux, menuy + buttonpos[6] - 200, 106 * 4, 30 * 4, button[17]);
		}
		else if (amscheck == 1) {
			iShowImage(menux - buttonpos[6], menuy - 300, 106 * 4, 30 * 4, button[16]);
			iShowImage(menux, menuy - 200 + buttonpos[6], 106 * 4, 30 * 4, button[17]);
		}
	}
	else if (menubutton[2] == 0 || buttonpos[6] > 5) {
		if (amscheck == 0) {
			iShowImage(menux, menuy - 301, 106 * 4, 30 * 4, button[15]);
			iShowImage(menux, menuy - 201, 106 * 4, 30 * 4, button[17]);
		}
		else if (amscheck == 1) {
			iShowImage(menux, menuy - 201, 106 * 4, 30 * 4, button[17]);
			iShowImage(menux, menuy - 301, 106 * 4, 30 * 4, button[15]);
		}
	}
	else if (menubutton[2] == 1 || buttonpos[6] > 5) {
		if (amscheck == 0) {
			iShowImage(menux, menuy - 301, 106 * 4, 30 * 4, button[15]);
			iShowImage(menux, menuy - 201, 106 * 4, 30 * 4, button[18]);
		}
		else if (amscheck == 1) {
			iShowImage(menux, menuy - 201, 106 * 4, 30 * 4, button[18]);
			iShowImage(menux, menuy - 301, 106 * 4, 30 * 4, button[15]);
		}
	}
	if (buttonpos[6] < 0 && amscheck == 0) {
		iShowImage(menux + 70, menuy - 201 + 38, 10 * 5, 10 * 5, button[32]);
		iShowImage(menux + 70, menuy - 301 + 38, 10 * 5, 10 * 5, button[33]);
	}
	else if (buttonpos[6] < 0 && amscheck == 1) {
		iShowImage(menux + 70, menuy - 301 + 38, 10 * 5, 10 * 5, button[32]);
		iShowImage(menux + 70, menuy - 201 + 38, 10 * 5, 10 * 5, button[33]);
	}
	backbutton();
}
void controls()
{
	mainpagegif();
	iShowImage(100, 200, 400, 550, button[42]);
	iText(140, 670, "Forward...................'d' 'D'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 640, "Backward................'a' 'A'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 700, "Jump.......................'(Space)'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 610, "Craft.........................'e' 'E'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 580, "Shoot.......................'f' 'F'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 550, "Save game...............'o' 'O'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 520, "Load game...............'l' 'L'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 490, "Double jump...........'(Space)2 times'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 370, "Inventory...............'i' 'I'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 430, "Equip item of slot 1.....'1'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 400, "Equip item of slot 2.....'2'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 460, "Use item..................'g' 'G'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 310, "Slice up....................'c' 'C'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 280, "Slice 360 degree.......'v' 'V'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 250, "Ultimate..................'x' 'X'", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(140, 340, "Dodge......................'s' 'S'", GLUT_BITMAP_TIMES_ROMAN_24);
	backbutton();
} 
void savedgame()
{
	statebuttonpos();
	fixbuttonpro = 3;
	//mainpagegif();
	backbutton();
}
void credits()
{
	fixbuttonpro = 4;
	statebuttonpos();
	mainpagegif();
	if (buttonpos[4] > 0) {
		buttonpos[4] = buttonpos[4] * 100 / 110 - 1;
	}
	iShowImage(menux, menuy + buttonpos[4], 106 * 4, 30 * 4, button[23]);
	iShowImage(menux - buttonpos[4], menuy - 100, 106 * 4, 30 * 4, button[8]);
	iShowImage(menux + buttonpos[4], menuy - 200, 106 * 4, 30 * 4, button[24]);
	iShowImage(menux, menuy - 300 - buttonpos[4], 106 * 4, 30 * 4, button[25]);
	backbutton();
}
void exit()
{
	mainpagegif();
	backbutton();
}



void MenuConditions(int mx, int my) {

	if ((mx > 10 && mx < 78) && (my > 690 && my < 758) && (::menu_click == 1 || ::menu_click == 2 || ::menu_click == 3 || ::menu_click == 4)) {
		::menu_click = 0;
		ButtonSound();
	}
	if ((mx > 10 && mx < 78) && (my > 690 && my < 758) && (::menu_click == 5 || ::menu_click == 6 || ::menu_click == 8)) {
		::menu_click = 3;
		ButtonSound();
	}
	else if ((mx > 51 + menux && mx < 380 + menux) && (my > 32 + menuy && my < 88 + menuy) && fixbuttonpro == 0 && gn == 0) {
		::menu_click = 1;
		ButtonSound();
	}
	else if ((mx > 51 + menux && mx < 380 + menux) && (my > 32 + menuy - 100 && my < 88 + menuy - 100) && fixbuttonpro == 0 && gn == 0) {
		::menu_click = 2;
		ButtonSound();
	}
	else if ((mx > 51 + menux && mx < 380 + menux) && (my > 32 + menuy - 200 && my < 88 + menuy - 200) && fixbuttonpro == 0 && gn == 0) {
		::menu_click = 3;
		ButtonSound();
	}
	else if ((mx > 51 + menux && mx < 380 + menux) && (my > 32 + menuy - 300 && my < 88 + menuy - 300) && fixbuttonpro == 0 && gn == 0) {
		::menu_click = 4;
		ButtonSound();
	}
	else if ((mx > 51 + menux && mx < 380 + menux) && (my > 32 + menuy - 200 && my < 88 + menuy - 200) && fixbuttonpro == 2) {
		::menu_click = 5;
		ButtonSound();
	}
	else if ((mx > 51 + menux && mx < 380 + menux) && (my > 32 + menuy - 300 && my < 88 + menuy - 300) && fixbuttonpro == 2) {
		::menu_click = 6;
		ButtonSound();
	}
	else if ((mx > 51 + menux && mx < 380 + menux) && (my > 32 + menuy - 400 && my < 88 + menuy - 400) && fixbuttonpro == 2) {
		::menu_click = 8;
		ButtonSound();
	}
	else if ((mx > 51 + menux && mx < 380 + menux) && (my > 32 + menuy - 400 && my < 88 + menuy - 400) && fixbuttonpro == 0) {
		::menu_click = 7;
		ButtonSound();
	}
}


void MainMenu() {


	if (::menu_click == 0) {
		mainpage();
	}

	if (::menu_click == 1) {
		ingame();
	}
	else if (::menu_click == 2) {
		LoadGame();
	}
	else if (::menu_click == 3) {
		settings();
	}
	else if (::menu_click == 4) {
		credits();
	}
	else if (::menu_click == 5) {
		audio();
	}
	else if (::menu_click == 6) {
		graphics();
	}
	else if (::menu_click == 7) {
		exit(0);
	}
	else if (::menu_click == 8) {
		controls();
	}
}

void loadingscreen()
{
	loaddot++;
	loadline = loadline + 5;

	loadingScr = iLoadImage("images\\loading.png");
	iShowImage(0, 0, 1366, 768, loadingScr);
	iSetColor(255, 255, 255);
	iText(643, 400, "Loading", GLUT_BITMAP_TIMES_ROMAN_24);


	if (loaddot < 5 * 3) {

	}
	else if (loaddot < 10 * 3) {
		iFilledRectangle(730, 400, 3, 3);
	}
	else if (loaddot < 15 * 3) {
		iFilledRectangle(730, 400, 3, 3);
		iFilledRectangle(740, 400, 3, 3);
	}
	else if (loaddot < 20 * 3) {
		iFilledRectangle(730, 400, 3, 3);
		iFilledRectangle(740, 400, 3, 3);
		iFilledRectangle(750, 400, 3, 3);
		if (loaddot == 19 * 3) {
			loaddot = 0;
		}
	}
	iRectangle(600, 361, 193, 12);
	iFilledRectangle(601, 363, loadline / 3, 7);

	iText(423, 300, "Winning isn't always necessary, making the right choice is.", GLUT_BITMAP_TIMES_ROMAN_24);
}


void failedText() {

	if (randT == 0) {
		iText(550, 384, "Maybe there is another way ?", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (randT == 1) {
		iText(640, 384, "Try again!", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (randT == 2) {
		iText(500, 384, "Look again, maybe you will find a way !", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void restartlevel() {
	resetVar();
	InitializeLevel0();
}


#endif
