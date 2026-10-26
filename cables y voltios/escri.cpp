#include "func.h"
#include "dib.h"

int caja(std::string msg){
    DrawRectangle(200, 125, 500, 200, GRAY);
    DrawText(TextFormat("%s", msg.c_str()), 250, 200, 20, BLACK);
    DrawRectangle(250, 300, 100, 30, WHITE);
    DrawRectangle(600, 150, 50, 50, RED);
    ekis(605, 155, 40);
    if(chekm(600, 150, 50, 50)){
        return 10;
    }
    return -1;
}
