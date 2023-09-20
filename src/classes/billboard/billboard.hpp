/**
 * @file billboard.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file for the Billboard class, representing a graphical text
 * display.
 * @version 0.1
 * @date 2023-09-20
 *
 * This file defines the Billboard class, which allows you to create and draw
 * graphical text displays with customizable settings such as text content,
 * regular or special formatting, column size, alignment, and width offset.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "fstring.hpp"
#include <iostream>
#include <string>
#include <vector>

#ifndef BILLBOARD_HPP_
#define BILLBOARD_HPP_

class Billboard {
   public:
   /**
    * @brief Construct a new Billboard object with specified settings
    *
    * @param text_ The text to be displayed on the billboard
    * @param regular_ Specifies whether the text is regular (true) or special (false)
    * @param column_size_ The column limit for automatic line breaks
    * @param alignment_ The alignment of the text (e.g., 'l' for left, 'c' for centered)
    * @param width_offset_ The width offset for adjusting the display width
    */
   Billboard(std::string text_, bool regular_, size_t column_size_,
     fos::align alignment_, size_t width_offset_);

   /**
    * @brief Draw the graphical text display on the billboard
    */
   void drawBillboard();

   private:
   std::string text; ///< The text content to be displayed on the billboard
   bool regular; ///< Specifies whether the text is regular (true) or special (false)
   size_t column_size; ///< The column limit for automatic line breaks
   fos::align alignment; ///< The alignment of the text (e.g., 'l' for left, 'c' for centered)
   size_t width_offset; ///< The width offset for adjusting the display width

   /**
    * @brief Format and display the text on the billboard based on the specified settings
    */
   void formatText();
};

#endif // BILLBOARD_HPP_