#ifndef _CAR_H
#define _CAR_H
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "rider.h"

/*
John Abreu
4/26/2018
*/


typedef struct car {
  int id;
  int seatsTaken;
  rider_t *passengers;

  struct car *next;
} car_t;

pthread_mutex_t car_lock; /* mutex ensuring exclusive access to buffer */
pthread_cond_t car_self;

car_t *CARS;
int NUM_OF_CARS;
int CAPACITY;

void car(int *t);
car_t *addToRear(car_t *head, car_t *newNode);
rider_t *removeRider(rider_t *head, rider_t *newNode);
void addToList(int t);
void loadCustomers(int t);
void unloadCustomers(int t);
void unloadCustomer(int t);
void waitForRideToFinish(int t);
void lastRide(int t);

#endif
