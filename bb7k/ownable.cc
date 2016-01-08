//
//  ownable.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "ownable.h"

using namespace std;

Ownable::Ownable(string name, int loc, int cost, int pay, string block, int blockcap): Building(name,loc), owner(NULL), mort(false), monopoly(false), cost(cost), pay(pay), block(block), blockcap(blockcap), blocknum(0) {}

Player *Ownable::getowner() { return owner; }

void Ownable::setowner(Player &p) {
    owner = &p;
    string oname = p.getname();
    int iindex = 0;
    while (iindex <= blockcap) {
        if (iindex == blockcap) {
            for (int i = 0; i < blockcap; i++) blockmem[i]->setmonopoly(true);
            break;
        }
        if (blockmem[iindex]->getowner() == NULL) break;
        if (blockmem[iindex]->getowner()->getname() != oname) break;
        ++iindex;
    }
}


int Ownable::getCost() { return cost; }

void Ownable::addCost(int n) { cost += n; }

void Ownable::subCost(int n) { cost -= n; }

int Ownable::getPay() { return pay; }

void Ownable::setPay(int n) { pay = n; }

bool Ownable::getmort() { return mort; }

void Ownable::addmem(Building *mem) {
    blockmem[blockcap++] = mem;
}

string Ownable::getblock() { return block; }

bool Ownable::Ismonopoly() { return monopoly; }

void Ownable::setmonopoly(bool de) { monopoly = de; }

void Ownable::setmortgage() {
    mort = true;
}

void Ownable::setunmortgage() {
    mort = false;
}


// mi gai de
void Ownable::buy(Player &p) {
        cout << "-> " << getName() << " is a ownerless property. ";
        cout << "It needs " << getCost() << ". ";
        cout <<"Do you wanna buy it? (yes / no)" << endl;
        string choice;
        cin >> choice;
        if (choice == "yes") {
            if (getCost() > p.getMoney()) {
                cout << "-> You do not have enough money to buy it. It will be done auction automatically." << endl;
                cout << endl;
                p.setauc(true);
            } else {
                cout << "-> Congradulations! You have got " << getName() << "!" << endl;
                cout << "-> Your original money: $" << p.getMoney() << endl;
                p.sub_money(getCost());
                p.add_building(p.getLoc());
                cout << "-> Your current money: $" << p.getMoney() << endl;
            }
        } else {
            cout << "-> You don't want to buy the property, so it will do auction." << endl;
            cout << endl;
            p.setauc(true);
        }
}
void Ownable::change(Player &p) {}
void Ownable::improve() {}
void Ownable::ntimprove() {}
int Ownable::getlevel() {return 0;}
int Ownable::getblockcap() {return blockcap;}

void Ownable::auction(int q, char c, int num,int onum,map<int,Player *>parr, Building *b, map<int,Building *>oarr) {
    cout << "--------------------Auction part--------------------" << endl;
    cout << endl;
    int price = 1;
    string choice;
    int give;
    int exist[num];
    int thistime = num;
    for (int i = 0; i < num; i++) {
        exist[i] = 1;
    }
    
    if (q < 0) {
        
        for (int i = 0; i < num; i++) {
            if (parr[i]->getchar() == c) {
                exist[i] = 0;
                cout << "-> " << parr[i]->getname() << " has declared bankrupt. We gonna auction his/her properties!" << endl;
                cout << endl;
            }
        }
        for (int i = 0; i < onum; i++) {
            int thistime = num - 1;
            for (int i = 0; i < num; i++) {
                if (parr[i]->getchar() != c) exist[i] = 1;
            }
            
            cout << "-> Now we gonna do auction for " << oarr[i]->getName() << "." << endl;
            
            for (int j = 0; true; j++) {
                
                if (j == num) {
                    j = 0;
                    continue;
                }
                
                cout << thistime << endl;
                if (thistime <= 1 && exist[j] == 1) {
                    cout << "-> Congradulations! " << parr[j]->getname() << " get the " << oarr[i]->getName() << "!" << endl;
                    cout << endl;
                    
                    
                    parr[j]->add_building(oarr[i]->getloc());
                    cout << "-> Your original money: $" << parr[j]->getMoney() << endl;
                    parr[j]->sub_money(price);
                    parr[j]->setauc(false);
                    cout << "-> Your current money: $" << parr[j]->getMoney() << endl;
                    cout << endl;
                    price = 0;
                    break;
                }
                
                if (exist[j] == 1) {
                    cout << "-> " << parr[j]->getname() << "'s turn." << endl;
                    if (parr[j]->getMoney() < price) {
                        cout << "-> " << parr[j]->getname() << "'s current cash is not enough." << endl;
                        cout << "-> Withdraw automatically!" << endl;
                        exist[j] = 0;
                        parr[j]->setauc(false);
                        thistime--;
                        continue;
                    }
                    cout << "-> Do you want to raise the bid? (yes/no)" << endl;
                    
                    cin >> choice;
                    if (choice != "yes") {
                        exist[j] = 0;
                        parr[j]->setauc(false);
                        thistime--;
                        cout << "-> " << parr[j]->getname() << " withdraw the auction." << endl;
                        cout << endl;
                        continue;
                    }
                    else {
                        cout << "-> What's amount do you wanna raise?" << endl;
                        cout << "-> Please enter the money." << endl;
                        
                        while (true) {
                            cin >> give;
                            if (give <= parr[j]->getMoney()) {
                                cout << "-> You bid $" << give << endl;
                                cout << endl;
                                break;
                            } else {
                                if (give > parr[j]->getMoney()) {
                                    cout << "-> You enter money which is more than your current cash! Re-enter please." << endl;
                                } else {
                                    cout << "-> You enter money which is not more than the current bid! Re-enter please." << endl;
                                }
                            }
                        }
                        price = give;
                    }
                }
            }
        }
    }
    else {
        
            cout << "-> Now we gonna do auction for " << b->getName() << "." << endl;
            
            int j = 0;
            while(true) {
                if (j > num) {
                    j = 0;
                    continue;
                }
                
                if (thistime == 1 && exist[j] == 1) {
                    cout << "-> Congradulations! " << parr[j]->getname() << " get the " << b->getName() << "!" << endl;
                    cout << endl;
                    parr[j]->add_building(b->getloc());
                    cout << "-> Your original money: $" << parr[j]->getMoney() << endl;
                    parr[j]->sub_money(price);
                    parr[j]->setauc(false);
                    cout << "-> Your current money: $" << parr[j]->getMoney() << endl;
                    cout << endl;
                    price = 0;
                    break;
                }
                
                if (exist[j] == 1) {
                    cout << "-> " << parr[j]->getname() << "'s turn." << endl;
                    if (parr[j]->getMoney() < price) {
                        cout << "-> " << parr[j]->getname() << "'s current cash is not enough." << endl;
                        cout << "-> Withdraw automatically!" << endl;
                        exist[j] = 0;
                        parr[j]->setauc(false);
                        thistime--;
                        continue;
                    }
                    cout << "-> Dou you want to raise the bid? (yes/no)" << endl;
                    
                    cin >> choice;
                    if (choice != "yes") {
                        exist[j] = 0;
                        thistime--;
                        parr[j]->setauc(false);
                        cout << "-> " << parr[j]->getname() << " withdraw the auction." << endl;
                        cout << endl;
                    }
                    else {
                        cout << "-> What's amount do you wanna raise?" << endl;
                        cout << "-> Please enter the money." << endl;
                        
                        while (true) {
                            cin >> give;
                            if (give <= parr[j]->getMoney() && give > price) {
                                cout << "-> You bid $" << give << endl;
                                cout << endl;
                                break;
                            } else {
                                if (give > parr[j]->getMoney()) {
                                cout << "-> You enter money which is more than your current cash! Re-enter please." << endl;
                                } else {
                                    cout << "-> You enter money which is not more than the current bid! Re-enter please." << endl;
                                }
                            }
                        }
                        price = give;
                        
                    }
                }
                j++;
            }
        
    }
}

void Ownable::setload(int n) {
        if (n == -1) {
            setmortgage();
        }
}

void Ownable::setblock(string b) {
    block = b;
}

Ownable::~Ownable() {}


