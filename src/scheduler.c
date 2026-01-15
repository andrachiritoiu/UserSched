#include <stdlib.h>
#include "sched.h"

//initializare
void sched_init(sched_t *sched, int quantum_base_n){
    sched->users = NULL;
    sched->user_count = 0;
    sched->rr_index = 0;
    sched->quantum_base = quantum_base_n;
}



//adaugare user 
static int find_user_index(const sched_t *sched, int uid){
    for(int i=0; i<sched->user_count; i++){
        if(sched->users[i].uid == uid) return i;
    }

    return -1;
}

void sched_add_user(sched_t *sched, int uid, int weight){
    int idx = find_user_index(sched, uid);

    if(idx!=-1){
        //daca exisat userul, doar ii actualizam ponderea
        sched->users[idx].weight = weight;
        return;
    }

    //daca nu exista userul 
    //extinderea vectorului de useri
    user_t *new_users = realloc(sched->users, (sched->user_count + 1) * sizeof(user_t));

    //alocare nereusita
    if(!new_users) exit(1);

    sched->users = new_users;

    user_t *u = &sched->users[sched->user_count];
    u->uid = uid;
    u->weight = weight;
    u->proc_queue_head = NULL;
    u->proc_queue_tail = NULL;

    sched->user_count++;
}



void sched_enqueue_ready(sched_t *sched, proc_t *p) {
    int idx = find_user_index(sched, p->uid);
    if (idx == -1) {
        sched_add_user(sched, p->uid, 1);
        idx = find_user_index(sched, p->uid);
    }

    user_t *u = &sched->users[idx];
    p->next = NULL;

    if (!u->proc_queue_tail) {
        u->proc_queue_head = u->proc_queue_tail = p;
    } else {
        u->proc_queue_tail->next = p;
        u->proc_queue_tail = p;
    }
}



//scheduler
static int min_int(int a, int b) {
    return (a < b) ? a : b;
}

int sched_next(sched_t *sched, sched_decision_t *dec, int *uid) {
    int chosen = -1;

    for (int k = 0; k < sched->user_count; k++) {
        int idx = (sched->rr_index + k) % sched->user_count;
        if (sched->users[idx].proc_queue_head) {
            chosen = idx;
            break;
        }
    }

    if (chosen == -1) {
        dec->proc = NULL;
        dec->slice = 0;
        return 0;
    }

    user_t *u = &sched->users[chosen];

    proc_t *p = u->proc_queue_head;
    u->proc_queue_head = p->next;
    if (!u->proc_queue_head)
        u->proc_queue_tail = NULL;

    int quantum = sched->quantum_base * u->weight;

    dec->proc = p;
    dec->slice = min_int(quantum, p->remaining_ticks);
    if (uid) *uid = u->uid;

    sched->rr_index = (chosen + 1) % sched->user_count;
    return 1;
}