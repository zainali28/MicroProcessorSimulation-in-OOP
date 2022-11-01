#include "inputfilestream.h"
#include "cassembler.h"
#include "outputfilestream.h"
#include <iostream>

using namespace std;

int main()
{
	OutputFileStream outfile("swap.bin");

	outfile << 0x14;

	outfile.close();

	InputFileStream infile("swap.bin");

	infile.close();

	return 0;
}