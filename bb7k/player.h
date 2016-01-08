//
//  player.h
//  bb7k
//
//  Created by Grant on 15-7-15.
//  Copyright (c) 2015年 Grant. All rights reserved.
//

#ifndef __bb7k__player__
#define __bb7k__player__

#include <stdio.h>
#include <iostream>
#include <string>
#include "map.h"
#include <map>

class Player{
    std::string name;
    char symbol;
    int money;
    static int total_cup;
    int cup;
    int place;
    int own_num;
    int Rnum;
    int Gnum;
    int own[32];
    bool die;
    bool lose;
    Map *map;
    bool send;
    bool test;
    bool outer;
    
    bool auc;
    
    int DCcount;
    
public:
    void setmap(Map &m);
    bool gettest();
    void set_die();
    void set_lose();
    Player(std::string name, char symbol);
    Player(std::string name, char symbol, int cups, int money, int position);
    ~Player();
    void print_name();
    std::string getname();
    
    
    bool check_havebuilding(int b); // new
    
    
    bool check_lose();
    bool check_die();
    char getchar();
    void add_money(int n);
    void sub_money(int n);
    void add_cup();
    void sub_cup();
    int getMoney();
    int getCups();
    int getAsset();
    void mortgage(int b);
    void unmortgage(int b);
    void add_building(int b);
    void sub_building(int b);
    void move(int n);
    int getTcup();
    Map *getMap();
    int getLoc();
    void setsend(bool a);
    bool getsend();
    void print_ownbuilding();
    
    void settest();
    int getDC();
    void setDC(int n);
    void setplace(int n);
    bool getout();
    void setout(bool b);
    
    bool getauc();
    void setauc(bool a);
    int getownnum();
    int getGnum();
    int getRnum();
    std::map<int, int> makeownarr(std::map<int,int>arr);
};


#endif /* defined(__bb7k__player__) */


