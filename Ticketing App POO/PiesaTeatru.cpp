#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class PiesaTeatru {
private:
	char* numePiesa;
	int nrActori;
	string* actori;
	string gen;
	char durata;

public:
	PiesaTeatru() {
		this->numePiesa = new char[strlen("Necunoscut") + 1];
		strcpy(this->numePiesa, "Necunoscut");
		this->nrActori = 0;
		this->actori = nullptr;
		this->gen = "Necunoscut";
		this->durata = NULL;
	}

	PiesaTeatru(const char* numePiesa, int nrActori, const string* actori, string gen, char durata) {
		this->numePiesa = new char[strlen(numePiesa) + 1];
		strcpy(this->numePiesa, numePiesa);
		this->nrActori = nrActori;
		this->actori = new string[this->nrActori];
		for (int i = 0;i < this->nrActori;i++) {
			this->actori[i] = actori[i];
		}
		this->gen = gen;
		this->durata = durata;
	}

	char* getNumePiesa() {
		return this->numePiesa;
	}

	void setNumePiesa(const char* numePiesa) {
		if (this->numePiesa != nullptr)
		{
			delete[]this->numePiesa;
			this->numePiesa = new char[strlen(numePiesa) + 1];
			strcpy(this->numePiesa, numePiesa);
		}
	}

	int getNrActori() {
		return this->nrActori;
	}

	string* getActori() {
		return this->actori;
	}

	void setActori(int nrActori, string* actori) {
		if (nrActori >= 0 && actori != NULL) {
			if (this->actori != NULL) {
				delete[]this->actori;
			}
			this->nrActori = nrActori;
			this->actori = new string[this->nrActori];
			for (int i = 0;i < this->nrActori;i++) {
				this->actori[i] = actori[i];
			}
		}
	}

	string getGen() {
		return this->gen;
	}

	void setGen(string gen) {
		if (gen != "")
		{
			this->gen = gen;
		}
		else {
			this->gen = "Necunoscut";
		}
	}

	char getDurata() {
		return this->durata;
	}

	void setDurata(char durata) {
		if (durata != NULL)
		{
			this->durata = durata;
		}
		else {
			this->durata = NULL;
		}
	}

	PiesaTeatru(const PiesaTeatru& p) {
		this->numePiesa = new char[strlen(p.numePiesa) + 1];
		strcpy(this->numePiesa, p.numePiesa);
		this->nrActori = p.nrActori;
		this->actori = new string[this->nrActori];
		for (int i = 0;i < this->nrActori;i++) {
			this->actori[i] = p.actori[i];
		}
		this->gen = p.gen;
		this->durata = p.durata;
	}

	~PiesaTeatru() {
		if (this->numePiesa != NULL)
		{
			delete[]this->numePiesa;
		}
		if (this->actori != NULL) {
			delete[]this->actori;
		}
	}

	PiesaTeatru& operator=(const PiesaTeatru& p) {
		if (this != &p) {
			if (this->numePiesa != NULL)
			{
				delete[]this->numePiesa;
			}
			if (this->actori != NULL) {
				delete[]this->actori;
			}
			this->numePiesa = new char[strlen(p.numePiesa) + 1];
			strcpy(this->numePiesa, p.numePiesa);
			this->nrActori = p.nrActori;
			this->actori = new string[this->nrActori];
			for (int i = 0;i < this->nrActori;i++) {
				this->actori[i] = p.actori[i];
			}
			this->gen = p.gen;
			this->durata = p.durata;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const PiesaTeatru p) {
		out << "Denumire piesa: " << p.numePiesa << endl;
		out << "Numar actori: " << p.nrActori << endl;
		out << "Actori: " << endl;
		for (int i = 0;i < p.nrActori;i++) {
			out << p.actori[i] << " | ";
		}
		out << endl;
		out << "Gen: " << p.gen << endl;
		out << "Durata: " << p.durata << " ore" << endl;
		return out;
	}

	friend istream& operator>>(istream& in, PiesaTeatru& p) {
		if (p.numePiesa != NULL)
		{
			delete[]p.numePiesa;
		}
		if (p.actori != NULL) {
			delete[]p.actori;
		}
		cout << "Denumire piesa: " << endl;
		in >> p.numePiesa;
		cout << "Numar actori: " << endl;
		in >> p.nrActori;
		cout << "Actori: ";
		p.actori = new string[p.nrActori];
		for (int i = 0;i < p.nrActori;i++) {
			in >> ws;
			getline(in, p.actori[i]);
		}
		cout << "Gen: " << endl;
		in >> p.gen;
		cout << "Durata: " << endl;
		in >> p.durata;
		return in;
	}

	explicit operator string()
	{
		return gen;
	}

	virtual void afiseazaActori() {
		cout << "Actorii din piesa " << numePiesa << " sunt:" << endl;
		for (int i = 0; i < nrActori; i++) {
			cout << actori[i] << endl;
		}
	}

};

template <typename obj>
void afisare(obj obiect) {
	cout << obiect << endl << endl;
}