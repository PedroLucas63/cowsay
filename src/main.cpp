#include "clioptions.hpp"
//#include "drawing.hpp"

int main(int argc, char* argv[]) {
   CLIOptions& cli { CLIOptions::getInstance() };
   cli.getConfigs(argc, argv);

   if (cli.getExecute()) {
      cli.getPendingConfig();
   }

   return 0;
}