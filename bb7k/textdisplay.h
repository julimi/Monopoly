//
//  textdisplay.h
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-21.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#ifndef __bb7k__textdisplay__
#define __bb7k__textdisplay__
#include "view.h"
#include <string>
#include <iostream>

class Textdisplay: public View {
public:
    Textdisplay();
    ~Textdisplay();
    
    virtual void initplayer(char c, int n);
    virtual void changepp(char c, int n, int loc);
    virtual void print(std::ostream &out);
    virtual void getbanben(bool b);
};
#endif /* defined(__bb7k__textdisplay__) */
