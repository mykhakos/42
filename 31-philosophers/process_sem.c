#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>

#define SEM_NAME "/mysemaphore"

int create_children(int count, pid_t *child_pids, sem_t *sem) {
    pid_t pid;
    int i;

    for (i = 0; i < count; i++) {
        pid = fork();
        if (pid < 0) {
            perror("fork");
            return (-1);
        }
        if (pid == 0) { // Child process
            printf("Hello from child %i\n", i);
            sem_wait(sem); // Wait on semaphore
            for (int j = 0; j < 4; j++) {
                printf("Child %i performs action %i\n", i, j);
                sleep(1);
            }
            printf("Child %i finished.\n", i);
            exit(0);
        }
        child_pids[i] = pid;
    }
    return 0;
}

int main(void) {
    pid_t *child_pids;
    int num_children = 5;
    sem_t *sem;

    // Initialize semaphore with value 0 (blocked)
    sem = sem_open(SEM_NAME, O_CREAT, 0644, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    child_pids = malloc(num_children * sizeof(pid_t));
    if (child_pids == NULL) {
        perror("Failed to allocate memory");
        sem_unlink(SEM_NAME);
        sem_close(sem);
        return (EXIT_FAILURE);
    }

    if (create_children(num_children, child_pids, sem) == -1) {
        free(child_pids);
        sem_unlink(SEM_NAME);
        sem_close(sem);
        return (EXIT_FAILURE);
    }

    // Simulating the parent pausing children (children are already waiting on semaphore)
    printf("Parent process paused children\n");

    // Parent process waits before resuming children
    for (int i = 0; i < num_children; i++) {
        printf("Parent process will resume child %i: pid=%i\n", i, child_pids[i]);
        sleep(1);
    }

    // Release the semaphore to allow children to proceed
    printf("Parent process resuming children\n");
    for (int i = 0; i < num_children; i++) {
        sem_post(sem);
    }

    // Wait for child processes to complete
    for (int i = 0; i < num_children; i++) {
        if (waitpid(child_pids[i], NULL, 0) < 0) {
            perror("waitpid");
        }
    }

    // Cleanup
    free(child_pids);
    sem_unlink(SEM_NAME);
    sem_close(sem);

    return (EXIT_SUCCESS);
}
