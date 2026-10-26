#include "code.h"
#include <iostream>
#include "raylib.h"
#include "dib.h"
#include "menu.h"
#include "func.h"


int m = 0; // mdo de game
int main(){
    std::cout << "carlos" << std::endl;
    llamada();
    InitWindow(800, 450, "Raylib - cyv");
    SetTargetFPS(60);
    Vector2 jugador = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    Camera2D camera = {0};
    camera.target = jugador;
    camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    
     Vector2 msi = GetMousePosition();
    while (!WindowShouldClose()){
        
        BeginDrawing();
        
        camera.target = jugador;
        BeginMode2D(camera);
        ClearBackground(WHITE);
        if(m == 1){
        tabla(&jugador.x, &jugador.y);
        
        if (IsKeyDown(KEY_RIGHT)){ jugador.x += 5;}
        if (IsKeyDown(KEY_LEFT)){  jugador.x -= 5; }
        if (IsKeyDown(KEY_UP)){    jugador.y -= 5; }
        if (IsKeyDown(KEY_DOWN)){  jugador.y += 5; }
        
            if(click()){
            Vector2 msim = GetMousePosition();
            msi = {msim.x + jugador.x, msim.y + jugador.y};
        }
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            Vector2 ms = GetMousePosition();
            jugador = { msi.x - ms.x, msi.y - ms.y};
             
        } 
        }
        else{
            pantalla(&m);
        }
        
        EndMode2D();
        if(m == 1){
        barra();
        hand();
    }
    
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}