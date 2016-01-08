//
//  dctl.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-20.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__dctl__
#define __bb7k__dctl__
#include "unownable.h"
#include <iostream>

class DCTim: public Unownable {
    int attempt;
public:
    DCTim(std::string name, int loc);
    ~DCTim();
    void change(Player &p);
};

#endif /* defined(__bb7k__dctl__) */
