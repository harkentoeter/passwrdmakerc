#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* generate_password(int length) {
    static char password[1025];
    srand(time(NULL));

    const char* uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* lowercase = "abcdefghijklmnopqrstuvwxyz";
    const char* digits = "0123456789";
    const char* special_characters = "!@#$%^&*()_+-=[]{}|;:,./<>~`\\";

    int uppercase_length = strlen(uppercase);
    int lowercase_length = strlen(lowercase);
    int digits_length = strlen(digits);
    int special_characters_length = strlen(special_characters);

    for (int i = 0; i < length - 1; ++i) {
        int character_set = rand() % 4;
        switch (character_set) {
            case 0:
                password[i] = uppercase[rand() % uppercase_length];
                break;
            case 1:
                password[i] = lowercase[rand() % lowercase_length];
                break;
            case 2:
                password[i] = digits[rand() % digits_length];
                break;
            case 3:
                password[i] = special_characters[rand() % special_characters_length];
                break;
        }
    }

    password[length - 1] = '\0';

    int last_character_set = rand() % 4;
    switch (last_character_set) {
        case 0:
            password[length - 1] = uppercase[rand() % uppercase_length];
            break;
        case 1:
            password[length - 1] = lowercase[rand() % lowercase_length];
            break;
        case 2:
            password[length - 1] = digits[rand() % digits_length];
            break;
        case 3:
            password[length - 1] = special_characters[rand() % special_characters_length];
            break;
    }

    return password;
}

int main() {
    int password_length = 500;
    char* password = generate_password(password_length);

    printf("Random password: %s\n", password);

    return 0;
}

