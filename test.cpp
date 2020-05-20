#include "Code/header.h"
#include "Code/Application.cpp"
#include "Code/Builder.cpp"
#include "Code/Director.cpp"
#include "Code/Player.cpp"
#include "Code/Decorator.cpp"
#include "Code/Exam.cpp"
#include "gtest/gtest.h"



Player hand_create() {
    Player a;
    a.set_motivation(7);
    a.set_abilities(6);
    return a;
}

Player hand_exam() {
    Player b;
    b.set_motivation(5);
    b.set_abilities(6);
    b.set_matan(8);
    b.set_labs(9);
    b.set_english(8);
    b.set_tech_prog(10);
    return b;
}

bool IsEqual(Player a, Player b) {
    if (a.get_abilities() == b.get_abilities() && a.get_motivation() == b.get_motivation()) {
        return true;
    }
    return false;
}


TEST(Create, Player) {
    Application a(7, 6);
    EXPECT_TRUE(IsEqual(a.make_player(), hand_create()));
}



TEST(Full, Decorator) {
    Decorator dec;
    Player pl = hand_create();
    int nowdays = pl.get_days() + 1;
    pl.change_matan(10);
    dec.Day(1, pl);
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

TEST(Matan, Exam) {
    Player pl = hand_exam();
    Exam_matan ex_mat;
    int now_tech = pl.get_tech_prog();
    int now_eng = pl.get_english();
    int now_labs = pl.get_labs();
    ex_mat.set_examiner();
    ex_mat.get_score(pl);
    EXPECT_TRUE(pl.get_tech_prog() == now_tech && pl.get_english() == now_eng && pl.get_labs() == now_labs);
}

TEST(Labs, Exam) {
    Player pl = hand_exam();
    Exam_labs ex_lab;
    int now_tech = pl.get_tech_prog();
    int now_eng = pl.get_english();
    int now_mat = pl.get_matan();
    ex_lab.set_examiner();
    ex_lab.get_score(pl);
    EXPECT_TRUE(pl.get_matan() == now_mat && pl.get_tech_prog() == now_tech && pl.get_english() == now_eng);
}

TEST(English, Exam) {
    Player pl = hand_exam();
    Exam_english ex_eng;
    int now_tech = pl.get_tech_prog();
    int now_labs = pl.get_labs();
    int now_mat = pl.get_matan();
    ex_eng.start_exam(pl);
    ex_eng.set_examiner();
    ex_eng.get_score(pl);
    EXPECT_TRUE(pl.get_matan() == now_mat && pl.get_tech_prog() == now_tech && pl.get_labs() == now_labs);
}

TEST(Tech, Exam) {
    Player pl = hand_exam();
    Exam_tech ex_tech;
    int now_eng = pl.get_english();
    int now_labs = pl.get_labs();
    int now_mat = pl.get_matan();
    ex_tech.set_examiner();
    ex_tech.get_score(pl);
    EXPECT_TRUE(pl.get_matan() == now_mat && pl.get_english() == now_eng && pl.get_labs() == now_labs);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
