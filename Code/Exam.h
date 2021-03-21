#pragma once
#include "header.h"


class Exam {
protected:
    std::string examiner_ = "none";
public:
    virtual bool start_exam(Player& player) = 0;
    void set_examiner();
    virtual bool get_score(Player& player) = 0;
};

class Exam_tech : public Exam {
public:
    bool start_exam(Player& player) override;
    bool get_score(Player& player) override;
};

class Exam_labs : public Exam {
public:
    bool start_exam(Player& player) override;
    bool get_score(Player& player) override;
};

class Exam_matan : public Exam {
public:
    bool start_exam(Player& player) override;
    bool get_score(Player& player) override;
};

class Exam_english : public Exam {
public:
    bool start_exam(Player& player) override;
    bool get_score(Player& player) override;
};