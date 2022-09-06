#include <stdlib.h>
#include <stdio.h>

struct numbers {
    int n;
    int *nums;
};

int n;

struct numbers *numbers;

void create_numbers(struct numbers **nrs, int *n) {
    *n = 3; // length of outter array
    *nrs = malloc((sizeof(struct numbers) * 3));  // array of struct numbers
    struct numbers *nm = *nrs; // why need this? 
    for (int i = 0; i < 3; i++) {
        nm->n = i + 1; // length of the inner array
        nm->nums = malloc(sizeof(int) * (i + 1));
        for (int j = 0; j < i + 1; j++) {
            nm->nums[j] = i + j;
        }
        nm++;
    }
}

void output_report(struct numbers *numbers) {
    puts("numbers");
    for (int i = 0; i < numbers->n; i++) {
        printf("Number: %d\n", numbers->nums[i]);
    }
    printf("\n");
}

int main() {
    create_numbers(&numbers, &n);
    for (int i = 0; i < 2; i++) {
        output_report(&numbers[i]);
        // numbers++; keep numbers as the base pointer and make the memory can be still reachable
    }
    return 0;
}
