#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
};

void registerUser() {
    struct User user;

    printf("Введіть ім'я користувача: ");
    scanf("%s", user.username);

    printf("Введіть пароль: ");
    scanf("%s", user.password);

    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Помилка відкриття файлу.\n");
        return;
    }

    fprintf(file, "%s %s\n", user.username, user.password);

    fclose(file);

    printf("Реєстрація успішна.\n");
}
