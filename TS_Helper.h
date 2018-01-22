#ifndef __TS_HELPER_H_
#define __TS_HELPER_H_

#include <iostream>
#include <string>

#define TS_SUCCESS 0

int check_args_usage(char *argv[], string &type_of_format)
{
    string arg_str(argv[1]+1);

    switch(argv[1][0]) {
      case '-':
                type_of_format = arg_str;
                return 0;
      default:
                type_of_format = "unknown";

    }

    return -1;
}

#endif
