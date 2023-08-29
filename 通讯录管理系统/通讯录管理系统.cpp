#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//��װ������ʾ�˵�����
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1.�����ϵ��  *****" << endl;
	cout << "***** 2.��ʾ��ϵ��  *****" << endl;
	cout << "***** 3.ɾ����ϵ��  *****" << endl;
	cout << "***** 4.������ϵ��  *****" << endl;
	cout << "***** 5.�޸���ϵ��  *****" << endl;
	cout << "***** 6.�����ϵ��  *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼  *****" << endl;
	cout << "*************************" << endl;
}



//�����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա� 1 �� 2 Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};


//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼��ǰ��¼����ϵ�˵ĸ���
	int m_Size;
};


//1.�����ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
	}
	else
	{
		//�����ϵ��

		//����
		string  name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1.��  2.Ů" << endl;
		int sex = 0;

		while (true)
		{//�������1��2�����˳�ѭ�� �������� ��������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "����������������" << endl;
		}


		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		cout << "������绰" << endl;
		string  phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//��ͥ��ַ
		cout << "�������ͥ��ַ" << endl;
		string  address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");//��������
	}
}

//2.��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0����Ϊ0����ʾ
	if	(abs->m_Size==0)
	{
		cout<<"��ǰ��¼Ϊ��" << endl;
	} 
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "����" <<abs->personArray[i].m_Name << endl;
			cout << "�Ա�" <<( abs->personArray[i].m_Sex ==1?"��" :"Ů") << endl;
			cout << "����" << abs->personArray[i].m_Age << endl;
			cout << "�绰" << abs->personArray[i].m_Phone << endl;
			cout << "סַ" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");//��������
}


  //�����ϵ���Ƿ���ڣ����ڷ�����ϵ�����������е�λ�ã������ڷ���-1
int  isexit(Addressbooks* abs, string name) //����1ͨѶ¼ ����2 �Ա�����
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ��û�
		if (abs->personArray[i].m_Name==name )
		{
			return i;
		}
	}
	return -1;
}


//3.ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "����Ҫɾ������ϵ��" << endl;

	string name;
	cin >> name;

	int rec=isexit(abs, name);
	if (rec!=-1)
	{
		//�鵽�� ����ɾ��
		for (int i =rec; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");//��������
}

//4.������ϵ��
void findPerson(Addressbooks* abs)
{
	cout<<"����Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж���ϵ���Ƿ����
	int ret = isexit(abs, name);
	 
	if (ret!=-1)
	{
		cout << "����" << abs->personArray[ret].m_Name << endl;
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << endl;
		cout << "����" << abs->personArray[ret].m_Age << endl;
		cout << "�绰" << abs->personArray[ret].m_Phone << endl;
		cout << "סַ" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");//��������
}

//5.�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "����Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж���ϵ���Ƿ����
	int ret = isexit(abs, name);
	if (ret != -1)//�ҵ���ϵ��
	{
		//�޸ĵ���Ŀ
		//����
		string  name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1.��  2.Ů" << endl;
		int sex = 0;

		while (true)
		{//�������1��2�����˳�ѭ�� �������� ��������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "����������������" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�绰
		cout << "������绰" << endl;
		string  phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//��ͥ��ַ
		cout << "�������ͥ��ַ" << endl;
		string  address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout<<"�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");//��������
}

//6.�����ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout<<"�����" << endl;
	system("pause");
	system("cls");//��������
}



int main()
{

	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	//�����û�ѡ������ı���
	int select = 0;

	while (true)
	{
		//�˵�����
		showMenu();

		cin >> select;

		switch (select)
		{
			case 1://1.�����ϵ��
				addPerson(&abs);
				break;
			case 2://2.��ʾ��ϵ��
				showPerson(&abs);
				break;
			case 3://3.ɾ����ϵ��
				deletePerson(&abs);
				break;
			case 4://4.������ϵ��
				findPerson(&abs);
				break;
			case 5://5.�޸���ϵ��
				modifyPerson(&abs);
				break;
			case 6://6.�����ϵ��
				cleanPerson(&abs);
				break;
			case 0://0.�˳�ͨѶ¼
				cout<<"��ӭ�´�ʹ��" << endl;
				system("pause ");
				return 0;
				break;

			default:
				break;
		}
	}


	system("pause ");
	return 0 ;


	system("pause ");
	return 0;	system("pause ");
	return 0;	system("pause ");
	return 0;	system("pause ");
	return 0;	system("pause ");
	return 0;	system("pause ");
	return 0;	system("pause ");
	return 0;



}




































