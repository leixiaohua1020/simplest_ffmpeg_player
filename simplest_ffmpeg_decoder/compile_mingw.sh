#! /bin/sh
g++ simplest_ffmpeg_decoder.cpp -g -o simplest_ffmpeg_decoder.exe \
-I /usr/local/include -L /usr/local/lib -lavformat -lavcodec -lavutil -lswscale
