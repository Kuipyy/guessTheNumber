#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int guessing(int correctIndex, int index) {
    // kullanıcının tahmin ettiği değerin alfabedeki sıralaması ile
    // gerçekte seçilen karakterin alfabedeki sıralamasını tutan değişkenleri parametre olarak alan fonk. başlatıldı
    if (index > correctIndex) {
        // Bu aşamada gerçek indeks değerinin tahmin edilen indeks değerinden uzakta olup olmadığına bakılıyor
        printf("Way ahead! Please try again.\n"); // Uzakta olduğu koşulda uyarı geçiliyor
        return 1;
        // Her türlü yanlış tahmin edildiği için buradan 1 değerini döndürüyoruz ki bu değeri toplayıp tahmin sayısını toplatabilelim
    } else if (index < correctIndex) {
        // Bu aşamada gerçek indeks değerinin tahmin edilen indeks değerinden daha yakında olup olmadığına bakılıyor
        printf("Way behind! Please try again.\n"); // Daha yakında olduğu koşulda uyarı geçiliyor
        return 1; // Yanlış tahmin, yanlış olduğu için 1 döndürüyoruz
    } else {
        // ne uzak ne de yakında değilse indeksler birbirine eşit yani aynı karakterin tahmin edildiği sonucunu ifade eder
        printf("Great! Your guess is right!\n"); // Tebrik mesajı
        return 0; // Doğru tahmin, doğru olduğu için 0 döndürüyoruz, tahmin sayacına eklenmesine gerek görülmedi
    }
}

int main() {
    // Ana fonk. başlatıldı
    char alphabet[26] = {
        // 26 karakterden oluşan alfabe dizisi tanımlandı
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    // Her defasında rastgele bir karakteri sisteme seçtirmek için srand ve rand fonksiyonları kullanıldı
    srand(time(NULL)); // Rastgele sayıların farklı olmasını sağlamak için ifade
    int correctIndex = rand() % 26; // 0-25 arası rastgele bir indeks üretilmesi sağlandı
    char correctChar = alphabet[correctIndex]; // Rastgele seçilen indeks değerinin karşılık geldiği karakter tutuluyor

    char choice; // Kullanıcıdan alınacak tahmin karakteri
    int incorrectCount = 0; // Yanlış tahmin sayısının tutulacağı değişken 0'la başlatıldı

    // Kullanıcıyı karşılama mesajı
    printf("I have selected a non-turkish character between A and Z.\n");
    printf("Try to guess the character selected by me!\n");
    printf("What is your guess?\n"); // Kullanıcıdan tahmin girilmesi bekleniyor

    // Tahmin yapılacak olan döngü başladı
    while (1) {
        // Sonsuz döngüye alındı böylece doğru yanıt gelene kadar devam edilecek
        scanf(" %c", &choice); // Kullanıcının girdiği değer karakter cinsinden alındı

        int index = -1; // Varsayılan olarak -1, eğer geçerli bir karakter değilse, bu döngüye girilemeyecek
        for (int i = 0; i < 26; i++) {
            // Karakterin indeksini bbulacak olan döngü başladı
            if (alphabet[i] == choice) {
                // İndex değeri tüm alfabe indeks değerlerini döner ve olması gereken yere ulaştığında
                // döngü durur ve bulunduğu konum index olarak saklanır:
                index = i;
                break;
            }
        }

        if (index == -1) {
            // Geçersiz karakter girildiğinde kullanıcı uyarılmış olur
            printf("Invalid input. Please enter a character between A and Z.\n");
        } else {
            // Geçerli bir karakter değeri girilmiş demektir, tahmin etme fonksiyonu çalıştırılır:
            int result = guessing(correctIndex, index);

            // Eğer yanlış tahminse, yanlış tahmin sayısı artırılıyor
            if (result == 1) {
                // guessing fonksiyonunda yanlış sonuç olduğunda fonksiyondan 1 değeriyle çık demiştik
                incorrectCount++; // Yanlış tahmin sayısını artır
            }

            // Eğer doğru tahminse, döngüyü sonlandırıyoruz
            if (result == 0) {
                // fonksiyondan 0 değeri ile çık dediğimiz için bu aşamaya 0 değerini alarak gelmiştir dolayısıyla doğru indekstir
                break; // Doğru tahmin yapıldı, döngü sonlanır
            }
        }
    }

    // Toplam yanlış tahmin sayısını yazdırma
    printf("Total incorrect guesses: %d\n", incorrectCount);

    if (incorrectCount == 5) {
        // 5 tahmin sonucunda ulaştıysa yapılacaklar:
        printf("I guess you know the secret!\n");
    } else if (incorrectCount > 5) {
        // 5'ten daha fazla tahminle ulaşıldıysa yapılacaklar:
        printf("You should be able to do better!");
    } else {
        // 5'ten daha az tahminle ulaşıldıysa yapılacaklar:
        printf("Either you know the secret or you are lucky!\n");
    }

    return 0;
}
