#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class Zona {
private:
	string numeZona;
	int nrLocuri;
	int etaj;
	int nrFacilitati;
	string* facilitati;

public:
	Zona() {
		this->numeZona = "Necunoscut";
		this->nrLocuri = 0;
		this->etaj = 0;
		this->nrFacilitati = 0;
		this->facilitati = NULL;
	}

	Zona(string numeZona, int nrLocuri, int etaj, int nrFacilitati, string* facilitati) {
		this->numeZona = numeZona;
		this->nrLocuri = nrLocuri;
		this->etaj = etaj;
		this->nrFacilitati = nrFacilitati;
		this->facilitati = new string[this->nrFacilitati];
		for (int i = 0;i < this->nrFacilitati;i++) {
			this->facilitati[i] = facilitati[i];
		}
	}

	string getNumeZona() {
		return this->numeZona;
	}

	void setNumeZona(string numeZona) {
		if (numeZona != "")
		{
			this->numeZona = numeZona;
		}
		else {
			this->numeZona = "Necunoscut";
		}
	}

	int getNrLocuri() {
		return this->nrLocuri;
	}

	void setNrLocuri(int nrLocuri) {
		if (nrLocuri != 0) {
			this->nrLocuri = nrLocuri;
		}
		else {
			this->nrLocuri = 0;
		}
	}

	int getEtaj() {
		return this->etaj;
	}

	void setEtaj(int etaj) {
		if (etaj >= 0) {
			this->etaj = etaj;
		}
		else {
			this->etaj = -1;
		}
	}

	int getNrFacilitati() {
		return this->nrFacilitati;
	}

	string* getFacilitati() {
		return this->facilitati;
	}

	void setFacilitati(int nrFacilitati, string* facilitati) {
		if (nrFacilitati >= 0 && facilitati != NULL) {
			if (this->facilitati != NULL) {
				delete[]this->facilitati;
			}
			this->nrFacilitati = nrFacilitati;
			this->facilitati = new string[this->nrFacilitati];
			for (int i = 0;i < this->nrFacilitati;i++) {
				this->facilitati[i] = facilitati[i];
			}
		}
	}

	Zona(const Zona& z) {
		this->numeZona = z.numeZona;
		this->nrLocuri = z.nrLocuri;
		this->etaj = z.etaj;
		this->nrFacilitati = z.nrFacilitati;
		this->facilitati = new string[this->nrFacilitati];
		for (int i = 0;i < this->nrFacilitati;i++) {
			this->facilitati[i] = z.facilitati[i];
		}
	}

	~Zona() {
		if (this->facilitati != NULL)
		{
			delete[]this->facilitati;
		}
	}

	Zona& operator=(const Zona& z) {
		if (this != &z) {
			if (this->facilitati != NULL)
			{
				delete[]this->facilitati;
			}
			this->numeZona = z.numeZona;
			this->nrLocuri = z.nrLocuri;
			this->etaj = z.etaj;
			this->nrFacilitati = z.nrFacilitati;
			this->facilitati = new string[this->nrFacilitati];
			for (int i = 0;i < this->nrFacilitati;i++) {
				this->facilitati[i] = z.facilitati[i];
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Zona z) {
		out << "Nume zona: " << z.numeZona << endl;
		out << "Numar locuri: " << z.nrLocuri << endl;
		out << "Etaj: " << z.etaj << endl;
		out << "Nr facilitati: " << z.nrFacilitati << endl;
		out << "Facilitati: ";
		for (int i = 0;i < z.nrFacilitati;i++) {
			out << z.facilitati[i] << " | ";
		}
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Zona& z) {
		if (z.facilitati != NULL) {
			delete[]z.facilitati;
		}
		cout << "Nume zona: " << endl;
		in >> z.numeZona;
		cout << "Numar locuri: " << endl;
		in >> z.nrLocuri;
		cout << "Etaj: " << endl;
		in >> z.etaj;
		cout << "Nr facilitati: " << endl;
		in >> z.nrFacilitati;
		cout << "Facilitati: ";
		z.facilitati = new string[z.nrFacilitati];
		for (int i = 0;i < z.nrFacilitati;i++) {
			in >> ws;
			getline(in, z.facilitati[i]);
		}
		return in;
	}

	Zona& operator++() {
		this->etaj++;
		return *this;
	}

};

class Teatru {
	string denumire;
	string adresa;
	int nrZone;
	Zona* zone;

public:
	Teatru() {
		this->denumire = "Necunoscut";
		this->adresa = "Necunoscut";
		this->nrZone = 0;
		this->zone = NULL;
	}

	Teatru(string denumire, string adresa, int nrZone, Zona* zone) {
		this->denumire = denumire;
		this->adresa = adresa;
		this->nrZone = nrZone;
		this->zone = new Zona[this->nrZone];
		for (int i = 0;i < this->nrZone;i++) {
			this->zone[i] = zone[i];
		}
	}

	Teatru(const Teatru& t) {
		this->denumire = t.denumire;
		this->adresa = t.adresa;
		this->nrZone = t.nrZone;
		this->zone = new Zona[this->nrZone];
		for (int i = 0;i < this->nrZone;i++) {
			this->zone[i] = t.zone[i];
		}
	}

	~Teatru() {
		if (this->zone != NULL) {
			delete[]this->zone;
		}
	}

	Teatru& operator=(const Teatru& t) {
		if (this != &t) {
			if (this->zone != NULL) {
				delete[]this->zone;
			}
			this->denumire = t.denumire;
			this->adresa = t.adresa;
			this->nrZone = t.nrZone;
			this->zone = new Zona[this->nrZone];
			for (int i = 0;i < this->nrZone;i++) {
				this->zone[i] = t.zone[i];
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Teatru& t) {
		out << "Denumire: " << t.denumire << endl;
		out << "Adresa: " << t.adresa << endl;
		out << "Nr zone: " << t.nrZone << endl;
		out << "Zone: " << endl;
		out << "-----------------------------" << endl;
		for (int i = 0;i < t.nrZone;i++) {
			out << t.zone[i] << endl;
		}
		out << "-----------------------------" << endl;
		return out;
	}

	void adaugaZona(Zona z) {
		Teatru copie = *this;
		if (this->zone) {
			delete[]this->zone;
		}
		this->nrZone++;
		this->zone = new Zona[this->nrZone];
		for (int i = 0;i < copie.nrZone;i++) {
			this->zone[i] = copie.zone[i];
		}
		this->zone[this->nrZone - 1] = z;
	}

	virtual void afiseazaZone() {
		cout << "Zonele disponibile in teatrul " << denumire << " sunt:" << endl;
		for (int i = 0; i < nrZone; i++) {
			cout << "Zona " << zone[i].getNumeZona() << " are " << zone[i].getNrLocuri() << " locuri disponibile." << endl;
		}
	}
};