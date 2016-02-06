::VS2010 Environment
call "D:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
::include
@set INCLUDE=include;%INCLUDE%
::lib
@set LIB=lib;%LIB%
::compile and link
cl simplest_video_play_sdl2.cpp /MD /link SDL2.lib SDL2main.lib /SUBSYSTEM:WINDOWS
exit