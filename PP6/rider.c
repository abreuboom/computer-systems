#include "rider.h"
#include "car.h"

/*
John Abreu
4/26/2018
*/


void rider(int *t) {
  int riderNum = *t + 1;

  addRider(riderNum);
  takeRide(riderNum);
  finishRide(riderNum);
  pthread_exit(NULL);
}

rider_t *addRiderToRear(rider_t *head, rider_t *newNode) {
  if (head == NULL) {
    return newNode;
  }
  if (newNode == NULL) {
    return head;
  } else {
    rider_t * temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    return head;
  }
}

void addRider(int t) {
  pthread_mutex_lock(&rider_lock);
  rider_t *r;
  r = (rider_t *)malloc(sizeof(rider_t));
  r->id = t;
  r->next = NULL;
  RIDERS = addRiderToRear(RIDERS, r);

  printf("Welcome to Abreu Park Rider #%d!\n", t);

  pthread_mutex_unlock(&rider_lock);
}

void takeRide(int t) {
  pthread_mutex_lock(&car_lock);

  rider_t *temp = RIDERS;
  while (temp!=NULL){
    if (temp->id == t)
      break;
    else
      temp = temp->next;
  }



  waitForRide(t);

  load(CARS->passengers, temp->id);
  printf("Rider #%d has boarded Car #%d\n", t, CARS->id);
  CARS->seatsTaken++;
  NUM_OF_RIDERS--;

  pthread_mutex_unlock(&car_lock);

  pthread_cond_broadcast(&car_self);
  pthread_cond_broadcast(&rider_self);
}

void waitForRide(int t) {
  while (CARS == NULL || CARS->seatsTaken == CAPACITY) {
    printf("Rider #%d is waiting\n", t);
    pthread_cond_wait(&rider_self, &car_lock);
  }
  pthread_cond_broadcast(&rider_self);
}

void load(rider_t *riders, int t) {
    rider_t *r;
    r = (rider_t *)malloc(sizeof(rider_t));
    r->id = t;
    r->next = NULL;
    riders = addRiderToRear(riders, r);
}

void finishRide(int t) {
  pthread_mutex_lock(&rider_lock);
  while (alreadyRode(t) == 0) {
    if(NUM_OF_RIDERS == 0) {
      break;
    }
    pthread_cond_wait(&rider_self, &rider_lock);
  }

  pthread_mutex_unlock(&rider_lock);
  pthread_cond_broadcast(&car_self);
  pthread_cond_broadcast(&rider_self);
}

// 0 if rider is not done with ride, 1 otherwise
int alreadyRode(int t) {
  if (DONE==NULL){
    return 0;
  }
  rider_t * temp = DONE;

  while (temp!=NULL){
    if (temp->id == t)
      return 1;
    temp = temp->next;
  }
  return 0;
}
