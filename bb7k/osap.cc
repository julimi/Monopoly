//
//  osap.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-18.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "osap.h"
#include <iostream>

using namespace std;

OSAP::OSAP(string name, int loc): Unownable(name,loc) {}

void OSAP::change(Player &p) {
    if (getbanben()) {
        cout << "The Treasure Island give you $200 because you are alive." << endl;
    } else {
    cout << "Due to your situation, there is $200 that UW supports your study." << endl;
    }
    cout << "-> Your original money: $" << p.getMoney() << endl;
    p.add_money(200);
    cout << "-> Your current money: $" << p.getMoney() << endl;
    cout << endl;
}

OSAP::~OSAP() {}


