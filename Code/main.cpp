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

    Application application(motivation, abilities);
    Player player = application.make_player();


    std::cout << "Итак, да начнутся Голодные игры! Ой, точнее твой первый семестр,\n"
                 "голодным он пока не должен быть, стипа какая-то есть.\n"
                 "У тебя есть 24 дня, чтобы подготовиться к сессии,\n"
                 "ты спросишь, почему всего месяц? Потому что ботать надо начинать,\n"
                 "когда выпадет снег, а выпал он за месяц до сессии.\n"
                 "Но небольшая подсказка - ночей тоже 24.\n"
                 "Что же делать?\n"
                 "Тебе будут доступные разные действия каждый день,\n"
                 "построй свою стратегию и посмотрим, насколько она\n"
                 "будет выигрышной.\n"
                 "Удачи!\n";
    days_while_sem(player);


    std::cout << "Ну всё, дедлайны по всем контрольным, заданиям прошли. Пора смотреть, что наработал\n";
    player.see_development();

    if (session(player)) {
        std::cout << "Молодец, ты прошел целый семестр вместе с сессией. Победа!\n"
                     "Твои итоговые оценки:\n";
        std::cout << "Технологии программирования:" << player.get_tech_prog() << std::endl;
        std::cout << "Английский:" << player.get_english() << std::endl;
        std::cout << "Физика:" << player.get_labs() << std::endl;
        std::cout << "Математический анализ:" << player.get_matan() << std::endl;
    } else {
        std::cout << "Пипец ежику.. Ну ничего, в следующий раз получится!\n";
    }

    return 0;
}
