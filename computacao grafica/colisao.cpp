#include <allegro.h>
#include <allegro_primitives.h>
#include <math.h>

ALLEGRO_DISPLAY *janela=NULL;
ALLEGRO_EVENT_QUEUE *fEventos=NULL;
ALLEGRO_EVENT ev;


bool teclas[4]={false, false, false, false}; // A D S W


struct CIRCULO {
     float cx, cy, r, traco;
     ALLEGRO_COLOR cor;

     void desenhaCirculo(){
        if (traco==0){
           al_draw_filled_circle(cx, cy, r, cor);
        } else {
           al_draw_circle(cx, cy, r, cor, traco);
        }
     }
};
struct RETANGULO {
     float x1, y1, w, h, traco;   // width, height
     ALLEGRO_COLOR cor;
};

void desenhaCirculo(CIRCULO c){
    if (c.traco==0){
        al_draw_filled_circle(c.cx, c.cy, c.r, c.cor);
    } else {
        al_draw_circle(c.cx, c.cy, c.r, c.cor, c.traco);
    }
}

void desenhaRetangulo(RETANGULO r){
    if (r.traco==0){
       al_draw_filled_rectangle(r.x1, r.y1, r.x1+r.w, r.y1+r.h, r.cor);
    } else {
       al_draw_rectangle(r.x1, r.y1, r.x1+r.w, r.y1+r.h, r.cor, r.traco);
    }
}

bool colideCirculo (CIRCULO c1, CIRCULO c2){
     float dx = c1.cx - c2.cx;
     float dy = c1.cy - c2.cy;
     float h = sqrt( pow(dx,2) + pow(dy,2) );

     if (h > c1.r + c2.r){
        return false; //não existe colisão
     } else {
        return true;  // existe colisão
     }
}

bool colideRetangulo (RETANGULO r1, RETANGULO r2){
    if ( r2.x1+r2.w > r1.x1 &&
         r1.x1+r1.w > r2.x1 &&
         r2.y1+r2.h > r1.y1 &&
         r1.y1+r1.h > r2.y1   ){
        return true;
    } else {
        return false;
    }
}

bool colideRetanguloCirculo (RETANGULO r1, CIRCULO c1){
    float x1,y1, w,h;
    float r = c1.r * 0.8;
    x1=(c1.cx - r);
    y1=(c1.cy - r);
    w = r * 2;
    h = r * 2;
    RETANGULO r2={x1, y1, w, h, c1.traco, c1.cor };

    return colideRetangulo(r1, r2);

}

int main(){
   int x1=-20;

   al_init();
   al_init_primitives_addon();
   al_install_keyboard();
   al_install_mouse();

   janela = al_create_display(800, 600);

   fEventos = al_create_event_queue();

   al_register_event_source(fEventos, al_get_keyboard_event_source());
   al_register_event_source(fEventos, al_get_mouse_event_source());

   ALLEGRO_COLOR amarelo=al_map_rgb(255,255,0);
   CIRCULO c1={400, 300, 80, 5, al_map_rgb(255,0,0)};
   CIRCULO c2={200, 200, 50, 0, al_map_rgb(0,0,255)};
   RETANGULO r1={600,80,60,60, 10, al_map_rgb(0,255,0)};
   RETANGULO r2={500,150,80,80,0, amarelo};

   while (true){
       al_wait_for_event_timed(fEventos, &ev, 0.001);
       if (ev.type==ALLEGRO_EVENT_KEY_CHAR) {
          if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
             break;
          }
          if (ev.keyboard.keycode == ALLEGRO_KEY_P){
             x1 += 20;
          }
          if (ev.keyboard.keycode == ALLEGRO_KEY_O){
             x1 -= 20;
          }
       }
       if (ev.type == ALLEGRO_EVENT_MOUSE_AXES){
           c1.cx = ev.mouse.x;
           c1.cy = ev.mouse.y;
       }

       if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
         if (ev.keyboard.keycode == ALLEGRO_KEY_A){
            teclas[0]=true;
         }
         if (ev.keyboard.keycode == ALLEGRO_KEY_D){
            teclas[1]=true;
         }
         if (ev.keyboard.keycode == ALLEGRO_KEY_S){
            teclas[2]=true;
         }
         if (ev.keyboard.keycode == ALLEGRO_KEY_W){
            teclas[3]=true;
         }
       }
       if (ev.type == ALLEGRO_EVENT_KEY_UP) {
         if (ev.keyboard.keycode == ALLEGRO_KEY_A){
            teclas[0]=false;
         }
         if (ev.keyboard.keycode == ALLEGRO_KEY_D){
            teclas[1]=false;
         }
         if (ev.keyboard.keycode == ALLEGRO_KEY_S){
            teclas[2]=false;
         }
         if (ev.keyboard.keycode == ALLEGRO_KEY_W){
            teclas[3]=false;
         }
       }
       if (teclas[0]) { r2.x1-=2; } //A
       if (teclas[1]) { r2.x1+=2; } //D
       if (teclas[2]) { r2.y1+=2; } //S
       if (teclas[3]) { r2.y1-=2; } //W

        al_clear_to_color(al_map_rgb(255,255,255));


        if (colideCirculo(c1, c2)){
            c1.traco = 0;
        } else {
            c1.traco = 5;
        }

        if (colideRetangulo(r1, r2)){
           r2.cor = al_map_rgb(255,0,0);
        } else {
           r2.cor = amarelo;
        }

        if (colideRetanguloCirculo(r1, c1)){
           c1.traco = 0;
        } else {
           c1.traco = 5;
        }

        c1.desenhaCirculo();
        desenhaCirculo(c2);

        desenhaRetangulo(r1);
        desenhaRetangulo(r2);

        al_flip_display();
        al_rest(0.01);
      }
   al_rest(5); //PAUSA DE 5 SEGUNDOS
}
