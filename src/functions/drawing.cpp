/**
 * @file drawing.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation file for drawing functions.
 * @version 0.1
 * @date 2023-09-20
 *
 * This file contains the implementation of drawing functions, including the
 * main drawing function that creates graphical displays with customizable
 * settings. It also contains functions for retrieving the creature's design
 * from a file and selecting the creature's mood.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "drawing.hpp" // Include the drawing functions header.

// Main drawing function that creates graphical displays.
void draw(BillboardConfigs billboard_configs, CreatureConfigs creature_configs,
  bool flip) {
   std::string creature_str { getCreatureFile(creature_configs.creature) };
   selectMood(creature_configs);

   Creature creature {
      creature_str, creature_configs.eyes, creature_configs.tongue, flip
   };

   size_t width_offset { flip ? fos::longestLine(creature.getCreature()) : 0 };
   Billboard billboard { billboard_configs.text,
      billboard_configs.regular,
      billboard_configs.column_size,
      billboard_configs.align,
      width_offset };

   billboard.drawBillboard();
   creature.drawCreature();
}

// Function to retrieve the creature's design from a file.
std::string getCreatureFile(std::string local) {
   std::ifstream file;
   file.open(local);

   if (!file.is_open()) {
      return DEFAULT_CREATURE;
   }

   std::string creature;
   std::string line;
   std::string init_comments { INIT_COMMENTS };
   bool get_creature { false };

   while (std::getline(file, line)) {
      if (fos::subString(line, init_comments.size()) == INIT_COMMENTS) {
         continue;
      } else if (line == INIT_CREATURE) {
         get_creature = true;
      } else if (line == END_CREATURE) {
         get_creature = false;
      } else if (get_creature) {
         creature += line + '\n';
      }
   }

   return creature;
}

// Function to select the creature's mood based on configurations.
void selectMood(CreatureConfigs& creature_configs) {
   if (creature_configs.mood == DEFAULT) {
      if (creature_configs.eyes.empty()) {
         creature_configs.eyes = "oo";
      }
      if (creature_configs.tongue.empty()) {
         creature_configs.tongue = "  ";
      }
   } else if (creature_configs.mood == BORG) {
      creature_configs.eyes = "==";
      creature_configs.tongue = "  ";
   } else if (creature_configs.mood == DEAD) {
      creature_configs.eyes = "xx";
      creature_configs.tongue = " U";
   } else if (creature_configs.mood == GREEDY) {
      creature_configs.eyes = "$$";
      creature_configs.tongue = "  ";
   } else if (creature_configs.mood == PARANOIA) {
      creature_configs.eyes = "@@";
      creature_configs.tongue = "  ";
   } else if (creature_configs.mood == STONED) {
      creature_configs.eyes = "**";
      creature_configs.tongue = " U";
   } else if (creature_configs.mood == TIRED) {
      creature_configs.eyes = "--";
      creature_configs.tongue = "  ";
   } else if (creature_configs.mood == WIRED) {
      creature_configs.eyes = "OO";
      creature_configs.tongue = "  ";
   } else if (creature_configs.mood == YOUNG) {
      creature_configs.eyes = "..";
      creature_configs.tongue = "  ";
   }
}
