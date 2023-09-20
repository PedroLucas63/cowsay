/**
 * @file drawing.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file for the drawing functions.
 * @version 0.1
 * @date 2023-09-20
 *
 * This file defines functions related to drawing, including functions to create
 * graphical displays with customizable settings and select mood for a creature.
 * It also contains constants related to drawing initialization and creature
 * representation.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "billboard.hpp" // Include the Billboard class header
#include "creature.hpp" // Include the Creature class header
#include "utils.hpp" // Include utility functions and constants
#include <fstream> // Include file stream functionality
#include <string> // Include string manipulation functions

#ifndef DRAWING_HPP_ // Include guard to prevent multiple inclusions
#define DRAWING_HPP_

constexpr const char* INIT_COMMENTS { "##" }; ///< Initial marker for comments
constexpr const char* INIT_CREATURE {
   "$the_creature = <<EOC;"
}; ///< Initial marker for creature
constexpr const char* END_CREATURE { "EOC" }; ///< End marker for creature

/**
 * @brief Draw a graphical display with customizable settings
 *
 * This function takes BillboardConfigs and CreatureConfigs as input to create a
 * graphical display with the specified settings. The 'flip' parameter
 * determines whether to flip the creature's design.
 *
 * @param billboard_configs Configurations for the billboard display
 * @param creature_configs Configurations for the creature's appearance
 * @param flip Indicates whether to flip the creature's design
 */
void draw(BillboardConfigs billboard_configs, CreatureConfigs creature_configs,
  bool flip);

/**
 * @brief Retrieve the file content representing the creature's design
 *
 * This function retrieves the content of the file that represents the
 * creature's design based on the 'local' parameter.
 *
 * @param local The location of the creature's design file
 * @return A string containing the creature's design
 */
std::string getCreatureFile(std::string local);

/**
 * @brief Select a mood for the creature
 *
 * This function allows you to select a mood for the creature by modifying the
 * CreatureConfigs structure.
 *
 * @param creature_configs The configuration structure for the creature
 */
void selectMood(CreatureConfigs& creature_configs);

#endif // DRAWING_HPP_
