#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {                 // virtual -> needed for dynamic_cast
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Dog barks" << endl;
    }
    void fetch() {
        cout << "Dog fetches the ball" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << "Cat meows" << endl;
    }
};

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    // ---------- 1. Implicit and C-style casting ----------
    cout << endl << "--- 1. Implicit and C-style Casting ---" << endl;
    float f = a;                           // implicit: compiler converts int to float
    cout << "Implicit : int " << a << " becomes float " << f << endl;

    float pi = 3.14;
    int i = (int)pi;                       // explicit C-style cast
    cout << "C-style  : (int)3.14 = " << i << endl;

    // ---------- 2. static_cast ----------
    cout << endl << "--- 2. static_cast ---" << endl;
    cout << "Without cast : " << a << " / " << b << " = " << a / b << endl;
    cout << "With cast    : " << a << " / " << b << " = "
         << static_cast<float>(a) / b << endl;

    // ---------- 3. const_cast ----------
    cout << endl << "--- 3. const_cast ---" << endl;
    int x = 10;
    const int *p = &x;                     // p cannot change the value
    int *q = const_cast<int*>(p);          // remove const
    *q = 20;
    cout << "x after const_cast = " << x << endl;

    // ---------- 4. dynamic_cast ----------
    cout << endl << "--- 4. dynamic_cast ---" << endl;
    Dog dog;
    Animal *ptr = &dog;                    // base pointer holds a Dog

    Dog *d = dynamic_cast<Dog*>(ptr);      // correct cast
    if (d != nullptr) {
        cout << "Cast to Dog successful: ";
        d->fetch();
    }

    Cat *c = dynamic_cast<Cat*>(ptr);      // wrong cast
    if (c == nullptr) {
        cout << "Cast to Cat failed (nullptr returned)" << endl;
    }

    // ---------- 5. reinterpret_cast ----------
    cout << endl << "--- 5. reinterpret_cast ---" << endl;
    int num = 65;
    char *ch = reinterpret_cast<char*>(&num);   // see the same memory as char
    cout << "First byte of 65 seen as char = " << *ch << endl;

    return 0;
}