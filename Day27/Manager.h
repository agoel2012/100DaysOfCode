#ifndef __MANAGER_H_
#define __MANAGER_H_

#include <iostream>
#include <string>

#include "Director.h"

#define MAX_MGRS_AVAIL 2

using namespace std;

class Manager : public Director {

  private:
      unsigned int manager_id_;
      int n_avail_mgrs_;

  public:
      Manager () : manager_id_(0), n_avail_mgrs_(MAX_MGRS_AVAIL) {}
      ~Manager() {}
      /* Accessors/ Mutators */
      unsigned int get_manager_id() {
          return manager_id_;
      }
      void set_manager_id(unsigned int dir_id) {
          manager_id_ = dir_id;
      }
      int get_n_mgrs_avail() {
          if (n_avail_mgrs_ == 0)
            return -1;
          else
            return n_avail_mgrs_;
      }
      void set_n_mgrs_avail(int n_avail) {
          n_avail_mgrs_ = n_avail;
      }
      void inc_mgrs_avail() {
          n_avail_mgrs_++;
      }
      void dec_mgrs_avail() {
          n_avail_mgrs_--;
      }

      virtual string dispatch_call() {
        if (get_n_mgrs_avail() != -1) {
          dec_mgrs_avail();
          set_manager_id(get_manager_id()+1);
          return "Mgr" + to_string(get_manager_id());
        } else
          return Director::dispatch_call();
      }
};



#endif /* __MANAGER_H_ */
