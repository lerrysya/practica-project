#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


struct User {
    char firstName[50];
    char lastName[50];
    char username[50];
    char password[50];
};


void registerUser() {
    struct User user;

    printf("Введіть ім'я: ");
    scanf("%s", user.firstName);

    printf("Введіть прізвище: ");
    scanf("%s", user.lastName);

    printf("Введіть нікнейм: ");
    scanf("%s", user.username);

    printf("Введіть пароль: ");
    scanf("%s", user.password);


    FILE* file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Помилка відкриття файлу.\n");
        return;
    }

    // Записати дані користувача у файл
    fprintf(file, "%s %s %s %s\n", user.firstName, user.lastName, user.username, user.password);

    // Закрити файл
    fclose(file);

    printf("Реєстрація успішна.\n");
}

void loginUser() {
    char username[50];
    char password[50];

    printf("Введіть нікнейм: ");
    scanf("%s", username);

    printf("Введіть пароль: ");
    scanf("%s", password);

    FILE* file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Помилка відкриття файлу.\n");
        return;
    }

    char line[200];
    int isAuthenticated = 0;

    while (fgets(line, sizeof(line), file)) {
        char savedFirstName[50];
        char savedLastName[50];
        char savedUsername[50];
        char savedPassword[50];
        sscanf(line, "%s %s %s %s", savedFirstName, savedLastName, savedUsername, savedPassword);

        if (strcmp(savedUsername, username) == 0 && strcmp(savedPassword, password) == 0) {
            isAuthenticated = 1;
            break;
        }
    }

    fclose(file);

    if (isAuthenticated) {
        printf("Авторизація успішна.\n");
    }
    else {
        printf("Невірні дані або невдача авторизації.\n");
    }
}

int main() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
    int choice;

    while (1) {
        printf("Оберіть дію:\n");
        printf("1. Реєстрація\n");
        printf("2. Авторизація\n");
        printf("3. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            exit(0);
        default:
            printf("Невірний вибір. Спробуйте ще раз.\n");
        }
    }

    return 0;
}
