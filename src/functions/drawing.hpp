#include "utils.hpp"
#include "billboard.hpp"
#include "creature.hpp"
#include <fstream>
#include <string> 

#ifndef DRAWING_HPP_
#define DRAWING_HPP_

constexpr char* INIT_COMMENTS { "##" };
constexpr char* INIT_CREATURE { "$the_creature = <<EOC;" };
constexpr char* END_CREATURE { "EOC" };

void draw(BillboardConfigs billboard_configs, CreatureConfigs creature_configs, bool flip);
std::string getCreature(std::string local);
void selectMood(CreatureConfigs& creature_configs);

#endif // DRAWING_HPP_