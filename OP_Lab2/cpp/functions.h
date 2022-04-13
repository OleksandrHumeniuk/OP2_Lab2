#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <math.h>
#include <vector>

using namespace std;
const size_t kRouteNameSize = 15;

struct TrainTime {
    int hours;
    int minutes;
};

struct TrainTrip {
    int tripNum;
    char tripRoute[kRouteNameSize];
    TrainTime departureTime;
    TrainTime arrivalTime;
};

int chooseMode();
vector <TrainTrip> generateTrips();
void createSchedule(string fileName, vector <TrainTrip> trips, int mode);
void createWinterSchedule(string scheduleFileName, string winterScheduleFileName);
void printSchedule(string fileName, string header);
