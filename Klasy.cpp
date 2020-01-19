#include <iostream>
#include <string>
using namespace std;

#pragma region Student
class Student {
	int nip; // Domyślnie private 

public:
	Student()
	{
		numerIndeksu = 0;
		imie = "";
		nazwisko = "";
		drugieImie = "";
		numerTelefonu = "";
		adresZamieszkania = "";
		pesel = "";
		plec = 'K';
		aktywny = true;
	}

	Student(string imie, string drugieImie, string nazwisko, int numerIndeksu)
	{
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->drugieImie = drugieImie;
		this->numerIndeksu = numerIndeksu;

		aktywny = true;
	}

	~Student()
	{
		//cout << "Wywołanie dekonstruktora dla studenta:\n";
		//WyswietlDane();
	}

	int numerIndeksu;
	string imie;
	string nazwisko;
	string drugieImie;

protected:
	string numerTelefonu;
	string adresZamieszkania;

private:
	string pesel;
	char plec;
	bool aktywny;

public:
	void WyswietlDane()
	{
		cout << imie + " " + nazwisko << "\n";
	}

	void WyswietlNumerIndeksu()
	{
		cout << numerIndeksu << "\n";
	}

	void WyswietlPesel()
	{
		cout << pesel;
	}

	int PobierzNumerIndeksu();

	void UstawPesel(string peselArg)
	{
		if (peselArg.length() != 11)
		{
			cout << "PESEL powinien mieć 11 znaków!\n";
			return;
		}

		int length = peselArg.length();
		for (int i = 0; i < length; i++)
		{
			if (!isdigit(peselArg[i]))
			{
				cout << "PESEL powinien składać się wyłącznie z cyfr!\n";
				return;
			}
		}

		pesel = peselArg;

		cout << "Ustawienie pola PESEL powiodło się!\n";
		cout << "Ustawiona wartość to:" << pesel << "\n";
	}

	void UstawNumerTelefonu(string numerTelefonuArg)
	{
		if (numerTelefonuArg.length() != 9)
		{
			cout << "Numer telefonu powinien mieć 9 znaków!\n";
			return;
		}

		int length = numerTelefonuArg.length();
		for (int i = 0; i < length; i++)
		{
			if (!isdigit(numerTelefonuArg[i]))
			{
				cout << "Numer telefonu powinien składać się wyłącznie z cyfr!\n";
				return;
			}
		}

		numerTelefonu = numerTelefonuArg;

		cout << "Ustawienie numeru telefonu powiodło się!\n";
		cout << "Ustawiona wartość to:" << numerTelefonu << "\n";
	}
};

int Student::PobierzNumerIndeksu()
{
	return numerIndeksu;
}
#pragma endregion


#pragma region GeneratorIndeksow
class GeneratorIndeksow
{
private:
	static int numer;
public:
	static int GenerujNumer()
	{
		return numer++;
	}
};

int GeneratorIndeksow::numer = 1000;
#pragma endregion

#pragma region BazaStudentow
class BazaStudentow
{
private:
	static Student Studenci[];
public:
	static int liczbaStudentow;
	static void Dodaj(Student student)
	{
		if (liczbaStudentow < 100)
		{
			Studenci[liczbaStudentow] = student;
			cout << "Student został dodany do bazy!\n";
			cout << "Przydzielony numer indeksu to:" << Studenci[liczbaStudentow].PobierzNumerIndeksu() << "\n";

			liczbaStudentow++;
		}
		else
		{
			cout << "Przekroczyłeś limit studentów!\n";
		}
	}

	static void WyswietlDane(int numerIndeksu)
	{
		bool znaleziono = false;
		for (int i = 0; i < liczbaStudentow; i++)
		{
			if (Studenci[i].numerIndeksu == numerIndeksu)
			{
				znaleziono = true;

				cout << "Znaleziono studenta o podanym numerze indeksu:\n";
				Studenci[i].WyswietlDane();
				break;
			}
		}

		if (!znaleziono)
		{
			cout << "Nie znaleziono studenta o podanym numerze indeksu!\n";
		}
	}
};
int BazaStudentow::liczbaStudentow = 0;
Student BazaStudentow::Studenci[100];
#pragma endregion

#pragma region Ćwiczenia 1-12
void student1()
{
	string imie, drugieImie, nazwisko, pesel, numerTelefonu;

	cout << "Podaj imię studenta:";
	cin >> imie;
	cout << "Podaj drugie imię studenta:";
	cin >> drugieImie;
	cout << "Podaj nazwisko studenta:";
	cin >> nazwisko;
	Student student1(imie, drugieImie, nazwisko, GeneratorIndeksow::GenerujNumer());
	student1.WyswietlDane();
	cout << student1.PobierzNumerIndeksu();

	cout << "\nPodaj PESEL:";
	cin >> pesel;
	student1.UstawPesel(pesel);

	cout << "\nPodaj numer telefonu:";
	cin >> numerTelefonu;
	student1.UstawNumerTelefonu(numerTelefonu);
}

void student2()
{
	Student student;
	cout << "Podaj imię studenta:";
	cin >> student.imie;
	cout << "Podaj drugie imię studenta:";
	cin >> student.drugieImie;
	cout << "Podaj nazwisko studenta:";
	cin >> student.nazwisko;
	student.numerIndeksu = GeneratorIndeksow::GenerujNumer();
	student.WyswietlDane();
	student.WyswietlNumerIndeksu();

	string pesel;
	cout << "Podaj PESEL:";
	cin >> pesel;
	student.UstawPesel(pesel);

	string numerTelefonu;
	cout << "Podaj numer telefonu:";
	cin >> numerTelefonu;
	student.UstawNumerTelefonu(numerTelefonu);
}
#pragma endregion

void NowyStudent()
{
	string imie, drugieImie, nazwisko, pesel, numerTelefonu;

	cout << "Podaj imię studenta:";
	cin >> imie;
	cout << "Podaj drugie imię studenta:";
	cin >> drugieImie;
	cout << "Podaj nazwisko studenta:";
	cin >> nazwisko;

	Student student(imie, drugieImie, nazwisko, GeneratorIndeksow::GenerujNumer());

	cout << "Podaj PESEL:";
	cin >> pesel;
	student.UstawPesel(pesel);

	cout << "Podaj numer telefonu:";
	cin >> numerTelefonu;
	student.UstawNumerTelefonu(numerTelefonu);

	BazaStudentow::Dodaj(student);
}

int main()
{
	// Ćwiczenia 1-12 - można odkomentować
	//student1();
	//cout << "\n\n";
	//student2();

	char akcja = '1';

	while (akcja != '0')
	{
		cout << "Wybierz rodzaj akcji jaki chcesz wykonać:\n";
		cout << "1. Wprowadzanie nowego studenta.\n";
		cout << "2. Wyświetlenie danych o studencie\n";
		cout << "0. Wyjście z programu\n";
		cin >> akcja;

		switch (akcja)
		{
		case '1':
			NowyStudent();
			break;
		case '2':
			int numerIndeksu;
			cout << "Podaj numer indeksu\n";
			cin >> numerIndeksu;
			BazaStudentow::WyswietlDane(numerIndeksu);
			break;
		case '0':
			cout << "Koniec działania programu!\n";
			break;
		default:
			cout << "Wybierz prawidłowy numer przypisany akcji\n";
			break;
		}
	}

	return 0;
}