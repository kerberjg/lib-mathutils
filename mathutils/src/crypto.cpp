#include "mathutils.hpp"

using namespace math;

u64 m64;
u32 m32;

u64 math::murmurhash3_64() {
	m64 ^= m64 >> 33;
	m64 *= 0xff51afd7ed558ccdULL;
	m64 ^= m64 >> 33;
	m64 *= 0xc4ceb9fe1a85ec53ULL;
	return m64 ^= m64 >> 33;
}

u32 math::murmurhash3_32() {
	m32 ^= m32 >> 16;
	m32 *= 0x85ebca6b;
	m32 ^= m32 >> 13;
	m32 *= 0xc2b2ae35;
	return m32 ^= m32 >> 16;
}
