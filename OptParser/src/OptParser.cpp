//c++ is best

#include <string.h>
#include <iostream>
#include "../include/OptParser.h"
/*
	returns true if all options could bee parsed successfully
	returns false if at least 1 invalid option was given

	false is returned on first occasion of an invalid option
*/
bool CmdLineOptParser::Parse(int argc, char* argv[]) {

	// contains respective returnvalue of Option
	bool optionValid = true;

	/* splitOpt is set if previous element only the variable
	 without a value like -x */
	int splitOpt = 0;

	/* keyBuffer stores the variable if no value is given in
	the string*/
	char keyBuffer;
	for( int i = 1; i < argc; i++ ){
		if( splitOpt ) {
			if(argv[i][0] == '-') { // no value for previous option
				optionValid = Option(keyBuffer, nullptr);
				if(!optionValid) {
					return false;
				}

				splitOpt = 0;
			} else {
				optionValid = Option(keyBuffer, argv[i]);
				if(!optionValid) {
					return false;
				}

				splitOpt = 0;
				continue;
			}
		} else if( strnlen(argv[i], MAX_OPTION_VALUE_LENGTH) == 1) { // invalid argument of length 1
			return false;
		}

		if(argv[i][0] != '-') { // arguments should start with -
			return false;
		}

		if( strnlen(argv[i], MAX_OPTION_VALUE_LENGTH) == 2 ) { // if -x
			keyBuffer = argv[i][1];
			splitOpt = 1;
		} else {
			if (argv[i][2] == '=') { // if -x=value
				optionValid = Option(argv[i][1], &argv[i][3]);
				if(!optionValid) {
					return false;
				}
			} else { // if -xvalue
				optionValid = Option(argv[i][1], &argv[i][2]);
				if(!optionValid) {
					return false;
				}
			}
		}
	}

	// if last option was -x
	if( splitOpt ) {
		optionValid = Option(keyBuffer, nullptr);
		if(!optionValid) {
			return false;
		}
		splitOpt = 0;
	}

	return true;
}

bool CmdLineOptParser::Option(const char c, const char* info) {
	if(c != '\0') {
		if(info == nullptr) {
			return true;
		}

		// check if info contains only valid characters
		int i = 0;
		while(info[i] != '\0' && i < MAX_OPTION_VALUE_LENGTH) {

			//  representable characters are from 32-126 (including)
			if(info[i] < 32 || info[i] > 126) {
				return false;
			}
			i++;
		}

		return true;
	} else {
		return false;
	}
}
