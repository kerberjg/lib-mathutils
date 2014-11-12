/*
 * common.h
 *
 *  Created on: Sep 25, 2013
 *      Author: mrgame64
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdint.h>

#define InitPointer(pointer) ((pointer) = NULL)
#define SafeDelete(pointer) if(pointer != NULL) {delete pointer; pointer = NULL;}
#define SafeDeleteArray(pointer) if(pointer != NULL) {delete [] pointer; pointer = NULL;}

//Data types
typedef unsigned char u8;
typedef int8_t s8;
typedef unsigned short int u16;
typedef int16_t s16;
typedef unsigned int u32;
typedef int32_t s32;
typedef unsigned long long int u64;
typedef int64_t s64;

//Flags
#define FLAG_Z 0x80
#define FLAG_N 0x40
#define FLAG_H 0x20
#define FLAG_C 0x10

#endif /* COMMON_H_ */
