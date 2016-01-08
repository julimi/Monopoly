//
//  tuition.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "tuition.h"
#include <iostream>

using namespace std;

Tuition::Tuition(string name, int loc): Unownable(name, loc) {}

void Tuition::change(Player &p) {
    if (getbanben()) {
        cout << "-> You should pay pass to Navy Base. Please choose a paying way: " << endl;
    } else {
    cout << "-> You should pay tuition to UW. Please choose a paying way: " << endl;
    }
    cout << "-> enter 1 : $300 " << endl;
    cout << "-> enter 2 : 10% of your total assets " << endl;
    
    int choice;
    while (cin >> choice) {
       if (choice == 1) {
           cout << "-> You choose to pay $300. " << endl;
           cout << "-> Your original money: $" << p.getMoney() << endl;
           p.sub_money(300);
           cout << "-> Your current money: $" << p.getMoney() << endl;
           break;
       } else if (choice == 2) {
           cout << "-> You choose to pay 10% of your total assets. " << endl;
           cout << "-> Your original money: $" << p.getMoney() << endl;
           choice = p.getAsset();
           choice *= 0.1;
           p.sub_money(choice);
           cout << "-> Your current money: $" << p.getMoney() << endl;
           break;
       } else {
           cout << "-> No this choice, choose again." << endl;
           cout << "-> enter 1 : $300 " << endl;
           cout << "-> enter 2 : 10% of your total assets " << endl;
       }
    }
    if (p.getMoney() < 0) {
        cout << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!You gonna bankrupt!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "-> Drop out now. " << endl;
        cout << "-> Trade, mortgage buildings and sell improvements to gather the required money." <<endl;
    }
}

Tuition::~Tuition() {}


