#include <vcl.h>
#pragma hdrstop
#include "Change.h"
#include "Encrypt.h"
#include "shifr.h"
#include <string.h>
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
using namespace std;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button3Click(TObject *Sender)
{
	Edit1->Text=" ";
	Edit2->Text=" ";
	Edit3->Text=" ";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
  Form4->Close();
  Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button4Click(TObject *Sender)
{
	if(OpenDialog1->Execute() == idOK)
	{
		Edit1->Text = OpenDialog1->FileName;
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button5Click(TObject *Sender)
{
	if(SaveDialog1->Execute() == idOK)
	{
		Edit2->Text = SaveDialog1->FileName;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	// Запросите у пользователя смену расшифровки
	//инициализация сдвига
	AnsiString k= Edit3->Text;
	string forencrypt, key, outfile;
	key =  string(k.c_str());
   //открытие файла для зашифрования
	AnsiString fc= Edit1->Text;
	int handle = FileOpen(fc, fmOpenRead);
	int length = FileSeek(handle, 0, 2);
	char* inbuf = new char[length];
	FileSeek(handle, 0, 0);
	FileRead(handle, inbuf, length);
	ShowMessage(inbuf);
	forencrypt=string(inbuf);
	ShowMessage(forencrypt.length());
	FileClose(handle);
	AnsiString outFileName = Edit2->Text;
	string ct = Shifr(forencrypt, key, outfile);
	ShowMessage(ct.c_str());
	AnsiString outFilePath = Edit2->Text;
	DeleteFile(outFilePath);
	int outhandle = FileCreate(outFilePath);
	char* outbuf = (char*)ct.c_str();
	ShowMessage(ct.length());
	FileWrite(outhandle, outbuf, ct.length());
	FileClose(outhandle);
	ShowMessage("Файл успешно зашифрован!");
   }

//---------------------------------------------------------------------------
