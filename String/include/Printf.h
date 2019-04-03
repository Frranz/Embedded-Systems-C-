#ifndef PRINTF_H
#define PRINTF_H

int decimalLengthOfInt(unsigned int n);
char* addStringToString(char* dst, const void* end, char* toCopy, unsigned int limit);
char* intToBaseString(int num, int base, char* c, char* cEnd);
char* Printf(char* dst, const void* end , const char* fmt , ...);

#endif
