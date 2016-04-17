/*
 * crypto.hpp
 *
 * 		Cryptographic functions/algorithms
 * 		crypto.cpp
 *  Created on: Dec 3, 2014
 *      Author: Jakub Kerber <kerber.jg@gmail.com>
 */

#include "mathutils.hpp"
#include "xprec.hpp"

namespace math {

	//CRC
	u16 crc16();
	u32 crc32();
	u64 crc64();

	//Message-Digest
	u128 md2();
	u128 md3();
	u128 md4();
	u128 md5();

	//SHA
	u256 sha256();

	//MurmurHash 3
	u32 murmurhash3_32();
	u64 murmurhash3_64();

}
