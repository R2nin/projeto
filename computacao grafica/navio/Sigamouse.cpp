#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

// Carrega a imagem
ALLEGRO_BITMAP *image = NULL;
ALLEGRO_MOUSE_STATE mouseState;

void update_bitmap_position() {
    // Obtém a posição atual do mouse
    al_get_mouse_state(&mouseState);
    int mouseX = al_get_mouse_state_axis(&mouseState, 0);
    int mouseY = al_get_mouse_state_axis(&mouseState, 1);

    // Atualiza a posição do bitmap para a posição do mouse
    al_draw_bitmap(image, mouseX, mouseY, 0);
}

int main() {
    ALLEGRO_DISPLAY *display = NULL;

    if(!al_init()) {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return -1;
    }

    display = al_create_display(800, 600);
    if(!display) {
        fprintf(stderr, "Falha ao criar a janela.\n");
        return -1;
    }

    al_init_image_addon(); // Inicializa o addon para carregar imagens
    al_install_mouse(); // Inicializa o mouse

    image = al_load_bitmap("navio.png");
    if(!image) {
        fprintf(stderr, "Falha ao carregar a imagem.\n");
        al_destroy_display(display);
        return -1;
    }

    while(true) {
        update_bitmap_position();
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0)); // Limpa a tela para evitar o rastro do bitmap
    }

    al_destroy_bitmap(image);
    al_destroy_display(display);

    return 0;
}

