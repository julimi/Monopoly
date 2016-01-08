//
//  player.cpp
//  bb7k
//
//  Created by Grant on 15-7-15.
//  Copyright (c) 2015年 Grant. All rights reserved.
//

#include "player.h"

using namespace std;
int Player::total_cup = 0;

Player::Player(std::string name, char symbol):
name(name), symbol(symbol), money(1500), cup(0),place(0),
own_num(0), Rnum(0), Gnum(0), test(0), lose(0),send(0), auc(0), outer(0), DCcount(0) {}


Player::Player(std::string name, char symbol, int cups, int money, int position):
        name(name),
        symbol(symbol),
        cup(cups),
        money(money),
        place(position),
own_num(0), Rnum(0), Gnum(0), test(0), lose(0),send(0), auc(0), outer(0), DCcount(0)
{}


Player::~Player(){}



void Player::setmap(Map &m){
    this->map = &m;
}


void Player::set_die(){
    die = true;
}


bool Player::gettest(){
    return test;
}


void Player::print_name(){
    std::cout << this->name;
    return;
}


std::string Player::getname(){
    return name;
}


bool Player::check_lose(){
    return lose;
}


bool Player::check_die(){
    return die;
}


char Player::getchar(){
    return symbol;
}


void Player::add_money(int n){
    money += n;
}


void Player::sub_money(int n){
    money -= n;
}


void Player::add_cup(){
    cup++;
    total_cup++;
}


void Player::sub_cup(){
    cup--;
    total_cup--;
}


int Player::getMoney(){
    return money;
}

int Player::getCups(){
    return cup;
}

int Player::getAsset(){
    int a = this->money;
    for (int i = 0; i < own_num; i++){
        a = a + map->getCost(own[i]);
    }
    return a;
}

void Player::add_building(int b){
    own[own_num] = b;
    map->setOwner(b, *this);
    if (map->getblock(b) == "Residence" || map->getblock(b) == "SHOU") Rnum++;
    if (map->getblock(b) == "Gym" || map->getblock(b) == "MOJIAO") Gnum++;
    own_num++;
}


void Player::sub_building(int b){
    for (int i = 0; i < own_num; i++){
        if (own[i] == b){
            own[i] = own[own_num - 1];
            if (map->getblock(b) == "Residence" || map->getblock(b) == "SHOU") Rnum--;
            if (map->getblock(b) == "Gym" || map->getblock(b) == "MOJIAO") Gnum--;
            //this->map->sub_owner(b);
            own_num--;
            break;
        }
    }
}


void Player::mortgage(int b){
    for (int i = 0; i < own_num; i++){
        if (own[i] == b){
            cout << "in mort" << endl;
            map->setmortgage(b);
            int get = map->getCost(b) / 2;
            add_money(get);
        }
    }
}


void Player::unmortgage(int b){
    for (int i = 0; i < own_num; i++){
        if (own[i] == b){
            map->setunmortgage(b);
            int get = map->getCost(b) / 2 * 1.1;
            sub_money(get);
            map->setunmortgage(b);
        }
    }
}


void Player::move(int n){
    place += n;
    if (place > 39){
        place = place - 40;
        cout << "You get $200 from OSAP" << endl;
        add_money(200);
        cout << "now you have $" << getMoney() << endl;
    }
    cout << "-> You have been to " << place << " -- " << this->map->getname(place) << endl;
    this->map->change(place, *this);
}


int Player::getTcup(){
    return total_cup;
}


Map *Player::getMap(){
    return map;
}


int Player::getLoc(){
    return place;
}


void Player::setsend(bool a){
    send = a;
}


bool Player::getsend(){
    return send;
}


void Player::print_ownbuilding(){
    for (int i = 0; i < own_num; i++){
        cout << "Building:" << endl;
        cout << "    name: " << map->printname(own[i]) << endl;
        cout << "    value: " << map->getCost(own[i]) << endl;;
        cout << "    level: " << map->getlevel(own[i]) << endl;
        if (map->getmort(own[i])){
            cout << "      is mortgage" << endl;
        }
        else {
            cout << "      is not mortgage" << endl;
        }
    }
}




bool Player::getauc() { return auc; }
void Player::setauc(bool a) { auc = a;}
int Player::getownnum() { return own_num; }
int Player::getGnum() { return Gnum;}
int Player::getRnum() { return Rnum;}
map<int, int> Player::makeownarr(std::map<int, int> arr) {
    for (int i = 0; i < own_num; i++) {
        arr[i] = own[i];
    }
    return arr;
}


bool Player::getout() {
    return outer;
}

void Player::setout(bool b) {
    outer = b;
}


void Player::set_lose(){
    lose = true;
}

int Player::getDC() {
    return DCcount;
}

void Player::setDC(int n) {
    DCcount = n;
}

void Player::settest() {
    test = true;
}

void Player::setplace(int n) {
    place += n;
    if (place > 39){
        place = place - 40;
    }
    cout << "-> You have been to " << place << " -- " << this->map->getname(place) << endl;
}

bool Player::check_havebuilding(int b) {
    for (int i = 0; i < own_num; i++){
        if (own[i] == b){
            return true;
        }
    }
    return false;
}



