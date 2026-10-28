#ifndef FUNC_H
#define FUNC_H
#include "raylib.h"
#include <cmath>
#include <random>
#include <map>

void precios(int x, int y, int t, int p);
int reem(int id);
int random(int min, int max);
bool igualc(Color c1, Color c2);
bool click();
bool click2();
bool chekm(int x, int y, int t, int t2);
int dis(int x1,int y1,int x2,int y2);

#endif
