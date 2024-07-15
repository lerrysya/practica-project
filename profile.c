#include <stdio.h>
#include "user.h"

void showProfile(struct User user) {
    printf("Мій профіль:\n");
    printf("Нікнейм: %s\n", user.username);
    printf("Пароль: %s\n", user.password);
    printf("Ім'я: %s\n", user.firstName);
    printf("Прізвище: %s\n", user.lastName);
}
Файл profile.h
#ifndef PROFILE_H
#define PROFILE_H

#include "user.h"

void showProfile(struct User user);

#endif
