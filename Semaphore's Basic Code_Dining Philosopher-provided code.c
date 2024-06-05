#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h> // Include for sleep function

#define NUM_PHILOSOPHERS 5

pthread_mutex_t forks[NUM_PHILOSOPHERS];
sem_t max_diners;

void *philosopher(void *num) {
    long id = (long)num;
    int leftFork = id;
    int rightFork = (id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %ld is thinking.\n", id);
        sleep(1); // Simulate thinking

        // Limit the number of philosophers trying to eat at the same time
        sem_wait(&max_diners);

        pthread_mutex_lock(&forks[leftFork]);
        printf("Philosopher %ld picked up fork %d.\n", id, leftFork);

        pthread_mutex_lock(&forks[rightFork]);
        printf("Philosopher %ld picked up fork %d.\n", id, rightFork);

        printf("Philosopher %ld is eating.\n", id);
        sleep(1);

        pthread_mutex_unlock(&forks[rightFork]);
        pthread_mutex_unlock(&forks[leftFork]);

        sem_post(&max_diners);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    long i;

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }
    sem_init(&max_diners, 0, NUM_PHILOSOPHERS - 1);

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, (void *)i);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }
    sem_destroy(&max_diners);

    return 0;
}
