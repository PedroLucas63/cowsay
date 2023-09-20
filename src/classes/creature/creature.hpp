/**
 * @file creature.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file for the Creature class, which represents a creature with
 * customizable features.
 * @version 0.1
 * @date 2023-09-20
 *
 * This file defines the Creature class, which allows you to create and draw
 * creatures with customizable body, eyes, and tongue. The class provides
 * methods to draw the creature and replace special directives within the
 * creature's design
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "fstring.hpp"
#include <iostream>
#include <string>

#ifndef CREATURE_HPP_
#define CREATURE_HPP_

constexpr const char* THOUGHTS {
   "\\"
}; ///< The character representing thoughts in the creature's design
constexpr const char* TAG_THOUGHTS {
   "$thoughts"
}; ///< The tag for thoughts in the creature's design
constexpr const char* TAG_EYES {
   "$eyes"
}; ///< The tag for eyes in the creature's design
constexpr const char* TAG_TONGUE {
   "$tongue"
}; ///< The tag for tongue in the creature's design

class Creature {
   public:
   /**
    * @brief Construct a new Creature object
    *
    * @param body_ The body of the creature
    * @param eyes_ The eyes of the creature
    * @param tongue_ The tongue of the creature
    * @param flip_ Indicates whether to flip the creature's design
    */
   Creature(
     std::string body_, std::string eyes_, std::string tongue_, bool flip_);


   /**
    * @brief Get the complete creature's design.
    *
    * @return A string representing the creature's design.
    */
   std::string getCreature() const;

   /**
    * @brief Draw the creature's design
    */
   void draw();

   private:
   std::string body; ///< The body design of the creature
   std::string eyes; ///< The eyes design of the creature
   std::string tongue; ///< The tongue design of the creature
   bool flip; ///< Indicates whether the creature's design should be flipped
   std::string creature; ///< The complete creature's design

   /**
    * @brief Replace special directives within the creature's design and
    * optionally invert the design.
    *
    * This method replaces special directives like "$thoughts", "$eyes", and
    * "$tongue" in the creature's design with their corresponding values. If the
    * 'flip' flag is set to true, the design is also inverted.
    */
   void defineDesign();
};

#endif // CREATURE_HPP_
