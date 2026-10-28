#ifndef DIB_H
#define DIB_H
#include <string>
#include <cmath>
#include "raylib.h"
void resi(int x, int y, int t, Color c);
void capa(int x, int y, int t, Color c);
void bate(int x, int y, int t, Color c);
void led(int x, int y, int t, Color c);
void diod(int x, int y, int t, Color c);
void ekis(int x, int y, int t);
void play(int x, int y, int t, Color c, Color c2);
void lpz(int x,int y, int t, Color c);
void line(int x, int y, int x2, int y2, Color c);
void eh(const char* msg, int x, int y, int t);
void band(int x, int y, int t, Color c);
void life(int x, int y, int min, int max);
void trans(int x, int y, int t, Color c);

#endif