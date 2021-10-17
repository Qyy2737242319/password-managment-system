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
	cout << "密码库已更新" << endl;
}

void help() {
	cout << endl << "\t帮助文档" << endl << endl;
	cout << "help()" << "\t\t" << "帮助页面" << endl;
	cout << "csp()" << "\t\t" << "更换系统密码" << endl;
	cout << "quit()" << "\t\t" << "退出程序" << endl;
	cout << "info()" << "\t\t" << "查看开发日志" << endl;
	cout << "cn()" << "\t\t" << "修改名称" << endl;
	cout << "ca()" << "\t\t" << "修改用户名" << endl;
	cout << "cp()" << "\t\t" << "修改密码" << endl;
	cout << "add()" << "\t\t" << "添加新名称" << endl;
	cout << "showall()" << "\t\t" << "显示密码个数" << endl << endl;
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
			cout << "请输入新密码" << endl;
			cin >> input;
			cout << "请再输入一遍确认新密码" << endl;
			cin >> input1;
			if (input1 == input) {
				password = input;
				fresh();
				cout << "需要重启程序以使新密码立即生效" << endl;
				break;
			}
			else {
				cout << "输入新密码不一致" << endl;
			}
		}
	}
	else if (input == "quit()") {
		log(1);
		exit(0);
	}
	else if (input == "info()") {
		cout << "该程序由程序员qyy8179227785所编写" << endl << "编写者：qyy8179227785" << endl;
		cout << "完成时间：2020.01.14 15:28:46" << endl << "试运行平台：Windows8及以上版本" << endl;
		cout << "2.0版本发布！完成时间：2021.10.13 00:26:00" << endl << "试运行平台：Windows8及以上版本" << endl;
		cout << ">>>>>>>>>>最终解释权归qyy8179227785所有<<<<<<<<<<" << endl;
	}
	else if (input == "cn()") {
		string current = "";
		cout << "请输入旧名称:" << endl;
		cin >> Name;
		for (int i = 0; i < number; i++) {
			current = object.name[i];
			if (Name == current) {
				position = i;
			}
		}
		if (position == -1) {
			cout << "抱歉,密码库中暂未收录该密码对" << endl;
		}
		else {
			cout << "请输入新名称:" << endl;
			cin >> object.name[position];
			fresh();
			cout << "已成功修改名称" << endl;
		}
	}
	else if (input == "ca()") {
		string current = "";
		cout << "请输入名称:" << endl;
		cin >> Name;
		for (int i = 0; i < number; i++) {
			current = object.name[i];
			if (Name == current) {
				position = i;
			}
		}
		if (position == -1) {
			cout << "抱歉,密码库中暂未收录该密码对" << endl;
		}
		else {
			cout << "请输入新用户名:" << endl;
			cin >> object.account[position];
			fresh();
			cout << "已成功修改用户名" << endl;
		}
	}
	else if (input == "cp()") {
		string current = "";
		cout << "请输入名称:" << endl;
		cin >> Name;
		for (int i = 0; i < number; i++) {
			current = object.name[i];
			if (Name == current) {
				position = i;
			}
		}
		if (position == -1) {
			cout << "抱歉,密码库中暂未收录该密码对" << endl;
		}
		else {
			cout << "请输入新密码:" << endl;
			cin >> object.password[position];
			fresh();
			cout << "已成功修改密码" << endl;
		}
	}
	else if (input == "add()") {
		number++;
		object.number[number - 1] = number;
		cout << "请输入项目名称" << endl;
		cin >> object.name[number - 1];
		cout << "请输入用户名" << endl;
		cin >> object.account[number - 1];
		cout << "请输入密码" << endl;
		cin >> object.password[number - 1];
		fresh();
	}
	else if (input == "showall()") {
		cout << "总密码个数为" << number << endl;
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
				//cout << "用户名:" << b[i] << endl << "密码:" << c[i] << endl;
				f = 0;
			}//匹配成功
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
					cout << "账号:" << object.name[i] << endl << "用户名:" << object.account[i] << endl << "密码:" << object.password[i] << endl;
					break;
				}
				fl = true;
			}
		}
		if (f == 0) {
			cout << "抱歉，密码库暂未收集该数据，现在添加吗?(输入0可退出）" << endl;
			cin >> Num_2;
			if (Num_2 == "0") {
			}
			else {
				number++;
				object.number[number - 1] = number;
				cout << "请输入项目名称" << endl;
				cin >> object.name[number - 1];
				cout << "请输入用户名" << endl;
				cin >> object.account[number - 1];
				cout << "请输入密码" << endl;
				cin >> object.password[number - 1];
				fresh();
			}
		}
	}//补充密码库
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
		cout << "请输入密码解锁" << endl;
		cin >> input;
		if (input == password) {
			while (true) {
				cout << "请输入关键词" << endl;
				cin >> Name;//输入
				System(Name);
				search(Name);
				def = true;
				flag = "";
				position = -1;
			}
		}
		else {
			cout << "密码错误!请重新输入密码或按0退出程序" << endl;
			cin >> input;
			if (input == "0") {
				judge = false;
			}
		}
	}
	log(1);
	return 0;
}