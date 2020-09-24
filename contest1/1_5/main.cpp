#include <iostream>

void linear_square(int input) {
    int count = 1;
    uint64_t sqr = 0;
    for(int i = 0; i < input; i++) {
        sqr += count;
        count += 2;
        std::cout << sqr << " ";
    }
}

int main() {
    int input;
    std::cin >> input;
    linear_square(input);
    return 0;
}