//
//  gtt.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-20.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "gtt.h"
#include <iostream>

using namespace std;

GtoT::GtoT(string name, int loc): Unownable(name, loc) {}

GtoT::~GtoT() {}

void GtoT::change(Player &p) {
    if (getbanben()) {
        cout << "!!!!!!! Unfortuately! You meet Red Dog Senior General! !!!!!!!" << endl;
        cout << "-> You lose and are sent to the Jail! See you~" << endl;
        cout << endl;
        cout << "-> Now you are in the Undersea Jail." << endl;
    } else {
    cout << "-> You must be sent to DC Tims Line! See you~" << endl;
    cout << endl;
    cout << "-> Now you are in DC Tims Line." << endl;
    }
    cout << endl;
    p.move(20);
    p.setsend(true);
    p.setDC(1);
}

