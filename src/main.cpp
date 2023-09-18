#include "clioptions.hpp"
#include "drawing.hpp"

int main(int argc, char* argv[]) {
   CLIOptions& cli { CLIOptions::getInstance() };
   cli.getConfigs(argc, argv);

   if (cli.getExecute()) {
      cli.getPendingConfig();
      draw(cli.getBillboardsConfigs(), cli.getCreatureConfigs(), cli.getFlip());
   }

   return 0;
}