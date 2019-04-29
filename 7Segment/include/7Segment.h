#ifndef MULTIDIGIT_H
#define MULTIDIGIT_H
constexpr int decimalLengthOfInt(unsigned int n);

class MultiDigit{
public:
    MultiDigit(unsigned int someInt, char* segmentPrint);
    operator const char*() const;
    void convertMyIntToArray();
    char getDigitChar(unsigned int myInt, unsigned int row, unsigned int col);


private:
    unsigned int md1;
    unsigned int md1Digits[40];
    unsigned int md1DigitsEnd;
    char* buffer;
};
#endif
