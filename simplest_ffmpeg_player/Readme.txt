最简单的基于FFmpeg的视频播放器 2
Simplest FFmpeg Player 2

雷霄骅 Lei Xiaohua
leixiaohua1020@126.com
中国传媒大学/数字电视技术
Communication University of China / Digital TV Technology
http://blog.csdn.net/leixiaohua1020

第2版使用SDL2.0取代了第一版中的SDL1.2
Version 2 use SDL 2.0 instead of SDL 1.2 in version 1.

本程序实现了视频文件的解码和显示（支持HEVC，H.264，MPEG2等）。
是最简单的FFmpeg视频解码方面的教程。
通过学习本例子可以了解FFmpeg的解码流程。
项目包含两个工程：
simplest_ffmpeg_player：标准版，FFmpeg学习的开始。
simplest_ffmpeg_player_su：SU（SDL Update）版，加入了简单的SDL的Event。

备注:
标准版在播放视频的时候，画面显示使用延时40ms的方式。这么做有两个后果：
（1）SDL弹出的窗口无法移动，一直显示是忙碌状态
（2）画面显示并不是严格的40ms一帧，因为还没有考虑解码的时间。
SU（SDL Update）版在视频解码的过程中，不再使用延时40ms的方式，而是创建了
一个线程，每隔40ms发送一个自定义的消息，告知主函数进行解码显示。这样做之后：
（1）SDL弹出的窗口可以移动了
（2）画面显示是严格的40ms一帧

This software is a simplest video player based on FFmpeg.
Suitable for beginner of FFmpeg.
Solutions contains 2 Project:
simplest_ffmpeg_player：Standard Version, suitable for biginner.
simplest_ffmpeg_player_su：SU（SDL Update）Version, Add SDL Event.

Remark:
Standard Version use's SDL_Delay() to control video's frame rate, it has 2
disadvantages:
(1)SDL's Screen can't be moved and always "Busy".
(2)Frame rate can't be accurate because it doesn't consider the time consumed 
by avcodec_decode_video2()
SU（SDL Update）Version solved 2 problems above. It create a thread to send SDL 
Event every 40ms to tell the main loop to decode and show video frames.
