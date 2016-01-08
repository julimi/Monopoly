//
//  gym.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-18.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "gym.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Gym::Gym(string name, int loc, int cost, int pay, string block, int blockcap): Ownable(name, loc, cost, pay, block, blockcap) {}

void Gym::change(Player &p) {
    if (getowner() != NULL) {
    if (getowner()->getname() != p.getname()) {
    if (getmort()) {
        cout << "-> You don't need to pay any fees to " << getowner()->getname() << "." << endl;
    } else {
        cout << "-> You should pay pass to the owner, " << getowner()->getname() << "." << endl;
        cout << "-> First of all, you should roll 2 dices." << endl;
        int dice1, dice2, total;
        if (getowner()->gettest()) {
            cout << ">>>>>>>>>>>>>>>>>>>>Test Mode<<<<<<<<<<<<<<<<<<<<<" << endl;
            cout << endl;
            cout << "-> enter the number of dices" << endl;
            cout << "-> The first dice: ";
            cin >> dice1;
            cout << endl;
            cout << "-> The second dice: ";
            cin >> dice2;
            cout << endl;
        } else {
        srand(time(NULL));
        dice1 = (rand() % 6) + 1;
        dice2 = (rand() % 6) + 1;
        }
        cout << "-> You roll " << dice1 << "and " << dice2 << "." << endl;
        total = dice1 + dice2;
        if (total == 12) cout << "-> HaHaHa! Lucky!" << endl;
        cout << "-> You get total " << total << endl;
        
        if (getowner()->getGnum() != 4) {
            total *= 4;
            if (getbanben()) {
                cout << "-> " << getowner()->getname() << " only owns 1 MOJIAO, so you just need to pay 4 times of total, $" << total << "." << endl;
            } else {
            cout << "-> " << getowner()->getname() << " only owns 1 Gym, so you just need to pay 4 times of total, $" << total << "." << endl;
            }
        } else {
            total *= 10;
            if (getbanben()) {
                cout << "-> " << getowner()->getname() << " owns 2 MOJIAOs, so you should pay 10 times of total, $" << total << "." << endl;
            } else {
            cout << "-> " << getowner()->getname() << " owns 2 Gyms, so you should pay 10 times of total, $" << total << "." << endl;
            }
        }
        
        cout << endl;
        cout << "-> Your original money: $" << p.getMoney() << endl;
        p.sub_money(total);
        cout << "-> Your current money: $" << p.getMoney() << endl;
        cout << endl;
        if (p.getMoney() < 0) {
            total += p.getMoney();
            getowner()->add_money(total);
            cout << "!!!!!!!!!!!!!!!!!!!!!!You gonna bankrupt!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "-> Drop out now. " << endl;
            cout << "-> Trade, mortgage buildings and sell improvements to gather the required money." <<endl;
        } else getowner()->add_money(total);
    }
    }
    } else buy(p);
}



Gym::~Gym() {}



