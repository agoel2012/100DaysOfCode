#include <iostream>
#include <string>
#include <stdlib.h>

#include "ProcessCall.h"

using namespace std;

#define MAX_CALLS_SUPPORTED 13

int main(int argc, char *argv[])
{
  if (argc < 2) {
    cout << "Usage: ./call_center <num_of_calls>" << endl;
    exit(1);
  }

  string who_handled_me;
  int i = 0, calls_requested = 0;
  calls_requested = atoi(argv[1]);
  if (calls_requested > MAX_CALLS_SUPPORTED) {
    cout << "Exceeding max supported calls. Please try again" << endl;
    exit(1);
  }

  ProcessCall *p_call = new ProcessCall();
  if (p_call == NULL) {
    cout << "Malloc failed for ProcessCall" << endl;
    return -1;
  }

  for (i = 0; i < calls_requested; i++) {
    p_call->handle_call();
    who_handled_me = p_call->get_handler_name();
    if (who_handled_me == "NA") {
      cout << "Call #" << i+1 << " not handled, bugger off mate !!" << endl;
      break;
    }
    cout << "Call #" << i+1 << " Handled by " << who_handled_me << endl;
  }

  delete p_call;
  return 0;
}
