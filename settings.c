#include <stdio.h>
#include <string.h>
#include "user.h"

void changePassword(struct User* user) {
    printf("Введіть старий пароль: ");
    char oldPassword[50];
    scanf("%s", oldPassword);

    if (strcmp(user->password, oldPassword) != 0) {
        printf("Старий пароль невірний. Пароль не буде змінений.\n");
        return;
    }

    printf("Введіть новий пароль: ");
    scanf("%s", user->password);
    printf("Пароль змінено.\n");

    // Оновлення пароля у файлі
    FILE *file = fopen("users.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Помилка відкриття файлів.\n");
        return;
    }

    char line[200];
    char savedUsername[50];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%*s %*s %s", savedUsername); // Зчитуємо нікнейм з рядка
        if (strcmp(savedUsername, user->username) == 0) {
            fprintf(tempFile, "%s %s %s %s\n", user->firstName, user->lastName, user->username, user->password);
        } else {
            fprintf(tempFile, "%s", line);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Перейменовуємо тимчасовий файл на оригінальний
    remove("users.txt");
    rename("temp.txt", "users.txt");
}

void changeUsername(struct User* user) {
    printf("Введіть новий нікнейм: ");
    scanf("%s", user->username);
    printf("Нікнейм змінено.\n");
}

void changeFirstName(struct User* user) {
    printf("Введіть нове ім'я: ");
    scanf("%s", user->firstName);
    printf("Ім'я змінено.\n");
}

void changeLastName(struct User* user) {
    printf("Введіть нове прізвище: ");
    scanf("%s", user->lastName);
    printf("Прізвище змінено.\n");
}

