#ifndef PROC_H
#define PROC_H

typedef struct proc{
    int pid;
    int uid;
    int remaining_ticks;
    struct proc *next; //coada
}proc_t;

#endif