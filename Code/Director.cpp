
#include "Director.h"

void Director::create_player(Builder& builder, string& gender, int motivation, int abilities) {
    builder.set_gender(gender);
    builder.set_motivation(motivation);
    builder.set_abilities(abilities);
}