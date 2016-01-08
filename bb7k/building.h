//
//  building.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__building__
#define __bb7k__building__
#include "player.h"
#include <iostream>
#include <string>
#include <map>

class Building {
    std::string name;
    int loc;
    bool banben;
public:
    Building(std::string name, int loc);
    
    virtual Player *getowner();
    virtual void setowner(Player &p);
    virtual std::string getName();
    virtual int getCost();
    virtual void addCost(int n);
    virtual void subCost(int n);
    virtual int getPay();
    virtual void setPay(int n);
    virtual bool getmort();
    virtual void improve();
    virtual void ntimprove();
    virtual bool Ismonopoly();
    virtual void setmonopoly(bool de);
    virtual void setmortgage();
    virtual void setunmortgage();
    virtual int getlevel();
    virtual void addmem(Building *mem);
    virtual int getloc();
    virtual std::string getblock();
    virtual int getblockcap();
    
    virtual void buy(Player &p);
    virtual void auction(int i, char c, int num, int onum,std::map<int,Player *>parr, Building *b, std::map<int,Building *>oarr); // mi gai de
    virtual void change(Player &p);
    virtual void setload(int n);
    
    virtual bool getbanben();
    virtual void setbanben();
    virtual void setblock(std::string b);
    virtual void setname(std::string n);
    
    virtual ~Building();
};
#endif /* defined(__bb7k__building__) */



