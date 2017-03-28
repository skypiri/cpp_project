#include <iostream>

using namespace std;

int square(int n) { return n * n; }
double square(double n) { return n*n; }

int main(int argc, char *argv[])
{

//    printf("%p\n", &square);      // error
//    auto p1 = square;             // error
    int(&r1)(int) = square;         // ok
    int(*p1)(int) = square;         // ok
    return 0;
}
