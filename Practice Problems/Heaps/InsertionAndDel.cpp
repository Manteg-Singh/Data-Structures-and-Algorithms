#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        int data = x;
        left = NULL;
    }
};

class heap
{
public:
    int arr[100];
    int size = 0;

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void delRoot()
    {
        if (size == 0)
        {
            cout << " Heap already empty!" << endl;
            return;
        }
        if (size == 1)
        {
            arr[size] = -1;
            size--;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        int left = 2 * i;
        int right = 2 * i + 1;

        while (i < size)
        {
            if (left > size && right > size)
                return;
            if (right > size)
            {
                if (arr[i] < arr[left])
                {
                    swap(arr[i], arr[left]);
                }
                return;
            }

            if (arr[i] >= max(arr[left], arr[right]))
            {
                return;
            }
            if (arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            left = 2 * i;
            right = 2 * i + 1;
        }

        // int ind = 1;
        // int leftChild = 2 * ind;
        // int rightChild = (2*ind+1<=size) ? (2 * ind + 1): -1;
        // int r;
        // if(rightChild==-1) r=-1;
        // else r=arr[rightChild];

        // while (leftChild<=size&&arr[ind]<max(arr[leftChild],r))
        // {
        //     int maxi=-1,maind=-1;
        //     if(arr[leftChild]>arr[ind]){
        //         maind=leftChild;
        //         maxi=arr[leftChild];
        //     }
        //     else {
        //         maind=rightChild;
        //         maxi=arr[rightChild];
        //     }

        //     swap(arr[ind],arr[maind]);
        //     ind=maind;
        //     leftChild = 2 * ind;
        //     rightChild = (2*ind+1<=size) ? (2 * ind + 1): -1;
        //     if(rightChild==-1) r=-1;
        //     else r=arr[rightChild];
        // }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    { // n is 1 size larger than actual arr we need coz of 1 based indexing
        largest = left;
    }
    else if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int ar[], int n)
{
    // Step1 : Create Heap
    for (int i = 1; i <= (n) / 2; i++)
    {
        heapify(ar, n, i);
    }

    int size = n;
    while (size > 1)
    {
        // Step2 : swap top element with last & fix it
        swap(ar[1], ar[size]);
        size--;

        // Step3 : Heapify swapped element to correct postn
        heapify(ar, size, 1);
    }
}

void printt(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // heap h1;
    // h1.insert(60);
    // h1.insert(50);
    // h1.insert(40);
    // h1.insert(30);
    // h1.insert(20);

    // cout << "Before insertion: ";
    // h1.print();

    // cout << "After insertion: "; //
    // h1.insert(55);               //
    // h1.print();                  //

    // cout << "After insertion 2: ";
    // h1.insert(70);
    // h1.print();

    // cout << "After deletion of " << h1.arr[1] << ": ";
    // h1.delRoot();
    // h1.print();

    // cout << "After deletion of " << h1.arr[1] << ": ";
    // h1.delRoot();
    // h1.print();

    // cout << "After deletion of " << h1.arr[1] << ": ";
    // h1.delRoot();
    // h1.print();

    int ar[] = {-1, 54, 53, 55, 52, 50};
    int n = 6 - 1;
    // for (int i = 1; i <=(n)/2; i++)
    // {
    //     heapify(ar,n,i);
    // }

    heapSort(ar, n);
    cout<<"After Sorting:\n";
    printt(ar, n);

    return 0;
}
