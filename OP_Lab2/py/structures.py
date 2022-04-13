# Defines class of time that is used for train schedules.
# Consists of number of hours and number of minutes
class TrainTime:
    def __init__(self, hours, minutes):
        self.hours = hours
        self.minutes = minutes


# Defines class of train trips that are used for train schedules.
# Consists of trip number (ID), trip route (direction),
# and variables with custom-made time type: departure time and arrival time
class TrainTrip:
    def __init__(self, tripRoute, tripNum, departureTime, arrivalTime):
        self.tripRoute = tripRoute
        self.tripNum = tripNum
        self.departureTime = departureTime
        self.arrivalTime = arrivalTime
