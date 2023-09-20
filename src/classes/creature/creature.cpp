/**
 * @file creature.fpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation file for the Creature class.
 * @version 0.1
 * @date 2023-09-20
 *
 * This file contains the implementation of the Creature class, which represents
 * a creature with customizable features including body, eyes, and tongue. The
 * class provides methods to draw the creature and replace special directives
 * within its design.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "creature.hpp"

// Constructor for the Creature class.
Creature::Creature(
  std::string body_, std::string eyes_, std::string tongue_, bool flip_) {
   body = body_;
   eyes = eyes_;
   tongue = tongue_;
   flip = flip_;
}

// Draw the creature's design, optionally flipping it.
void Creature::draw() {
   replaceDirectives();

   if (!flip) {
      std::cout << creature;
   } else {
      std::vector<std::string> lines { fos::split(creature, "\n") };
      for (std::string line : lines) {
         std::cout << fos::reverse(line) << '\n';
      }
   }
}

// Replace special directives within the creature's design.
void Creature::replaceDirectives() {
   creature = fos::replace(body, TAG_THOUGHTS, THOUGHTS);
   creature = fos::replace(creature, TAG_EYES, eyes);
   creature = fos::replace(creature, TAG_TONGUE, tongue);

   creature = fos::completeLines(creature) + "\n";

   if (flip) {
      creature = fos::invertCharacters(creature);
   }
}
