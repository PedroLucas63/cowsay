#include <string>
using std::string;

#include "cowsay.h"

//== THESE ARE AUXILIARY FUNCTIONS.

//== THESE ARE THE METHODS.
Cow::Cow() {
  m_body = std::string{ "             ^__^   $thoughts  \n" }
           + std::string{ "     _______/($eyes)  $thoughts\n" }
           + std::string{ " /\\/(       /(__)             \n" }
           + std::string{ "    | w---- | $tongue          \n" }
           + std::string{ "    ||     ||                  \n" };
}

BillBoard::BillBoard() {
  // TODO
}

void BillBoard::append_line(const std::string& line) {
  // TODO
}

/// Formats the billboard based on the parameters set by the CLI or default values.
void BillBoard::format() {
  // TODO
}

void BillBoard::show() const {
  // TODO
}

/// Constructor that parses the command-line arguments.
CLIOptions::CLIOptions(int argc, char* argv[]) {
  // Default running options.
  cow_mood = Cow::mood_t::NEUTRAL;
  eyes = "oo";
  tongue = "  ";
  alignment = BillBoard::align_t::LEFT;
  width = BillBoard::m_dft_width;
  wrapping = true;
  flip = false;
  // TODO: parse the arguments.
}

// ================================[ cowsay.cpp ]=====================================
