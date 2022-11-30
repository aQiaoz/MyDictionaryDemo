/* stepgame_final.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
���룺GBK
���ߣ�����������𩡢����ϡ������
ʱ�䣺2022/7/22
*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <string>
#include <string.h>
#include <fstream>
#include <windows.h>
#include <numeric>
#include <sstream>
using namespace std;
/* ��Ϸ�г�:
            1.��Ϸ����
            2.������Ϸ��ֱ��չʾ��
            3.��Ϸ���--[1.fps�����Ϸ 2.moba��Ϸ  3.Act������Ϸ   4.����������Ϸ]
*/             

//===========================================Game��ָ���============================================================
int yxbh = 1;
int num = 1;
void color(int a) //��ɫ����
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
void showpicture(string st) //չʾͼƬ����������������Ҳ������ת����
{
	ifstream infile(st, ios::in); /*չʾͼƬ������*/
	if (!infile)
	{
		cout << "error";
	}
	char s;
	infile >> noskipws;
	while (infile >> s)
	{

		cout << s;
	}
	return;
}
class Game
{
	friend bool operator==(const Game &a, string b)
	{
		return a.name == b;
	}
	friend ostream &operator<<(ostream &out, Game &g);
	friend istream &operator>>(istream &in, Game &g);

public:
	Game(string n, string t, double p, string developname) : name(n), type(t), price(p), develop(developname)
	{
		amount = 0;
		n = num++;
		score = 0;
		log.push_back("markted");
		comment.push_back("newgame!");
		Score.push_back(10);
	} //�˹��캯������������Ϸ
	Game(int no, string n, string t, string developname, double p, double s, int a, vector<string> l, vector<string> writing, vector<int> sc) : name(n), type(t), price(p), develop(developname)
	{
		amount = a;
		n = num++;
		score = s;
		log.assign(l.begin(), l.end());
		comment.assign(writing.begin(), writing.end());
		Score.assign(sc.begin(), sc.end());
	}					//д��ʱ����
	void showcomment(); //չʾ���۵ȼ�(have)
	void showcom();		//չʾ��������(have)
	void showlog();		//չʾ��־(have)
	// void displaystock(); //չʾ��Ϸ�ڿ��(to be)
	//����Ϊ������get set���Եĺ���
	string gettype() { return type; }			 // get type
	string getname() { return name; }			 // get name
	double getprice() { return price; }			 // get price
	double getscore() { return score; }			 // get final score
	string getdevelop() { return develop; }		 // get develop name
	int getamount() { return amount; }			 // get amount
	void change_price(int p) { price = p; }		 // set price
	void setname(string newn) { name = newn; }	 // set name
	void settype(string newt) { type = newt; }	 // set type
	void setprice(double newp) { price = newp; } // set price
	void setscore(vector<int> S)				 // set score(��)
	{
		int sum = accumulate(Score.begin(), Score.end(), 0);
		score = double(sum) / Score.size();
	}
	void setScore(int point) { Score.push_back(point); }
	void setlog(string Log) { log.push_back(Log); }		   // set log
	void setremark(string com) { comment.push_back(com); } // set comment
	void setamount() { amount++; }						   //����ʱ���ô˺�����ʹ������1
	int getn()
	{
		return n;
	}
	vector<string> &getlog()
	{
		return log;
	}
	vector<string> &getcomment()
	{
		return comment;
	}
	vector<int> &getevescore()
	{
		return Score;
	}

protected:
	int n;
	string type, name, develop; //��Ϸ���࣬��Ϸ��������������
	double price, score;		//��Ϸ�۸���Ϸ����
	int amount;					//��Ϸ����
	map<string, double> stock;	//��Ϸ���
	vector<string> log;			//��������־
	vector<string> comment;		//��������
	vector<int> Score;			//ÿ���û���������
};
vector<Game> game; //ȫ�ֱ�����ȫ����Ϸ��
//����
void Game::showlog()
{
	cout << "**********************************��������־**************************************" << endl;
	for (int i = 0; i < log.size(); i++)
	{
		cout << log[i] << endl;
		cout << "*********************************************************************************" << endl;
	}
}
void Game::showcomment() //չʾ����
{
	if (Score.size() == 1)
	{
		cout << "��������";
		return;
	}
	int sum = accumulate(Score.begin(), Score.end(), 0);
	score = double(sum) / (Score.size() - 1);
	if (score >= 0 && score <= 20)
		cout << "�ر����";
	else if (score >= 20 && score < 40)
		cout << "������";
	else if (score >= 40 && score < 60)
		cout << "���᲻һ";
	else if (score >= 60 && score < 80)
		cout << "������";
	else if (score >= 80 && score <= 100)
		cout << "�ر����";
	return;
}
void Game::showcom()
{
	if (comment.size() > 1)
	{
		for (int i = 1; i < comment.size(); i++)
		{
			cout << setw(5) << i;
			cout << "*" << endl;
			cout << "*********************************************************************************" << endl;
			cout << "      *����:" << Score[i] << endl;
			cout << "      *     " << comment[i] << endl;
			cout << "********************************************************************************" << endl;
		}
	}
	else
		cout << "�������ۡ�";
	system("pause");
}
ostream &operator<<(ostream &out, Game &g)
{
	out << setiosflags(ios::left);
	out << setw(5) << "*"
		<< "|";
	out << setw(20) << g.name << setw(15) << g.type << setiosflags(ios::left) << setw(8) << g.price << setiosflags(ios::left)
		<< "|"
		<< "	���ۣ�" << g.amount << endl;
	return out;
}
/*=================================================�û���ָ���============================================================*/
//�û�
class User
{
	friend bool operator==(const User &a, string b)
	{
		return a.Account == b;
	}

private:
	string Account;			  //�˺�
	string Name;			  //�ǳ�
	string Passwords;		  //����
	vector<string> mine_game; //������Ϸ��
public:
	User(vector<string> minegame, string account = "", string passwords = "", string name = "") : Account(account), Passwords(passwords), Name(name)
	{
		mine_game.assign(minegame.begin(), minegame.end());
	} //Ĭ�Ϲ���
	User(string acc, string pass, string na)
	{
		Account = acc;
		Passwords = pass;
		Name = na;
		mine_game.push_back("hornpub");
	}
	void Comment(Game &g);			   //��������
	void buy_game(Game &x);			   //������Ϸ
	void change_inf();				   //�޸ĸ�����Ϣ
	void give_friend(User &a, Game x); //����
	//����Ϊ������set get����
	string getname() //��������																				//�����ǳ�
	{
		return Name;
	}
	string getaccount() //�����˺�
	{
		return Account;
	}
	void setname(string name) //�����ǳ�
	{
		Name = name;
	}
	void setaccount(string account) //�����˺�
	{
		Account = account;
	}
	void setpasswords(string passwords) //��������
	{
		Passwords = passwords;
	}
	string getpasswords() //��������
	{
		return Passwords;
	}
	vector<string> &getgames() //������Ϸ��
	{
		return mine_game;
	}
	void show()
	{
		cout << Name << "  your information:\n";
		cout << "account: " << Account << endl;
		cout << "Your game:\n";
		for (vector<string>::iterator it = mine_game.begin(); it != mine_game.end(); it++)
		{
			cout << (*it) << endl;
		}
		return;
	}
};
vector<User> accounts; //�����û�
void User::give_friend(User &a, Game x)
{
	a.buy_game(x);
	Sleep(2000);
}
void User::buy_game(Game &x) //��Ϸ����
{
	if (find(mine_game.begin(), mine_game.end(), x.getname()) != mine_game.end()) //�ж��Ƿ��Ѿ������
	{
		cout << "��ӵ�д���Ϸ,�����ظ�����!\n";
		Sleep(2000);
		return;
	}
	else //���û���
	{

		mine_game.push_back(x.getname()); //������Ϸ������
		x.setamount();
		cout << "����ɹ�,�������!\n";
		Sleep(2000);
		return;
	}
}
void User::Comment(Game &g)
{
	int point;
	string com;
	if (find(mine_game.begin(), mine_game.end(), g.getname()) != mine_game.end()) //�ж��Ƿ��Ѿ������
	{
		cout << "������������(0~10):";
		cin >> point;
		g.setScore(point);
		cout << "ϸ����Ϸ��";
		cin >> com;
		g.setremark(com);
		cout << "���۳ɹ�";
	}
	else
	{
		cout << "δӵ�д���Ϸ,���ܽ�������\n";
		cout << "You have not bought this game,you can't comment on it\n";
		return;
	}
	system("pause");
}
void User::change_inf()
{
	system("cls");
	cout << "********************************************************************\n";
	cout << "*****************Your personal information settings*****************\n";
	cout << "************************���ĸ�����Ϣ���ý���**************************\n";
	cout << "********************************************************************\n";
	while (1)
	{
		system("cls");
		cout << "\n(change your name)�����ǳ�[1]" << endl;
		cout << "\n(change your passwords)��������[2]" << endl;
		cout << "\nȡ������[3]";
		int choice;
		cout << "\n������ѡ��:";
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			cout << "***************�ǳ��޸Ľ���******************" << endl;
			cout << "(your old name)���ľ��ǳ�:   " << Name << endl;
			cout << "\n(please input your new name)��������Ҫ�������ǳ�:";
			string a;
			cin >> a;
			Name = a;
			cout << "\n(changing success!)�޸ĳɹ�!�������ǳ���:  " << a << endl;
			cout << "\n������ת�ظ��˽���\n";
			Sleep(1500);
			return;
		}
		else if (choice == 2)
		{
			cout << "***************�����޸Ľ���******************" << endl;
			string psnew; //������;
			cout << "���������ľ�������֤��ݻ�������N�˳�\n";
			while (1)
			{
				cin >> psnew;
				if (psnew == Passwords)
				{
					cout << "������ȷ";
					break;
				}
				else if (psnew == "N")
				{
					cout << "\n������ת�ظ��˽���\n";
					Sleep(1000);
					return;
				}
				else
				{
					cout << "�������,�����������ѡ���˳�������Ϣ�޸Ľ���" << endl;
					continue;
				}
			}
			string newps;
			cout << "(please input your new passwords)������������";
			cin >> newps;
			Passwords = newps;
			cout << "�޸ĳɹ���\n"
				 << endl;
			cout << "\n������ת�ظ��˽���\n";
			Sleep(1000);
			return;
		}
		else if (choice == 3)
		{
			cout << "�˳�!" << endl;
			cout << "\n������ת�ظ��˽���\n";
			Sleep(1000);
			return;
		}
		else
		{

			system("cls");
			showpicture("error.txt");
			cout << "\n���ڸ�ʲôѼ!!!QAQ" << endl;
			cout << "�������������ѡ���˳�" << endl;
			Sleep(3000);
			continue;
		}
	}
}
/*======================================��������ָ���=================================================*/

//������
class developer
{
	friend bool operator==(const developer &a, string b)
	{
		return a.Account == b;
	}

public:
	developer(vector<string> minegame, string account = "", string pw = "8888", string name = "") : Account(account), Passwords(pw), Name(name) //���캯��
	{
		mine_game.assign(minegame.begin(), minegame.end());
	}
	developer(string acco, string pass, string n)
	{
		Account = acco;
		Passwords = pass;
		Name = n;

		mine_game.push_back("tools");
	}
	void change_inf();	 //�޸ĸ�����Ϣ
	void change_price(); //������Ϸ�۸�
	void add_game();	 //������Ϸ
	void delete_game();	 //ɾ����Ϸ
	void Setlogs();		 //������־
	string getname()	 //��������																				//�����ǳ�
	{
		return Name;
	}
	string getaccount() //�����˺�
	{
		return Account;
	}
	string getpasswords() //��������
	{
		return Passwords;
	}
	void setname(string name) //�����ǳ�
	{
		Name = name;
	}
	void setaccount(string account) //�����˺�
	{
		Account = account;
	}
	void setpasswords(string passwords) //��������
	{
		Passwords = passwords;
	}
	vector<string> &getgames() //������Ϸ��
	{
		return mine_game;
	}
	void show()
	{
		cout << "************************************�����µ���Ϸ***********************************" << endl;
		for (vector<string>::iterator it = mine_game.begin(); it != mine_game.end(); it++)
		{
			cout << (*it) << endl;
		}
		cout << "*********************************************************************************" << endl;
		return;
	}

protected:
	string Account;			  //�˺�
	string Name;			  //�ǳ�
	string Passwords;		  //����
	vector<string> mine_game; //������Ϸ��
};
vector<developer> accounts_develop; //���п�����
void developer::change_inf()
{
	system("cls");
	cout << "**************************************\n";
	cout << "**Your personal information settings**\n";
	cout << "*********���ĸ�����Ϣ���ý���**********\n";
	cout << "**************************************\n";
	while (1)
	{
		system("cls");
		cout << "(change your name)�����ǳ�[1]" << endl;
		cout << "\n(change your passwords)��������[2]" << endl;
		cout << "\nȡ������[3]\n";
		int choice;
		cout << "������ѡ��:";
		cin >> choice;
		if (choice == 1)
		{
			cout << "***************�ǳ��޸Ľ���******************" << endl;
			cout << "(your old name)���ľ��ǳ�:   " << Name << endl;
			cout << "(please input your new name)��������Ҫ�������ǳ�:";
			string a;
			cin >> a;
			Name = a;
			cout << "(changing success!)�޸ĳɹ�!�������ǳ���:  " << a << endl;
			return;
		}
		else if (choice == 2)
		{
			cout << "***************�����޸Ľ���******************" << endl;
			string psnew; //������;
			cout << "�����������ľ�������֤��ݻ�������N�˳�\n";
			while (1)
			{
				cin >> psnew;
				if (psnew == Passwords && psnew != "N")
				{
					cout << "������ȷ";
					break;
				}
				else if (psnew == "N")
				{
					return;
				}
				else
				{
					cout << "�������,�����������ѡ���˳�������Ϣ�޸Ľ���" << endl;
					continue;
				}
			}
			string newps;
			cout << "(please input your new passwords)������������";
			cin >> newps;
			Passwords = newps;
			cout << "�޸ĳɹ�" << endl;
			return;
		}
		else if (choice == 3)
		{
			cout << "�˳�!" << endl;
			return;
		}
		else
		{
			system("cls");
			showpicture("error.txt");
			cout << "\n���ڸ�ʲôѼ!!!QAQ" << endl;
			cout << "�������������ѡ���˳�" << endl;
			Sleep(3000);
			continue;
		}
	}
	Sleep(3000);
}
void developer::change_price()
{
	string name;
	double price;
	vector<Game>::iterator result;
	cout << "\n\nEsc ��3����*********************************************************X.��0�˳�������" << endl;
	while (1)
	{
		cout << "������������ĵ���Ϸ������:";
		cin >> name;
		if (name == "3")
		{
			return;
		}
		result = find(game.begin(), game.end(), name);
		if (result == game.end())
		{
			cout << "���ڸ�ʲôѼ���������� �Ҳ�������Ϸ\n";
			cout << "���������룡\n";
			continue;
		}
		else
		{
			break;
		}
	}
	cout << "����Ϸ��Ϣ����:" << endl;
	cout << "*********************************************************************************" << endl;
	cout << (*result) << endl;
	cout << "*********************************************************************************" << endl;
	cout << endl;

	cout << "�����롶" << name << "�����¼۸�: ";
	cin >> price;
	result->change_price(price); //����Game����޸ļ۸���
	if (price == result->getprice())
	{
		cout << "��" << name << "��"
			 << "���ļ۸�ɹ�!" << endl;
	}
	cout << "����Ϸ���ĺ���Ϣ����:" << endl;
	cout << "*********************************************************************************" << endl;
	cout << (*result) << endl;
	cout << "*********************************************************************************" << endl;
	cout << endl;
	cout << "������Ϸ��������С���" << endl;
	Sleep(5000);

	//************���⣬����Ҫ�з��ؽ��棬��������
}
void developer::add_game() //������Ϸ
{
	string develop;
	string newname, newtype;
	double newprice;
	double newscore;
	cout << "*********************************************************************************" << endl;
	cout << "********************************�����봴���µ���Ϸ*********************************" << endl;
	cout << "�봴������Ϸ������:" << endl;
	cin >> newname;

	cout << "�봴������Ϸ�����:" << endl;
	cin >> newtype;

	cout << "�봴������Ϸ�ļ۸�:" << endl;
	cin >> newprice;
	Game Newgame(newname, newtype, newprice, Name);
	game.push_back(Newgame);
	mine_game.push_back(newname);
	cout << "��������Ϸ�ɹ�!" << endl;
	cout << Newgame << endl;
	cout << endl;
	cout << "������Ϸ��������С���" << endl;
	Sleep(5000);
}
void developer::delete_game() //ɾ����Ϸ
{
	string delete_name;
	cout << "��������Ҫɾ������Ϸ����:" << endl;
	cin >> delete_name;
	for (vector<Game>::iterator i = game.begin(); i != game.end(); ++i)
	{
		if (delete_name == i->getname())
		{
			game.erase(i);
			break;
		}
	}
	for (vector<string>::iterator j = mine_game.begin(); j != mine_game.end(); ++j) //��������Ϸ��ɾ��
	{
		if (delete_name == *j)
		{
			mine_game.erase(j);
			break;
		}
	}
	cout << "��" << delete_name << "��"
		 << "�ѳɹ�ɾ��" << endl;
	cout << endl;
	cout << "������Ϸ��������С���" << endl;
	Sleep(5000);
}
void developer::Setlogs() //������־
{
	string name;
	string newlog;
	bool x = true;

	vector<Game>::iterator result;
	cout << "\n\nEsc ��3����*********************************************************X.��0�˳�������" << endl;
	while (1)
	{
		cout << "������������ĵ���Ϸ������:";
		cin >> name;
		if (name == "3")
		{
			return;
		}
		result = find(game.begin(), game.end(), name);
		if (result == game.end())
		{
			cout << "���ڸ�ʲôѼ���������� �Ҳ�������Ϸ\n";
			cout << "���������룡\n";
			continue;
		}
		else
		{
			break;
		}
	}
	cout << "����Ϸ��Ϣ����:" << endl;
	cout << "*********************************************************************************" << endl;
	cout << (*result) << endl;
	cout << "*********************************************************************************" << endl;
	cout << "����Ϸ������־��Ϣ����:" << endl;
	result->showlog();
	cout << endl;
	cout << "�����롶" << name << "����������־: ";
	cin >> newlog;
	result->setlog(newlog);
	cout << "�ѳɹ�������־" << endl;
	cout << "����Ϸ������־��Ϣ����:" << endl;
	result->showlog();
	cout << endl;
	cout << "������Ϸ��������С���" << endl;
	Sleep(5000);
}

//=================================================��������ĺ���========================================
int getnum();							  //��ȡ��Ϸȫ�ֱ���������
void search(string searchname);			  //ȫ�ֺ������ѯ��Ϸ��
void displaytype(vector<Game> game);	  //չʾ��Ϸ����
void displayall_game(User &a);			  //�г�����
void displaybuy_game(Game &g, User &u);	  //������Ϸ���溯��
void displayall_user(User &u);			  //չʾ���˿��
bool checkaccount(string accounts_check); //�ж��Ƿ������˺�
void mainpage();						  //������
void userpage(User &a);					  //���˽������Ϸ�г�
void developerpage(developer &a);		  //������������
void developer_manage_page(developer &a); //�����߹�����Ϸ����
void usersetting(User &a);				  //�鿴����Լ��޸�
double str_num(string d);
int str_intnum(string f);
void build(string a, string b, string c, string d);		// readin�ĸ�������(�û�)
void readin_users();									//���û�txt�ļ����ݶ����
void write_out_users();									//���������û��Ŀ⵼��
void build_dev(string a, string b, string c, string d); // readin�ĸ�������(������)
void readin_developers();								//��������txt�ļ����ݶ����
void write_out_develops();								//�������п����ߵĿ⵼��
void bulid_game(string n, string a, string b, string c, string d,
				string e, string f, string g, string h, string k); // readin�ĸ�������(��Ϸ)
void readin_games();											   //����Ϸtxt�ļ����ݶ����
void write_out_game();											   //����������Ϸ�Ŀ⵼��
void Exit();													   //�˳�������
void Signin();													   //չʾ��Ϣ
void user_Sign_in();											   //�û���½
void developer_Sign_in();										   //�����ߵ�¼
bool whetherhave(User &u, Game &g);								   //�ж��û��Ƿ�ӵ����Ϸ
void Pos(int x, int y);											   //������λ��
User &ask_user(string acc);										   //�����˺ŷ��ض�Ӧ���û�������
developer &ask_developer(string acc);							   //�����˺ŷ��ض�Ӧ�Ŀ����ߵ�����
Game &ask_game(string acc);										   //�����˺ŷ��ض�Ӧ����Ϸ������
void errorpage()												   //�����������չʾ
{
	showpicture("success1.txt");
	Sleep(1000);
	system("cls");
	showpicture("success.txt");
	Sleep(1000);
	system("cls");
	showpicture("success2.txt");
}
//=========================================game��ȫ�ֺ����ָ���==========================================

int getnum()
{
	return game.size();
}
//������Ϸ
void search(string searchname)
{
	vector<Game>::iterator g = game.begin();
	vector<Game>::iterator findname = find(game.begin(), game.end(), searchname);
	if (findname == game.end())
	{
		cout << "�̳������޴���Ϸ" << endl;
	}
	else
	{
		cout << "���ҵ�����Ϸ��\n";
		cout << *(findname);
	}
}
//�г�����
void displayall_game(User &a)
{
	system("cls");
	vector<Game>::iterator g;
	cout << "Esc.��3�����ϼ�                                                      X.��0�˳�������" << endl;
	cout << "**********************************������Ϸ***************************************" << endl;
	cout << "*    |��Ϸ��              ��Ϸ����       �۸�    |      ���۳�\n"
		 << endl;
	for (g = game.begin(); g != game.end(); g++)
	{
		cout << (*g) << endl;
	}
	cout << "��ѡ����Ҫ�鿴����Ϸ����(������Ϸ����):";
	string choice;
	while (1)
	{
		cin >> choice;
		if (choice == "B")
		{
			displayall_game(a);
		}
		if (choice == "0")
		{
			Exit();
		}
		if (choice == "3")
		{
			userpage(a);
		}
		vector<Game>::iterator it = find(game.begin(), game.end(), choice);
		if (it == game.end())
		{
			cout << "��������ʲô��������������������������\n";
			cout << "���������������������B�����г�\n";
			cout << "���ѡ��: ";
		}
		else
		{
			system("cls");
			cout << "������ת�� ��" << choice << "�� �Ľ���.....\n";
			Sleep(2000);
			displaybuy_game(ask_game(choice), a);
		}
	}
}
//չʾ���˿��
void displayall_user(User &u)
{
	vector<Game>::iterator g;
	cout << "*********************************************************************************" << endl;
	cout << u.getname() << "  ������Ϸ�������:\n";

	for (g = game.begin(); g != game.end(); g++)
	{
		if (!whetherhave(u, (*g)))
		{
			cout << (*g);
		}
	}
	Sleep(5000);
	system("pause");
	usersetting(u);
}
bool whetherhave(User &u, Game &g)
{
	if (find(u.getgames().begin(), u.getgames().end(), g.getname()) == u.getgames().end()) //�ж��Ƿ��Ѿ������
	{
		return true;
	}
	return false;
}
//���������Ϸ�����չʾ�������ۣ�������ɾ�˴�����
void displaybuy_game(Game &g, User &u) //������Ϸ���溯��
{
	system("cls");
	if (g.getname() == "csgo")
	{
		showpicture("csgo.txt");
		Sleep(1000);
	}
	if (g.getname() == "League_Of_Legends")
	{
		showpicture("LOL.txt");
		Sleep(1000);
	}
	if (g.getname() == "������ϰ��")
	{
		showpicture("kunkun.txt");
		Sleep(1000);
	}
	if (g.getname() == "�����͸���սʿ")
	{
		showpicture("Eva.txt");
		Sleep(1000);
	}
	if (g.getname() == "hornpub")
	{
		showpicture("hornpub.txt");
		Sleep(1000);
	}
	system("cls");
	int choice;
	string given;
	cout << "                                                                   X.��0�˳�������" << endl;
	cout << "*********************************************************************************" << endl;
	cout << "|" << setw(5) << "��Ϸ��:"
		 << "��" << g.getname() << "��\n"
		 << setw(5) << "������:" << setw(10) << g.getdevelop() << "|\n";
	cout << "*********************************************************************************" << endl;
	g.showcomment();
	if (!whetherhave(u, g))
	{
		cout << endl
			 << "******************************>>>>����Ϸ���ڿ���<<<<*****************************" << endl;
		cout << "*********************************************************************************" << endl;
	}
	cout << endl;
	cout << "                            *******[��ѡ����Ĳ���]*******\n";
	cout << "                            *      [1]�������Ϸ         *" << endl;
	cout << "                            *      [2]���ͺ��Ѵ���Ϸ     *" << endl;
	cout << "                            *      [3]�鿴������         *" << endl;
	cout << "                            *      [4]������Ϸ�г�       *" << endl;
	cout << "                                     ������ѡ��:";
	cin >> choice;
	switch (choice)
	{
	case 0:
		Exit();
		break;
	case 1:
		u.buy_game(g);
		cout << "������Ϸ������..." << endl;
		system("cls");
		displaybuy_game(g, u);
		break;
	case 2:
	{
		cout << "��Ҫ������Ϸ���͸�(�������˺�):";
		cin >> given;
		if (!checkaccount(given))
		{
			u.give_friend(ask_user(given), g);
			showpicture("thanks.txt");
			cout << ask_user(given).getname() << "��ʾзз����" << endl;
			cout << "������ɣ�������Ϸ��������.....";
			Sleep(3000);
			displaybuy_game(g, u);
		}
		else
		{
			cout << "���޴���!������Ϸ�����棡.......\n";
			Sleep(2000);
			displaybuy_game(g, u);
		}
	}
	break;

	case 3:
	{
		cout << "\n\n";
		cout << "                            *******[��ѡ����Ĳ���]*******\n";
		cout << "                            *      [1]�鿴��������         *" << endl;
		cout << "                            *      [2]��������             *" << endl;
		cout << "                            *      [3]������һ��           *" << endl;
		cout << "                                    ������ѡ��:";
		int choice1;
		cin >> choice1;
		switch (choice1)
		{
		case 0:
			Exit();
			break;
		case 1:
			g.showcom();
			cout << "������Ϸ����..." << endl;
			Sleep(2000);

			displaybuy_game(g, u);
			break;
		case 2:
			u.Comment(g);
			cout << "������Ϸ����...." << endl;
			Sleep(2000);

		case 3:
			displaybuy_game(g, u);
		}
		break;
	}
	case 4:
		displayall_game(u);
		break;
	default:
		cout << "��������,������Ϸ������.... ";
		Sleep(2000);
		displaybuy_game(g, u);
	}
}
//============================================�ָ���====================================================

//�ж��Ƿ������˺�
bool checkaccount(string accounts_check) //�ж��û���
{
	vector<User>::iterator findaccount = find(accounts.begin(), accounts.end(), accounts_check);
	if (findaccount != accounts.end()) //����ҵ��ˣ����Ѵ���
	{
		return false;
	}
	return true; //û�ҵ�
}
bool checkaccount_developer(string accounts_check)
{
	vector<developer>::iterator findaccount = find(accounts_develop.begin(), accounts_develop.end(), accounts_check);
	if (findaccount != accounts_develop.end()) //����ҵ��ˣ����Ѵ���
	{
		return false;
	}
	return true; //û�ҵ�
}
User &ask_user(string acc)
{
	vector<User>::iterator it = find(accounts.begin(), accounts.end(), acc);
	return *it;
}
developer &ask_developer(string acc) //�����˺ŷ��ض�Ӧ�Ŀ����ߵ�����
{
	vector<developer>::iterator it = find(accounts_develop.begin(), accounts_develop.end(), acc);
	return *it;
}
Game &ask_game(string acc) //�����˺ŷ��ض�Ӧ����Ϸ������
{
	vector<Game>::iterator it = find(game.begin(), game.end(), acc);
	return *it;
}
//========================================�������ָ���===================================================
void Pos(int x, int y) //���
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void mainpage() //������
{
	//����������
	system("cls");
	char choice1;
	cout << "                                                                                                  X.��0�˳�������" << endl;
	cout << "                                     **************************��ӭ��½stepgame��Ϸƽ̨***************************\n"
		 << endl;
	ifstream infile("mainpage.txt", ios::in); /*չʾͼƬ������*/
	if (!infile)
	{
		cout << "error";
	}
	char s;
	infile >> noskipws;
	while (infile >> s)
	{
		color(3);
		cout << s;
	}
	Sleep(1500);
	color(15);
	cout << setw(10) << "\n��ѡ���Ƿ��������˳�����(Y/N)";
	cin >> choice1;
	switch (choice1)
	{
	case 'y':
		system("cls");
		cout << "������....";
		Sleep(1000);
		Signin();
		break;
	case 'Y':
		system("cls");
		cout << "������....";
		Sleep(1000);
		Signin();
		break;
	case 'n':
		Exit();
		break;
	case 'N':
		Exit();
		break;
	case '0':
		Exit();
		break;
	default:
		cout << "Error!����������";
		Sleep(1000);
		mainpage();
		break;
	}
}
void Signin() //չʾ��Ϣ
{
	system("cls");
	cout << "��ӭ�ؼң�ŷ�ὴ������������������" << endl;
	showpicture("biubiu.txt");
	Sleep(2500);
	system("cls");
	int choice2;
	cout << "                                                              X.��0�˳�������" << endl;
	cout << "****************************��ѡ��ע����ߵ�¼*******************************" << endl;
	cout << "************                   *************                 *************" << endl;
	cout << "*  1.ע��  *                    *  2.��¼  *                  *  3.����  *" << endl;
	cout << "************                   *************                 *************" << endl;
	cout << "                                  _______                                   " << endl;
	cout << "                                 |       |                                  " << endl;
	cout << "                                 |       |                                  " << endl;
	cout << "                                 |_______|                                  " << endl; //�˴���������
	Pos(36, 7);
	cin >> choice2;
	if (choice2 == 0)
	{
		Exit();
	}
	else if (choice2 == 3)
	{
		system("cls");
		mainpage();
	}
	else if (choice2 == 1)
	{
		system("cls");
		cout << "                                                              X.��0�˳�������" << endl;
		cout << "****************************��ѡ�񿪷��߻��û�ע��*******************************" << endl;
		cout << "************                     **************                  *************" << endl;
		cout << "*  1.�û�  *                      *  2.������  *                  *  3.����  *" << endl;
		cout << "************                     **************                  *************" << endl;
		cout << "                                  _______                                   " << endl;
		cout << "                                 |       |                                  " << endl;
		cout << "                                 |       |                                  " << endl;
		cout << "                                 |_______|                                  " << endl; //�˴���������
		int choice5;
		Pos(36, 8);
		cin >> choice5;
		if (choice5 == 1)
		{
			system("cls");
			string new_name, new_account, new_password;
			cout << "�������ǳƣ�" << endl;
			cin >> new_name;
			cout << "\n�������˻���" << endl;
			cin >> new_account;
			cout << "\n���������룺" << endl;
			cin >> new_password;
			Sleep(1000);
			if (!checkaccount(new_account))
			{
				system("cls");
				cout << "�˺��Ѵ��ڣ�ע��ʧ�ܣ�3�뷵�ص�½/ע�����" << endl;
				errorpage();
			}
			else
			{
				accounts.push_back(User(new_account, new_password, new_name));
				cout << "ע��ɹ�!3�����ת����½/ע�����  ��Ϊ���������˸���:��hornpub��" << endl;
				showpicture("error.txt");
				cout << "\n";
				cout << "                       �ⶼ����������ɹ�!?\n";
				cout << "                       �ⶼ����������ɹ�!?\n";
				cout << "                       �ⶼ����������ɹ�!?\n";
			}
			Sleep(3000);
			system("cls");
			Signin();
		}
		else if (choice5 == 2)
		{
			system("cls");
			string new_name, new_account, new_password;
			cout << "�������ǳƣ�" << endl;
			cin >> new_name;
			cout << "\n�������˻���" << endl;
			cin >> new_account;
			cout << "\n���������룺" << endl;
			cin >> new_password;
			Sleep(1000);
			if (!checkaccount_developer(new_account))
			{
				system("cls");
				cout << "�˺��Ѵ��ڣ�ע��ʧ�ܣ�3�뷵�ص�½/ע�����" << endl;
				errorpage();
			}
			else
			{
				accounts_develop.push_back(developer(new_account, new_password, new_name));
				cout << "ע��ɹ�!3�����ת����½/ע�����,��Ϊ�����Ż��������߹��߸���:tools" << endl;
				showpicture("error.txt");
				cout << "\n";
				cout << "                       �ⶼ����������ɹ�!?\n";
				cout << "                       �ⶼ����������ɹ�!?\n";
				cout << "                       �ⶼ����������ɹ�!?\n";
			}
			Sleep(3000);
			system("cls");
			Signin();
		}
		else if (choice5 == 3)
		{
			Signin();
		}
		else if (choice5 == 0)
		{
			Exit();
		}
		else
		{
			Signin();
		}
	}
	else if (choice2 == 2)
	{
		system("cls");
		cout << "                                                              X.��0�˳�������" << endl;
		cout << "****************************��ѡ�񿪷��߻��û���¼*******************************" << endl;
		cout << "************                     **************                  ***********" << endl;
		cout << "*  1.�û�  *                      *  2.������  *                  *  3.����  *" << endl;
		cout << "************                     **************                  ************" << endl;
		cout << "                                  _______                   " << endl;
		cout << "                                 |       |                  " << endl;
		cout << "                                 |       |                  " << endl;
		cout << "                                 |_______|                  " << endl; //�˴���������
		int choice6;
		Pos(36, 8);
		cin >> choice6;
		if (choice6 == 1)
		{
			user_Sign_in();
		}
		else if (choice6 == 2)
		{
			developer_Sign_in();
		}
		else if (choice6 == 3)
		{
			Signin();
		}
		else if (choice6 == 0)
		{
			Exit();
		}
		else
		{
			Signin();
		}
	}
	else
	{
		cout << "Error! 1���Ϊ�㷵��ԭ����";
		Sleep(1000);
		system("cls");
		Signin();
	}
}
void userpage(User &a) //���˽������Ϸ�г�
{
	system("cls");
	int choice3;
	cout << "                                                 X.��0�˳�������" << endl;
	cout << "*****************************��ӭ******************************" << endl;
	cout << "**************            **************          ***********" << endl;
	cout << "* 1.���˽���  *            * 2.��Ϸ�г�  *          * 3. ����  *" << endl;
	cout << "**************            **************          ***********" << endl;
	cout << "                           ________                         " << endl;
	cout << "                          |        |                        " << endl;
	cout << "                          |        |                        " << endl;
	cout << "                          |________|                        " << endl;
	Pos(32, 8);
	cin >> choice3;
	if (choice3 == 0)
	{
		Exit();
	}
	else if (choice3 == 3)
	{
		Signin();
	}
	else if (choice3 == 1)
	{
		usersetting(a);
	}
	else if (choice3 == 2)
	{
		displayall_game(a);
	}
	else
	{
		cout << "Error! 1���Ϊ�㷵��ԭ����";
		Sleep(1000);
		system("cls");
		userpage(a);
	}
	userpage(a);
}
void usersetting(User &a) //�鿴����Լ��޸�
{
	system("cls");
	int choice4;
	cout << "                                                X.��0�˳�������" << endl;
	cout << "*****************************��ӭ*****************************" << endl;
	cout << "***********            ****************           ***********" << endl;
	cout << "* 1.���  *            * 2.������Ϣ�޸� *           * 3. ���� *" << endl;
	cout << "***********            ****************           ***********" << endl;
	cout << "                           ________                         " << endl;
	cout << "                          |        |                        " << endl;
	cout << "                          |        |                        " << endl;
	cout << "                          |________|                        " << endl;
	Pos(30, 7);
	cin >> choice4;
	if (choice4 == 0)
	{
		Exit();
	}
	else if (choice4 == 3)
	{
		userpage(a);
	}
	else if (choice4 == 1)
	{
		system("cls");
		cout << "������ת..." << endl;
		Sleep(1000);
		displayall_user(a);
	}
	else if (choice4 == 2)
	{
		a.change_inf();
		usersetting(a);
	}
	else
	{
		cout << "error! 1���Ϊ�㷵��ԭ���档";
		Sleep(1000);
		usersetting(a);
	}
	cout << "wtclmqiaottc" << endl;
	Sleep(50000);
}
void developer_manage_page(developer &a) //�����߹�����Ϸ����
{
	int choice7;
	system("cls");
	cout << "                                                                                          X.��0�˳�������" << endl;
	cout << "**************************************��ӭ�����߽�����Ϸ�������*******************************************" << endl;
	cout << "**************        *****************     ******************      *******************     ***************" << endl;
	cout << "* 1.������Ϸ  *       * 2.ɾ����Ϸ    *      *  3.�޸���Ϸ�۸�  *      *  4. ������־    *     *   5. ����    *" << endl;
	cout << "**************        *****************     ******************      *******************     ***************" << endl;
	cout << "                                              ________                         " << endl;
	cout << "                                             |        |                        " << endl;
	cout << "                                             |        |                        " << endl;
	cout << "                                             |________|                        " << endl;
	Pos(50, 7);
	cin >> choice7;
	if (choice7 == 0)
	{
		Exit();
	}
	else if (choice7 == 5)
	{
		developerpage(a);
	}
	else if (choice7 == 1)
	{
		system("cls");
		a.show();
		a.add_game();
		developer_manage_page(a);
	}
	else if (choice7 == 2)
	{
		system("cls");
		a.show();
		a.delete_game();
		developer_manage_page(a);
	}
	else if (choice7 == 3)
	{
		system("cls");
		a.show();
		a.change_price();
		developer_manage_page(a);
	}
	else if (choice7 == 4)
	{
		system("cls");
		a.show();
		a.Setlogs();
		developer_manage_page(a);
	}
	else
	{
		cout << "error!1���Ϊ������ԭ���档" << endl;
		Sleep(1000);
		system("cls");
		developer_manage_page(a);
	}
}
void developerpage(developer &a) //������ҳ��
{
	system("cls");
	int choice5;
	cout << "                                                     X.��0�˳�������" << endl;
	cout << "***********************��ӭ���뿪���߽���*************************" << endl;
	cout << "**************             *****************          ***********" << endl;
	cout << "* 1.��Ϸ����  *             * 2.������Ϣ�޸� *           * 3. ���� *" << endl;
	cout << "**************             *****************          ***********" << endl;
	cout << "                           ________                         " << endl;
	cout << "                          |        |                        " << endl;
	cout << "                          |        |                        " << endl;
	cout << "                          |________|                        " << endl;
	Pos(32, 8);
	cin >> choice5;
	if (choice5 == 0)
	{
		Exit();
	}
	if (choice5 == 3)
	{
		Signin();
	}
	switch (choice5)
	{
	case 1:
	{
		developer_manage_page(a);
	}
	break;
	case 2:
	{
		a.change_inf();
		cout << "�������,������������...";
		Sleep(2000);
		developerpage(a);
	}
	break;
	default:
		cout << "error!1���Ϊ������ԭ���档" << endl;
		Sleep(1000);
		system("cls");
		developerpage(a);
		break;
	}
}
void user_Sign_in() //�û���½
{
	system("cls");
	string used_useraccount, used_userpassword;
	cout << "�������˺ţ�" << endl;
	cin >> used_useraccount;
	if (checkaccount(used_useraccount))
	{
		cout << "��¼ʧ�ܣ��˺Ų�����\n������ת��������..." << endl;
		Sleep(1000);
		system("cls");
		Signin();
	}
	cout << "\n���������룺" << endl;
	cin >> used_userpassword;
	if (used_userpassword == ask_user(used_useraccount).getpasswords())
	{
		system("cls");
		cout << "��¼�ɹ�\n������ת..." << endl;
		showpicture("error.txt");
		cout << "\n";
		cout << "                       �ⶼ����������ɹ�!?\n";
		cout << "                       �ⶼ����������ɹ�!?\n";
		cout << "                       �ⶼ����������ɹ�!?\n";
		//ͣ��ʱ��
		Sleep(1500);
		//��������
		system("cls");
		//���˽������Ϸ�г�
		userpage(ask_user(used_useraccount)); // 1.���˽���2.��Ϸ�г�3.����
	}
	else
	{
		system("cls");
		cout << "������󣬷���������!...";
		errorpage();
		Sleep(1500);
		Signin();
	}
}
void developer_Sign_in() //�����ߵ�¼
{
	system("cls");
	string used_useraccount, used_userpassword;
	cout << "�������˺ţ�" << endl;
	cin >> used_useraccount;
	if (checkaccount_developer(used_useraccount))
	{
		cout << "��¼ʧ�ܣ��˺Ų�����\n������ת��������..." << endl;
		Sleep(1000);
		system("cls");
		Signin();
	}
	cout << "\n���������룺" << endl;
	cin >> used_userpassword;
	if (used_userpassword == ask_developer(used_useraccount).getpasswords())
	{
		system("cls");
		cout << "��¼�ɹ�\n������ת..." << endl;
		//ͣ��ʱ��
		showpicture("error.txt");
		cout << "\n";
		cout << "                       �ⶼ����������ɹ�!?\n";
		cout << "                       �ⶼ����������ɹ�!?\n";
		cout << "                       �ⶼ����������ɹ�!?\n";
		Sleep(1500);
		//��������
		system("cls");
		//���˽������Ϸ�г�
		developerpage(ask_developer(used_useraccount)); // 1.���˽���2.��Ϸ�г�3.����
	}
	else
	{
		system("cls");
		cout << "������󣬷���������!...";
		errorpage();
		Sleep(1500);
		Signin();
	}
}
// user�������������===================================================================================
void build(string a, string b, string c, string d) // readin�ĸ�������
{
	vector<string> newaccount_games; //
	string newgames;
	for (int i = 0; i < d.size(); i++) // d�ǿ��ո�ָ���������Ϸ�����ַ���
	{
		if (d[i] == ' ')
		{
			newaccount_games.push_back(newgames);
			newgames.clear();
			continue;
		}
		newgames.push_back(d[i]);
	}
	accounts.push_back(User(newaccount_games, a, c, b));
	return;
}
void readin_users() //���û�txt�ļ����ݶ����
{
	fstream user("users.txt");
	if (!user) //�ļ������ڣ���Ȼ�ļ�һ������
	{
		exit(1);
	}
	string temp[4];
	int i = 0;
	while (getline(user, temp[i++]))
	{
		if (i == 4)
		{
			build(temp[0], temp[1], temp[2], temp[3]);
			i = 0;
		}
	}
	return;
}
void write_out_users() //���������û��Ŀ⵼��
{
	fstream user("users.txt");
	if (!user) //�ļ������ڣ���Ȼ�ļ�һ������
	{
		exit(1);
	}
	string a(" ");	//�ո�
	string b("\n"); //����
	vector<User>::iterator it;
	for (it = accounts.begin(); it != accounts.end(); it++)
	{
		user << ((*it).getaccount() + b);
		user << ((*it).getname() + b);
		user << ((*it).getpasswords() + b);
		for (vector<string>::iterator it1 = (*it).getgames().begin(); it1 != (*it).getgames().end(); it1++)
		{
			user << ((*it1) + a);
		}
		user << b;
	}
	return;
}
// developer�����ݶ����뱣��==============================================================================
void build_dev(string a, string b, string c, string d) // readin�ĸ�������
{
	vector<string> newaccount_games; //
	string newgames;
	for (int i = 0; i < d.size(); i++) // d�ǿ��ո�ָ���������Ϸ�����ַ���
	{
		if (d[i] == ' ')
		{
			newaccount_games.push_back(newgames);
			newgames.clear();
			continue;
		}
		newgames.push_back(d[i]);
	}
	accounts_develop.push_back(developer(newaccount_games, a, c, b));
	return;
}
void readin_developers() //��txt�ļ����ݶ����
{
	fstream develop("developers.txt");
	if (!develop) //�ļ������ڣ���Ȼ�ļ�һ������
	{
		exit(1);
	}
	string temp[4];
	int i = 0;
	while (getline(develop, temp[i++]))
	{
		if (i == 4)
		{
			build_dev(temp[0], temp[1], temp[2], temp[3]);
			i = 0;
		}
	}
	return;
}
void write_out_develops() //�������еĿ�д������
{
	fstream develop("developers.txt");
	if (!develop) //�ļ������ڣ���Ȼ�ļ�һ������
	{
		exit(1);
	}
	string a(" ");	//�ո�
	string b("\n"); //����
	vector<developer>::iterator it;
	for (it = accounts_develop.begin(); it != accounts_develop.end(); it++)
	{
		develop << ((*it).getaccount() + b);
		develop << ((*it).getname() + b);
		develop << ((*it).getpasswords() + b);
		for (vector<string>::iterator it1 = (*it).getgames().begin(); it1 != (*it).getgames().end(); it1++)
		{
			develop << ((*it1) + a);
		}
		develop << b;
	}
	return;
}
// game�����ݶ����뱣��===================================================================================
double str_num(string d)
{
	stringstream ss;
	double price1 = 0;
	ss << d;
	ss >> price1;
	return price1;
}
int str_intnum(string f)
{
	int sum = 0;
	stringstream ss;
	ss << f;
	ss >> sum;
	return sum;
}
void bulid_game(string n, string a, string b, string c, string d,
				string e, string f, string g, string h, string k)
{
	vector<string> log;
	string temp;
	for (int i = 0; i < g.size(); i++)
	{
		if (g[i] == ' ')
		{
			log.push_back(temp);
			temp.clear();
			continue;
		}
		temp.push_back(g[i]);
	}
	temp.clear();
	vector<string>
		yhpj;
	for (int i = 0; i < h.size(); i++)
	{
		if (h[i] == ' ')
		{
			yhpj.push_back(temp);
			temp.clear();
			continue;
		}
		temp.push_back(h[i]);
	}
	temp.clear();
	vector<int> yhpf;
	for (int i = 0; i < k.size(); i++)
	{
		if (k[i] == ' ')
		{
			yhpf.push_back(str_intnum(temp));
			temp.clear();
			continue;
		}
		temp.push_back(k[i]);
	}
	game.push_back(Game(str_intnum(n), a, b, c, str_num(d), str_num(e), str_intnum(f), log, yhpj, yhpf));
}
void readin_games()
{
	fstream qaq("games.txt");
	if (!qaq)
	{
		exit(1);
	}
	string temp[10];
	int i = 0;
	while (getline(qaq, temp[i++]))
	{
		if (i == 10)
		{
			bulid_game(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9]);
			i = 0;
		}
	}
}
void write_out_game()
{
	fstream qaq("games.txt");
	if (!qaq)
	{
		exit(1);
	}
	vector<Game>::iterator it;
	string a(" ");
	string b("\n");
	int i = 1;
	for (it = game.begin(); it != game.end(); it++)
	{
		qaq << i++ << b;
		qaq << ((*it).getname() + b);
		qaq << ((*it).gettype() + b);
		qaq << ((*it).getdevelop() + b);
		qaq << ((*it).getprice()) << b;
		qaq << ((*it).getscore()) << b;
		qaq << ((*it).getamount()) << b;
		for (vector<string>::iterator i = (*it).getlog().begin(); i != (*it).getlog().end(); i++)
		{
			qaq << ((*i) + a);
		}
		qaq << b;
		for (vector<string>::iterator i = (*it).getcomment().begin(); i != (*it).getcomment().end(); i++)
		{
			qaq << ((*i) + a);
		}
		qaq << b;
		for (vector<int>::iterator i = (*it).getevescore().begin(); i != (*it).getevescore().end(); i++)
		{
			qaq << (*i) << a;
		}
		qaq << b;
	}
	return;
}
void Exit() //�˳�����exit
{
	int w = 6;
	int l = 5;
	int t = 10;
	int h = 11;
	write_out_users();
	write_out_develops();
	write_out_game();
	system("cls");
	showpicture("bye.txt");
	color(w);
	cout << "                                    �ǵû���Ŷ~������С�������" << endl;
	color(h);
	cout << "                                    �ǵû���Ŷ~������qiao������" << endl;
	color(l);
	cout << "                                    �ǵû���Ŷ~���������к�����" << endl;
	color(t);
	cout << "                                    �ǵû���Ŷ~������ ��c������" << endl;

	Sleep(4000);
	exit(0);
}
//=======================================================================================================
int main()
{
	readin_developers();
	readin_users();
	readin_games();
	mainpage();
}

/*
���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
 ���Գ���: F5 ����� >����ʼ���ԡ��˵�

 ����ʹ�ü���:
   1. ʹ�ý��������Դ�������������/�����ļ�
   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
   3. ʹ��������ڲ鿴���������������Ϣ
   4. ʹ�ô����б��ڲ鿴����
   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
*/  

