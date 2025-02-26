# qlibc

Qlibc is a lightweight C standard library that supports multiple architectures. And currently support ANSI/ISO C11. It is completely independent of glibc, libc, and other standard libraries, and can be ported to any freestanding environment or custom kernel. 

**Copyright (C):  QIU YIXIANG**

**Current Version:** 0.1

**LICENSE: MIT**



## Usage

To build this project, you will need the GNU `make` utility and the GNU `gcc` compiler. Select your target architecture (the default is i386). You can modify the configuration in `qlibc/config/config.mk` to change the target architecture.

To build the project, simply run `make` from the root directory. Afterward, you will find the built library as `libqlibc-x.x` in the `qlibc/build` directory. You can then link the library with the `-lqlibc-x.x` flag.

```makefile
make
```

To view help information, run:

```makefile
make help
```

You can also use the provided test framework in `qlibc/test` to test the library. If everything is working correctly, all the test cases should pass!

```makefile
make test
```



## Progress

The current implementation progress of header files is summarized below:

Finished :  <assert.h>,  <ctype.h>,  <stdbool.h>,  <stddef.h>

