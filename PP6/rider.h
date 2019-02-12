#ifndef _RIDER_H
#define _RIDER_H
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

/*
John Abreu
4/26/2018
*/


typedef struct rider {
  int id;

  struct rider *next;
} rider_t;

pthread_mutex_t rider_lock; /* mutex ensuring exclusive access to buffer */
pthread_cond_t rider_self;

rider_t *RIDERS;
rider_t *DONE;
int NUM_OF_RIDERS;

void rider(int *t);
rider_t *addRiderToRear(rider_t *head, rider_t *newNode);
void addRider(int t);
void takeRide(int t);
void load(rider_t * riders, int t);
void waitForRide(int t);
void finishRide(int t);
int alreadyRode(int t);


#endif
