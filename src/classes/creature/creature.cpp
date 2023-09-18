#include "creature.hpp"

Creature::Creature(std::string body_, std::string eyes_, std::string tongue_, bool flip_) {
   body = body_;
   eyes = eyes_;
   tongue = tongue_;
   flip = flip_;

   replaces();
}

void Creature::draw() {
   std::cout << creature;
}

void Creature::replaces() {
   std::string thoughts { flip ? FLIP_THOUGHTS : THOUGHTS };
   creature = fos::replace(body, TAG_THOUGHTS, thoughts);
   creature = fos::replace(creature, TAG_EYES, eyes);
   creature = fos::replace(creature, TAG_TONGUE, tongue);
}
