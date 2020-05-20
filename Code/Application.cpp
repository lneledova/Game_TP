#include "Application.h"

Application::Application(int motivation, int abilities) {
    this->motivation = motivation;
    this->abilities = abilities;
};

Player Application::make_player() const {
    Director director;
    Builder builder;
    director.create_player(builder, motivation, abilities);
    Player player = builder.get_result();
    return player;
}