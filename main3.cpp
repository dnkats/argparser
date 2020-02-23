#include <string>
#include <iostream>
#include "argpars.h"
//#define _SIMPLEOPT
int main(int argc, char **argv)
{
  namespace ap = ArgParser;
  ap::ArgPars args(argc,argv);
  std::string opt, arg;
  // handle options  
  while ( args.nextoption(opt) ) {
    if ( opt == "h" || opt == "-help" ) {
      std::cout << "Help file" << std::endl;
      return 0;
    } else if ( opt == "v" || opt == "-verbose" ) {
      if ( args.optarg(arg) ){
        std::cout << "Verbosity: " << arg << std::endl;
        args.markasoption();
      }
    } else if ( opt == "o" || opt == "-output" ) {
      if ( args.optarg(arg) ){
        std::cout << "Output: " << arg << std::endl;
        args.markasoption();
      }
    } else {
        std::cout << "Option: " << opt << std::endl;
    }
  }
  while( args.nextremaining(arg) ) {
    std::cout << " Remaining arguments: " << arg << std::endl;
  } 
  return 0;
}

