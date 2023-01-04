#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//�����ϵ�˽ṹ��
struct Person
{
	string m_Name;  //����
	int m_Sex;  //�Ա�  1 ��  2 Ů
	int m_Age;  //����
	string m_Phone;  //�绰
	string m_Addr;  //סַ
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX];  //ͨѶ¼�б������ϵ������
	int m_Size;  //ͨѶ¼�е�ǰ��¼��ϵ�˸���
};
//�˵�����
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}

//�����ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		int sex=0;
		cout << "�������Ա� " << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		//����
		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << "�������ͥ��ַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ���" << endl;

		system("pause");  //�밴���������
		system("cls");  //��������
	}
}

//��ʾ������ϵ��
void showPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0����Ϊ0����ʾ��¼Ϊ��
	if (abs->m_Size == 0)
	{
		cout << "��ǰͨѶ¼��¼Ϊ0" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" <<(abs->personArray[i].m_Sex == 1? "��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");  //�����������
	system("cls");  //��������
}

//�����ϵ���Ƿ���ڣ������ڣ��򷵻���ϵ���������еľ���λ�ã��������ڣ�����-1
int isExist(Addressbooks* abs, string name)  //����1��ͨѶ¼  ����2���Ա�����
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;  //�ҵ�
		}
	}
	return -1;  //δ�ҵ�
}

//ɾ��ָ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ� " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);  //-1Ϊδ�鵽
	if (ret != -1)
	{
		//�鵽���ˣ�����ɾ������
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;  //����ͨѶ¼�е�����
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}

//����ָ����ϵ����Ϣ
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	//�ж�ָ����ϵ���Ƿ���ͨѶ¼��
	int ret = isExist(abs, name);
	if (ret != -1)  //�ҵ�
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else  //δ�ҵ�
	{
		cout << "���޴��ˣ�" << endl;
	}
	//���������������������
	system("pause");
	system("cls");
}

//�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)  //�鵽
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				//������ȷ���˳�ѭ��
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "�޸ĳɹ���" << endl;
	}
	else  //δ�鵽
	{
		cout << "���޴��ˣ�" << endl;
	}
	//�����������
	system("pause");
	system("cls");
}

//�����ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;  //˼·����ͨѶ¼��������Ϊ0�����߼����㼴��
	cout << "ͨѶ¼�����" << endl;
	//�����������
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;  //�����û�ѡ���������
	struct Addressbooks abs;  // ����ͨѶ¼�ṹ�����
	abs.m_Size = 0;  //��ʼ����ǰ��Ա����

	while (true)
	{
		//�˵�����
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:  //���
			addPerson(&abs);  //���õ�ַ���ݣ������β�����ʵ��
			break;
		case 2:  //��ʾ
			showPerson(&abs);
			break;
		case 3:  //ɾ��
			deletePerson(&abs);
			break;
		case 4:  //����
			findPerson(&abs);
			break;
		case 5:  //�޸�
			modifyPerson(&abs);
			break;
		case 6:  //���
			cleanPerson(&abs);
			break;
		case 0:  //�˳�
			cout << "��ӭ�´�ʹ�ã�����" << endl;
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