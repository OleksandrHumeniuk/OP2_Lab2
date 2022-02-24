import functions as f


def main():
    inputName = "input.txt"
    outputName = "output.txt"

    mode = f.chooseMode()

    f.createInputFile(inputName, mode)
    f.createOutputFile(outputName, inputName)

    f.printFile(inputName, "Input File:");
    f.printFile(outputName, "\nOutput File:");


if __name__ == '__main__':
    main()

