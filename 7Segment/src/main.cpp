#include "../include/7Segment.h"

int main() {
  char my7Segment[MAX_INT_AS_STRING_LENGTH];

  MultiDigit md = MultiDigit(123, &my7Segment);

  return 0;
}
