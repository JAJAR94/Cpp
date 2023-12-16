#include <iostream>

int main() {
    const char* message = "Hello, World!";  // C-style string

    // Accessing characters using pointer arithmetic
    const char* ptr = message;  // Pointer to the first character of the string

    while (*ptr != '\0') {
        std::cout << *ptr;  // Print the current character
        ptr++;  // Move the pointer to the next character
    }

    std::cout << std::endl;

    // Modifying the string using pointers
    char greeting[] = "Good day!";  // C-style string stored in an array

    char* ptr2 = greeting;  // Pointer to the first character of the string

    while (*ptr2 != '\0') {
        *ptr2 = 'X';  // Modify the current character
        ptr2++;  // Move the pointer to the next character
    }

    std::cout << greeting << std::endl;

    return 0;
}
