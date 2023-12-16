#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

int factorial(int number)
{
    // return number <= 1 ? number : factorial(number - 1) * number;
/*
    if (number < 2)
        return 1;

    return factorial(number - 1) * number;
*/

    if (number < 2)
        return 1;

    int res = number;
    // invariant: res == n * (n - 1) * (n - 2) * ... * (n - i)
    // 4!
    // [3] res == 4 * 3
    // [2] res == 4 * 3 * 2
    // [1] <stop>
    for (auto i = number - 1; i > 1; --i)
        res *= i;
    return res;
}

TEST_CASE("testing the factorial function") {
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}
