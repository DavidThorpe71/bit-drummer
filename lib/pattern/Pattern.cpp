#include <Pattern.h>

const int patternArray[129] = {
  0,1,3,5,9,17,33,65,129,7,11,13,19,21,25,
  35,37,41,49,67,69,73,81,97,131,133,137,
  145,161,193,15,23,27,29,39,43,45,51,53,
  57,71,75,77,83,85,89,99,101,105,113,135,
  139,141,147,149,153,163,165,169,177,195,
  197,201,209,225,31,47,55,59,61,79,87,91,
  93,103,107,109,115,117,121,143,151,155,
  157,167,171,173,179,181,185,199,203,205,
  211,213,217,227,229,233,241,63,95,111,
  119,123,125,159,175,183,187,189,207,215,
  219,221,231,235,237,243,245,249,127,191,
  223,239,247,251,253,255};

int Pattern::add(int a, int b)
{
    return a + b;
}

int Pattern::rightRotate(int n, unsigned int d) {
    return (n << d)|(n >> (8 - d));
}

int Pattern::get(int patternIndex, int patternRotate)
{
    if (patternIndex == 0) {
    return 0;
  }
  return Pattern::rightRotate(patternArray[patternIndex / 4], patternRotate / 4);
}