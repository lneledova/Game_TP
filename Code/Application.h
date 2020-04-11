#pragma once
#include "Director.h"

class Application {
public:
    string gender;
    int motivation;
    int abilities;

    Application(string& gender, int motivation, int abilities);

    Player make_player();
};
