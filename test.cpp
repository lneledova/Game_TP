#include "Code/header.h"
#include "Code/Application.cpp"
#include "Code/Builder.cpp"
#include "Code/Director.cpp"
#include "Code/Player.cpp"
#include <gtest/gtest.h>


Player hand_create() {
    Player a;
    std::string g = "male";
    a.set_gender(g);
    a.set_motivation(7);
    a.set_abilities(6);
    return a;
}

bool IsEqual(Player a, Player b) {
    if (a.get_gender() == b.get_gender() && a.get_abilities() == b.get_abilities() && a.get_motivation() == b.get_motivation()) {
        return true;
    }
    return false;
}


TEST(Create, Player) {
    std::string g = "male";
    Application a(g, 7, 6);
    EXPECT_TRUE(IsEqual(a.make_player(), hand_create()));
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
