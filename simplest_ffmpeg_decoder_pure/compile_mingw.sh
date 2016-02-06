#! /bin/sh
g++ simplest_ffmpeg_decoder_pure.cpp -g -o simplest_ffmpeg_decoder_pure.exe \
-I /usr/local/include -L /usr/local/lib -lavcodec -lavutil -lswscale
