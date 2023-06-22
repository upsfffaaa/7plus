#include <iostream>
#include <memory>

using namespace std;

class PersonException : public exception {
public:
    PersonException(const string& message) : exception(message.c_str()) {}
};

class Person {
private:
    string name;
    int age;
    int id;

public:
    Person(const string& name, int age, int id) : name(name), age(age), id(id) {}

    void setName(const string& name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setId(int id) {
        this->id = id;
    }

    const string& getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    int getId() const {
        return id;
    }

    void validate() const {
        if (age <= 0 || id <= 0) {
            throw PersonException("Invalid person data.");
        }
    }
};

int main() {
    try {
        string name;
        int age = 0, id = 0;

        cout << "Enter person's name: ";
        getline(cin, name);

        cout << "Enter person's age: ";
        cin >> age;

        cout << "Enter person's ID: ";
        cin >> id;

        Person person(name, age, id);

        person.validate();

        cout << "Person information:" << endl;
        cout << "Name: " << person.getName() << endl;
        cout << "Age: " << person.getAge() << endl;
        cout << "ID: " << person.getId() << endl;
    }
    catch (const PersonException& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
