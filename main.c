#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "user.h"
#include "profile.h"
#include "settings.h"
#include "message.h"

void logout(int* isAuthenticated) {
    *isAuthenticated = 0;
    printf("Ви вийшли з аккаунту.\n");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    struct User currentUser;
    int isAuthenticated = 0;
    int settingChoice;

    while (1) {
        if (!isAuthenticated) {
            system("cls");

            printf("\nМеню (ТЕМА: Електронна пошта)\n");
            printf("1. Реєстрація\n");
            printf("2. Авторизація\n");
            printf("3. Вихід\n");
            printf("Ваш вибір: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    registerUser();
                    system("pause");
                    break;
                case 2:
                    loginUser(&currentUser, &isAuthenticated);
                    if (isAuthenticated) {
                        printf("Авторизація успішна.\n");
                        system("pause");
                    } else {
                        printf("Невірні дані або невдача авторизації.\n");
                        system("pause");
                    }
                    break;
                case 3:
                    exit(0);
                default:
                    printf("Невірний вибір. Спробуйте ще раз.\n");
                    system("pause");
                    break;
            }
        } else {
            system("cls");

            printf("\nМеню (ТЕМА: Електронна пошта)\n");
            printf("1. Мій профіль\n");
            printf("2. Налаштування\n");
            printf("3. Відправити повідомлення\n");
            printf("4. Переглянути отримані повідомлення\n");
            printf("5. Вийти з аккаунту\n");
            printf("Ваш вибір: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    showProfile(currentUser);
                    system("pause");
                    break;
                case 2:
                    printf("Налаштування:\n");
                    printf("1. Змінити пароль\n");
                    printf("2. Змінити нікнейм\n");
                    printf("3. Змінити ім'я\n");
                    printf("4. Змінити прізвище\n");
                    printf("5. Повернутись назад\n");
                    printf("Ваш вибір: ");
                    scanf("%d", &settingChoice);

                    switch (settingChoice) {
                        case 1:
                            changePassword(&currentUser);
                            system("pause");
                            break;
                        case 2:
                            changeUsername(&currentUser);
                            system("pause");
                            break;
                        case 3:
                            changeFirstName(&currentUser);
                            system("pause");
                            break;
                        case 4:
                            changeLastName(&currentUser);
                            system("pause");
                            break;
                        case 5:
                            break;
                        default:
                            printf("Невірний вибір. Спробуйте ще раз.\n");
                            system("pause");
                            break;
                    }
                    break;
                case 3:
                    sendMessage(currentUser);
                    system("pause");
                    break;
                case 4:
                    viewMessages();
                    system("pause");
                    break;
                case 5:
                    logout(&isAuthenticated);
                    system("pause");
                    break;
                default:
                    printf("Невірний вибір. Спробуйте ще раз.\n");
                    system("pause");
                    break;
            }
        }
    }

    return 0;
}

