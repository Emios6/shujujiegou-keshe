#include<iostream>
#include<string>
#define MAX 1000
using namespace std;


struct Linkman			//��ϵ�� 
{
	string Name;//����
	string Company;//��λ
	string Phone;//�绰
	string Address;//סַ
};

struct Phonebook		//ͨѶ¼
{
	struct Linkman person[MAX];//ͨѶ¼�б������ϵ������
	int size;			//ͨѶ¼����Ա����
};

struct t		//�м��� 
{
	struct Linkman t[MAX];
	int size;
};

void Menu()
{
	cout << "������Ĺ����У�\n"; 
	cout << "*************************" << endl;
	cout << "*     1�������ϵ��     *" << endl;
	cout << "*     2����ʾ��ϵ��     *" << endl;
	cout << "*     3��ɾ����ϵ��     *" << endl;
	cout << "*     4��������ϵ��     *" << endl;
	cout << "*     5���޸���ϵ��     *" << endl;
	cout << "*     6���ƶ���ϵ��     *" << endl;
	cout << "*     7�������ϵ��     *" << endl;
	cout << "*     0���˳�ͨѶ¼     *" << endl;
	cout << "*************************" << endl;
	cout << "��������в����Ķ�Ӧ��ţ�"; 
}

void add(Phonebook *p)//�����ϵ��
{
	if (p->size == MAX)//�ж�ͨѶ¼�Ƿ��Ѿ���������������
	{
		cout << "ͨѶ¼�Ѿ�����������ӣ�" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		p->person[p->size].Name = name;

		//��λ 
		cout << "��������ϵ�˵�λ�� " << endl;
		string company;
		cin >> company;
		p->person[p->size].Company = company;
		//סַ
		cout << "�������ͥסַ�� " << endl;
		string address;
		cin >> address;
		p->person[p->size].Address = address;

		//�绰
		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		p->person[p->size].Phone = phone;
		
		//����ͨѶ¼����
		p->size++;

		cout << "��ӳɹ���" << endl;


	}
}

void Display(Phonebook * p)//2.��ʾ������ϵ��
{
	if (p->size == 0)//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾΪ�գ������Ϊ0����ʾ��¼����ϵ����Ϣ
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << i <<" ";
			cout << "������ " << p->person[i].Name <<" ";
			cout << "��λ�� " << p->person[i].Company<< " ";
			cout << "סַ�� " << p->person[i].Address << " ";
			cout << "�绰�� " << p->person[i].Phone << " ";
			cout << endl;
		
		}
	}
}

//3��ɾ����ϵ�˺���
int isExist(Phonebook * p, string name)//�����ϵ���Ƿ����
{
	for (int i = 0; i < p->size; i++)
	{
		if (p->person[i].Name == name)
		{
			return i;
		}
	}
	return -1;
}
void Delete(Phonebook *p)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int s = isExist(p, name);
	if (s != -1)//����ɾ��
	{
		for (int i = s; i < p->size; i++)
		{
			//����ǰ��
			p->person[i] = p->person[i + 1];
		}
		p->size--;//����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ�" << endl;

	}
	else
	{
		cout << "���޴���" << endl;
	}

}

void Find(Phonebook *p)//4������ָ����ϵ��
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int s = isExist(p, name);//�ж��������ϵ���Ƿ����ͨѶ¼��
	if (s != -1)//�ҵ���ϵ��
	{
		cout << "������ " << p->person[s].Name << "\t"; 
		cout << "��λ�� " << p->person[s].Company<< "\t";
		cout << "�绰�� " << p->person[s].Phone << "\t";
		cout << "סַ�� " << p->person[s].Address << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}

void modify(Phonebook *p)//5���޸�ָ����ϵ����Ϣ
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	string name1;
	string company ;
	string address ;
	string phone ;
	int i = isExist(p, name);
	if (i != -1)//�ҵ�ָ������ϵ��
	{
		int s;
		cout << "*     1���޸�����     *" << endl;
		cout << "*     2���޸ĵ�λ     *" << endl;
		cout << "*     3���޸ĵ�ַ     *" << endl;
		cout << "*     4���޸ĵ绰     *" << endl;	
		cout <<"������Ҫ�޸����ݶ�Ӧ����ţ�"; 
		cin>>s; 
		switch(s)
		{
			case 1://�����޸�
				
				cout << "������������ " << endl;
				cin >> name1;
				p->person[i].Name = name1;
				break;
			case 2://��λ�޸� 
				cout << "�����뵥λ�� " << endl;
				cin >> company;
				p->person[i].Company = company;
				break;
			case 3:	//סַ�޸�
				cout << "�������ַ�� " << endl;
				cin >> address;
				p->person[i].Address= address;
				break;
			case 4://�绰�޸�
				cout << "������绰�� " << endl;
				cin >> phone;
				p->person[i].Phone = phone;
				break;
			default:
				break;
		}
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

}

//6.�ƶ� 
void Move(Phonebook*p)
{
	t*q;  //�м��� 
	int i,s;
	cout<<"������Ҫ�ƶ�����ϵ�˱�ţ�" ;
	cin>>i;
	cout<<"������Ŀ�ı�ţ�";
	cin>>s;
	cout<<endl; 
	cout<<"�ƶ��ɹ���";
	cout<<endl; 
} 

void Clear(Phonebook * p)//7.�����ϵ��
{
	p->size = 0;//����ǰ��ϵ����ֵΪ0�����߼���ղ���
	cout << "ͨѶ¼�����" << endl;
}
int main()
{
	struct Phonebook p;//����ͨѶ¼�ṹ�����
	p.size = 0;//��ʼ��ͨѶ���е�ǰ��Ա����
	int i = 0;//�����û�ѡ������ı���
	while (1)
	{
		Menu();
		cin >> i ;
		switch (i)
		{
			case 1://�����ϵ��
				add(&p);
				break;
			case 2://��ʾ��ϵ��
				Display(&p);
				break;
			case 3://ɾ����ϵ��
				Delete(&p);
				break;
			case 4://������ϵ��
				Find(&p);
				break;
			case 5://�޸���ϵ��
				modify(&p);
				break;
			case 6://�ƶ���ϵ�� 
				Move(&p);
				break;	
			case 7://�����ϵ��
				Clear(&p);
				break;
			case 0://�˳�ͨѶ¼
				cout << "��ӭ�´�ʹ��" << endl;
				return 0;
				break;
			default:
				break;
		}
	}
	

	return 0;
}

