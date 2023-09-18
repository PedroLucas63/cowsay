#include "billboard.hpp"

Billboard::Billboard(std::string text_, bool regular_, size_t column_size_, fos::align alignment_) {
   text = text_;
   regular = regular_;
   column_size = column_size_;
   alignment = alignment_;

   format();
}

void Billboard::draw() {
   std::vector<std::string> lines { fos::split(text, "\n") };
   size_t max_line_size { fos::longestLine(text) };
   auto last { lines.end() - 1 };

   std::cout << ' ' << fos::repeat('-', max_line_size + 2) << '\n';

   for (auto line { lines.begin() }; line < lines.end(); ++line) {
      if (line == lines.begin() && line == last) {
         std::cout << "< " << *line << " >\n";
      } else if (line == lines.begin()) {
         std::cout << "/ " << *line << " \\\n";
      } else if (line == last) {
         std::cout << "\\ " << *line << " /\n";
      } else {
         std::cout << "| " << *line << " |\n";
      }
   }

   std::cout << ' ' << fos::repeat('-', max_line_size + 2) << '\n';
}

void Billboard::format() {
   if (!regular) {
      text = fos::columnWrap(text, column_size);
      text = fos::justify(text, column_size, alignment, ' ', true, true);
   }
}