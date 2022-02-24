#include "functions.h"

int main()
{
	string inputName = "input.txt";
	string outputName = "output.txt";

	int mode = chooseMode();

	createInputFile(inputName, mode);
	createOutputFile(outputName, inputName);

	printFile(inputName, "Input File:");
	printFile(outputName, "\nOutput File:");
}
