#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#define DEBUG(x) cout << __FILE__ << " // " << __LINE__ << " // " << #x << " : " << x << endl;

using namespace std;

class Player {
    private:
        int status;		//	Will increment as the game progresses.
		int x;
        int y;
        int prevX;
        int prevY;
    
    public:
        Player();
        ~Player();

        void setLocation(int d);
        void printRoom(string file);
};

Player::Player() {
    this->x = 0;
    this->y = 0;
	this->status = 0;
    
    printRoom("entryHall.txt");
}

Player::~Player() {
    cout << "\nGAME OVER\n";
}

void Player::setLocation(int d) {
    //  DEBUG(this->status);
	this->prevX = this->x;
    this->prevY = this->y;

    switch(d) {
        case 1:
            this->y++;
            break;
        case 2:
            this->x++;
            break;
        case 3:
            this->y--;
            break;
        case 4:
            this->x--;
            break;
    }

    if(this->x == 0 && this->y == 0) {
        	printRoom("entryHall.txt");
    }
    else if(this->x == 0 && this->y == 1) {
        printRoom("mainRoom.txt");
    }
    else if((this->x == 1 && this->y == 1)) {
        if(this->status == 2) {
			printRoom("gameOver.txt");
            cout << ">>";
            cin.ignore();
            cin.get();

			delete this;
		}
		else {
			printRoom("entryHall.txt");
		}
    }
    else if(this->x == 2 && this->y == 1) {
        if(this->status == 1) {
			printRoom("armRoom1.txt");
			this->status++;
		}
		else {
			printRoom("armRoom.txt");
		}
	}
	else if(this->x == 0 && this->y == 2) {
        printRoom("entryHall.txt");
    }
    else if(this->x == 0 && this->y == 3) {
        printRoom("ringRoom.txt");
		this->status++;
    }
    else {
        this->x = this->prevX;
        this->y = this->prevY;

        printRoom("noRoom.txt");
    }
}

void Player::printRoom(string file) {
    fstream roomFile;
    string roomDesc;

    roomFile.open(file);
    while(!roomFile.eof()) {
        getline(roomFile, roomDesc);
        cout << roomDesc << endl;
    }
}

#endif