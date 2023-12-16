#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

/*
bool is_prime(int n)
{
    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i < n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}
*/

bool is_prime(int n)
{
    if (n == 2)
        return true;

    if (n < 2 || n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2) {
        // invariant: i <= sqrt(n) and i is odd
        if (n % i == 0)
            return false;
    }
    return true;
}

TEST_CASE("testing the `is_prime` function") {
    CHECK(is_prime(1) == false);
    CHECK(is_prime(2) == true);
    CHECK(is_prime(3) == true);
    CHECK(is_prime(4) == false);
    CHECK(is_prime(5) == true);
    CHECK(is_prime(6) == false);
    CHECK(is_prime(7) == true);
    CHECK(is_prime(8) == false);
    CHECK(is_prime(9) == false);
    CHECK(is_prime(10) == false);
}
