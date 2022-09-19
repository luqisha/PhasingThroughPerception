#ifndef OBJECTS
#define OBJECTS_H_INCLUDED

#include "stdc++.h"
#include "iGraphics.h"
#include "bitmap_loader.h"

#define SIZE (int)1e5+10
#define MOD 100000007
#define mem(n,m) memset(n,m,sizeof(n))
#define ll long long

//intial global declarations starts

int delay = 0; //resetable 

double TIME = 0;

//intial global declarations ends


void RandomAlgorithm() {
	srand(time(0));
}

class TimeStamp {

	//Best to use map to tag TimeStamps
public:
	double t1;
	double target;

	TimeStamp() {

	}

	TimeStamp(double target) {
		this->t1 = ::TIME;
		this->target = target;
	}

	bool Counter() {

		if (::TIME - this->t1 >= this->target) {
			return true;
		}
		return false;
	}

};


char* to_char(int n)
{
	char buffer[20];
	sprintf(buffer, "%d", n);
	char* s = buffer;
	//std::string s = buffer;
	return s;
}

char* to_char(std::string n)
{
	char buffer[50];
	sprintf(buffer, "%d", n);
	//char* s = buffer;
	std::string s = buffer;
	return (char*)s.c_str();
}


template < typename T > std::string to_string(const T& n)
{
	std::ostringstream stm;
	stm << n;
	return stm.str();
}  //this template is for the function "to_String()"


ll convertToASCIIsum(std::string word)
{
	ll sum = 0;
	for (int z = 0; z < word.length(); z++)
	{
		//char x = word[z];
		sum = sum + (int)word[z];
	}
	return sum;
}

std::vector <unsigned int > loadImage(std::vector<unsigned int> V1, std::string location, unsigned int numberofImages) {
	char loader[100]; //for loading images in a vector using iLoadImage
	std::string str1_1 = location;
	std::string str1_2 = ".png";
	for (int i = 0; i <= numberofImages; i++) {
		std::string str = str1_1 + to_string(i) + str1_2;
		strcpy(loader, str.c_str());
		V1.push_back(iLoadImage(loader));
	}
	return V1;
}


struct Materials {

	std::string name;
	unsigned int img;
	int x, y;
	int n;
	int slotID;
	double UniqueWeight;

	Materials() {
		this->img = 0;
		this->x = 0;
		this->y = 0;
		this->n = 0;
		this->UniqueWeight = 0;
		slotID = 0;
		
		//std::cout << "Default Item Constructor Called" << std::endl;
	};

	Materials(std::string name, unsigned int img, float weight) {
		this->name = name;
		this->img = img;
		this->UniqueWeight = weight;
		this->x = 0;
		this->y = 0;
		this->n = 0;
	}
};

struct Equipments {
	std::string name;
	unsigned int img;
	int x, y;
	int n;
	int slotID;
	bool equipClick;

	Equipments() {
		this->img = 0;
		this->x = 0;
		this->y = 0;
		this->n = 0;
		this -> slotID = 0;
		this->equipClick = false;

		//std::cout << "Default Equipment Constructor Called" << std::endl;
	};

	Equipments(std::string name, unsigned int img) {
		this->name = name;
		this->img = img;
		this->x = 0;
		this->y = 0;
		this->n = 0;
		this->equipClick = false;
	}
};


class GameObject {
public:
	int x;
	int y;
	int height;
	int width;
	std::vector < unsigned int > imagesF, imagesB;
	std::vector<int> attackF;
	std::vector<int> attackB;
	int frame;
	int numberOfFrames;
	bool running;
	double maxHealth;
	double health;
	int deadImageF;
	int deadImageB;
	bool deadDirection;
	int icon;
	bool stunned;

	//boar variables start

	bool boarsense;
	int boarvision;
	double boarspeed;
	double boarTopSpeed;
	double boarAcceleration;
	//boar variables ends

	//boar variables start

	bool rhinosense;
	int rhinovision;
	double rhinospeed;
	double rhinoTopSpeed;
	double rhinoAcceleration;
	//boar variables ends

	//lion variables starts
	bool lionsense;
	int lionvision;
	double lionspeed;
	double lionTopSpeed;
	double lionAcceleration;
	bool lionHittable;
	int lionHitFrame;

	//lion variables ends

	//Tiger variables stars
	bool tigersense;
	int tigervision;
	double tigerspeed;
	double tigerTopSpeed;
	double tigerAcceleration;
	bool tigerHittable;
	int tigerHitFrame;

	//Tiger variables ends

	//boss variables starts

	bool bosssense;
	int bossvision;
	double bossspeed;

	//boss variables ends

	GameObject() {
		std::cout << "Default Constructor Called" << std::endl;
	}


	GameObject(int sx, int sy, int height, int width) {
		x = sx;
		y = sy;
		this->height = height;
		this->width = width;
		frame = 0;
		numberOfFrames = 0;
		running = false;
		this->maxHealth = 0;
		this->health = 0;
		this->stunned = false;

		this->boarsense = false;
		this->boarspeed = 0;
		this->boarvision = 600;
		this->boarTopSpeed = (double)(25 + (rand() % 10)) / 10;
		this->boarAcceleration = (double)(10 + (rand() % 8)) / 100.0000000;

		this->rhinosense = false;
		this->rhinospeed = 0;
		this->rhinovision = 500;
		this->rhinoTopSpeed = (double)(25 + (rand() % 8)) / 10;
		this->rhinoAcceleration = (double)(3 + (rand() % 5)) / 100.0000000;

		this->lionsense = false;
		this->lionspeed = 0;
		this->lionvision = 600;
		this->lionTopSpeed = (double)(45 + (rand() % 15)) / 10;
		this->lionAcceleration = (double)(5 + (rand() % 5)) / 100.0000000;
		this->lionHittable = false;

		this->tigersense = false;
		this->tigerspeed = 0;
		this->tigervision = 600;
		this->tigerTopSpeed = (double)(45 + (rand() % 15)) / 10;
		this->tigerAcceleration = (double)(5 + (rand() % 5)) / 100.0000000;
		this->tigerHittable = false;

	}

	GameObject(int sx, int sy, int height, int width, int bossvision, int bossspeed) {
		x = sx;
		y = sy;
		this->height = height;
		this->width = width;
		frame = 0;
		numberOfFrames = 0;
		running = false;

		this->bossvision = bossvision;
		this->bossspeed = bossspeed;
		this->bosssense = false;
	}

	GameObject(int sx, int sy, int height, int width, char file[]) {
		x = sx;
		y = sy;
		this->height = height;
		this->width = width;
		this->imagesF.push_back(iLoadImage(file));
		frame = 0;
		numberOfFrames = 0;
		running = false;
		boarsense = false;
		this->boarspeed = 0;
		this->boarvision = 600;
		this->boarTopSpeed = (double)(20 + rand() % 20) / 10;
		this->boarAcceleration = (double)(10 + rand() % 8) / 100.0000000;
	}

	GameObject(int sx, int sy, int height, int width, std::vector <unsigned int > vecF, std::vector <unsigned int > vecB) {
		x = sx;
		y = sy;
		this->height = height;
		this->width = width;
		this->imagesF = vecF;
		this->imagesB = vecB;
		frame = 0;
		numberOfFrames = 0;
		running = false;
		boarsense = false;
		this->boarspeed = 0;
		this->boarvision = 600;
		this->boarTopSpeed = (double)(20 + rand() % 20) / 10;
		this->boarAcceleration = (double)(10 + rand() % 8) / 100;
	}




	void show(bool x, int skip) {
		if (x == false)
		{
			iShowImage(this->x, this->y, this->width, this->height, this->imagesF[0]);
		}
		else {
			iShowImage(this->x, this->y, this->width, this->height, this->imagesB[0]);
		}
	}

	void showDead() {
		if (this->deadDirection == false) {
			iShowImage(this->x, this->y, this->width, this->height, this->deadImageF);
		}
		else {
			iShowImage(this->x, this->y, this->width, this->height, this->deadImageB);
		}
	}


	void loadImageF(std::string location, unsigned int numberofImages) {
		char loader[100]; //for loading images in vector using iLoadImage
		std::string str1_1 = location;
		std::string str1_2 = ".png";
		for (int i = 0; i <= numberofImages; i++) {
			std::string str = str1_1 + to_string(i) + str1_2;
			strcpy(loader, str.c_str());
			this->imagesF.push_back(iLoadImage(loader));
		}

		this->numberOfFrames = numberofImages;

	}

	void loadattackImageF(std::string location, unsigned int numberofImages) {
		char loader[100]; //for loading images in vector using iLoadImage
		std::string str1_1 = location;
		std::string str1_2 = ".png";
		for (int i = 0; i <= numberofImages; i++) {
			std::string str = str1_1 + to_string(i) + str1_2;
			strcpy(loader, str.c_str());
			this->attackF.push_back(iLoadImage(loader));
		}

	}

	//void loadImageF(std::string location,int startIndex, int endIndex) {
	//	char loader[100]; //for loading images in vector using iLoadImage
	//	std::string str1_1 = location+"(";
	//	std::string str1_2 = ").png";
	//	for (int i = startIndex; i <=endIndex; i++) {
	//		std::string str = str1_1 + to_string(i) + str1_2;
	//		strcpy(loader, str.c_str());
	//		this->imagesF.push_back(iLoadImage(loader));
	//	}

	//	this->numberOfFrames = endIndex-startIndex;

	//}

	void loadImageB(std::string location, unsigned int numberofImages) {
		char loader[100]; //for loading images in vector using iLoadImage
		std::string str2_1 = location;
		std::string str2_2 = ".png";
		for (int i = 0; i <= numberofImages; i++) {
			std::string str = str2_1 + to_string(i) + str2_2;
			strcpy(loader, str.c_str());
			this->imagesB.push_back(iLoadImage(loader));
		}
		this->numberOfFrames = numberofImages;
	}

	void loadattackImageB(std::string location, unsigned int numberofImages) {
		char loader[100]; //for loading images in vector using iLoadImage
		std::string str2_1 = location;
		std::string str2_2 = ".png";
		for (int i = 0; i <= numberofImages; i++) {
			std::string str = str2_1 + to_string(i) + str2_2;
			strcpy(loader, str.c_str());
			this->attackB.push_back(iLoadImage(loader));
		}
	}


	//void loadImageB(std::string location, int startIndex, int endIndex) {
	//	char loader[100]; //for loading images in vector using iLoadImage
	//	std::string str1_1 = location + "(";
	//	std::string str1_2 = ").png";
	//	for (int i = startIndex; i <= endIndex; i++) {
	//		std::string str = str1_1 + to_string(i) + str1_2;
	//		strcpy(loader, str.c_str());
	//		this->imagesB.push_back(iLoadImage(loader));
	//	}

	//	this->numberOfFrames = endIndex - startIndex;

	//}

};

class Item {

public:
	int pos;
	int radius;
	TimeStamp t;

	Item() {

	}

	Item(int pos,int radius, double activeTime) {
		this->pos = pos;
		this->radius = radius;
		this->t = TimeStamp(activeTime);
	}
};




class circle {
public:
	int x;
	int y;
	int r;
	circle(int x, int y, int r) {
		this->r = r;
		this->x = x;
		this->y = y;
	}
};



#endif
