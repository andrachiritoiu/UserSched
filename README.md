# UserSched – User Weighted Round-Robin Scheduler

## Description
This project implements a **User Weighted Round-Robin scheduler**.

The algorithm schedules process execution based on **users**, not directly on individual processes:
- users are traversed in **round-robin order**
- each user is assigned an execution time proportional to their **weight**
- for the selected user, a ready process is chosen and executed for a **finite quantum**

The project is implemented as a **user-space simulator**, with support for statistics and testing.

---

## Project Structure

```text
usersched/
├── include/           # Header files (Interfaces)
│   ├── sched.h        # Public scheduler interface
│   ├── proc.h         # Process structure and helper functions
│
├── src/               # Source code (Implementation)
│   ├── scheduler.c    # User Weighted RR algorithm implementation
│   ├── process.c      # Process model (creation, execution)
│   └── main.c         # Entry point (Simulator)
│
├── Makefile           # Build script
── README.md          # Project documentation
```


## Algorithm Overview

The scheduler uses a **two-level scheduling strategy**:

### 1. User-Level Scheduling (Round-Robin)
- Users are scheduled in **round-robin order**
- Only users with at least one ready process are considered
- A round-robin index (`rr_index`) ensures fair traversal

### 2. Process-Level Scheduling (FIFO)
- Each user maintains a **FIFO queue** of ready processes
- Once a user is selected, the first process in the queue is chosen

-----
## Run

After building the project, run the scheduler simulator using:

```bash
./usersched
```

Alternatively, if the `run` target is defined in the Makefile, you can execute:

```bash
make run
```
