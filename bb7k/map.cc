//
//  map.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-17.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "map.h"
#include "academic.h"
#include "residence.h"
#include "gym.h"
#include "osap.h"
#include "slc.h"
#include "nh.h"
#include "tuition.h"
#include "gtt.h"
#include "dctl.h"
#include "goose.h"
#include "coop.h"

using namespace std;

Map::Map() {
    
    
    
    int tui[16][6] = {
        {2,10,30,90,160,250}, {4,20,60,180,320,450},  // Arts1
        {6,30,90,270,400,550} /* 1,2 */, {8,40,100,300,450,600},  // Arts2
        {10,50,150,450,625,750} /* 1,2 */, {12,60,180,500,700,900},  // Eng
        {14,70,200,550,750,950} /* 1,2 */, {16,80,220,600,800,1000},  // Health
        {18,90,250,700,875,1050} /* 1,2 */, {20,100,300,750,925,1100},  // Env
        {22,110,330,800,975,1150} /* 1,2 */, {24,120,360,850,1025,1200},  // Sci1
        {26,130,390,900,1100,1275} /* 1,2 */, {28,150,450,1000,1200,1400},  // Sci2
        {35,175,500,1100,1300,1500}, {50,200,600,1400,1700,2000}  // Math
    };
    
    // Ownable:
    // Academic:
    // Env:
    board[21] = new Academic("EV1", 21, 220, 18, 150, "Env", 0, tui[8]);
    board[23] = new Academic("EV2", 23, 220, 18, 150, "Env", 0, tui[8]);
    board[24] = new Academic("EV3", 24, 240, 20, 150, "Env", 0, tui[9]);
    
    board[21]->addmem(board[21]);board[21]->addmem(board[23]);board[21]->addmem(board[24]);
    board[23]->addmem(board[21]);board[23]->addmem(board[23]);board[23]->addmem(board[24]);
    board[24]->addmem(board[21]);board[24]->addmem(board[23]);board[24]->addmem(board[24]);
    
    // Sci1
    board[26] = new Academic("PHYS", 26, 260, 22, 150, "Sci1", 0, tui[10]);
    board[27] = new Academic("B1", 27, 260, 22, 150, "Sci1", 0, tui[10]);
    board[29] = new Academic("B2", 29, 280, 24, 150, "Sci1", 0, tui[11]);
    
    board[26]->addmem(board[26]);board[26]->addmem(board[27]);board[26]->addmem(board[29]);
    board[27]->addmem(board[26]);board[27]->addmem(board[27]);board[27]->addmem(board[29]);
    board[29]->addmem(board[26]);board[29]->addmem(board[27]);board[29]->addmem(board[29]);
    
    // Sci2
    board[31] = new Academic("EIT", 31, 300, 26, 200, "Sci2", 0, tui[12]);
    board[32] = new Academic("ESC", 32, 300, 26, 200, "Sci2", 0, tui[12]);
    board[34] = new Academic("C2", 34, 320, 28, 200, "Sci2", 0, tui[13]);
    
    board[31]->addmem(board[31]);board[31]->addmem(board[32]);board[31]->addmem(board[34]);
    board[32]->addmem(board[31]);board[32]->addmem(board[32]);board[32]->addmem(board[34]);
    board[34]->addmem(board[31]);board[34]->addmem(board[32]);board[34]->addmem(board[34]);
    
    // Math
    board[37] = new Academic("MC", 37, 350, 35, 200, "Math", 0, tui[14]);
    board[39] = new Academic("DC", 39, 400, 50, 200, "Math", 0, tui[15]);
    
    board[37]->addmem(board[37]);board[37]->addmem(board[39]);
    board[39]->addmem(board[37]);board[39]->addmem(board[39]);
    
    // Arts1
    board[1] = new Academic("AL", 1, 40, 2, 50, "Arts1", 0, tui[0]);
    board[3] = new Academic("ML", 3, 60, 4, 50, "Arts1", 0, tui[1]);
    
    board[1]->addmem(board[1]);board[1]->addmem(board[3]);
    board[3]->addmem(board[1]);board[3]->addmem(board[3]);
    
    // Arts2
    board[6] = new Academic("ECH", 6, 100, 6, 50, "Arts2", 0, tui[2]);
    board[8] = new Academic("PAS", 8, 100, 6, 50, "Arts2", 0, tui[2]);
    board[9] = new Academic("HH", 9, 120, 8, 50, "Arts2", 0, tui[3]);
    
    board[6]->addmem(board[6]);board[6]->addmem(board[8]);board[6]->addmem(board[9]);
    board[8]->addmem(board[6]);board[8]->addmem(board[8]);board[8]->addmem(board[9]);
    board[9]->addmem(board[6]);board[9]->addmem(board[8]);board[9]->addmem(board[9]);
    
    // Eng
    board[11] = new Academic("RCH", 11, 140, 10, 100, "Eng", 0, tui[4]);
    board[13] = new Academic("DWE", 13, 140, 10, 100, "Eng", 0, tui[4]);
    board[14] = new Academic("CPH", 14, 160, 12, 100, "Eng", 0, tui[5]);
    
    board[11]->addmem(board[11]);board[11]->addmem(board[13]);board[11]->addmem(board[14]);
    board[13]->addmem(board[11]);board[13]->addmem(board[13]);board[13]->addmem(board[14]);
    board[14]->addmem(board[11]);board[14]->addmem(board[13]);board[14]->addmem(board[14]);
    
    // Health
    board[16] = new Academic("LHI", 16, 180, 14, 100, "Health", 0, tui[6]);
    board[18] = new Academic("BMH", 18, 180, 14, 100, "Health", 0, tui[6]);
    board[19] = new Academic("OPT", 19, 200, 16, 100, "Health", 0, tui[7]);
    
    board[16]->addmem(board[16]);board[16]->addmem(board[18]);board[16]->addmem(board[19]);
    board[18]->addmem(board[16]);board[18]->addmem(board[18]);board[18]->addmem(board[19]);
    board[19]->addmem(board[16]);board[19]->addmem(board[18]);board[19]->addmem(board[19]);
    
    // Residence:
    board[25] = new Residence("V1", 25, 200, 25, "Residence", 0);
    board[35] = new Residence("REV", 35, 200, 25, "Residence", 0);
    board[5] = new Residence("MKV", 5, 200, 25, "Residence", 0);
    board[15] = new Residence("UWP", 15, 200, 25, "Residence", 0);
    
    for (int i = 5; i < 36; i += 10) {
        for (int j = 5; j < 36; j += 10) board[i]->addmem(board[j]);
    }
    
    // Gym:
    board[28] = new Gym("CIF", 28, 150, 0, "Gym", 0);
    board[12] = new Gym("PAC", 12, 150, 0, "Gym", 0);
    
    board[28]->addmem(board[28]);board[28]->addmem(board[12]);
    board[12]->addmem(board[28]);board[12]->addmem(board[12]);
    
    // Unownable:
    // Goose Nesting:
    board[20] = new Goose("Goose Nesting", 20);
    
    // Needles Hall:
    board[22] = new NH("Needles Hall", 22);
    board[36] = new NH("Needles Hall", 36);
    board[7] = new NH("Needles Hall", 7);
    
    // GO TO TIMS:
    board[30] = new GtoT("GO TO TIMS", 30);
    
    // SLC:
    board[33] = new SLC("SLC", 33);
    board[2] = new SLC("SLC", 2);
    board[17] = new SLC("SLC", 17);
    
    // COOP FEE:
    board[38] = new Coop("COOP FEE", 38);
    
    // COLLECT OSAP:
    board[0] = new OSAP("COLLECT OSAP", 0);
    
    // TUITION:
    board[4] = new Tuition("TUITION", 4);
    
    // DC Tims Line:
    board[10] = new DCTim("DC Tims Line", 10);
    
}

Map::~Map() {
    for (int i = 0; i < 40; i++) delete board[i];
}

void Map::change(int n,Player &p) {
    board[n]->change(p);
}

string Map::printname(int n) {
    return board[n]->getName();
}

Player *Map::getowner(int n) {
    return board[n]->getowner();
}

string Map::getname(int n) {
    return board[n]->getName();
}

int Map::getCost(int n) {
    return board[n]->getCost();
}

bool Map::getmort(int n) {
    return board[n]->getmort();
}

void Map::setOwner(int n, Player &p) {
    board[n]->setowner(p);
}

void Map::improve(int n) {
    board[n]->improve();
}

void Map::ntimprove(int n) {
    board[n]->ntimprove();
}

bool Map::Ismonopoly(int n) {
    return board[n]->Ismonopoly();
}

void Map::setmortgage(int n) {
    board[n]->setmortgage();
}

void Map::setunmortgage(int n) {
    board[n]->setunmortgage();
}

int Map::getPay(int n) {
    return board[n]->getPay();
}

int Map::getlevel(int n) {
    return board[n]->getlevel();
}

int Map::getLoc(int n) {
    return board[n]->getloc();
}

string Map::getblock(int n) {
    return board[n]->getblock();
}
// mi gai de

Building *Map::getbuilding(int n) {
    return board[n];
}

void Map::auction(int n, int mon, char c, int num,int onum, map<int,Player *> parr, Building *b, map<int,int>oarr) {
    
    map<int, Building *>barr;
    for (int i = 0; i < onum; i++) {
        barr[i] = board[oarr[i]];
    }
    
    board[n]->auction(mon, c, num, onum, parr, b, barr);
}


// xin gai de
void Map::setload(int index, int n) {
    board[index]->setload(n);
}
// end
void Map::getbanben(bool banben) {
    if (banben) {
        for (int i = 0; i < 40; ++i) {
            board[i]->setbanben();
        }
        board[0]->setname("TREASURE ISLAND");
        board[20]->setname("SEAKING NESTING");
        
        // Needles Hall:
        board[22]->setname("WORLD COURT");
        board[36]->setname("WORLD COURT");
        board[7]->setname("WORLD COURT");
        
        // GO TO TIMS:
        board[30]->setname("GO TO JAIL");
        
        // SLC:
        board[33]->setname("SKYLAND");
        board[2]->setname("SKYLAND");
        board[17]->setname("SKYLAND");
        
        // COOP FEE:
        board[38]->setname("WATER SEVEN");
        
        // TUITION:
        board[4]->setname("REDLAND");
        
        // DC Tims Line:
        board[10]->setname("UNDERSEA JAIL");
        
        // Ownable:
        // Env:
        board[21]->setname("MIGECUN");board[21]->setblock("BEIHAI");
        board[23]->setname("MIGEZHEN");board[23]->setblock("BEIHAI");
        board[24]->setname("MIGEYOSH");board[24]->setblock("BEIHAI");
        
        // Sci1
        board[26]->setname("WENCUN");board[26]->setblock("NANHAI");
        board[27]->setname("WENZHEN");board[27]->setblock("NANHAI");
        board[29]->setname("WENYOSH");board[29]->setblock("NANHAI");
        
        // Sci2
        board[31]->setname("SHUSHAN");board[31]->setblock("FUDI");
        board[32]->setname("KUNWU");board[32]->setblock("FUDI");
        board[34]->setname("FANGCUN");board[34]->setblock("FUDI");
        
        
        // Math
        board[37]->setname("SHENJIE");board[37]->setblock("SHENMO");
        board[39]->setname("MOJIE");board[39]->setblock("SHENMO");
        
        // Arts1
        board[1]->setname("YUHANG");board[1]->setblock("SUHANG");
        board[3]->setname("SUZHOU");board[3]->setblock("SUHANG");
        
        // Arts2
        board[6]->setname("JINGDU");board[6]->setblock("DUCHENG");
        board[8]->setname("FENGDU");board[8]->setblock("DUCHENG");
        board[9]->setname("DUDU");board[9]->setblock("DUCHENG");
        // Eng
        board[11]->setname("SHAOLIN");board[11]->setblock("FANJIAN1");
        board[13]->setname("WUDANG");board[13]->setblock("FANJIAN1");
        board[14]->setname("EMEI");board[14]->setblock("FANJIAN1");
        
        // Health
        board[16]->setname("KONGTONG");board[16]->setblock("FANJIAN2");
        board[18]->setname("HUASHAN");board[18]->setblock("FANJIAN2");
        board[19]->setname("KUNLUN");board[19]->setblock("FANJIAN2");
        
        // Residence:
        board[25]->setname("QINGLONG");board[25]->setblock("SHOU");
        board[35]->setname("ZHUQUE");board[35]->setblock("SHOU");
        board[5]->setname("BAIHU");board[5]->setblock("SHOU");
        board[15]->setname("XUANWU");board[15]->setblock("SHOU");
                
        // Gym:
        board[28]->setname("MING");board[28]->setblock("MOJIAO");
        board[12]->setname("RIYUE");board[12]->setblock("MOJIAO");
    }
}

bool Map::Isownable(int n) {
    if (board[n]->getblock() == "") return false;
    else return true;
}


