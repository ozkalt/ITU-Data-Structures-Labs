//
//  main.cpp
//  DS_Lab7
//
//  Created by Tuğba Özkal on 22.11.2016.
//  Copyright © 2016 Tuğba Özkal. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;

#define RIGHT 1
#define LEFT 2
#define DOWN 3
#define UP 4


void printlab(char l[14][22]) {
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 21; j++)
            cout << l[i][j];
        cout << endl;
    }
    cout << endl << endl;
}


char lab[14][22] =
{
    "#####################",
    "#     #           # #",
    "# # # # ###### ## # #",
    "# # #        #    # E",
    "# ##### ######## ## #",
    "o     # # ##   #    #",
    "##### # # ## # # ####",
    "#     # #    #      #",
    "# # # # # ######### #",
    "# # # # # #       # #",
    "# # #   # # #####   #",
    "# # ##### # #   #####",
    "#         #   #     #",
    "#####################"
};


int main() {
    Stack Decision;
    Stack Current;
    Decision.create();
    Current.create();
    
    position temp;
    position start = { 1, 5, 0, 0, 0, 0, 0 };
    position exit = { 20, 3, 0, 0, 0, 0 };
    position p = start;
    
    start.camefrom = LEFT;
    printlab(lab);
    //getchar();
    
    bool goback = false;
    
    while (p.x != exit.x || p.y != exit.y) {
        lab[p.y][p.x] = 'o';
        printlab(lab);
        //getchar();
        
        //first find in how many directions we can move
        if (!goback) {      //if not calculated before
            p.right = 0; p.left = 0; p.down = 0; p.up = 0;
            if (lab[p.y][p.x + 1] != '#' && p.x < 13) p.right = 1;      //right
            if (lab[p.y][p.x - 1] != '#' && p.x > 0) p.left = 1;       //left
            if (lab[p.y - 1][p.x] != '#' && p.y < 21) p.down = 1;       //down
            if (lab[p.y + 1][p.x] != '#' && p.x > 0) p.up = 1;         //up
        }
        else
            goback = false;
        
        //here, one of the possible moves is selected
        bool moved = true;
        
        position past = p;
        if (p.up && p.camefrom != UP){
            p.y++;
            p.camefrom = DOWN;
            past.up = 0;
        }
        else if (p.down && p.camefrom != DOWN){
            p.y--;
            p.camefrom = UP;
            past.down = 0;
        }
        else if (p.left && p.camefrom != LEFT){
            p.x--;
            p.camefrom = RIGHT;
            past.left = 0;
        }
        else if (p.right && p.camefrom != RIGHT) {
            p.x++;
            p.camefrom = LEFT;
            past.right = 0;
        }
        else
            moved = false;         //one direction (the minimum) is open, but this is the direction we came from
        
        if (lab[p.y][p.x + 1] == 'o' && lab[p.y][p.x - 1] == 'o') moved = false;
        else if (lab[p.y + 1][p.x] == 'o' && lab[p.y - 1][p.x] == 'o') moved = false;
        
        Current.push(past);
        if (p.x != exit.x || p.y != exit.y) {
            if ((p.down + p.up + p.right + p.left) >= 2) {
                Decision.push(past);
            }
            
            if (!moved) { //has to go back
                if (!Decision.isEmpty()) {
                    while (Current.top().x != Decision.top().x || Current.top().y != Decision.top().y) {
                        temp = Current.pop();
                        lab[temp.y][temp.x] = ' ';
                        //printlab(lab);
                        //getchar();
                    }
                    p = Decision.pop();
                    goback = true;
                }
            }
        }
    }   //end of while
    
    lab[p.y][p.x] = 'o';
    printlab(lab);
    //getchar();
    cout << "You have solved the maze!" << endl;
    //getchar();
    Decision.close();
    return EXIT_SUCCESS;
}


