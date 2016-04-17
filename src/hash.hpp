/*
 * crypto.hpp
 *
 * 		Cryptographic functions/algorithms
 * 		crypto.cpp
 *  Created on: Dec 3, 2014
 *      Author: Jakub Kerber <kerber.jg@gmail.com>
 */

#include <string>
#include "mathutils.hpp"

namespace math {

	//CRC
	u8 crc8();
	u16 crc16();
	u32 crc32();
	u64 crc64();

	//Message-Digest
	std::string md5();

	//SHA
	std::string sha256();

	//MurmurHash 3
	u32 murmurhash3_32();
	u64 murmurhash3_64();

}
