#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

const int LARGURA_TELA = 800;
const int ALTURA_TELA = 600;

struct CIRCULO {
    float cx, cy, r, traco;
    ALLEGRO_COLOR cor;
    void desenhaCirculo() {
        if (traco == 0) {
            al_draw_filled_circle(cx, cy, r, cor);
        } else {
            al_draw_circle(cx, cy, r, cor, traco);
        }
    }
};

struct RETANGULO {
    float x1, y1, w, h, traco;
    ALLEGRO_COLOR cor;
    void desenhaRetangulo() {
        if (traco == 0) {
            al_draw_filled_rectangle(x1, y1, x1 + w, y1 + h, cor);
        } else {
            al_draw_rectangle(x1, y1, x1 + w, y1 + h, cor, traco);
        }
    }
};

int main() {
    al_init();
    al_init_primitives_addon();
    al_install_keyboard();

    al_init_primitives_addon();

    ALLEGRO_DISPLAY* display = al_create_display(LARGURA_TELA, ALTURA_TELA);

    ALLEGRO_BITMAP* ilha = al_load_bitmap("ilha.png");
    ALLEGRO_BITMAP* navio = al_load_bitmap("navio.png");

    RETANGULO r1;
    r1.x1 = 100;
    r1.y1 = 100;
    r1.w = 200;
    r1.h = 100;
    r1.traco = 5;
    r1.cor = al_map_rgb(255, 0, 0);

    CIRCULO c1;
    c1.cx = 400;
    c1.cy = 300;
    c1.r = 50;
    c1.traco = 5;
    c1.cor = al_map_rgb(0, 0, 255);

    RETANGULO r2;
    r2.x1 = 400;
    r2.y1 = 300;
    r2.w = 100;
    r2.h = 50;
    r2.traco = 5;
    r2.cor = al_map_rgb(255, 255, 0);

    bool teclas[ALLEGRO_KEY_MAX];
    al_install_keyboard();

    while (true) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(NULL, &evento);

        if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
            teclas[evento.keyboard.keycode] = true;
        } else if (evento.type == ALLEGRO_EVENT_KEY_UP) {
            teclas[evento.keyboard.keycode] = false;
        } else if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
            r2.x1 = evento.mouse.x - r2.w / 2;
            r2.y1 = evento.mouse.y - r2.h / 2;
        }

        if (teclas[ALLEGRO_KEY_ESCAPE]) {
            break;
        }

            if (teclas[ALLEGRO_KEY_W]) {
        r1.y1 -= 5;
    }
    if (teclas[ALLEGRO_KEY_S]) {
        r1.y1 += 5;
    }
    if (teclas[ALLEGRO_KEY_A]) {
        r1.x1 -= 5;
    }
    if (teclas[ALLEGRO_KEY_D]) {
        r1.x1 += 5;
    }

    al_draw_bitmap(ilha, 0, 0, 0);

    r1.desenhaRetangulo();
    r2.desenhaRetangulo();
    c1.desenhaCirculo();

    al_flip_display();
}

al_destroy_display(display);

return 0;
}
