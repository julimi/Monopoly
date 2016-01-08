//
//  coop.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "coop.h"
#include <iostream>

using namespace std;

Coop::Coop(string name, int loc): Unownable(name, loc) {}

void Coop::change(Player &p) {
    if (getbanben()) {
        if (p.getchar() != '7') {
        cout << "-> Oops! You meet Water 7! You have to pay $150 for your life." << endl;
        cout << "-> Your original money: $" << p.getMoney() << endl;
        p.sub_money(150);
        cout << "-> Your current money: $" << p.getMoney() << endl;
        cout << endl;
        if (p.getMoney() < 0) {
            
            cout << "!!!!!!!!!!!!!!!!!!!!!!You gonna bankrupt!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "-> Drop out now. " << endl;
            cout << "-> Trade, mortgage buildings and sell improvements to gather the required money." <<endl;
        }
        } else {
            cout << "-> This is place of Water 7, welcome home!" << endl;
            cout << "-> You get recharge of $150!" << endl;
            cout << "-> Your original money: $" << p.getMoney() << endl;
            p.add_money(150);
            cout << "-> Your current money: $" << p.getMoney() << endl;
            cout << endl;
        }
    } else {
    cout << "-> You should pay coop fee of $150 to UW." << endl;
    cout << "-> Your original money: $" << p.getMoney() << endl;
    p.sub_money(150);
    cout << "-> Your current money: $" << p.getMoney() << endl;
    cout << endl;
    if (p.getMoney() < 0) {
        
        cout << "!!!!!!!!!!!!!!!!!!!!!!You gonna bankrupt!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "-> Drop out now. " << endl;
        cout << "-> Trade, mortgage buildings and sell improvements to gather the required money." <<endl;
    }
    }
}

Coop::~Coop() {}

