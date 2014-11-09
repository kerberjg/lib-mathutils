/*
 * bitManipulation.h
 *
 *  Created on: Sep 30, 2013
 *      Author: mrgame64
 */

#ifndef BITMANIPULATION_H_
#define BITMANIPULATION_H_

typedef unsigned char u8;
typedef unsigned short int u16;

inline u16 combineWord(u8 low, u8 high)
{return low | (high << 4);}

inline u8 breakWord(u16 word, int n)
{return n ? (word & 0xFF) : (word >> 8);}

inline int valueOfBit(int n)
{return 1 << n;}

inline u8 setBit(u8 data, int n)
{return data | (1 << n);}

inline u8 clearBit(u8 data, int n)
{return data & ~(1 << n);}

inline u8 affectBit(u8 data, int n, bool bit)
{
	if(bit)
		return setBit(data, n);
	else
		return clearBit(data, n);
}

inline bool testBit(u8 data, int n)
{return ((data & (1 << n)) == 1);}

inline u8 toggleBit(u8 data, int n)
{return data ^ (1 << n);}

inline int bitToInt(u8 data, int n)
{return testBit(data, n) ? 1 : 0;}

#endif /* BITMANIPULATION_H_ */
