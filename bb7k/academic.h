//
//  academic.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-18.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__academic__
#define __bb7k__academic__
#include "ownable.h"
#include <iostream>

class Academic: public Ownable {
    unsigned int level;
    int Icost;
    int levelp[6];
public:
    Academic(std::string name, int loc, int cost, int pay, int Icost, std::string block, int blockcap, int tui[6]);
    ~Academic();
    int getlevel();
    void improve();
    void ntimprove();
    void change(Player &p);
    void setload(int n);
};

#endif /* defined(__bb7k__academic__) */



