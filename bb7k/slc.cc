//
//  slc.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "slc.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

SLC::SLC(string name, int loc): Unownable(name, loc) {}

void SLC::change(Player &p) {
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
        int rate = rand() % 24 + 1;
        string pos;
        if (rate >= 1 && rate <= 3) {
            if (getbanben()) {
                cout << "-> You see Enel in SkyLand, so you get back 3 steps.";
            } else {
            cout << "-> You see your EX in SLC, so you get back 3 steps.";
            }
            p.move(-3);
            p.setout(true);
        } else if (rate >= 4 && rate <= 7) {
            if (getbanben()) {
                cout << "-> You see 3 Senior General in Skyland, so you get back 2 steps.";
            } else {
            cout << "-> You see a bomb in SLC, so you get back 2 steps.";
            }
            p.move(-2);
            p.setout(true);
        } else if (rate >= 8 && rate <= 11) {
            if (getbanben()) {
                cout << "-> You see Thunder in Skyland, so you get back 1 step to ";
            } else {
            cout << "-> You see ugly Grant in SLC, so you get back 1 step to ";
            }
            p.move(-1);
            p.setout(true);
        } else if (rate >= 12 && rate <= 14) {
            if (getbanben()) {
                cout << "-> You see a gold board, so you get forward 1 step to ";
            } else {
            cout << "-> You see a pretty dog, so you get forward 1 step to ";
            }
            p.move(1);
            pos = p.getMap()->printname(p.getLoc());
            p.setout(true);
        } else if (rate >= 15 && rate <= 18) {
            if (getbanben()) {
                cout << "-> You see a relic, so you get forward 2 steps to ";
            } else {
            cout << "-> You see a pretty kid, so you get forward 2 steps to ";
            }
            p.move(2);
            p.setout(true);
        } else if (rate >= 19 && rate <= 22) {
            cout << "-> You see a beautiful lady, so you get forward 3 steps to ";
            p.move(3);
            p.setout(true);
        } else if (rate == 23) {
            if (getbanben()) {
                cout << "-> Oops! You are catched by Kapu and then take to Jail!" << endl;
            } else {
            cout << "-> Oops! You are catched by DCers and then take to DC Tims Line!" << endl;
            }
            cout << endl;
            p.move(10 - p.getLoc());
            p.setsend(true);
            p.setDC(1);
        } else {
            if (getbanben()) {
                cout << "-> Lucky! You are sent to Treasure Island by unknown airflow!" << endl;
            } else {
            cout << "-> Lucky! You are advanced to Collect OSAP!" << endl;
            }
            cout << endl;
            cout << "-> Now you are in Collect OSAP." << endl;
            p.move(20 - p.getLoc());
            p.setout(true);
        }
    }
    cout << endl;
}

SLC::~SLC() {}




