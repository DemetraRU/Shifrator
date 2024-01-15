#include "shifr.h"
#include <string>
#include <fstream>
#include <iostream>
	using namespace std;
	unsigned char x;
	int startpose, alph_len;
	int get_shift(unsigned char x)
{
	if (x>=65 && x<=90)  //English alphabet has large letters
		return int(x) - 64;  //The return of the capital letter "A"
	else if (x>=97 && x<=122)  //English alphabet small letters
		return int(x) - 96;  //The return of the small letter "A"
	else if (x >= 48 && x <= 57)  //The alphabet of numbers
		return int(x) - 48;  //The return of a digit
	else if (x >= 192 && x <= 223)  //Russian alphabet has large letters
		return int(x) - 192;  //The return of the capital letter "A"
	else if (x >=224 && x <=255)  //Russian alphabet small letters
		return int(x) - 224;  //The return of the small letter "A"
	else return int(x) - 0;  //the set values remain
}
string Shifr (string forencrypt, string key, string fe)
{
	fe = "";
	int shift = 0;//
	for (int i =0; i < forencrypt.length(); i++) {
		x = static_cast <unsigned char> (forencrypt[i]);
		shift = get_shift(key[i % key.length()]);
		if (x>=65 && x<=90)
		{
		  alph_len = 26;
		  startpose = 65;
		  char y = char ( (((x - startpose) + shift) % alph_len) + startpose);
			fe += y;
		}
			else if (x>=97 && x<=122)
			{
			  alph_len = 26;
			  startpose = 97;
			  char y = char ( (((x - startpose) + shift) % alph_len) + startpose);
				fe += y;
			}
				else if (x>=192 && x<=223)
				{
				  alph_len = 32;
				  startpose = 192;
				  char y = char ( (((x - startpose) + shift) % alph_len) + startpose);
					fe += y;
				}
					else if (x>=224 && x<=255)
					{
					  alph_len = 32;
					  startpose = 224;
					  char y = char ( (((x - startpose) + shift) % alph_len) + startpose);
						fe += y;
					}
							else if (x>=48 && x<=57)
						{
						  alph_len = 10;
						  startpose = 48;
						  char y = char ( (((x - startpose) + shift) % alph_len) + startpose);
							fe += y;
						}
							else
							{
							char y = char (x);
							fe += y;
							}
	}
	return fe;
}

string DeShifr(string encrypted, string key, string decrypt)
{
		string qwe = key;
	decrypt="";
	int shift = 0;//
	for (int i =0; i < encrypted.length(); i++) {
		x = static_cast <unsigned char> (encrypted[i]);
		shift = get_shift(key[i % key.length()]);
		if (x>=65 && x<=90)
		{
		  alph_len = 26;
		  startpose = 65;
		  char y = char ( (((x - startpose) - shift) % alph_len) + startpose );
			decrypt += y;
		}
			else if (x>=97 && x<=122)
			{
			  alph_len = 26;
			  startpose = 97;
			  char y = char ( (((x - startpose) - shift) % alph_len) + startpose );
			  decrypt += y;
			}
				else if (x>=192 && x<=223)
				{
				  alph_len = 32;
				  startpose = 192;
				  char y = char ( (((x - startpose) - shift) % alph_len) + startpose );
				  decrypt += y;
				}
					else if (x>=224 && x<=255)
					{
					  alph_len = 32;
					  startpose = 224;
					  char y = char ( (((x - startpose) - shift) % alph_len) + startpose );
					  decrypt += y;
					}
							else if (x>=48 && x<=57)
						{
						  alph_len = 10;
						  startpose = 48;
						  char y = char ( (((x - startpose) - shift) % alph_len) + startpose );
						  decrypt += y;
						}
							else
							{
								char y = char (x);
								decrypt += y;
							}
	}
	return decrypt;
}
