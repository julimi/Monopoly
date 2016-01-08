//
//  main.cpp
//  bb7k
//
//  Created by Grant on 15-7-14.
//  Copyright (c) 2015年 Grant. All rights reserved.
//

#include <iostream>
#include "controller.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    int test = 0;
    int load = 0;
    string file;
    std::string ind;
    // Note that loop starts from index 1
    for (int i = 1; i < argc; ++i) {
        ind = argv[i];
        if (ind == "-testing") test = 1;
        else if(ind == "-load") {
            load = 1;
            i++;
            file = argv[i];
        };
    }
    controller c(test, load, file);
    c.play();
}


