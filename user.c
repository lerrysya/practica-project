#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

void loginUser(struct User* user, int* isAuthenticated) {
    char username[50];
    char password[50];

    printf("Введіть ім'я користувача: ");
    scanf("%s", username);

    printf("Введіть пароль: ");
    scanf("%s", password);

    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Помилка відкриття файлу.\n");
        return;
    }

    char line[100];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        char savedUsername[50];
        char savedPassword[50];
        sscanf(line, "%s %s", savedUsername, savedPassword);

        if (strcmp(savedUsername, username) == 0 && strcmp(savedPassword, password) == 0) {
            strcpy(user->username, savedUsername);
            strcpy(user->password, savedPassword);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found) {
        *isAuthenticated = 1;
    } else {
        *isAuthenticated = 0;
    }
}
