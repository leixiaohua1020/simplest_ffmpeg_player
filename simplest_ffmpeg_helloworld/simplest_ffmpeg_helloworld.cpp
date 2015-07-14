/**
 * 最简单的FFmpeg Helloworld程序
 * Simplest FFmpeg HelloWorld
 *
 * 雷霄骅 Lei Xiaohua
 * leixiaohua1020@126.com
 * 中国传媒大学/数字电视技术
 * Communication University of China / Digital TV Technology
 * http://blog.csdn.net/leixiaohua1020
 *
 * 
 * 本程序是基于FFmpeg函数的最简单的程序。它可以打印出FFmpeg类库的下列信息：
 * Protocol:  FFmpeg类库支持的协议
 * AVFormat:  FFmpeg类库支持的封装格式
 * AVCodec:   FFmpeg类库支持的编解码器
 * AVFilter:  FFmpeg类库支持的滤镜
 * Configure: FFmpeg类库的配置信息
 * 
 * This is the simplest program based on FFmpeg API. It can show following 
 * informations about FFmpeg library:
 * Protocol:  Protocols supported by FFmpeg.
 * AVFormat:  Container format supported by FFmpeg.
 * AVCodec:   Encoder/Decoder supported by FFmpeg.
 * AVFilter:  Filters supported by FFmpeg.
 * Configure: configure information of FFmpeg.
 *
 */

#include <stdio.h>

#define __STDC_CONSTANT_MACROS

#ifdef _WIN32
//Windows
extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"
};
#else
//Linux...
#ifdef __cplusplus
extern "C"
{
#endif
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
#ifdef __cplusplus
};
#endif
#endif

//FIX
struct URLProtocol;
/**
 * Protocol Support Information
 */
char * urlprotocolinfo(){
	
	char info[40000]={0};
	av_register_all();

	struct URLProtocol *pup = NULL;
	//Input
	struct URLProtocol **p_temp = &pup;
	avio_enum_protocols((void **)p_temp, 0);
	while ((*p_temp) != NULL){
		sprintf(info, "%s[In ][%10s]\n", info, avio_enum_protocols((void **)p_temp, 0));
	}
	pup = NULL;
	//Output
	avio_enum_protocols((void **)p_temp, 1);
	while ((*p_temp) != NULL){
		sprintf(info, "%s[Out][%10s]\n", info, avio_enum_protocols((void **)p_temp, 1));
	}

	return info;
}

/**
 * AVFormat Support Information
 */
char * avformatinfo(){

	char info[40000] = { 0 };

	av_register_all();

	AVInputFormat *if_temp = av_iformat_next(NULL);
	AVOutputFormat *of_temp = av_oformat_next(NULL);
	//Input
	while(if_temp!=NULL){
		sprintf(info, "%s[In ] %10s\n", info, if_temp->name);
		if_temp=if_temp->next;
	}
	//Output
	while (of_temp != NULL){
		sprintf(info, "%s[Out] %10s\n", info, of_temp->name);
		of_temp = of_temp->next;
	}
	return info;
}

/**
 * AVCodec Support Information
 */
char * avcodecinfo()
{
	char info[40000] = { 0 };

	av_register_all();

	AVCodec *c_temp = av_codec_next(NULL);

	while(c_temp!=NULL){
		if (c_temp->decode!=NULL){
			sprintf(info, "%s[Dec]", info);
		}
		else{
			sprintf(info, "%s[Enc]", info);
		}
		switch (c_temp->type){
		case AVMEDIA_TYPE_VIDEO:
			sprintf(info, "%s[Video]", info);
			break;
		case AVMEDIA_TYPE_AUDIO:
			sprintf(info, "%s[Audio]", info);
			break;
		default:
			sprintf(info, "%s[Other]", info);
			break;
		}

		sprintf(info, "%s %10s\n", info, c_temp->name);

		c_temp=c_temp->next;
	}
	return info;
}

/**
 * AVFilter Support Information
 */
char * avfilterinfo()
{
	char info[40000] = { 0 };
	av_register_all();
	AVFilter *f_temp = (AVFilter *)avfilter_next(NULL);
	while (f_temp != NULL){
		sprintf(info, "%s[%10s]\n", info, f_temp->name);
	}
	return info;
}

/**
 * Configuration Information
 */
char * configurationinfo()
{
	char info[10000] = { 0 };
	av_register_all();

	sprintf(info, "%s\n", avcodec_configuration());

	return info;
}

int main(int argc, char* argv[])
{
	printf("\n<<Configuration>>\n%s",configurationinfo());
	printf("\n<<URLProtocol>>\n%s",urlprotocolinfo());
	printf("\n<<AVFormat>>\n%s",avformatinfo());
	printf("\n<<AVCodec>>\n%s",avcodecinfo());
	printf("\n<<AVFilter>>\n%s",avfilterinfo());
	return 0;
}