#ifndef _ntheory_h
#define _ntheory_h


#endif


//This header file includes things like LCM, GCD, Euler Totient, Primes
//All to do with ints!


//GCD
int gcd(const int& a, const int& b) {
    unsigned x = abs(a);
    unsigned y = abs(b);
    return y == 0 ? x : gcd(y, x % y);
}

//LCM
int lcm(const int& a, const int& b) {
    return abs(a*b/gcd(a,b));
}

//Euler Totient
int etot(const unsigned& a) {
    unsigned counter = 0;
    for(unsigned i=0; i<a; ++i){
        if (gcd(a,i) == 1)
        counter ++;
    }
    return counter;
}

//Primality Check
bool isprime(const unsigned& a) {
    if(a!=2)
        for(unsigned i=2; i<sqrt(a)+1; ++i)
            if(a%i == 0)
                return false;
    
    return (true and a!=1);
}

//Prime Factorization
std::vector<unsigned> fact(unsigned a) {
    std::vector<unsigned> res;
    
    while (a%2 == 0){
        res.push_back(2);
        a /= 2;
    }
    
    for (unsigned i = 3; i < sqrt(a) + 1; i += 2)
        while (a%i == 0){
            res.push_back(i);
            a /= i;
        }
    
    if ( a > 2)
        res.push_back(a);
    
    return res;
}
