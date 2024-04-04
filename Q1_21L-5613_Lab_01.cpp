#include <iostream>
using namespace std;

template<class T>
class my_vector {
    int size;
    int capacity;
    T* arr;
    friend istream& operator >>(istream& input, const my_vector& s);
    friend ostream& operator<<(ostream& output, const my_vector& s);
public:
    my_vector() {
        size = -1;
        capacity = 1;
        arr = new T[capacity];
    }
    friend istream& operator>>(istream& input, my_vector& s) {
        int capt = 10;
        for (int i = 0; i < capt; i++) {
            input >> s.arr[i];
        }
        return input;
    }

    friend ostream& operator<<(ostream& output, const my_vector& s) {
        int capt = 10;
        for (int i = 0; i < capt; i++) {
            output << s.arr[i];
        }
        return output;
    }
    my_vector(my_vector& c) {
        for (int i = 0; i < size; i++) {
            arr[i] = c.arr[i];
        }
    }
    T total_cap(int s) {
        int i = 0, j = s, t = 0;
        for (int k = 0; k < capacity; k++) {
            if (arr[k] != 0) {
                i++;
            }
        }
        t = i + j;
        cout << "Total Size = " << t;
        cout << endl;
        return t;
    }
    void add(int val) {
        for (int i = 0; i < capacity; i++) {
            arr[i] = arr[i] + val;
            cout << arr[i] << "  ";
        }
    }
    void push_back(T val) {
        size += 1;
        if (capacity > size) {
            arr[size] = val;
        }
        else {
            T* temp;
            temp = new T[capacity * 2];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            temp[size] = val;
            arr = temp;
            capacity *= 2;
        }
    }
    T pop_back(void) {
        T temp = arr[size];
        arr[size] = NULL;
        if (size > capacity / 2) {
            size -= 1;
        }
        else if (size <= capacity / 2) {
            T* temp = new T[capacity / 2];
            for (int i = 0; i < capacity / 2; i++) {
                temp[i] = arr[i];
                size = i;
            }
            arr = temp;
            capacity /= 2;
        }
        return temp;
    }
    void display_list(void) {
        cout << "Elements present in list are:\n";
        for (int i = 0; i < capacity; i++)
            cout << arr[i] << "\t";
        cout << endl;
    }

    int& operator[](int s) {
        if (s > capacity) {
            cout << "Index out of bounds" << endl;
            return arr[0];
        }
        else {
            arr[s] = s;
            cout << arr[s];
            return arr[s];
        }
    }
    my_vector& operator = (my_vector& F) {
        for (int i = 0; i < capacity; i++) {
            arr[i] = F.arr[i];
        }
    }
    ~my_vector(){
        delete arr;
    }
};
int main() {
    my_vector<int> list;
    for (int i = 0; i < 8; i++) {
        list.push_back(i + 1);
        cout << endl;
        list.display_list();
        cout << endl;
    }
    for (int j = 0; j < 4; j++) {
        cout << endl;
        cout << "Pop up \t" << list.pop_back() << "\tfrom list" << endl;
        list.display_list();
        cout << endl;
    }
    int size = 5;
    int* s = new int[size];
    for (int i = 0; i < size; i++) {
        s[i] = i + 1;
    }
    list.total_cap(size);
    cout << endl << endl;
    int value;
    cout << "Please Give Value to Add = ";
    cin >> value;
    cout << "Array after adding " << value << " becomes " << endl;
    list.add(value);
    cout << endl << endl;
    cout << "[] Opertor Type Value : ";
    list[2];
    cout << endl << endl;
    list.display_list();
    cout << endl << endl;
    return 0;
}

