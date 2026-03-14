#include "graphics.h"

uint32_t* vram = (uint32_t*)0xFD000000;

// Renk karıştırma (Blending) - Cam efektinin sırrı burası
uint32_t blend(uint32_t fg, uint32_t bg, uint8_t alpha) {
    uint8_t rb = (bg >> 16) & 0xFF, gb = (bg >> 8) & 0xFF, bb = bg & 0xFF;
    uint8_t rf = (fg >> 16) & 0xFF, gf = (fg >> 8) & 0xFF, bf = fg & 0xFF;

    uint8_t r = (rf * alpha + rb * (255 - alpha)) / 255;
    uint8_t g = (gf * alpha + gb * (255 - alpha)) / 255;
    uint8_t b = (bf * alpha + bb * (255 - alpha)) / 255;

    return (r << 16) | (g << 8) | b;
}

void draw_background_gradient() {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        uint8_t factor = (y * 255) / SCREEN_HEIGHT;
        uint32_t color = blend(AURA_BG_BOTTOM, AURA_BG_TOP, factor);
        for (int x = 0; x < SCREEN_WIDTH; x++) vram[y * SCREEN_WIDTH + x] = color;
    }
}

void draw_glass_panel(int x, int y, int w, int h, uint8_t alpha) {
    for (int i = y; i < y + h; i++) {
        for (int j = x; j < x + w; j++) {
            uint32_t bg = vram[i * SCREEN_WIDTH + j];
            vram[i * SCREEN_WIDTH + j] = blend(AURA_GLASS, bg, alpha);
        }
    }
    // Panelin dışına ince parlayan çerçeve
    for (int j = x; j < x + w; j++) vram[y * SCREEN_WIDTH + j] = blend(AURA_BLUE, AURA_GLASS, 100);
}

void draw_halo(int x0, int y0, int radius, uint32_t color) {
    // Parlayan halka algoritması
    int x = radius - 1, y = 0, dx = 1, dy = 1, err = dx - (radius << 1);
    while (x >= y) {
        vram[(y0 + y) * SCREEN_WIDTH + (x0 + x)] = color;
        vram[(y0 + x) * SCREEN_WIDTH + (x0 + y)] = color;
        vram[(y0 + x) * SCREEN_WIDTH + (x0 - y)] = color;
        vram[(y0 + y) * SCREEN_WIDTH + (x0 - x)] = color;
        vram[(y0 - y) * SCREEN_WIDTH + (x0 - x)] = color;
        vram[(y0 - x) * SCREEN_WIDTH + (x0 - y)] = color;
        vram[(y0 - x) * SCREEN_WIDTH + (x0 + y)] = color;
        vram[(y0 - y) * SCREEN_WIDTH + (x0 + x)] = color;
        if (err <= 0) { y++; err += dy; dy += 2; }
        if (err > 0) { x--; dx += 2; err += dx - (radius << 1); }
    }
}