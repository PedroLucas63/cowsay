#include "drawing.hpp"

void draw(BillboardConfigs billboard_configs, CreatureConfigs creature_configs, bool flip) {
   Billboard billboard { billboard_configs.text, billboard_configs.regular, billboard_configs.column_size, billboard_configs.align };
   billboard.draw();

   std::string creature { getCreature(creature_configs.creature) };
   selectMood(creature_configs);
   
   Creature cre { creature, creature_configs.eyes, creature_configs.tongue, flip };
   cre.draw();
}

std::string getCreature(std::string local) {
   std::ifstream file;
   file.open(local);

   if (!file.is_open()) {
      file.open(DEFAULT_CREATURE);
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
      } else {
         creature += line + '\n';
      }
   }

   return creature;
}

void selectMood(CreatureConfigs& creature_configs) {
   if (creature_configs.eyes.empty()) {
   creature_configs.eyes = "00";
   }

      if (creature_configs.tongue.empty()) {
   creature_configs.tongue = " U";
   }
}