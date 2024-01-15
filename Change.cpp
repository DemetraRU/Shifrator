//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "MainHub.h"
#include "Decrypt.h"
#include "Encrypt.h"
#include "Change.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Form4->Show();
	Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	Form5->Show();
	Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	 Form1->Close();
	 Form2->Close();
}
