lib-mathutils
=============

A C++ math library heavily optimized for real time applications such as games.

**Status**: Work in progress!

## Features:
 - Cached trigonometric functions (1MB of RAM, 99.9999% precision)
 - Vector and matrix classes (Vec2, Vec3, Mat3, Mat4)
 - Compile-time selection between "*fast*" and "*precise*" modes (read below)
 - "Fast inverse square root" hack
 - Operates on 32-bit floats by default

 
## Planned features:
 - Big integers (128 and 256 bits)
 - Big float (128 bit)
 - SIMD optimizations

### "Precise" and "Fast" modes
The default compilation mode is "fast". To enable the "precise" mode, you have to define the "PRECISE" macro in your compilation command.

**Example**: (G++ and Clang)

```
-D PRECISE
```

The precise mode disables caching of the trig functions as well as the `fast_inv_sqrt` hack.
It also switches to using 64bit floats instead of the 32bit ones.
