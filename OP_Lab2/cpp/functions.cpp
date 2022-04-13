#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <math.h>
#include <vector>

using namespace std;
const size_t kRouteNameSize = 15;                //Constant size of char array - name of trip routes                           

/* Defines time that is used for train schedules.
 * Consists of number of hours and number of minutes 
 */
struct TrainTime {
    int hours;
    int minutes;
};


/* Defines structure of train trips that are used for train schedules.
 * Consists of trip number (ID), trip route (direction),
 * and variables with custom-made time type: departure time and arrival time
 */
struct TrainTrip {
    int tripNum;
    char tripRoute[kRouteNameSize];
    TrainTime departureTime;
    TrainTime arrivalTime;
};


// This enum and function is used to let user choose the mode for information input (overwriting or adding)
enum Mode {
    OVERWRITING = 1,												// Overwriting mode: program erases any text that the file might have
    ADDING = 2														// Adding mode: program writes text on top of text from the file
};
int chooseMode() {
    string ch;														// Character that user writes to choose mode
    cout << "Choose writing mode (1 - for overwriting file, 2 - for adding to file): ";
    cin >> ch;

    while (ch != "1" && ch != "2") {								// The function will ask for user input, until it's "1" or "2"
        cout << "You may only enter a '1' or an '2'!" << endl;
        cout << "Choose writing mode (1 - for overwriting file, 2 - for adding to file): ";
        cin >> ch;
    }

    return stoi(ch);												// The function returns an int 1, which in enum Mode stands for OVERWRITING,
}


/* Generates departure and arrival times with hours number based on "hours" and random minutes number.
 * Round number of hours and minutes, so they can't be greater than 23 and 59 respectively
 */
void generateTrainTime(int hours, TrainTime& depTime, TrainTime& arrTime) {
    depTime = { rand() % 24, rand() % 60 };
    arrTime = { (depTime.hours + hours) % 24, rand() % 60 };
}


/* Generates 3-5 trip with route name "routeName" and trip number "tripNumber" (with each trip tripNumber increases by one). 
 * Each trip last for about "tripLength" hours. Appends generated trips to "trips" vector
 */
void generateRouteTrips(char routeName[kRouteNameSize], int& tripNumber, int tripLength, vector <TrainTrip>& trips) {

    for (int i = 0; i < rand()%3 + 3; i++) {
        TrainTrip trip;
        trip.tripNum = tripNumber;
        generateTrainTime(tripLength, trip.departureTime, trip.arrivalTime);
        strncpy_s(trip.tripRoute, routeName, kRouteNameSize);
        trips.push_back(trip);
        tripNumber++;
    }
}


// Checks if string "s" constists only of digit characters
bool isNum(string s)
{
    for (char ch : s) {
        if (!isdigit(ch)) return false;
    }
    return true;
}


// Allows to input only positive integers
int inputNum(string text) {
    string n;
    cout << text << ": ";
    cin >> n;

    while (!isNum(n)) {
        cout << "You can only enter a positive integer: ";
        cin >> n;
    }
    cin.ignore();
    return stoi(n);
}


/* Asks user for number of routes and name for each one.
 * Then generates train trips for each route, using function "generateRouteTrips"
 * Returns a vector with all train trips
 */
vector <TrainTrip> generateTrips() {
    srand(unsigned(time(NULL)));

    int numOfRoutes = inputNum("Enter the number of routes (directions)");      // Number of all routes

    int tripNumber = 11111;                                                     // Trip number starts 11111 and increases by one with each trip
    vector <TrainTrip> trips;                                                   // Vector, consisted of all trips

    for (int i = 0; i < numOfRoutes; i++) {
        char routeName[kRouteNameSize];
        cout << "Enter name of route #" << i + 1 << ": ";
        cin.getline(routeName, kRouteNameSize);
        generateRouteTrips(routeName, tripNumber, rand() % 6 + 2, trips);
    }

    return trips;
}


// Writes all trips from vector "trips" into file with name "fileName" with writing mode "mode"
void createSchedule(string fileName, vector <TrainTrip> trips, int mode) {

    ofstream file;

    if (Mode::OVERWRITING == mode) {
        file.open(fileName, ios::binary);
    }
    else {
        file.open(fileName, ios::binary | ios::app);
    }

    for (TrainTrip trip : trips) {
        file.write(reinterpret_cast<char*>(&trip), sizeof(TrainTrip));
    }
    file.close();
}


// Checks whether a trip is a winter trip. Winter trips are trips before 10:00 or after 18:00
bool isWinterTrip(TrainTrip trip) {

    bool isMorningDeparture = trip.departureTime.hours < 10;
    bool isEveningDeparture = trip.departureTime.hours > 18 || (trip.departureTime.hours == 18 && trip.departureTime.minutes != 0);

    bool isMorningArrival = trip.arrivalTime.hours < 10;
    bool isEveningArrival = trip.arrivalTime.hours > 18 || (trip.arrivalTime.hours == 18 && trip.arrivalTime.minutes != 0);
    
    /* A trip is winter only if it: 
     * starts in the morning and finishes in the morning OR 
     * starts in the evening and finishes in the evening OR
     * start in the evening and finishes in the morning
     */
    if ((isMorningDeparture && isMorningArrival) || (isEveningDeparture && (isEveningArrival || isMorningArrival))) {
        return true;
    }
    else {
        return false;
    }
}


/* Reads all trips from file "scheduleFileName" and writes only winter one to vector "trips".
 * Using functions "createSchedule" writes all winter trips in the "winterScheduleFileName" file
 */
void createWinterSchedule(string scheduleFileName, string winterScheduleFileName) {

    vector <TrainTrip> trips;
    TrainTrip trip;
    ifstream schedule(scheduleFileName, ios::binary);

    while (schedule.read(reinterpret_cast<char*>(&trip), sizeof(TrainTrip))) {
        if (isWinterTrip(trip)) trips.push_back(trip);
    }

    schedule.close();

    createSchedule(winterScheduleFileName, trips, 1);
}


// Prints all properties of "trip" in the console
void printTrip(TrainTrip trip) {
    cout << "Trip Number: " << trip.tripNum;
    cout << " Route: " << trip.tripRoute;
    cout << " Departure Time: " << setw(2) << setfill('0') << trip.departureTime.hours << ":" << setw(2) << setfill('0') << trip.departureTime.minutes;
    cout << " Arrival Time: " << setw(2) << setfill('0') << trip.arrivalTime.hours << ":" << setw(2) << setfill('0') << trip.arrivalTime.minutes << endl;
}


/* Writes string "header" first.
 * Reads all trips from "fileName" and prints them(their properties) in the console, using functions "printTrip".
 * Visually split output of trips with different routes into different sections.
 */
void printSchedule(string fileName, string header) {

    ifstream schedule(fileName, ios::binary);
    TrainTrip trip;
    char tripRoute[kRouteNameSize];

    cout << "\n" << header << "\n";

    if (schedule.read(reinterpret_cast<char*>(&trip), sizeof(TrainTrip))) {             // If file consists of at least one trip
        do {
            strncpy_s(tripRoute, trip.tripRoute, kRouteNameSize);                       // Copy the route name of trip to "tripRoute" (current route)               
            cout << "Route Name: " << tripRoute << endl;
            printTrip(trip);

            while (schedule.read(reinterpret_cast<char*>(&trip), sizeof(TrainTrip)) && !strcmp(trip.tripRoute, tripRoute)) { 
                printTrip(trip);                                                        // Prints all trips with route Name "routeName"
            }                                                                           // and break after first trips with different route name 
            cout << "\n";                                                               // or after last trip in the file

        } while (!schedule.eof());                                                      // Prints trip until the end of the file
    }

    schedule.close();
}