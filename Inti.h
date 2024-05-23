//---------------------------------------------------------------------------

#ifndef IntiH
#define IntiH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <vector>
#include <string>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Button1;
	TButton *Button2;
	TMemo *ListTitipan;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit3;
	TEdit *Edit4;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit5;
	TLabel *Label6;
	TImage *Image1;
	void __fastcall ClickBeliBarang(TObject *Sender);
	void __fastcall ClickTitipBarang(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
