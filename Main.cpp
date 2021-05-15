#include <iostream>
#include "Player.h"

using namespace std;

int main() {
    Player player;
    int direction;

    do {
        cout << "\nWhere will you go?\n";
        //  only four possible directions. reject input if outside 1-4.
        cout << "\t1. NORTH\n";
        cout << "\t2. WEST\n";
        cout << "\t3. SOUTH\n";
        cout << "\t4. EAST\n";
        cout << ">>";
        cin >> direction;

        if(direction < 1 || direction > 4) {
            cout << "\nYou pace around the room, not going anywhere in particular.\n";
        }

        if(direction != -1) {
            player.setLocation(direction);
        }
    } while(direction != -1);    //  -1 is only a temporary value to quit
    
    return 0;
}