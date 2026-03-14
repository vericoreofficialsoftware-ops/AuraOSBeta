#include "graphics.h"

void render_aura_explorer() {
    draw_background_gradient(); // İlk resimdeki gibi derin geçişli arka plan

    // Ana Explorer Penceresi (Hafif şeffaf cam etkisi)
    draw_glass_panel(80, 80, 864, 560, 160);

    // Sol Panel (Gezgin Alanı)
    draw_glass_panel(100, 150, 200, 450, 40);

    // Orta HALO Sistemi
    draw_halo(512, 360, 140, AURA_BLUE);
    
    // Halkanın etrafındaki küçük ikon kutucukları
    draw_glass_panel(500, 240, 24, 24, 200); // Üst
    draw_glass_panel(500, 460, 24, 24, 200); // Alt
    draw_glass_panel(390, 350, 24, 24, 200); // Sol
    draw_glass_panel(610, 350, 24, 24, 200); // Sağ

    // Alt Görev Çubuğu (Taskbar)
    draw_glass_panel(460, 710, 100, 40, 180); 
}