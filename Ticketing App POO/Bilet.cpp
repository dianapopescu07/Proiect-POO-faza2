#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "Reducere.cpp"
using namespace std;
//Gestionarea biletelor unui teatru

class Bilet : public Reducere {
private:
	const int idBilet;
	string numePiesa;
	string data_ora;
	string zona;
	int nrPersoane;
	char* locuri;
	float pret;

	static int contor;
public:
	vector<Bilet> bilete;

	Bilet() : idBilet(contor++) {
		bilete = vector<Bilet>();
		this->numePiesa = "Necunoscut";
		this->data_ora = "Necunoscut";
		this->zona = "Necunoscut";
		this->nrPersoane = 0;
		this->locuri = nullptr;
		this->pret = 0;
	}

	Bilet(string numePiesa, string data_ora, string zona, int nrPersoane, const char* locuri, float pret) :idBilet(contor++) {
		this->numePiesa = numePiesa;
		this->data_ora = data_ora;
		this->zona = zona;
		this->nrPersoane = nrPersoane;
		this->locuri = new char[this->nrPersoane];
		for (int i = 0;i < this->nrPersoane;i++) {
			this->locuri[i] = locuri[i];
		}
		this->pret = pret;
	}

	Bilet(string numePiesa, string data_ora, string zona, int nrPersoane) :idBilet(contor++) {
		this->numePiesa = numePiesa;
		this->data_ora = data_ora;
		this->zona = zona;
		this->nrPersoane = nrPersoane;
	}


	string getNumePiesa() {
		return this->numePiesa;
	}

	void setNumePiesa(string numePiesa) {
		if (numePiesa != "")
		{
			this->numePiesa = numePiesa;
		}
		else {
			this->numePiesa = "Necunoscut";
		}
	}

	string getDataOra() {
		return this->data_ora;
	}

	void setDataOra(string data_ora) {
		if (data_ora != "")
		{
			this->data_ora = data_ora;
		}
		else {
			this->data_ora = "Necunoscut";
		}
	}

	string getZona() {
		return this->zona;
	}

	void setZona(string zona) {
		if (zona != "")
		{
			this->zona = zona;
		}
		else {
			this->zona = "Necunoscut";
		}
	}

	int getNrPersoane() {
		return this->nrPersoane;
	}

	char* getLocuri() {
		return this->locuri;
	}

	void setNrLocuri(int nrPersoane, char* locuri) {
		if (nrPersoane >= 0 && locuri != NULL) {
			if (this->locuri != NULL) {
				delete[]this->locuri;
			}
			this->nrPersoane = nrPersoane;
			this->locuri = new char[this->nrPersoane];
			for (int i = 0;i < this->nrPersoane;i++) {
				this->locuri[i] = locuri[i];
			}
		}
	}

	float getPret() {
		return this->pret;
	}

	void setPret(float pret) {
		if (pret > 0)
		{
			this->pret = pret;
		}
		else {
			this->pret = 0;
		}
	}

	Bilet(const Bilet& b) :idBilet(b.idBilet) {
		this->numePiesa = b.numePiesa;
		this->data_ora = b.data_ora;
		this->zona = b.zona;
		this->nrPersoane = b.nrPersoane;
		this->locuri = new char[this->nrPersoane];
		for (int i = 0;i < this->nrPersoane;i++) {
			this->locuri[i] = b.locuri[i];
		}
		this->pret = b.pret;
	}

	~Bilet() {
		if (this->locuri != NULL)
		{
			delete[]this->locuri;
		}
	}

	Bilet& operator=(const Bilet& b) {
		if (this != &b) {
			if (this->locuri != NULL)
			{
				delete[]this->locuri;
			}
			this->numePiesa = b.numePiesa;
			this->data_ora = b.data_ora;
			this->zona = b.zona;
			this->nrPersoane = b.nrPersoane;
			this->locuri = new char[this->nrPersoane];
			for (int i = 0;i < this->nrPersoane;i++) {
				this->locuri[i] = b.locuri[i];
			}
			this->pret = b.pret;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Bilet b) {
		out << "Id bilet: " << b.idBilet << endl;
		out << "Piesa: " << b.numePiesa << endl;
		out << "Data si ora: " << b.data_ora << endl;
		out << "Zona: " << b.zona << endl;
		out << "Nr persoane: " << b.nrPersoane << endl;
		out << "Locuri: ";
		for (int i = 0;i < b.nrPersoane;i++) {
			out << b.locuri[i] << " | ";
		}
		out << endl;
		out << "Pret: " << b.pret << " lei" << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Bilet& b) {
		if (b.locuri != NULL)
		{
			delete[]b.locuri;
		}
		cout << "Nume piesa: ";
		in >> b.numePiesa;
		cout << "Data si ora: ";
		in >> b.data_ora;
		cout << "Zona: ";
		in >> b.zona;
		cout << "Numar persoane: ";
		in >> b.nrPersoane;
		cout << "Locuri: ";
		b.locuri = new char[b.nrPersoane];
		char aux[100];
		for (int i = 0;i < b.nrPersoane;i++) {
			in >> ws;
			in >> aux;
			in.getline(aux, 99);
			b.locuri = new char[strlen(aux) + 1];
			strcpy(b.locuri, aux);
		}
		cout << "Pret: ";
		in >> b.pret;
		return in;
	}

	/*Bilet operator+(Bilet b)
	{
		Bilet copie = *this;
		copie.pret = copie.pret + b.pret;

		return copie;
	}*/

	bool operator==(Bilet b) {
		return (this->idBilet == b.idBilet && this->numePiesa == b.numePiesa && this->data_ora == b.data_ora && this->zona == b.zona &&
			this->nrPersoane == b.nrPersoane && strcmp(this->locuri, b.locuri) && this->pret == b.pret);
	}

	void cumparaBilet() {
		string numePiesa;
		string data_ora;
		string zona;
		int nrPersoane;

		cout << "Introduceti numele piesei:" << endl;
		cin >> numePiesa;
		cout << "Introduceti data si ora:" << endl;
		cin >> data_ora;
		cout << "Introduceti zona:" << endl;
		cin >> zona;
		cout << "Introduceti numarul de persoane:" << endl;
		cin >> nrPersoane;

		Bilet biletNou(numePiesa, data_ora, zona, nrPersoane);
		bilete.push_back(biletNou);
		cout << "Bilet cumparat cu succes!" << endl;
	}

	float realizeazaReducere() override
	{
		return 50;
	}

	void serialize()
	{
		ofstream f("bilet.txt", ios::binary);
		short dim = this->numePiesa.length();
		f.write((char*)&idBilet, sizeof(idBilet));
		f.write((char*)&dim, sizeof(dim));
		f.write(numePiesa.c_str(), dim + 1);
		dim = this->data_ora.length();
		f.write((char*)&dim, sizeof(dim));
		f.write(data_ora.c_str(), dim + 1);
		dim = this->zona.length();
		f.write((char*)&dim, sizeof(dim));
		f.write(zona.c_str(), dim + 1);
		f.write((char*)&nrPersoane, sizeof(nrPersoane));
		//f.write((char*)&dim, sizeof(dim));
		for (int i = 0; i < nrPersoane; i++)
		{
			f.write((char*)&locuri[i], sizeof(locuri[i]));
		}
		f.close();
	}

	void deserialize() {
		ifstream f("bilet.txt", ios::binary);
		short dim = 0;
		f.read((char*)&idBilet, sizeof(idBilet));
		f.read((char*)&dim, sizeof(dim));
		char* n = new char[dim + 1];
		f.read(n, dim + 1);
		numePiesa = n;
		delete[] n;
		f.read((char*)&dim, sizeof(dim));
		n = new char[dim + 1];
		f.read(n, dim + 1);
		data_ora = n;
		delete[] n;
		f.read((char*)&dim, sizeof(dim));
		n = new char[dim + 1];
		f.read(n, dim + 1);
		zona = n;
		delete[] n;
		f.read((char*)&nrPersoane, sizeof(nrPersoane));
		f.read((char*)&dim, sizeof(dim));
		n = new char[dim + 1];
		f.read(n, dim + 1);
		locuri = n;
		delete[] n;
		f.read((char*)&pret, sizeof(pret));
		f.close();
	}

	void vizualizeazaBileteDisp() {
		if (bilete.size() == 0) {
			cout << "Nu exista bilete disponibile." << endl;
			return;
		}
		for (int i = 0; i < bilete.size(); i++) {
			cout << "Biletul " << i + 1 << ":" << endl;
			cout << "Numele piesei: " << bilete[i].numePiesa << endl;
			cout << "Data si ora: " << bilete[i].data_ora << endl;
			cout << "Zona: " << bilete[i].zona << endl;
			cout << "Numarul de persoane: " << bilete[i].nrPersoane << endl;
		}
	}
};
