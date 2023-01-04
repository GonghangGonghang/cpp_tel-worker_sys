#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//设计联系人结构体
struct Person
{
	string m_Name;  //姓名
	int m_Sex;  //性别  1 男  2 女
	int m_Age;  //年龄
	string m_Phone;  //电话
	string m_Addr;  //住址
};

//设计通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];  //通讯录中保存的联系人数组
	int m_Size;  //通讯录中当前记录联系人个数
};
//菜单界面
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}

//添加联系人
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		int sex=0;
		cout << "请输入性别： " << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入家庭地址： " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;

		cout << "添加成功！" << endl;

		system("pause");  //请按任意键继续
		system("cls");  //清屏操作
	}
}

//显示所有联系人
void showPerson(Addressbooks * abs)
{
	//判断通讯录中人数是否为0，若为0，提示记录为空
	if (abs->m_Size == 0)
	{
		cout << "当前通讯录记录为0" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" <<(abs->personArray[i].m_Sex == 1? "男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");  //按任意键继续
	system("cls");  //清屏操作
}

//检测联系人是否存在，若存在，则返回联系人在数组中的具体位置，若不存在，返回-1
int isExist(Addressbooks* abs, string name)  //参数1：通讯录  参数2：对比姓名
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;  //找到
		}
	}
	return -1;  //未找到
}

//删除指定联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);  //-1为未查到
	if (ret != -1)
	{
		//查到此人，进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;  //更新通讯录中的人数
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}

//查找指定联系人信息
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;
	//判断指定联系人是否在通讯录中
	int ret = isExist(abs, name);
	if (ret != -1)  //找到
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else  //未找到
	{
		cout << "查无此人！" << endl;
	}
	//按下任意键进行清屏操作
	system("pause");
	system("cls");
}

//修改指定联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)  //查到
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				//输入正确则退出循环
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "修改成功！" << endl;
	}
	else  //未查到
	{
		cout << "查无此人！" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//清空联系人
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;  //思路：将通讯录中人数置为0，做逻辑清零即可
	cout << "通讯录已清空" << endl;
	//按任意键清屏
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;  //创建用户选择输入变量
	struct Addressbooks abs;  // 创建通讯录结构体变量
	abs.m_Size = 0;  //初始化当前人员个数

	while (true)
	{
		//菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:  //添加
			addPerson(&abs);  //利用地址传递，可以形参修饰实参
			break;
		case 2:  //显示
			showPerson(&abs);
			break;
		case 3:  //删除
			deletePerson(&abs);
			break;
		case 4:  //查找
			findPerson(&abs);
			break;
		case 5:  //修改
			modifyPerson(&abs);
			break;
		case 6:  //清空
			cleanPerson(&abs);
			break;
		case 0:  //退出
			cout << "欢迎下次使用！！！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}