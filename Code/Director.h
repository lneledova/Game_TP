#pragma once
#include "Builder.h"


class Director {
public:
    void create_player(Builder& builder, string& gender, int motivation, int abilities);
};
