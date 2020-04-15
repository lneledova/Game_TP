#include "header.h"



int main() {
    std::cout << "Пока я умею только создавать персонажа с разными характеристиками :)\n";
    std::cout << std::endl;
    std::cout << "Здравствуй, страждущий! Да начнётся твоё увлекательное (или не очень)\n"
            "путешествие по физтеху. Начнем с тебя.\n";
    std::string gender;
    int motivation;
    int abilities;
    what_gender(gender);
    what_motivation(motivation);
    what_abilities(abilities);
    std::cout << std::endl;
    std::cout << "На этом всё.\n";

    Application application(gender, motivation, abilities);
    Player player = application.make_player();


    return 0;
}
