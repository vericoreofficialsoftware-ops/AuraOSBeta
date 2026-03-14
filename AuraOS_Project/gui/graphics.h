#ifndef GRAPHICS_H
#define GRAPHICS_H

typedef unsigned char  uint8_t;
typedef unsigned int   uint32_t;

// AuraOS Renk Paleti (Birebir İlk Resim Tonları)
#define AURA_BG_TOP    0x0A1428  // Derin siber lacivert
#define AURA_BG_BOTTOM 0x1E0A28  // Derin siber mor
#define AURA_BLUE      0x00F2FF  // Parlayan neon turkuaz
#define AURA_GLASS     0x1A2233  // Şeffaf panel bazı
#define SCREEN_WIDTH   1024
#define SCREEN_HEIGHT  768

void draw_background_gradient();
void draw_glass_panel(int x, int y, int w, int h, uint8_t alpha);
void draw_halo(int x0, int y0, int radius, uint32_t color);

#endif