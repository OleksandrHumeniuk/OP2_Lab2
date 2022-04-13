import pickle
import random
import structures as struct


#Allows to input only positive integers
def inputNum(text):
    text += ": "
    num = input(text)
    while (not num.isdigit()) or int(num) < 0:
        print(f"{num} isn't a positive number!")
        num = input(text)
    return int(num)


# Generates departure and arrival times with hours number based on "hours" and random minutes number.
# Round number of hours and minutes, so they can't be greater than 23 and 59 respectively
def generateTrainTime(hours):
    depTime = struct.TrainTime(random.randint(0, 23), random.randint(0, 59))
    arrTime = struct.TrainTime((depTime.hours + hours) % 24, random.randint(0, 59))
    return depTime, arrTime


# Generates 3-5 trip with route name "routeName" and trip number "tripNumber" (with each trip tripNumber increases by
# one). Each trip last for about "tripLength" hours. Appends generated trips to "trips" list
def generateRouteTrips(tripRoute, tripNum, tripLength, trips):
    for i in range(random.randint(3, 5)):
        depTime, arrTime = generateTrainTime(tripLength)
        trip = struct.TrainTrip(tripRoute, tripNum, depTime, arrTime)
        trips.append(trip)
        tripNum += 1
    return tripNum


# Asks user for number of routes and name for each one.
# Then generates train trips for each route, using function "generateRouteTrips"
# Returns a list with all train trips
def generateTrips():
    trips = []
    tripNum = 11111
    numOfRoutes = inputNum("Enter the number of routes (directions)")
    for i in range(numOfRoutes):
        tripRoute = input(f"Enter name of route #{i + 1} : ")
        tripNum = generateRouteTrips(tripRoute, tripNum, random.randint(2, 8), trips)
    return trips


# Lets user choose the mode for information input (overwriting or adding)
def chooseMode():
    ch = input("Choose writing mode (1 - for overwriting text, 2 - for adding text): ")
    while ch != "1" and ch != "2":
        print("You may only enter a '1' or an '2'!")
        ch = input("Choose writing mode (1 - for overwriting text, 2 - for adding text): ")

    if ch == "1":
        return "wb"
    else:
        return "ab"


# Writes all trips from list "trips" into file with name "fileName" with writing mode "mode"
def createSchedule(fileName, trips, mode):
    with open(fileName, mode) as file:
        for trip in trips:
            pickle.dump(trip, file)


# Checks whether a trip is a winter trip. Winter trips are trips before 10:00 or after 18:00
def isWinterTrip(trip):
    isMorningDeparture = trip.departureTime.hours < 10
    isEveningDeparture = trip.departureTime.hours > 18 or (trip.departureTime.hours == 18 and trip.departureTime.minutes != 0)
    isMorningArrival = trip.arrivalTime.hours < 10
    isEveningArrival = trip.arrivalTime.hours > 18 or (trip.arrivalTime.hours == 18 and trip.arrivalTime.minutes != 0)

    if (isMorningDeparture and isMorningArrival) or (isEveningDeparture and (isEveningArrival or isMorningArrival)):
        return True
    else:
        return False


# Reads all trips from file "scheduleFileName" and writes only winter one to list "trips".
# Using functions "createSchedule" writes all winter trips in the "winterScheduleFileName" file
def createWinterSchedule(scheduleFileName, winterScheduleFileName):
    winterTrips = []
    with open(scheduleFileName, "rb") as schedule:
        while True:
            try:
                trip = pickle.load(schedule)
                if isWinterTrip(trip) : winterTrips.append(trip)
            except EOFError:
                break

    createSchedule(winterScheduleFileName, winterTrips, "wb")


#Prints all properties of "trip" in the console
def printTrip(trip):
    print(f"Trip Number: {trip.tripNum} Direction: {trip.tripRoute}", end=" ")
    print(f"Departure Time: {str(trip.departureTime.hours).zfill(2)}:{str(trip.departureTime.minutes).zfill(2)}",
          end=" ")
    print(f"Arrival Time: {str(trip.arrivalTime.hours).zfill(2)}:{str(trip.arrivalTime.minutes).zfill(2)}")


# Writes string "header" first.
# Reads all trips from "fileName" and prints them(their properties) in the console, using functions "printTrip".
# Visually split output of trips with different routes into different sections.
def printSchedule(fileName, header):
    print("\n" + header)

    trips = []
    with open(fileName, "rb") as schedule:
        while True:
            try:
                trips.append(pickle.load(schedule))
            except EOFError:
                break
    i = 0
    while i < len(trips):
        tripRoute = trips[i].tripRoute
        print(f"Direction Name: {tripRoute}")
        printTrip(trips[i])
        i += 1
        while i < len(trips) and tripRoute == trips[i].tripRoute:
            printTrip(trips[i])
            i += 1
        print("")
