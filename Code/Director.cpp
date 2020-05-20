
#include "Director.h"

void Director::create_player(Builder& builder, int motivation, int abilities) {
    builder.set_motivation(motivation);
    builder.set_abilities(abilities);
}