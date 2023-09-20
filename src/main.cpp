/**
 * @file main.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Main program file for drawing a graphical display based on
 * command-line options.
 * @version 1.0
 * @date 2023-09-20
 *
 * This file contains the main program code that reads command-line options,
 * configures the drawing parameters, and generates a graphical display based on
 * the provided options.
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "clioptions.hpp" // Include the CLIOptions class header.
#include "drawing.hpp" // Include the drawing functions header.

/**
 * @brief Main function of the program
 *
 * This function is the entry point of the program. It initializes the
 * CLIOptions singleton, sets configurations based on command-line arguments,
 * and generates a graphical display if the '--execute' option is provided.
 *
 * @param argc The number of command-line arguments
 * @param argv An array of command-line argument strings
 * @return An integer representing the exit status of the program
 */
int main(int argc, char* argv[]) {
   CLIOptions& cli {
      CLIOptions::getInstance()
   }; // Get an instance of CLIOptions
   cli.setConfigs(
     argc, argv); // Set configurations based on command-line arguments
   cli.getPendingConfig(); // Retrieve pending configurations

   // Check if the '--execute' option is provided
   if (cli.getExecute()) {
      draw(cli.getBillboardsConfigs(),
        cli.getCreatureConfigs(),
        cli.getFlip()); // Generate a graphical display
   }

   return EXIT_SUCCESS; // Return a success status code
}
