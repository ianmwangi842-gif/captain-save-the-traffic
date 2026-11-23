/*
CH-235
Captain save the traffic project
*/
#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <stdbool.h>

typedef struct {
    char direction;
    int queue_length;
    int total_arrivals;
    int total_departures;
    bool emergency_waiting;
} TrafficDirection;

#endif