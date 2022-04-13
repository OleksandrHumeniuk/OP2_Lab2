#include "functions.h"


int main()
{
    int mode = chooseMode();                                            // Choosing file opening mode (overwriting/adding)
    vector <TrainTrip> trips = generateTrips();                         // Generate vector of train trips with routes based on users input

    string scheduleFileName = "schedule.dat";                           // File name with whole schedule
    string winterScheduleFileName = "winter_schedule.dat";              // File name with winter schedule

    createSchedule(scheduleFileName, trips, mode);                      // Creating file with schedule      
    createWinterSchedule(scheduleFileName, winterScheduleFileName);     // Creating file with winter schedule
    
    printSchedule(scheduleFileName, "Schedule");                        // Outputting file with schedule in console
    printSchedule(winterScheduleFileName, "Winter Schedule");           // Outputting file with winter schedule in console
}

