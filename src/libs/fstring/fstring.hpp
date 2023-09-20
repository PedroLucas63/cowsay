/**
 * @file fstring.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Definition of Text Formatting Functions
 * @version 1.0
 * @date 2023-09-15
 *
 * @copyright Copyright (c) 2023
 */

#include <sstream>
#include <string>
#include <vector>

#ifndef FSTRING_HPP_
#define FSTRING_HPP_

/**
 * @brief Formatted output string
 */
namespace fos {

#include "style.hpp"

   /**
    * @brief Text alignment
    */
   enum align {
      left, /**< Left alignment */
      right, /**< Right alignment */
      center, /**< Center alignment */
      justify,
   };

   /**
    * @brief Remove all target characters that are to the left of the string
    *
    * @param str String to trim
    * @param _target Target wanted (default: " \t\n\r\f\v")
    * @return Trimmed string
    */
   std::string leftTrim(
     std::string const& str, std::string _target = " \t\n\r\f\v");

   /**
    * @brief Remove all target characters that are to the right of the string
    *
    * @param str String to trim
    * @param _target Target wanted (default: " \t\n\r\f\v")
    * @return Trimmed string
    */
   std::string rightTrim(
     std::string const& str, std::string _target = " \t\n\r\f\v");

   /**
    * @brief Remove all target characters that are at the ends of the string
    *
    * @param str String to trim
    * @param _target Target wanted (default: " \t\n\r\f\v")
    * @return Trimmed string
    */
   std::string trim(
     std::string const& str, std::string _target = " \t\n\r\f\v");

   /**
    * @brief Replace the first occurrence of the target
    *
    * @param str String to replace
    * @param target Target wanted
    * @param _replace Replacement text (default: "")
    * @return Replaced string
    */
   std::string replaceFirst(
     std::string const& str, std::string target, std::string _replace = "");

   /**
    * @brief Replace all occurrences of the target
    *
    * @param str String to replace
    * @param target Target wanted
    * @param _replace Replacement text (default: "")
    * @return Replaced string
    */
   std::string replace(
     std::string const& str, std::string target, std::string _replace = "");

   /**
    * @brief Get a substring
    *
    * @param str Full string
    * @param end Ending position of the substring (open interval)
    * @param _init Starting position of the substring (closed interval, default:
    * 0)
    * @return Substring
    */
   std::string subString(std::string const& str, size_t end, size_t _init = 0);

   /**
    * @brief Split a string based on a delimiter and store all substrings in a
    * vector
    *
    * @param str String to be split
    * @param _delimiter Delimiter for splitting (default: " ")
    * @return Vector of substrings
    */
   std::vector<std::string> split(
     std::string const& str, std::string _delimiter = " ");

   /**
    * @brief Repeat a given element a specified number of times
    *
    * @param element Element to be repeated
    * @param times Number of times to repeat (default: 1)
    * @param _max_width If true, limits the resulting string to the specified
    * width (default: false)
    * @return Repeated string
    *
    * If _max_width is true, the "times" parameter defines the maximum width of
    * the resulting string, not just the number of repetitions. For example,
    * repeat("-=-", 10) generates a string with 30 characters, and repeat("-=-",
    * 10, true) generates a string with a maximum width of 10 characters.
    */
   template <typename T>
   std::string repeat(T element, size_t times = 1, bool _max_width = false);

   /**
    * @brief Wrap text to fit within a maximum width while preserving word
    * boundaries
    *
    * @param str Input text to be wrapped
    * @param size Maximum width for the wrapped text
    * @param _delimiter Delimiter for word boundaries (default: " ")
    * @param _new_delimiter Delimiter to replace the original delimiter in the
    * wrapped text (default: " ")
    * @return Wrapped text
    */
   std::string columnWrap(std::string& str, size_t size,
     std::string _delimiter = " ", std::string _new_delimiter = " ");

   /**
    * @brief Justify a string based on a specified size and alignment
    *
    * @param str Input string to be justified
    * @param size Desired size for justification
    * @param _align Alignment (left, right, center or justify) (default:
    * align::left)
    * @param _element Element to pad the string with (default: ' ')
    * @param _dynamic_size If true, the size is automatically set to match the
    * widest line (default: false)
    * @param _right_space If true, adds elements to the right until reaching the
    * specified size (default: false)
    * @return Justified string
    *
    * If _dynamic_size is true, the size is determined automatically based on
    * the widest line in the input string. If _right_space is true, elements are
    * added to the right of the string until it reaches the specified size. The
    * "_element" parameter accepts the same data types as the "repeat" function.
    */
   template <typename T>
   std::string alignment(std::string& str, size_t size,
     align _align = align::left, T _element = ' ', bool _dynamic_size = false,
     bool _right_space = false);

   /**
    * @brief Concatenate a collection of strings from init (inclusive) to end
    * (exclusive) with a separator between them
    *
    * @param init Pointer to the beginning of the collection (inclusive)
    * @param end Pointer to the end of the collection (exclusive)
    * @param _separator Separator to place between words (default: " ")
    * @return Concatenated string
    */
   template <typename T>
   std::string concat(T* init, T* end, std::string _separator = " ");

   /**
    * @brief Reverse the characters in a string
    *
    * @param str Input string to be reversed
    * @return Reversed string
    */
   std::string reverse(std::string const& str);

   /**
    * @brief Count the number of lines in a string
    *
    * @param str String to count lines in
    * @return Number of lines
    */
   size_t countLines(std::string const& str);

   /**
    * @brief Apply text style to a string
    *
    * @param str Input string
    * @param _color Text color (default: foreground::none)
    * @param _background Background color (default: background::none)
    * @param _style Text style (default: style::none)
    * @return Styled string
    */
   std::string setStyle(std::string const& str,
     short const _color = foreground::none,
     short const _background = background::none,
     short const _style = style::none);

   /**
    * @brief Find the length of the longest line in a string
    *
    * This function calculates and returns the length of the longest line
    * within a given input string
    *
    * @param str The input string to analyze
    * @return The length of the longest line in the input string
    */
   size_t longestLine(std::string const& str);

   /**
    * @brief Complete each line of a string with a specified string
    *
    * This function takes an input string, completes each line of the string
    * with a specified completion string, and ensures that each line has a
    * minimum column width
    *
    * @param str The input string to process
    * @param _complete The string used to complete each line (default is " ")
    * @param _column The minimum column width (default is 0)
    * @return The string with each line completed and adjusted to the minimum
    *         column width
    *
    * @note This function is useful for maintaining formatting when inverting
    *       drawings or designs stored as strings where spaces on the left may
    *       not be preserved when inverted
    */
   std::string completeLines(
     std::string const& str, std::string _complete = " ", size_t _column = 0);

   /**
    * @brief Inverts characters in a given string according to specific rules
    *
    * This function takes a string as input and inverts certain characters based
    * on predefined rules
    * - '(' is inverted to ')'
    * - ')' is inverted to '('
    * - '[' is inverted to ']'
    * - ']' is inverted to '['
    * - '{' is inverted to '}'
    * - '}' is inverted to '{'
    * - '\' is inverted to '/'
    * - '/' is inverted to '\'
    * - '<' is inverted to '>'
    * - '>' is inverted to '<'
    * Other characters remain unchanged
    *
    * @param str The input string to be processed
    * @return A new string with characters inverted according to the specified
    * rules
    */
   std::string invertCharacters(std::string const& str);

   std::string invertCharacters(std::string const& str);

} // namespace fos

#endif // FSTRING_HPP_
