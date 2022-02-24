import functions as f

inputName = "/Users/oleksandrhumeniuk/Desktop/input.txt"
outputName = "/Users/oleksandrhumeniuk/Desktop/output.txt"

mode = f.chooseMode()

f.createInputFile(inputName, mode)
f.createOutputFile(outputName, inputName)

f.printFile(inputName, "\nInput File:");
f.printFile(outputName, "\n\nOutput File:");
