#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rastgele_sayi, tahmin, deneme_sayisi = 0;
    
    // Rastgele sayı üreteci için seed ayarlama
    srand(time(NULL));
    
    // 1 ile 100 arasında rastgele sayı üretme
    rastgele_sayi = rand() % 100 + 1;
    
    printf("=== SAYI TAHMİN OYUNU ===\n");
    printf("1 ile 100 arasında bir sayı tuttum!\n");
    printf("Bakalım kaç denemede bulabileceksin?\n\n");
    
    do {
        printf("Tahmininizi girin: ");
        scanf("%d", &tahmin);
        deneme_sayisi++;
        
        if (tahmin < rastgele_sayi) {
            printf("Daha büyük bir sayı deneyin!\n\n");
        }
        else if (tahmin > rastgele_sayi) {
            printf("Daha küçük bir sayı deneyin!\n\n");
        }
        else {
            printf("\n🎉 TEBRİKLER! 🎉\n");
            printf("Doğru tahmin! Sayı: %d\n", rastgele_sayi);
            printf("Toplam deneme sayısı: %d\n", deneme_sayisi);
            
            // Performans değerlendirmesi
            if (deneme_sayisi <= 5) {
                printf("Mükemmel! Çok iyi bir tahmin yeteneğiniz var! 🌟\n");
            }
            else if (deneme_sayisi <= 10) {
                printf("İyi iş çıkardınız! 👍\n");
            }
            else {
                printf("Biraz daha pratik yapabilirsiniz! 😊\n");
            }
        }
        
    } while (tahmin != rastgele_sayi);
    
    printf("\nOyun bitti! Tekrar oynamak için programı yeniden çalıştırın.\n");
    
    return 0;
}
