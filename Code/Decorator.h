#pragma once
#include "header.h"

class Decorator {
private:
    void Day_matan(Player& player);
    void Day_english(Player& player);
    void Day_labs(Player& player);
    void Day_tech_prog(Player& player);
    void Chill_day(Player& player);
    void Day_walk(Player& player);
    void Day_coffee(Player& player);
public:
    void Day (int what_action, Player& player);
};

