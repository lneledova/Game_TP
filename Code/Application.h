#pragma once
#include "Director.h"

class Application {
public:
    std::string gender;
    int motivation;
    int abilities;

    Application(const std::string& gender, int motivation, int abilities);

    Player make_player();
};
