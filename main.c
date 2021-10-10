#include <tonc.h>
#include <string.h>
#include "background.gfx.h"
#include "sprites.gfx.h"

// Definir estructura para guardar los datos del juego
struct game_s {
    // Buffer con los metadatos de los sprites
    OBJ_ATTR obj_buffer[128];
    // Tamano del buffer de metadatos de sprites
    int obj_buffer_size;
    // Contador de frames
    u32 frame;
    
    /* LOGICA DE JUEGO */
    
};
// Instanciar en memoria la estructura con los datos del juego
struct game_s game;

// Inicializar datos juego
void init_game() {
	// Inicializar buffer sprites
	oam_init(game.obj_buffer, 128);
	// Inicializar contador tamano buffer sprites
    game.obj_buffer_size=0;
    // Inicializar contador de frames
    game.frame=0;
    
    /* Inicializar logica de juego */
    
    
}

// Cargar fondo
void load_background() {
    
}

// Cargar sprites
void load_sprites() {
    
}

// Actualizar y mostar sprites en pantalla
void update_sprites() {
    
    // Copiar buffer to sprites memory
    oam_copy(oam_mem, game.obj_buffer, game.obj_buffer_size);
}

// Actualizar datos juego
void update_game() {
    
}

// Inicializar sistema grafico
void init_display() {
    
}

// Metodo main. Inicio del programa
int main()
{
	// Inicializar interrupciones
	irq_init(NULL);
	// Activar interrupción VBlank
    irq_add(II_VBLANK, NULL);
    
    // Inicializar datos    
	init_game();
	
	// Cargar fondo	
	load_background();
	// Cargar sprites
	load_sprites();
    // Inicializar video
    init_display();
	    
	// Bucle infinito. No tenemos sistema operativo al que volver
	while(1)
	{
		// Sincronizar con VBlank mediante interrupcion.
		// Esto se hace para evitar modificar la memoria a mitad de un refresco de pantalla.
        VBlankIntrWait();
        // Actualizar contador de frames
		game.frame++;
        // Leer botones
		key_poll();
        // Actualizar datos juego
		update_game();
        // Actualizar sprites
        update_sprites();
	}

	// Nunca llegaremos a este punto. Sólo por cumplir con estandar c
	return 0;
}
