#include "dib.h"



void resi(int x, int y, int t, Color c){
    DrawRectangle(x , y - t/5 , t * 1.5, t/4, BLACK);
    DrawRectangle(x + t / 3, y - t/3, (t/2)  * 1.7, t/2, c);
}
void ekis(int x, int y, int t){
    for(int i = 0; i < t/4; i++){
    DrawLine(x + i, y , x + t + 1, y + t, BLACK);
    DrawLine(x + t + i, y, x + i, y + t, BLACK);    
    }
    
}
void capa(int x, int y, int t, Color c){

    DrawRectangle(x + t/2 , y - t/2, t/ 2, t, c);
    DrawCircle(x + t/4 + t/2, y - t/2, t/4, GRAY);
    
}

void bate(int x, int y, int t, Color c){
    DrawRectangle(x - t/3, y - t/3 , t * 2, t/5, BLACK);
    DrawRectangle(x  , y - t/3 + (t/2.7) , t, t/5, c);
    DrawRectangle(x - t/3, y - t/3 + ((t/2.7) * 2), t * 2, t/5, BLACK);
    DrawRectangle(x , y - t/3 + ((t/2.7) * 3), t, t/5, BLACK);
}

void led(int x, int y, int t, Color c){
    DrawRectangle(x , y - t/6 , t * 1.5, t/4, BLACK);
    
    DrawTriangle( // ASISELEEMEJOR
     (Vector2){x + (t/3), y - (t/2)},
     (Vector2){x + (t/3), y + (t/2)},
     (Vector2){x + ((t/2)  * 1.7), y }, c);
Color c2 = {225, 225, 225, 125};     
     DrawCircle(x + t/2, y, t/1.5, c2);
}


void life(int x, int y, int min, int max){
    DrawRectangle(x, y, max * 5, 15, GRAY);
    DrawRectangle(x, y, min * 5, 15, RED);
}

void play(int x, int y, int t, Color c, Color c2){
    DrawRectangle(x, y, t, t, c);
    DrawTriangle(
        (Vector2){x + (t/4) , y + (t/4)},
        (Vector2){x + (t/4), y + ((t/4) * 3)},
        (Vector2){x + ((t/4) * 3), y + (t / 2)},
     c2);
    
}

void eh(const char* msg, int x, int y, int t){
    DrawText(msg, x, y, t, RED);
    
} // escrito

void lpz(int x,int y, int t, Color c){
    for(int i = 0; i < t/ 3; i++){
        DrawLine(x + i, y + t , x + t + i , y, c);
    }
    
}

void band(int x, int y, int t, Color c){
  DrawRectangle(x, y, t , t / 2, c);
  DrawRectangle(x, y, t / 3, t * 1.5, GRAY);  
}

void line(int x, int y, int x2, int y2,  Color c){
    int xt = x - x2;
    int yt = y - y2;
    int dx = sqrt(xt * xt);
    int dy = sqrt(yt * yt);
    
    if(dx < dy){
        for(int i = 0; i < 3; i++){
            DrawLine(x + i,y ,x2 +i , y2 , c);
        }
    }   else{
            
        for(int i = 0; i < 3; i++){
            DrawLine(x ,y + i ,x2  , y2 + i, c);
        }
        }
    
}

void diod(int x, int y, int t, Color c){
    DrawRectangle(x , y - t/6 , t * 1.5, t/4, c);
    
    DrawTriangle( // ASISELEEMEJOR
     (Vector2){x + (t/2), y - (t/2)},
     (Vector2){x + (t/2), y + (t/2)},
     (Vector2){x + (t), y }, BLACK);
     
    DrawRectangle(x , y - t/6 , t, t/4, BLACK);
}