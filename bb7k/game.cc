//
//  game.cpp
//  bb7k
//
//  Created by Grant on 15-7-15.
//  Copyright (c) 2015年 Grant. All rights reserved.
//

#include "game.h"

using namespace std;

game::game():num_player(0), now_play(-1), same(0){}

game::~game(){
    for(int i = 0; i < num_player; i++){
        delete players[i];
    }
}





void game::start_new(Map &m) {
    int num_players;
    cout << "How many players? (2 to 8 players)" << endl;
    cin >> num_players;
    
    bool all_symbol[8];
    for (int i = 0; i < 8; i++){
        all_symbol[i] = true;
    }
    for (int i = 1; i <= num_players; i++){
        string name;
        cout << "For player " << i << " , what's your name?" << endl;
        cin >> name;
        
        
        
        cout << "you can choose one of the following character" << endl;
        if (all_symbol[0]) cout << "Goose -------------------------- G" << endl;
        if (all_symbol[1]) cout << "GRT Bus ------------------------ B" << endl;
        if (all_symbol[2]) cout << "Tim Hortons Doughnut ----------- D" << endl;
        if (all_symbol[3]) cout << "Professor ---------------------- P" << endl;
        if (all_symbol[4]) cout << "Student ------------------------ S" << endl;
        if (all_symbol[5]) cout << "Money -------------------------- $" << endl;
        if (all_symbol[6]) cout << "Laptop ------------------------- L" << endl;
        if (all_symbol[7]) cout << "Pink tie ----------------------- T" << endl;
        char symbol;
        cin >> symbol;
        
        if (symbol == 'G') all_symbol[0] = false;
        if (symbol == 'B') all_symbol[1] = false;
        if (symbol == 'D') all_symbol[2] = false;
        if (symbol == 'P') all_symbol[3] = false;
        if (symbol == 'S') all_symbol[4] = false;
        if (symbol == '$') all_symbol[5] = false;
        if (symbol == 'L') all_symbol[6] = false;
        if (symbol == 'T') all_symbol[7] = false;
        
        cout << name << " is " << symbol << endl;
        add_player(name, symbol, m);
    }
    cout << "Game start! Take care for the goose!" << endl;
}












void game::add_player(std::string name, char symbol, Map &m){
    players[num_player] = new Player(name, symbol);
    players[num_player]->setmap(m);
    num_player++;
}

void game::trade_money(string p1, string p2, int n, int b){
    for(int i = 0; i < num_player; i++){
        if(players[i]->getname() == p1){
            players[i]->sub_money(n);
            players[i]->add_building(b);
        }
        if(players[i]->getname() == p2){
            players[i]->add_money(n);
            players[i]->sub_building(b);
        }
    }
}

void game::trade_building(string p1, string p2, int a, int b){
    cout << "a is " << a << " b is " << b << endl;
    for(int i = 0; i < num_player; i++){
        if(players[i]->getname() == p1){
            players[i]->sub_building(a);
            players[i]->add_building(b);
        }
        if(players[i]->getname() == p2){
            cout << players[i]->getname() << endl;
            cout << "add a " << a << endl;
            players[i]->add_building(a);
            
            players[i]->sub_building(b);
        }
    }
}

void game::next(){
    print_numplayer();
    if (now_play == num_player - 1){
        now_play = 0;
    }
    else{
        now_play++;
    }
    players[now_play]->print_name();
    cout << /*players[now_play]->getname() << */"'s turn!" <<endl;
}



bool game::Iswin(){
    int left = 0;
    for (int i = 0; i < num_player; i++){
        if (players[i]->check_lose() == 0){
            
            left++;
        }
    }
    if (left == 1) return true;
    else return false;
} //





void game::print_numplayer(){
    cout << num_player << endl;
}



void game::roll(int n){
    // int same = 0;
    int get;
    int a,b;
    if (n != 1) srand(time(NULL));
    while(true){
        if (n == 1) {
            cout << ">>>>>>>>>>>>>>>>>>>>Test Mode<<<<<<<<<<<<<<<<<<<<<" << endl;
            cout << endl;
            cout << "-> enter the number of dices" << endl;
            cout << "-> The first dice: ";
            cin >> a;
            cout << endl;
            cout << "-> The second dice: ";
            cin >> b;
            cout << endl;
        } else {
        a = rand()%6 + 1;
        b = rand()%6 + 1;
        }
        cout << "result is " << a << " & " << b << endl;
        if (a == b){
            same++;
            if (same == 3){
                same = 0;
                players[now_play]->setsend(true);
                players[now_play]->setDC(1);
                players[now_play]->setplace(10 - players[now_play]->getLoc());
                break;
            }
            else{
                cout << "same result, roll again" << endl;
                cout << endl;
                players[now_play]->move(a + b);
                break;
                
            }
        }
        else{
            same = 0;
            get = a + b;
            players[now_play]->move(get);
            break;
        }
    }
}

void game::getassets(){
    cout << "===============BANK STATEMENT for "<< players[now_play]->getname() << "===============" << endl;
    cout << "Assets: ";
    cout << players[now_play]->getAsset() << endl;
    cout << "Cash: " << players[now_play]->getMoney() << endl;
    cout << "Cup: " << players[now_play]->getCups() << endl;
    players[now_play]->print_ownbuilding();
    cout << endl;
}


string game::getname(){
    return players[now_play]->getname();
}

string game::getname(int n){
    return players[n]->getname();
}


int game::getLoc(){
    return players[now_play]->getLoc();
}



char game::getchar(){
    return players[now_play]->getchar();
}

char game::getchar(int n){
    return players[n]->getchar();
}

int game::getmoney(int n){
    return players[n]->getMoney();
}

int game::getmoney(){
    return players[now_play]->getMoney();
}


int game::getcup(int n){
    return players[n]->getCups();
}

int game::getposition(int n){
    return players[n]->getLoc();
}

int game::get_nowplay(){
    return now_play;
}



void game::loop(){
    now_play++;
}

void game::reset_nowplay(){
    now_play = -1;
}


int game::get_numplayer(){
    return num_player;
}


void game::print_winer(){
    for (int i = 0; i < num_player; i++){
        if (players[i]->check_lose() == 0){
            cout << "Congratulations!!!" << endl;
            cout << players[i]->getname() << " win this game!" << endl;
        }
    }
}

void game::mortgage(int b){
    players[now_play]->mortgage(b);
}

void game::unmortgage(int b){
    players[now_play]->unmortgage(b);
}



int game::getnump() { return num_player; }

map<int,Player *> game::makearray (int n) {
    map<int, Player *>arr;
    
    for (int i = 0; i < n; ++i) {
        arr[i] = players[i];
        cout << arr[i]->getname() << endl;
    }
    
    return arr;
}


int game::getnplay() {
    return now_play;
}

void game::add_player(std::string name, char symbol, int cups, int money, int position, Map &m){
    players[num_player] = new Player(name, symbol, cups, money, position);
    players[num_player]->setmap(m);
    num_player++;
}

void game::add_player(std::string name, char symbol, int cups, int money, int position, Map &m, bool b){
    players[num_player] = new Player(name, symbol, cups, money, position);
    players[num_player]->setmap(m);
    players[num_player]->settest();
    num_player++;
}

void game::load_player(ifstream &get, Map &m, int t){
    int num_player;
    get >> num_player;
    cout << "num player is " <<num_player << endl;
    for (int i = 0; i < num_player; i++){
        cout << "s" << endl;
        string name;
        get >> name;
        char c;
        get >> c;
        
        int cup;
        get >> cup;
        int money;
        get >> money;
        int position;
        get >> position;
        if (position == 10){
            if (t == 1) {
                add_player(name, c, cup, money, position, m, true);
            } else {
            add_player(name, c, cup, money, position, m);
            }
            int a;
            get >> a;
            if (a == 0){
                players[i]->setDC(0);
            }
            else {
                int b;
                get >> b;
                players[i]->setDC(b + 1);
            }
        }
        else{
            if (t == 1) {
                add_player(name, c, cup, money, position, m, true);
            } else {
            add_player(name, c, cup, money, position, m);
            }
        }
        players[i] -> print_name();
    }
}


Player *game::getplayer(string owner){
    for (int i = 0; i < num_player; i++){
        if (players[i]->getname() == owner){
            return players[i];
        }
    }
    return 0;
}


void game::setbuilding(std::string owner, int b){
    for (int i = 0; i < num_player; i++){
        if (players[i]->getname() == owner){
            players[i]->add_building(b);
        }
    }
}



void game::setlose(){
    players[now_play]->set_lose();
}



Player *game::getnplayer() {
    return players[now_play];
}


int game::getDC(int n){
    return players[n]->getDC();
}


void game::setDC(int n, int dc){
    players[n]->setDC(dc);
}


void game::start_new(Map &m, bool b, int t) {
    int num_players;
    cout << "How many players? (2 to 8 players)" << endl;
    cin >> num_players;
    
    bool all_symbol[8];
    for (int i = 0; i < 8; i++){
        all_symbol[i] = true;
    }
    for (int i = 1; i <= num_players; i++){
        string name;
        cout << "For player " << i << " , what's your name?" << endl;
        cin >> name;
        
        
        
        cout << "you can choose one of the following character" << endl;
        if (all_symbol[0]) cout << "Straw Hat Pirates -------------- S" << endl;
        if (all_symbol[1]) cout << "Red Haired Pirates ------------- R" << endl;
        if (all_symbol[2]) cout << "CP9 ---------------------------- C" << endl;
        if (all_symbol[3]) cout << "White Beard Pirates ------------ W" << endl;
        if (all_symbol[4]) cout << "Black Beard Pirates ------------ B" << endl;
        if (all_symbol[5]) cout << "Water 7 ------------------------ 7" << endl;
        if (all_symbol[6]) cout << "Navy --------------------------- N" << endl;
        if (all_symbol[7]) cout << "Gragon Man---------------------- G" << endl;
        char symbol;
        cin >> symbol;
        
        if (symbol == 'S') all_symbol[0] = false;
        if (symbol == 'R') all_symbol[1] = false;
        if (symbol == 'C') all_symbol[2] = false;
        if (symbol == 'W') all_symbol[3] = false;
        if (symbol == 'B') all_symbol[4] = false;
        if (symbol == '7') all_symbol[5] = false;
        if (symbol == 'N') all_symbol[6] = false;
        if (symbol == 'G') all_symbol[7] = false;
        
        cout << name << " is " << symbol << endl;
        if (t == 1) {
            add_player(name, symbol, m, true);
        } else {
            add_player(name, symbol, m);
        }
    }
    cout << "Game start! Welcome to the New World!" << endl;
}

void game::getassets(bool b) {
    cout << "===============BANK STATEMENT for "<< players[now_play]->getname() << "===============" << endl;
    cout << "Assets: ";
    cout << players[now_play]->getAsset() << endl;
    cout << "Coins: " << players[now_play]->getMoney() << endl;
    cout << "Statements: " << players[now_play]->getCups() << endl;
    players[now_play]->print_ownbuilding();
    cout << endl;
}

void game::add_player(std::string name, char symbol, Map &m, bool b) {
    if (b) {
        players[num_player] = new Player(name, symbol);
        players[num_player]->setmap(m);
        players[num_player]->settest();
        num_player++;
    }
}

void game::start_new(Map &m, int t) {
    int num_players;
    cout << "How many players? (2 to 8 players)" << endl;
    cin >> num_players;
    
    bool all_symbol[8];
    for (int i = 0; i < 8; i++){
        all_symbol[i] = true;
    }
    for (int i = 1; i <= num_players; i++){
        string name;
        cout << "For player " << i << " , what's your name?" << endl;
        cin >> name;
        
        
        
        cout << "you can choose one of the following character" << endl;
        if (all_symbol[0]) cout << "Goose -------------------------- G" << endl;
        if (all_symbol[1]) cout << "GRT Bus ------------------------ B" << endl;
        if (all_symbol[2]) cout << "Tim Hortons Doughnut ----------- D" << endl;
        if (all_symbol[3]) cout << "Professor ---------------------- P" << endl;
        if (all_symbol[4]) cout << "Student ------------------------ S" << endl;
        if (all_symbol[5]) cout << "Money -------------------------- $" << endl;
        if (all_symbol[6]) cout << "Laptop ------------------------- L" << endl;
        if (all_symbol[7]) cout << "Pink tie ----------------------- T" << endl;
        char symbol;
        cin >> symbol;
        
        if (symbol == 'G') all_symbol[0] = false;
        if (symbol == 'B') all_symbol[1] = false;
        if (symbol == 'D') all_symbol[2] = false;
        if (symbol == 'P') all_symbol[3] = false;
        if (symbol == 'S') all_symbol[4] = false;
        if (symbol == '$') all_symbol[5] = false;
        if (symbol == 'L') all_symbol[6] = false;
        if (symbol == 'T') all_symbol[7] = false;
        
        cout << name << " is " << symbol << endl;
        add_player(name, symbol, m, true);
    }
    cout << "Game start! Take care for the goose!" << endl;
}


//new

bool game::check_havebuilding(int b){
    return players[now_play]->check_havebuilding(b);
}

bool game::check_havebuilding(int b, string name){
    for (int i = 0; i < num_player; i++){
        if (getname(i) == name){
            return players[i]->check_havebuilding(b);
        }
    }
    return false;
}

int game::getsame() {
    return same;
}




