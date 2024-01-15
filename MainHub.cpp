//---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>
#include <fstream>
#include <string.h>
#pragma hdrstop
#include "MainHub.h"
#include "Change.h"
#include "About.h"
#include "Encrypt.h"
#include "Decrypt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
using namespace std;
 int p; // p - рандомное число, count - число для подсчетов попыток входа
 int coun=0;
 AnsiString  date, mounth, year;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
	{
		randomize();
		p = random(100);
		Label3->Caption= "Случайное число: "+IntToStr(p);
	}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
	{
		date = FormatDateTime("dd", Now());
		mounth = FormatDateTime("mm", Now());
		year = FormatDateTime("yy", Now());
		Label4->Caption="Дата: "+date+"."+mounth+"."+year;
	}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)

{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	if (Edit1->Text == "Tochilkin" && Edit2->Text == p + StrToInt(date))
		{
			fstream fout;
			fout.open("Logs.txt" , ios::app);
			fout << "Успешная авторизация:  " << asctime(ltm);
			fout.close();
			Form1->Visible=0;
			Form2 -> Show();
		}
	else
	{
		coun++;
		ShowMessage("Ошибка авторизации!\n Неудачных попыток входа: "+IntToStr(coun));
		int n = 3;
		Label5->Caption = "У вас осталось попыток: "+IntToStr(n-coun);
		 if (coun == 3)
			{
				fstream fout;
				fout.open("Logs.txt" , ios::app);
				ShowMessage("Превышен лимит попыток авторизации!");
				fout << "Неудачная попытка авторизации:  " << asctime(ltm);
				fout.close();
				this->Close();
				ShowMessage("Превышено количество неверных авторизаций!");
				Form1 -> Close();
				LockWorkStation();
			}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Form3->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
Form5->Show();
}
//---------------------------------------------------------------------------
