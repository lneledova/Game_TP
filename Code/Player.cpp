
#include "Player.h"



void Player::set_motivation(int that) {
    motivation = that;
}
void Player::set_abilities(int that) {
    abilities = that;
}
void Player::set_matan(int that) {
    matan = that;
}
void Player::set_labs(int that) {
    labs = that;
}
void Player::set_tech_prog(int that) {
    tech_prog = that;
}
void Player::set_english(int that) {
    english = that;
}


int Player::get_motivation() const {
    return motivation;
}
int Player::get_abilities() const {
    return abilities;
}
int Player::get_labs() const {
    return labs;
}
int Player::get_matan() const {
    return matan;
}
int Player::get_english() const {
    return english;
}
int Player::get_tech_prog() const {
    return tech_prog;
}
int& Player::get_days() {
    return days;
}


void Player::change_motivation(int that) {
    motivation += that;
    if (motivation < 0) {
        motivation = 0;
    }
}

void Player::change_abilities(int that) {
    abilities += that;
    if (abilities < 0) {
        abilities = 0;
    }
}

void Player::change_matan(int that) {
    matan += that;
    if (matan > 10) {
        matan = 10;
    }
    if (matan < 0) {
        matan = 0;
    }
}

void Player::change_english(int that) {
    english += that;
    if (english > 10) {
        english = 10;
    }
    if (english < 0) {
        english = 0;
    }
}

void Player::change_labs(int that) {
    labs += that;
    if (labs > 10) {
        labs = 10;
    }
    if (labs < 0) {
        labs = 0;
    }
}

void Player::change_tech_prog(int that) {
    tech_prog += that;
    if (tech_prog > 10) {
        tech_prog = 10;
    }
    if (tech_prog < 0) {
        tech_prog = 0;
    }
}

void Player::see_development() const {
    std::cout << "Ну, давай посмотрим, насколько ты прокачался." << std::endl;
    std::cout << "{ ";
    for (int i = 0; i < matan; ++i) {
       std::cout << "== ";
    }
    for (int i = 0; i < 10 - matan; ++i) {
        std::cout << "-- ";
    }
    std::cout << "} - Матан" << std::endl;
    std::cout << "{ ";
    for (int i = 0; i < labs; ++i) {
        std::cout << "== ";
    }
    for (int i = 0; i < 10 - labs; ++i) {
        std::cout << "-- ";
    }
    std:: cout << "} - Лабы" << std::endl;
    std::cout << "{ ";
    for (int i = 0; i < english; ++i) {
        std::cout << "== ";
    }
    for (int i = 0; i < 10 - english; ++i) {
        std::cout << "-- ";
    }
    std::cout << "} - Английский язык" << std::endl;
    std::cout << "{ ";
    for (int i = 0; i < tech_prog; ++i) {
        std::cout << "== ";
    }
    for (int i = 0; i < 10 - tech_prog; ++i) {
        std::cout << "-- ";
    }
    std::cout << "} - Технологии программирования" << std::endl;
}