//
//  view.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-21.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__view__
#define __bb7k__view__

#include <iostream>
#include <string>

class View {
protected:
    std::string board[56][23];
    int ppos[7];
    int pplace[40][2];  // store i,j player can put
public:
    View();
    ~View();
    
    virtual void initplayer(char c, int n) = 0;
    virtual void changepp(char c, int n, int loc) = 0;
    virtual void print(std::ostream &out) = 0;
    virtual void getbanben(bool b) = 0;
};

#endif /* defined(__bb7k__view__) */
