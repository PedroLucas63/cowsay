#include <string>
#include <iostream>
#include "fstring.hpp"

#ifndef CREATURE_HPP_
#define CREATURE_HPP_

constexpr char* THOUGHTS { "/" };
constexpr char* FLIP_THOUGHTS { "\\" };
constexpr char* TAG_THOUGHTS { "$thoughts" };
constexpr char* TAG_EYES { "$eyes" };
constexpr char* TAG_TONGUE { "$tongue" };

class Creature {
public:
Creature(std::string body_, std::string eyes_, std::string tongue_, bool flip_);
void draw();
private:
std::string body;
std::string eyes;
std::string tongue;
bool flip;
std::string creature;

void replaces();
};

#endif // CREATURE_HPP_