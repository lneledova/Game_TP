#pragma once
#include <iostream>
#include <string>


class Player {
private:
    std::string gender;
    int motivation;
    int abilities;
    int matan;
    int labs;
    int english;
    int tech_prog;
    bool alone;
public:
    void set_gender(const std::string& that);
    void set_motivation(int that);
    void set_abilities(int that);

    void change_motivation(int that);
    void change_abilities(int that);
    void change_matan(int that);
    void change_english(int that);
    void change_labs(int that);
    void change_tech_prog(int that);

    std::string get_gender() const;
    int get_motivation() const;
    int get_abilities() const;
    int get_labs() const;
    int get_matan() const;
    int get_english() const;
    int get_tech_prog() const;

    void see_development() const;

    Player(): matan(0), labs(0), english(0), tech_prog(0), alone(true){};
    Player& operator=(Player& that) = default;
    ~Player(){};

};
