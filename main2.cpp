#include <string>
#include <iostream>
#include "argpars.h"
// handle existing options separate from the arguments
// (old way)
int main(int argc, char **argv)
{
  namespace ap = ArgParser;
  ap::ArgPars args(argc,argv);
  std::string opt, arg;
  // handle options  
  while ( args.nextoption(opt) ) {
    // autogenerate help 
    ap::ArgOpts options;
    if (options.check(opt,ap::ArgOpt("Verbosity level","v","-verbose"))) {
      if ( args.optarg(arg) ){
        std::cout << "Verbosity: " << arg << std::endl;
        args.markasoption();
      }
    } else if (options.check(opt,ap::ArgOpt("Output","o","-output"))) {
      if ( args.optarg(arg) ){
        std::cout << "Output: " << arg << std::endl;
        args.markasoption();
      }
    } else if (options.check(opt,ap::ArgOpt("Print this help","h","-help"))) {
      options.printhelp(std::cout,"a.out [OPTIONS]","Test program for ArgPars");
//      options.printhelp(std::cout);
      return 0;
    } else {
      std::cout << "Unknown option: " << opt << std::endl;
    }
  }
  while( args.nextremaining(arg) ) {
    std::cout << " Remaining arguments: " << arg << std::endl;
  } 
  return 0;
}
