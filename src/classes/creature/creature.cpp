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
   defineDesign();
}

// Returns the representation of the creature
std::string Creature::getCreature() const {
   return creature;
}

// Draw the creature's design, optionally flipping it.
void Creature::drawCreature() {
   std::cout << creature;
}

// Replace special directives within the creature's design.
void Creature::defineDesign() {
   creature = fos::replace(body, TAG_THOUGHTS, THOUGHTS);
   creature = fos::replace(creature, TAG_EYES, eyes);
   creature = fos::replace(creature, TAG_TONGUE, tongue);

   if (flip) {
      creature = fos::completeLines(creature) + "\n";
      creature = fos::invertCharacters(creature);

      std::vector<std::string> lines { fos::split(creature, "\n") };

      for (size_t index { 0 }; index < lines.size(); ++index) {
         lines[index] = fos::rightTrim(fos::reverse(lines[index]));
      }

      creature = fos::concat(&lines.front(), &lines.back() + 1, "\n") + "\n";
   }
}
