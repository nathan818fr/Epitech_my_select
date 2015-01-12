C_Lib_MyUtils
=============

Libraries of basic utils for C!

## Compilation
Just run `make`, that will create "libmyutils.a" !

## Usage
Put "libmyutils.a" in your library folder.
> mkdir lib<br>
cp path/to/libmyutils.a lib/

Put "myutils.h" in your include folder.
> mkdir include<br>
cp path/to/myutils.h include/

Indicate to "gcc" to compile the with library.
> gcc main.c -Llib/ -lmyutils -Iinclude/
