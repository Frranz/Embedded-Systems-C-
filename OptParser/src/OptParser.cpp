//c++ is best

#include <string.h>
#include <stdio.h>
#include "../include/OptParser.h"

bool CmdLineOptParser::Parse(int argc, char* argv[]) {


	/* splitOpt is set if previous element only the variable
	 without a value like -x */
	int splitOpt = 0;

	/* keyBuffer stores the variable if no value is given in
	the string*/
	char keyBuffer;
	for( int i = 1; i < argc; i++ ){
		if( splitOpt ) {
			if(argv[i][0] == '-') { // no value for previous option
				Option(keyBuffer, nullptr);
				splitOpt = 0;
			} else {
				Option(keyBuffer, argv[i]);

				splitOpt = 0;
				continue;
			}
		} else if( strlen(argv[i]) == 1) {
			printf("Parse failed, invalid option\n");
			return false;
		}

		if( strlen(argv[i]) == 2 ) { // if -x
			keyBuffer = argv[i][1];
			splitOpt = 1;
		} else {
			if (argv[i][2] == '=') { // if -x=value
				Option(argv[i][1], &argv[i][3]);
			} else { // if -xvalue
				Option(argv[i][1], &argv[i][2]);
			}
		}
	}

	if( splitOpt ) {
		Option(keyBuffer, nullptr);
		splitOpt = 0;
	}

	return true;
}

bool CmdLineOptParser::Option(const char c, const char* info) {
	printf("char: %c; info: %s\n", c, info);
	if(c != '\0' && info != nullptr) {
		return true;
	} else {
		return false;
	}
}
