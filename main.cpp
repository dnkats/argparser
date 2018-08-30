#include <string>
#include <iostream>
#include "argpars.h"
//#define _SIMPLEOPT
int main(int argc, char **argv)
{
  ArgPars args(argc,argv);
  std::string opt, arg;
  // handle options  
  while ( args.nextoption(opt) ) {
#ifdef _SIMPLEOPT
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
#else
    // autogenerate help 
    ArgOpts options;
    if (options.check(opt,ArgOpt("Verbosity level","v","-verbose"))) {
      if ( args.optarg(arg) ){
        std::cout << "Verbosity: " << arg << std::endl;
        args.markasoption();
      }
    } else if (options.check(opt,ArgOpt("Output","o","-output"))) {
      if ( args.optarg(arg) ){
        std::cout << "Output: " << arg << std::endl;
        args.markasoption();
      }
    } else if (options.check(opt,ArgOpt("Print this help","h","-help"))) {
      options.printhelp(std::cout,"a.out [OPTIONS]","Test program for ArgPars");
//      options.printhelp(std::cout);
      return 0;
    } else {
      std::cout << "Unknown option: " << opt << std::endl;
    }
#endif
  }
  while( args.nextremaining(arg) ) {
    std::cout << " Remaining arguments: " << arg << std::endl;
  } 
  return 0;
}
