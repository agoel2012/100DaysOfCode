#include <iostream>
#include <string>
#include <cstdlib>

/* User Defined Includes */
#include "New_Year.h"
#include "TS_Helper.h"

int main(int argc, char *argv[])
{
    string type_of_format;
    double days_elapsed = 0.0, weeks_elapsed = 0.0, months_elapsed = 0.0;
    int rc = 0;

    if (argc != 2) {
        cout << "Usage: ./ts_today [OPTIONS]" << endl;
        cout << "OPTIONS: [-days/-weeks/-months]" << endl;
        exit (1);
    }

    /* Parse arguments to get display options */
    rc = check_args_usage(argv, type_of_format);
    if (rc != TS_SUCCESS) {
      cout << "Invalid arguments" << endl;
      exit(1);
    }

    /* Get ts_info from todays_date */
    rc = New_Year::get_ts_info_from_today(days_elapsed,
                                          weeks_elapsed,
                                          months_elapsed);
    if (rc != TS_SUCCESS) {
      cout << "Unable to get ts_info from todays_date" << endl;
      exit(1);
    }

    /* Create a new_year instance & display the counter */
    New_Year *new_year = new New_Year();
    new_year->set_ts_info(days_elapsed, weeks_elapsed, months_elapsed);
    rc = New_Year::display_ts_info(new_year, type_of_format);
    if (rc != TS_SUCCESS) {
      cout << "Unable to display the ts_info data" << endl;
      exit(1);
    }

    return 0;
}
