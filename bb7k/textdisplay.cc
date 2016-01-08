//
//  textdisplay.cpp
//  bb7k
//
//  Created by 江 伟锋 on 2015-07-21.
//  Copyright (c) 2015 Terminal instance. All rights reserved.
//

#include "textdisplay.h"
#include <sstream>

using namespace std;

Textdisplay::Textdisplay(): View() {
    cout << "in td cotr" << endl;
    for (int i = 0; i < 56; i++) {
        for (int j = 0; j < 23; j++) {
            board[i][j] = " ";
        }
    }
    for (int i = 0; i < 56; i++) {
        for (int j = 1; j <= 21; j += 2) {
            board[i][j] = "        ";
        }
    }
    for (int j = 0; j < 23; j += 2) {
        board[0][j] = "_";
        if (j >= 4 && j <= 18) board[50][j] = "_";
    }
    
    for (int i = 1;i < 6; i++) {
        for (int j = 0; j < 23; j += 2) {
            board[i][j] = "|";
        }
    }
    for (int i = 6; i < 51; i++) {
        board[i][0] = "|";
        board[i][2] = "|";
        board[i][20] = "|";
        board[i][22] = "|";
    }
    
    for (int i = 51;i < 56; i++) {
        for (int j = 0; j < 23; j += 2) {
            board[i][j] = "|";
        }
    }
    
    for (int j = 1; j < 23; j += 2) {
        board[0][j] = "________";
        board[5][j] = "________";
        board[50][j] = "________";
        board[55][j] = "________";
    }
    
    board[2][3] = "--------";board[2][7] = "--------";board[2][9] = "--------";
    board[2][13] = "--------";board[2][15] = "--------";board[2][19] = "--------";
    
    board[52][3] = "--------";board[52][5] = "--------";board[52][9] = "--------";
    board[52][15] = "--------";board[52][19] = "--------";
    
    for (int i = 10;i < 50; i += 5) {
        board[i][1] = "________";
        board[i][21] = "________";
    }
    
    board[7][1] = "--------";board[12][1] = "--------";board[22][1] = "--------";
    board[32][1] = "--------";board[37][1] = "--------";board[47][1] = "--------";
    
    board[7][21] = "--------";board[12][21] = "--------";board[22][21] = "--------";
    board[37][21] = "--------";board[47][21] = "--------";
    
    // bb7000
    for (int j = 6; j <= 16; j += 2) {
        board[24][j] = "_";
        board[31][j] = "_";
    }
    for (int i = 25; i < 32; i++) {
        board[i][6] = "|";
        board[i][16] = "|";
    }
    for (int j = 7; j <= 15; j += 2) {
        board[24][j] = "________";
        board[31][j] = "________";
    }
    
    board[26][7] = "  ###   ";board[26][9] = "###    #";board[26][11] = "###  ###";
    board[26][13] = "   ###  ";board[26][15] = " ###    ";board[26][10] = "#";
    board[27][7] = "  #  #  ";board[27][9] = "#  #    ";board[27][11] = " #  #   ";
    board[27][13] = "  #   # ";board[27][15] = "#   #   ";board[27][12] = "#";
    board[28][7] = "  ####  ";board[28][9] = "####    ";board[28][11] = "#   #   ";
    board[28][13] = "  #   # ";board[28][15] = "#   #   ";board[28][12] = "#";
    board[29][7] = "  #   # ";board[29][9] = "#   #   ";board[29][11] = "    #   ";
    board[29][13] = "  #   # ";board[29][15] = "#   #   ";board[29][10] = "#";board[29][12] = "#";
    board[30][7] = "  ####  ";board[30][9] = "####   #";board[30][11] = "     ###";
    board[30][13] = "   ###  ";board[30][15] = " ###    ";
    
    // 1 column:
    board[1][1] = "Goose   ";board[2][1] = "Nesting ";board[8][1] = "OPT     ";
    board[13][1] = "BMH     ";board[16][1] = "SLC     ";board[23][1] = "LHI     ";
    board[26][1] = "UWP     ";board[33][1] = "CPH     ";board[38][1] = "DWE     ";
    board[41][1] = "PAC     ";board[48][1] = "RCH     ";board[51][1] = "DC Tims ";
    board[52][1] = "Line    ";
    // 3 column:
    board[3][3] = "EV1     ";board[53][3] = "HH      ";
    // 5 column:
    board[1][5] = "NEEDLES ";board[2][5] = "HALL    ";board[53][5] = "PAS     ";
    // 7 column:
    board[3][7] = "EV2     ";board[51][7] = "NEEDLES ";board[52][7] = "HALL    ";
    // 9 column:
    board[3][9] = "EV3     ";board[53][9] = "ECH     ";
    // 11 column:
    board[1][11] = "V1      ";board[51][11] = "MKV     ";
    // 13 column:
    board[3][13] = "PHYS    ";board[51][13] = "TUITION ";
    // 15 column:
    board[3][15] = "B1      ";board[53][15] = "ML      ";
    // 17 column:
    board[1][17] = "CIF     ";board[51][17] = "SLC     ";
    // 19 column:
    board[3][19] = "B2      ";board[53][19] = "AL      ";
    // 21 column:
    board[1][21] = "GO TO   ";board[2][21] = "TIMS    ";board[8][21] = "EIT     ";
    board[13][21] = "ESC     ";board[16][21] = "SLC     ";board[23][21] = "C2      ";
    board[26][21] = "REV     ";board[31][21] = "NEEDLES ";board[32][21] = "HALL    ";
    board[38][21] = "MC      ";board[41][21] = "COOP    ";board[42][21] = "FEE     ";
    board[48][21] = "DC      ";board[51][21] = "COLLECT ";board[52][21] = "OSAP    ";
    
    // player can be put:
    int n = 0;
    int i = 54;
    int j = 21;
    
    while (n <= 10) {
        pplace[n][0] = i;
        pplace[n][1] = j;
        n++;
        j -= 2;
    }
    
    i -= 5;
    j = 1;
    while (n <= 20) {
        pplace[n][0] = i;
        pplace[n][1] = j;
        n++;
        i -= 5;
    }
    
    j += 2;
    i = 4;
    while (n <= 30) {
        pplace[n][0] = i;
        pplace[n][1] = j;
        n++;
        j += 2;
    }
    
    i += 5;
    j = 21;
    while (n <= 39) {
        pplace[n][0] = i;
        pplace[n][1] = j;
        n++;
        i += 5;
    }
    
}

Textdisplay::~Textdisplay() {}

void Textdisplay::initplayer(char c, int n) {
    board[54][21][n] = c;
    ppos[n] = 0;
}

void Textdisplay::changepp(char c, int n, int loc) {
    int oldpos = ppos[n];
    int i = pplace[oldpos][0];
    int j = pplace[oldpos][1];
    board[i][j][n] = ' ';
    
    i = pplace[loc][0];
    j = pplace[loc][1];
    board[i][j][n] = c;
    ppos[n] = loc;
}

void Textdisplay::print(ostream &out) {
    for (int i = 0; i < 56; i++) {
        for (int j = 0; j < 23; j++) {
            out << board[i][j];
        }
        out << endl;
    }
}

void Textdisplay::getbanben(bool b) {
    if (b) {
        // 1 column:
        board[1][1] = "Seaking ";board[2][1] = "Nesting ";board[8][1] = "KUNLUN  ";
        board[13][1] = "HUASHAN ";board[16][1] = "SKYLAND ";board[23][1] = "KONGTONG";
        board[26][1] = "XUANWU  ";board[33][1] = "EMEI    ";board[38][1] = "WUDANG  ";
        board[41][1] = "RIYUE   ";board[48][1] = "SHAOLIN ";board[51][1] = "UNDERSEA";
        board[52][1] = "JAIL    ";
        // 3 column:
        board[3][3] = "MIGECUN ";board[53][3] = "DUDU    ";
        // 5 column:
        board[1][5] = "WORLD   ";board[2][5] = "COURT   ";board[53][5] = "FENGDU  ";
        // 7 column:
        board[3][7] = "MIGEZHEN";board[51][7] = "WORLD   ";board[52][7] = "COURT   ";
        // 9 column:
        board[3][9] = "MIGEYOSH";board[53][9] = "JINGDU  ";
        // 11 column:
        board[1][11] = "QINGLONG";board[51][11] = "BAIHU   ";
        // 13 column:
        board[3][13] = "WENCUN  ";board[51][13] = "REDLAND ";
        // 15 column:
        board[3][15] = "WENZHEN ";board[53][15] = "SUZHOU  ";
        // 17 column:
        board[1][17] = "MING    ";board[51][17] = "SKYLAND ";
        // 19 column:
        board[3][19] = "WENYOSH ";board[53][19] = "YUHANG  ";
        // 21 column:
        board[1][21] = "GO TO   ";board[2][21] = "JAIL    ";board[8][21] = "SHUSHAN ";
        board[13][21] = "KUNWU   ";board[16][21] = "SKYLAND ";board[23][21] = "FANGCUN ";
        board[26][21] = "ZHUQUE  ";board[31][21] = "WORLD   ";board[32][21] = "COURT   ";
        board[38][21] = "SHENJIE ";board[41][21] = "WATER   ";board[42][21] = "SEVEN   ";
        board[48][21] = "MOJIE   ";board[51][21] = "TREASURE";board[52][21] = "ISLAND  ";
    }
}




