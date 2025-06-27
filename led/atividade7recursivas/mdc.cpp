#include <iostream>

using namespace std;

int MDC(int a, int b) {
    if (a % b == 0) return b;
    return MDC(b, a%b);
    }

int main()
{
    int a, b;
    cout << "Insira 2 números:" << endl;
    cin >> a;
    cin >> b;
    int c = MDC(a, b);
    cout << c << endl;
    return 0;
}
