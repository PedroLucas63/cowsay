/**
 * @file main.cpp
 *
 * @description
 * This program implements a clone of the classic cowsay program.
 *
 * @author	Selan, <selan.santos@ufrn.br>
 * @date	November 13th, 2021
 *
 * @remark On 2023-09-08 new version initiated.
 */

#include <cstdlib>  // EXIT_SUCCESS

#include "cowsay.h"

int main(int argc, char** argv) {
  // TODO: Add here your own code.
  Cow mimosa;
  mimosa.set_mood(Cow::mood_t::WIRED);
  // mimosa.m_mood = Cow::mood_t::TIRED;
  //
  std::cout << "testes\n";

  return EXIT_SUCCESS;
}
