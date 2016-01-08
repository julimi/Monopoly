//
//  map.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__map__
#define __bb7k__map__

#include <iostream>
#include <map>

class Building;
class Player;
class Map {
    Building *board[40];
public:
    Map();
    ~Map();
    
    void change(int n, Player &p);
    std::string printname(int n);
    Player *getowner(int n);
    std::string getname(int n);
    int getCost(int n);
    bool getmort(int n);
    void setOwner(int n, Player &p);
    void improve(int n);
    void ntimprove(int n);
    bool Ismonopoly(int n);
    void setmortgage(int n);
    void setunmortgage(int n);
    int getPay(int n);
    int getlevel(int n);
    int getLoc(int n);
    std::string getblock(int n);
    // mi gai de
    Building *getbuilding(int n);
    void auction(int n, int mon, char c, int num, int onum, std::map<int,Player *>parr, Building *b, std::map<int,int>oarr);
    
    
    
    void setload(int index, int n);
    
    void getbanben(bool banben);
    bool Isownable(int n);
};

#endif /* defined(__bb7k__map__) */






