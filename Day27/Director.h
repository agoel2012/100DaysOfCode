#ifndef __DIRECTOR_H_
#define __DIRECTOR_H_

#include <iostream>
#include <string>

#define MAX_DIRS_AVAIL 1

using namespace std;

class Director {

  private:
      unsigned int director_id_;
      int n_avail_dirs_;

  public:
      Director () : director_id_(0), n_avail_dirs_(MAX_DIRS_AVAIL) {}
      ~Director() {}
      /* Accessors/ Mutators */
      unsigned int get_director_id() {
          return director_id_;
      }
      void set_director_id(unsigned int dir_id) {
          director_id_ = dir_id;
      }
      int get_n_dirs_avail() {
          if (n_avail_dirs_ == 0)
            return -1;
          else
            return n_avail_dirs_;
      }
      void set_n_dirs_avail(int n_avail) {
          n_avail_dirs_ = n_avail;
      }
      void inc_dirs_avail() {
          n_avail_dirs_++;
      }
      void dec_dirs_avail() {
          n_avail_dirs_--;
      }

      virtual string dispatch_call() {
        if (get_n_dirs_avail() != -1) {
          dec_dirs_avail();
          set_director_id(get_director_id()+1);
          return "Dir" + to_string(get_director_id());
        } else
          return "NA";
      }
};

#endif /* __DIRECTOR_H_ */
