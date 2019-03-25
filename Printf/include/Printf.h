#ifndef PRINTF_H
#define PRINTF_H

char* intToBaseString(int num, int base, char* c, char* cEnd);
char* Printf(char* dst, const void* end , const char* fmt , ...);

#endif
