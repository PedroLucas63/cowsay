#ifndef COWSAY_H
#define COWSAY_H

/*!
 *  The cowsay classes
 */

#include <iostream>
#include <string>
using std::string;
#include <optional>
using std::optional;
#include <vector>
using std::vector;

//=== Forward declarations
struct CLIOptions;

/// Class representing a text-based cow witha a personality!
class Cow {
public:
  //!< The cow's possible moods/appearances.
  enum class mood_t : uint {
    NEUTRAL = 0,  //!< Default cow
    BORG,         //!< Borg mode
    DEAD,         //!< Dead
    GREEDY,       //!< Greedy
    PARANOIA,     //!< Paranoia
    STONED,       //!< Stoned
    TIRED,        //!< Tired
    WIRED,        //!< Wired
    YOUTH         //!< Young cow
  };

  Cow();
  void set_mood(mood_t);
  void show();

private:
  bool m_flip;
  string m_body;
  mood_t m_mood;

  // TODO: Add other members/methods
};

/// Class representing a billboard that stored and formats the text the cow says.
class BillBoard {
public:
  enum class align_t : uint { LEFT = 0, CENTERED, RIGHT, JUSTIFY };
  // TODO: Add members/methods
};

/// This class keeps track of all the running option, which may be modified via CLI.
struct CLIOptions {
  //== Data members

  //== Public members
  /// Cow related options
  Cow::mood_t cow_mood;  //!< Cow's mood.
  std::string tongue;    //!< The cow's tongue (2 chacracters long).
  std::string eyes;      //!< The cow's eyes (2 characters long).

  /// Billboard related options
  std::vector<string> buffer;    //!< The text content.
  BillBoard::align_t alignment;  //!< The choosen alignment.
  size_t width;                  //!< The text width.
  bool wrapping;                 //!< Wrap text and remove ws.
  bool flip;                     //!< Flip billboard.

  //== Public interface
  /// Basic constructor.
  CLIOptions(int argc, char** argv);
  /// Use instructions.
  void usage(const std::string& msg = "") const;
  /// Have we received text from the CLI?
  [[nodiscard]] inline bool has_text() const { return not buffer.empty(); }
};

#endif
