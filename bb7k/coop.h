//
//  coop.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__coop__
#define __bb7k__coop__
#include "unownable.h"

#include <iostream>

class Coop: public Unownable {
public:
    Coop(std::string name, int loc);
    void change(Player &p);
    ~Coop();
};

#endif /* defined(__bb7k__coop__) */


