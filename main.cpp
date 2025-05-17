#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

// Kuriame Debesijos serviso paslaugos
// Nuomojam HDD, RAM


class Componentai {
    public:
    virtual ~Componentai() = default;

    virtual double get_Kainą() = 0;
    virtual void get_Informaciją() = 0;
    virtual int get_Sumą() =  0;

    void push_back(Componentai * componentai);
};
class  Composite : public Componentai {
private:
    string name;
    vector<Componentai*> components;
public:
    Composite(string name) {
        this->name = name;
    }
    void add (Componentai* compomentai) {
        components.push_back(compomentai);
    }

    double get_Kainą() override {
        double total = 0.0;
        for (auto componentai : components) {
            total += componentai ->get_Kainą();
        }
        return total;
    }

    void get_Informaciją() override {
        cout << "-----------------------------" << name << "--------------------------" << endl;
        for (auto componentai : components) {
            componentai->get_Informaciją();
        }
        cout << "Suma už visas paslaugas: " << get_Kainą() << endl;
    }

    int get_Sumą() override {
        return 0;
    }
};

class Leaf : public Composite {
private:
    string Pavadinimas;
    double Kaina;
    int Suma;
public:
    Leaf(const string &pavadinimas, double kaina)
        : Pavadinimas(pavadinimas),
          Kaina(kaina) {

    }

    Leaf(const string &pavadinimas, double kaina, int suma)
        : Pavadinimas(pavadinimas),
          Kaina(kaina),
          Suma(suma) {
    }
    void get_Informaciją() override {
        cout << Pavadinimas << " " << Kaina << endl;
    }
    double get_Kainą() override {
        return Kaina;
    }
    int get_Sumą() override {
        return 0;
    }

};

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    SetConsoleOutputCP( 65001 );

    Composite root ("Servisas");

    Composite storage ("Paslaugos");
    Composite network ( "Tinklas");
    Composite security ( "Apsauga");
    Composite software( "Programinė įranga");
    Composite database ( "Duomenų bazė");


    storage.add(new Leaf ("HDD", 100));
    storage.add(new Leaf ("RAM", 200));
    storage.add(new Leaf ("SSD", 300));

    network.add(new Leaf ("Internetas", 400));
    network.add(new Leaf ("WiFi", 500));

    security.add(new Leaf ("Ugnesienė", 600));
    security.add(new Leaf ("Antivirusinė", 700));

    software.add(new Leaf ("Windows", 800));
    software.add(new Leaf ("Linux", 900));

    database.add(new Leaf ("MySQL", 1100));
    database.add(new Leaf ("PostgreSQL", 1200));
    database.add(new Leaf ("MongoDB", 1300));




    root.add(&storage);
    root.add(&network);
    root.add(&security);
    root.add(&software);
    root.add(&database);
/*
 // Žemiaus pasirenkame kokią informaciją norime pateikti!!!!
 // datebase.. root...
   root.get_Informaciją();
    cout << "Paskaičiuoti kainą duomenų bazės: "<< root.get_Kainą() << endl;
*/

int input = 1 ;
    while (input != 0) {

        cout << "0 Norint išeiti iš programos. " << endl;
        cout << "1 Pasirinkti ..... " << endl;
        cout << "2 sukurti naują kategoriją " << endl;

        cin >> input;

        if (input == 1) {
            root.get_Informaciją();
        }
        else if (input ==2) {
            cout << "Įvesti pavadinimo kategoriją: " << endl;
            string Pavadinimas_Kategorijos;
            cin >> Pavadinimas_Kategorijos;

            cout <<  "Įvesti kainą ir sumą: "<< endl;
            string Pavadinimas;
            double Kaina;
            int Suma;
            cin >> Pavadinimas >> Kaina >> Suma;

            root.add(new Leaf(Pavadinimas, Kaina, Suma));

        }
    }
1.24 minutes




    return 0;
}