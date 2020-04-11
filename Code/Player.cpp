
#include "Player.h"


void Player::set_gender(string& that) {
    gender = that;
}

void Player::set_motivation(int that) {
    motivation = that;
}

void Player::set_abilities(int that) {
    abilities = that;
}

string Player::get_gender() const {
    return gender;
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
    cout << "Ну, давай посмотрим, насколько ты прокачался." << endl;
    cout << "{ ";
    for (int i = 0; i < matan; ++i) {
        cout << "== ";
    }
    for (int i = 0; i < 10 - matan; ++i) {
        cout << "-- ";
    }
    cout << "} - Матан" << endl;
    cout << "{ ";
    for (int i = 0; i < labs; ++i) {
        cout << "== ";
    }
    for (int i = 0; i < 10 - labs; ++i) {
        cout << "-- ";
    }
    cout << "} - Лабы" << endl;
    cout << "{ ";
    for (int i = 0; i < english; ++i) {
        cout << "== ";
    }
    for (int i = 0; i < 10 - english; ++i) {
        cout << "-- ";
    }
    cout << "} - Английский язык" << endl;
    cout << "{ ";
    for (int i = 0; i < tech_prog; ++i) {
        cout << "== ";
    }
    for (int i = 0; i < 10 - tech_prog; ++i) {
        cout << "-- ";
    }
    cout << "} - Технологии программирования" << endl;
}