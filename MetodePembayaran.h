//---------------------------------------------------------------------------

#ifndef MetodePembayaranH
#define MetodePembayaranH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TMetodePembayaranForm : public TForm
{
__published:	// IDE-managed Components
	TRadioButton *RadioButton1;
	TLabel *Label1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TButton *Button1;
	TEdit *Edit1;
	TLabel *Label2;
	TImage *Image1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMetodePembayaranForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMetodePembayaranForm *MetodePembayaranForm;
//---------------------------------------------------------------------------
#endif
