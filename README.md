# UserSched – User Weighted Round-Robin Scheduler

## Descriere
Acest proiect implementează un **scheduler user weighted round-robin**.

Algoritmul planifică execuția proceselor în funcție de **utilizator**, nu direct de proces:
- utilizatorii sunt parcurși în **ordine round-robin**
- fiecărui utilizator i se alocă un timp de execuție proporțional cu **ponderea (weight)** sa
- pentru utilizatorul selectat, se alege un proces ready care este rulat pentru un **quantum finit**

Proiectul este implementat ca **simulator în user-space**, cu suport pentru statistici și teste.

---

## Structura proiectului

```text
usersched/
├── include/           # Header files (Interfețe)
│   ├── sched.h        # Interfața publică a schedulerului
│   ├── proc.h         # Structura proceselor și funcții auxiliare
│   └── stats.h        # Definiții pentru statistici de execuție
│
├── src/               # Codul sursă (Implementare)
│   ├── scheduler.c    # Implementarea algoritmului User Weighted RR
│   ├── process.c      # Modelul de proces (creare, stări)
│   ├── stats.c        # Logică pentru colectare și afișare statistici
│   └── main.c         # Punctul de intrare (Simulatorul)
│
├── tests/             # Suita de teste
│   └── test_basic.c   # Teste de bază (corectitudine și fairness)
│
├── Makefile           # Script de compilare
└── README.md          # Documentația proiectului
```

