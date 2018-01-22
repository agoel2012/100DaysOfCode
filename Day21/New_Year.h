#ifndef __NEW_YEAR_H_
#define __NEW_YEAR_H_

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class New_Year {
    private:
        double n_days_gone_by;
        double n_weeks_gone_by;
        double n_months_gone_by;

        /* Accessors/Mutators */
        double get_ts_info_in_days(void) {
            /* Approximation in days */
            return (n_days_gone_by);
        }

        double get_ts_info_in_weeks(void) {
            /* Approximation in weeks */
            return (n_weeks_gone_by);
        }

        double get_ts_info_in_months(void) {
            /* Approximation in months */
            return (n_months_gone_by);
        }

    public:
      /* Default */
      New_Year() : n_days_gone_by(0.0), n_months_gone_by(0.0), n_weeks_gone_by(0.0){}
      ~New_Year() {}

      void set_ts_info(double n_days, double n_weeks, double n_months) {
          n_days_gone_by = n_days;
          n_months_gone_by = n_months;
          n_weeks_gone_by = n_weeks;
      }

      static int display_ts_info(New_Year *instance, string type_of_format);
      static int get_ts_info_from_today(double &days,
                                    double &weeks, double &months);
};

int New_Year::get_ts_info_from_today(double &days, double &weeks, double &months)
{
  time_t rawtime;
  struct tm *time_info;
  int n_days_since_jan1, n_year_since_1900;

  time(&rawtime);
  time_info = localtime(&rawtime);

  n_days_since_jan1 = time_info->tm_yday+1;
  n_year_since_1900 = time_info->tm_year;

  days = static_cast<double>(n_days_since_jan1);
  weeks = static_cast<double>(days/7.0);
  months = static_cast<double>(days/30.0);
  return 0;
}

int New_Year::display_ts_info(New_Year *instance, string tof)
{

    if (tof == "days") {
      cout << "-------------------TS_INFO-----------------------" << endl;
      cout << instance->get_ts_info_in_days() << " Days elapsed since New Year 2018" << endl;
    } else if (tof == "weeks") {
      cout << "-------------------TS_INFO-----------------------" << endl;
      cout << instance->get_ts_info_in_weeks() << " Weeks elapsed since New Year 2018" << endl;
    } else if (tof == "months") {
      cout << "-------------------TS_INFO-----------------------" << endl;
      cout << instance->get_ts_info_in_months() << " Months elapsed since New Year 2018" << endl;
    } else {
      cout << "Illegal time format" << endl;
      return -1;
    }

    cout << "-------------------------------------------------" << endl;
    return 0;
}

#endif /* __NEW_YEAR_H_ */
