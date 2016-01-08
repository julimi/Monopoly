//
//  nh.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "nh.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

NH::NH(string name, int loc): Unownable(name, loc) {}

void NH::change(Player &p) {
    srand(time(NULL));
    if ((rand() % 100 + 1) == 1 && p.getTcup() < 4) {
        if (getbanben()) {
            cout << "-> Congradulations! You get 1 Government Statement!" << endl;
            p.add_cup();
            cout << "-> Now you have " << p.getCups() << " Statement!" << endl;
        } else {
        cout << "-> Congradulations! You get 1 Roll Up the Rim Cup!" << endl;
        p.add_cup();
        cout << "-> Now you have " << p.getCups() << " RURP!" << endl;
        }
    } else {
        int rate = rand() % 18 + 1;
        
        if (rate == 1) {
            if (getbanben()) {
                cout << "-> You bit the 5 Old Stars. $200 please." << endl;
            } else {
            cout << "-> You kick the front door and it is broken. $200 please." << endl;
            }
            cout << "-> Your original money: $" << p.getMoney() << endl;
            p.sub_money(200);
            cout << "-> Your current money: $" << p.getMoney() << endl;
        } else if (rate >= 2 && rate <= 3) {
            if (getbanben()) {
                cout << "-> You hack a desk by hand to run. $100 please." << endl;
            } else {
            cout << "-> You hack a desk by hand to practice karate. $100 please." << endl;
            }
            cout << "-> Your original money: $" << p.getMoney() << endl;
            p.sub_money(100);
            cout << "-> Your current money: $" << p.getMoney() << endl;
        } else if (rate >= 4 && rate <= 6) {
            cout << "-> HaHa! You just pay without any reasons! $50 please." << endl;
            cout << "-> Your original money: $" << p.getMoney() << endl;
            p.sub_money(50);
            cout << "-> Your current money: $" << p.getMoney() << endl;
        } else if (rate >= 7 && rate <= 12) {
            cout << "-> HaHa! Someone gives you $25 without any reasons!" << endl;
            cout << "-> Your original money: $" << p.getMoney() << endl;
            p.add_money(25);
            cout << "-> Your current money: $" << p.getMoney() << endl;
        } else if (rate >= 13 && rate <= 15) {
            cout << "-> You pick up a $50 cash. You Bad Bad." << endl;
            cout << "-> Your original money: $" << p.getMoney() << endl;
            p.add_money(50);
            cout << "-> Your current money: $" << p.getMoney() << endl;
        } else if (rate >= 16 && rate <= 17) {
            if (getbanben()) {
                cout << "-> You pick up a $100 cash! You Bad Bad totally! Are u Joker?" << endl;
            } else {
            cout << "-> You pick up a $100 cash! You Bad Bad totally! Are u Lefi?" << endl;
            }
            cout << "-> Your original money: $" << p.getMoney() << endl;
            p.add_money(100);
            cout << "-> Your current money: $" << p.getMoney() << endl;
        } else {
            if (getbanben()) {
                cout << "-> Someone gives you $200 to bomb the World Court and you are success! HeHeHe!" << endl;
            } else {
            cout << "-> Someone gives you $200 to bomb NH and you are success! HeHeHe!" << endl;
            }
            cout << "-> Your original money: $" << p.getMoney() << endl;
            p.add_money(200);
            cout << "-> Your current money: $" << p.getMoney() << endl;
        }
    }
    cout << endl;
    if (p.getMoney() < 0) {
        cout << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!You gonna bankrupt!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "-> Drop out now. " << endl;
        cout << "-> Trade, mortgage buildings and sell improvements to gather the required money" <<endl;
    }
}

NH::~NH() {}


