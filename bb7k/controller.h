//
//  controller.h
//  bb7k
//
//  Created by Grant on 15-7-14.
//  Copyright (c) 2015年 Grant. All rights reserved.
//

#ifndef __bb7k__controller__
#define __bb7k__controller__

#include <stdio.h>
#include <iostream>
#include "game.h"
#include "map.h"
#include <sstream>
#include "view.h"
#include <fstream>


class controller {
    
    
    Map *m;
    game *p;
    View *td;
    // View *gd;
    
    
    int test;
    int load;
    std::string file;
    
    
public:
    
    
    controller(int test, int load, std::string file);
    ~controller();
    void play();
   // void load(std::string get);
    
    
};



#endif /* defined(__bb7k__controller__) */


