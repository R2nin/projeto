#include<allegro5/allegro5.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>

#define BLOCKSIZE 32
#define WMAPA 15
#define HMAPA 12
#define SCREENWIDTH BLOCKSIZE*WMAPA
#define SCREENHEIGHT BLOCKSIZE*HMAPA

enum KEYS{UP, DOWN, LEFT, RIGHT};
enum KEYS2{W, S, A, D};

int mapa[HMAPA][WMAPA] = {
                     { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                     { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                     { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
                     { 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
                     { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
                     { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1},
                     { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
                     { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
                     { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1},
                     { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                     { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                     { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                   };

void DrawMap(){

    ALLEGRO_BITMAP *bloco2 = al_load_bitmap("Bloco2.bmp");
    ALLEGRO_BITMAP *bloco1 = al_load_bitmap("Bloco1.bmp");

    for(int i=0; i<HMAPA; i++){
        for(int j=0; j<WMAPA; j++){
            if(mapa[i][j] == 0){
                al_draw_bitmap(bloco2, j * BLOCKSIZE, i * BLOCKSIZE, 0);
            }
            else{
                al_draw_bitmap(bloco1, j * BLOCKSIZE, i * BLOCKSIZE, 0);
            }
        }
    }
    al_destroy_bitmap(bloco1);
    al_destroy_bitmap(bloco2);
}

int main(){

    ALLEGRO_DISPLAY *display;

    const float FPS = 30.0;
    bool done = false;
    bool redesenha=true;
    int posX = 30;
    int posY = 30;
    int posX2 = 265;
    int posY2 = 265;

    bool keys[4] = {false, false, false, false};
    bool keys2[4] = {false, false, false, false};

    al_init();
    display = al_create_display(SCREENWIDTH, SCREENHEIGHT);
    al_set_window_position(display, 300, 200);

    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    ALLEGRO_BITMAP *player2 = al_load_bitmap("Fantasma.png");
    ALLEGRO_BITMAP *player = al_load_bitmap("pacman.png");

    al_start_timer(timer);

    while(!done){
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        ALLEGRO_EVENT_TYPE tipoEvento=events.type;
        switch (tipoEvento) {
          case ALLEGRO_EVENT_TIMER: { redesenha=true; break;}
          case ALLEGRO_EVENT_DISPLAY_CLOSE: { done = true; break;}
          case ALLEGRO_EVENT_KEY_DOWN: {
            int tecla = events.keyboard.keycode;
            switch(tecla){
                case ALLEGRO_KEY_UP: {keys[UP] = true; break;}
                case ALLEGRO_KEY_DOWN: {keys[DOWN] = true; break;}
                case ALLEGRO_KEY_LEFT: {keys[LEFT] = true; break;}
                case ALLEGRO_KEY_RIGHT: {keys[RIGHT] = true; break;}
            }
            break;
          }
          case ALLEGRO_EVENT_KEY_UP: {
            int tecla = events.keyboard.keycode;
            switch(tecla){
                case ALLEGRO_KEY_UP: {keys[UP] = false; break;}
                case ALLEGRO_KEY_DOWN: {keys[DOWN] = false;break; }
                case ALLEGRO_KEY_LEFT: {keys[LEFT] = false; break;}
                case ALLEGRO_KEY_RIGHT: {keys[RIGHT] = false; break;}
                case ALLEGRO_KEY_ESCAPE: {done = true; break; }
            }
            break;
          }
        }
        posY -= keys[UP] * 2;
        posY += keys[DOWN] * 2;
        posX -= keys[LEFT] * 2;
        posX += keys[RIGHT] * 2;

        if(events.type == ALLEGRO_EVENT_KEY_DOWN){
            switch(events.keyboard.keycode){
                case ALLEGRO_KEY_W:
                    keys2[W] = true;
                    break;
                case ALLEGRO_KEY_S:
                    keys2[S] = true;
                    break;
                case ALLEGRO_KEY_A:
                    keys2[A] = true;
                    break;
                case ALLEGRO_KEY_D:
                    keys2[D] = true;
                    break;
            }
        }
        else if(events.type == ALLEGRO_EVENT_KEY_UP) {
            switch(events.keyboard.keycode){
                case ALLEGRO_KEY_W:
                    keys2[W] = false;
                    break;
                case ALLEGRO_KEY_S:
                    keys2[S] = false;
                    break;
                case ALLEGRO_KEY_A:
                    keys2[A] = false;
                    break;
                case ALLEGRO_KEY_D:
                    keys2[D] = false;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;
            }
        }

        posY2 -= keys2[W] * 2;
        posY2 += keys2[S] * 2;
        posX2 -= keys2[A] * 2;
        posX2 += keys2[D] * 2;

        if (redesenha) {
          DrawMap(mapa);

          al_draw_bitmap(player, posX, posY, 0);
          al_draw_bitmap(player2, posX2, posY2, 0);

          al_flip_display();
          redesenha=false;
        }
    }

    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);

    return 0;
}

