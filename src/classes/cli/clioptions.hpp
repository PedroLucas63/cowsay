/**
 * @file clioptions.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Defines the CLIOptions class for handling command-line options.
 * @version 0.1
 * @date 2023-09-15
 *
 * This file contains the definition of the CLIOptions class, which is
 * responsible for parsing and managing command-line options for the
 * application.
 *
 * @copyright Copyright (c) 2023
 */

#include "fstring.hpp"
#include "utils.hpp"
#include <string>

#ifndef CLI_OPTIONS_HPP_
#define CLI_OPTIONS_HPP_

constexpr short FIRST_ARGUMENT {
   1
}; ///< Index of the first command-line argument
constexpr short EYES_SIZE { 2 }; ///< Size of the eyes argument
constexpr short TONGUE_SIZE { 2 }; ///< Size of the tongue argument
constexpr short MIN_COLUMN { 1 }; ///< Minimum column value
constexpr short MAX_COLUMN { 100 }; ///< Maximum column value

/**
 * @brief Enumeration of argument types.
 */
enum ArgumentType {
   BASIC, ///< Basic argument type
   COMPOST, ///< Compost argument type
   COMPLEX, ///< Complex argument type
   NONE, ///< No argument type
};

/**
 * @brief Structure representing a command-line argument.
 */
struct Argument {
   ArgumentType type; ///< The type of the argument
   std::string code; ///< The code for the argument
};

/**
 * @brief List of command-line arguments.
 */
Argument const arguments[] = { { BASIC, "-h" },
   { BASIC, "-b" },
   { BASIC, "-d" },
   { BASIC, "-g" },
   { BASIC, "-p" },
   { BASIC, "-s" },
   { BASIC, "-t" },
   { BASIC, "-w" },
   { BASIC, "-y" },
   { COMPOST, "-E" },
   { COMPOST, "-T" },
   { COMPOST, "-F" },
   { COMPOST, "-J" },
   { COMPOST, "-W" },
   { BASIC, "-n" },
   { NONE, std::string() } };

/**
 * @brief Enumeration of argument types used in the application.
 */
enum ArgumentsEnumeration {
   HELP,
   BORG,
   DEAD,
   GREEDY,
   PARANOIA,
   STONED,
   TIRED,
   WIRED,
   YOUNG,
   EYES,
   TONGUE,
   COW_FILE,
   ALIGNMENT,
   WRAP_COLUMN,
   REGULAR,
   UNDEFINED,
};

/**
 * @brief CLI Options class for handling command-line options
 */
class CLIOptions {
   public:
   /**
    * @brief Get the single instance of CLIOptions
    *
    * @return Pointer to the instance
    */
   static CLIOptions& getInstance();

   /**
    * @brief Default copy constructor for CLIOptions (disabled)
    */
   CLIOptions(CLIOptions const&) = delete;

   /**
    * @brief Default copy assignment operator for CLIOptions (disabled)
    */
   CLIOptions operator=(CLIOptions const&) = delete;

   /**
    * @brief Destruct the instance of CLIOptions
    */
   static void destruct();

   /**
    * @brief Get the configurations for billboards and creatures from
    * command-line arguments
    *
    * @param arguments_count The number of command-line arguments
    * @param arguments The command-line arguments
    */
   void getConfigs(int arguments_count, char* arguments[]);

   /**
    * @brief Get the billboard configurations
    *
    * @return Billboard configurations
    */
   BillboardConfigs getBillboardsConfigs() const;

   /**
    * @brief Get the creature configurations
    *
    * @return Creature configurations
    */
   CreatureConfigs getCreatureConfigs() const;

   /**
    * @brief Get the flip option
    *
    * @return The flip option
    */
   bool getFlip() const;

   /**
    * @brief Get the execute option
    *
    * @return The execute option
    */
   bool getExecute() const;

   /**
    * @brief Get the pending configuration
    */
   void getPendingConfig();

   private:
   static CLIOptions*
     instance; ///< Pointer to the single instance of CLIOptions

   BillboardConfigs
     billboard_configs; ///< Configuration settings for billboards
   CreatureConfigs creature_configs; ///< Configuration settings for creatures
   bool flip; ///< Flag indicating if a flip operation is required
   bool execute {
      true
   }; ///< Flag indicating if execution is enabled (default: true)
   std::string* lost_arguments; ///< Pointer to an array of lost arguments
   int lost_arguments_size; ///< The size of the lost arguments array
   bool invalid_element {
      false
   }; ///< Flag indicating the presence of invalid elements

   /**
    * @brief Private constructor for creating a new CLIOptions object
    */
   CLIOptions() = default;

   /**
    * @brief Private destructor for destroying the CLIOptions object
    */
   ~CLIOptions() = default;

   /**
    * @brief Verifies the type of a command-line argument
    *
    * @param argument The command-line argument to be verified
    * @return Pointer to the Argument structure representing the argument type
    */
   Argument const* verifyArgument(char* argument) const;

   /**
    * @brief Gets basic configuration settings based on a command-line argument
    *
    * @param argument The command-line argument specifying the configuration
    * type.
    */
   void getBasicConfig(Argument const* argument);

   /**
    * @brief Prints help information for command-line usage
    */
   void printHelp();

   /**
    * @brief Gets compost configuration settings based on a command-line
    * argument and complementary data
    *
    * @param argument The command-line argument specifying the configuration
    * type.
    * @param complementary Additional data required for configuration
    */
   void getCompostConfig(Argument const* argument, std::string complementary);

   /**
    * @brief Retrieves lost command-line arguments from a list
    *
    * @param arguments_count The total number of command-line arguments
    * @param last_index The last index processed when searching for lost
    * arguments
    * @param arguments The array of command-line arguments
    */
   void getLostArguments(
     int arguments_count, int& last_index, char* arguments[]);

   /**
    * @brief Gets complex configuration settings based on a command-line
    * argument and additional arguments
    *
    * @param argument The command-line argument specifying the configuration
    * type
    * @param arguments Additional command-line arguments required for
    * configuration
    * @param index The index of the current argument being processed
    */
   void getComplexConfig(
     Argument const* argument, char* arguments[], int& index);
};

#endif // CLI_OPTIONS_HPP_
