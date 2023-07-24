																									 


#include<iostream>
#include<cmath>
using namespace std;

class KarmasikSayi
{

public:

	void GirdiFonk() //kullanicidan karmasik sayi girmesi icin fonksiyon yazdim
	{
		cout << "sanal kismi girniz" << endl;
		cin >> sanal;
		cout << "gercel kismi giriniz" << endl;
		cin >> gercel;
	}
	void CiktiFonk() // karmasik sayinin yazilisina gore cikti fonksiyon yazdim
	{
		if (sanal < 0)
		{
			cout << "sayi:" << gercel << " " << sanal << "i";

		}
		else
		{
			cout << "sayi:" << gercel << "+" << sanal << "i";
		}
	}
	KarmasikSayi operator + (KarmasikSayi sayi2) // toplama operatorunu overloading yaptirdim 
	{
		KarmasikSayi yenisayi;
		yenisayi.gercel = gercel + sayi2.gercel;
		yenisayi.sanal = sanal + sayi2.sanal;
		return yenisayi;
	}

	KarmasikSayi operator - (KarmasikSayi sayi2) // cikartma operatorunu overloading yaptirdim
	{
		KarmasikSayi yenisayi;
		yenisayi.gercel = gercel - sayi2.gercel;
		yenisayi.sanal = sanal - sayi2.sanal;
		return yenisayi;
	}
	KarmasikSayi operator * (KarmasikSayi sayi2) // carpma operatorunu overloading yapt�rdim
	{
		KarmasikSayi yenisayi;
		yenisayi.gercel = gercel * sayi2.gercel - sanal * sayi2.sanal;
		yenisayi.sanal = gercel * sayi2.sanal + sanal * sayi2.gercel;
		return yenisayi;
	}

	KarmasikSayi operator / (KarmasikSayi sayi2) // bolme operatorunu overloading yaptirdim
	{

		KarmasikSayi yenisayi;
		float sayi = sayi2.gercel * sayi2.gercel + sayi2.sanal * sayi2.sanal;
		yenisayi.gercel = (gercel * sayi2.gercel - sanal * (-1 * sayi2.sanal)) / sayi;
		yenisayi.sanal = (gercel * (-1 * sayi2.sanal) + sanal * sayi2.gercel) / sayi;
		return yenisayi;
	}

	KarmasikSayi operator += (KarmasikSayi sayi2) // toplayip ekleme operatorunu overloading yaptirdim
	{
		KarmasikSayi yenisayi;
		gercel = gercel + sayi2.gercel;
		sanal = sanal + sayi2.sanal;
		return *this;
	}

	KarmasikSayi operator -= (KarmasikSayi sayi2) // c�kartip ekleme operatorunu overloading yaptirdim
	{
		KarmasikSayi yenisayi;
		gercel = gercel - sayi2.gercel;
		sanal = sanal - sayi2.sanal;
		return *this;
	}

	KarmasikSayi operator *= (KarmasikSayi sayi2)// carpip ekleme operatorunu overloading yaptirdim
	{
		KarmasikSayi yenisayi;
		gercel = sayi2.gercel - sanal * sayi2.sanal;
		sanal = sayi2.sanal + sanal * sayi2.gercel;
		return *this;
	}

	KarmasikSayi operator /= (KarmasikSayi sayi2)// bolup ekleme operatorunu overloading yaptirdim
	{
		KarmasikSayi yenisayi;
		float sayi = sayi2.gercel * sayi2.gercel + sayi2.sanal * sayi2.sanal;
		gercel = (gercel * sayi2.gercel - sanal * (-1 * sayi2.sanal)) / sayi;
		sanal = (gercel * (-1 * sayi2.sanal) + sanal * sayi2.gercel) / sayi;
		return *this;
	}

	void kutupsal() //kutupsal gosterim fonksiyonu yazdim
	{
		double r;
		double aci;
		const double derece = 180 / 3.141593;
		r = sqrt(gercel * gercel + sanal * sanal);
		aci = atan(sanal / gercel) * derece;
		cout << "r:" << r << " " << "aci:" << aci << endl;

	}
private:

	float gercel;
	float sanal;
};

int main() {

	KarmasikSayi karmasayi; //karmasilSayi s�n�f�ndan karmasayi nesnesi tanimladim
	karmasayi.GirdiFonk(); // ilk karmasik sayi icin fonksiyonlar� cagirdim
	karmasayi.CiktiFonk();
	KarmasikSayi karmasayi2;  //karmasilSayi s�n�f�ndan karmasayi2 nesnesi tanimladim

	cout << endl;

	karmasayi2.GirdiFonk(); // 2. karmasik sayi icin fonksiyonlari cagirdim
	karmasayi2.CiktiFonk();

	KarmasikSayi topla, cikart, carp, bol;

	topla = karmasayi + karmasayi2; //burda da nesnelerle islemleri yaptirdim normalde yapamadigimiz bisi o yuzden overloading yaparak yapt�rd�m
	cikart = karmasayi - karmasayi2;
	carp = karmasayi * karmasayi2;
	bol = karmasayi / karmasayi2;

	cout << endl;
	int secim;
	char eh; //bunu da men�y� d�ng�ye almak i�in yazd�m
	do
	{



		cout << endl;



		cout << "********* MENU **********" << endl;
		cout << " 1: TOPLAMA �SLEM� �C�N" << endl;     //men� kismi
		cout << " 2: C�KARTMA �SLEM� �C�N" << endl;
		cout << " 3: CARPMA �SLEM� �C�N" << endl;
		cout << " 4: BOLME �SLEM� �C�N" << endl;
		cout << " 5: += �SLEM� �C�N" << endl;
		cout << " 6: -= �SLEM� �C�N" << endl;
		cout << " 7: *= �SLEM� �C�N" << endl;
		cout << " 8: /= �SLEM� �C�N" << endl;
		cout << " 9: KUTUPSAL �SLEM �C�N" << endl;
		cin >> secim;// men� icin secim yapmasini istedim kullanicidan
		switch (secim)

		{

		case 1:

			cout << endl << "toplam: ";
			topla.CiktiFonk();  //fonksiyonlari cagirdim
			break;

		case 2:

			cout << endl << "cikarma: ";
			cikart.CiktiFonk();  //fonksiyonlari cagirdim
			break;

		case 3:

			cout << endl << "carpma: ";
			carp.CiktiFonk();  //fonksiyonlari cagirdim
			break;

		case 4:

			cout << endl << "bolme: ";
			bol.CiktiFonk();  //fonksiyonlari cagirdim
			break;

		case 5:

			karmasayi += karmasayi2;
			cout << endl << " topla ekle: ";
			karmasayi.CiktiFonk();  //fonksiyonlari cagirdim
			break;

		case 6:

			karmasayi -= karmasayi2;
			cout << endl << "cikart ekle: ";
			karmasayi.CiktiFonk();  //fonksiyonlari cagirdim
			break;

		case 7:

			karmasayi *= karmasayi2;
			cout << endl << "carp ekle: ";
			karmasayi.CiktiFonk();  //fonksiyonlari cagirdim
			break;

		case 8:

			karmasayi /= karmasayi2;
			cout << endl << "bol ekle: ";
			karmasayi.CiktiFonk();  //fonksiyonlari cagirdim
			break;

		case 9:
			cout << endl << "kutupsal gosterim: ";
			cout << "1.karmasik sayi:"; karmasayi.kutupsal();  //fonksiyonlari cagirdim
			cout << "		   2.karmasik sayi:"; karmasayi2.kutupsal();  //fonksiyonlari cagirdim
			break;

		default:
			cout << "lutfen gecerli aral�kta deger giriniz";
			break;

		}
		cout << endl;
		cout << "islemi tekrar yapmak ister misiniz (e/h)" << endl;  //dong� icin kullan�c�ya evet hayir sorusunu sordum
		cin >> eh;

	}

	while (eh != 'h');

	system("pause");

}