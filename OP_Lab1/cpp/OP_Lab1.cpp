#include "functions.h"

int main()
{
	string inputName = "input.txt"; // Name of input file
	string outputName = "output.txt"; // Name of output file

	int mode = chooseMode(); // Variable for mode of information input (adding/overwriting)

	createInputFile(inputName, mode); // Creates input file based on inputted text
	createOutputFile(outputName, inputName); // Creates outfile file based on input file

	printFile(inputName, "Input File:"); // Outputs input file in console
	printFile(outputName, "\nOutput File:"); // Outputs output file in console
}
