//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MetodePembayaran.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMetodePembayaranForm *MetodePembayaranForm;
//---------------------------------------------------------------------------
__fastcall TMetodePembayaranForm::TMetodePembayaranForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMetodePembayaranForm::Button1Click(TObject *Sender)
{
	ShowMessage("Pembayaran Berhasil");

}
//---------------------------------------------------------------------------
