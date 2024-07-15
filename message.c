#include <stdio.h>
#include <string.h>
#include "user.h"

void sendMessage(struct User user) {
    char recipient[50];
    char message[100];

    printf("Введіть одержувача: ");
    scanf("%s", recipient);

    printf("Введіть повідомлення: ");
    scanf(" %[^\n]s", message);

    FILE *file = fopen("messages.txt", "a");
    if (file == NULL) {
        printf("Помилка відкриття файлу.\n");
        return;
    }

    fprintf(file, "--------------------\n");
    fprintf(file, "Від: %s\n", user.username);
    fprintf(file, "Кому: %s\n", recipient);
    fprintf(file, "Повідомлення: %s\n", message);
    fprintf(file, "--------------------\n");

    fclose(file);

    printf("Повідомлення відправлено.\n");
}

void viewMessages() {
    printf("Переглядаєте отримані повідомлення:\n");

    FILE *file = fopen("messages.txt", "r");
    if (file == NULL) {
        printf("Помилка відкриття файлу.\n");
        return;
    }

    char line[200];
    int messageCount = 0;

    while (fgets(line, sizeof(line), file)) {
        messageCount++;
        printf("%s", line); // Виводимо зчитаний рядок (повідомлення) на екран
    }

    fclose(file);

    if (messageCount == 0) {
        printf("Немає отриманих повідомлень.\n");
    }
}

Файл message.h
#ifndef MESSAGE_H
#define MESSAGE_H

#include "user.h"

void sendMessage(struct User user);
void viewMessages();

#endif
