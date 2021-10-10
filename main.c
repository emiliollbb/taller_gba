#include <tonc.h>
#include <string.h>
#include "background.gfx.h"

struct game_s {
    int objects;
    u32 frame;
};
struct game_s game;

void init_game() {
    game.objects=0;
    game.frame=0;    
}

void load_background() {
    // Cargar paleta
	memcpy(pal_bg_mem, background_gfxPal, background_gfxPalLen);
	// Cargar tiles en CBB 0
	memcpy(&tile_mem[0][0], background_gfxTiles, background_gfxTilesLen);
	// Cargar mapa de tiles en SBB 16
	memcpy(&se_mem[16][0], background_gfxMap, background_gfxMapLen);
    
    // Activar fondo 0 usando CBB0 Y SBB16
	REG_BG0CNT= BG_CBB(0) | BG_SBB(16) | BG_4BPP | BG_REG_64x32 | BG_PRIO(1);
	
	// Scroll horizontal fondo 0
	REG_BG0HOFS= 0;
    // Scroll vertical fondo 0
	REG_BG0VOFS= 0;
}

void load_sprites() {
}

void update_game() {
}

void init_video() {
    // Init Display
    REG_DISPCNT= DCNT_MODE0 
                | DCNT_BG0 
    //            | DCNT_OBJ | DCNT_OBJ_1D
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
