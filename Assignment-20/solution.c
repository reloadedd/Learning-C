#include <stdio.h>

struct Struct {
    int int_member;
    char char_member;
    float float_member;
};

int main() {
    struct Struct s1 = {1337, 'Z', 1.44};

    printf("This is the int: %d, this is the char: %c, this is the float: %.2f\n", s1.int_member,
    s1.char_member, s1.float_member);
}