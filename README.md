# UserSched – User Weighted Round-Robin Scheduler

## Descriere
Acest proiect implementează un **scheduler user weighted round-robin**, conform cerinței proiectului 9 la Sisteme de Operare.

Algoritmul planifică execuția proceselor în funcție de **utilizator**, nu direct de proces:
- utilizatorii sunt parcurși în **ordine round-robin**
- fiecărui utilizator i se alocă un timp de execuție proporțional cu **ponderea (weight)** sa
- pentru utilizatorul selectat, se alege un proces ready care este rulat pentru un **quantum finit**

Proiectul este implementat ca **simulator în user-space**, cu suport pentru statistici și teste.

---

## Structura proiectului
usersched/
├── include/

│   ├── sched.h    # Interfața schedulerului

│   ├── proc.h     # Structura și funcțiile proceselor

│   └── stats.h    # Statistici de execuție

├── src/

│   ├── scheduler.c # Algoritmul user weighted round-robin

│   ├── process.c   # Modelul de proces

│   ├── stats.c     # Colectare și afișare statistici

│   └── main.c      # Simulatorul

├── tests/
│   └── test_basic.c # Teste pentru corectitudine și fairness

├── Makefile

└── README.md
