#include "header.h"


void what_gender(std::string& gender) {
    std::cout << "Если твой пол - мужской напиши 'm', если женский - 'f'\n";
    char gen;
    std::cin >> gen;
    if (gen != 'm' && gen != 'f') {
        while (gen != 'm' && gen != 'f') {
            std::cout << "Ты ввел что-то не то." << std::endl;
            std::cout << "Если твой пол - мужской напиши 'm', если женский - 'f'\n";
            std::cin >> gen;
        }
    }
    if (gen == 'm') {
        gender = "male";
    } else {
        gender = "female";
    }
}

void what_motivation(int& motivation) {
    std::cout << "Так, а теперь давай что-то более личное.\n";
    std::cout << "Оцени по шкале от 1 до 10, насколько ты (твой персонаж) хочет на физтех, \n"
            "где 1 - родители заставили, а так я вообще поэт, а 10 - ходил на ДОД с 9 класса и мечтал\n"
            "об этом месте.\n";
    int mot;
    std::cin >> mot;
    if (mot > 10 || mot < 0) {
        while (mot > 10 || mot < 0) {
            std::cout << "Ты ввел что-то не то." << std::endl;
            std::cout << "Оцени по шкале от 1 до 10, насколько ты (твой персонаж) хочет на физтех, \n"
                    "где 1 - родители заставили, а так я вообще поэт, а 10 - ходил на ДОД с 9 класса и мечтал\n"
                    "об этом месте.\n";
            std::cin >> mot;
        }
    }
    motivation = mot;
}

void what_abilities(int& abilities) {
    std::cout << "А теперь завершающее.\n";
    std::cout << "Выбирай уровень сложности: вводи 'e' - easy, 'n' - normal и 'h' - hard.\n";
    char ab;
    std::cin >> ab;
    if (ab != 'e' && ab != 'n' && ab != 'h') {
        while (ab != 'e' && ab != 'n' && ab != 'h') {
            std::cout << "Ты ввел что-то не то." << std::endl;
            std::cout << "Выбирай уровень сложности: вводи 'e' - easy, 'n' - normal и 'h' - hard.\n";
            std::cin >> ab;
        }
    }
    if (ab == 'e') {
        abilities = 10;
        std::cout << "Да ты, видимо, смышленый малый, тебе будет проще.\n";
    } else if (ab == 'n') {
        abilities = 6;
        std::cout << "Классический физтех, но не расслабляйся, только будешь усердно ботать - справишься.\n";
    } else {
        abilities = 3;
        std::cout << "Ну что, через тернии к звёздам?\n";
    }
}