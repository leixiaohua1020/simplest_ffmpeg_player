::最简单的SDL2播放视频的例子（SDL2播放RGB/YUV）----命令行编译
::Simplest Video Play SDL2 (SDL2 play RGB/YUV) ----Compile in Cmd 
::
::雷霄骅 Lei Xiaohua
::leixiaohua1020@126.com
::中国传媒大学/数字电视技术
::Communication University of China / Digital TV Technology
::http://blog.csdn.net/leixiaohua1020
::
::VS2010 Environment
call "D:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
::include
@set INCLUDE=include;%INCLUDE%
::lib
@set LIB=lib;%LIB%
::compile and link
cl simplest_video_play_sdl2.cpp /MD /link SDL2.lib SDL2main.lib /SUBSYSTEM:WINDOWS
exit