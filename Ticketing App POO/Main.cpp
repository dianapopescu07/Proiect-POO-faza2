#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "Bilet.cpp"
#include "PiesaTeatru.cpp"
#include "Zona.cpp"
using namespace std;

int afiseazaMeniu() {
    int choice;
    cout << "1. Vizualizaza biletele disponibile" << endl;
    cout << "2. Cumpara bilete" << endl;
    cout << "3. Iesire" << endl;
    cin >> choice;
    return choice;
}

int main() {
    
    /*
    cout << "--------------CLASA BILET--------------" << endl;
    Bilet b;

	cout << "Testare constructori, getter si setter:" << endl;
	//Testare constructori, getter si setter
	cout << b.getNrPersoane() << endl;
	for (int i = 0;i < b.getNrPersoane(); i++) {
		cout << b.getLocuri()[i] << " | ";
	}
	cout << endl;

    char locuri[] = { 22, 23, 24 };
    Bilet b1("Hamlet", "20.02.2023 17:30", "Standard", 3, locuri, 150);
    for (int i = 0;i < b1.getNrPersoane(); i++) {
        cout << b1.getLocuri()[i] << " | ";
    }
    cout << endl << endl;

    cout << b1.getNumePiesa() << endl << b1.getDataOra() << endl << endl;

    //Testare operator = si operator <<
    cout << "Testare operator = si operator <<" << endl;
    Bilet b2 = b1;
    cout << b2;
    cout << endl;

    //Testare operator ==
    cout << "Operatorul ==:" << endl;
    cout << (b1 == b2) << endl;
    if (b2 == b1) {
        cout << "Obiectele sunt identice!" << endl;
    }
    else {
        cout << "Obiectele nu sunt identice!" << endl;
    }
    cout << endl;*/

    /*
    cout << "--------------CLASA PIESA TEATRU--------------" << endl;
    PiesaTeatru p;

    cout << "Testare constructori, getter si setter:" << endl;
    //Testare constructori, getter si setter
    cout <<p.getNrActori() << endl;
    for (int i = 0;i < p.getNrActori(); i++) {
        cout << p.getActori()[i] << " | ";
    }
    cout << endl;

    string actori[] = { "Mara", "Ion", "George"};
    PiesaTeatru p1("Hamlet", 3, actori, "drama", 1);
    for (int i = 0;i < p1.getNrActori(); i++) {
        cout << p1.getActori()[i] << " | ";
    }
    cout << endl << endl;

    cout << p1.getNumePiesa() << endl << p1.getGen() << endl << endl;

    //Testare operator = si operator <<
    cout << "Testare operator = si operator <<" << endl;
    PiesaTeatru p2 = p1;
    cout << p2;
    cout << endl;
    
    //Testare STL
    cout << "Testare STL" << endl;
    afisare(p2);*/

    vector<Bilet> bilete;
    Bilet bilet;
    bilet.deserialize();
    int optiune;
    do {
        afiseazaMeniu();
        cin >> optiune;
        switch (optiune) {
        case 1:
            bilet.cumparaBilet();
            break;
        case 2:
            bilet.vizualizeazaBileteDisp();
            break;
        case 3:
            bilet.serialize();
            break;
        case 4:
            break;
        default:
            cout << "Optiune invalida. Incearca din nou." << endl;
            break;
        }
    } while (optiune != 4);
}

int Bilet::contor = 1;