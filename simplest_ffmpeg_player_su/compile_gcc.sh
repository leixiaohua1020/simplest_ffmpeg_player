#! /bin/sh
gcc simplest_ffmpeg_player_su.cpp -g -o simplest_ffmpeg_player_su.out -I /usr/local/include -L /usr/local/lib \
-lSDL2main -lSDL2 -lavformat -lavcodec -lavutil -lswscale
