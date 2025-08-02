#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_valid_input(const char *str) {
    while (*str) {
        if (!isdigit(*str) && *str != ' ')
            return 0;
        str++;
    }
    return 1;
}

int count_numbers(const char *str) {
    int count = 0;
    int in_number = 0;
    while (*str) {
        if (isdigit(*str)) {
            if (!in_number) {
                count++;
                in_number = 1;
            }
        } else {
            in_number = 0;
        }
        str++;
    }
    return count;
}

int *split_and_convert(const char *str, int *size) {
    *size = count_numbers(str);
    int *numbers = malloc(sizeof(int) * (*size));
    if (!numbers) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    const char *start = str;
    while (*str) {
        if (isdigit(*str)) {
            start = str;
            while (isdigit(*str)) str++;
            char temp[32];
            int len = str - start;
            strncpy(temp, start, len);
            temp[len] = '\0';
            numbers[index++] = atoi(temp);
        } else {
            str++;
        }
    }

    return numbers;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "❌ Usage: %s \"<numbers separated by spaces>\"\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input = argv[1];

    if (!is_valid_input(input)) {
        fprintf(stderr, "❌ Invalid input: only digits and spaces are allowed.\n");
        return EXIT_FAILURE;
    }

    int size;
    int *numbers = split_and_convert(input, &size);

    printf("✅ Parsed numbers:\n");
    for (int i = 0; i < size; i++) {
        printf("  ➤ numbers[%d] = %d\n", i, numbers[i]);
    }

    free(numbers);
    return EXIT_SUCCESS;
}

