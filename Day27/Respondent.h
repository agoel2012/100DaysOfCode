#ifndef __RESPONDENT_H_
#define __RESPONDENT_H_

#include <iostream>
#include <string>
#include "Manager.h"
#include "Director.h"

#define MAX_RESP_AVAIL 10

using namespace std;

class Respondent : public Manager {

  private:
      unsigned int respondent_id_;
      int n_avail_resp_;

  public:
      Respondent () : respondent_id_(0), n_avail_resp_(MAX_RESP_AVAIL) {}
      ~Respondent() {}
      /* Accessors/ Mutators */
      unsigned int get_respondent_id() {
          return respondent_id_;
      }
      void set_respondent_id(unsigned int dir_id) {
          respondent_id_ = dir_id;
      }
      int get_n_resp_avail() {
          if (n_avail_resp_ == 0)
            return -1;
          else
            return n_avail_resp_;
      }
      void set_n_resp_avail(int n_avail) {
          n_avail_resp_ = n_avail;
      }
      void inc_resp_avail() {
          n_avail_resp_++;
      }
      void dec_resp_avail() {
          n_avail_resp_--;
      }

      string dispatch_call() {
        if (get_n_resp_avail() != -1) {
          dec_resp_avail();
          set_respondent_id(get_respondent_id()+1);
          return "Resp" + to_string(get_respondent_id());
        } else
          return Manager::dispatch_call();
      }
};



#endif /* __respondent_H_ */
