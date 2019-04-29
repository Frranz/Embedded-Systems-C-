#include "../include/7Segment.h"
#include <climits>

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
      md1DigitsEnd--;
      remainder = numUns % base;
      numUns = numUns / base;

      this->md1Digits[md1DigitsEndCopy] = remainder;
  }
};

char MultiDigit::getDigitChar(unsigned int myInt, unsigned int row, unsigned int col) {
    if(row == 0 && col ==  0) {
        return ' ';
    } else if(row == 1) {
        return ' ';
    }

};
