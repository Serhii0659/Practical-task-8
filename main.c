#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_LENGTH 15 // +1 для нульового завершення

unsigned long long factorial(int n) {
    if (n < 0) return 0; // факторіал не визначений для від'ємних чисел
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

unsigned long long anagramsAmount(char* str) {
    int freq[52] = {0}; // Лічильник частот для 52 літер (26 малих + 26 великих)

    // Підрахунок частот кожної літери у рядку str
    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
        } else if (ch >= 'A' && ch <= 'Z') {
            freq[ch - 'A' + 26]++;
        }
    }

    // Обчислення кількості анаграм
    unsigned long long result = factorial(strlen(str));
    for (int i = 0; i < 52; i++) {
        if (freq[i] > 1) {
            result /= factorial(freq[i]);
        }
    }

    return result;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter text up to 14 characters (no spaces): ");
    scanf("%14s", input); // %14s - обмеження в 14 символів

    size_t len = strlen(input);
    printf("Input: %s\nLen: %zu\n", input, len);

    unsigned long long num_anagrams = anagramsAmount(input);
    printf("Number of anagrams: %llu\n", num_anagrams);

    printf("Press any key to exit the program.");
    getch();
    return 0;
}
