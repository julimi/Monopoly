//
//  nh.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__nh__
#define __bb7k__nh__
#include "unownable.h"
#include <iostream>

class NH: public Unownable {
public:
    NH(std::string name, int loc);
    void change(Player &p);
    ~NH();
};
#endif /* defined(__bb7k__nh__) */
