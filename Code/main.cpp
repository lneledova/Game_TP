#include "header.h"



int main() {
    std::cout << "Здравствуй, страждущий! Да начнётся твоё увлекательное (или не очень)\n"
            "путешествие по физтеху. Начнем с тебя.\n";
    std::string gender;
    int motivation;
    int abilities;
    what_gender(gender);
    what_motivation(motivation);
    what_abilities(abilities);
    std::cout << std::endl;

    Application application(gender, motivation, abilities);
    Player player = application.make_player();

    std::cout << "Итак, да начнутся Голодные игры! Ой, точнее твой первый семестр,\n"
                 "голодным он пока не должен быть, стипа какая-то есть.\n"
                 "У тебя есть 30 дней, чтобы подготовиться к сессии,\n"
                 "ты спросишь, почему всего месяц? Потому что ботать надо начинать,\n"
                 "когда выпадет снег, а выпал он за месяц до сессии.\n"
                 "Но небольшая подсказка - ночей тоже 30.\n"
                 "Что же делать?\n"
                 "Тебе будут доступные разные действия каждый день,\n"
                 "построй свою стратегию и посмотрим, насколько она\n"
                 "будет выигрышной.\n"
                 "Удачи!\n";
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
        std::cout << "Cамое интересное:\n"
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


    return 0;
}
