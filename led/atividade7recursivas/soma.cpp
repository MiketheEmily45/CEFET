#include <iostream>

using namespace std;

int soma(int a) {
    if (a / 10 == 0) return a;
    return a % 10 + soma(a / 10);
}
int main()
{
    int a;
    cout << "Insira um número:" << endl;
    cin >> a;
    cout << soma(a) << endl;
    return 0;
}
