
#include "gmp.h"
#include <Integer.h>

using namespace std;

Integer factor(Integer n)
{
    Integer r, t, u, v, e;

    t = 0;

    if (n%2 == 0) return 2;
    r = sqrt(n);
    if (issquare(n)) {
        if (isprime(r)) return r;
        else return factor(r);
    }
    r++;
    u = 2*r + 1; v = 1;		// start with possible candidates
    e = r*r - n;
    while (e != 0)  {		// minimize the error term a la Gauss
        while (e<0) {e += u; u+=2;}
        while (e>0) {e -= v; v+=2;}
    }
//    return (u+v-2)/2;		// either one will work
    return (u-v)/2;
}


int main (int argc, char *argv[])
{
    Integer n, t;
    int x0, a;
    int p;

    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " NumberToFactor" << endl;
        return -1;
    }

    n = argv[1];

    cout << n << ": " << flush;
    while (!isprime(n)) {
        t = factor(n);
        if (t==0) break;
        cout << t << " " << flush;
        n /= t;
    }
    cout << n << endl;
    return 0;
}