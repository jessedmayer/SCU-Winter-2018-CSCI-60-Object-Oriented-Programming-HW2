#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> v;
    int n,next(0);
    cout << "Enter number of suitors n:";
    cin >> n;

    for(int i=1; i<=n; i++){
        v.push_back(i);
    }
    int size = static_cast<int>(v.size());
    while(size!=1) {
        next+=2;
        if(next>=size)    {
            next=next-size;
        }
        cout << "suitor " << v[next] << " eliminated" <<endl;
        v.erase(v.begin() + next);
        size--;
    }
    cout << "Ideal position is: ";
    cout << v[0];

    return 0;
}
