#pragma once
#include "Player.h"


class Builder {
private:
    Player p;
public:
    void set_gender(string& gender);
    void set_motivation(int motivation);
    void set_abilities(int abilities);
    Player get_result();
};
