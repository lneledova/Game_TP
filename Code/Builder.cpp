
#include "Builder.h"

void Builder::set_gender(string& gender) {
    p.set_gender(gender);
};

void Builder::set_motivation(int motivation) {
    p.set_motivation(motivation);
};

void Builder::set_abilities(int abilities) {
    p.set_abilities(abilities);
};

Player Builder::get_result() {
    return p;
}
