# Super Mario 64 EX for Windows 98
Fork of sm64ex that has been tweaked to build for Windows 98 using a custom msys2 toolchain.
## Toolchain Setup (Windows only!)
Download and install the newest version of [Msys2](https://www.msys2.org/)<br>
Open a msys2 msys terminal (tho in theory any of them should work) and run the following commands:
```
pacman -Syy
pacman -S unzip make git python3
```
Do not install any version of gcc.<br>
Download and install [TDM-GCC 5.1](https://sourceforge.net/projects/tdm-gcc/files/TDM-GCC%20Installer/tdm-gcc-5.1.0-3.exe/download)<br>
Once installed, go into the TDM GCC install folder, then into the bin folder. copy gcc.exe and give it the name of cc.exe. This will fix the build failing due to cc being missing<br>
Download [SDL1 for MinGW](http://libsdl.org/release/SDL-devel-1.2.14-mingw32.zip), extract its contents to the respective folders in your TDM-GCC install (I.E. contents of include go to TDM's include folder)<br>
Once you have extracted SDL, go into your TDM GCC install's lib folder, and make a copy of libSDL.dll.a, giving it the name of libSDL.a
Download [GLEW, version 2.1.0, for MinGW](https://sourceforge.net/projects/glew/files/glew/2.1.0/glew-2.1.0-win32.zip/download), extract its contents into your TDM-GCC install like you did for SDL.<br>
However, when you go to extract the lib folder from the glew zip, go into glew.zip/lib/Release/win32 and take the 2 .lib files there, and drop those into TDMGCC's lib folder. trying to keep the folder structure present in the zip will cause a compilation failure.<br>
Open include/sys/types.h from your TDM install in a text editor. Comment out the following line:
```
#ifndef _SSIZE_T_
#define _SSIZE_T_
typedef int _ssize_t;

#ifndef	_NO_OLDNAMES
//typedef _ssize_t ssize_t; <--- comment out this line, found at line 118
#endif
#endif /* Not _SSIZE_T_ */ 
```
Save the file and exit<br>
Copy a rom of us 1.0 mario 64 as baserom.us.z64 to the respository root.<br>
Add your TDM's bin folder to your Msys2 terminal using the following command:
```
export PATH=$PATH:/driveletter/path/to/tdm/bin
```
Replace driverletter with the drive you installed TDM on, and fill in the path to the folder.<br>
For example, if I installed TDMGCC into C:\tdmgcc, the command would be:
```
export PATH=$PATH:/c/tdmgcc/bin
```
Run ezmake.sh to build. The result will be placed into the build folder in the repo root.<br>
Before playing, open the copy of SDL you downloaded eariler, and copy SDL.dll from the archive's bin folder to the same location as your game's EXE<br>
Download [glew32.dll compiled for Windows 98](https://github.com/EzioisAwesome56/sm64ex-win98/releases/download/GLEW32/glew32.dll) that I have provided. The copy included with the glew archive is compiled for Windows vista, and would thus require KernelEX. This version does not need KernelEX.<br>
Place this file in the same folder as your game EXE. You can now enjoy Super Mario 64 on Windows 98!

## Additional notes
Building on Linux is untested and unsupported.
From testing to figure out why it wouldnt build years later, trying to add the -j argument for multithreaded building causes failures. do not add any of these flags.

## Todo:
Nothing atm
