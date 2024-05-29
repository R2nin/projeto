#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int main() {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP  *background = NULL;
    al_create_display(800, 600);

    al_init_image_addon(); // Inicializa o addon para carregar imagens

    background = al_load_bitmap("ilha_fundo.png");


    al_draw_bitmap(background, 0, 0, 0); // Desenha a imagem de fundo na tela

    al_flip_display(); // Atualiza a tela

    al_rest(10.0); // Aguarda 10 segundos

    al_destroy_bitmap(background);
    al_destroy_display(display);

    return 0;
}
