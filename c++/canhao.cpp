#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

const int LARGURA_TELA = 800;
const int ALTURA_TELA = 600;

const float GRAVIDADE = 9.8; // Ajuste conforme necessário
const float VELOCIDADE_INICIAL = 50; // Ajuste conforme necessário

struct Bala {
    float x;
    float y;
    float angulo;
    float velocidade;
    bool disparada;
};

void desenharCenario(ALLEGRO_DISPLAY* display, float angulo, const Bala& bala) {
    al_clear_to_color(al_map_rgb(255, 255, 255)); // Fundo branco

    // Desenhar o canhão
    al_draw_filled_rectangle(50, ALTURA_TELA - 50, 150, ALTURA_TELA, al_map_rgb(128, 128, 128));

    // Desenhar o alvo
    al_draw_filled_circle(LARGURA_TELA - 100, ALTURA_TELA - 100, 20, al_map_rgb(255, 0, 0));

    // Desenhar a bala se ela estiver disparada
    if (bala.disparada) {
        al_draw_filled_circle(bala.x, bala.y, 5, al_map_rgb(0, 0, 0));
    }

    al_flip_display();
}

int main() {
    ALLEGRO_DISPLAY* display = nullptr;
    ALLEGRO_EVENT_QUEUE* event_queue = nullptr;
    bool sair = false;

    // Inicialização do Allegro
    if (!al_init()) {
        return -1;
    }

    display = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!display) {
        return -1;
    }

    al_init_primitives_addon();

    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    // Inicializar variáveis do jogo
    Bala bala = { 0, 0, 45, 0, false }; // Ângulo inicial de 45 graus

    while (!sair) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            sair = true;
        }

        desenharCenario(display, bala.angulo, bala);

        al_rest(0.02); // Ajuste conforme necessário para controlar a taxa de atualização da tela
    }

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}
