#include <allegro.h>
#include <allegro_primitives.h>

ALLEGRO_DISPLAY *janela=NULL;

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



int main(){
   int x1=-20;

   al_init();
   al_init_primitives_addon();
   janela = al_create_display(800, 600);

   ALLEGRO_COLOR preto=al_map_rgb(0,0,0);
   CIRCULO c1={400, 300, 80, 5, al_map_rgb(255,0,0)};
 //  CIRCULO c2={200, 200, 50, 0, al_map_rgb(0,0,255)};
   RETANGULO r1={600,80,60,60, 10, al_map_rgb(0,255,0)};

   for (x1=-20; x1<760; x1+=1)
      {
        al_clear_to_color(al_map_rgb(255,255,255));

       // c1.desenhaCirculo();
       // c1.cx+=1; c1.cy-=1;



        al_draw_filled_rectangle(x1,400,x1+40,440,preto);
        al_flip_display();
        al_rest(0.01);
      }
   al_rest(5); //PAUSA DE 5 SEGUNDOS
}
