#include <iostream>
#include <string>

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
	Document(string newDate, double newSum) {
		date = newDate;
		sum = newSum;
	}
	virtual ~Document() {
		cout << "default destructor" << endl;
	}
	virtual void show() = 0; 
	virtual void input() = 0;
	virtual void addToList() = 0;
protected:
	string date;
	double sum;
};

class Bill :public Document {
public:
	Bill() : Document() {};
	Bill(int amountN, string sellerN, string nameOfGoodN, 
		 string dateN, double sumN) {
		amount = amountN;
		seller = sellerN;
		nameOfGood = nameOfGoodN;
		date = dateN;
		sum = sumN;
	}
	void show() {
		cout << "Bill" << endl;
		cout << "Date: " << date << endl;
		cout << "Sum: " << sum << endl;
		cout << "Name of good: " << nameOfGood << endl;
		cout << "Amount: " << amount << endl;
		cout << "Seller: " << seller << endl;
		cout << endl;
	}
	void input() {
		cout << "Bill" << endl;
		cout << "Enter date: ";			cin >> date;
		cout << "Enter sum: ";			cin >> sum;
		cout << "Enter name of good: "; cin >> nameOfGood;
		cout << "Enter amount: ";		cin >> amount;
		cout << "Enter seller: ";		cin >> seller;
		cout << endl;
	}
	void addToList() {
		Document* p = start;
		while (p->next) {
			p = p->next;
		}
		p->next = this;
	}
protected:
	int amount;
	string seller;
	string nameOfGood;
};

class Invoice :public Bill {
public:
	Invoice() : Bill() {};
	Invoice(int amountN, string sellerN, string nameOfGoodN, 
			string dateN, double sumN, string nameOfOrganizationN, 
			int numberOfInvoiceN, string buyerN, string gradeN) {
		amount = amountN;
		seller = sellerN;
		nameOfGood = nameOfGoodN;
		date = dateN;
		sum = sumN;
		nameOfOrganization = nameOfOrganizationN;
		numberOfInvoice = numberOfInvoiceN;
		buyer = buyerN;
		grade = gradeN;
	}
	void show() {
		cout << "Invoice" << endl;
		cout << "Name of organization: " << nameOfOrganization << endl;
		cout << "Number of invoice: " << numberOfInvoice << endl;
		cout << "Date: " << date << endl;
		cout << "Sum: " << sum << endl;
		cout << "Name of good: " << nameOfGood << endl;
		cout << "Amount: " << amount << endl;
		cout << "Grade: " << grade << endl;
		cout << "Seller: " << seller << endl;
		cout << "Buyer: " << buyer << endl;
		cout << endl;
	}
	void input() {
		cout << "Invoice" << endl;
		cout << "Enter name of organization: ";   cin >> nameOfOrganization;
		cout << "Enter number of invoice: ";	  cin >> numberOfInvoice;
		cout << "Enter date: ";					  cin >> date;
		cout << "Enter sum: ";					  cin >> sum;
		cout << "Enter name of good: ";			  cin >> nameOfGood;
		cout << "Enter amount: ";				  cin >> amount;
		cout << "Enter grade: ";				  cin >> grade;
		cout << "Enter seller: ";				  cin >> seller;
		cout << "Enter buyer: ";				  cin >> buyer;
		cout << endl;
	}
	void addToList() {
		Document* p = start;
		while (p->next) {
			p = p->next;
		}
		p->next = this;
	}
private:
	string nameOfOrganization;
	int numberOfInvoice;
	string buyer;
	string grade;
};

class Receipt :public Document {
public:
	Receipt() : Document() {};
	Receipt(string dateN, double sumN, int numberOfReceiptN,
			string nameOfOrganizationN,	int numberOfContractN,
			string dateOfContractN,	string typeN, string clientN,
			string periodN) {
		date = dateN;
		sum = sumN;
		numberOfReceipt = numberOfReceiptN;
		nameOfOrganization = nameOfOrganizationN;
		numberOfContract = numberOfContractN;
		dateOfContract = dateOfContractN;
		type = typeN;
		client = clientN;
		period = periodN;
	}
	void show() {
		cout << "Receipt" << endl;
		cout << "Name of organization: " << nameOfOrganization << endl;
		cout << "Number of receipt: " << numberOfReceipt << endl;
		cout << "Number of contract: " << numberOfContract << endl;
		cout << "Date of contract: " << dateOfContract << endl;
		cout << "Type of insurance: " << type << endl;
		cout << "Client: " << client << endl;
		cout << "Period: " << period << endl;
		cout << "Sum: " << sum << endl;
		cout << "Date: " << date << endl;
		cout << endl;
	}
	void input() {
		cout << "Receipt" << endl;
		cout << "Enter name of organization: "; cin >> nameOfOrganization;
		cout << "Enter number of receipt: ";	cin >> numberOfReceipt;
		cout << "Enter number of contract: ";	cin >> numberOfContract;
		cout << "Enter date of contract: ";		cin >> dateOfContract;
		cout << "Enter type of insurance: ";	cin >> type;
		cout << "Enter client: ";				cin >> client;
		cout << "Enter period: ";				cin >> period;
		cout << "Enter sum: ";					cin >> sum;
		cout << "Enter date: ";					cin >> date;
		cout << endl;
	}
	void addToList() {
		Document* p = start;
		while (p->next) {
			p = p->next;
		}
		p->next = this;
	}
protected: 
	int numberOfReceipt;
	string nameOfOrganization;
	int numberOfContract;
	string dateOfContract;
	string type;
	string client;
	string period;
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