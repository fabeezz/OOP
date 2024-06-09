#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <unordered_set>

using namespace std;

class Stream {
public:
	friend istream& operator>>(istream& in, Stream& s);
	friend ostream& operator<<(ostream& in, const Stream& s);
	virtual void read(istream& in) = 0;
	virtual void print(ostream& out) const = 0;
};

istream& operator>>(istream& in, Stream& s) {
	s.read(in);
	return in;
}

ostream& operator<<(ostream& out, const Stream& s) {
	s.print(out);
	return out;
}

class Proprietate : public Stream {
	string adresa = "";
	bool vandut = false;
protected:
	float supLoc = 0.0f;
	float chirie = 0.0f;
public:
	virtual float getChirie(float x = 0) const = 0;
	void read(istream& in) {
		cout << "Introduceti adresa: ";
		in >> adresa;
		cout << "Suprafata locuibila: ";
		in >> supLoc;
		cout << "Valoarea chiriei pe mp: ";
		in >> chirie;
	}
	void print(ostream& out) const {
		out << "Adresa: " << adresa << "\nsupLoc: " << supLoc << "\nChirie per mp: " << chirie;
	}
	string getAdresa() const {
		return adresa;
	}
};

class Casa : public Proprietate {
	int nrNivel = 0;
	float supCurte = 0.0f;
public:
	float getChirie(float discount) const {
		return chirie * (supLoc + 0.2 * supCurte) * (1 - discount);
	}
	void read(istream& in) {
		Proprietate::read(in);
		cout << "Numar nivele: ";
		in >> nrNivel;
		cout << "Suprafata curte: ";
		in >> supCurte;
	}
	void print(ostream& out) const {
		Proprietate::print(out);
		out << "Nr nivele: " << nrNivel << "\nSup curte:" << supCurte;
	}
};

class Apartament : public Proprietate {
	int etaj = 0;
	int nrCamere = 0;
public:
	float getChirie(float discount) const {
		return chirie * supLoc * (1 - discount);
	}
	void read(istream& in) {
		Proprietate::read(in);
		cout << "Etaj: ";
		in >> etaj;
		cout << "Numar camere: ";
		in >> nrCamere;
	}
	void print(ostream& out) const {
		Proprietate::print(out);
		cout << "Etaj: " << etaj << "\nNumar camere: " << nrCamere;
	}
};

class Data : public Stream {
	int luna, an;
public:
	Data(int l = 1, int a = 2004) : luna(l), an(a) {};
	int operator-(const Data& d) {
		return (an - d.an) * 12 + luna - d.luna;
	}
	void read(istream& in) {
		cout << "\n";
		cout << "An: ";
		in >> an;
		cout << "Luna: ";
		in >> luna;
	}
	void print(ostream& out) const {
		out << luna << "." << an;
	}
	bool operator<=(const Data& d) const {
		if (an < d.an)
			return true;
		else if (an == d.an)
			return luna <= d.luna;
		return false;
	}
};

class Contract : public Stream {
protected:
	string nume = "";
	Data dataI = Data();
	Data dataS = Data();
	Proprietate* Prop = nullptr;
public:
	void read(istream& in) {
		cout << "Nume client: ";
		getline(in, nume);
		cout << "Data tranzactie: ";
		in >> dataI;
		cout << "Data achitare:";
		in >> dataS;
		setDiscount();
	}
	void print(ostream& out) const {
		cout << "Nume client: " << nume << "\nData tranzactie: " << dataI << "\nData achitare: " << dataS << "\nAdresa Proprietate: " << Prop->getAdresa();
	}
	const Data& getDataI() const {
		return dataI;
	}
	const Data& getDataS() const {
		return dataS;
	}
	Proprietate* getProp() const {
		return Prop;
	}
	virtual float getProfit() const = 0;
	virtual void setDiscount() = 0;
};

class Inchiriere : public Contract {
	float discount = 0;
	void setDiscount() {
		int nrLuni = Contract::dataS - Contract::dataI;
		if (nrLuni > 24)
			discount = 0.1;
		else if (nrLuni > 12)
			discount = 0.05;
		else discount = 0;
	}
public:
	float getProfit() const {
		return Contract::Prop->getChirie(discount);
	}
};

class Cumparare : public Contract { // max 240 luni
	float discount = 0;
	float pret = 0;
	void setDiscount() {
		int nrLuni = Contract::dataS - Contract::dataI;
		if (nrLuni == 0)
			discount = 0.1;
		else if (nrLuni <= 60)
			discount = 0.07;
		else if (nrLuni <= 120)
			discount = 0.05;
		else discount = 0;
		setPret();
	}
	void setPret() {
		pret = 240 * Contract::Prop->getChirie() * (1 - discount);
	}
public:
	float getProfit() const {
		return pret;
	}
};

class Istoric {
	static Istoric* instance;
	vector<Proprietate*> proprietati;
	vector<Contract*> contracte;
public:
	Istoric() = default;
	Istoric(const Istoric&) = delete;
	Istoric& operator=(const Istoric&) = delete;
	static Istoric* getInstance() {
		if (instance == nullptr)
			instance = new Istoric();
		return instance;
	}
	void addProp(Proprietate* p) {
		proprietati.push_back(p);
	}
	void addCon(Contract* c) {
		contracte.push_back(c);
	}
	void printProp() const {
		cout << "\nCase:\n";
		for (const auto& p : proprietati)
			if (dynamic_cast<Casa*>(p))
				cout << *p;
		cout << "Apartamente:\n";
		for (const auto& p : proprietati)
			if (dynamic_cast<Apartament*>(p))
				cout << *p;
	}
	void printContracte() const {
		cout << "\nInchiriere:\n";
		for (const auto& c : contracte)
			if (dynamic_cast<Inchiriere*>(c))
				cout << *c;
		cout << "Cumparare:\n";
		for (const auto& c : contracte)
			if (dynamic_cast<Cumparare*>(c))
				cout << *c;
	}
	void printPropDupaData(const Data& d) const {
		unordered_set<Proprietate*> libere;
		unordered_set<Proprietate*> inchiriate;
		unordered_set<Proprietate*> vandute;
		for (const auto& c : contracte)
			if (c->getDataI() <= d && d <= c->getDataS()) {
				if (dynamic_cast<Inchiriere*>(c))
					inchiriate.insert(c->getProp());
				else vandute.insert(c->getProp());
			}
		for (const auto& p : proprietati)
			if (inchiriate.find(p) == inchiriate.end() && vandute.find(p) == vandute.end())
				libere.insert(p);
		cout << "\nLibere: \n";
		for (const auto& p : libere)
			cout << *p;
		cout << "Inchiriate: \n";
		for (const auto& p : inchiriate)
			cout << *p;
		cout << "Vandute: \n";
		for (const auto& p : vandute)
			cout << *p;
	}	
	float getProfit(const Data& d) const {
		float profit = 0;
		for (const auto& c : contracte)
			if (c->getDataI() <= d && d <= c->getDataS()) {
				profit += c->getProfit();
			}
		return profit;
	}
};

Istoric* Istoric::instance = nullptr;

void menu() {
	try {
		cout << "\nAlege optiunea:\n1.Adauga n prop sau contracte\n2.Afisare prop si contractele grupate dupa tip\n3.Afisare prop dupa situatia lor la o anumita data\n4.Suma pe care o incaseaza la o anumita data";
		int x;
		cout << "\n";
		cin >> x;
		switch (x) {
		case 1:
		{
			cout << "Ce introduceti? (proprietati/contracte): ";
			string tip;
			cin >> tip;
			if (tip != "proprietati" && tip != "contracte")
				throw runtime_error("Input gresit!");
			cout << "Cate intrari? :";
			int nr;
			cin >> nr;
			while (nr--) {
				if (tip == "proprietati") {
					Proprietate* Prop = nullptr;
					cout << "Casa sau Apartament? (casa/apartament):";
					string fel;
					cin >> fel;
					if (fel == "casa")
						Prop = new Casa();
					else Prop = new Apartament();
					cin >> *static_cast<Stream*>(Prop);
					Istoric::getInstance()->addProp(Prop);
				}
				else {
					Contract* Con = nullptr;
					cout << "Inchiriere sau cumparare? (inchiriere/cumparare):";
					string fel;
					cin >> fel;
					if (fel == "inchiriere")
						Con = new Inchiriere();
					else Con = new Cumparare();
					cin >> *static_cast<Stream*>(Con);
					Istoric::getInstance()->addCon(Con);
				}
			}
		}
		break;
		case 2:
		{
			Istoric::getInstance()->printProp();
			Istoric::getInstance()->printContracte();
		}
		break;
		case 3:
		{
			cout << "La ce data?: ";
			Data data;
			cin >> data;
			Istoric::getInstance()->printPropDupaData(data);
		}
		break;
		case 4:
		{
			cout << "La ce data?: ";
			Data data;
			cin >> data;
			cout << "\n" << Istoric::getInstance()->getProfit(data);
		}
		}

	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	menu();
}

int main() {

	menu();
	return 0;
}