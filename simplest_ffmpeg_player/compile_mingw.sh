#! /bin/sh
#最简单的基于FFmpeg的视频播放器 2----MinGW命令行编译
#Simplest FFmpeg Player 2----Compile in MinGW 
#
#雷霄骅 Lei Xiaohua
#leixiaohua1020@126.com
#中国传媒大学/数字电视技术
#Communication University of China / Digital TV Technology
#http://blog.csdn.net/leixiaohua1020
#
#compile
g++ simplest_ffmpeg_player.cpp -g -o simplest_ffmpeg_player.exe \
-I /usr/local/include -L /usr/local/lib \
-lmingw32 -lSDL2main -lSDL2 -lavformat -lavcodec -lavutil -lswscale
