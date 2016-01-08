//
//  gtt.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-20.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__gtt__
#define __bb7k__gtt__
#include "unownable.h"
#include <iostream>

class GtoT: public Unownable {
public:
    GtoT(std::string name, int loc);
    ~GtoT();
    void change(Player &p);
};

#endif /* defined(__bb7k__gtt__) */
