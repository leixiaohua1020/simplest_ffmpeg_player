#! /bin/sh
g++ simplest_ffmpeg_player_su.cpp -g -o simplest_ffmpeg_player_su.exe \
-I /usr/local/include -L /usr/local/lib \
-lmingw32 -lSDL2main -lSDL2 -lavformat -lavcodec -lavutil -lswscale
