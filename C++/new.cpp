#include <bits/stdc++.h>

using namespace std;

enum gender {
    male, // these values are discarded in compiling -- just replaced with 0
    female
};

class Person {

public :
    int age;
    gender gen;

    void talk() {
        cout << "Hello! I am " << age << " years old ";
        if (gen == male) cout << "male" << endl;
        else cout << "female" << endl;
    }

    Person(int age, gender gen) { // constructor
        this->age = age;
        this->gen = gen;
    }

    ~Person() { // destructor
        if (gen == male) {
            cout << "Old soldiers never die, they simply fade away." << endl;
        }
        if (gen == female) {
            cout << "After all... tomorrow is another day." << endl;
        }

    }
};

int main() {

    Person *a = new Person(20, male);
    Person *b = new Person(18, female);

    a->talk();
    b->talk();

    delete b;
    delete a;

    return 0;
}
