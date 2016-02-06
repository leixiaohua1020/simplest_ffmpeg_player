#! /bin/sh
gcc simplest_ffmpeg_decoder_pure.cpp -g -o simplest_ffmpeg_decoder_pure.out -I /usr/local/include -L /usr/local/lib \
-lavcodec -lavutil -lswscale
