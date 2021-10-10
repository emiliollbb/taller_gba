#include <tonc.h>
#include <string.h>
#include "background.gfx.h"
#include "sprites.gfx.h"

struct game_s {
    // Buffer con los metadatos de los sprites
    OBJ_ATTR obj_buffer[128];
    // Tamano del buffer de metadatos de sprites
    int obj_buffer_size;
    // Contador de frames
    u32 frame;
    
    /* LOGICA DE JUEGO */
    int posx;
    int posy;
};
struct game_s game;


void init_game() {
    game.obj_buffer_size=0;
    game.frame=0;
    
    // Inicializar logica de juego
    game.posx=96;
    game.posy=100;
    
}

void load_background() {
    // Cargar paleta fondo
	memcpy(pal_bg_mem, background_gfxPal, background_gfxPalLen);
	// Cargar tiles fondo en CBB 0
	memcpy(&tile_mem[0][0], background_gfxTiles, background_gfxTilesLen);
	// Cargar mapa de tiles en SBB 16
	memcpy(&se_mem[16][0], background_gfxMap, background_gfxMapLen);
    
    // Activar fondo 0 usando CBB 0 Y SBB 16
	REG_BG0CNT= BG_CBB(0) | BG_SBB(16) | BG_4BPP | BG_REG_64x32 | BG_PRIO(1);
	
	// Scroll horizontal fondo 0
	REG_BG0HOFS= 0;
    // Scroll vertical fondo 0
	REG_BG0VOFS= 0;
}

void load_sprites() {
    // Inicializar buffer sprites
	oam_init(game.obj_buffer, 128);
    // Cargar paleta sprites
	memcpy(pal_obj_mem, sprites_gfxPal, sprites_gfxPalLen);
    // Cargar tiles sprites en CBB 4
	memcpy(&tile_mem[4][0], sprites_gfxTiles, sprites_gfxTilesLen);
    
    // Cargar mapa sprite 0
    obj_set_attr(&game.obj_buffer[game.obj_buffer_size++], 
			ATTR0_SQUARE,
			ATTR1_SIZE_32x32,
			ATTR2_PALBANK(0) | ATTR2_PRIO(0) | 0);    
}

void update_sprites() {
    // Establecer posicion sprite 0
    obj_set_pos(&game.obj_buffer[0], game.posx, game.posy);
    // Copiar buffer to sprites memory
    oam_copy(oam_mem, game.obj_buffer, game.obj_buffer_size);
}

void update_game() {
}

void init_display() {
    // Init Display
    REG_DISPCNT= DCNT_MODE0 
                | DCNT_BG0 
                | DCNT_OBJ | DCNT_OBJ_1D
    ;
}

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
	    
	
	while(1)
	{
		// Sincronizar con VBlank
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

	return 0;
}
