最简单的基于FFmpeg的视频解码器（纯净版）
Simplest FFmpeg Decoder Pure

雷霄骅 Lei Xiaohua
leixiaohua1020@126.com
中国传媒大学/数字电视技术
Communication University of China / Digital TV Technology
http://blog.csdn.net/leixiaohua1020


本程序实现了视频码流(支持HEVC，H.264，MPEG2等)解码为YUV数据。
它仅仅使用了libavcodec（而没有使用libavformat）。
是最简单的FFmpeg视频解码方面的教程。
通过学习本例子可以了解FFmpeg的解码流程。
This software is a simplest decoder based on FFmpeg.
It decode bitstreams to YUV pixel data.
It just use libavcodec (do not contains libavformat).
Suitable for beginner of FFmpeg.