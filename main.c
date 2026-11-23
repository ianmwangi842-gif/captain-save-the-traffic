#include <stdio.h>
#include "traffic.h"

void update_traffic(TrafficDirection *direction,
                    int arrivals,
                    int departures)
{
    if (departures > direction->queue_length + arrivals)
    {
        departures = direction->queue_length + arrivals;
    }

    direction->queue_length += arrivals - departures;
    direction->total_arrivals += arrivals;
    direction->total_departures += departures;
}

int main(void)
{
    TrafficDirection directions[4] = {
        {'N', 0, 0, 0, false},
        {'S', 0, 0, 0, false},
        {'E', 0, 0, 0, false},
        {'W', 0, 0, 0, false}
    };

    directions[0].queue_length = 15;
    directions[1].queue_length = 8;
    directions[2].queue_length = 12;
    directions[3].queue_length = 20;

    update_traffic(&directions[2], 2, 15);

    for (int i = 0; i < 4; i++)
    {   
        printf("Direction: %c\n", directions[i].direction);
        printf("Waiting vehicles: %d\n", directions[i].queue_length);
        printf("Total arrivals: %d\n", directions[i].total_arrivals);
        printf("Total departures: %d\n", directions[i].total_departures);
    }


    return 0;
}