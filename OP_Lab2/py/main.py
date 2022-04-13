import functions as f


def main():
    mode = f.chooseMode()                               # Choosing file opening mode (overwriting/adding)
    trips = f.generateTrips()                           # Generate list of train trips with routes based on users input

    scheduleFileName = "schedule.dat"                   # File name with whole schedule
    winterScheduleFileName = "winter_schedule.dat"      # File name with winter schedule

    f.createSchedule(scheduleFileName, trips, mode)                     # Creating file with schedule
    f.createWinterSchedule(scheduleFileName, winterScheduleFileName)    # Creating file with  winter schedule

    f.printSchedule(scheduleFileName, "Schedule")                      # Outputting file with schedule in console
    f.printSchedule(winterScheduleFileName, "Winter Schedule")         # Outputting file with winter schedule in console


if __name__ == '__main__':
    main()
