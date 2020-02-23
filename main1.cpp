#include <string>
#include <iostream>
#include "argpars.h"
// simple example with help autogeneration
int main(int argc, char **argv)
{
  namespace ap = ArgParser;
  ap::ArgPars args(argc,argv);
  std::string arg;
  // handle options  
  while ( args.nextoption() ) {
    if (args.check(ap::ArgOpt("Verbosity level","v","-verbose"))) {
      if ( args.optarg(arg) ){
        std::cout << "Verbosity: " << arg << std::endl;
        args.markasoption();
      }
    } else if (args.check(ap::ArgOpt("Output","o","-output"))) {
      if ( args.optarg(arg) ){
        std::cout << "Output: " << arg << std::endl;
        args.markasoption();
      }
    } else if (args.check(ap::ArgOpt("Print this help","h","-help"))) {
      args.printhelp(std::cout,"a.out [OPTIONS]","Test program for ArgPars");
//      args.printhelp(std::cout);
      return 0;
    } else {
      std::cout << "Unknown option: " << args.get_current_option() << std::endl;
    }
  }
  while( args.nextremaining(arg) ) {
    std::cout << " Remaining arguments: " << arg << std::endl;
  } 
  return 0;
}
