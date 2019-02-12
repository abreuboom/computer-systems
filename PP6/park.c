#include "car.h"
#include "rider.h"

/*
John Abreu
4/26/2018
*/

int main(int argc, char *argv[]) {
  int x = 0;
  int *carNum;
  int *riderNum;
  NUM_OF_CARS = 1;
  NUM_OF_RIDERS =  atoi(argv[1]);
  CAPACITY = atoi(argv[2]);

  printf("Welcome to Abreu Park!\nThere are %d riders today.\n", NUM_OF_RIDERS);
  printf("Coaster's max occupancy: %d\n", CAPACITY);


  srand(time(NULL));
  pthread_t riders[NUM_OF_RIDERS];
  pthread_t cars[NUM_OF_CARS];

  pthread_mutex_init(&car_lock, NULL);
  pthread_cond_init(&car_self, NULL);
  pthread_mutex_init(&rider_lock, NULL);
  pthread_cond_init(&rider_self, NULL);

  while (x < NUM_OF_CARS) {
    if((carNum = (int *)malloc(sizeof(int))) == NULL) {
      perror("malloc");
      exit(1);
    }
    *carNum = x;
    pthread_create(&(cars[x]), NULL, (void *)car, carNum);
    x++;
  }
  x = 0;

  while (x < NUM_OF_RIDERS) {
    if((riderNum = (int *)malloc(sizeof(int))) == NULL) {
      perror("malloc");
      exit(1);
    }
    *riderNum = x;
    pthread_create(&(riders[x]), NULL, (void *)rider, riderNum);
    x++;
  }
  x = 0;



  for (x = 0; x < NUM_OF_RIDERS; x++){
    pthread_join(riders[x], NULL);
  }

  for (x = 0; x < NUM_OF_CARS; x++){
    pthread_join(cars[x], NULL);
  }
}
