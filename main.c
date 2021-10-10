#include <tonc.h>
#include <string.h>
#include "background.gfx.h"
#include "sprites.gfx.h"

struct game_s {
    int objects;
    u32 frame;
};
struct game_s game;
OBJ_ATTR obj_buffer[128];

void init_game() {
    game.objects=0;
    game.frame=0;    
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
	oam_init(obj_buffer, 128);
    // Cargar paleta sprites
	memcpy(pal_obj_mem, sprites_gfxPal, sprites_gfxPalLen);
    // Cargar tiles sprites en CBB 4
	memcpy(&tile_mem[4][0], sprites_gfxTiles, sprites_gfxTilesLen);
    
    // Cargar mapa sprite 0
    obj_set_attr(&obj_buffer[0], 
			ATTR0_SQUARE,
			ATTR1_SIZE_32,
			ATTR2_PALBANK(0) | ATTR2_PRIO(0) | 0);
    // Establecer posicion sprite 0
    obj_set_pos(&obj_buffer[0], 96, 100);
    // Copiar buffer to sprites memory
    oam_copy(oam_mem, obj_buffer, 1);
}

void update_game() {
}

void init_video() {
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
	
	// Cargar fondo	
	load_background();
	// Cargar sprites
	load_sprites();
    // Inicializar video
    init_video();
	
    // Inicializar datos    
	init_game();
	
	while(1)
	{
		// Sincronizar con VBlank
        VBlankIntrWait();
        // Actualizar contador de frames
		game.frame++;
        // Leer botones
		key_poll();
        // Actualizar juego
		update_game();
	}

	return 0;
}
