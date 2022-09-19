#ifndef VARIABLES
#define VARIABLES_H_INCLUDED

#include "Objects.h"

//Declarations
int riCount = 0;

int dx= 0; 
int change = 0; 
int level = 165; //this our primary level
int Hmax = 300;
int reach_y = 0;
bool jumpY = false; //says has to jump in Y only
bool jump = false; //used to detect jump key pressed or not
double jumpModifier = 0; // used to create parabolic jump action
const int move_speed = 10; // determines the speed of movement
double gravitymodifier = 0; //used in the gravity method
bool direction = false; //use to track move direction

//jump for boar begins
bool boarHitjumpY = false; //says has to jump in Y only
bool boarHitjump = false; //used to detect jump key pressed or not
double boarHitjumpModifier = 0; // used to create parabolic jump action
bool boardirection = false;
//jump for boar ends

//jump for rhino begins
bool rhinoHitjumpY = false; //says has to jump in Y only
bool rhinoHitjump = false; //used to detect jump key pressed or not
double rhinoHitjumpModifier = 0; // used to create parabolic jump action
bool rhinodirection = false;
//jump for rhino ends

int jumpForwardImage = 0;
int jumpBackwardImage = 0;
int jumpingCounter = 0; //used to control when backward running animation will stop

int mouseX = -100 , mouseY = -100;
int menu_click = 0;
int Menu, Credits;
bool inmenu = false; 

double maxHealth = 700;
double heroHealth = 700;
double shootDamage = 1;


int gameState= 2;
int heroState = 1;

const int invX = 343, invY = 184;
int crosshair = 0;
int inventory = -1;
int invImg = 1;
int equipImg = 0;

int portalx = 565, portaly = level-25, pindex = 0;
bool portal = false;

//DayNight Variables
int index = 0;
bool dayTime = true;
ll prevSwitch = 0;

//Rain Variables
bool rainOn = false;
int rainOncnt = 8000;
int rainOffcnt = 5000;

//music.h
int gameP = 0;
//music.h

//Dynamic Background Variables
int backgroundWidth = 6830;
int backgroundRepeat = 2;
bool slice;
std::vector <unsigned int> sliceF, sliceB, sliceUpF, sliceUpB, sliceDownF, sliceDownB, slice360F, slice360B, dodgeMoveF, dodgeMoveB, rollF, rollB;; 
std::vector <unsigned int> ultMoveF, ultMoveB;
int x = 0, reset = 0;

//new
int healthBarImg = 0;
int craftQImg = 0;
int loadingScr = 0;
int guideImg = 0;
bool guide = false;
int buttonAImg = 0;
int buttonDImg = 0;

bool sliceUp = false;
bool sliceDown = false;
bool slice360 = false;
bool ultMove = false;
bool dodge = false; 
bool roll = false; 
double sliceDamage = 2;
double sliceUpDamage = 3;
double slice360Damage = 4;

double ultMoveDamage = 10;

bool bombEquip = false;
bool smokeEquip = false;
bool stunEquip = false;
bool stpotionEquip = false;
bool hpotionEquip = false;
bool cheetahbloodEquip = false;
bool coilEquip = false;

//effects animations [dont save]
int bloodFrame = 0;
int bloodX = 0;
int bloodY = 0;
bool bloodAnimation = false;
int smokeFrame = 0;
int stunFrame = 0;
int bombFrame = 0;
bool bombAnimation = false;
int bombX = 0;
int bombIcon = 0;

int mmmm = 0;
int portalTextImg = 0;
int slotAvail = 3;

//levelupgrade vars
int swordLv = 0, backpackLv = 0, armorLv = 0;
int bLimit = 3, equipLimit = 6;
int currentBItem = 0, equippedItemCount= 0;



std::vector <unsigned int> runEmtF, runEmtB, runPistolF, runPistolB, portalImg;
std::vector <unsigned int> bgLevel1day;
std::vector <unsigned int> bgLevel1dayB;
std::vector <unsigned int> bgLevel1night;
std::vector <unsigned int> bgLevel1nightB;
std::vector <unsigned int> bossLevel;
std::vector <unsigned int> blood;
std::vector <unsigned int> smoke;
std::vector <unsigned int> stun;
std::vector <unsigned int> bomb;
std::vector <unsigned int> act1;
std::vector <unsigned int> act2;
std::vector <unsigned int> act3;
std::vector <unsigned int> act4;
std::vector <unsigned int> act5;
std::vector <unsigned int> guideImage;
std::map<std::string, std::vector<GameObject>> objects;
std::map<std::string, TimeStamp> counters;
std::map<std::string, GameObject> boss;
std::map<std::string, std::vector<GameObject>> destructed;
std::map<std::string, Item> items;
std::map < ll, Equipments > equipmentsHash;


void addObj(std::string name, GameObject& obj) {
	objects[name].push_back(obj);
}

//void addEquipments(double hash, Equipments& itm) {
//	equipmentsHash[hash].push_back(itm);
//}


GameObject hero(683, 250, 75, 25);


//MENU VARIABLES DONT SAVE
long long loaddot = 0;
int loadline = 0;
bool initializeDone = false;
int menupics[8] = { 0 };
int menugif = 0;
int button[100] = { 0 };
int menubutton[100] = { 0 };
int buttonpos[100] = { 1000 };
void loadingscreen();
void failedText();
int fixbuttonpro;
int mscheck = 0, mbscheck = 0;
int amscheck = 1;
int msbugfix = 0;
int amsbugfix = 0;
int backpos = 14, backposcon = 0;
int menux = 471, menuy = 575;
int gn = 34;

//cutscene save
bool inCutScene = false;
bool skipCutScene1 = false;
bool skipCutScene2 = false;
bool skipCutScene3 = false;

//boss defeat check save
bool tanakeDefeated = true;
bool DemonDefeated = false;

//XP and Stamina save
double maxXP = 200;
int characterlevel = 0;
double XP = 180;
double maxStamina = 200;
double stamina = 200;




void resetVar() {

	dx = 0;
	change = 0;
	Hmax = 300;
	reach_y = 0;
	jumpY = false; //says has to jump in Y only
	jump = false; //used to detect jump key pressed or not
	jumpModifier = 0; // used to create parabolic jump action
	gravitymodifier = 0; //used in the gravity method
	direction = false; //use to track move direction

	//jump for boar begins
	boarHitjumpY = false; //says has to jump in Y only
	boarHitjump = false; //used to detect jump key pressed or not
	boarHitjumpModifier = 0; // used to create parabolic jump action
	boardirection = false;
	//jump for boar ends

	jumpForwardImage = 0;
	jumpBackwardImage = 0;
	jumpingCounter = 0; //used to control when backward running animation will stop

	inmenu = false;

	heroHealth = 200;
	heroState = 1;
	
	inventory = -1;
	invImg = 1;

	portalx = 565, portaly = level - 25, pindex = 0;
	portal = false;

}

#endif
