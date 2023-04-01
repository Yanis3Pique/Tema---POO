#include <iostream>
#include <cstring>
using namespace std;

class Jucator {
private:
    char* name;
    char* position;
    int age;
    int salary;
public:

};

class Antrenor {
private:
    char* name;
    int experience;
    int age;
    int salary;
public:

};

class Stadion {
private:
    char* name;
    char* adress;
    int capacity;
public:
    explicit Stadion() {
        name = nullptr;
        adress = nullptr;
        capacity = 0;
    }

    explicit Stadion(const char* nume = "Town Park Stadium", const char* adresa = "8 Mile Road", int capacitate = 5000) : capacity(capacitate) {
        name = new char[strlen(nume) + 1];
        strcpy(name, nume);
        adress = new char[strlen(adresa) + 1];
        strcpy(adress, adresa);
    }

    Stadion(const Stadion& other){
        name = new char[strlen(other.name) + 1];
        strncpy(this->name, other.name, strlen(other.name));
        name[strlen(other.name) + 1] = '\0';

        adress = new char[strlen(other.adress) + 1];
        strncpy(this->adress, other.adress, strlen(other.adress));
        adress[strlen(other.adress) + 1] = '\0';

        this->capacity = other.capacity;
    }

    ~Stadion() {
        if(name != nullptr) delete[] name;
        if(adress != nullptr) delete[] adress;
    }

    Stadion& operator=(const Stadion& other) {

    }

    friend ostream& operator<<(ostream& out, const Stadion& stadion);
};
ostream& operator<<(ostream& out, const Stadion& stadion){
    out << "Numele stadionului: " << stadion.name << endl;
    out << "Adresa stadionului: " << stadion.adress << endl;
    out << "Capacitatea stadionului: " << stadion.capacity << endl;
    return out;
}

class Echipa {
private:
    char* nume;
    Antrenor antrenor;
    Stadion stadion;
    Jucator* lista_jucatori;
    int numar_jucatori;
public:

};