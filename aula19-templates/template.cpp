#include <iostream>
using namespace std;




template<class MyVarType> void swap_values(MyVarType &variable1, MyVarType &variable2) {
    MyVarType temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

template<class MyVarType> void bubbleSort(MyVarType a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
                swap_values(a[j], a[j - 1]);
}
  
int main()
{
    //int a{2};
    //int b{4};
    //swap_values(2, 4);

    int a[5] = { 10, 50, 30, 40, 20 };
    int n = 5;
  
    // calls template function
    bubbleSort(a, n);
  
    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
  
    return 0;
}