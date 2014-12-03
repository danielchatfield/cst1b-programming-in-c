#include <stdio.h>

template <int p, int i>
struct prime_ {
    static const bool isPrime = ( (p % i) && prime_<p, i - 1>::isPrime );
};

template <int p>
struct prime_<p, 1> {
    static const bool isPrime = true;
};

template <int p>
struct prime {
    static const bool isPrime = prime_<p, p-1>::isPrime;
};

struct prime<29> prime56;

int main() {
    if(prime56.isPrime){
        printf("Prime");
    } else {
        printf("Not prime");
    }
}
