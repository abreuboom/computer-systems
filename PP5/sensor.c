#include "sensor.h"

/*
John Abreu
4/14/2018
*/


void sensor(int *t) {
  int cycles = 1;
  int sensorNum = *t + 1;
  printf("Initializing sensor %d\n", sensorNum);
  while (cycles <= NUM_OF_CYCLES) {
    addToList(sensorNum, cycles);
    lastSensorInCycle(sensorNum);
    waitForCycleToFinish(sensorNum, cycles);
    cycles++;
    sleep(1);
  }
  printf("all cycles completed, Sensor %d is done\n", sensorNum);
  pthread_exit(NULL);
}

sensor_t *addToRear(sensor_t *head, sensor_t *newNode) {
  if (head == NULL) {
    return newNode;
  }
  if (newNode == NULL) {
    return head;
  } else {
    sensor_t * temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    return head;
  }
}

void addToList(int t, int cycles) {
  pthread_mutex_lock(&lock);
  sensor_t *s;
  s = (sensor_t *)malloc(sizeof(sensor_t));
  s->id = t;
  s->temp = getTemp();
  s->cycle = cycles;
  s->next = NULL;
  SENSORS = addToRear(SENSORS, s);

  pthread_mutex_unlock(&lock);
}

void waitForCycleToFinish(int t, int cycles) {
  pthread_mutex_lock(&lock);
  while (containSensor(t)) {
    pthread_cond_wait(&self, &lock);
  }
  pthread_mutex_unlock(&lock);
}

void lastSensorInCycle(int t) {
  pthread_mutex_lock(&lock);
  if (numberOfSensors() == NUM_OF_SENSORS) {
    CYCLE++;
    printAll();
    printf("The average temperature for cycle %d was %d degrees\n", CYCLE, averageTemp());
    SENSORS = NULL;
  }
  else {
    pthread_cond_wait(&self, &lock);
  }
  pthread_mutex_unlock(&lock);
  pthread_cond_broadcast(&self);
}

int getTemp() { return 1 + rand() % 100; }

int numberOfSensors() {
  int x = 0;
  sensor_t *temp = SENSORS;

  if (temp == NULL) {
    return x;
  }
  while (temp != NULL) {
    x++;
    temp = temp->next;
  }
  return x;
}

void printAll() {
  if (SENSORS == NULL) {
    puts("List is EMPTY");
    return;
  }
  sensor_t * temp = SENSORS;
  while(temp!=NULL) {
    printf("Sensor %d read a temperature of %d in cycle %d\n", temp->id, temp->temp, temp->cycle);
    temp = temp->next;
  }

}


// 0 if the sensor is not in the Global list, 1 otherwise
int containSensor(int t) {
  if (SENSORS==NULL){
    return 0;
  }
  sensor_t * temp = SENSORS;

  while (temp!=NULL){
    if (temp->id == t)
      return 1;
    temp = temp->next;
  }
  return 0;
}

int averageTemp() {
  if (SENSORS == NULL)
    puts("Sensor List is NULL");

  int sum = 0, count = 0;
  sensor_t *temp = SENSORS;
  while (temp != NULL) {
    sum = sum + temp->temp;
    count++;
    temp = temp->next;
  }
  return sum / count;
}
