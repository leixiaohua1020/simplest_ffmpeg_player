 最简单的SDL2播放视频的例子（SDL2播放RGB/YUV）
 Simplest Video Play SDL2 (SDL2 play RGB/YUV) 

 雷霄骅 Lei Xiaohua
 leixiaohua1020@126.com
 中国传媒大学/数字电视技术
 Communication University of China / Digital TV Technology
 http://blog.csdn.net/leixiaohua1020

 本程序使用SDL2播放RGB/YUV视频像素数据。SDL实际上是对底层绘图
 API（Direct3D，OpenGL）的封装，使用起来明显简单于直接调用底层
 API。

 函数调用步骤如下: 

 [初始化]
 SDL_Init(): 初始化SDL。
 SDL_CreateWindow(): 创建窗口（Window）。
 SDL_CreateRenderer(): 基于窗口创建渲染器（Render）。
 SDL_CreateTexture(): 创建纹理（Texture）。

 [循环渲染数据]
 SDL_UpdateTexture(): 设置纹理的数据。
 SDL_RenderCopy(): 纹理复制给渲染器。
 SDL_RenderPresent(): 显示。


 This software plays RGB/YUV raw video data using SDL2.
 SDL is a wrapper of low-level API (Direct3D, OpenGL).
 Use SDL is much easier than directly call these low-level API.  

 The process is shown as follows:

 [Init]
 SDL_Init(): Init SDL.
 SDL_CreateWindow(): Create a Window.
 SDL_CreateRenderer(): Create a Render.
 SDL_CreateTexture(): Create a Texture.

 [Loop to Render data]
 SDL_UpdateTexture(): Set Texture's data.
 SDL_RenderCopy(): Copy Texture to Render.
 SDL_RenderPresent(): Show.