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

#ifndef UTILS_HPP_
#define UTILS_HPP_

/**
 * @brief Structure that defines configurations for a billboard
 *
 * A billboard is a graphical representation of text with formatting options
 */
struct BillboardConfigs {
   std::string text; ///< The text to be displayed on the billboard
   bool regular; ///< Specifies whether the text is regular (true) or special
                 ///< (false)
   int wrap_column; ///< The column limit for automatic line breaks
   char align; ///< The alignment of the text (e.g., 'l' for left, 'c' for
               ///< centered)
};

/**
 * @brief Structure that defines configurations for a creature
 *
 * This structure contains information about the creature, its mood, and facial
 * features
 */
struct CreatureConfigs {
   std::string creature; ///< The file of the creature
   char mood; ///< The mood of the creature (e.g., 'b' for borg, 'd' for dead).
   std::string eyes; ///< The appearance of the creature's eyes
   std::string tongue; ///< The appearance of the creature's tongue
};

#endif // UTILS_HPP_
