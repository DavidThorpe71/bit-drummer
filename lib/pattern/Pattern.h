/*
  Pattern.h - Library for handling 
  patterns in the bit-drummer project.
  Created by David Thorpe 21st Feb 2022
*/
#ifndef PATTERN_H
#define PATTERN_H

class Pattern
{
public:
  Pattern() {}
  int rightRotate(int patternIndex, unsigned int patternRotate);
};
#endif
