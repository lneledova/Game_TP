#pragma once
#include "Director.h"

class Application {
public:
    int motivation;
    int abilities;

    Application(int motivation, int abilities);

    Player make_player() const;
};
