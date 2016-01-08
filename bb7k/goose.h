//
//  goose.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__goose__
#define __bb7k__goose__
#include "unownable.h"

#include <iostream>

class Goose: public Unownable {
    int left;
public:
    Goose(std::string name, int loc);
    void change(Player &p);
    ~Goose();
};

#endif /* defined(__bb7k__goose__) */
