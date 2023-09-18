/**
 * @file utils.cpp
 * @brief Implementation file for useful settings used in multiple files.
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @version 0.1
 * @date 2023-09-15
 *
 * This file contains definitions of data structures and useful settings that
 * are shared across multiple files in the project.
 *
 * @copyright Copyright (c) 2023
 */

#include <string>
#include "fstring.hpp"

#ifndef UTILS_HPP_
#define UTILS_HPP_

enum Moods {
   DEFAULT,
   BORG,
   DEAD,
   GREEDY,
   PARANOIA,
   STONED,
   TIRED,
   WIRED,
   YOUNG,
};

constexpr bool DEFAULT_REGULAR { false };
constexpr size_t DEFAULT_COLUMN_SIZE { 40 };
constexpr fos::align DEFAULT_ALIGN { fos::align::left };

constexpr char* DEFAULT_CREATURE { "./data/default.cow" };
constexpr Moods DEFAULT_MOOD { Moods::DEFAULT };

/**
 * @brief Structure that defines configurations for a billboard
 *
 * A billboard is a graphical representation of text with formatting options
 */
struct BillboardConfigs {
   std::string text; ///< The text to be displayed on the billboard
   bool regular { DEFAULT_REGULAR }; ///< Specifies whether the text is regular (true) or special
                 ///< (false)
   size_t column_size { DEFAULT_COLUMN_SIZE }; ///< The column limit for automatic line breaks
   fos::align align { DEFAULT_ALIGN }; ///< The alignment of the text (e.g., 'l' for left, 'c' for
               ///< centered)
};

/**
 * @brief Structure that defines configurations for a creature
 *
 * This structure contains information about the creature, its mood, and facial
 * features
 */
struct CreatureConfigs {
   std::string creature { DEFAULT_CREATURE }; ///< The file of the creature
   Moods mood { DEFAULT_MOOD }; ///< The mood of the creature (e.g., 'b' for borg, 'd' for dead).
   std::string eyes; ///< The appearance of the creature's eyes
   std::string tongue; ///< The appearance of the creature's tongue
};

#endif // UTILS_HPP_
