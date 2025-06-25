#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int total_boys = A + 1;
    int total_slices = total_boys * 4 + B * 3;
    
    double pizzas = ceil((double)total_slices / 8);
    cout << (int)pizzas << endl;

    return 0;
}
