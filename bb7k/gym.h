//
//  gym.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-18.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__gym__
#define __bb7k__gym__
#include "ownable.h"
#include <iostream>
#include <map>

class Gym: public Ownable {
public:
    Gym(std::string name, int loc, int cost, int pay, std::string block, int blockcap);
    ~Gym();
    void change(Player &p);
};
#endif /* defined(__bb7k__gym__) */
