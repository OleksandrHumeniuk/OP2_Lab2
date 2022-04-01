import functions as f


def main():
    inputName = "input.txt"                     # Name of input file
    outputName = "output.txt"                   # Name of output file

    mode = f.chooseMode()                       # Variable for mode of information input (adding/overwriting)

    f.createInputFile(inputName, mode)          # Creates input file based on inputted text
    f.createOutputFile(outputName, inputName)   # Creates outfile file based on input file

    f.printFile(inputName, "\nInput File:");        # Outputs input file in console
    f.printFile(outputName, "\n\nOutput File:");    # Outputs output file in console


if __name__ == '__main__':
    main()

