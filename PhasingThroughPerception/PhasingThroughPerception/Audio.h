#ifndef AUDIO
#define AUDIO_H_INCLUDED
#include "Variables.h"

bool musicOn = true;
bool BGmusicOn = true;
void music() {
	musicOn = !mscheck;
	BGmusicOn = !mbscheck;
	//std::cout << "MUSIC ON " << musicOn << "BGmusicOn " << musicOn << std::endl;
	if (musicOn == true) {
		if (gameState == 1 && inmenu == true)
		{

			mciSendString("play music\\breakout.wav ", NULL, 0, 0);

		}
		if (BGmusicOn == true) {
			if (gameState == 1 && inmenu == false)
			{
				mciSendString("close music\\breakout.wav", NULL, 0, 0);
				mciSendString("play music\\incaVolUpdate.wav ", NULL, 0, 0);

			}
		}

		if (BGmusicOn == true) {
			if (gameState == 2 && inmenu == false)
			{

				mciSendString("close music\\breakout.wav", NULL, 0, 0);
				mciSendString("play music\\incaVolUpdate.wav", NULL, 0, 0);
			}
		}
		if (BGmusicOn == true) {
			if (gameState == 3 && inmenu == false)
			{

				mciSendString("close music\\breakout.wav", NULL, 0, 0);
				mciSendString("play music\\incaVolUpdate.wav", NULL, 0, 0);
			}
		}

	}
	else {
		mciSendString("close music\\incaVolUpdate.wav", NULL, 0, 0);
		mciSendString("close music\\breakout.wav", NULL, 0, 0);
	}
}


/*void JumpSound() {
	mciSendString("play music\\Jump.wav", NULL, 0, 0);
}*/


void ButtonSound() {
	if (musicOn == true) {

		mciSendString("play music\\Collide.wav", NULL, 0, 0);
	}
}
void ShootSound() {
	if (musicOn == true) {

		mciSendString("play music\\9mm.wav", NULL, 0, 0);
	}
}
void SliceSound() {
	if (musicOn == true) {
		mciSendString("play music\\slice.wav", NULL, 0, 0);
	}
}
void RainSound() {
	if (musicOn == true) {
		if (rainOn = true) {
			mciSendString("play music\\rain.wav", NULL, 0, 0);
		}
	}
}

void PowerSound1() {
	if (musicOn == true) {
		mciSendString("close music\\fireball2.wav", NULL, 0, 0);
		mciSendString("close music\\fireball1.wav", NULL, 0, 0);
		mciSendString("play music\\fireball3.wav", NULL, 0, 0);
	}
}
void PowerSound3() {
	if (musicOn == true) {
		mciSendString("close music\\fireball3.wav", NULL, 0, 0);
		mciSendString("close music\\fireball1.wav", NULL, 0, 0);
		mciSendString("play music\\fireball2.wav", NULL, 0, 0);
	}
}
void PowerSound2() {
	if (musicOn == true) {

		mciSendString("close music\\fireball3.wav", NULL, 0, 0);
		mciSendString("close music\\fireball2.wav", NULL, 0, 0);
		mciSendString("play music\\fireball1.wav", NULL, 0, 0);
	}

}
void RunningSound() {
	if (musicOn == true) {
		if (jump == false && rhinoHitjump == false && boarHitjump == false && hero.running) {
			mciSendString("play music\\running1.wav", NULL, 0, 0);
		}
	}
}
void DemonWalkSound() {
	if (musicOn == true) {
		if (boss["demon"].bosssense == true) {
			mciSendString("play music\\MonsterWalk.wav", NULL, 0, 0);
		}
		else {
			mciSendString("close music\\MonsterWalk.wav", NULL, 0, 0);
		}
	}
}
void RhinoSound() {
	if (musicOn == true) {

		mciSendString("play music\\rhino.wav", NULL, 0, 0);
	}
}

void BoarSound() {
	if (musicOn == true) {

		mciSendString("play music\\boar.wav", NULL, 0, 0);
	}
}

void TigerSound() {
	if (musicOn == true) {

		mciSendString("play music\\tiger1.wav", NULL, 0, 0);
	}
}

void LionSound() {
	if (musicOn == true) {

		mciSendString("play music\\lion.wav", NULL, 0, 0);
	}
}

#endif