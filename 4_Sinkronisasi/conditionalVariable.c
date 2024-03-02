#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;
// Write numbers 1-3 and 8-10 as permitted by functionCount2()

void *functionCount1() {
    for(;;) {
    // Lock mutex and then wait for signal to relase mutex
    pthread_mutex_lock( &count_mutex );

    // Wait while functionCount2() operates on count
    // mutex unlocked if condition varialbe in functionCount2() signaled.
    count++;
    printf("Counter value functionCount1: %d\n",count);

    pthread_mutex_unlock( &count_mutex );
    if(count >= 10)
        return(NULL);
    }
}

// Write numbers 4-7
void *functionCount2(){
    for(;;) {
        pthread_mutex_lock( &count_mutex );

    if( count < 3 || count > 6 ) {
        // Condition of if statement has been met.
        // Signal to free waiting thread by freeing the mutex.
        // Note: functionCount1() is now permitted to modify "count".
    } else {
        count++;
        printf("Counter value functionCount2: %d\n",count);
    }

    pthread_mutex_unlock( &count_mutex );
    if(count >= 10)
        return(NULL);
    }
}
int main(){
    pthread_t thread1, thread2;
    pthread_create( &thread1, NULL, &functionCount1, NULL);
    pthread_create( &thread2, NULL, &functionCount2, NULL);
    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);
    printf("Final count: %d\n",count);
    exit(EXIT_SUCCESS);
}
