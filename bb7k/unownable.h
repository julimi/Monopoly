//
//  unownable.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__unownable__
#define __bb7k__unownable__

#include "building.h"

class Unownable: public Building {
    static int collection;
public:
    Unownable(std::string name, int loc);
    virtual void change(Player &p);
    virtual ~Unownable() = 0;
};

#endif /* defined(__bb7k__unownable__) */





