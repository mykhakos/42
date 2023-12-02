# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <semaphore.h>


int create_children(int count, pid_t *child_pids)
{
    pid_t pid;
    int i;
    int j;

    i = 0;
    while (i < count)
    {
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork");
            return (-1);
        }
        if (pid == 0)
        {
            printf("Hello from child %i\n", i);
            j = 0;
            while (j < 4)
            {
                printf("Child %i performs action %i\n", i, j);
                j++;
                sleep(1);
            }
            printf("Child %i finished.\n", i);
            return (0);
        }
        child_pids[i] = pid;
        i++;
    }
    return (pid);
}

int main(void)
{
    pid_t *child_pids;
    int num_children;
    int res;
    int i;
    
    num_children = 5;
    child_pids = malloc(num_children * sizeof(pid_t));
    if (child_pids == NULL) {
        perror("Failed to allocate memory");
        return (EXIT_FAILURE);
    }
    res = create_children(num_children, child_pids);
    if (res == -1)
    {
        free(child_pids);
        return (EXIT_FAILURE);
    }
    if (res != 0)
    {
        printf("Parent pausing children\n");
        i = 0;
        while (i < num_children)
        {
            kill(child_pids[i], SIGSTOP);
            i++;
        }
        i = 0;
        while (i < num_children)
        {
            printf(
                "Parent process returned after creating child process %i: \
                pid=%i\n", i, child_pids[i]);
            i++;
            sleep(1);
        }
        printf("Parent resuming children\n");
        i = 0;
        while (i < num_children)
        {
            kill(child_pids[i], SIGCONT);
            i++;
        }
        i = 0;
        while (i < num_children)
        {
            if (waitpid(child_pids[i], NULL, 0) < 0)
            {
                perror("waitpid");
                free(child_pids);
                return (EXIT_FAILURE);
            }
            i++;
        }
    }
    free(child_pids);
    return (EXIT_SUCCESS);
}
