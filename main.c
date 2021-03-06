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
    /***** CODIGO DEMO JAQUERIA. ELIMINAR AL INICIO DEL TALLER*********/
    REG_DISPCNT= DCNT_MODE0 | DCNT_BG2;
    const unsigned short backgroundz_gfxTiles[1424] __attribute__((aligned(4))) ={0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFAF,0xFFFF,0xC10F,0xFFFF,0x000E,0xFFC1,0x000D,0xB300,0x000B,0x0000,0x000A,0x0000,0x0009,0x0000,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFC3,0xFFFF,0xE300,0xFFFF,0x0000,0xFFE3,0x0007,0x0000,0x0006,0x0000,0x0004,0x0000,0x0004,0x0000,0x0001,0x0000,0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xD500,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFFF,0xFFFF,0xFFE6,0xFFFF,0xFA00,0xFFFF,0xF800,0xFFFF,0xF700,0xFFFF,0xF700,0xFFFF,0xF500,0xFFFF,0xF400,0xFFFF,0xFFFF,0xBFFF,0xFFFF,0xCFFF,0xFFFF,0x8FFF,0xFFFF,0x7FFF,0xFFFF,0x3FFF,0xFFFF,0x4FFF,0xFFFF,0x1FFF,0xFFFF,0x1FFF,0xF400,0xFFFF,0xF300,0xFFFF,0xF100,0xFFFF,0xF100,0xFFFF,0xF000,0xFFFF,0xF000,0xFFFF,0xF000,0xFFFF,0xF000,0xFFFF,0xFFFF,0x1FFF,0xFFFF,0x0FFF,0xFFFF,0x0FFF,0xFFFF,0x0EFF,0xFFFF,0x0DFF,0xFFFF,0x0BFF,0xFFFF,0x09FF,0xFFFF,0x06FF,0xF000,0xFFFF,0xD000,0xFFFF,0xC000,0xFFFF,0xC000,0xFFFF,0xB000,0xFFFF,0x9000,0xFFFF,0x9000,0xFFFF,0x8000,0xFFFF,0xFFFF,0x04FF,0xFFFF,0x01FF,0xFFFF,0x00FF,0xFFFF,0x00EF,0xFFFF,0x00EF,0xFFFF,0x00DF,0xFFFF,0x00DF,0xFFFF,0x00BF,0x7000,0xFFFF,0x5000,0xFFFF,0x5000,0xFFFF,0x4000,0xFFFF,0x3000,0xFFFF,0x3000,0xFFFF,0x3000,0xFFFF,0x3000,0xFFFF,0xFFFF,0x00BF,0xFFFF,0x009F,0xFFFF,0x009F,0xFFFF,0x005F,0xFFFF,0x004F,0xFFFF,0x001F,0xFFFF,0x001F,0xFFFF,0x000F,0x1000,0xFFFF,0x1000,0xFFFF,0x1000,0xFFFF,0x0000,0xFFFF,0x0000,0xFFFF,0x0000,0xFFFF,0x0000,0xFFFF,0x0000,0xFFFE,0xFFFF,0x000F,0xFFFF,0x000D,0xFFFF,0x000B,0xFFFF,0x0009,0xFFFF,0x0008,0xFFFF,0x0006,0xFFFF,0x0004,0xFFFF,0x0004,0x0000,0xFFFE,0x0000,0xFFFD,0x0000,0xFFFC,0x0000,0xFFF9,0x0000,0xFFF9,0x0000,0xFFF9,0x0000,0xFFF6,0x0000,0xFFF4,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xEFFF,0xFFFF,0x4FFF,0xFFFF,0x3FFF,0xFFFF,0x2FFF,0xFFFF,0x1FFF,0xFFFF,0x0FFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xBBBC,0xBBBB,0x0000,0x0000,0x0000,0x0000,0x0000,0x4555,0x0000,0xDCC9,0x0000,0xCCC0,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xABBB,0x8888,0x0000,0x0000,0x0000,0x0000,0x7754,0x6665,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x8888,0xFA88,0x0000,0xC000,0x0000,0x0000,0x9877,0x004A,0xCCCC,0x03CC,0xCCCC,0x0CCC,0xFFFF,0x0002,0xFFFF,0x0002,0xFFFF,0x0000,0xFFFF,0x0000,0xEFFE,0x0000,0xEFF1,0x0000,0xAF40,0x0000,0xA600,0x0000,0x0000,0xFFF4,0x0000,0xFFF4,0x0000,0xFFF1,0x0000,0xFFF0,0x0000,0xFFF0,0x0000,0xFFF0,0x0000,0xFFF0,0x0000,0xFFE0,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xBFFF,0xFFFF,0x4FFF,0xFFFF,0x0FFF,0xFFFF,0x49FF,0xFFFF,0xA1FF,0xFFFF,0xD0EF,0xFFFF,0xFFFF,0xFFFD,0xFFFF,0xFF40,0xFFFF,0xA057,0xFFFF,0x1CDD,0xFFE2,0xDDDE,0xFF70,0x1BDD,0xFFF7,0xA0BD,0xFFFF,0xFFFF,0x0FFF,0xFFFF,0x0FFF,0xFFFF,0x0CFF,0xFFFF,0x0BFF,0xFFFF,0x08FF,0xFFFF,0x07FF,0xFFFF,0x04FF,0xFFFF,0x02FF,0x0000,0xCC30,0x0000,0xCA00,0x0000,0xC000,0x0000,0x4000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCC8,0xCCCC,0xCCC0,0xCCCC,0xCC20,0xCCCC,0xC800,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0x2000,0x0000,0x000A,0x0000,0x008C,0x0000,0x06CC,0x0000,0x7CCC,0x0000,0xCCCC,0x0003,0xCCCC,0x002D,0xCCCC,0x01CC,0x0000,0xFFE0,0x0000,0xFFE0,0x0000,0xFFE0,0x0000,0xFFE0,0x0000,0xFFD0,0x0000,0xFFD0,0x0000,0xFFC0,0x0000,0xFFC0,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x7778,0xEFFF,0x4430,0xCFFF,0xDD90,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFF87,0xFFFF,0xFF04,0x5FFF,0xFB0D,0x04FF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x88AD,0xFFFB,0x0300,0xFC00,0x2D00,0xD000,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x89AF,0x8888,0x200E,0x4444,0x600E,0xDDDD,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xF988,0x888D,0xC014,0x0005,0xC02D,0x0005,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x8888,0x8CF8,0x0000,0x05C0,0x0000,0x05C0,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x8888,0xFFB9,0x0000,0xD100,0x7771,0x0028,0xFFFF,0xE76F,0xFFFF,0x6D0F,0xFFFF,0x240B,0xFFFF,0xF47F,0xFFFF,0xFFFF,0x9EFF,0xD999,0x07FF,0x6000,0x08FE,0x6000,0xFD09,0xFFFF,0xFFD1,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xEFFF,0x7777,0x9FFF,0x4440,0x7FFF,0xDDD0,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFF87,0xFFFF,0xFF04,0xFFFF,0xFD0B,0xFFFF,0xFFFF,0x01FF,0xFFFF,0x00FF,0xFFFF,0x00FF,0xFFFF,0x00EF,0xFFFF,0x00EF,0xFFFF,0x00EF,0xFFFF,0x00DF,0xFFFF,0x00CF,0xA000,0xCCCC,0x1000,0xCCCD,0x0000,0xCCC5,0x0000,0xCC90,0x0000,0xCB00,0x0000,0xD200,0x0000,0x4000,0x0000,0x0000,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCA,0xCCCC,0xCCCC,0x0CCC,0xCCCC,0xACCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0x0000,0x0000,0x0000,0x0000,0x000B,0x0000,0x00BC,0x0000,0x0BCC,0x0000,0x9CCC,0x0000,0xCCCC,0x0009,0xCCCC,0x00AC,0x0000,0xFFB0,0x0000,0xFFA0,0x0000,0xFF90,0x0000,0xFF90,0x0000,0xFF60,0x0000,0xFF50,0x0000,0xFF40,0x0000,0xFF30,0x8FFF,0xDD70,0x3FFF,0xDE40,0x0FFF,0xDE20,0x0EFF,0xDE00,0x0DFF,0xDD00,0x0BFF,0xDA00,0x09FF,0xC700,0x06FF,0x9500,0xF80A,0x00EF,0xF406,0x00DF,0xF103,0x00DF,0xF102,0x00DF,0xF001,0x00DF,0xD000,0x00DF,0xA000,0x00DF,0x6000,0x00DF,0x4D00,0x9000,0x7D10,0x6000,0xAD20,0x6000,0xDD30,0x6000,0xED50,0x6000,0xED80,0x6002,0xEDB0,0x6005,0xDDD0,0x6007,0x400E,0xDDDE,0x200F,0xDDDE,0x000F,0xDDDE,0x000F,0xDDDD,0x000F,0xEDDB,0x000F,0xEDD9,0x000F,0xDDD6,0x000F,0xBDD3,0xC00D,0x0006,0xC00D,0x0006,0xD00C,0x0005,0xC009,0x0005,0xD005,0x0005,0xC000,0x0005,0xC000,0x0005,0xC000,0x0005,0x0000,0x05D0,0xDE70,0x05FE,0xFF70,0x05FF,0xFF80,0x05FF,0xBC60,0x05FE,0x0000,0x05F0,0x0000,0x05F0,0x0000,0x05F0,0xDDE0,0x001E,0xDDB0,0x000D,0xDD80,0x0009,0xDD40,0x0005,0xDE10,0x0003,0xEC00,0x0001,0xD700,0xD000,0x8200,0x0000,0x08FA,0x6000,0x08F8,0x6000,0x08F8,0x6000,0x08F8,0x6000,0x08FA,0x6000,0x08FF,0x6000,0x08FF,0x6000,0x08FE,0x6000,0x5FFF,0xDDD0,0x2FFF,0xEDB0,0x0FFF,0xDD90,0x0EFF,0xCD60,0x0BFF,0xAE30,0x07FF,0x8E00,0x03FF,0x5D00,0x01FF,0x1D00,0xFB07,0xFFFF,0xF902,0xFFFF,0xF600,0xFFFF,0xF300,0xFFFF,0xF100,0xFFFF,0xE000,0xFFFF,0xB000,0xFFFF,0x8000,0xFFFF,0xFFFF,0x00AF,0xFFFF,0x008F,0xFFFF,0x006F,0xFFFF,0x004F,0xFFFF,0x002F,0xFFFF,0x000F,0xFFFF,0x000F,0xFFFF,0x000E,0xCCB0,0xCCCC,0xCC10,0xCCCC,0xC300,0xCCCC,0x5000,0xCCCC,0x0000,0xCCC9,0x0000,0xCCB0,0x0000,0xCD10,0x0000,0xC300,0xCCCC,0x09CC,0xCCCC,0xACCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0x0000,0x0000,0x0000,0x0000,0x000A,0x0000,0x00AC,0x0000,0x0BCC,0x0000,0xACCC,0x0000,0xCCCC,0x000A,0xCCCC,0x00AC,0x0000,0xFF10,0x0000,0xFF00,0x0000,0xFF00,0x0000,0xFF00,0x0000,0xFF00,0x0000,0xFF00,0x0000,0xFF00,0x0000,0xFD00,0x03FF,0x6300,0x00FF,0x2200,0x00EF,0x0000,0x00BF,0x0000,0x008F,0x4500,0x005F,0x8800,0x004F,0xBB00,0x003F,0xEE00,0x2000,0x00DF,0x0000,0x00DF,0x0000,0x00DE,0x0000,0x00DC,0x0000,0x00DB,0x0000,0x00E8,0x0000,0x02F5,0x0000,0x3FF1,0xDDE0,0x6009,0xDDE2,0x600B,0xDDE5,0x600D,0xDDD7,0x600E,0xDDD9,0x603E,0xDDDA,0x806D,0x0000,0xD000,0x0000,0xC300,0x000F,0x9DD2,0x000F,0x7DD1,0x000F,0x4ED0,0x000F,0x0ED0,0x000F,0x0DC0,0x000F,0x0AA0,0x002F,0x0670,0x00EF,0x0330,0xC000,0x0005,0xC000,0x0005,0xC000,0x0005,0xC000,0x0005,0xC000,0x0005,0xD000,0x0005,0xF000,0x0005,0xFB00,0x0005,0xBC60,0x05FD,0xFF80,0x05FF,0xFF80,0x05FF,0xFF80,0x05FF,0xFF80,0x05FF,0x2210,0x05E2,0x0000,0x05C0,0x0000,0x05C0,0x1000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x4000,0x0000,0x08F9,0x6000,0x08F8,0x6000,0x08F9,0x6000,0x08F9,0x6000,0x08F9,0x6000,0x08F8,0x6000,0x08F6,0x6000,0x08F3,0x6000,0x01FF,0x0B00,0x00FF,0x0800,0x00DF,0x0100,0x00AF,0x0000,0x005F,0x3B00,0x000F,0x6C00,0x000F,0x8E00,0x000E,0xAE00,0x5000,0xFFFF,0x3000,0xFFFF,0x1000,0xFFFF,0x0000,0xFFFF,0x0000,0xFFFE,0x0000,0xFFFA,0x0000,0xFFF6,0x0000,0xFFF1,0xFFFF,0x000E,0xFFFF,0x000C,0xFFFF,0x000B,0xFFFF,0x0009,0xFFFF,0x111A,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1111,0x1111,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x0000,0x7003,0x0000,0x004E,0x0000,0x03FF,0x1000,0x1EFF,0x3211,0xEFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xCCCC,0xCCCC,0xCCC9,0xCCCC,0x2110,0x1111,0x0000,0x0000,0x2323,0x2223,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xCCCC,0xCCCC,0xCCCC,0xCCCC,0x1011,0x1111,0x0000,0x0000,0x2123,0x3334,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xCCCC,0x0BCC,0xCCCC,0x9CCC,0x0000,0x0000,0x0100,0x0000,0x3333,0x4223,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x0000,0xFC00,0x0000,0xFC00,0x0000,0xFB00,0x0000,0xFA00,0x7777,0xFC67,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x113F,0xFF11,0xFFFF,0xFFFF,0xFFFE,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x1111,0xFFF1,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x158D,0x8000,0xFFFF,0xFEEF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x6FFF,0x1112,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFE4,0x1119,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x1111,0x17D1,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xB111,0x0001,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x19F0,0x8111,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x111D,0xCF21,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x1111,0xFFF2,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF};
	const unsigned short backgroundz_gfxMap[1024] __attribute__((aligned(4))) ={0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0002,0x0003,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0004,0x0005,0x0006,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0007,0x0000,0x0000,0x0008,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0009,0x0000,0x0000,0x000A,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x000B,0x0000,0x0000,0x000C,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x000D,0x0000,0x0000,0x000E,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x000F,0x0000,0x0000,0x0010,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0011,0x0012,0x0013,0x0014,0x0015,0x0000,0x0000,0x0016,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0017,0x0018,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0019,0x001A,0x001B,0x001C,0x001D,0x0000,0x0000,0x001E,0x001F,0x0020,0x0021,0x0022,0x0023,0x0024,0x0025,0x0026,0x0027,0x0028,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0029,0x0000,0x002A,0x002B,0x002C,0x002D,0x0000,0x002E,0x002F,0x0030,0x0031,0x0032,0x0033,0x0034,0x0035,0x0036,0x0037,0x0038,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0039,0x0000,0x0000,0x003A,0x001C,0x003B,0x003C,0x003D,0x003E,0x003F,0x0040,0x0041,0x0042,0x0043,0x0044,0x0045,0x0046,0x0047,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0048,0x0049,0x0049,0x004A,0x004B,0x004C,0x004D,0x004E,0x004F,0x0050,0x0051,0x0052,0x0053,0x0054,0x0055,0x0056,0x0057,0x0058,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000};
	const unsigned short backgroundz_gfxPal[16] __attribute__((aligned(4))) ={0x0000,0x0C63,0x10A4,0x18C6,0x2108,0x294A,0x318C,0x39CE,0x4210,0x4A52,0x5294,0x5AD6,0x6739,0x6F7A,0x73BC,0x7FFF};
	#define backgroundz_gfxTilesLen 2848
	#define backgroundz_gfxMapLen 2048
	#define backgroundz_gfxPalLen 32
	memcpy(pal_bg_mem, backgroundz_gfxPal, backgroundz_gfxPalLen);
	memcpy(&tile_mem[0][0], backgroundz_gfxTiles, backgroundz_gfxTilesLen);
	memcpy(&se_mem[16][0], backgroundz_gfxMap, backgroundz_gfxMapLen);
	REG_BG2CNT= BG_CBB(0) | BG_SBB(16) | BG_4BPP | BG_REG_64x32 | BG_PRIO(1) | BG_MOSAIC;
	REG_BG2VOFS= 0;
	REG_BG2HOFS=240;
    u32 i=0; while(1){VBlankIntrWait(); REG_BG2HOFS=i++/2+240;}
	/***************** FIN DEMO ***************************************/
}

// Metodo main. Inicio del programa
int main()
{
	// Inicializar interrupciones
	irq_init(NULL);
	// Activar interrupci??n VBlank
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

	// Nunca llegaremos a este punto. S??lo por cumplir con estandar c
	return 0;
}
