/*
  Pattern.h - Library for handling 
  patterns in the bit-drummer project.
  Created by David Thorpe 21st Feb 2022
*/
#ifndef BITDRUMPATTERN_H
#define BITDRUMPATTERN_H

class BitDrumPattern
{
public:
  BitDrumPattern() {}
  int rightRotate(int patternIndex, unsigned int patternRotate);
};
#endif
