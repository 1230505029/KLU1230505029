#include <stdio.h>
#include <ctype.h>

void encrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = islower(message[i]) ? 'a' : 'A';
            message[i] = (message[i] - base + key) % 26 + base;        //Kullandığımız döngüler.
        }
    }
}

void decrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = islower(message[i]) ? 'a' : 'A';
            message[i] = (message[i] - base - key + 26) % 26 + base;    //Kullandığımız döngüler.
        }
    }
}

int main(void) {
    char message[1000];
    int key;
    int choice;

    while (1) {
        printf("\nLütfen Yapmak İstediğiniz İşlemi Seçiniz:\n");
        printf("1=Şifreleme\n2=Şifre çözme\n3=Programın Sonlandırılması\n");
        scanf("%d", &choice);        //Bilgi alır.

        if (choice == 3) {
            printf("Program sonlandırılıyor.\n");
            break;                   //Programı direkt bitirir.
        }

        printf("Lütfen Öteleme Adetini Giriniz: ");
        scanf("%d", &key);           //Kaç karakter öteleyeceğimizi sorar.

      
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Lütfen Mesajı Girin:\n");
        scanf(" %[^\n]s", message);  //Ötelenecek metni sorar.

       switch (choice) {
          case 1:
             encrypt(message, key);
             printf("Şifrelenmiş Metin:\n%s\n", message);
             break;
          case 2:
             decrypt(message, key);
             printf("Şifresi Çözülmüş Metin:\n%s\n", message);
             break;
          default:
             printf("Geçersiz seçim. Lütfen tekrar deneyin.\n");
                                    //Üç seçenekten biriyle programı bitirir.
       }
    }

    return 0;
}




