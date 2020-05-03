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

TEST(Full, Decorator) {
    Decorator dec;
    Player pl = hand_create();
    int nowdays = pl.get_days() + 1;
    pl.change_matan(10);
    decorator.Day(1, pl);
    EXPECT_EQ(pl.get_days(), nowdays);
}

TEST(Tech_prog, Decorator) {
    Decorator dec;
    Player pl = hand_create();
    int now_tech = pl.get_tech_prog();
    int now_mat = pl.get_matan();
    int now_eng = pl.get_english();
    int now_labs = pl.get_labs();
    dec.Day(3, pl);
    EXPECT_TRUE(pl.get_tech_prog() >= now_tech && pl.get_matan() == now_mat && pl.get_english() == now_eng && pl.get_labs() == now_labs);
}

TEST(Matan, Decorator) {
    Decorator dec;
    Player pl = hand_create();
    int now_tech = pl.get_tech_prog();
    int now_mat = pl.get_matan();
    int now_eng = pl.get_english();
    int now_labs = pl.get_labs();
    dec.Day(1, pl);
    EXPECT_TRUE(pl.get_matan() >= now_mat && pl.get_tech_prog() == now_tech && pl.get_english() == now_eng && pl.get_labs() == now_labs);
}

TEST(Labs, Decorator) {
    Decorator dec;
    Player pl = hand_create();
    int now_tech = pl.get_tech_prog();
    int now_mat = pl.get_matan();
    int now_eng = pl.get_english();
    int now_labs = pl.get_labs();
    dec.Day(4, pl);
    EXPECT_TRUE(pl.get_matan() == now_mat && pl.get_tech_prog() == now_tech && pl.get_english() == now_eng && pl.get_labs() >= now_labs);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
