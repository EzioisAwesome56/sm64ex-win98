// this is a simple header fix for audiofile.cpp
// without this, we would fail due to the commented out line from tdm's gcc types.h
#include <_mingw.h>

typedef _ssize_t ssize_t; 
