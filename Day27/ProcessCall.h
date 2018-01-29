#ifndef __PROCESSCALL_H_
#define __PROCESSCALL_H_

#include <iostream>
#include <string>

#include "Director.h"
#include "Manager.h"
#include "Respondent.h"

using namespace std;

class ProcessCall {

  private:
      string handler_name_;
      Respondent *r_ptr_;
  public:
      ProcessCall() : handler_name_ ("NA"), r_ptr_(NULL) {}
      ~ProcessCall() {
        if (r_ptr_ != NULL)
          delete r_ptr_;
      }

      /* Accessors/Mutators */
      string get_handler_name() {
        return handler_name_;
      }
      void set_handler_name(string hldr_name) {
        handler_name_ = hldr_name;
      }

      Respondent * get_resp_obj() {
        if (r_ptr_ == NULL) {
          r_ptr_ = new Respondent();
          if (r_ptr_ == NULL) {
            cout << "Malloc failed for Respondent" << endl;
            return NULL;
          }
        }
        return r_ptr_;
      }
      void handle_call () {
          Director *d_ptr = dynamic_cast<Director *>(get_resp_obj());
          if (d_ptr == NULL) {
            cout << "Director is NULL" << endl;
            return;
          }
          set_handler_name(d_ptr->dispatch_call());
          return;
      }
};

#endif /* __PROCESSCALL_H_ */
