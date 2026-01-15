#ifndef SCHED_H
#define SCHED_H

#include "proc.h"

typedef struct user{
    int uid;
    int weight;

    proc_t *proc_queue_head;
    proc_t *proc_queue_tail;
}user_t;

//scheduler-ul
typedef struct sched{
    user_t *users;
    int user_count;
    int rr_index;    // de unde continua Round-Robin 
    int quantum_base;  //pentru a calcula cate tick-uri are un proces
}sched_t;

//raspunsul scheduler-ului
typedef struct sched_decision{
    proc_t *proc;
    int slice;  //cat ruleaza procesul ales
}sched_decision_t;



//functii

//initilaizare
void sched_init(sched_t *sched, int quantum_base_n);
void sched_add_user(sched_t *sched, int uid, int weight);

//scheduler
int sched_next(sched_t *sched, sched_decision_t *dec, int *uid);
void sched_enqueue_ready(sched_t *sched, proc_t *p);

#endif 