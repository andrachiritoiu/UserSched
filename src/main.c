#include <stdio.h>
#include <stdlib.h>
#include "sched.h"
#include "proc.h"

int main(void) {
    sched_t sched;
    sched_init(&sched, 10);

    sched_add_user(&sched, 1, 1);
    sched_add_user(&sched, 2, 3);

    sched_enqueue_ready(&sched, proc_create(101, 1, 50));
    sched_enqueue_ready(&sched, proc_create(201, 2, 80));
    sched_enqueue_ready(&sched, proc_create(102, 1, 30));
    sched_enqueue_ready(&sched, proc_create(202, 2, 40));

    int time = 0, uid;
    sched_decision_t d;

    printf("- START -\n");

    while (sched_next(&sched, &d, &uid)) {
        proc_t *p = d.proc;

        printf("T=%3d | user=%d | pid=%d | slice=%d | rem=%d\n",
               time, uid, p->pid, d.slice, p->remaining_ticks);

        proc_run(p, d.slice);
        time += d.slice;

        if (p->remaining_ticks > 0)
            sched_enqueue_ready(&sched, p);
        else
            free(p);
    }

    printf("- DONE -\n");
    free(sched.users);
    return 0;
}
