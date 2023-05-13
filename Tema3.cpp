//
// Created by Lenovo on 5/13/2023.
//



#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <iomanip>
#include <memory>
#include <numeric>
using namespace std;

class InvalidAgeException : public exception {
private:
    string message;
public:
    InvalidAgeException(int age) : message("Invalid age: " + to_string(age)) {}
    const char* what() const noexcept override {
        return message.c_str(); //conversie la string
    }
};
class InvalidNumberException : public exception {
private:
    string message;
public:
    InvalidNumberException(int number) : message("Invalid shirt number: " + to_string(number)) {}
    const char* what() const noexcept override {
        return message.c_str(); //conversie la string
    }
};

template<class T>
class Angajat {
protected:
    string name;
    int age;
    T salary;
public:
    Angajat(string nume, int varsta, T salariu) : name(nume), age(varsta), salary(salariu) {}
    virtual void prezinta() const = 0; // metoda pur virtuala
    virtual ~Angajat() = default;

    template <typename U>
    friend ostream& operator<<(ostream& out, const Angajat<U>& angajat);
};
template <typename T>
ostream& operator<<(ostream& out, const Angajat<T>& angajat) {
    out << "Numele: " << angajat.name << endl;
    out << "Varsta: " << angajat.age << " ani" << endl;
    out << "Salariul: " << angajat.salary << "$" << endl;
    return out;
}

template <class T>
class Antrenor : public Angajat<T> {
private:
    T number_of_titles;
public:
    Antrenor(string nume = "Gheorghe Hagi", int varsta = 60, T salariu = 10000, T numar_de_titluri = 0) :
            Angajat<T>(nume, varsta, salariu), number_of_titles(numar_de_titluri) {}
    void prezinta() const override;
    Antrenor(const Antrenor& other) : Angajat<T>(other), number_of_titles(other.number_of_titles) {}
    Antrenor& operator=(const Antrenor& other) {
        if (this != &other) {
            Angajat<T>::operator=(other);
            number_of_titles = other.number_of_titles;
        }
        return *this;
    }
    ~Antrenor() = default;
    const string& getName() const;
    int getAge() const;
    double getSalary() const;
    T getNumberOfTitles() const;
    void setName(const string& newName);
    void setAge(int newAge);
    void setSalary(T newSalary);
    void setNumberOfTitles(T newNumberOfTitles);
    void nivelulAntrenorului() const;

    friend ostream& operator<<(ostream& out, const Antrenor<T>& antrenor) {
        out << static_cast<const Angajat<T>&>(antrenor); // Chemam operatorul << al clasei de baza
        out << "Numar de titluri: " << antrenor.number_of_titles << endl;
        return out;
    }
};
template <class T>
const string& Antrenor<T>::getName() const { return this->name; }
template <class T>
int Antrenor<T>::getAge() const { return this->age; }
template <class T>
double Antrenor<T>::getSalary() const { return this->salary; }
template <class T>
T Antrenor<T>::getNumberOfTitles() const { return number_of_titles; }
template <class T>
void Antrenor<T>::setName(const string& newName) { this->name = newName; }
template <class T>
void Antrenor<T>::setAge(int newAge) { this->age = newAge; }
template <class T>
void Antrenor<T>::setSalary(T newSalary) { this->salary = newSalary; }
template <class T>
void Antrenor<T>::setNumberOfTitles(T newNumberOfTitles) { number_of_titles = newNumberOfTitles; }
template <class T>
void Antrenor<T>::prezinta() const {
    cout << "Sunt antrenorul " << getName() << endl;
}
template<typename T>
void Antrenor<T>::nivelulAntrenorului() const {
    cout << "Nivel necunoscut" << endl;
}
template<>
void Antrenor<int>::nivelulAntrenorului() const {
    if(number_of_titles >= 10) { cout << "Antrenor foarte bun" << endl; }
    else {
        if (number_of_titles >= 5) cout << "Antrenor mediu" << endl;
        else cout << "Antrenor mediocru" << endl;
    }
}

class Building { //Asta e interfata
public:
    virtual void descriere() const = 0;
    virtual void marimeCladire() const = 0;
    virtual ~Building() = default;
};

class Stadion : public Building {
private:
    string name;
    int capacity;
public:
    Stadion(string nume = "Stadionul Nicolae Dobrin", int capacitate = 10000) : name(nume), capacity(capacitate) {}
    Stadion(const Stadion& other) : name(other.name), capacity(other.capacity) {}
    virtual void descriere() const override {cout << "Stadionul " << name << " are o capacitate de " << capacity << " de locuri." << endl;}
    virtual void marimeCladire() const override { if(capacity > 80000) cout << "Stadion Foarte Mare";
        else{ if(capacity > 60000) cout << "Stadion Mare";
            else { if(capacity > 30000) cout << "Staidon Mediu";
                else cout << "Stadion Mic"; } } }
    ~Stadion() = default;
    friend ostream& operator<<(ostream& out, const Stadion& stadion);
    const string& getName() const;
    int getCapacity() const;
    void setName(const string& newName);
    void setCapacity(int newCapacity);
};
const string& Stadion::getName() const { return name; }
int Stadion::getCapacity() const { return capacity; }
void Stadion::setName(const string &newName) { name = newName; }
void Stadion::setCapacity(int newCapacity) { capacity = newCapacity; }
ostream& operator<<(ostream& out, const Stadion& stadion){
    out << "Numele stadionului: " << stadion.name << endl;
    out << "Capacitatea stadionului: " << stadion.capacity << " de locuri" << endl;
    return out;
}

class Contract {
protected:
    long value;
    virtual long getValue() const { return value; }
public:
    Contract(long value) : value(value) {}
    Contract(const Contract& other) : value(other.value) {}
    virtual ~Contract() = default;
};

class Echipa {
private:
    static list<Echipa> created_teams;
    string name;
    std::unique_ptr<Antrenor<int>> coach;
    Stadion stadium;
public:
    Echipa(const string& name = "FC Arges", const Antrenor<int>& coach = Antrenor<int>(), const Stadion& stadium = Stadion())
            : name(name), coach(make_unique<Antrenor<int>>(coach)), stadium(stadium) {
        created_teams.push_back(*this);
    }

    Echipa(const Echipa& other) : name(other.name), coach(make_unique<Antrenor<int>>(*(other.coach))), stadium(other.stadium) {}
    ~Echipa() {}
    string getName() const;
    Antrenor<int> getCoach() const;
    Stadion getStadium() const;
    void setName(const string& name) { this->name = name; }
    void setStadium(const Stadion& stadium) { this->stadium = stadium; }
    static Echipa* getTeamByName(const string& name);
    friend ostream& operator<<(ostream& out, const Echipa& echipa);
    bool hasName(const string& teamName) const {
        return name == teamName;
    }
};
list<Echipa> Echipa::created_teams;
string Echipa::getName() const { return name; }
Antrenor<int> Echipa::getCoach() const { return *coach; }
Stadion Echipa::getStadium() const { return stadium; }
Echipa* Echipa::getTeamByName(const string& name) {
    auto it = find_if(created_teams.begin(), created_teams.end(), [&](const Echipa& team) {
        return team.getName() == name;
    });
    if (it != created_teams.end()) {
        return &(*it);
    }
    return nullptr;
}
ostream& operator<<(ostream& out, const Echipa& echipa) {
    out << "Echipa: " << endl << echipa.name << endl << endl;
    out << "Antrenor: " << endl << echipa.getCoach() << endl;
    out << "Stadion:" << endl << echipa.stadium << endl;
    return out;
}

class Jucator : public Angajat<double>, private Contract {
private:
    static list<Jucator*> jucatori;
    static int contor;
    const int id;
    int shirt_number;
    double durata_contract;
    std::unique_ptr<Echipa> echipa; // Smart pointer catre un obiect de tip Echipa
public:
    Jucator(string nume = "Andrei Prepelita", int varsta = 25, int salariu = 10000, std::unique_ptr<Echipa> echipa = nullptr,
            int numar_tricou = 1, double durataContract = 4, long value = 300000) :
            id(contor++), Contract(value), Angajat(nume, varsta, salariu), shirt_number(numar_tricou), durata_contract(durataContract) {
        if (echipa == nullptr) {
            // Seteaza echipa default daca nu se da nicio valoare in constructor
            this->echipa = std::make_unique<Echipa>();
        } else {
            this->echipa = std::move(echipa);
        }
    }
    void prezinta() const override;
    Jucator(const Jucator& other) : Angajat(other), Contract(other), shirt_number(other.shirt_number), durata_contract(other.durata_contract),
                                    id(other.id), echipa(other.echipa ? std::make_unique<Echipa>(*other.echipa) : nullptr) { }
    Jucator& operator=(const Jucator& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
            salary = other.salary;
            shirt_number = other.shirt_number;
            durata_contract = other.durata_contract;
            value = other.value;
            echipa = other.echipa ? std::make_unique<Echipa>(*other.echipa) : nullptr;
        }
        return *this;
    }
    ~Jucator() { jucatori.remove(this); }
    bool operator==(const Jucator& other) const {
        return name == other.name && age == other.age && salary == other.salary;
    }
    friend istream& operator>>(istream& in, Jucator& jucator);
    friend ostream& operator<<(ostream& out, const Jucator& jucator);
    const string& getName() const;
    const int getID() const;
    int getAge() const;
    int getSalary() const;
    int getShirtNumber() const;
    double getContractDuration() const;
    long getValue() const override;
    void setName(const string& newName);
    void setAge(int newAge);
    void setSalary(int newSalary);
    void setShirNumber(int newShirtNumber);
    void setContractDuration(double newContractDuration);
    static list<Jucator*>& getJucatori();
    static void addJucator(Jucator* jucator) { jucatori.push_back(jucator); }
    static int numJucatori() { return jucatori.size(); }
    static int nextId() { return contor; }
    std::unique_ptr<Echipa> getEchipa() const { return std::make_unique<Echipa>(*echipa); }
    void setEchipa(std::unique_ptr<Echipa> newEchipa) { echipa = std::move(newEchipa); } // Setter pentru obiect de tip Echipa
    static double calculatePlayersSalary(const Echipa& xteam) {
        double total_salary = accumulate(jucatori.begin(), jucatori.end(), 0.0, [&](double sum, Jucator* player) {
            if (player->getEchipa()->hasName(xteam.getName())) {
                return sum + player->getSalary();
            }
            return sum;
        });
        int number_of_players = count_if(jucatori.begin(), jucatori.end(), [&](Jucator* player) {
            return player->getEchipa()->hasName(xteam.getName());
        });
        return total_salary / number_of_players;
    }
    static long calculateSquadValue(const Echipa& xteam) {
        long total_value = 0;
        for (const auto& player : jucatori) {
            if (player->getEchipa()->hasName(xteam.getName())) {
                total_value += player->value;
            }
        }
        return total_value;
    }
    static double calculateAverageAge(const Echipa& xteam) {
        int num_players = 0;
        int total_age = 0;
        for (const auto& player : jucatori) {
            if (player->getEchipa()->hasName(xteam.getName())) {
                total_age += player->getAge();
                num_players++;
            }
        }
        if (num_players == 0) {
            return 0;
        }
        return static_cast<double>(total_age) / num_players;
    }
protected:
    bool isExpirat() const;
};
int Jucator::contor = 0;
list<Jucator*> Jucator::jucatori = list<Jucator*>();
istream& operator>>(istream& in, Jucator& jucator) {
    cout << "Introdu numele jucatorului:";
    in.ignore();
    getline(in, jucator.name);
    int age;
    cout << "Introdu varsta jucatorului:";
    in >> age;
    if (age < 0 || age > 50) {
        throw InvalidAgeException(age);
    }
    jucator.age = age;
    int salary;
    cout << "Introdu salariul jucatorului:";
    in >> salary;
    if (salary < 0) {
        throw runtime_error("Salariu negativ!");
    }
    jucator.salary = salary;
    int shirt_number;
    cout << "Introdu numarul jucatorului:";
    in >> shirt_number;
    if (shirt_number < 0 || shirt_number > 99) {
        throw InvalidNumberException(shirt_number);
    }
    jucator.shirt_number = shirt_number;
    cout << "Introdu valoarea jucatorului:";
    in >> jucator.value;
    cout << "Introdu durata in ani a contractului jucatorului:";
    in >> jucator.durata_contract;
    jucator.setContractDuration(jucator.durata_contract);

    string team_name;
    cout << "Introdu numele echipei jucatorului:";
    in.ignore();
    getline(in, team_name);
    Echipa* team_ptr = Echipa::getTeamByName(team_name);
    if (team_ptr == nullptr) {
        throw runtime_error("Echipa nu exista!");
    }
    jucator.setEchipa(std::make_unique<Echipa>(*team_ptr));
    return in;
}
ostream& operator<<(ostream& out, const Jucator& jucator) {
    out << "ID: " << jucator.id << endl;
    out << "Echipa: " << jucator.getEchipa()->getName() << endl;
    out << "Numele: " << jucator.name << endl;
    out << "Varsta: " << jucator.age << " ani" << endl;
    out << "Salariul: " << jucator.salary << "$" << endl;
    out << "Numarul: " << jucator.shirt_number << endl;
    out << "Durata contractului: " << jucator.durata_contract << " ani" << endl;
    out << "Valoare de piata: " << jucator.value << "$" << endl;
    return out;
}
const string& Jucator::getName() const { return name; }
const int Jucator::getID() const { return id; }
int Jucator::getAge() const { return age; }
int Jucator::getSalary() const { return salary; }
int Jucator::getShirtNumber() const { return shirt_number; }
double Jucator::getContractDuration() const { return durata_contract; }
long Jucator::getValue() const {
    if(isExpirat()) {
        return this->value / 2;
    }
    else return this->value;
}
void Jucator::setName(const string& newName) { name = newName; }
void Jucator::setAge(int newAge) {
    if (newAge < 0 || newAge > 120) {
        throw InvalidAgeException(newAge);
    }
    age = newAge;
}
void Jucator::setSalary(int newSalary) {
    if (newSalary < 0) {
        throw runtime_error("Salariu negativ!");
    }
    salary = newSalary;
}
void Jucator::setShirNumber(int newShirtNumber) {
    if (newShirtNumber < 0 || newShirtNumber > 99) {
        throw InvalidNumberException(newShirtNumber);
    }
    shirt_number = newShirtNumber;
}
void Jucator::setContractDuration (double newContractDuration) {
    this->durata_contract = newContractDuration;
    this->value = getValue();
}
void Jucator::prezinta() const { cout << "Jucatorul " << name << endl; }
list<Jucator*>& Jucator::getJucatori() { return jucatori; }
bool Jucator::isExpirat() const { return this->durata_contract <= 0.5; }

class Meci {
private:
    Echipa echipaGazda;
    Echipa echipaOaspete;
    Stadion stadion;
    int nrSpectatori;
    int scorGazda;
    int scorOaspete;
public:
    Meci(Echipa echipaGazda = Echipa(),
         Echipa echipaOaspete = Echipa("FCSB", Antrenor("Nicolae Dica", 44, 15000, 3),
                                       Stadion("Arena Nationala", 50000)),
         Stadion stadion = Stadion(), int nrSpectatori = 0, int scorGazda = 0, int scorOaspete = 0)
            : echipaGazda(echipaGazda), echipaOaspete(echipaOaspete), stadion(stadion), nrSpectatori(nrSpectatori), scorGazda(scorGazda), scorOaspete(scorOaspete) {}
    const Echipa& getEchipaGazda() const;
    const Echipa& getEchipaOaspete() const;
    const Stadion& getStadion() const;
    int getNrSpectatori() const;
    int getScorGazda() const;
    int getScorOaspete() const;
    void setNrSpectatori(int newNrSpectatori);
    void setScorGazda(int newScor);
    void setScorOaspete(int newScor);
    friend ostream& operator<<(ostream& out, const Meci& meci);
    void joacaMeci() const;
};
const Echipa& Meci::getEchipaGazda() const { return echipaGazda; }
const Echipa& Meci::getEchipaOaspete() const { return echipaOaspete; }
const Stadion& Meci::getStadion() const { return stadion; }
int Meci::getNrSpectatori() const { return nrSpectatori; }
int Meci::getScorGazda() const { return scorGazda; }
int Meci::getScorOaspete() const { return scorOaspete; }
void Meci::setNrSpectatori(const int newNrSpectatori) { nrSpectatori = newNrSpectatori; }
void Meci::setScorGazda(const int newScor) { scorGazda = newScor; }
void Meci::setScorOaspete(const int newScor) { scorOaspete = newScor; }
void Meci::joacaMeci() const {
    cout << "Meci: " << echipaGazda.getName() << " - " << echipaOaspete.getName() << endl;
    cout << "Numar de spectatori: " << nrSpectatori << " din " << stadion.getCapacity() << " de locuri" << endl;
    cout << "Jucat pe stadionul " << stadion.getName() << endl;
}
ostream& operator<<(ostream& out, const Meci& meci) {
    out << "Meciul s-a incheiat cu scorul " << meci.echipaGazda.getName() << " " << meci.scorGazda << " - " << meci.scorOaspete << " " << meci.echipaOaspete.getName() << "." << endl;
    return out;
}

int main() {
    cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
    Jucator jucator2;
    jucator2.setName("Lionel Messi");
    jucator2.setAge(35);
    jucator2.setSalary(110000);
    jucator2.setShirNumber(10);
    jucator2.setContractDuration(5);
    cout << jucator2.getID() << endl;
    cout << jucator2.getName() << endl;
    cout << jucator2.getAge() << endl;
    cout << jucator2.getSalary() << endl;
    cout << jucator2.getShirtNumber() << endl;
    cout << jucator2.getContractDuration() << endl;

    cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
    Antrenor antrenor("Gica Popescu", 45, 5000, 3);
    antrenor.nivelulAntrenorului();

    Antrenor<int> antrenor1;
    cout << antrenor1.getName() << endl;
    cout << antrenor1.getAge() << endl;
    cout << antrenor1.getSalary() << endl;
    cout << antrenor1.getNumberOfTitles() << endl << endl;

    Antrenor<double> antrenor2("Jose Mourinho", 59, 15000.75, 28);
    cout << antrenor2.getName() << endl;
    cout << antrenor2.getAge() << endl;
    cout << antrenor2.getSalary() << endl;
    cout << antrenor2.getNumberOfTitles() << endl << endl;

    antrenor1.setName("Pep Guardiola");
    cout << antrenor1.getName() << endl;
    antrenor1.setAge(50);
    cout << antrenor1.getAge() << endl;
    antrenor1.setSalary(20000);
    cout << antrenor1.getSalary() << endl;
    antrenor1.setNumberOfTitles(20);
    cout << antrenor1.getNumberOfTitles() << endl;
    cout << "Prezentare antrenor 1: ";
    antrenor1.prezinta();

    cout << endl << antrenor2;

    cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
    Echipa gazda("Steaua", Antrenor("Gigi Becali", 60, 5000, 5), Stadion("Ghencea", 40000));
    Echipa oaspete("Dinamo", Antrenor("Mircea Rednic", 58, 8000, 4), Stadion("Dinamo", 35000));
    Meci meci(gazda, oaspete, Stadion("National", 55000), 25000);

    cout << meci.getEchipaGazda().getName() << endl;
    cout << meci.getEchipaOaspete().getName() << endl;
    cout << meci.getStadion().getName() << endl;
    cout << meci.getNrSpectatori() << endl;
    cout << meci.getScorGazda() << endl;
    cout << meci.getScorOaspete() << endl;

    meci.setNrSpectatori(30000);
    cout << meci.getNrSpectatori() << endl;

    meci.setScorGazda(2);
    meci.setScorOaspete(1);
    cout << meci.getScorGazda() << endl;
    cout << meci.getScorOaspete() << endl;

    meci.joacaMeci();
    cout << meci;

    cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
    Stadion s1("Stadionul National", 50000);
    cout << s1.getName() << endl;
    cout << s1.getCapacity() << endl << endl;
    s1.setCapacity(75000);
    cout << s1.getCapacity() << endl << endl;
    Stadion s2(s1);
    cout << s2.getName() << endl;
    cout << s2.getCapacity() << endl << endl;

    s1.setName("San Siro");
    s1.descriere();
    s1.marimeCladire();
    cout << endl;

    Antrenor<int> antrenor3("Ionut Popa", 50);
    Echipa e1("FC Arges", antrenor1, s1);
    cout << e1.getName() << endl;
    cout << e1.getCoach().getName() << endl;
    cout << e1.getStadium().getName() << endl << endl;

    e1.setStadium(s2);
    cout << e1.getStadium().getName() << endl;
    cout << e1.getStadium().getCapacity() << endl << endl;

    Echipa e2(e1);
    cout << e2.getName() << endl;
    cout << e2.getCoach().getName() << endl;
    cout << e2.getStadium().getName() << endl;
    cout << e2.getStadium().getCapacity() << endl;

    cout << s1 << endl;

    cout << e1 << endl;

    antrenor1.nivelulAntrenorului();
    antrenor2.nivelulAntrenorului();
    antrenor3.nivelulAntrenorului();
    cout << endl;

    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    Echipa team("Barcelona"), echipa11, echipa22("FC Barcelona", antrenor1, s1), echipa33("San Lorenzo", antrenor3, s2);

    int optiune_jucator;
    do {
        cout << "1. Introdu un jucator" << endl;
        cout << "2. Afiseaza toti jucatorii" << endl;
        cout << "3. Afiseaza un jucator dupa id" << endl;
        cout << "4. Actualizeaza jucatorul dupa id" << endl;
        cout << "5. Sterge un jucator dupa id" << endl;
        cout << "6. Calculeaza valoarea totala a jucatorilor dintr-o echipa" << endl;
        cout << "7. Calculeaza varsta medie a jucatorilor dintr-o echipa" << endl;
        cout << "8. Calculeaza salariul mediu al jucatorilor dintr-o echipa" << endl;
        cout << "Daca vrei sa iesi apasa 0" << endl;

        cin >> optiune_jucator;
        switch (optiune_jucator) {
            case 0:
                break;
            case 1:{
                try {
                    Jucator jucatorNou;
                    cin >> jucatorNou;
                    Jucator::addJucator(new Jucator(jucatorNou));
                    jucatorNou.prezinta();
                    cout << "Urmatorul ID disponibil este " << jucatorNou.nextId() << endl << endl;
                } catch (const InvalidAgeException& error) {
                    cerr << "Exceptie custom prinsa: " << error.what() << endl;
                } catch (const InvalidNumberException& error) {
                    cerr << "Exceptie custom prinsa: " << error.what() << endl;
                } catch (const runtime_error& e) {
                    cerr << "Caught runtime_error: " << e.what() << endl;
                    throw logic_error("A logic error occurred.");
                } catch (...) {
                    cerr << "O exceptie neasteptata a fost aruncata." << endl;
                }
                break;
            }
            case 2:{
                if (Jucator::numJucatori() == 0) {
                    cout << "Nu am niciun jucator in lista" << endl;
                }
                for (auto jucator : Jucator::getJucatori()) {
                    cout << *jucator << endl;
                }
                break;
            }
            case 3:{
                int idCautat;
                cout << "Introdu id-ul jucatorului pe care vrei sa il cauti:";
                cin >> idCautat;
                if (Jucator::getJucatori().empty()) {
                    cout << "Nu exista jucatori" << endl;
                    break;
                }
                Jucator *current = NULL;
                for (auto jucator : Jucator::getJucatori()) {
                    if (jucator->getID() == idCautat) {
                        current = jucator;
                        break;
                    }
                }
                auto jucatorGasit = find_if(Jucator::getJucatori().begin(), Jucator::getJucatori().end(), [idCautat](Jucator *jucator)->bool {
                    return jucator->getID() == idCautat;
                });
                if(jucatorGasit == Jucator::getJucatori().end()) cout << "Nu exista jucator cu ID-ul cerut." << endl;
                else {
                    /// Dereferentiere din Iterator in tipul din lista (Jucator*)
                    Jucator *jucatorGasitPointer = *jucatorGasit;
                    /// Dereferentiere dintre Jucator* -> Jucator
                    cout << *jucatorGasitPointer << endl;
                }
                break;
            }
            case 4:{
                int idCautat;
                cout << "Introdu id-ul jucatorului pe care vrei sa il cauti:";
                cin >> idCautat;
                Jucator *jucatorCitit = new Jucator();
                cin >> *jucatorCitit;
                if(Jucator::getJucatori().empty()) {
                    cout << "Nu exista jucatori." << endl;
                    break;
                }
                for(auto& jucator : Jucator::getJucatori()) {
                    if(jucator->getID() == idCautat) {
                        *jucator = *jucatorCitit;
                        break;
                    }
                }
                cout << "Jucatorul cu ID-ul " << idCautat << " a fost actualizat" << endl;
                delete jucatorCitit;
                break;
            }
            case 5:{
                int idCautat;
                cout << "Introdu id-ul jucatorului pe care vrei sa il stergi:";
                cin >> idCautat;
                if(Jucator::getJucatori().empty()) {
                    cout << "Nu exista jucatori in lista." << endl;
                    break;
                }
                int sizeCurrent = Jucator::numJucatori();
                Jucator::getJucatori().remove_if([idCautat](Jucator *jucator)->bool {
                    return jucator->getID() == idCautat;
                });
                int sizeDupaStergere = Jucator::numJucatori();
                if(sizeCurrent != sizeDupaStergere) cout << "Jucatorul cu ID-ul " << idCautat << " a fost sters" << endl;
                break;
            }
            case 6: {
                string echipaCautata;
                cout << "Dati numele echipei cautate: ";
                cin >> echipaCautata;
                Echipa* team_ptr = Echipa::getTeamByName(echipaCautata);
                if (team_ptr == nullptr) {
                    cout << "Echipa nu exista!";
                } else {
                    cout << "Squad value: " << Jucator::calculateSquadValue(*team_ptr) << "$" << endl;
                }
                break;
            }
            case 7: {
                string echipaCautata;
                cout << "Dati numele echipei cautate: ";
                cin >> echipaCautata;
                Echipa* team_ptr = Echipa::getTeamByName(echipaCautata);
                if (team_ptr == nullptr) {
                    cout << "Echipa nu exista!";
                } else {
                    cout << "Average age: " << Jucator::calculateAverageAge(*team_ptr) << " ani" << endl;
                }
                break;
            }
            case 8: {
                string echipaCautata;
                cout << "Dati numele echipei cautate: ";
                cin >> echipaCautata;
                Echipa* team_ptr = Echipa::getTeamByName(echipaCautata);
                if (team_ptr == nullptr) {
                    cout << "Echipa nu exista!";
                } else {
                    cout << "Players medium salary: " << fixed << setprecision(2) << Jucator::calculatePlayersSalary(*team_ptr) << "$" << endl;
                }
                break;
            }
            default:
                cout << "Alegere incorecta. Incearca din nou." << endl;
        }
    } while(optiune_jucator != 0);
}
