[![Build Status](https://travis-ci.org/KadrusBAG/matrix-0.0.3-2nd-sem-.svg?branch=master)](https://travis-ci.org/KadrusBAG/matrix-0.0.3-2nd-sem-)
```
cmake -H. -B_builds -DBUILD_TESTS=ON -DBUILD_EXAMPLES=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose
_builds/example
```
