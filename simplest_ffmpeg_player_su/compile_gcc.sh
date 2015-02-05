#! /bin/sh
#最简单的基于FFmpeg的视频播放器2(SDL升级版)----命令行编译
#Simplest FFmpeg Player 2(SDL Update)----Compile in Shell 
#
#雷霄骅 Lei Xiaohua
#leixiaohua1020@126.com
#中国传媒大学/数字电视技术
#Communication University of China / Digital TV Technology
#http://blog.csdn.net/leixiaohua1020
#
#compile
gcc simplest_ffmpeg_player_su.cpp -g -o simplest_ffmpeg_player_su.out -I /usr/local/include -L /usr/local/lib \
-lSDL2main -lSDL2 -lavformat -lavcodec -lavutil -lswscale
