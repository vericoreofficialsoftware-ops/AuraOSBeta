/* AuraOS v1.0 - Donanıma Yakın Kernel */

// Kendi yazı yazdırma fonksiyonumuzu simüle ediyoruz
void aura_print(char* metin) {
    // Gerçek bir kernelda burada ekran kartı belleğine (0xB8000) veri gönderilir
    // Şimdilik simülasyon için burayı boş bırakabiliriz veya temel çıktı alabiliriz
}

void aura_kernel_main() {
    aura_print("AuraOS v1.0 baslatiliyor...");
    aura_print("Islemci: i3 2330M Algilandi.");
    
    int toplam_ram = 256; 
    // Ram kontrol simülasyonu
}

int main() {
    aura_kernel_main();
    return 0;
}