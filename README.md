# Super Mario 64 EX for Windows 98
Fork of sm64ex that has been tweaked to build for Windows 98 using a custom msys2 toolchain.
## toolchain setup
Download and install the newest version of [Msys2](https://www.msys2.org/)<br>
Open a msys2 32bit terminal and run the following commands:
```
pacman -Syy
pacman -S unzip make git python3
```
Do not install any version of gcc.<br>
Download and install [TDM-GCC 5.1](https://sourceforge.net/projects/tdm-gcc/files/TDM-GCC%20Installer/tdm-gcc-5.1.0-3.exe/download)<br>
Download [sdl for mingw](http://libsdl.org/release/SDL-devel-1.2.14-mingw32.zip), extract its contents to the respective folders in your TDM-GCC install (I.E. contents of include go to TDM's include folder)<br>
Download [GLEW for mingw](https://sourceforge.net/projects/glew/files/glew/2.1.0/glew-2.1.0-win32.zip/download), extract its contents into your TDM-GCC install like you did for SDL.<br>
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
Run ezmake.sh to build. The result will be placed into the build folder in the repo root.

## Additional notes
As of now, you need KernelEX to launch the game due to GLEW32 being too new. Work is being done to resolve this<br>
Building on Linux is untested and unsupported.

## Todo:
remove KernelEX Requirement
