class PersonException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Ошибка: некорректные данные о человеке!";
    }
};

class Person {
private:
    std::string name;
    int age;
    int id;
public:
    Person(const std::string& name, int age, int id) : name(name), age(age), id(id) {
        if (name.empty()  age <= 0  id < 0) {
            throw PersonException();
        }
    }
    void printInfo() const {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Возраст: " << age << std::endl;
        std::cout << "Идентификатор: " << id << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    setlocale(LC_ALL, "Russian");
    try {
        std::string name;
        int age, id;

        std::cout << "Введите имя: ";
        std::cin >> name;
        std::cout << "Введите возраст: ";
        std::cin >> age;
        std::cout << "Введите идентификатор: ";
        std::cin >> id;

        std::unique_ptr<Person> person(new Person(name, age, id));
        person->printInfo();
    }
    catch (PersonException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
    }

    return 0;
}
