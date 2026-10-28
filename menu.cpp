#include "menu.h"
#include "func.h"
#include "dib.h"

void pantalla(int *m){
    DrawRectangle(125, 50, 700, 350, GRAY);
    DrawText("QUE HAREMOS HOY??", 150, 175, 20, BLACK);
    led(500, 220, 100, RED);
    if(chekm(150, 200, 250, 40)){
         DrawRectangle(150, 200, 250, 40, RED);
         if(click()){
             *m = 1;
         }
    }else{
    DrawRectangle(150, 200, 250, 40, WHITE); }   
    DrawText("SANDBOX (MODO LIBRE)", 155, 210, 15, BLACK);
    
    if(chekm(150, 250, 250, 40)){
         DrawRectangle(150, 250, 250, 40, RED);
          if(click()){
             *m = 2;
         }
    }else{
    DrawRectangle(150, 250, 250, 40, WHITE); }   
    DrawText("HISTORIA", 155, 260, 15, BLACK);
}