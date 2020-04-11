#include "header.h"



int main() {
    cout << "Пока я умею только создавать персонажа с разными характеристиками :)\n";
    cout << endl;
    cout << "Здравствуй, страждущий! Да начнётся твоё увлекательное (или не очень)\n"
            "путешествие по физтеху. Начнем с тебя.\n";
    string gender;
    int motivation;
    int abilities;
    what_gender(gender);
    what_motivation(motivation);
    what_abilities(abilities);
    cout << endl;
    cout << "На этом всё.\n";

    Application application(gender, motivation, abilities);
    Player player = application.make_player();


    return 0;
}
