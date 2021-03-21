#pragma once
#include "header.h"

class Decorator {
private:
    static void Day_matan(Player& player);
    static void Day_english(Player& player);
    static void Day_labs(Player& player);
    static void Day_tech_prog(Player& player);
    static void Chill_day(Player& player);
    static void Day_walk(Player& player);
    static void Day_coffee(Player& player);
public:
    void Day (int what_action, Player& player);
};

