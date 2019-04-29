#include "../include/7Segment.h"
#include <stdio.h>

int main() {
  char my7Segment[500];

  MultiDigit md = MultiDigit(123, &my7Segment[0]);

  printf("meine 7segment anzeige:\n%s", static_cast<const char*>(md));

  return 0;
}
