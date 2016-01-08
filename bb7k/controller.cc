//
//  controller.cpp
//  bb7k
//
//  Created by Grant on 15-7-14.
//  Copyright (c) 2015年 Grant. All rights reserved.
//

#include "controller.h"
#include "textdisplay.h"
#include <map>
#include <cstring>
#include <cstdlib>
using namespace std;

controller::controller(int test, int load, string file):
test(test),
load(load),
file(file){
    m = new Map;
    p = new game;
    td = new Textdisplay;
    // gd = new Graphicdisplay;
}

controller::~controller(){}

void welcome_msg(){
    cout << "=====================================" << endl;
    cout << "==         Welcome to BB7K         ==" << endl;
    cout << "==       New game   -> press 1     ==" << endl;
    cout << "==       Exit       -> press 2     ==" << endl;
    cout << "=====================================" << endl;
}

void display_help(){
    cout << "====================HELP INFORMATION====================" << endl;
    cout << "-->   Command:                                        ==" << endl;
    cout << "-->         roll---------roll dice and move           ==" << endl;
    cout << "-->         next---------exit your turn               ==" << endl;
    cout << "-->         map----------view the current map         ==" << endl;
    cout << "-->         trade--------trade with other             ==" << endl;
    cout << "-->         assets-------get your total assets        ==" << endl;
    cout << "-->         save---------save the game                ==" << endl;
    cout << "-->         quit---------end game                     ==" << endl;
    cout << "-->         bankrupt-----declear bank rupt            ==" << endl;
    cout << "========================================================" << endl;
}




void controller::play(){
    //load = 1;
    //file = "a.txt";
    //td->print(cout);
    
    map<int, Player*>parr;   // mi gai de
    
    map<string, int>build;
    for (int i = 0;i<40;i++) {
        build[m->printname(i)] = i;
    }
    bool banben = false;
    
    if (load == 0){
        
        welcome_msg();
        
        while (true){
            int get;
            cin >> get;
            if (get == 1){
                
                cout << endl;
                cout << "Which version do you want to play?" << endl;
                cout << "-> enter 1: University of Waterloo" << endl;
                cout << "-> enter 2: One Piece" << endl;
                cin >> get;
                if (get == 1)  {
                    if (test == 1) p->start_new(*m, test);
                    else p->start_new(*m);
                }
                else {
                    banben = true;
                    p->start_new(*m, banben, test);
                }
                
                int total_player = p->get_numplayer();
                for (int i = 0; i < total_player; i++){
                    p->loop();
                    td->initplayer(p->getchar(), p->get_nowplay());
                }
                
                
                
                
                break;
            }
            else if (get == 2){
                return;
            }
            else {
                cout << "wrong input, please try again!" << endl;
            }
        }
    }
    
    
    else{
        //load game;
        ifstream get(file.c_str());
        
        
        
        
        if (/*get.is_open()*/ 1) {
            
            
            
            p->load_player(get, *m, test);
            
        
            
            while (!get.eof()){
                string building;
                get >> building;
                
                
                string owner;
                get >> owner;
                
                int imp;
                get >> imp;
                
                
                int b = build[building];
                //cout << "building is" << b << endl;
                if (owner != "BANK" && b != 0){
                    p->setbuilding(owner, b);
                    m->setload(b,imp);
                    
                }
            }
            
            
           // get.close();
        }
        //
        int total_player = p->get_numplayer();
        for (int i = 0; i < total_player; i++){
            p->loop();
            td->initplayer(p->getchar(), p->get_nowplay());
            td->changepp(p->getchar(), p->get_nowplay(), p->getLoc());
        }
        
        //td->print(cout);
    }
    
    m->getbanben(banben);
    td->getbanben(banben);
    
    for (int i = 0;i<40;i++) {
        build[m->printname(i)] = i;
    }
    
    td->print(cout);
    
    
    int nump = p->getnump();
    
    
    
    
    
    bool finish = true;
    bool roll = true;
    while(true){
        if (finish) {
            p->next();
            roll = false;
            finish = false;
        }
        /*
         string read;
         getline(cin, read);
         cout << "read is: " << read << endl;
         istringstream sread(read);
         */
        
        if (p->getLoc() == 10 && p->getnplayer()->getsend() == true && roll == false) {
            p->getnplayer()->move(0);
            roll = true;
            finish = true;
        }
        
        
        td->changepp(p->getchar(), p->get_nowplay(), p->getLoc());
        
        if (p->getnplayer()->getout() && p->getnplayer()->getauc())
        
        /*
            p->getnplayer()->getout() &&
            p->getnplayer()->getLoc() != 0 && p->getnplayer()->getLoc() != 2 &&
            p->getnplayer()->getLoc() != 4 && p->getnplayer()->getLoc() != 7 &&
            p->getnplayer()->getLoc() != 17 && p->getnplayer()->getLoc() != 20 &&
            p->getnplayer()->getLoc() != 22 && p->getnplayer()->getLoc() != 30 &&
            p->getnplayer()->getLoc() != 36 && p->getnplayer()->getLoc() != 38)*/
        {
            parr = p->makearray(nump);
            // mi gai de
            if (parr[p->getnplay()]->getauc()) {
                int onum = parr[p->getnplay()]->getownnum();
                map<int,int>ownarr;
                parr[p->getnplay()]->makeownarr(ownarr);
                
                m->auction(parr[p->getnplay()]->getLoc(), parr[p->getnplay()]->getMoney(), parr[p->getnplay()]->getchar(), nump,onum, parr, m->getbuilding(parr[p->getnplay()]->getLoc()), ownarr);
                
            }
            
            td->changepp(p->getchar(), p->get_nowplay(), p->getLoc());
        } else if (p->getnplayer()->getout() && !p->getnplayer()->getauc()) {
            p->getnplayer()->setout(false);
        }
        
        p->getnplayer()->setout(false);
        
        cout << "You can enter 'help' for help." << endl;
        
        
        string commond;
        cin >> commond;
        
        
        
        if (commond == "roll"){
            if (roll == true){
                cout << "sorry, you already roll it" << endl;
            }
            else {
                
                parr = p->makearray(nump); 
                p->roll(test);
                td->changepp(p->getchar(), p->get_nowplay(), p->getLoc());
                if (p->getsame() == 0) roll = true;
                
                if (parr[p->getnplay()]->getauc()) {
                    int onum = parr[p->getnplay()]->getownnum();
                    map<int,int>ownarr;
                    parr[p->getnplay()]->makeownarr(ownarr);
                    
                    m->auction(parr[p->getnplay()]->getLoc(), parr[p->getnplay()]->getMoney(), parr[p->getnplay()]->getchar(), nump,onum, parr, m->getbuilding(parr[p->getnplay()]->getLoc()), ownarr);
                    
                    td->changepp(p->getchar(), p->get_nowplay(), p->getLoc());
                }
            }
            finish = false;
        }
        
        // xin gai de
        else if (commond == "next"){
            if (roll == false) {
                cout << endl;
                cout << "You haven't rolled! You cannot next the turn!" << endl;
                finish = false;
            } else {
                td->print(cout);
                finish = true;
            }
        }
        
        else if (commond == "Migehaoshuai") {
            p->getnplayer()->add_money(10000);
            finish = false;
        } else if (commond == "map") {
            td->print(cout);
            finish = false;
        }
        
        else if (commond == "assets"){
            if (banben) {
                p->getassets(banben);
            } else {
                p->getassets();
            }
            finish = false;
        }
        
        else if (commond == "trade"){
            
            string nowplay = p->getname();
            string target;
            cin >> target;
            
            
            int n;
            string a;
            string b;
            if (cin >> n){ //money trade building
                cin >> b;
                int building = build[b];
                if (!p->check_havebuilding(building, target)){
                    cout << "Sorry, this trade can not be made." << endl;
                } else if (m->getlevel(building) != 0) {
                    cout << "Sorry, "<< target << "'s building is improved, the trade cannot be made. " << endl;
                }
                else {
                    cout << target << ": do you want to trade with " << nowplay << "?" << endl;
                    cout << "if yes enter 'yes', if no enter 'no' " << endl;
                    string ans;
                    cin >> ans;
                    if (ans == "yes"){
                        p->trade_money(nowplay, target, n, building);
                        cout << "trade completed" << endl;
                    }
                    else{
                        cout << "Sorry, " << target << " do not want to trade you" << endl;
                    }
                }
            }
            else{
                
                cin.clear();
                cin >> a;
                
                int buildinga = build[a];
                
                //check whether i have this building
                if (!p->check_havebuilding(buildinga)){
                    cout << "Sorry, this trade can not be made." << endl;
                    cin >> a;
                } else if (m->getlevel(buildinga) != 0) {
                    cout << "Sorry, your building is improved, the trade cannot be made. " << endl;
                }
                
                else {
                    //building trade money
                
                    if (cin >> n){
                        cout << target << ": do you want to trade with " << nowplay << "?" << endl;
                        cout << "if yes enter 'yes', if no enter 'no' " << endl;
                    
                    
                        string ans;
                        cin >> ans;
                        if (ans == "yes"){
                            p->trade_money(target, nowplay, n, buildinga);
                            cout << "trade completed" << endl;
                        }
                        else{
                        cout << "Sorry, " << target << " do not want to trade you" << endl;
                        }
                    
                    
                    }
                    else{
                        //building trade building
                        cin.clear();
                        cin >> b;
                        int buildingb = build[b];
                        if (!p->check_havebuilding(buildingb, target)){
                            cout << "Sorry, this trade can not be made." << endl;
                        } else if (m->getlevel(buildingb) != 0) {
                            cout << "Sorry, "<< target << "'s building is improved, the trade cannot be made. " << endl;
                        }
                        else {
                        
                        
                            cout << target << ": do you want to trade with " << nowplay << "?" << endl;
                            cout << "if yes enter 'yes', if no enter 'no' " << endl;
                    
                    
                            string ans;
                            cin >> ans;
                            if (ans == "yes"){
                                int buildingb = build[b];
                                cout << "b " << b << endl;
                                p->trade_building(nowplay, target, buildinga,   buildingb);
                                cout << buildingb << endl;
                                cout << "trade completed" << endl;
                            }
                            else{
                                cout << "Sorry, " << target << " do not want to trade you" << endl;
                            }
                        }
                    }
                        
                }
            }
            
            finish = false;
        }
        
        
        
        else if (commond == "mortgage"){
            // int location = p->getLoc();
            string b;
            cin >> b;
            int building = build[b];
            if (m->getmort(building)){
                cout << "Sorry, this building already mortgaged" << endl;
            }
            else if (m->getlevel(building) > 0){
                cout << "sorry, this building already update, can not be mortgage" << endl;
            }
            else {
                p->mortgage(building);
                cout << "finish mortgage" << endl;
            }
            finish = false;
        }
        
        
        else if (commond == "unmortgage"){
            string b;
            cin >> b;
            int building = build[b];
            if (m->getmort(building)){
                p->unmortgage(building);
            }
            else {
                cout << "this buiding haven't been mortgage before" << endl;
            }
            finish = false;
        }
        
        else if (commond == "improve"){
            string b;
            cin >> b;
            int building = build[b];
            string get;
            cin >> get;
            if (get == "buy"){
                m->improve(building);
            }
            else if (get == "sell"){
                m->ntimprove(building);
            }
            finish = false;
        }
        
        
        else if (commond == "bankrupt"){
            if (p->getmoney() > 0){
                cout << "You still have money, you can not go bankrupt" << endl;
            }
            else{
                p->setlose();
            
                parr = p->makearray(nump);
                
                    int onum = parr[p->getnplay()]->getownnum();
                    map<int,int>ownarr;
                
                    ownarr = parr[p->getnplay()]->makeownarr(ownarr);
                
                    // ownarr
                    m->auction(1, parr[p->getnplay()]->getMoney(), parr[p->getnplay()]->getchar(), nump,onum, parr, m->getbuilding(parr[p->getnplay()]->getLoc()), ownarr);
                
                    td->changepp(p->getchar(), p->get_nowplay(), p->getLoc());
                finish = 1;
                roll = 1;
            }
        }
        
        
        else if (commond == "help"){
            display_help();
            finish = false;
        }
        
        
        // xin gai de
        else if (commond == "quit"){
            cout << endl;
            cout << "=====================================" << endl;
            cout << "==       Thanks for Playing!       ==" << endl;
            cout << "==                                 ==" << endl;
            cout << "==             Bye Bye!            ==" << endl;
            cout << "=====================================" << endl;
            break;
        }
        // end
        
        
        else if (commond == "save"){
            cout << "What name do you want for the save file?" << endl;
            string filename;
            cin >> filename;
            ofstream myfile;
           // const char *agg = filename.c_str;           //(filename.c_str);
            myfile.open(filename.c_str());
            int nump = p->getnump();
            myfile << nump << endl;
            for (int i = 0; i < nump; i++){
                myfile << p->getname(i) << " ";
                myfile << p->getchar(i) << " ";
                myfile << p->getcup(i) << " ";
                myfile << p->getmoney(i) << " ";
                int position = p->getposition(i);
                if (position == 10){
                    int dcnum = p->getDC(i);
                    if (p->getDC(i) == 0){
                        myfile << position << " 0" << endl;
                    }
                    else {
                        myfile << position << " 1 " << dcnum - 1 << endl;
                    }
                }
                else{
                    myfile << position << endl;;
                }
                
            }
            for (int i = 0; i < 40; i++){
                if(m->Isownable(i)){
                    cout << "go in" << endl;
                    myfile << m->getname(i) << " ";
                    if (m->getowner(i) == NULL){
                        myfile << "BANK ";
                    }
                    else{
                        myfile << m->getowner(i)->getname() << " ";
                    }
                    if (m->getmort(i)){
                        myfile << "-1" << endl;
                    }
                    else{
                        myfile << m->getlevel(i) << endl;
                    }
                }
            }
            
          //  myfile.close();
            
            finish = false;
        }
        
        
        
        
        
        
        
        
        
        else{
            cout << "Worng commmond, please try again" << endl;
            finish = false;
        }
        
        
        if (p->Iswin()){
            p->print_winer();
            cout << "finish" << endl;
            break;
        }
    }
}







/*

void controller::load(string file){
    ifstream get(file.c_str());
    p->load_player(get, *m);
    while (get.eof()){
        string building;
        get >> building;
        string owner;
        get >> owner;
        int imp;
        get >> imp;
//        m->setload(building, owner, imp);
    }
}

*/









