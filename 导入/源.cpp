#include<iostream>
#include<fstream>
#include<algorithm>
#include<conio.h>
#include<ctime>
#include"store.h"
using namespace std;

struct item {
	int* number = new int[200];
	string* name = new string[200];
	string* account = new string[200];
	string* password = new string[200];
	string* email = new string[200];
};

string password;
string input, input1;
int* num = new int[200];
string Name, Num_2, Num_3, Num_4;
bool judge = true;
bool def = true;
string flag = "";
int number = 0;
int position = -1;
struct item object;

void fresh() {
	fstream fs("password.txt", fstream::out | ios_base::trunc);
	fs.close();
	ofstream fout("password.txt", ios::app);
	fout << password << endl << number << endl;
	for (int i = 0; i < number; i++) {
		fout << object.number[i] << endl << object.name[i] << endl << object.account[i] << endl << object.password[i] << endl;
	}
	fout.close();
	cout << "������Ѹ���" << endl;
}

void help() {
	cout << endl << "\t�����ĵ�" << endl << endl;
	cout << "help()" << "\t\t" << "����ҳ��" << endl;
	cout << "csp()" << "\t\t" << "����ϵͳ����" << endl;
	cout << "quit()" << "\t\t" << "�˳�����" << endl;
	cout << "info()" << "\t\t" << "�鿴������־" << endl;
	cout << "cn()" << "\t\t" << "�޸�����" << endl;
	cout << "ca()" << "\t\t" << "�޸��û���" << endl;
	cout << "cp()" << "\t\t" << "�޸�����" << endl;
	cout << "add()" << "\t\t" << "���������" << endl;
	cout << "showall()" << "\t\t" << "��ʾ�������" << endl << endl;
}
void System(string input) {
	string h[10] = { "help()", "csp()", "quit()", "info()", "cn()", "ca()", "cn()", "cp()", "add()","showall()" };
	string current = "";
	for (int i = 0; i < sizeof(h) / sizeof(string); i++) {
		current = h[i];
		if (input == current) {
			def = false;
		}
	}
	if (input == "help()") {
		help();
	}
	else if (input == "csp()") {
		string input1 = "";
		string input = "";
		while (true) {
			cout << "������������" << endl;
			cin >> input;
			cout << "��������һ��ȷ��������" << endl;
			cin >> input1;
			if (input1 == input) {
				password = input;
				fresh();
				cout << "��Ҫ����������ʹ������������Ч" << endl;
				break;
			}
			else {
				cout << "���������벻һ��" << endl;
			}
		}
	}
	else if (input == "quit()") {
		log(1);
		exit(0);
	}
	else if (input == "info()") {
		cout << "�ó����ɳ���Աqyy8179227785����д" << endl << "��д�ߣ�qyy8179227785" << endl;
		cout << "���ʱ�䣺2020.01.14 15:28:46" << endl << "������ƽ̨��Windows8�����ϰ汾" << endl;
		cout << "2.0�汾���������ʱ�䣺2021.10.13 00:26:00" << endl << "������ƽ̨��Windows8�����ϰ汾" << endl;
		cout << ">>>>>>>>>>���ս���Ȩ��qyy8179227785����<<<<<<<<<<" << endl;
	}
	else if (input == "cn()") {
		string current = "";
		cout << "�����������:" << endl;
		cin >> Name;
		for (int i = 0; i < number; i++) {
			current = object.name[i];
			if (Name == current) {
				position = i;
			}
		}
		if (position == -1) {
			cout << "��Ǹ,���������δ��¼�������" << endl;
		}
		else {
			cout << "������������:" << endl;
			cin >> object.name[position];
			fresh();
			cout << "�ѳɹ��޸�����" << endl;
		}
	}
	else if (input == "ca()") {
		string current = "";
		cout << "����������:" << endl;
		cin >> Name;
		for (int i = 0; i < number; i++) {
			current = object.name[i];
			if (Name == current) {
				position = i;
			}
		}
		if (position == -1) {
			cout << "��Ǹ,���������δ��¼�������" << endl;
		}
		else {
			cout << "���������û���:" << endl;
			cin >> object.account[position];
			fresh();
			cout << "�ѳɹ��޸��û���" << endl;
		}
	}
	else if (input == "cp()") {
		string current = "";
		cout << "����������:" << endl;
		cin >> Name;
		for (int i = 0; i < number; i++) {
			current = object.name[i];
			if (Name == current) {
				position = i;
			}
		}
		if (position == -1) {
			cout << "��Ǹ,���������δ��¼�������" << endl;
		}
		else {
			cout << "������������:" << endl;
			cin >> object.password[position];
			fresh();
			cout << "�ѳɹ��޸�����" << endl;
		}
	}
	else if (input == "add()") {
		number++;
		object.number[number - 1] = number;
		cout << "��������Ŀ����" << endl;
		cin >> object.name[number - 1];
		cout << "�������û���" << endl;
		cin >> object.account[number - 1];
		cout << "����������" << endl;
		cin >> object.password[number - 1];
		fresh();
	}
	else if (input == "showall()") {
		cout << "���������Ϊ" << number << endl;
	}
}

void data() {
	ifstream in("password.txt");
	in >> password;
	in >> number;
	for (int i = 0; i < number; i++) in >> object.number[i] >> object.name[i] >> object.account[i] >> object.password[i];
	in.close();
}

void search(string Name) {
	int f = 0;
	string current = "";
	int opra = 0;
	bool fl = true;
	if (def) {
		for (int i = 0; i < number; i++) {
			current = object.name[i];
			if (Name == current) {
				position = i;
				//cout << "�û���:" << b[i] << endl << "����:" << c[i] << endl;
				f = 0;
			}//ƥ��ɹ�
		}
		for (int i = 0; i < number; i++) {
			for (int j = 0; j <= max(0, int(object.name[i].length() - Name.length())); j++) {
				for (int k = j; k < min(object.name[i].length() + j, Name.length() + j); k++) {
					if (object.name[i][k] != Name[opra]) {
						fl = false;
					}
					opra++;
				}
				opra = 0;
				if (fl == true) {
					position = i;
					f = 1;
					cout << "�˺�:" << object.name[i] << endl << "�û���:" << object.account[i] << endl << "����:" << object.password[i] << endl;
					break;
				}
				fl = true;
			}
		}
		if (f == 0) {
			cout << "��Ǹ���������δ�ռ������ݣ����������?(����0���˳���" << endl;
			cin >> Num_2;
			if (Num_2 == "0") {
			}
			else {
				number++;
				object.number[number - 1] = number;
				cout << "��������Ŀ����" << endl;
				cin >> object.name[number - 1];
				cout << "�������û���" << endl;
				cin >> object.account[number - 1];
				cout << "����������" << endl;
				cin >> object.password[number - 1];
				fresh();
			}
		}
	}//���������
}

void log(int location) {
	if (location == 0) {
		time_t now = time(0);
		char dt[26];
		ctime_s(dt, sizeof(dt), &now);
		ofstream fout("log.txt", ios::app);
		fout << dt << "program start" << endl;
		fout.close();
	}
	else if (location == 1) {
		time_t now = time(0);
		char dt[26];
		ctime_s(dt, sizeof(dt), &now);
		ofstream fout("log.txt", ios::app);
		fout << dt << "program quit" << endl;
		fout.close();
	}
}

int main() {
	log(0);
	data();
	while (judge) {
		cout << "�������������" << endl;
		cin >> input;
		if (input == password) {
			while (true) {
				cout << "������ؼ���" << endl;
				cin >> Name;//����
				System(Name);
				search(Name);
				def = true;
				flag = "";
				position = -1;
			}
		}
		else {
			cout << "�������!���������������0�˳�����" << endl;
			cin >> input;
			if (input == "0") {
				judge = false;
			}
		}
	}
	log(1);
	return 0;
}