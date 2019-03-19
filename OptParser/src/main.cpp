#include "../include/OptParser.h"
#include <iostream>

int main(int argc, char* argv[]){
	CmdLineOptParser parser;

	bool parseSuccess = parser.Parse(argc, argv);
	std::cout << "Parse returned " << ((parseSuccess) ? "true": "false") << '\n';

	return 0;
}
