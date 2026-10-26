#include "func.h"

std::random_device a;
std::mt19937 b(a());

int random(int min, int max){
    std::uniform_int_distribution<int> total(min, max);
    return total(b);
}


bool click(){
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

bool click2(){
    return IsMouseButtonPressed(MOUSE_BUTTON_RIGHT);
}

bool chekm(int x, int y, int t, int t2){
    Vector2 ms = GetMousePosition();
    if(ms.x < x  + t && ms.x > x && ms.y > y && ms.y < y + t2)
    return true;
    
    return false;
}
bool igualc(Color c1, Color c2) {
    return (c1.r == c2.r) && 
           (c1.g == c2.g) && 
           (c1.b == c2.b) && 
           (c1.a == c2.a);
}
int dis(int x1, int y1, int x2, int y2){
    int xt = x1 - x2;
    int yt = y1 - y2;
    return sqrt(xt * xt + yt * yt);
}

