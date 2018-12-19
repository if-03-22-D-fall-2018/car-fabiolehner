/*----------------------------------------------------------
*				HTBLA-Leonding / Klasse: 2DHIF
* ---------------------------------------------------------
* Exercise Number: 0
* Title:			car.h
* Author:			Fabio LEhner
* Due Date:		6. Dezmber 2018
* ----------------------------------------------------------
* Description:
* Car abstract data type demo.
* ----------------------------------------------------------
*/
#ifndef ___CAR_H
#define ___CAR_H

typedef struct CarImplementation* Car;

enum CarType{AIXAM, FIAT_MULTIPLA, JEEP};
enum Color{RED, GREEN, BLUE, ORANGE, SILVER, BLACK};

Car get_car(enum CarType type);

enum CarType get_type(Car car);
enum Color get_color(Car car);

double get_fill_level(Car car);
double get_acceleration_rate(Car car);

int get_speed(Car car);

void init();
void set_acceleration_rate(Car car, double acceleration_rate);
void accelerate(Car car);

#endif
