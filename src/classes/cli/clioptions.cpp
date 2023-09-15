/**
 * @file clioptions.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation of the CLIOptions class for handling command-line options.
 * @version 0.1
 * @date 2023-09-15
 *
 * This file contains the implementation of the CLIOptions class, which is responsible for
 * parsing and managing command-line options for the application. It defines functions to
 * retrieve and handle various command-line configurations.
 *
 *
 * @copyright Copyright (c) 2023
 */

#include "clioptions.hpp"
#include <iostream>

CLIOptions* CLIOptions::instance = nullptr;

// Gets the single instance of CLIOptions
CLIOptions& CLIOptions::getInstance() {
   if (instance == nullptr) {
      instance = new CLIOptions;
   }

   return *instance;
}

// Destroys the instance of CLIOptions
void CLIOptions::destruct() {
   delete instance;
   instance = nullptr;
}

// Parses command-line arguments to obtain configurations
void CLIOptions::getConfigs(int arguments_count, char* arguments[]) {
   for (int index { FIRST_ARGUMENT }; index < arguments_count; ++index) {
      Argument const* argument = verifyArgument(arguments[index]);

      if (argument->type == BASIC) {
         getBasicConfig(argument);
      } else if (argument->type == COMPOST) {
         if (index + 1 != arguments_count) {
            try {
               getCompostConfig(argument, arguments[++index]);
            } catch (std::invalid_argument& e) {
               std::cerr << fos::setStyle(e.what(), fos::foreground::red)
                         << "\n";
               invalid_element = true;
            }
         } else {
            std::cerr << fos::setStyle(
              "A compound algorithm needs some complementary argument. The "
              "default will be set.",
              fos::foreground::red)
                      << "\n";
         }

      } else if (argument->type == COMPLEX) {
         // getComplexConfig(argument, arguments, index);
      }

      if (argument->type == NONE || invalid_element) {
         getLostArguments(arguments_count, index, arguments);
      }
   }
}

// Retrieves billboard configurations
BillboardConfigs CLIOptions::getBillboardsConfigs() const {
   return billboard_configs;
}

// Retrieves creature configurations
CreatureConfigs CLIOptions::getCreatureConfigs() const {
   return creature_configs;
}

// Retrieves the flip option
bool CLIOptions::getFlip() const {
   return flip;
}

// Retrieves the execute option
bool CLIOptions::getExecute() const {
   return execute;
}

// Verifies the type of a command-line argument
Argument const* CLIOptions::verifyArgument(char* argument) const {
   for (Argument const& arg : arguments) {
      if (arg.code == argument) {
         return &arg;
      }
   }

   return &arguments[UNDEFINED];
};

// Handles basic configuration settings
void CLIOptions::getBasicConfig(Argument const* argument) {
   if (argument == &arguments[HELP]) {
      printHelp();
      execute = false;
   } else if (argument == &arguments[BORG]) {
      creature_configs.mood = 'b';
   } else if (argument == &arguments[DEAD]) {
      creature_configs.mood = 'd';
   } else if (argument == &arguments[GREEDY]) {
      creature_configs.mood = 'g';
   } else if (argument == &arguments[PARANOIA]) {
      creature_configs.mood = 'p';
   } else if (argument == &arguments[TIRED]) {
      creature_configs.mood = 't';
   } else if (argument == &arguments[WIRED]) {
      creature_configs.mood = 'w';
   } else if (argument == &arguments[YOUNG]) {
      creature_configs.mood = 'y';
   } else if (argument == &arguments[REGULAR]) {
      billboard_configs.regular = true;
   }
}

// Prints help information for command-line usage
void CLIOptions::printHelp() {
   std::cout << "Welcome to C++ Cowsay Clone, version 1.0, (c) 2021-2023 Pedro "
                "Lucas, DIMAp, UFRN.\n";
   std::cout << "Usage: cowsay [-h] [-bdgpstwy] [-E eyes] [-T tongue] [-F "
                "cowfile] [-J alignment] [-W wrapcolumn] [-n] [message]\n";

   std::cout << "\twhere\t- eyes       is a 2-character string. Ex.: '@@'.\n";
   std::cout << "\t\t- tongue     is a 2-character string. Ex.: ' U'.\n";
   std::cout
     << "\t\t- cowfile    is a text file that contains a cow description.\n";
   std::cout
     << "\t\t- alignment  `c` means center aligned, `r` means right aligned.\n";
   std::cout << "\t\t- wrapcolunm is an integer value in [1,100].\n";
}

// Handles compound configuration settings
void CLIOptions::getCompostConfig(
  Argument const* argument, std::string complementary) {
   if (argument == &arguments[EYES]) {
      if (complementary.size() != EYES_SIZE) {
         throw std::invalid_argument(
           "Eyes must be exactly 2 characters long. The default will be set.");
      } else {
         creature_configs.eyes = complementary;
      }
   } else if (argument == &arguments[TONGUE]) {
      if (complementary.size() != TONGUE_SIZE) {
         throw std::invalid_argument(
           "Eyes must be exactly 2 characters long. The default will be set.");
      } else {
         creature_configs.tongue = complementary;
      }
   } else if (argument == &arguments[WRAP_COLUMN]) {
      try {
         int column_size { std::stoi(complementary) };

         if (column_size < MIN_COLUMN || column_size > MAX_COLUMN) {
            throw std::invalid_argument("The column size must be in the range ["
              + std::to_string(MIN_COLUMN) + ", " + std::to_string(MAX_COLUMN)
              + "]. The default will be set.");
         } else {
            billboard_configs.wrap_column = column_size;
         }
      } catch (std::invalid_argument& e) {
         throw std::invalid_argument("The expected value must be of type "
                                     "integer (int). The default will be set.");
      }
   } else if (argument == &arguments[COW_FILE]) {
      creature_configs.creature = complementary;
   } else if (argument == &arguments[ALIGNMENT]) {
      if (complementary == "l") {
         billboard_configs.align = 'l';
      } else if (complementary == "c") {
         billboard_configs.align = 'c';
      } else if (complementary == "r") {
         billboard_configs.align = 'r';
      } else {
         throw std::invalid_argument("The expected input must be 'l', 'c' or "
                                     "'r'. The default will be set.");
      }
   }
}

// Retrieves lost command-line arguments
void CLIOptions::getLostArguments(
  int arguments_count, int& last_index, char* arguments[]) {
   lost_arguments_size = arguments_count - last_index;
   lost_arguments = new std::string[lost_arguments_size];

   for (int l_index { 0 }; l_index < lost_arguments_size; l_index++) {
      lost_arguments[l_index] = arguments[last_index++];
   }
}

// Handles complex configuration settings (currently commented out)
// void CLIOptions::getComplexConfig(
//   Argument const* argument, char* arguments[], int& index) { ... }

// Retrieves pending configurations from lost arguments or standard input
void CLIOptions::getPendingConfig() {
   billboard_configs.text
     = fos::concat(lost_arguments, lost_arguments + lost_arguments_size);

   if (billboard_configs.text.empty()) {
      std::string line;
      while (std::getline(std::cin, line)) {
         billboard_configs.text += line + '\n';
      }
   }
}