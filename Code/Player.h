#pragma once
#include <iostream>
#include <string>


class Player {
private:
    int motivation;
    int abilities;
    int matan;
    int labs;
    int english;
    int tech_prog;
    int days;
public:
    void set_motivation(int that);
    void set_abilities(int that);
    void set_matan(int that);
    void set_english(int that);
    void set_labs(int that);
    void set_tech_prog(int that);

    void change_motivation(int that);
    void change_abilities(int that);
    void change_matan(int that);
    void change_english(int that);
    void change_labs(int that);
    void change_tech_prog(int that);

    int get_motivation() const;
    int get_abilities() const;
    int get_labs() const;
    int get_matan() const;
    int get_english() const;
    int get_tech_prog() const;

    int& get_days();

    void see_development() const;

    Player(): matan(0), labs(0), english(0), tech_prog(0), days(24) {};
    Player& operator=(Player& that) = default;
    ~Player(){};

};