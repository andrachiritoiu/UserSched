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
