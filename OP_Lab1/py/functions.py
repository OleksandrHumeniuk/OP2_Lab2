
#This function is used to let user choose the mode for information input (overwriting or adding)
def chooseMode():
    ch = input("Choose writing mode (1 - for overwriting text, 2 - for adding text): ")
    while ch != "1" and ch != "2":
        print("You may only enter a '1' or an '2'!")
        ch = input("Choose writing mode (1 - for overwriting text, 2 - for adding text): ")

    if ch == "1":
        return "w"
    else:
        return "a"


# This function creates input file with user-chosen name and using user-chose mode.
# After opening selected input file, the function lets the user input
# text through console: line by line, until an empty line is inputted.
def createInputFile(name, mode):
    with open(name, mode) as inputFile:
        print("Input your text. ENTER for next line. Empty line to stop")

        line = input()
        if line != "":
            inputFile.write(line)
            line = input()
            while line != "":
                inputFile.write("\n" + line)
                line = input()


# This function lets the user to enter an integer, and not something else
def inputNum():
    num = input("Enter number N: ")
    while (not num.isdigit()) or int(num) < 0:
        print(f"{num} isn't an integer!")
        num = input("Enter number N:")
    return int(num)


# This functions is splitting text from file with user-selected name into list of words
def getWords(name):
    words = []
    with open(name, "r") as inputFile:
        while True:
            line = inputFile.readline()
            if not line: break
            words.extend(line.split())
    return words


# This function is counting how many times the word is repeated in list of words
def countWords(word, words):
    counter = 0
    for s in words:
        if s == word:
            counter += 1
    return counter


# This function creates a list, which consists only of words from file that repeat more than n times
def createRepeatingWords(name, n):
    words = getWords(name)
    updatedWords = words
    for word in words:
        counter = countWords(word, words)
        if counter <= n:
            updatedWords = [s for s in updatedWords if s != word]
    return updatedWords


# This function sorts words by length ascendingly in string list using Odd-Even Bubble Sort
def oddEvenSort(words):
    isSorted = False
    while not isSorted:
        isSorted = True

        for i in range(0, len(words) - 1, 2):
            if len(words[i]) > len(words[i + 1]):
                words[i], words[i + 1] = words[i + 1], words[i]
                isSorted = False

        for i in range(1, len(words) - 1, 2):
            if len(words[i]) > len(words[i + 1]):
                words[i], words[i + 1] = words[i + 1], words[i]
                isSorted = False


# This function creates output file based on input file
def createOutputFile(outputName, inputName):
    n = inputNum()
    repeatingWords = createRepeatingWords(inputName, n)
    oddEvenSort(repeatingWords)

    with open(outputName, "w") as outputFile:
        if len(repeatingWords) > 0: outputFile.write(repeatingWords[0])
        for i in range(1, len(repeatingWords)):
            outputFile.write(" " + repeatingWords[i])


# This function outputs text from user-selected file in console
def printFile(name, text):
    with open(name, "r") as file:
        print(text)
        while True:
            line = file.readline()
            if not line: break
            print(line, end="")
