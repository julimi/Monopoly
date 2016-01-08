//
//  game.h
//  bb7k
//
//  Created by Grant on 15-7-15.
//  Copyright (c) 2015年 Grant. All rights reserved.
//

#ifndef __bb7k__game__
#define __bb7k__game__
#include "player.h"
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <iostream>
#include <map>
#include <fstream>

class game{
    int num_player;
    Player *players[8];
    
    int now_play;
    int same;
public:
    game();
    ~game();
    
    
    
    
    void loop();
    
    int get_nowplay();
    void start_new(Map &m);
    
    void load_player(std::ifstream &get, Map &m, int t);
    
    void roll(int n);
    
    void getassets();
    std::string getname();
    std::string getname(int n);
    char getchar();
    char getchar(int n);
    int getcup(int n);
    int getmoney(int n);
    int getmoney();
    int getposition(int n);
    int getDC(int n);
    
    void setDC(int n, int dc);
    
    
    void add_player(std::string name, char symbol, Map &m);
    void add_player(std::string name, char symbol, int cups, int money, int position, Map &m);
    void trade_money(std::string p1,std::string p2, int n, int b);
    void trade_building(std::string p1,std::string p2, int a, int b);
    void next();
    bool Iswin();
    void print_numplayer();
    int getLoc();
    int get_numplayer();
    
    void reset_nowplay();
    void print_winer();
    
    void mortgage(int b);
    void unmortgage(int b);
    
    // mi gai de
    int getnump();
    int getnplay();
    std::map<int,Player *> makearray(int n);
    
    Player* getplayer(std::string owner);
    
    void setbuilding(std::string owner, int b);
    
    void setlose();
    
    Player *getnplayer();
    
    void start_new(Map &m, bool b, int t);
    void getassets(bool b);
    void add_player(std::string name, char symbol, Map &m, bool b);
    void start_new(Map &m, int t);
    
    bool check_havebuilding(int b);//new
    bool check_havebuilding(int b, std::string name);
    
    int getsame();
    void add_player(std::string name, char symbol, int cups, int money, int position, Map &m, bool b);
};




#endif /* defined(__bb7k__game__) */
