//
//  academic.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-18.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "academic.h"

using namespace std;

Academic::Academic(string name,int loc, int cost, int pay, int Icost, string block, int blockcap, int tui[6]): Ownable(name, loc, cost, pay, block, blockcap), Icost(Icost), level(0)
{  for (int i = 0; i < 6; i++) levelp[i] = tui[i];
}

Academic::~Academic() {}

int Academic::getlevel() { return level; }

void Academic::improve() {
    if (!Ismonopoly()) {
        cout << "-> You cannot improve " << getName() << " because you have not had the monopoly of " << getblock() << "." << endl;
    } else if (getmort()) {
        cout << "-> You cannot improve" << getName() << "because it is mortgaged." << endl;
    } else {
        if (level == 5) {
            if (getbanben()) cout << "-> Your territory has already been SUPER! You cannot improve it" << endl;
            else cout << "-> Your building has already been WAP! You cannot improve it" << endl;
        } else {
            if (getowner()->getMoney() < Icost) {
                cout << "-> Aoo! You do not have enough money to improve. ByeBye." << endl;
            } else {
                ++level;
                addCost(Icost);
                setPay(levelp[level]);
                cout << "-> Congradulations! You improve " << getName() << " to level " << level << "!" << endl;
                cout << endl;
                cout << "-> Your original money: $" << getowner()->getMoney() << endl;
                getowner()->sub_money(Icost);
                cout << "-> Your current money: $" << getowner()->getMoney() << endl;
                cout << endl;
            }
        }
    }
}

void Academic::ntimprove() {
    if (level == 0) {
        cout << "-> " << getName() << " is at the lowest level! You cannot sell the improvement!" << endl;
    } else {
        --level;
        subCost(Icost);
        setPay(levelp[level]);
        cout << "-> You have sold your 1 level improvement for " << getName() << "!" << endl;
        cout << endl;
        cout << "-> Your original money: $" << getowner()->getMoney() << endl;
        getowner()->add_money(Icost/2);
        cout << "-> Your current money: $" << getowner()->getMoney() << endl;
        cout << endl;
    }
}


void Academic::change(Player &p) {
    if (getowner() != NULL) {
    if (getowner()->getname() != p.getname()) {
    if (getmort()) {
        cout << "-> You don't need to pay any fees to " << getowner()->getname() << "." << endl;
    } else {
        int total = getPay();
        cout << "-> You should pay pass of $";
        if (Ismonopoly() && level == 0) {
            total *= 2;
            cout << total << "." << endl;
        } else {
            cout << total << "." << endl;
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
    } else {
        buy(p);
    }
}

void Academic::setload(int n) {
        if (n == -1) {
            setmortgage();
        } else {
            while (level < n) {
                ++level;
                addCost(Icost);
            }
            setPay(levelp[n]);
        }
}




