#include "sensor.h"

/*
John Abreu
4/14/2018
*/

int main(int argc, char *argv[]) {
  int x = 0, CYCLE = 1;
  int * sensorNum;
  SENSORS = NULL;

  printf("Please input # of sensors you'd like to install: ");
  scanf("%d",&NUM_OF_SENSORS);
  printf("\nGotcha! I'll install %d of em\n", NUM_OF_SENSORS);

  printf("And how many cycles would you like to run for: ");
  scanf("%d",&NUM_OF_CYCLES);
  printf("\n%d cycles, will do!\n", NUM_OF_CYCLES);

  srand(time(NULL));
  pthread_t sensors[NUM_OF_SENSORS];


  pthread_mutex_init(&lock, NULL);
  pthread_cond_init(&self, NULL);


  while (x < NUM_OF_SENSORS) {
    if((sensorNum = (int *)malloc(sizeof(int))) == NULL) {
      perror("malloc");
      exit(1);
    }
    *sensorNum = x;
    pthread_create(&(sensors[x]), NULL, (void *)sensor, sensorNum);
    x++;
  }

  for (x = 0; x < NUM_OF_SENSORS; x++){
    pthread_join(sensors[x], NULL);
  }
}
