#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <bits/stdc++.h>
// Return nth Jacobsthal number.
int Jacobsthal(int n)
{
    // base case
    if (n == 0)
        return 0;

    // base case
    if (n == 1)
        return 1;

    // recursive step.
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

// Return nth Jacobsthal-Lucas number.
int Jacobsthal_Lucas(int n)
{
    // base case
    if (n == 0)
        return 2;

    // base case
    if (n == 1)
        return 1;

    // recursive step.
    return Jacobsthal_Lucas(n - 1)
           + 2 * Jacobsthal_Lucas(n - 2);
}

// Driven Program
int main(int argc, char **argv)
{
    int n = 7;
    std::cout << "Jacobsthal number: " << Jacobsthal(std::atoi(argv[1])) << std::endl;
    std::cout << "Jacobsthal-Lucas number: "
         << Jacobsthal_Lucas(n) << std::endl;
    return 0;
}
