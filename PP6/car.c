#include "car.h"
#include "rider.h"

/*
John Abreu
4/26/2018
*/


void car(int *t) {
  int carNum = *t + 1;
  addToList(carNum);
  pthread_cond_broadcast(&rider_self);
  while (NUM_OF_RIDERS != 0) {
    loadCustomers(carNum);
    unloadCustomers(carNum);
  }
  printf("Abreu Park is empty, ride %d is shutting down\n", carNum);
  pthread_exit(NULL);
}

car_t *addToRear(car_t *head, car_t *newNode) {
  if (head == NULL) {
    return newNode;
  }
  if (newNode == NULL) {
    return head;
  } else {
    car_t * temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    return head;
  }
}

void addToList(int t) {
  pthread_mutex_lock(&car_lock);
  car_t *c;
  c = (car_t *)malloc(sizeof(car_t));
  c->id = t;
  c->seatsTaken = 0;
  c->passengers = NULL;
  c->next = NULL;
  CARS = addToRear(CARS, c);
  printf("Car #%d is ready for duty\n", t);

  pthread_mutex_unlock(&car_lock);
  pthread_cond_broadcast(&rider_self);
}

void loadCustomers(int t) {
  pthread_mutex_lock(&car_lock);

  car_t *c = CARS;
  while(c->id != t){
    c = c->next;
  }

  while(c->seatsTaken < CAPACITY && NUM_OF_RIDERS > 0) {
    pthread_cond_wait(&car_self, &car_lock);
  }

  printf("Car #%d is on it's way... CHOO CHOO!\n", t);
  sleep(1);
  pthread_mutex_unlock(&car_lock);

  pthread_cond_broadcast(&rider_self);
}

void unloadCustomers(int t) {
  pthread_mutex_lock(&rider_lock);
  pthread_mutex_lock(&car_lock);

  rider_t *temp = CARS->passengers;
  rider_t *r;
  while(temp!=NULL) {
    r = (rider_t *)malloc(sizeof(rider_t));
    r->id = temp->id;
    r->next = NULL;

    DONE = addRiderToRear(DONE, r);
    printf("Rider #%d is leaving Abreu Park\n", r->id);
    temp = temp->next;
  }

  CARS->passengers = NULL;
  CARS->seatsTaken = 0;

  printf("Car #%d has finished a ride, accepting new passengers\n", t);

  pthread_mutex_unlock(&car_lock);
  pthread_mutex_unlock(&rider_lock);
  pthread_cond_broadcast(&car_self);
  pthread_cond_broadcast(&rider_self);
}


/*
void waitForRideToFinish(int t, int cycles) {
  pthread_mutex_lock(&lock);
  while (containSensor(t)) {
    pthread_cond_wait(&self, &lock);
  }
  pthread_mutex_unlock(&lock);
}

void lastRide(int t) {
  pthread_mutex_lock(&rider_lock);
  pthread_mutex_lock(&car_lock);
  if (NUM_OF_RIDERS == 0) {
    RIDERS = NULL;
  }
  else {
    pthread_cond_wait(&car_self, &rider_lock);
  }
  pthread_mutex_unlock(&rider_lock);
  pthread_mutex_unlock(&car_lock);
  pthread_cond_broadcast(&car_self);
}

*/
