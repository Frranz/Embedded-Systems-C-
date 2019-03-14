//c++ is best

#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>

class CmdLineOptParser {
	public:
		virtual ~CmdLineOptParser() = default;
		bool Parse(int argc, char* argv[]) {

			char keyBuffer;

			//splitOpt is set if previous element was not set
			int splitOpt = 0;
			for( int i = 1; i < argc; i++ ){
				if( splitOpt ) {
					if(argv[i][0] == '-') {
						Option(keyBuffer, nullptr);
					} else {
						Option(keyBuffer, argv[i]);
					}

					splitOpt = 0;
				} else if( strlen(argv[i]) == 1) {
					printf("Parse failed, Option without key given\n");
					return false;
				}

				if( strlen(argv[i]) == 2 ) {
					keyBuffer = argv[i][1];
					splitOpt = 1;
				} else {
					if (argv[i][2] == '=') { // for -x=value
						Option(argv[i][1], &argv[i][3]);
					} else { // for -xvalue
						Option(argv[i][1], &argv[i][2]);
					}
				}
			}

			return true;
		};
	protected:
		bool Option(const char c, const char* info) {
			printf("Option receid %c=%s\n", c, info);
			return true;
		};
};

int main(int argc, char *argv[]) {
	for(int i = 0; i < argc  ; i++){
		printf("arg nr %d: %s\n", i, argv[i]);
	}

	CmdLineOptParser parser;

	bool parseSuccess = parser.Parse(argc, argv);
	printf("Parse returned %s\n", (parseSuccess) ? "true": "false");

	return 0;
}
