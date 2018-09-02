# argparser

Argument list parser class

  * loop through "-" and "--" options using `nextoption(option)`
  * get arguments after the current option using `optarg(arg)`
  * mark this argument as a part of the options using `markasoption()`
  * loop through remaining arguments using `nextremaining(arg)`
  
See main.cpp for an example.

    ./a.out -pd test1 -vox -1 test bla
    
Output:

    Unknown option: p
    Unknown option: d
    Verbosity: -1
    Output: -1
    Unknown option: x
     Remaining arguments: test1
     Remaining arguments: test
     Remaining arguments: bla
