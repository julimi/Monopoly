//
//  slc.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__slc__
#define __bb7k__slc__
#include "unownable.h"
#include <iostream>

class SLC: public Unownable {
public:
    SLC(std::string name, int loc);
    void change(Player &p);
    ~SLC();
    
};

#endif /* defined(__bb7k__slc__) */
