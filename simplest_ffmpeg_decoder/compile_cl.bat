::最简单的基于FFmpeg的视频解码器----命令行编译
::Simplest FFmpeg Decoder----Compile in Cmd 
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
cl simplest_ffmpeg_decoder.cpp /MD /link avcodec.lib ^
avformat.lib avutil.lib avdevice.lib avfilter.lib postproc.lib swresample.lib swscale.lib ^
 /OPT:NOREF
exit