//
//  residence.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-18.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "residence.h"

using namespace std;

Residence::Residence(string name, int loc, int cost, int pay, string block, int blockcap): Ownable(name, loc, cost, pay, block, blockcap) {}

void Residence::change(Player &p) {
    if (getowner() != NULL) {
    if (getowner()->getname() != p.getname()) {
    if (getmort()) {
        if (getbanben()) {
            cout << "-> You don't need to pay the food of " << getowner()->getname() << "'s Shenshou." << endl;
        } else {
        cout << "-> You don't need to pay the rent of " << getowner()->getname() << "'s redience." << endl;
        }
    } else {
        int total = getPay();
        int Rnum = getowner()->getRnum();
        if (Rnum == 2) total *= 2;
        else if (Rnum == 3) total *= 4;
        else if (Rnum == 4) total *= 8;
        if (getbanben()) {
            cout << "-> " << getowner()->getname() << " has " << Rnum << " Shenshous." << endl;
            cout << "-> So you need to pay food of $" << total << "." << endl;
        } else {
        cout << "-> " << getowner()->getname() << " has " << Rnum << " residences." << endl;
        cout << "-> So you need to pay rent of $" << total << "." << endl;
        }
        cout << endl;
        cout << "-> Your original money: $" << p.getMoney() << endl;
        p.sub_money(total);
        cout << "-> Your current money: $" << p.getMoney() << endl;
        
        if (p.getMoney() < 0) {
            total += p.getMoney();
            getowner()->add_money(total);
            cout << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!You gonna bankrupt!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "-> Drop out now. " << endl;
            cout << "-> Trade, mortgage buildings and sell improvements to gather the required money." <<endl;
        } else getowner()->add_money(total);
    }
    }
    } else {
        buy(p);
    }
}



Residence::~Residence() {}


