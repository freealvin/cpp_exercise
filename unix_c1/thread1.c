#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int global = 0;

void *thread_function(void *arg){
    int i;

    for(i=0;i<20;i++){
        printf("Thread says hi!\n");
        int j;
        j = global;
        j += 1;
        sleep(1);
        global = j;
    }

    return NULL;
}

int main(void){
    pthread_t mythread;

    if(pthread_create(&mythread, NULL, thread_function, NULL)){
        printf("error creating thread.");
        abort();
    }

    int i;
    for(i=0;i<20;i++)
    {
        global += 1;
        printf("main global\n");
        fflush(stdout);
        sleep(1);
    }
    if(pthread_join(mythread, NULL)){
        printf("error joining thread.");
        abort();
    }

    printf("\n myglobal equals %d\n", global);
    //printf("from main\n");

    exit(0);
}
