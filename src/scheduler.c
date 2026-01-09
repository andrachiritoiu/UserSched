#include <stdlib.h>
#include "sched.h"

void sched_init(sched_t *sched, int quantum_base_n){
    sched->users = NULL;
    sched->user_count = 0;
    sched->rr_index = 0;
    sched->quantum_base = quantum_base_n;
}