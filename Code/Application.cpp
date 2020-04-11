#include "Application.h"

Application::Application(string& gender, int motivation, int abilities) {
    this->gender = gender;
    this->motivation = motivation;
    this->abilities = abilities;
};

Player Application::make_player() {
    Director director;
    Builder builder;
    director.create_player(builder, gender, motivation, abilities);
    Player player = builder.get_result();
    return player;
}