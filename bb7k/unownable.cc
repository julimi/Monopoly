//
//  unownable.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "unownable.h"

using namespace std;

int Unownable::collection = 0;

Unownable::Unownable(string name, int loc ): Building(name, loc) {}

void Unownable::change(Player &p) {}

Unownable::~Unownable() {}



