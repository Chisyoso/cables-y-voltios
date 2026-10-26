#include "code.h"
#include "dib.h"
#include "func.h"

int team = 0;
bool run = false;
Color handc = RED;
struct linea{
    
    int x,y,x2,y2;
    bool col = false;
};
class obje {
    private:
    int busc = -1;
    int checker = 0;
    int dista = 10000;
    int vx;
    int r = random(0, 100);
    int frame = 0;
    public:
    
    int ob;
    int ohm;
    int vol;
    int a;
    int id;
    float x;
    float y;
    Color t;
        
    obje(int ob_, int ohm_, int vol_, int a_, int id_, float x_, float y_, Color t_
    ){
     ob = ob_;
     ohm = ohm_;
     vol = vol_;
     a = a_;
    id = id_;
     x = x_;
     y = y_;
     t = t_;
     vx = ohm;
     frame = a * 40;
    }
    
    void vida(){
        life(x, y + 40 , ohm, vx);
    }
    void atack();
     void bus();
    void seg();
};

std::vector<obje> obj;


     void obje::bus(){
         dista = 10000;
         busc = -1;
         
        for(int i = 0; i < static_cast<int>(obj.size()); i++){
            if(!( igualc(obj[i].t, t) )){
                int distan = dis(x, y, obj[i].x, obj[i].y);
             if(dista > distan){
                 busc = i;
                 checker = obj[busc].ob;
                 dista = distan;
             }    
            }
        }
    
    }
    void obje::atack(){
        
        int dis = 20;
        
        if(ob == 3){
            dis = 200;
        }
        else if(ob == 5){
            dis = 5;
        }
        
        if(igualc(obj[busc].t, t)){
            bus();
        }
        
        if(frame == a * 40){
        
        if(obj[busc].y - dis < y && obj[busc].y + dis > y && obj[busc].x - dis < x && obj[busc].x + dis > x && obj[busc].ohm > 0){
            eh(">:c" ,x, y - 50, 30);
            obj[busc].ohm -= vol;
            
                bus();
            
            frame = 0;    
        }
        
        
    }
    
    else{
        if(frame < a * 40){
        frame++;
    }
    
    
    
    }
    }
    
    void obje::seg(){
        
        if(checker != obj[busc].ob){
            bus();
        }
        if((obj[busc].x == 0 && obj[busc].y == 0) || busc == -1){
            eh(":>" ,x, y - 50, 30);
            return;
        }
        
        if(r < 40 ){
        if(obj[busc].x < x ){
            x-= 3/a;
        }
        else if(obj[busc].x > x ){
             x += 3/a;
             
        }
        if(obj[busc].x == x ){
            if(obj[busc].y < y ){
            y -= 3/a;
        }
        else if(obj[busc].y > y ){
             y += 3/a;
        }
        }
    }
    else if(r < 80){
        if(obj[busc].y < y ){
            y -= 3/a;
        }
        else if(obj[busc].y > y ){
             y += 3/a;
        }
         if(obj[busc].y == y ){
            if(obj[busc].x < x ){
            x-= 3/a;
        }
        else if(obj[busc].x > x ){
             x += 3/a;
             
        }
        }
    }
    
    else{
        if(obj[busc].x < x ){
            x-= 3/a;
        }
        else if(obj[busc].x > x ){
             x += 3/a;
             
        }
        
        if(obj[busc].y < y ){
            y -= 3/a;
        }
        else if(obj[busc].y > y ){
             y += 3/a;
        }
        
    }
        life(x, y + 40 , ohm, vx);
        
        atack();
         if(obj[busc].ohm <= 0 || igualc(obj[busc].t, t)){
                bus();
            }
        
    } 



std::vector<linea> wire;

int mano = -2;
int id = 0;

void llamada(){
    std::cout << "llamada!!" << std::endl;
}

void decis(int ide, int o, int v, int a){
    obj[ide].ohm = o;
    obj[ide].vol = v;
    obj[ide].a = a;
}

void declare(int ide){
    
    if(obj[ide].ob == 1){
         decis(ide, 5, 2, 2);
    }
    else if(obj[ide].ob == 2){
         decis(ide, 5, -2, 3);
    }
    else if(obj[ide].ob == 3){
         decis(ide, 8, 3, 2);
    }
    else if(obj[ide].ob == 4){
         decis(ide, 10, 4, 2);
    }
    else if(obj[ide].ob == 5){
         decis(ide, 2, 7, 1);
    }
    obj[ide].bus();
    
}
Vector2 j = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

void hand(){
    Vector2 ms = GetMousePosition();
    
    if( id > 0 && ms.y > 90 && click() && mano == -2 && id != 6 ){
        // DECLARAR TROPAS
            
            obj.push_back({id, 0, 0, 0, static_cast<int>(obj.size()), ms.x - j.x, ms.y - j.y , handc});
            declare(static_cast<int>(obj.size()) - 1);
            
        }
    else if(ms.y > 90 && click() && id != 6 && mano != -2 && !(chekm(obj[mano].x + j.x, obj[mano].y + j.y - 20, 40, 40))){
        
        obj[mano].x = ms.x - j.x;
        obj[mano].y = ms.y - j.y;
        mano = -2;
        id = 0;
    }
    
    else if(id == 6 && ms.y > 90 && click() && mano == -2){
        id = 0;
        wire.push_back({ms.x - j.x, ms.y - j.y , ms.x - j.x, ms.y - j.y, false});
    }
    
    switch(id){
    case -1:
    ekis(ms.x, ms.y, 30 );
    
    break;
    case 1:
    resi(ms.x, ms.y, 30, handc);
    break;
    case 2:
    bate(ms.x, ms.y, 30, handc);
    break;
    case 3:
    led(ms.x, ms.y, 30, handc);
    break;
    case 4:
    diod(ms.x, ms.y, 30, handc);
    break;
    case 5:
    capa(ms.x, ms.y, 30, handc);
    break;
    case 6:
    lpz(ms.x, ms.y, 30, BLACK);
    break;
    case 8:
    id = 0;
    break;
    case 9:
    id = 0;
    break;
 }
 
 
}


void ia(bool s){
    if(s){
    for(int i = 0; i < static_cast<int>(obj.size()) ; i++){
        obj[i].bus();
    }
    
    s = false;
}

for(int i = 0; i < static_cast<int>(obj.size()) ; i++){
        obj[i].seg();
    }
}
bool blockeado = false;


void barra(){
    
    DrawRectangle(0, 0, 800, 80, GRAY);
    for(int i = 0; i < 9; i++){
        if(chekm((i * 70) + 20, 20, 50, 50)){
        DrawRectangle((i * 70) + 20, 20, 50, 50, RED);
        
        if(click()) id = i + 1;
        
        if(mano != -2 && click()){
            obj.erase(obj.begin() + mano);
            mano = -2;
            id = 0;
        }
        
        }
        else{
        DrawRectangle((i * 70) + 20 , 20, 50, 50, WHITE);
        }
}
        resi(25, 45, 30, handc);
        bate((1 * 70) + 25 , 35, 30, handc);
        led((2 * 70) + 25 , 45, 30, handc);
        diod((3 * 70) + 25 , 45, 30, handc);
        capa((4 * 70) + 25 , 45, 30, handc);
        lpz((5 * 70) + 25 , 35, 30, BLACK);
        band((7 * 70) + 25 , 25, 30, handc);
        ekis((8 * 70) + 25 , 25, 30);
        
        if(chekm((10 * 70), 20, 50, 50)){
        play((10 * 70) + 20, 20, 50, RED, WHITE);
        if(click()){
            ia(true);
            run = !run;
            
        }
    }
        else{
            play((10 * 70) + 20, 20, 50, WHITE, RED);
        }
        
        if(chekm((7 * 70) + 20, 20, 50, 50) && click()){
            blockeado = true;
               
                 
           } 
        
        
        if(blockeado){
                eh("ESCRIBE DEL 1 AL 6", 10, 200, 50);
               if(IsKeyDown(KEY_ONE)){
                   handc = BROWN;  blockeado = false;
               }
               else if(IsKeyDown(KEY_TWO)){
                   handc = RED; blockeado = false;
               }
               else if(IsKeyDown(KEY_THREE)){
                   handc = ORANGE; blockeado = false;
               }
               else if(IsKeyDown(KEY_FOUR)){
                   handc = YELLOW; blockeado = false;
               }
               else if(IsKeyDown(KEY_FIVE)){
                   handc = GREEN; blockeado = false;
               }
               else if(IsKeyDown(KEY_SIX)){
                  blockeado = false; handc = BLUE;
               }
               
           }
        DrawText(TextFormat("obj: %d", static_cast<int>(obj.size())  ), (9 * 70) + 20, 20, 20, BLACK);
        DrawText(TextFormat("lin: %d", static_cast<int>(wire.size())  ), (9 * 70) + 20, 50, 20, BLACK);
}

// TABLA RENDER

void tabla(float *jx, float *jy){
    Vector2 ms = GetMousePosition();
     j = {(GetScreenWidth() / 2.0f) - *jx, (GetScreenHeight() / 2.0f) - *jy};
    Vector2 msm = {ms.x  - j.x,  ms.y - j.y };
  
    if(run){
        ia(false);
    }
    
    
    for(int i = 0; i < static_cast<int>(obj.size()) ; i++){
        if(obj[i].ohm <= 0){
            obj.erase(obj.begin() + i);
            continue;
        }
        
        if(chekm(obj[i].x + j.x, obj[i].y - 20 + j.y, 40, 40)){
            DrawRectangle(obj[i].x, obj[i].y -20, 40, 40, RED);
            obj[i].vida();
            if(click()){
             id = obj[i].ob;
             mano = i;
                
            }
        }
        
        if(i != mano){
        if(obj[i].ob == 1){
            resi(obj[i].x, obj[i].y, 25, obj[i].t);    
        }
        else if(obj[i].ob == 2){
            bate(obj[i].x, obj[i].y, 25,  obj[i].t);
        }
        else if(obj[i].ob == 3){
            led(obj[i].x, obj[i].y, 25,  obj[i].t);
        }
        else if(obj[i].ob == 4){
            diod(obj[i].x, obj[i].y, 25,  obj[i].t);
        }
        else if(obj[i].ob == 5){
            capa(obj[i].x, obj[i].y, 25,  obj[i].t);
        }
        
    }
        
    }
    
    
    for(int i = 0; i < static_cast<int>(wire.size()) ; i++){
        if(chekm(wire[i].x -5 + j.x, wire[i].y -5 + j.y, 10, 10) && wire[i].col == true){
           line(wire[i].x, wire[i].y,wire[i].x2, wire[i].y2, RED);  
           if(click2()){
               wire.erase(wire.begin() + i);
           }
        }
        else if(chekm(wire[i].x2 -5 + j.x, wire[i].y2 -5 + j.y, 10, 10) && wire[i].col == true){
           line(wire[i].x, wire[i].y,wire[i].x2, wire[i].y2, RED);  
           if(click2()){
               wire.erase(wire.begin() + i);
           }
        }
        
        else if(wire[i].col == true){
            line(wire[i].x, wire[i].y,wire[i].x2, wire[i].y2, BLACK);
        }
        
        else{
        
        line(wire[i].x, wire[i].y, msm.x, msm.y , GRAY);
        
        if(click()){
           wire[i].x2 = msm.x;  
           wire[i].y2 = msm.y;
           wire[i].col = true;
        }
        }
    }
    
    }
