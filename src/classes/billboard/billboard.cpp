/**
 * @file billboard.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation file for the Billboard class.
 * @version 0.1
 * @date 2023-09-20
 *
 * This file contains the implementation of the Billboard class, which
 * represents a graphical text display with customizable settings such as text
 * content, regular or special formatting, column size, alignment, and width
 * offset.
 *
 * @copyright Copyright (c) 2023
 */

#include "billboard.hpp"

// Constructor for the Billboard class
Billboard::Billboard(std::string text_, bool regular_, size_t column_size_,
  fos::align alignment_, size_t width_offset_) {
   text = text_;
   regular = regular_;
   column_size = column_size_;
   alignment = alignment_;
   width_offset = width_offset_;

   formatText();
}

// Draw the graphical text display on the billboard
void Billboard::drawBillboard() {
   std::vector<std::string> lines { fos::split(text, "\n") };
   size_t max_line_size { fos::longestLine(text) };
   auto last { lines.end() - 1 };

   // Draw the top border of the billboard
   std::cout << fos::repeat(' ', width_offset) << ' '
             << fos::repeat('_', max_line_size + 2) << '\n';

   // Iterate through lines and draw the content
   for (auto line { lines.begin() }; line < lines.end(); ++line) {
      if (line == lines.begin() && line == last) {
         std::cout << fos::repeat(' ', width_offset) << "< " << *line << " >\n";
      } else if (line == lines.begin()) {
         std::cout << fos::repeat(' ', width_offset) << "/ " << *line
                   << " \\\n";
      } else if (line == last) {
         std::cout << fos::repeat(' ', width_offset) << "\\ " << *line
                   << " /\n";
      } else {
         std::cout << fos::repeat(' ', width_offset) << "| " << *line << " |\n";
      }
   }

   // Draw the bottom border of the billboard
   std::cout << fos::repeat(' ', width_offset) << ' '
             << fos::repeat('-', max_line_size + 2) << '\n';
}

// Format the text on the billboard based on the specified settings
void Billboard::formatText() {
   if (!regular) {
      text = fos::columnWrap(text, column_size);
      text = fos::alignment(text, column_size, alignment, ' ', true, true);
   }
}
