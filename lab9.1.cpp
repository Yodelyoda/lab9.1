#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;
enum Spec { KOMPNAUK, INFORMAT,TRUDOVIK,FIZIK,MATEM };
string specStr[] = { "���������� �����", "������������", "����������� �� ��������","�Գ���� �� �����������","�������� ���������" };
struct Student
{
	string prizv;
	unsigned kurs;
	unsigned nomer;
	Spec spec;
	int FIZrate;
	int MATrate;
	union
	{
		int PEDArate;
		int PROGrate;
		int CHISLrate;
	};
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double LineSearch(Student* p, const int N);
int main()
{ // ������������ ����������� ��������:
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������
	int N;
	cout << "������ ������� ��������: "; cin >> N;
	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	double proc = LineSearch(p, N);
	cout << "ʳ������ ��������, ��� ������� ��� �������� 4,5:" << proc << endl;
	return 0;
}
void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "������� No " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ���������� ����� �������� � ����: "; cin >> p[i].nomer;
		cout << " ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 -������� �������� ): ";
		cin >> spec;
		p[i].spec = (Spec)spec;
		switch (p[i].spec)
		{
		case KOMPNAUK:
			cout << " ������ � ������ : "; cin >> p[i].FIZrate;
			cout << " ������ � ���������� : "; cin >> p[i].MATrate;
			cout << " ������ � ������������� : "; cin >> p[i].PROGrate;
			break;
		case INFORMAT:
			cout << " ������ � ������ : "; cin >> p[i].FIZrate;
			cout << " ������ � ���������� : "; cin >> p[i].MATrate;
			cout << " ������ � ��������� ������ : "; cin >> p[i].CHISLrate;
			break;
		case TRUDOVIK:
			cout << " ������ � ������ : "; cin >> p[i].FIZrate;
			cout << " ������ � ���������� : "; cin >> p[i].MATrate;
			cout << " ������ � ��������� : "; cin >> p[i].PEDArate;
			break;
		case FIZIK:
			cout << " ������ � ������ : "; cin >> p[i].FIZrate;
			cout << " ������ � ���������� : "; cin >> p[i].MATrate;
			cout << " ������ � ��������� : "; cin >> p[i].PEDArate;
			break;
		case MATEM:
			cout << " ������ � ������ : "; cin >> p[i].FIZrate;
			cout << " ������ � ���������� : "; cin >> p[i].MATrate;
			cout << " ������ � ��������� : "; cin >> p[i].PEDArate;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "====================================================================================================================================================================================================="
		<< endl;
	cout << "| No | ������� | ���� | ���������� ����� �������� � ���� | ������������ | ������ � ������ | ������ � ���������� | ������ � ��������� ������ | ������ � ������������� | ������ � ���������|"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(4) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(6) << left << p[i].kurs
			<< "| " << setw(36) << right << p[i].nomer
			<< "| " << setw(20) << left << specStr[p[i].spec]
			<< "| " << setw(11) << right << p[i].FIZrate
			<< "| " << setw(11) << right << p[i].MATrate;
		switch (p[i].spec)
		{
		case KOMPNAUK:
			cout << "| " << setw(11) << right << "|"  << " " << setw(8) << right<< p[i].PROGrate << " |" << setw(11) << right << "|" << endl;
			break;
		case INFORMAT:
			cout << "| " << " " << setw(8) << right << p[i].CHISLrate << "|"  << setw(11) << right << "|" << setw(11) << right << "|" << endl;
		case TRUDOVIK:
		case FIZIK:
		case MATEM:
			cout << "| " << setw(11) << right << "|"  << setw(11) << right << "|" << " " << setw(8) << right<< p[i].PEDArate << " |" << endl;
			break;
		}
	}
	cout << "====================================================================================================================================================================================================="
		<< endl;
	cout << endl;
}
double LineSearch(Student* p, const int N)
{
	cout << "������� ��������, ��� ������� ��� �������� 4,5:" << endl;
	int k = 0, n = 0, a = 0, b = 0, c = 0, d = 0, f = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].spec == KOMPNAUK)
		{
			n++;
			if ((p[i].FIZrate+ p[i].MATrate + p[i].PROGrate )/3 > 4.5)
			{
				k++;
				a += p[i].FIZrate;
				b += p[i].MATrate;
				c += p[i].PROGrate;
				cout << setw(3) << right << k
					<< " " << p[i].prizv << endl;
			}
		}
		else if (p[i].spec == INFORMAT)
		{
			n++;
			if ((p[i].FIZrate + p[i].MATrate + p[i].CHISLrate) / 3 > 4.5)
			{
				k++;
				a += p[i].FIZrate;
				b += p[i].MATrate;
				d += p[i].CHISLrate;
				cout << setw(3) << right << k
					<< " " << p[i].prizv << endl;
			}
		}
		else if (p[i].spec == TRUDOVIK || p[i].spec == FIZIK || p[i].spec == MATEM)
		{
			n++;
			if ((p[i].FIZrate + p[i].MATrate + p[i].PEDArate) / 3 > 4.5)
			{
				k++;
				a += p[i].FIZrate;
				b += p[i].MATrate;
				f += p[i].PEDArate;
				cout << setw(3) << right << k
					<< " " << p[i].prizv << endl;
			}
		}
		
	}
	int maximum = max(a, max(b, max(c, d)));;
	if (maximum = a)
	{
		cout << "�������, ������� ��� ����� ��������� ������" << endl;
	}
	else if (maximum = b)
	{
		cout << "�������, ������� ��� ����� ��������� ����������" << endl;
	}
	else if (maximum = c)
	{
		cout << "�������, ������� ��� ����� ��������� �������������" << endl;
	}
	else if (maximum = d)
	{
		cout << "�������, ������� ��� ����� ��������� �����������" << endl;
	}
	else
	{
		cout << "�������, ������� ��� ����� ��������� ���������" << endl;
	}
	return 100.0* k / n;
}