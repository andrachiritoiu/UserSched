#include <stdlib.h>
#include "proc.h"

proc_t* proc_create(int pid, int uid, int ticks) {
    proc_t *p = (proc_t*)malloc(sizeof(proc_t));
    if (!p) exit(1);

    p->pid = pid;
    p->uid = uid;
    p->remaining_ticks = ticks;
    p->next = NULL;
    return p;
}

void proc_run(proc_t *p, int ticks) {
    if (p->remaining_ticks > ticks)
        p->remaining_ticks -= ticks;
    else
        p->remaining_ticks = 0;
}
