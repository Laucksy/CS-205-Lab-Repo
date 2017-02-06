#ifndef MACROS_H
#define MACROS_H

#include <iostream>

#define DEBUGGING

#ifdef DEBUGGING
    #define SHOW_WHERE std::cout << __PRETTY_FUNCTION__ << std::endl;
#else
    #define SHOW_WHERE
#endif

#endif // MACROS_H
