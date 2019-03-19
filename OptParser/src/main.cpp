#include "../include/OptParser.h"
#include <stdio.h>

int main(int argc, char* argv[]){
	CmdLineOptParser parser;

	bool parseSuccess = parser.Parse(argc, argv);
	printf("Parse returned %s\n", (parseSuccess) ? "true": "false");

	return 0;
}
