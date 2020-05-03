#include "header.h"


void Decorator::Day (int what_action, Player& player) {
    if (what_action == 1) {
        Day_matan(player);
    }
    if (what_action == 2) {
        Day_english(player);
    }
    if (what_action == 3) {
        Day_tech_prog(player);
    }
    if (what_action == 4) {
        Day_labs(player);
    }
    if (what_action == 5) {
        Day_walk(player);
    }
    if (what_action == 6) {
        Day_coffee(player);
    }
    if (what_action == 7) {
        Chill_day(player);
    }
};

void Decorator::Day_matan(Player& player) {
    if (player.get_matan() == 10) {
        std::cout << "И куда больше тебе ботать матан...\n"
                     "Можешь попробовать выбрать еще что-то\n";
        ++player.get_days();
        return;
    }
    int random = rand() % 2;
    if (player.get_motivation() > 6) {
        std::cout << "Отличный день для бота!\n" << "Ты получаешь: " << (int) 4 * player.get_abilities() / 10 << " баллов\n";
        player.change_matan(4 * player.get_abilities() / 7);
        player.change_motivation(1);
    } else if (random == 0) {
        std::cout << "Рутинный день\n" << "Ты получаешь: " << (int) 3 * player.get_abilities() / 7 << " баллов\n";
        player.change_matan(3 * player.get_abilities() / 7);
    } else {
        std::cout << "Сегодня не твой день, да и тема заковыристая, но не получилось сегодня - получится потом\n";
    }
    player.change_motivation(-1);
    if (player.get_matan() == 10) {
        player.change_abilities(2);
        std::cout << "Молодец, десятка по матану, это сильно!\n";
    }
}

void Decorator::Day_labs(Player& player) {
    if (player.get_labs() == 10) {
        std::cout << "Лабы кончились...\n"
                     "Можешь попробовать выбрать еще что-то\n";
        ++player.get_days();
        return;
    }
    int random = rand() % 2;
    if (player.get_motivation() > 6) {
        std::cout << "Да у тебя руки из правильного места, даже всё сошлось!\n" << "Ты получаешь: " << (int) 4 * player.get_abilities() / 10 << " баллов\n";
        player.change_labs(4 * player.get_abilities() / 7);
        player.change_motivation(1);
    } else if (random == 0) {
        std::cout << "Ну, как обычно, тут приписать нолик, там убрать и получится приличное число.\n" << "Ты получаешь: " << (int) 3 * player.get_abilities() / 7 << " баллов\n";
        player.change_labs(3 * player.get_abilities() / 7);
    } else {
        std::cout << "Сегодня не твой день, установка взорвалась, до свидания. Попробуешь потом еще.\n";
    }
    if (player.get_labs() == 10) {
        player.change_abilities(2);
        std::cout << "В этом семестре развлечения с физическими установками для тебя закончены, 10 получил!\n";
    }
    player.change_motivation(-1);
}

void Decorator::Day_english(Player& player) {
    if (player.get_english() == 10) {
        std::cout << "У тебя всё хорошо? Итак уже 10 по английскому... Может тебе на лингвистический?\n"
                     "Можешь попробовать выбрать еще что-то\n";
        ++player.get_days();
        return;
    }
    int random = rand() % 2;
    if (player.get_motivation() > 6) {
        std::cout << "У англичанки хорошее настроение!\n" << "Ты получаешь: " << (int) 5 * player.get_abilities() / 10 << " баллов\n";
        player.change_english(5 * player.get_abilities() / 7);
        player.change_motivation(1);
    } else if (random == 0) {
        std::cout << "За окном серо, уныло, но баллы за сегодня ты всё-таки получил.\n" << "Ты получаешь: " << (int) 3 * player.get_abilities() / 7 << " баллов\n";
        player.change_english(3 * player.get_abilities() / 7);
    } else {
        std::cout << "Походу ты уснул на английском.. Сочувствую.\n";
    }
    if (random == 0 || player.get_motivation() > 6) {
        int random_sub = rand() % 2;
        std::cout << "Но не заниматься же на английском только английским...\n";
        if (random_sub == 0) {
            std::cout << "Сегодня ты соскучился по ТП и получаешь 1 балл по нему\n";
            player.change_tech_prog(1);
        }
        if (random_sub == 1) {
            std::cout << "Раз уже занятся нечем пообрабатывал пару графиков для лаб и получаешь 1 балл по ним\n";
            player.change_labs(1);
        }
    }
    player.change_motivation(-1);
    if (player.get_english() == 10) {
        player.change_abilities(2);
        std::cout << "Ну все, в этом семестре с английским покончено, десять есть!\n";
    }
}

void Decorator::Day_tech_prog(Player& player) {
    if (player.get_tech_prog() == 10) {
        std::cout << "Какой-то тs бешеный Фивт, но, прости, задания кончились.\n"
                     "Можешь попробовать выбрать еще что-то\n";
        ++player.get_days();
        return;
    }
    int random = rand() % 4;
    if (player.get_motivation() > 6 && random > 1) {
        std::cout << "Ну сегодня тебе очень повезло, быстро наткнулся на нужный сайт!\n" <<
        "Ты получаешь: " << (int) 3 * player.get_abilities() / 7 << " баллов\n";
        player.change_motivation(1);
        player.change_tech_prog(3 * player.get_abilities() / 7);
    } else if (random == 0) {
        std::cout << "Даже вторая страница гугла на английском не помогла.. А уже середина ночи, попытайся ещё!\n";

    } else {
        if (random == 1) {
            std::cout << "Через непонятно что всё-таки получил рабочие файлы и даже зачли!\n" <<
                      "Ты получаешь: " << (int) 3 * player.get_abilities() / 7 << " баллов\n";
        } else if (random == 2) {
            std::cout << "Добрый дядя второкур подкинул идей, что делать.\n" <<
                      "Ты получаешь: " << (int) 3 * player.get_abilities() / 7 << " баллов\n";
        } else if (random == 3) {
            std::cout << "Твой любимый одногруппник уже сделал это задание и тебе помог.\n" <<
                      "Ты получаешь: " << (int) 3 * player.get_abilities() / 7 << " баллов\n";
        }
        player.change_tech_prog(3 * player.get_abilities() / 7);
    }
    player.change_motivation(-1);
    if (player.get_tech_prog() == 10) {
        player.change_abilities(2);
        std::cout << "Добился высшего былла по техническому программированию, уважаемо!\n";
    }
}

void Decorator::Chill_day(Player& player) {
    std::cout << "Твои жизненные силы увеличились, и ты снова готов ботать!\n";
    if (!rand() % 4) {
        std::cout << "О, да ты так отдохнул, что готов ботать всю ночь!\n";
        ++player.get_days();
    }
    player.change_motivation(5);
}

void Decorator::Day_coffee(Player& player) {
    std::cout << "Мотивация ботать увеличилась, может и производительность тоже..\n";
    if (rand() % 2) {
        std::cout << "В кофе будто энергетик подмешали - ночью будет весело, чем займёшься?\n";
        ++player.get_days();
    }
    player.change_motivation(4);
}

void Decorator::Day_walk(Player& player) {
    std::cout << "Посмотрим, куда же ты попадешь сегодня..\n";
    int place = rand() % 4;
    int random = rand() & 2;
    if (place == 0 && player.get_labs() < 6 && random) {
        std::cout << "В лабораторном корпусе ты встретил своего лабника, которому не сдал последнуюю работу\n"
                     "Он предложил сдать сейчас, согласен?\n"
                     "Напиши 1, если да;\n"
                     "2 - нет\n";
        int yes_no;
        std::cin >> yes_no;
        if (yes_no == 1) {
            player.change_motivation(2);
            Day_labs(player);
            return;
        }
    } else if (place == 0) {
        std::cout << "Встретил в лабораторном корпусе своего знакомого, который подсказал, где найти можно найти\n"
                     "сделанные лабы по физике. Получаешь +1 лабам (ну или ничего, если ты такой, что сам всё сделал)\n";
        player.change_labs(1);
    }
    if (place == 1 && player.get_matan() < 5 && random) {
        std::cout << "В главном корпусе ты встретил семинариста по матану, который предложил тебе переписать последнюю кр по матану.\n"
                     "Согласен?\n"
                     "Напиши 1, если да;\n"
                     "2 - нет\n";
        int yes_no;
        std::cin >> yes_no;
        if (yes_no == 1) {
            player.change_motivation(2);
            Day_matan(player);
            return;
        }
    } else if (place == 1) {
        std::cout << "На подоконнике заметил странную тетрадь...\n"
                     "Написано: для будущих поколений.\n"
                     "А в ней сделанное дз по матану.\n"
                     "Если ты еще его не сдал, то получаешь +1 балл по матану!\n";
        player.change_matan(1);
    }
    if (place == 2) {
        std::cout << "Вы попали на нк и у вас села батарейка..(Для полного погружения можно включить\n"
                     "песню <<Батарейка>>.И да, это на всю ночь\n";
        player.change_motivation(3);
    }
    if (place == 3) {
        std::cout << "Что-то есть хочется, а вот как раз и шаурмечная рядом\n"
                     "Получаешь заряд сил и плюс к мотивации\n ";
        player.change_motivation(3);
    }
}