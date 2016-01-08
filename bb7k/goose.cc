//
//  goose.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "goose.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Goose::Goose(string name, int loc): Unownable(name, loc), left(0) {}

void Goose::change(Player &p) {
    if (getbanben()) {
        if (left > 0) {
            cout << "-> Congradulations! You pick up a money bag of $" << left <<endl;
            cout << "-> Your original money: $" << p.getMoney() << endl;
            p.add_money(left);
            left = 0;
            cout << "-> Your current money: $" << p.getMoney() << endl;
        }
        
        srand(time(NULL));
        
        // 5% opportunity attacked by geese and go die
        int rate = rand() % 100 + 1;
        if (rate >= 1 && rate <= 8) {
            p.set_die();
            cout << "-> So sad! You are attacked by hundreds of Seaking and you die. R.I.P" << endl;
            cout << "-> You leave all your money and you drop out the game." << endl;
            left = p.getMoney();
            p.sub_money(left);
        } else {
            cout << "-> Oops! Many Seaking gonna attack you!" << endl;
            cout << "-> But they miss. Don't worry" << endl;
        }
    }
    else {
        cout << "-> Oops! Many geese gonna attack you!" << endl;
        cout << "-> But they miss. Don't worry. Nothing happens." << endl;
    }
}

Goose::~Goose() {}



