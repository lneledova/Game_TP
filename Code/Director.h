#pragma once
#include "Builder.h"


class Director {
public:
    void create_player(Builder& builder, int motivation, int abilities);
};
