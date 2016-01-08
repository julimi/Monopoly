//
//  building.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "building.h"

using namespace std;

Building::Building(string name, int loc): name(name), loc(loc), banben(false) {}
Player *Building::getowner() { return NULL;}
void Building::setowner(Player &p) {}
string Building::getName() { return name; }
int Building::getCost() { return 0;}
void Building::addCost(int n) {}
void Building::subCost(int n) {}
int Building::getPay() {return 0;}
void Building::setPay(int n) {}
bool Building::getmort() {return false;}
void Building::improve() {
    if (banben) {
        cout << "-> This building doesn't belong to Territory, you cannot improve it." << endl;
    } else {
    cout << "-> This building doesn't belong to Academic, you cannot improve it." << endl;
    }
}
void Building::ntimprove() {
    if (banben) {
        cout << "-> This building doesn't belong to Territory, you cannot improve it." << endl;
    } else {
        cout << "-> This building doesn't belong to Academic, you cannot improve it." << endl;
    }
}
bool Building::Ismonopoly() {return false;}
void Building::setmonopoly(bool de) {}
void Building::setmortgage() {}
void Building::setunmortgage() {}
int Building::getlevel() {return 0;}
void Building::addmem(Building *mem) {}
int Building::getloc() {return loc;}
string Building::getblock() {return "";}
void Building::buy(Player &p) {}
void Building::auction(int i, char c, int num,int onum,map<int,Player *>parr, Building *b, map<int,Building *>oarr) {} // mi gai de
void Building::change(Player &p) {}
void Building::setload(int n) {}
int Building::getblockcap() {
    return 0;
}

bool Building::getbanben() {
    return banben;
}
void Building::setbanben() {
    banben = true;
}
void Building::setblock(string b) {}
void Building::setname(string n) {
    name = n;
}
Building::~Building() {}



