//
//  osap.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-18.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__osap__
#define __bb7k__osap__
#include "unownable.h"

#include <iostream>

class OSAP: public Unownable {
public:
    OSAP(std::string name, int loc);
    void change(Player &p);
    ~OSAP();
};

#endif /* defined(__bb7k__osap__) */
