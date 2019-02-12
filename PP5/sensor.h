#ifndef _SENSOR_H
#define _SENSOR_H
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

/*
John Abreu
4/14/2018
*/


typedef struct sensor {
  int id;
  int temp;
  int cycle;
  struct sensor *next;
} sensor_t;

pthread_mutex_t lock; /* mutex ensuring exclusive access to buffer */
pthread_cond_t self;

sensor_t *SENSORS;
int CYCLE;
int NUM_OF_SENSORS;
int NUM_OF_CYCLES;

void sensor(int *t);
sensor_t *addToRear(sensor_t *head, sensor_t *newNode);
void addToList(int t, int cycles);
void waitForCycleToFinish(int t, int cycles);
void lastSensorInCycle(int t);
int getTemp();
int numberOfSensors();
void printAll();
int containSensor(int t);
int averageTemp();

#endif
