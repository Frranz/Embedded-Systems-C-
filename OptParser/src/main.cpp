#include "OptParser.cpp"

class CmdToolBox : public CmdLineOptParser{
	public:
		bool Option(const char c, const char* info) {
			printf("Option received %c=%s\n", c, info);
			return true;
		}
};

int main(int argc, char *argv[]){
	CmdToolBox parser;

	bool parseSuccess = parser.Parse(argc, argv);
	printf("Parse returned %s\n", (parseSuccess) ? "true": "false");

	return 0;
}
