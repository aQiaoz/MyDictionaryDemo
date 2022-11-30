/* stepgame_final.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编码：GBK
作者：李明、何琪皓、汤天诚、王天驰
时间：2022/7/22
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
/* 游戏市场:
            1.游戏搜索
            2.所有游戏（直接展示）
            3.游戏类别--[1.fps射击游戏 2.moba游戏  3.Act动作游戏   4.益智休闲游戏]
*/             

//===========================================Game类分割线============================================================
int yxbh = 1;
int num = 1;
void color(int a) //颜色更改
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
void showpicture(string st) //展示图片函数，不会清屏，也不含跳转界面
{
	ifstream infile(st, ios::in); /*展示图片并清屏*/
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
	} //此构造函数用于新增游戏
	Game(int no, string n, string t, string developname, double p, double s, int a, vector<string> l, vector<string> writing, vector<int> sc) : name(n), type(t), price(p), develop(developname)
	{
		amount = a;
		n = num++;
		score = s;
		log.assign(l.begin(), l.end());
		comment.assign(writing.begin(), writing.end());
		Score.assign(sc.begin(), sc.end());
	}					//写入时调用
	void showcomment(); //展示评价等级(have)
	void showcom();		//展示具体评论(have)
	void showlog();		//展示日志(have)
	// void displaystock(); //展示游戏内库存(to be)
	//以下为基础的get set属性的函数
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
	void setscore(vector<int> S)				 // set score(总)
	{
		int sum = accumulate(Score.begin(), Score.end(), 0);
		score = double(sum) / Score.size();
	}
	void setScore(int point) { Score.push_back(point); }
	void setlog(string Log) { log.push_back(Log); }		   // set log
	void setremark(string com) { comment.push_back(com); } // set comment
	void setamount() { amount++; }						   //购买时调用此函数，使销量加1
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
	string type, name, develop; //游戏种类，游戏名，开发者名字
	double price, score;		//游戏价格，游戏评分
	int amount;					//游戏销量
	map<string, double> stock;	//游戏库存
	vector<string> log;			//开发者日志
	vector<string> comment;		//文字评价
	vector<int> Score;			//每个用户单独评分
};
vector<Game> game; //全局变量，全体游戏库
//待定
void Game::showlog()
{
	cout << "**********************************开发者日志**************************************" << endl;
	for (int i = 0; i < log.size(); i++)
	{
		cout << log[i] << endl;
		cout << "*********************************************************************************" << endl;
	}
}
void Game::showcomment() //展示评级
{
	if (Score.size() == 1)
	{
		cout << "暂无评级";
		return;
	}
	int sum = accumulate(Score.begin(), Score.end(), 0);
	score = double(sum) / (Score.size() - 1);
	if (score >= 0 && score <= 20)
		cout << "特别差评";
	else if (score >= 20 && score < 40)
		cout << "多半差评";
	else if (score >= 40 && score < 60)
		cout << "褒贬不一";
	else if (score >= 60 && score < 80)
		cout << "多半好评";
	else if (score >= 80 && score <= 100)
		cout << "特别好评";
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
			cout << "      *评分:" << Score[i] << endl;
			cout << "      *     " << comment[i] << endl;
			cout << "********************************************************************************" << endl;
		}
	}
	else
		cout << "暂无评价。";
	system("pause");
}
ostream &operator<<(ostream &out, Game &g)
{
	out << setiosflags(ios::left);
	out << setw(5) << "*"
		<< "|";
	out << setw(20) << g.name << setw(15) << g.type << setiosflags(ios::left) << setw(8) << g.price << setiosflags(ios::left)
		<< "|"
		<< "	已售：" << g.amount << endl;
	return out;
}
/*=================================================用户类分割线============================================================*/
//用户
class User
{
	friend bool operator==(const User &a, string b)
	{
		return a.Account == b;
	}

private:
	string Account;			  //账号
	string Name;			  //昵称
	string Passwords;		  //密码
	vector<string> mine_game; //名下游戏库
public:
	User(vector<string> minegame, string account = "", string passwords = "", string name = "") : Account(account), Passwords(passwords), Name(name)
	{
		mine_game.assign(minegame.begin(), minegame.end());
	} //默认构造
	User(string acc, string pass, string na)
	{
		Account = acc;
		Passwords = pass;
		Name = na;
		mine_game.push_back("hornpub");
	}
	void Comment(Game &g);			   //进行评论
	void buy_game(Game &x);			   //购买游戏
	void change_inf();				   //修改个人信息
	void give_friend(User &a, Game x); //赠送
	//以下为基础的set get函数
	string getname() //返回名字																				//返回昵称
	{
		return Name;
	}
	string getaccount() //返回账号
	{
		return Account;
	}
	void setname(string name) //设置昵称
	{
		Name = name;
	}
	void setaccount(string account) //设置账号
	{
		Account = account;
	}
	void setpasswords(string passwords) //设置密码
	{
		Passwords = passwords;
	}
	string getpasswords() //返回密码
	{
		return Passwords;
	}
	vector<string> &getgames() //返回游戏库
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
vector<User> accounts; //已有用户
void User::give_friend(User &a, Game x)
{
	a.buy_game(x);
	Sleep(2000);
}
void User::buy_game(Game &x) //游戏购买
{
	if (find(mine_game.begin(), mine_game.end(), x.getname()) != mine_game.end()) //判断是否已经买过了
	{
		cout << "已拥有此游戏,不能重复购买!\n";
		Sleep(2000);
		return;
	}
	else //如果没买过
	{

		mine_game.push_back(x.getname()); //讲此游戏推入库存
		x.setamount();
		cout << "购买成功,游玩愉快!\n";
		Sleep(2000);
		return;
	}
}
void User::Comment(Game &g)
{
	int point;
	string com;
	if (find(mine_game.begin(), mine_game.end(), g.getname()) != mine_game.end()) //判断是否已经买过了
	{
		cout << "请给出你的评分(0~10):";
		cin >> point;
		g.setScore(point);
		cout << "细嗦游戏：";
		cin >> com;
		g.setremark(com);
		cout << "评论成功";
	}
	else
	{
		cout << "未拥有此游戏,不能进行评论\n";
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
	cout << "************************您的个人信息设置界面**************************\n";
	cout << "********************************************************************\n";
	while (1)
	{
		system("cls");
		cout << "\n(change your name)更改昵称[1]" << endl;
		cout << "\n(change your passwords)更改密码[2]" << endl;
		cout << "\n取消操作[3]";
		int choice;
		cout << "\n请输入选择:";
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			cout << "***************昵称修改界面******************" << endl;
			cout << "(your old name)您的旧昵称:   " << Name << endl;
			cout << "\n(please input your new name)请输入您要更换的昵称:";
			string a;
			cin >> a;
			Name = a;
			cout << "\n(changing success!)修改成功!您的新昵称是:  " << a << endl;
			cout << "\n正在跳转回个人界面\n";
			Sleep(1500);
			return;
		}
		else if (choice == 2)
		{
			cout << "***************密码修改界面******************" << endl;
			string psnew; //新密码;
			cout << "请输入您的旧密码验证身份或者输入N退出\n";
			while (1)
			{
				cin >> psnew;
				if (psnew == Passwords)
				{
					cout << "输入正确";
					break;
				}
				else if (psnew == "N")
				{
					cout << "\n正在跳转回个人界面\n";
					Sleep(1000);
					return;
				}
				else
				{
					cout << "密码错误,请重新输入或选择退出个人信息修改界面" << endl;
					continue;
				}
			}
			string newps;
			cout << "(please input your new passwords)请输入新密码";
			cin >> newps;
			Passwords = newps;
			cout << "修改成功！\n"
				 << endl;
			cout << "\n正在跳转回个人界面\n";
			Sleep(1000);
			return;
		}
		else if (choice == 3)
		{
			cout << "退出!" << endl;
			cout << "\n正在跳转回个人界面\n";
			Sleep(1000);
			return;
		}
		else
		{

			system("cls");
			showpicture("error.txt");
			cout << "\n你在干什么鸭!!!QAQ" << endl;
			cout << "请重新输入或者选择退出" << endl;
			Sleep(3000);
			continue;
		}
	}
}
/*======================================开发者类分割线=================================================*/

//开发者
class developer
{
	friend bool operator==(const developer &a, string b)
	{
		return a.Account == b;
	}

public:
	developer(vector<string> minegame, string account = "", string pw = "8888", string name = "") : Account(account), Passwords(pw), Name(name) //构造函数
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
	void change_inf();	 //修改个人信息
	void change_price(); //更改游戏价格
	void add_game();	 //增加游戏
	void delete_game();	 //删除游戏
	void Setlogs();		 //更新日志
	string getname()	 //返回名字																				//返回昵称
	{
		return Name;
	}
	string getaccount() //返回账号
	{
		return Account;
	}
	string getpasswords() //返回密码
	{
		return Passwords;
	}
	void setname(string name) //设置昵称
	{
		Name = name;
	}
	void setaccount(string account) //设置账号
	{
		Account = account;
	}
	void setpasswords(string passwords) //设置密码
	{
		Passwords = passwords;
	}
	vector<string> &getgames() //返回游戏库
	{
		return mine_game;
	}
	void show()
	{
		cout << "************************************您名下的游戏***********************************" << endl;
		for (vector<string>::iterator it = mine_game.begin(); it != mine_game.end(); it++)
		{
			cout << (*it) << endl;
		}
		cout << "*********************************************************************************" << endl;
		return;
	}

protected:
	string Account;			  //账号
	string Name;			  //昵称
	string Passwords;		  //密码
	vector<string> mine_game; //名下游戏库
};
vector<developer> accounts_develop; //已有开发者
void developer::change_inf()
{
	system("cls");
	cout << "**************************************\n";
	cout << "**Your personal information settings**\n";
	cout << "*********您的个人信息设置界面**********\n";
	cout << "**************************************\n";
	while (1)
	{
		system("cls");
		cout << "(change your name)更改昵称[1]" << endl;
		cout << "\n(change your passwords)更改密码[2]" << endl;
		cout << "\n取消操作[3]\n";
		int choice;
		cout << "请输入选择:";
		cin >> choice;
		if (choice == 1)
		{
			cout << "***************昵称修改界面******************" << endl;
			cout << "(your old name)您的旧昵称:   " << Name << endl;
			cout << "(please input your new name)请输入您要更换的昵称:";
			string a;
			cin >> a;
			Name = a;
			cout << "(changing success!)修改成功!您的新昵称是:  " << a << endl;
			return;
		}
		else if (choice == 2)
		{
			cout << "***************密码修改界面******************" << endl;
			string psnew; //新密码;
			cout << "请先输入您的旧密码验证身份或者输入N退出\n";
			while (1)
			{
				cin >> psnew;
				if (psnew == Passwords && psnew != "N")
				{
					cout << "输入正确";
					break;
				}
				else if (psnew == "N")
				{
					return;
				}
				else
				{
					cout << "密码错误,请重新输入或选择退出个人信息修改界面" << endl;
					continue;
				}
			}
			string newps;
			cout << "(please input your new passwords)请输入新密码";
			cin >> newps;
			Passwords = newps;
			cout << "修改成功" << endl;
			return;
		}
		else if (choice == 3)
		{
			cout << "退出!" << endl;
			return;
		}
		else
		{
			system("cls");
			showpicture("error.txt");
			cout << "\n你在干什么鸭!!!QAQ" << endl;
			cout << "请重新输入或者选择退出" << endl;
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
	cout << "\n\nEsc 按3返回*********************************************************X.按0退出主程序" << endl;
	while (1)
	{
		cout << "请输入你想更改的游戏的名称:";
		cin >> name;
		if (name == "3")
		{
			return;
		}
		result = find(game.begin(), game.end(), name);
		if (result == game.end())
		{
			cout << "你在干什么鸭！！！！！ 找不到此游戏\n";
			cout << "请重新输入！\n";
			continue;
		}
		else
		{
			break;
		}
	}
	cout << "该游戏信息如下:" << endl;
	cout << "*********************************************************************************" << endl;
	cout << (*result) << endl;
	cout << "*********************************************************************************" << endl;
	cout << endl;

	cout << "请输入《" << name << "》的新价格: ";
	cin >> price;
	result->change_price(price); //调用Game类的修改价格函数
	if (price == result->getprice())
	{
		cout << "《" << name << "》"
			 << "更改价格成功!" << endl;
	}
	cout << "该游戏更改后信息如下:" << endl;
	cout << "*********************************************************************************" << endl;
	cout << (*result) << endl;
	cout << "*********************************************************************************" << endl;
	cout << endl;
	cout << "返回游戏管理界面中……" << endl;
	Sleep(5000);

	//************主意，这里要有返回界面，否则闪退
}
void developer::add_game() //增加游戏
{
	string develop;
	string newname, newtype;
	double newprice;
	double newscore;
	cout << "*********************************************************************************" << endl;
	cout << "********************************下面请创建新的游戏*********************************" << endl;
	cout << "请创建新游戏的名字:" << endl;
	cin >> newname;

	cout << "请创建新游戏的类别:" << endl;
	cin >> newtype;

	cout << "请创建新游戏的价格:" << endl;
	cin >> newprice;
	Game Newgame(newname, newtype, newprice, Name);
	game.push_back(Newgame);
	mine_game.push_back(newname);
	cout << "创建新游戏成功!" << endl;
	cout << Newgame << endl;
	cout << endl;
	cout << "返回游戏管理界面中……" << endl;
	Sleep(5000);
}
void developer::delete_game() //删除游戏
{
	string delete_name;
	cout << "请输入你要删除的游戏名字:" << endl;
	cin >> delete_name;
	for (vector<Game>::iterator i = game.begin(); i != game.end(); ++i)
	{
		if (delete_name == i->getname())
		{
			game.erase(i);
			break;
		}
	}
	for (vector<string>::iterator j = mine_game.begin(); j != mine_game.end(); ++j) //在名下游戏里删除
	{
		if (delete_name == *j)
		{
			mine_game.erase(j);
			break;
		}
	}
	cout << "《" << delete_name << "》"
		 << "已成功删除" << endl;
	cout << endl;
	cout << "返回游戏管理界面中……" << endl;
	Sleep(5000);
}
void developer::Setlogs() //更新日志
{
	string name;
	string newlog;
	bool x = true;

	vector<Game>::iterator result;
	cout << "\n\nEsc 按3返回*********************************************************X.按0退出主程序" << endl;
	while (1)
	{
		cout << "请输入你想更改的游戏的名称:";
		cin >> name;
		if (name == "3")
		{
			return;
		}
		result = find(game.begin(), game.end(), name);
		if (result == game.end())
		{
			cout << "你在干什么鸭！！！！！ 找不到此游戏\n";
			cout << "请重新输入！\n";
			continue;
		}
		else
		{
			break;
		}
	}
	cout << "该游戏信息如下:" << endl;
	cout << "*********************************************************************************" << endl;
	cout << (*result) << endl;
	cout << "*********************************************************************************" << endl;
	cout << "该游戏往期日志信息如下:" << endl;
	result->showlog();
	cout << endl;
	cout << "请输入《" << name << "》的最新日志: ";
	cin >> newlog;
	result->setlog(newlog);
	cout << "已成功更新日志" << endl;
	cout << "该游戏最新日志信息如下:" << endl;
	result->showlog();
	cout << endl;
	cout << "返回游戏管理界面中……" << endl;
	Sleep(5000);
}

//=================================================主函数里的函数========================================
int getnum();							  //获取游戏全局变量总数量
void search(string searchname);			  //全局函数里查询游戏名
void displaytype(vector<Game> game);	  //展示游戏类型
void displayall_game(User &a);			  //市场界面
void displaybuy_game(Game &g, User &u);	  //购买游戏界面函数
void displayall_user(User &u);			  //展示个人库存
bool checkaccount(string accounts_check); //判断是否已有账号
void mainpage();						  //主界面
void userpage(User &a);					  //个人界面和游戏市场
void developerpage(developer &a);		  //开发者主界面
void developer_manage_page(developer &a); //开发者管理游戏界面
void usersetting(User &a);				  //查看库存以及修改
double str_num(string d);
int str_intnum(string f);
void build(string a, string b, string c, string d);		// readin的辅助函数(用户)
void readin_users();									//将用户txt文件数据读入库
void write_out_users();									//将程序中用户的库导出
void build_dev(string a, string b, string c, string d); // readin的辅助函数(开发者)
void readin_developers();								//将开发者txt文件数据读入库
void write_out_develops();								//将程序中开发者的库导出
void bulid_game(string n, string a, string b, string c, string d,
				string e, string f, string g, string h, string k); // readin的辅助函数(游戏)
void readin_games();											   //将游戏txt文件数据读入库
void write_out_game();											   //将程序中游戏的库导出
void Exit();													   //退出程序函数
void Signin();													   //展示信息
void user_Sign_in();											   //用户登陆
void developer_Sign_in();										   //开发者登录
bool whetherhave(User &u, Game &g);								   //判断用户是否拥有游戏
void Pos(int x, int y);											   //光标更换位置
User &ask_user(string acc);										   //根据账号返回对应的用户的引用
developer &ask_developer(string acc);							   //根据账号返回对应的开发者的引用
Game &ask_game(string acc);										   //根据账号返回对应的游戏的引用
void errorpage()												   //输入错误后如何展示
{
	showpicture("success1.txt");
	Sleep(1000);
	system("cls");
	showpicture("success.txt");
	Sleep(1000);
	system("cls");
	showpicture("success2.txt");
}
//=========================================game类全局函数分割线==========================================

int getnum()
{
	return game.size();
}
//搜索游戏
void search(string searchname)
{
	vector<Game>::iterator g = game.begin();
	vector<Game>::iterator findname = find(game.begin(), game.end(), searchname);
	if (findname == game.end())
	{
		cout << "商城中暂无此游戏" << endl;
	}
	else
	{
		cout << "已找到此游戏：\n";
		cout << *(findname);
	}
}
//市场界面
void displayall_game(User &a)
{
	system("cls");
	vector<Game>::iterator g;
	cout << "Esc.按3返回上级                                                      X.按0退出主程序" << endl;
	cout << "**********************************热销游戏***************************************" << endl;
	cout << "*    |游戏名              游戏类型       价格    |      已售出\n"
		 << endl;
	for (g = game.begin(); g != game.end(); g++)
	{
		cout << (*g) << endl;
	}
	cout << "请选择你要查看的游戏界面(输入游戏名字):";
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
			cout << "你在输入什么？？？？？？？？？？？？？\n";
			cout << "请重新输入或者输入输入B返回市场\n";
			cout << "你的选择: ";
		}
		else
		{
			system("cls");
			cout << "正在跳转到 《" << choice << "》 的界面.....\n";
			Sleep(2000);
			displaybuy_game(ask_game(choice), a);
		}
	}
}
//展示个人库存
void displayall_user(User &u)
{
	vector<Game>::iterator g;
	cout << "*********************************************************************************" << endl;
	cout << u.getname() << "  您的游戏库存如下:\n";

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
	if (find(u.getgames().begin(), u.getgames().end(), g.getname()) == u.getgames().end()) //判断是否已经买过了
	{
		return true;
	}
	return false;
}
//具体个体游戏界面的展示【待讨论（讨论完删此处）】
void displaybuy_game(Game &g, User &u) //购买游戏界面函数
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
	if (g.getname() == "篮球练习生")
	{
		showpicture("kunkun.txt");
		Sleep(1000);
	}
	if (g.getname() == "新世纪福音战士")
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
	cout << "                                                                   X.按0退出主程序" << endl;
	cout << "*********************************************************************************" << endl;
	cout << "|" << setw(5) << "游戏名:"
		 << "《" << g.getname() << "》\n"
		 << setw(5) << "开发者:" << setw(10) << g.getdevelop() << "|\n";
	cout << "*********************************************************************************" << endl;
	g.showcomment();
	if (!whetherhave(u, g))
	{
		cout << endl
			 << "******************************>>>>此游戏已在库中<<<<*****************************" << endl;
		cout << "*********************************************************************************" << endl;
	}
	cout << endl;
	cout << "                            *******[请选择你的操作]*******\n";
	cout << "                            *      [1]购买此游戏         *" << endl;
	cout << "                            *      [2]赠送好友此游戏     *" << endl;
	cout << "                            *      [3]查看评论区         *" << endl;
	cout << "                            *      [4]返回游戏市场       *" << endl;
	cout << "                                     请输入选择:";
	cin >> choice;
	switch (choice)
	{
	case 0:
		Exit();
		break;
	case 1:
		u.buy_game(g);
		cout << "返回游戏主界面..." << endl;
		system("cls");
		displaybuy_game(g, u);
		break;
	case 2:
	{
		cout << "你要将此游戏赠送给(请输入账号):";
		cin >> given;
		if (!checkaccount(given))
		{
			u.give_friend(ask_user(given), g);
			showpicture("thanks.txt");
			cout << ask_user(given).getname() << "表示蟹蟹！！" << endl;
			cout << "操作完成，返回游戏主界面中.....";
			Sleep(3000);
			displaybuy_game(g, u);
		}
		else
		{
			cout << "查无此人!返回游戏主界面！.......\n";
			Sleep(2000);
			displaybuy_game(g, u);
		}
	}
	break;

	case 3:
	{
		cout << "\n\n";
		cout << "                            *******[请选择你的操作]*******\n";
		cout << "                            *      [1]查看所有评论         *" << endl;
		cout << "                            *      [2]进行评论             *" << endl;
		cout << "                            *      [3]返回上一级           *" << endl;
		cout << "                                    请输入选择:";
		int choice1;
		cin >> choice1;
		switch (choice1)
		{
		case 0:
			Exit();
			break;
		case 1:
			g.showcom();
			cout << "返回游戏界面..." << endl;
			Sleep(2000);

			displaybuy_game(g, u);
			break;
		case 2:
			u.Comment(g);
			cout << "返回游戏界面...." << endl;
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
		cout << "输入有误,返回游戏主界面.... ";
		Sleep(2000);
		displaybuy_game(g, u);
	}
}
//============================================分割线====================================================

//判断是否已有账号
bool checkaccount(string accounts_check) //判断用户类
{
	vector<User>::iterator findaccount = find(accounts.begin(), accounts.end(), accounts_check);
	if (findaccount != accounts.end()) //如果找到了，即已存在
	{
		return false;
	}
	return true; //没找到
}
bool checkaccount_developer(string accounts_check)
{
	vector<developer>::iterator findaccount = find(accounts_develop.begin(), accounts_develop.end(), accounts_check);
	if (findaccount != accounts_develop.end()) //如果找到了，即已存在
	{
		return false;
	}
	return true; //没找到
}
User &ask_user(string acc)
{
	vector<User>::iterator it = find(accounts.begin(), accounts.end(), acc);
	return *it;
}
developer &ask_developer(string acc) //根据账号返回对应的开发者的引用
{
	vector<developer>::iterator it = find(accounts_develop.begin(), accounts_develop.end(), acc);
	return *it;
}
Game &ask_game(string acc) //根据账号返回对应的游戏的引用
{
	vector<Game>::iterator it = find(game.begin(), game.end(), acc);
	return *it;
}
//========================================主函数分割线===================================================
void Pos(int x, int y) //光标
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void mainpage() //主界面
{
	//主界面如下
	system("cls");
	char choice1;
	cout << "                                                                                                  X.按0退出主程序" << endl;
	cout << "                                     **************************欢迎登陆stepgame游戏平台***************************\n"
		 << endl;
	ifstream infile("mainpage.txt", ios::in); /*展示图片并清屏*/
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
	cout << setw(10) << "\n请选择是否进入或者退出程序(Y/N)";
	cin >> choice1;
	switch (choice1)
	{
	case 'y':
		system("cls");
		cout << "进入中....";
		Sleep(1000);
		Signin();
		break;
	case 'Y':
		system("cls");
		cout << "进入中....";
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
		cout << "Error!请重新输入";
		Sleep(1000);
		mainpage();
		break;
	}
}
void Signin() //展示信息
{
	system("cls");
	cout << "欢迎回家！欧尼酱！！！！！！！！！" << endl;
	showpicture("biubiu.txt");
	Sleep(2500);
	system("cls");
	int choice2;
	cout << "                                                              X.按0退出主程序" << endl;
	cout << "****************************请选择注册或者登录*******************************" << endl;
	cout << "************                   *************                 *************" << endl;
	cout << "*  1.注册  *                    *  2.登录  *                  *  3.返回  *" << endl;
	cout << "************                   *************                 *************" << endl;
	cout << "                                  _______                                   " << endl;
	cout << "                                 |       |                                  " << endl;
	cout << "                                 |       |                                  " << endl;
	cout << "                                 |_______|                                  " << endl; //此处用于输入
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
		cout << "                                                              X.按0退出主程序" << endl;
		cout << "****************************请选择开发者或用户注册*******************************" << endl;
		cout << "************                     **************                  *************" << endl;
		cout << "*  1.用户  *                      *  2.开发者  *                  *  3.返回  *" << endl;
		cout << "************                     **************                  *************" << endl;
		cout << "                                  _______                                   " << endl;
		cout << "                                 |       |                                  " << endl;
		cout << "                                 |       |                                  " << endl;
		cout << "                                 |_______|                                  " << endl; //此处用于输入
		int choice5;
		Pos(36, 8);
		cin >> choice5;
		if (choice5 == 1)
		{
			system("cls");
			string new_name, new_account, new_password;
			cout << "请输入昵称：" << endl;
			cin >> new_name;
			cout << "\n请输入账户：" << endl;
			cin >> new_account;
			cout << "\n请输入密码：" << endl;
			cin >> new_password;
			Sleep(1000);
			if (!checkaccount(new_account))
			{
				system("cls");
				cout << "账号已存在，注册失败，3秒返回登陆/注册界面" << endl;
				errorpage();
			}
			else
			{
				accounts.push_back(User(new_account, new_password, new_name));
				cout << "注册成功!3秒后跳转至登陆/注册界面  已为您发放新人福利:《hornpub》" << endl;
				showpicture("error.txt");
				cout << "\n";
				cout << "                       这都能让你操作成功!?\n";
				cout << "                       这都能让你操作成功!?\n";
				cout << "                       这都能让你操作成功!?\n";
			}
			Sleep(3000);
			system("cls");
			Signin();
		}
		else if (choice5 == 2)
		{
			system("cls");
			string new_name, new_account, new_password;
			cout << "请输入昵称：" << endl;
			cin >> new_name;
			cout << "\n请输入账户：" << endl;
			cin >> new_account;
			cout << "\n请输入密码：" << endl;
			cin >> new_password;
			Sleep(1000);
			if (!checkaccount_developer(new_account))
			{
				system("cls");
				cout << "账号已存在，注册失败，3秒返回登陆/注册界面" << endl;
				errorpage();
			}
			else
			{
				accounts_develop.push_back(developer(new_account, new_password, new_name));
				cout << "注册成功!3秒后跳转至登陆/注册界面,已为您发放基础开发者工具福利:tools" << endl;
				showpicture("error.txt");
				cout << "\n";
				cout << "                       这都能让你操作成功!?\n";
				cout << "                       这都能让你操作成功!?\n";
				cout << "                       这都能让你操作成功!?\n";
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
		cout << "                                                              X.按0退出主程序" << endl;
		cout << "****************************请选择开发者或用户登录*******************************" << endl;
		cout << "************                     **************                  ***********" << endl;
		cout << "*  1.用户  *                      *  2.开发者  *                  *  3.返回  *" << endl;
		cout << "************                     **************                  ************" << endl;
		cout << "                                  _______                   " << endl;
		cout << "                                 |       |                  " << endl;
		cout << "                                 |       |                  " << endl;
		cout << "                                 |_______|                  " << endl; //此处用于输入
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
		cout << "Error! 1秒后为你返回原界面";
		Sleep(1000);
		system("cls");
		Signin();
	}
}
void userpage(User &a) //个人界面和游戏市场
{
	system("cls");
	int choice3;
	cout << "                                                 X.按0退出主程序" << endl;
	cout << "*****************************欢迎******************************" << endl;
	cout << "**************            **************          ***********" << endl;
	cout << "* 1.个人界面  *            * 2.游戏市场  *          * 3. 返回  *" << endl;
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
		cout << "Error! 1秒后为你返回原界面";
		Sleep(1000);
		system("cls");
		userpage(a);
	}
	userpage(a);
}
void usersetting(User &a) //查看库存以及修改
{
	system("cls");
	int choice4;
	cout << "                                                X.按0退出主程序" << endl;
	cout << "*****************************欢迎*****************************" << endl;
	cout << "***********            ****************           ***********" << endl;
	cout << "* 1.库存  *            * 2.个人信息修改 *           * 3. 返回 *" << endl;
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
		cout << "正在跳转..." << endl;
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
		cout << "error! 1秒后为你返回原界面。";
		Sleep(1000);
		usersetting(a);
	}
	cout << "wtclmqiaottc" << endl;
	Sleep(50000);
}
void developer_manage_page(developer &a) //开发者管理游戏界面
{
	int choice7;
	system("cls");
	cout << "                                                                                          X.按0退出主程序" << endl;
	cout << "**************************************欢迎开发者进入游戏管理界面*******************************************" << endl;
	cout << "**************        *****************     ******************      *******************     ***************" << endl;
	cout << "* 1.增加游戏  *       * 2.删除游戏    *      *  3.修改游戏价格  *      *  4. 更新日志    *     *   5. 返回    *" << endl;
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
		cout << "error!1秒后为您返回原界面。" << endl;
		Sleep(1000);
		system("cls");
		developer_manage_page(a);
	}
}
void developerpage(developer &a) //开发者页面
{
	system("cls");
	int choice5;
	cout << "                                                     X.按0退出主程序" << endl;
	cout << "***********************欢迎进入开发者界面*************************" << endl;
	cout << "**************             *****************          ***********" << endl;
	cout << "* 1.游戏管理  *             * 2.个人信息修改 *           * 3. 返回 *" << endl;
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
		cout << "操作完成,返回主界面中...";
		Sleep(2000);
		developerpage(a);
	}
	break;
	default:
		cout << "error!1秒后为您返回原界面。" << endl;
		Sleep(1000);
		system("cls");
		developerpage(a);
		break;
	}
}
void user_Sign_in() //用户登陆
{
	system("cls");
	string used_useraccount, used_userpassword;
	cout << "请输入账号：" << endl;
	cin >> used_useraccount;
	if (checkaccount(used_useraccount))
	{
		cout << "登录失败，账号不存在\n正在跳转回主界面..." << endl;
		Sleep(1000);
		system("cls");
		Signin();
	}
	cout << "\n请输入密码：" << endl;
	cin >> used_userpassword;
	if (used_userpassword == ask_user(used_useraccount).getpasswords())
	{
		system("cls");
		cout << "登录成功\n正在跳转..." << endl;
		showpicture("error.txt");
		cout << "\n";
		cout << "                       这都能让你操作成功!?\n";
		cout << "                       这都能让你操作成功!?\n";
		cout << "                       这都能让你操作成功!?\n";
		//停顿时间
		Sleep(1500);
		//清屏函数
		system("cls");
		//个人界面和游戏市场
		userpage(ask_user(used_useraccount)); // 1.个人界面2.游戏市场3.返回
	}
	else
	{
		system("cls");
		cout << "密码错误，返回主界面!...";
		errorpage();
		Sleep(1500);
		Signin();
	}
}
void developer_Sign_in() //开发者登录
{
	system("cls");
	string used_useraccount, used_userpassword;
	cout << "请输入账号：" << endl;
	cin >> used_useraccount;
	if (checkaccount_developer(used_useraccount))
	{
		cout << "登录失败，账号不存在\n正在跳转回主界面..." << endl;
		Sleep(1000);
		system("cls");
		Signin();
	}
	cout << "\n请输入密码：" << endl;
	cin >> used_userpassword;
	if (used_userpassword == ask_developer(used_useraccount).getpasswords())
	{
		system("cls");
		cout << "登录成功\n正在跳转..." << endl;
		//停顿时间
		showpicture("error.txt");
		cout << "\n";
		cout << "                       这都能让你操作成功!?\n";
		cout << "                       这都能让你操作成功!?\n";
		cout << "                       这都能让你操作成功!?\n";
		Sleep(1500);
		//清屏函数
		system("cls");
		//个人界面和游戏市场
		developerpage(ask_developer(used_useraccount)); // 1.个人界面2.游戏市场3.返回
	}
	else
	{
		system("cls");
		cout << "密码错误，返回主界面!...";
		errorpage();
		Sleep(1500);
		Signin();
	}
}
// user类读入和输出保存===================================================================================
void build(string a, string b, string c, string d) // readin的辅助函数
{
	vector<string> newaccount_games; //
	string newgames;
	for (int i = 0; i < d.size(); i++) // d是靠空格分隔的已有游戏名称字符串
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
void readin_users() //将用户txt文件数据读入库
{
	fstream user("users.txt");
	if (!user) //文件不存在，当然文件一定存在
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
void write_out_users() //将程序中用户的库导出
{
	fstream user("users.txt");
	if (!user) //文件不存在，当然文件一定存在
	{
		exit(1);
	}
	string a(" ");	//空格
	string b("\n"); //换行
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
// developer类数据读入与保存==============================================================================
void build_dev(string a, string b, string c, string d) // readin的辅助函数
{
	vector<string> newaccount_games; //
	string newgames;
	for (int i = 0; i < d.size(); i++) // d是靠空格分隔的已有游戏名称字符串
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
void readin_developers() //将txt文件数据读入库
{
	fstream develop("developers.txt");
	if (!develop) //文件不存在，当然文件一定存在
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
void write_out_develops() //将程序中的库写入数据
{
	fstream develop("developers.txt");
	if (!develop) //文件不存在，当然文件一定存在
	{
		exit(1);
	}
	string a(" ");	//空格
	string b("\n"); //换行
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
// game类数据读入与保存===================================================================================
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
void Exit() //退出程序exit
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
	cout << "                                    记得回来哦~。。。小天很想你" << endl;
	color(h);
	cout << "                                    记得回来哦~。。。qiao很想你" << endl;
	color(l);
	cout << "                                    记得回来哦~。。。明仔很想你" << endl;
	color(t);
	cout << "                                    记得回来哦~。。。 πc很想你" << endl;

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
运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
 调试程序: F5 或调试 >“开始调试”菜单

 入门使用技巧:
   1. 使用解决方案资源管理器窗口添加/管理文件
   2. 使用团队资源管理器窗口连接到源代码管理
   3. 使用输出窗口查看生成输出和其他消息
   4. 使用错误列表窗口查看错误
   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
*/  

