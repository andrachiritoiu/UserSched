#ifndef PROC_H
#define PROC_H

typedef struct proc{
    int pid;
    int uid;
    int remaining_ticks;
    struct proc *next; //coada
}proc_t;

proc_t* proc_create(int pid, int uid, int ticks);
void proc_run(proc_t *p, int ticks);

#endif