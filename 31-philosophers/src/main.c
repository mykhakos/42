#include "../include/philo.h"

// Thread function
void *threadFunction(void *vargp) {
    int *myNumber = (int *)vargp;
    printf("Thread number: %d\n", *myNumber);
    
    // Free the dynamically allocated memory
    free(myNumber);

    return NULL;
}

int main() {
    const int numThreads = 5;
    pthread_t threads[numThreads];

    for (int i = 0; i < numThreads; ++i) {
        // Dynamically allocate a number for each thread
        int *threadNum = malloc(sizeof(int));
        *threadNum = i;

        // Create a new thread passing the number to it
        pthread_create(&threads[i], NULL, threadFunction, (void *)threadNum);
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

// int main() {
//     struct timeval tv;
//     int ret;

//     while (1)
//     {
//         // Get the current time
//         ret = gettimeofday(&tv, NULL);

//         // Check for errors
//         if (ret == 0) {
//             printf("Seconds: %ld\n", tv.tv_sec);
//             printf("Microseconds: %ld\n", tv.tv_usec);
//         } else {
//             perror("gettimeofday");
//         }
//         usleep(1000000);
//     }


//     return 0;
// }