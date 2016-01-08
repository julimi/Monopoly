//
//  dctl.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-20.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "dctl.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

DCTim::DCTim(string name, int loc): Unownable(name, loc), attempt(0) {}

DCTim::~DCTim() {}

void DCTim::change(Player &p) {
    if (p.getsend() == true) {
        int count = p.getDC();
        
        cout << "-> This is your ";
        if (count == 1) cout << "1st";
        else if (count == 2) cout << "2nd";
        else cout << "3rd";
        if (getbanben()) {
            cout << " turn in the Undersea Jail!" << endl;
        } else {
        cout << " turn in the DC Tims Line." << endl;
        }
        cout << "-> You can choose 3 ways to get out of here:" << endl;
        cout << "-> enter 1: Roll doubles" << endl;
        cout << "-> enter 2: Pay $50" << endl;
        if (getbanben()) {
            cout << "-> enter 3: Use Government Statement" << endl;
        } else {
        cout << "-> enter 3: Use Roll Up the Rim Cup" << endl;
        }
        
        int choice;
        while (true) {
            
            cin >> choice;
            
            int dice1,dice2;
            string command;
            
            
            if (choice == 1) {
                
                cout << "-> You choose to try rolling doubles. GL!" << endl;
                cout << "-> Please enter 'roll' to roll the dices." << endl;
                cin >> command;
                
                if (p.gettest()) {
                    cout << ">>>>>>>>>>>>>>>>>>>>Test Mode<<<<<<<<<<<<<<<<<<<<<" << endl;
                    cout << endl;
                    cout << "-> enter the number of dices" << endl;
                    cout << "-> The first dice: ";
                    cin >> dice1;
                    cout << endl;
                    cout << "-> The second dice: ";
                    cin >> dice2;
                    cout << endl;
                } else {
                    srand(time(NULL));
                    dice1 = (rand() % 6) + 1;
                    dice2 = (rand() % 6) + 1;
                }
                
                if (dice1 == dice2) {
                    if (getbanben()) {
                        cout << "-> Congradulations! You can leave the Jail now!" << endl;
                    } else {
                    cout << "-> Congradulations! You can leave DC Tims Line now!" << endl;
                    }
                    p.setsend(false);
                    cout << endl;
                    p.move(dice1 * 2);
                    p.setout(true);
                    p.setDC(0);
                    break;
                } else {
                    if (count != 3) {
                        if (getbanben()) {
                            cout << "-> GG~You have to wait here more time because you are catched back by Magellan!" << endl;
                        } else {
                        cout << "-> GG~You have to wait here more time for your coffee." << endl;
                        }
                        attempt = dice1 + dice2;
                        count += 1;
                        p.setDC(count);
                        break;
                    } else {
                        cout << "-> This is your final turn staying here, you have to choose other ways to get out!" << endl;
                        if (p.getCups() == 0) {
                            if (getbanben()) {
                                cout << "-> You do not have any statements! You must pay $50 for out!" << endl;
                                cout << "-> You leave the Jail ";
                            } else {
                            cout << "-> You do not have any cups! You must pay $50 for out!" << endl;
                            cout << "-> You leave DC Tim Line ";
                            }
                            cout << "by the last try number " << attempt << endl;
                            p.setsend(false);
                            p.setDC(0);
                            cout << endl;
                            cout << "-> Your original money: $" << p.getMoney() << endl;
                            p.sub_money(50);
                            cout << "-> Your current money: $" << p.getMoney() << endl;
                            if (p.getMoney() < 0) {
                                cout << endl;
                                cout << "!!!!!!!!!!!!!!!!!!!!!!You gonna bankrupt!!!!!!!!!!!!!!!!!!!!!!" << endl;
                                cout << "-> Drop out now. " << endl;
                                cout << "-> Trade, mortgage buildings and sell improvements to gather the required money." <<endl;
                            } else {
                                p.move(attempt);
                                p.setout(true);
                            }
                            break;
                        } else if (p.getMoney() < 0) {
                            if (getbanben()) {
                                cout << "-> Your current money is not enough for paying $50 out permit!" << endl;
                                cout << "-> So you must use your statement to go out!" << endl;
                                cout << "-> You leave the Jail ";
                            } else {
                            cout << "-> Your current money is not enough for paying $50 coffee!" << endl;
                            cout << "-> So you must use your cup to go out!" << endl;
                            cout << "-> You leave DC Tim Line ";
                            }
                            cout << "by the last try number " << attempt << endl;
                            p.setsend(false);
                            p.setDC(0);
                            cout << endl;
                            cout << "-> Your original cups: " << p.getCups() << endl;
                            p.sub_cup();
                            cout << "-> Your current cups: " << p.getCups() << endl;
                            p.move(attempt);
                            p.setout(true);
                            break;
                        } else {
                            cout << "-> You can choose either: " << endl;
                            cout << "-> enter 2: Pay $50." << endl;
                            if (getbanben()) {
                                cout << "-> enter 3: Use Government Statement" << endl;
                            } else {
                            cout << "-> enter 3: Use the Roll Up the Rim Cup." << endl;
                            }
                        }
                    }
                }
            } else if (choice == 2) {
                if (p.getMoney() < 50) {
                    if (p.getCups() != 0) {
                        cout << "-> Your current money is not enough, choose other two ways." << endl;
                        cout << "-> enter 1: Roll Doubles." << endl;
                        if (getbanben()) {
                            cout << "-> enter 3: Use Government Statement" << endl;
                        } else {
                            cout << "-> enter 3: Use the Roll Up the Rim Cup." << endl;
                        }
                    } else {
                        if (getbanben()) {
                            cout << "-> Your current money is not enough and Your # of statements is 0." << endl;
                        } else {
                        cout << "-> Your current money is not enough and Your # of cups is 0." << endl;
                        }
                        cout << "-> You just can choose 1st method." << endl;
                        cout << "-> enter 1: Roll Doubles." << endl;
                    }
                } else {
                    if (getbanben()) {
                        cout << "-> You pay for a $50 out permit, see you soon~ " << endl;
                        cout << "-> You can leave the Jail ";
                    } else {
                    cout << "-> You pay for a $50 coffee, enjoy it." << endl;
                    cout << "-> You can leave DC Tim Line ";
                    }
                    p.setsend(false);
                    p.setDC(0);
                    if (count == 3) {
                        cout << "by the last try number " << attempt << endl;
                    }
                    else {
                        cout << endl;
                        cout << "-> Please enter 'roll' to roll the dices." << endl;
                        cin >> command;
                        cout << p.gettest() << endl;
                        if (p.gettest()) {
                            cout << endl;
                            cout << ">>>>>>>>>>>>>>>>>>>>Test Mode<<<<<<<<<<<<<<<<<<<<<" << endl;
                            cout << endl;
                            cout << "-> enter the number of dices" << endl;
                            cout << "-> The first dice: ";
                            cin >> dice1;
                            cout << endl;
                            cout << "-> The second dice: ";
                            cin >> dice2;
                            cout << endl;
                        } else {
                            srand(time(NULL));
                            dice1 = (rand() % 6) + 1;
                            dice2 = (rand() % 6) + 1;
                        }
                        attempt = dice1 + dice2;
                        cout << "by the number of " << attempt << endl;
                    }
                    cout << endl;
                    cout << "-> Your original money: $" << p.getMoney() << endl;
                    p.sub_money(50);
                    cout << "-> Your current money: $" << p.getMoney() << endl;
                    p.move(attempt);
                    p.setout(true);
                    break;
                }
            } else if (choice == 3){
                if (p.getCups() == 0) {
                    if (p.getMoney() >= 50) {
                        if (getbanben()) {
                            cout << "-> You do not have any statements, choose other two ways." << endl;
                        } else {
                        cout << "-> You do not have any cups, choose other two ways." << endl;
                        }
                        cout << "-> enter 1: Roll Doubles." << endl;
                        cout << "-> enter 2: Pay $50." << endl;
                    } else {
                        
                        if (getbanben()) {
                            cout << "-> Your current money is not enough and Your # of statements is 0." << endl;
                        } else {
                            cout << "-> Your current money is not enough and Your # of cups is 0." << endl;
                        }
                        cout << "-> You just can choose 1st method." << endl;
                        cout << "-> enter 1: Roll Doubles." << endl;
                    }
                } else {
                    if (getbanben()) {
                        cout << "-> You use your government statement for free to out." << endl;
                        cout << "-> You can leave the Jail ";
                    } else {
                    cout << "-> You use your magic card for free to out." << endl;
                    cout << "-> You can leave DC Tim Line ";
                    }
                    p.setsend(false);
                    p.setDC(0);
                    if (count == 3) {
                        cout << "by the last try number " << attempt << endl;
                    }
                    else {
                        cout << endl;
                        cout << "-> Please enter 'roll' to roll the dices." << endl;
                        cin >> command;
                        if (p.gettest()) {
                            cout << endl;
                            cout << ">>>>>>>>>>>>>>>>>>>>Test Mode<<<<<<<<<<<<<<<<<<<<<" << endl;
                            cout << endl;
                            cout << "-> enter the number of dices" << endl;
                            cout << "-> The first dice: ";
                            cin >> dice1;
                            cout << endl;
                            cout << "-> The second dice: ";
                            cin >> dice2;
                            cout << endl;
                        } else {
                            srand(time(NULL));
                            dice1 = (rand() % 6) + 1;
                            dice2 = (rand() % 6) + 1;
                        }
                        attempt = dice1 + dice2;
                        cout << "by the number of " << attempt << endl;
                    }
                    cout << endl;
                    cout << "-> Your original cups: " << p.getCups() << endl;
                    p.sub_cup();
                    cout << "-> Your current cups: " << p.getCups() << endl;
                    p.move(attempt);
                    p.setout(true);
                    
                    break;
                }
            } else {
                cout << "-> No this choice, choose again." << endl;
                cout << "-> enter 1: Roll doubles" << endl;
                cout << "-> enter 2: Pay $50" << endl;
                if (getbanben()) {
                    cout << "-> enter 3: Use Government Statement" << endl;
                } else {
                    cout << "-> enter 3: Use Roll Up the Rim Cup" << endl;
                }
            }
        }
    } else {
        if (getbanben()) {
            cout << "-> Welcome to visit the Undersea Jail! Duomi will take you to look around." << endl;
            if (p.getchar() == 'C') {
                cout << "-> You are CP9. $100 for you!" << endl;
                cout << "-> Your original money: $" << p.getMoney() << endl;
                p.add_money(100);
                cout << "-> Your current money: $" << p.getMoney() << endl;
            } else if (p.getchar() == 'N') {
                cout << "-> Navy come for get prisoner. $10 to Magellon." << endl;
                cout << "-> Your original money: $" << p.getMoney() << endl;
                p.sub_money(10);
                cout << "-> Your current money: $" << p.getMoney() << endl;
            } else if (p.getchar() == 'G') {
                cout << "-> You are SB Gragon Man! $200 for you!" << endl;
                cout << "-> Your original money: $" << p.getMoney() << endl;
                p.add_money(200);
                cout << "-> Your current money: $" << p.getMoney() << endl;
            }
            cout << endl;
            
        } else {
        cout << "-> Welcome to get in DC Tims Line for a break! There is a free coffee for you!" << endl;
        }
        cout << endl;
    }
}

