Jenkins workshop
================

This repository contains a simple C++ library as playground for Jenkins.

Copyright &copy; 2017 Bernd Doser - All rights reserved.

Requirements
------------

- cmake (version >= 3.0, http://www.cmake.org)
- google-test (1.8.0, optional)
- doxygen (1.8.13, optional)

Compilation and Test
--------------------

```
mkdir build && cd build
cmake ..
make
make test
make doc
make package
```
