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
    std::cout << "Если ты задаешься вопросом, зачем нам это знать - да незачем\n"
                 "Тут все равны вне зависимости от пола\n";
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

void days_while_sem(Player& player) {
    Decorator decorator;
    for (int i = 0; i < player.get_days(); ++i) {
        if (player.get_motivation() < 2) {
            std::cout << "Сегодня твой настрой ужасен, вот-вот кокнешься, учти это!\n";
        }
        std::cout << "Тебе доступные такие действия:\n";

        if (player.get_matan() < 10) {
            std::cout << "Побороться с матаном - клавиша 1\n";
        }
        if (player.get_english() < 10) {
            std::cout << "Сходить на английский - надо же как-то БРС получать.. - клавиша 2\n";
        }
        if (player.get_tech_prog() < 10) {
            std::cout << "Занятся очередным техническим заданием по ТП (не суйся - сожрет, но всё-таки надо) - клавиша 3\n";
        }
        if (player.get_labs() < 10) {
            std::cout << "Отправиться в лабораторию и погрязнуть в погрешностях и несходящихся числах - клавиша 4\n";
        }
        std::cout << "Самое интересное:\n"
                     "Поболтаться по кампусу, авось что нужное найдешь - клавиша 5\n"
                     "Выпить кофе в семёрке - клавиша 6\n"
                     "Занятся каким-нибудь еще интересным тебе делом - клавиша 7\n";
        std::cout << "Также ты можешь посмотреть свой прогресс в зачетке - клавиша 8\n";
        int what_want;
        std::cin >> what_want;
        while (what_want < 1 || what_want > 8) {
            std::cout << "Вроде на физтех поступил, а читаешь плохо.. Введи корректно!\n";
            std::cin >> what_want;
        }
        if (what_want == 8) {
            player.see_development();
            std::cout << '\n' << '\n';
            ++player.get_days();
            continue;
        }
        decorator.Day(what_want, player);
        std::cout << '\n' << '\n';
    }
}

bool session(Player& player) {
    std::cout << "Итак, начнем с технологий программирования\n";
    Exam_tech e_tech;
    if (e_tech.start_exam(player)) {
        e_tech.set_examiner();
        if (!e_tech.get_score(player)) {
            return false;
        }
    }
    std::cout << "Далee на очереди английский\n";
    Exam_english e_eng;
    e_eng.start_exam(player);
    e_eng.set_examiner();
    e_eng.get_score(player);
    std::cout << "Мы подходим к самому вкусному - матан\n";
    Exam_matan e_mat;
    e_mat.start_exam(player);
    e_mat.set_examiner();
    if (!e_mat.get_score(player)) {
        return false;
    }
    std::cout << "Финишная прямая, заключительный экзамен - физика\n";
    Exam_labs e_lab;
    e_lab.start_exam(player);
    e_lab.set_examiner();
    return e_lab.get_score(player);
}