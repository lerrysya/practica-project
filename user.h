#ifndef USER_H
#define USER_H

struct User {
    char username[50];
    char password[50];
};

void registerUser();

#endif
