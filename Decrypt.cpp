//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Change.h"
#include "Decrypt.h"
#include "shifr.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
using namespace std;
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
	if(OpenDialog1->Execute() == idOK)
	{
		Edit1->Text = OpenDialog1->FileName;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button4Click(TObject *Sender)
{
	Edit1->Text=" ";
	Edit2->Text=" ";
	Edit3->Text=" ";
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button5Click(TObject *Sender)
{
	Form5->Close();
	Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button2Click(TObject *Sender)
{
	if(SaveDialog1->Execute() == idOK)
	{
		Edit2->Text = SaveDialog1->FileName;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button3Click(TObject *Sender)
{
// Запросите у пользователя смену расшифровки
	AnsiString fc= Edit1->Text;
	AnsiString k= Edit3->Text;
	string cyphertext, key, decrypt;
	key =  string((k).c_str());

	int handle = FileOpen(fc, fmOpenRead);
	int length = FileSeek(handle, 0, 2);
	char* inbuf = new char[length];
	FileSeek(handle, 0, 0);
	FileRead(handle, inbuf, length);
	ShowMessage(inbuf);
	cyphertext = string(inbuf);
	ShowMessage(cyphertext.length());
	FileClose(handle);

	string res = DeShifr(cyphertext, key, decrypt);
//    ShowMessage(key);
	ShowMessage(res.c_str());
	AnsiString outFileName = Edit2->Text;
	DeleteFile(outFileName);
	int outhandle = FileCreate(outFileName);
	char* outbuf = (char*)res.c_str();
	ShowMessage(res.length());
	FileWrite(outhandle, outbuf, res.length());
	FileClose(outhandle);
	ShowMessage("Файл успешно расшифрован!");
}
//---------------------------------------------------------------------------
