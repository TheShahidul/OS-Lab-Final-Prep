//dining philosopher [faulty code]


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5  // Number of philosophers

sem_t mutex;  // Semaphore for mutual exclusion
sem_t S[N];   // Semaphore for each philosopher
int state[N]; // Array to keep track of state of each philosopher
int phil[N] = {0, 1, 2, 3, 4};  // Philosopher identifiers

#define THINKING 0
#define HUNGRY 1
#define EATING 2

void test(int phnum) {
    if (state[phnum] == HUNGRY &&
        state[(phnum + 4) % N] != EATING &&
        state[(phnum + 1) % N] != EATING) {
        state[phnum] = EATING;
        sleep(1);  // Simulate eating
        printf("Philosopher %d takes fork %d and %d\n", phnum, (phnum + 4) % N, phnum);
        printf("Philosopher %d is Eating\n", phnum);
        sem_post(&S[phnum]);
    }
}

void take_fork(int phnum) {
    sem_wait(&mutex);  // Enter critical section
    state[phnum] = HUNGRY;
    printf("Philosopher %d is Hungry\n", phnum);
    test(phnum);  // Try to acquire forks
    sem_post(&mutex);  // Leave critical section
    sem_wait(&S[phnum]);  // Block if forks are not available
    sleep(1);  // Simulate eating
}

void put_fork(int phnum) {
    sem_wait(&mutex);  // Enter critical section
    state[phnum] = THINKING;
    printf("Philosopher %d putting fork %d and %d down\n", phnum, (phnum + 4) % N, phnum);
    printf("Philosopher %d is thinking\n", phnum);
    test((phnum + 4) % N);  // Test left neighbor
    test((phnum + 1) % N);  // Test right neighbor
    sem_post(&mutex);  // Leave critical section
}

void* philosopher(void* num) {
    while (1) {
        int* i = num;
        sleep(1);  // Simulate thinking
        take_fork(*i);  // Acquire forks
        sleep(0);  // Simulate eating
        put_fork(*i);  // Release forks
    }
}

int main() {
    int i;
    pthread_t thread_id[N];

    // Initialize the semaphores
    sem_init(&mutex, 0, 1);
    for (i = 0; i < N; i++)
        sem_init(&S[i], 0, 0);

    // Create philosopher threads
    for (i = 0; i < N; i++) {
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
        printf("Philosopher %d is thinking\n", i);
    }

    // Join philosopher threads
    for (i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);

    return 0;
}




//===============================


//


//compilation command

gcc -o dining_philosophers dining_.c -lpthread

//running command

./dining_philosophers

