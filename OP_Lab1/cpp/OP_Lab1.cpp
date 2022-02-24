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

//word1 word1 word1
//word2 word2
//word3
//word4 word4 word4 word
//word3
//word3
//word5

//abc zxc ab
//abc zxc zx z z
//asd g gdsfl abcd abcd
//e a a a
//zc zxc
//zbdcas