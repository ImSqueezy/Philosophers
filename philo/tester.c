#include <stdio.h>
#include <sys/time.h>

#include <stdio.h>
#include <pthread.h>

void	*threadFunction() {
    printf("This is the new thread.\n");
	return (NULL);
}

int main() {
    pthread_t newThread; // Thread identifier
    int threadCreationStatus;

    // Create a new thread
    threadCreationStatus = pthread_create(&newThread, NULL, threadFunction, NULL);

    if (threadCreationStatus != 0) {
        fprintf(stderr, "Error creating thread: %d\n", threadCreationStatus);
        return 1;
    }

    printf("This is the main thread.\n");

    // Wait for the new thread to finish and retrieve its exit status
    void *threadExitStatus;
    pthread_join(newThread, &threadExitStatus);

    printf("The new thread has finished with exit status: %ld\n", (long)threadExitStatus);

    return 0;
}