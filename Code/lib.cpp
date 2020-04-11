#include "header.h"

void what_gender(string& gender) {
    cout << "Если твой пол - мужской напиши 'm', если женский - 'f'\n";
    char gen;
    cin >> gen;
    if (gen != 'm' && gen != 'f') {
        while (gen != 'm' && gen != 'f') {
            cout << "Ты ввел что-то не то." << endl;
            cout << "Если твой пол - мужской напиши 'm', если женский - 'f'\n";
            cin >> gen;
        }
    }
    if (gen == 'm') {
        gender = "male";
    } else {
        gender = "female";
    }
}

void what_motivation(int& motivation) {
    cout << "Так, а теперь давай что-то более личное.\n";
    cout << "Оцени по шкале от 1 до 10, насколько ты (твой персонаж) хочет на физтех, \n"
            "где 1 - родители заставили, а так я вообще поэт, а 10 - ходил на ДОД с 9 класса и мечтал\n"
            "об этом месте.\n";
    int mot;
    cin >> mot;
    if (mot > 10 || mot < 0) {
        while (mot > 10 || mot < 0) {
            cout << "Ты ввел что-то не то." << endl;
            cout << "Оцени по шкале от 1 до 10, насколько ты (твой персонаж) хочет на физтех, \n"
                    "где 1 - родители заставили, а так я вообще поэт, а 10 - ходил на ДОД с 9 класса и мечтал\n"
                    "об этом месте.\n";
            cin >> mot;
        }
    }
    motivation = mot;
}

void what_abilities(int& abilities) {
    cout << "А теперь завершающее.\n";
    cout << "Выбирай уровень сложности: вводи 'e' - easy, 'n' - normal и 'h' - hard.\n";
    char ab;
    cin >> ab;
    if (ab != 'e' && ab != 'n' && ab != 'h') {
        while (ab != 'e' && ab != 'n' && ab != 'h') {
            cout << "Ты ввел что-то не то." << endl;
            cout << "Выбирай уровень сложности: вводи 'e' - easy, 'n' - normal и 'h' - hard.\n";
            cin >> ab;
        }
    }
    if (ab == 'e') {
        abilities = 10;
        cout << "Да ты, видимо, смышленый малый, тебе будет проще.\n";
    } else if (ab == 'n') {
        abilities = 6;
        cout << "Классический физтех, но не расслабляйся, только будешь усердно ботать - справишься.\n";
    } else {
        abilities = 3;
        cout << "Ну что, через тернии к звёздам?\n";
    }
}