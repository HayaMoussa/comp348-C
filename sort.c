#include "sort.h"
#include "tablegen.h" //for struct

// This seems to work in print but not in file
int compare_data(const void *a, const void *b) {
    const struct UserData *user_a = (const struct UserData *)a;
    const struct UserData *user_b = (const struct UserData *)b;

    // Compare based on the specified column
    switch (sortedBy) {
        case USER_ID:
            // if substraction is neg -> a is less than b
            // if substration is pos -> a is greater than b
            // if 0, same so order does not matter
            // PRINTS KEPT FOR TA TO SEE HOW IT WORKS
            /*
            printf("ORDER A:%d\n", user_a->user_id);
            printf("ORDER B:%d\n", user_b->user_id);
            printf("int returned by compare: %d\n", user_a->user_id - user_b->user_id);
            */
            return user_a->user_id - user_b->user_id;
        case FIRST_NAME:
            // if value is neg -> a is before b
            // if value is pos -> b is after a
            // if 0, same so order does not matter
            // PRINTS KEPT FOR TA TO SEE HOW IT WORKS
            /*
            printf("ORDER A:%s\n", user_a->first_name);
            printf("ORDER B:%s\n", user_b->first_name);
            printf("int returned by compare: %d\n", strcmp(user_a->first_name, user_b->first_name));
            */

            return strcmp(user_a->first_name, user_b->first_name);
        case LAST_NAME:
            return strcmp(user_a->last_name, user_b->last_name);
        case COUNTRY:
            return strcmp(user_a->country, user_b->country);
        case PHONE_NUMBER:
            return strcmp(user_a->phone_number, user_b->phone_number);
        case EMAIL:
            return strcmp(user_a->email, user_b->email);
        case SIN:
            return strcmp(user_a->sin, user_b->sin);
        case PASSWORD:
            return strcmp(user_a->password, user_b->password);
        default:
            // Handle unsupported column
            return 0;
    }
}