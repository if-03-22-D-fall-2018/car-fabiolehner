#include "car.h"

#define CAR_PARK_SIZE 6
struct CarData{
  CarType type;
  int max_speed;
  double fill_level;
  double acceleration_rate;
  int speed;
  double lowest_acceleration_rate;
  double highest_acceleration_rate;
};

struct CarImplementation{
  Color color;
  struct CarData data;
  bool is_rented;
};

struct CarData aixam={AIXAM,45,16.0,0.0,0,-8.0,1.0};
struct CarData fiat_multipla={FIAT_MULTIPLA,170,65.0,0.0,0,-8.0,2.26};
struct CarData jeep={JEEP,196,80.0,0.0,0,-8.0,3.14};

struct CarImplementation aixam1={RED,aixam,false};
struct CarImplementation fiat_multipla1={GREEN,fiat_multipla,false};
struct CarImplementation fiat_multipla2={BLUE,fiat_multipla,false};
struct CarImplementation fiat_multipla3={ORANGE,fiat_multipla,false};
struct CarImplementation jeep1={SILVER,jeep,false};
struct CarImplementation jeep2={BLACK,jeep,false};

Car carpark[6]={&aixam1,&fiat_multipla1,&fiat_multipla2,&fiat_multipla3,&jeep1,&jeep2};

Car get_car(enum CarType type)
{
  for (int i = 0; i < CAR_PARK_SIZE; i++) {
    if (carpark[i]->data.type == type && carpark[i]->is_rented == false) {
      carpark[i]->is_rented = true;
      return carpark[i];

    }
  }
  return 0;
}

enum CarType get_type(Car car)
{
  return car->data.type;
}

enum Color get_color(Car car)
{
  return car->color;
}

double get_fill_level(Car car)
{
  return car->data.fill_level;
}

double get_acceleration_rate(Car car)
{
  return car->data.acceleration_rate;
}

int get_speed(Car car)
{
  if (car->data.speed - (int)car->data.speed >= .5) {
      return (int)car->data.speed + 1;
    }
    return (int)car->data.speed;
}

void init()
{
  for (int i = 0; i < CAR_PARK_SIZE; i++) {
    carpark[i]->data.speed= 0;
    carpark[i]->data.acceleration_rate = 0;
    carpark[i]->is_rented = false;
  }
}

void set_acceleration_rate(Car car, double acceleration_rate)
{
  if(acceleration_rate >= car->data.lowest_acceleration_rate && acceleration_rate <= car->data.highest_acceleration_rate){
    car->data.acceleration_rate = acceleration_rate;
  }
  else if(acceleration_rate < car->data.lowest_acceleration_rate){
    car->data.acceleration_rate = car->data.lowest_acceleration_rate;
  }
  else{
    car->data.acceleration_rate = car->data.highest_acceleration_rate;
  }
}

void accelerate(Car car)
{
}
