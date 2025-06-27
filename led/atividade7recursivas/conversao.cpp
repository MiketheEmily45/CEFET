#include <iostream>

using namespace std;

unsigned long long int binario(int a) {
    if (a / 2 == 0) return a % 2;
    return a % 2 + (binario(a / 2) * 10);
}

int main()
{
    int a;
    cout << "Insira um número:" << endl;
    cin >> a;
    cout << binario(a);
    return 0;
}
