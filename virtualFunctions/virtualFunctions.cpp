#include<iostream>
#include<string>

using namespace std;

class Document {
public:
	static Document* start; 
	Document* next = NULL;
	static void ShowList() {
		Document* p = start;
		while (p) {
			p->show();
			p = p->next;
		}
	}
	Document() {
		cout << "defaul constructor" << endl;
	}
	Document(string newType, string newDate) {
		date = newDate;
		type = newType;
	}
	virtual ~Document() {
		cout << "default destructor" << endl;
	}
	virtual void show() = 0; 
	virtual void input() = 0;
	virtual void addToList() = 0;
protected:
	string date, type;
};

class Bill :public Document {
public:
	Bill() : Document() {};
	Bill(string newType, string newDate) {
		date = newDate;
		type = newType;
	}
	void show() {
		cout << "Type " << type << endl;
		cout << "Date " << date << endl;
	}
	void input() {
		type = "bill";
		cout << "Enter date ";
		cin >> date;
		cout << endl;
	}
	void addToList() {
		Document* p = start;
		while (p->next) {
			p = p->next;
		}
		p->next = this;
	}
};

class Invoice :public Document {
public:
	Invoice() : Document() {};
	Invoice(string newType, string newDate) {
		date = newDate;
		type = newType;
	}
	void show() {
		cout << "Type " << type << endl;
		cout << "Date " << date << endl;
	}
	void input() {
		type = "bill";
		cout << "Enter date ";
		cin >> date;
		cout << endl;
	}
	void addToList() {
		Document* p = start;
		while (p->next) {
			p = p->next;
		}
		p->next = this;
	}
};

class Receipt :public Document {
public:
	Receipt() : Document() {};
	Receipt(string newType, string newDate) {
		date = newDate;
		type = newType;
	}
	void show() {
		cout << "Type " << type << endl;
		cout << "Date " << date << endl;
	}
	void input() {
		type = "receipt";
		cout << "Enter date ";
		cin >> date;
		cout << endl;
	}
	void addToList() {
		Document* p = start;
		while (p->next) {
			p = p->next;
		}
		p->next = this;
	}
};

Document* Document::start = NULL;

int main() {
	Bill* bill;
	Receipt* receipt;
	Invoice* invoice;
	bill = new Bill();
	receipt = new Receipt();
	invoice = new Invoice();
	bill->input();
	receipt->input();
	invoice->input();
	Document::start = bill;
	receipt->addToList();
	invoice->addToList();
	Document::ShowList();
}