Design a call-center that handles every incoming call in the following order:
1. Respondent
2. Manager
3. Director

Unless MAX_RESP_AVAIL is not reached, incoming call should be handled by a respondent.
Unless MAX_MGRS_AVAIL is not reached and MAX_RESP_AVAIL is reached, incoming call should be handled by manager.
Unless MAX_DIRS_AVAIL is not reached and MAX_MGRS_AVAIL,MAX_RESP_AVAIL is reached, incoming call should be handled by director.
If all n_avail_resp_, n_avail_dirs_, and n_avail_mgrs_ have all maxed out, drop all the calls_requested
