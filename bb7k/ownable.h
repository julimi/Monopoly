//
//  ownable.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__ownable__
#define __bb7k__ownable__

#include "building.h"
#include <iostream>
#include <vector>

class Ownable: public Building {
    bool mort, monopoly;
    int cost, pay, blocknum, blockcap;
    Player *owner;
    std::string block;
    Building *blockmem[4];
public:
    Ownable(std::string name, int loc, int cost, int pay, std::string block, int blockcap);
    ~Ownable();
    
    virtual Player *getowner();
    virtual void setowner(Player &p);
    virtual int getCost();
    virtual void addCost(int n);
    virtual void subCost(int n);
    virtual int getPay();
    virtual void setPay(int n);
    virtual bool getmort();
    virtual void improve();
    virtual void ntimprove();
    virtual void addmem(Building *mem);
    virtual std::string getblock();
    virtual bool Ismonopoly();
    virtual void setmonopoly(bool de);
    virtual void setmortgage();
    virtual void setunmortgage();
    virtual int getlevel();
    virtual int getblockcap();
    
    virtual void setblock(std::string b);
    
    // mi gai de
    virtual void buy(Player &p);
    virtual void auction(int q, char c, int num,int onum,std::map<int,Player *>parr, Building *b, std::map<int, Building *>oarr);
    virtual void change(Player &p);
    virtual void setload(int n);
};
#endif /* defined(__bb7k__ownable__) */
