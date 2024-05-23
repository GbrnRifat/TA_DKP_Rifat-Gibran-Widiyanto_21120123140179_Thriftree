//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Inti.h"
#include <iostream>
#include <vector>
#include "MetodePembayaran.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

using namespace std;

class Item {
public:
	Item(const string& nama, double harga)
		: nama(nama), harga(harga)  {}

	void displayItem(TMemo* memo) const {
		memo->Lines->Add("Nama: " + UnicodeString(nama.c_str()));
		memo->Lines->Add("Harga: " + UnicodeString(harga));
	}

	string getNama() const {
		return nama;
	}

	double getHarga () const {
		return harga;
	}

private:
	string nama;
	double harga;
};

class Seller {
public:
	Seller(const string& nama) : nama(nama) {}

	void addItem(const Item& item) {
		items.push_back(item);
	}

	bool removeItem(const string& itemName) {
		for (auto it = items.begin(); it != items.end(); ++it) {
			if (it->getNama() == itemName) {
				items.erase(it);
				return true;
			}
		}
		return false;
	}

	void displayItems(TMemo* memo) const {
		memo->Lines->Add("Penjual: " + UnicodeString(nama.c_str()));
		for (const auto& item : items) {
			item.displayItem(memo);
		}
		memo->Lines->Add("=========================");
	}

	const vector<Item>& getItems() const {
		return items;
	}

	string getNama() const {
		return nama;


	}


private:
	string nama;
	vector<Item> items;
};

class ThriftShop {
public:
	void addSeller(const Seller& seller) {
		sellers.push_back(seller);
	}

	void displayAllItems(TMemo* memo) const {
		for (const auto& seller : sellers) {
			seller.displayItems(memo);
		}
	}

	bool buyItem(const string& itemName, double expectedPrice, TMemo* memo) {
		for (auto& seller : sellers) {
			for (const auto& item : seller.getItems()) {
				if (item.getNama() == itemName) {
					double actualPrice = item.getHarga();
					if (actualPrice == expectedPrice) {
						if (seller.removeItem(itemName)) {
							memo->Lines->Add("Item '" + UnicodeString(itemName.c_str()) + "' telah dibeli dengan harga: " + UnicodeString(actualPrice));
							return true;
						}
					} else {
						memo->Lines->Add("Harga yang dimasukkan tidak sesuai untuk item '" + UnicodeString(itemName.c_str()) + "'.");
						return false;
					}
				}
			}
		}
		memo->Lines->Add("Item '" + UnicodeString(itemName.c_str()) + "' tidak ditemukan.");
		return false;
	}




private:
	vector<Seller> sellers;
};

ThriftShop shop;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ClickBeliBarang(TObject *Sender)
{
	string itemNama = AnsiString(Edit2->Text).c_str();
	double itemHarga = StrToFloat(Edit1->Text);

	bool result = shop.buyItem(itemNama, itemHarga, ListTitipan);

	if (result) {
		ShowMessage("Item telah berhasil dibeli.");
	} else {
		ShowMessage("Pembelian item gagal. Periksa kembali nama dan harga item.");
	}
		MetodePembayaranForm->Show ();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClickTitipBarang(TObject *Sender)
{

	string itemNama = AnsiString(Edit4->Text).c_str();
	double itemHarga = StrToFloat(Edit3->Text);
	string sellerNama = AnsiString(Edit5->Text).c_str();

	Seller seller(sellerNama);

	Item item(itemNama, itemHarga);
	seller.addItem(item);

	shop.addSeller(seller);
	ListTitipan->Lines->Add("Penjual dan item telah ditambahkan.");
	ShowMessage("Item telah ditambahkan!");


	}



