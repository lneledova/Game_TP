
#include "Exam.h"

void Exam::set_examiner() {
    int rand = random() % 3;
    if (rand == 0) {
        examiner_ = "fucker";
    }
    if (rand == 1) {
        examiner_ = "normal";
    }
    if (rand == 2) {
        examiner_ = "light";
    }
}

bool Exam_tech::start_exam(Player& player) {
    if (player.get_tech_prog()  < 3) {
        return true;
    }
    std::cout << "У тебя есть возможность получить автомат по тому, что ты наработал в семестре\n"
                 "или испытать судьбу на экзамене.\n"
                 "Введи 0 - если не хочешь париться или 1 - если нечем заняться\n";
    int now;
    std::cin >> now;
    while (now != 1 && now != 0) {
        std::cout << "Семестр прошел, а читать не научился..\n"
                     "Вводи снова\n"
                     "0 - если не хочешь париться или 1 - если нечем заняться\n";
        std::cin >> now;
    }
    if (rand() % 4 && !now) {
        std::cout << "Произошло обнуление, так что никакого автомата.\n";
        return true;
    }
    return now;
}

bool Exam_english::start_exam(Player& player) {
    if (player.get_english() < 4) {
        std::cout << "Ты вообще что-то делал в семестре?\n";
    }
    return true;
}

bool Exam_matan::start_exam(Player& player) {
    return true;
}

bool Exam_labs::start_exam(Player& player) {
    if (player.get_labs() < 3) {
        std::cout << "В течение семестра ты работал очень плохо, так что экзамен будет в ужесточенной форме\n";
    }
    return true;
}

bool Exam_tech::get_score(Player& player) {
    if (examiner_ == "fucker") {
        std::cout << "Это была тяжелая сдача\n";
        if (player.get_tech_prog() == 2) {
            std::cout << "Но на уд ты наскреб!\n"
                         "Получай 3\n";
            player.set_tech_prog(3);
        }
        if (player.get_tech_prog() < 2) {
            std::cout << "Не повезло - пересда\n";
            return false;
        }
        if (player.get_tech_prog() > 2){
            std::cout << "Ну так уж и быть получил свой " << (3 + player.get_tech_prog() / 5) << '\n';
            player.set_tech_prog(3 + player.get_tech_prog() / 5);
        }
    }
    if (examiner_ == "normal") {
        if (player.get_tech_prog() < 3) {
            std::cout << "Ну на уд ты наскреб!\n"
                         "Получай 3\n";
            player.set_tech_prog(3);
        }
        if (player.get_tech_prog() > 2){
            std::cout << "Ну так уж и быть получил свой " << (3 + player.get_tech_prog() / 4) << '\n';
            player.set_tech_prog((3 + player.get_tech_prog() / 4));
        }
    }
    if (examiner_ == "light") {
        if (player.get_tech_prog() < 3) {
            std::cout << "Совсем халява, пацанский хор(5) в кармане!\n";
            player.set_tech_prog(5);
        }
        if (player.get_tech_prog() > 2){
            std::cout << "Получай " << (5 + player.get_tech_prog() / 4) << '\n';
            player.set_tech_prog((5 + player.get_tech_prog() / 4));
        }
    }
    return true;
}

bool Exam_english::get_score(Player& player) {
    std::cout << "Это же английский..\n";
    if (player.get_english() == 10) {
        std::cout << "Так что держи свою десятку\n";
        player.set_english(10);
    } else {
        std::cout << "Так что держи девятку\n";
        player.set_english(9);
    }
    return true;
}

bool Exam_matan::get_score(Player& player) {
    if (examiner_ == "fucker") {
        std::cout << "Ты попался к Ивановой - трепещи и бойся\n";
        if (player.get_matan() == 2) {
            std::cout << "На уд ты наскреб!\n"
                         "Получай 3\n";
            player.set_matan(3);
        }
        if (player.get_matan() < 2) {
            std::cout << "Не повезло - пересда\n";
            return false;
        }
        if (player.get_matan() > 2){
            std::cout << "Ну так уж и быть получил свой " << (3 + player.get_matan() / 3) << '\n';
            player.set_matan(3 + player.get_matan() / 3);
        }
    }
    if (examiner_ == "normal") {
        std::cout << "Ну Лукаш это поприятнее, чем какой-то факер\n";
        if (player.get_matan() < 3) {
            std::cout << "Ну на уд ты наскреб!\n"
                         "Получай 3\n";
            player.set_matan(3);
        }
        if (player.get_matan() > 2){
            std::cout << "Ну так уж и быть получил свой " << (4 + player.get_matan() / 3) << '\n';
            player.set_matan((4 + player.get_matan() / 4));
        }
    }
    if (examiner_ == "light") {
        if (player.get_matan() < 3) {
            std::cout << "Совсем халява, пацанский хор(5) в кармане!\n";
            player.set_matan(5);
        }
        if (player.get_matan() > 2){
            std::cout << "Получай " << (5 + player.get_matan() / 2) << '\n';
            player.set_matan((5 + player.get_matan() / 2));
        }
    }
    return true;
}

bool Exam_labs::get_score(Player& player) {
    if (examiner_ == "fucker") {
        std::cout << "Твою зачетку берет Светличный.. Искра, буря, безумие\n";
        if (player.get_labs() == 2) {
            std::cout << "Огромный успех - получить уд3!\n";
            player.set_labs(3);
        }
        if (player.get_labs() < 2) {
            std::cout << "Ну это бан - до свидания\n";
            return false;
        }
        if (player.get_labs() > 2) {
            std::cout << "Ну так уж и быть получил свой " << (3 + player.get_labs() / 5) << '\n';
            player.set_labs(3 + player.get_labs() / 5);
        }
    }
    if (examiner_ == "normal") {
        if (player.get_labs() < 3) {
            std::cout << "Ну на уд ты наскреб!\n"
                         "Получай 3\n";
            player.set_labs(3);
        }
        if (player.get_labs() > 2){
            std::cout << "Ну так уж и быть получил свой " << (4 + player.get_labs() / 4) << '\n';
            player.set_labs((4 + player.get_labs() / 4));
        }
    }
    if (examiner_ == "light") {
        std::cout << "Ба, да ты же у Овчинкина и ходил на все его лекции!\n";
        if (player.get_labs() < 3) {
            std::cout << "Он вспомнил, что ты сидел на первой парте и даже порой говорил что-то умное - пацанский хор(5) в кармане!\n";
            player.set_labs(5);
        }
        if (player.get_labs() > 2){
            std::cout << "На все вопросы отвечал, что так повелел боженька..\n";
            std::cout << "Получай " << (5 + player.get_labs()) % 10 << '\n';
            std::cout << "И перевод в МИФИ..\n"
                         "Шутка!\n";
            player.set_labs((5 + player.get_labs()) % 10);
        }
    }
    return true;
}