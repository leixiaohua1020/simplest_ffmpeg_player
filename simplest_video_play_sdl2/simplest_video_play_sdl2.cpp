/**
 * 最简单的SDL2播放视频的例子（SDL2播放RGB/YUV）
 * Simplest Video Play SDL2 (SDL2 play RGB/YUV) 
 *
 * 雷霄骅 Lei Xiaohua
 * leixiaohua1020@126.com
 * 中国传媒大学/数字电视技术
 * Communication University of China / Digital TV Technology
 * http://blog.csdn.net/leixiaohua1020
 *
 * 本程序使用SDL2播放RGB/YUV视频像素数据。SDL实际上是对底层绘图
 * API（Direct3D，OpenGL）的封装，使用起来明显简单于直接调用底层
 * API。
 *
 * 函数调用步骤如下: 
 *
 * [初始化]
 * SDL_Init(): 初始化SDL。
 * SDL_CreateWindow(): 创建窗口（Window）。
 * SDL_CreateRenderer(): 基于窗口创建渲染器（Render）。
 * SDL_CreateTexture(): 创建纹理（Texture）。
 *
 * [循环渲染数据]
 * SDL_UpdateTexture(): 设置纹理的数据。
 * SDL_RenderCopy(): 纹理复制给渲染器。
 * SDL_RenderPresent(): 显示。
 *
 * This software plays RGB/YUV raw video data using SDL2.
 * SDL is a wrapper of low-level API (Direct3D, OpenGL).
 * Use SDL is much easier than directly call these low-level API.  
 *
 * The process is shown as follows:
 *
 * [Init]
 * SDL_Init(): Init SDL.
 * SDL_CreateWindow(): Create a Window.
 * SDL_CreateRenderer(): Create a Render.
 * SDL_CreateTexture(): Create a Texture.
 *
 * [Loop to Render data]
 * SDL_UpdateTexture(): Set Texture's data.
 * SDL_RenderCopy(): Copy Texture to Render.
 * SDL_RenderPresent(): Show.
 */

#include <stdio.h>

extern "C"
{
#include "sdl/SDL.h"
};

const int bpp=12;

int screen_w=500,screen_h=500;
const int pixel_w=320,pixel_h=180;

unsigned char buffer[pixel_w*pixel_h*bpp/8];


//Refresh Event
#define REFRESH_EVENT  (SDL_USEREVENT + 1)

#define BREAK_EVENT  (SDL_USEREVENT + 2)

int thread_exit=0;

int refresh_video(void *opaque){
	thread_exit=0;
	while (!thread_exit) {
		SDL_Event event;
		event.type = REFRESH_EVENT;
		SDL_PushEvent(&event);
		SDL_Delay(40);
	}
	thread_exit=0;
	//Break
	SDL_Event event;
	event.type = BREAK_EVENT;
	SDL_PushEvent(&event);

	return 0;
}

int main(int argc, char* argv[])
{
	if(SDL_Init(SDL_INIT_VIDEO)) {  
		printf( "Could not initialize SDL - %s\n", SDL_GetError()); 
		return -1;
	} 

	SDL_Window *screen; 
	//SDL 2.0 Support for multiple windows
	screen = SDL_CreateWindow("Simplest Video Play SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		screen_w, screen_h,SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
	if(!screen) {  
		printf("SDL: could not create window - exiting:%s\n",SDL_GetError());  
		return -1;
	}
	SDL_Renderer* sdlRenderer = SDL_CreateRenderer(screen, -1, 0);  

	Uint32 pixformat=0;

	//IYUV: Y + U + V  (3 planes)
	//YV12: Y + V + U  (3 planes)
	pixformat= SDL_PIXELFORMAT_IYUV;  

	SDL_Texture* sdlTexture = SDL_CreateTexture(sdlRenderer,pixformat, SDL_TEXTUREACCESS_STREAMING,pixel_w,pixel_h);

	FILE *fp=NULL;
	fp=fopen("test_yuv420p_320x180.yuv","rb+");

	if(fp==NULL){
		printf("cannot open this file\n");
		return -1;
	}

	SDL_Rect sdlRect;  

	SDL_Thread *refresh_thread = SDL_CreateThread(refresh_video,NULL,NULL);
	SDL_Event event;
	while(1){
		//Wait
		SDL_WaitEvent(&event);
		if(event.type==REFRESH_EVENT){
			if (fread(buffer, 1, pixel_w*pixel_h*bpp/8, fp) != pixel_w*pixel_h*bpp/8){
				// Loop
				fseek(fp, 0, SEEK_SET);
				fread(buffer, 1, pixel_w*pixel_h*bpp/8, fp);
			}

			SDL_UpdateTexture( sdlTexture, NULL, buffer, pixel_w);  

			//FIX: If window is resize
			sdlRect.x = 0;  
			sdlRect.y = 0;  
			sdlRect.w = screen_w;  
			sdlRect.h = screen_h;  
			
			SDL_RenderClear( sdlRenderer );   
			SDL_RenderCopy( sdlRenderer, sdlTexture, NULL, &sdlRect);  
			SDL_RenderPresent( sdlRenderer );  
			
		}else if(event.type==SDL_WINDOWEVENT){
			//If Resize
			SDL_GetWindowSize(screen,&screen_w,&screen_h);
		}else if(event.type==SDL_QUIT){
			thread_exit=1;
		}else if(event.type==BREAK_EVENT){
			break;
		}
	}
	SDL_Quit();
	return 0;
}
