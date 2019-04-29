#include "../include/7Segment.h"
#include <climits>
#include <stdio.h>

static const unsigned int MAX_INT_AS_STRING_LENGTH = (decimalLengthOfInt(UINT_MAX) + 1) * 20; // * 4 colums * 5 rows

constexpr int decimalLengthOfInt(unsigned int n) {
    int i = 0;
    while(n>0) {
        n = n/10;
        i++;
    }
    return i;
};

MultiDigit::MultiDigit(unsigned int myInt, char* segmentPrint) {
  this->md1 = myInt;
  this->buffer = segmentPrint;
  this->md1DigitsEnd = decimalLengthOfInt(myInt);
  this->convertMyIntToArray();
};

MultiDigit::operator const char *() const{
    for(unsigned int i = 0; i < this->md1DigitsEnd; ++i ) {
        for(unsigned int row = 0; row < 5; ++row) {

        }
    }
    return buffer;
};

void MultiDigit::convertMyIntToArray() {
  unsigned int remainder;
  unsigned int base = 10;
  unsigned int numUns = this->md1;
  unsigned int md1DigitsEndCopy = this->md1DigitsEnd;

  if(numUns == 0) {
      md1DigitsEndCopy--;
      this->md1Digits[md1DigitsEndCopy] = 0;
      return;
  }

  while(numUns != 0 && 0 < this->md1DigitsEnd) {
      md1DigitsEndCopy--;
      remainder = numUns % base;
      numUns = numUns / base;

      this->md1Digits[md1DigitsEndCopy] = remainder;
  }

  printf("0:%d;1:%d;2:%d,3:%d\n", this->md1Digits[0], this->md1Digits[1], this->md1Digits[2], this->md1Digits[3]);
};

char MultiDigit::getDigitChar(unsigned int myInt, unsigned int row, unsigned int col) {

    switch(col) {
        case 0:
            switch(row) {
                case 0:
                case 2:
                case 4:
                    return ' ';
                case 1:
                    if(myInt == 1 || myInt == 2 || myInt == 3 || myInt == 7) {
                        return ' ';
                    }
                    return '|';
                case 3:
                    if(myInt == 1 || myInt == 3 || myInt == 4 || myInt == 7 || myInt == 9) {
                        return ' ';
                    }
                    return '|';
                default:
                    return ' ';
            }
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            return ' ';
            break;
        default:
            return ' ';
    }

    if(col == 3){
        return ' ';
    }
    if(col == 1) {

    }

    if(col == 2) {

    }


    return ' ';

};
