#include "../include/philo.h"

sem_t *sem_safeopen(char *sem_name, int sem_value)
{
    sem_t *sem;

    sem_unlink(sem_name);
    sem = sem_open(sem_name, O_CREAT, 0644, sem_value);
    if (sem == SEM_FAILED)
    {
        perror("sem_open");
        return (NULL);
    }
    return (sem);
}

void sem_safeclose(sem_t **sem, char *sem_name)
{
    if (sem != NULL && *sem != NULL && *sem != SEM_FAILED)
    {
        if (sem_unlink(sem_name) != 0)
        {
            perror("sem_unlink");
        }
        if (sem_close(*sem) != 0)
        {
            perror("sem_close");
        }
        *sem = NULL;
    }
}
