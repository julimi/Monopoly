//
//  tuition.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__tuition__
#define __bb7k__tuition__
#include "unownable.h"

#include <iostream>
class Tuition: public Unownable {
public:
    Tuition(std::string name, int loc);
    void change(Player &p);
    ~Tuition();
};
#endif /* defined(__bb7k__tuition__) */
