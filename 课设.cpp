#include<iostream>
#include<string>
#define MAX 1000
using namespace std;


struct Linkman			//联系人 
{
	string Name;//姓名
	string Company;//单位
	string Phone;//电话
	string Address;//住址
};

struct Phonebook		//通讯录
{
	struct Linkman person[MAX];//通讯录中保存的联系人数组
	int size;			//通讯录中人员个数
};

struct t		//中间量 
{
	struct Linkman t[MAX];
	int size;
};

void Menu()
{
	cout << "本程序的功能有：\n"; 
	cout << "*************************" << endl;
	cout << "*     1、添加联系人     *" << endl;
	cout << "*     2、显示联系人     *" << endl;
	cout << "*     3、删除联系人     *" << endl;
	cout << "*     4、查找联系人     *" << endl;
	cout << "*     5、修改联系人     *" << endl;
	cout << "*     6、移动联系人     *" << endl;
	cout << "*     7、清空联系人     *" << endl;
	cout << "*     0、退出通讯录     *" << endl;
	cout << "*************************" << endl;
	cout << "请输入进行操作的对应序号："; 
}

void add(Phonebook *p)//添加联系人
{
	if (p->size == MAX)//判断通讯录是否已经满，如果满不添加
	{
		cout << "通讯录已经满，不能添加！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		p->person[p->size].Name = name;

		//单位 
		cout << "请输入联系人单位： " << endl;
		string company;
		cin >> company;
		p->person[p->size].Company = company;
		//住址
		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		p->person[p->size].Address = address;

		//电话
		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		p->person[p->size].Phone = phone;
		
		//更新通讯录人数
		p->size++;

		cout << "添加成功！" << endl;


	}
}

void Display(Phonebook * p)//2.显示所有联系人
{
	if (p->size == 0)//判断通讯录中人数是否为0，如果为0，提示为空；如果不为0，显示记录的联系人信息
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << i <<" ";
			cout << "姓名： " << p->person[i].Name <<" ";
			cout << "单位： " << p->person[i].Company<< " ";
			cout << "住址： " << p->person[i].Address << " ";
			cout << "电话： " << p->person[i].Phone << " ";
			cout << endl;
		
		}
	}
}

//3、删除联系人函数
int isExist(Phonebook * p, string name)//检测联系人是否存在
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
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int s = isExist(p, name);
	if (s != -1)//进行删除
	{
		for (int i = s; i < p->size; i++)
		{
			//数据前移
			p->person[i] = p->person[i + 1];
		}
		p->size--;//更新通讯录中的人员数
		cout << "删除成功" << endl;

	}
	else
	{
		cout << "查无此人" << endl;
	}

}

void Find(Phonebook *p)//4、查找指定联系人
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int s = isExist(p, name);//判断输入的联系人是否存在通讯录中
	if (s != -1)//找到联系人
	{
		cout << "姓名： " << p->person[s].Name << "\t"; 
		cout << "单位： " << p->person[s].Company<< "\t";
		cout << "电话： " << p->person[s].Phone << "\t";
		cout << "住址： " << p->person[s].Address << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}

void modify(Phonebook *p)//5、修改指定联系人信息
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	string name1;
	string company ;
	string address ;
	string phone ;
	int i = isExist(p, name);
	if (i != -1)//找到指定的联系人
	{
		int s;
		cout << "*     1、修改姓名     *" << endl;
		cout << "*     2、修改单位     *" << endl;
		cout << "*     3、修改地址     *" << endl;
		cout << "*     4、修改电话     *" << endl;	
		cout <<"请输入要修改内容对应的序号："; 
		cin>>s; 
		switch(s)
		{
			case 1://姓名修改
				
				cout << "请输入姓名： " << endl;
				cin >> name1;
				p->person[i].Name = name1;
				break;
			case 2://单位修改 
				cout << "请输入单位： " << endl;
				cin >> company;
				p->person[i].Company = company;
				break;
			case 3:	//住址修改
				cout << "请输入地址： " << endl;
				cin >> address;
				p->person[i].Address= address;
				break;
			case 4://电话修改
				cout << "请输入电话： " << endl;
				cin >> phone;
				p->person[i].Phone = phone;
				break;
			default:
				break;
		}
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

}

//6.移动 
void Move(Phonebook*p)
{
	t*q;  //中间量 
	int i,s;
	cout<<"请输入要移动的联系人编号：" ;
	cin>>i;
	cout<<"请输入目的编号：";
	cin>>s;
	cout<<endl; 
	cout<<"移动成功！";
	cout<<endl; 
} 

void Clear(Phonebook * p)//7.清空联系人
{
	p->size = 0;//将当前联系人数值为0，做逻辑清空操作
	cout << "通讯录已清空" << endl;
}
int main()
{
	struct Phonebook p;//创建通讯录结构体变量
	p.size = 0;//初始化通讯绿中当前人员个数
	int i = 0;//创建用户选择输入的变量
	while (1)
	{
		Menu();
		cin >> i ;
		switch (i)
		{
			case 1://添加联系人
				add(&p);
				break;
			case 2://显示联系人
				Display(&p);
				break;
			case 3://删除联系人
				Delete(&p);
				break;
			case 4://查找联系人
				Find(&p);
				break;
			case 5://修改联系人
				modify(&p);
				break;
			case 6://移动联系人 
				Move(&p);
				break;	
			case 7://清空联系人
				Clear(&p);
				break;
			case 0://退出通讯录
				cout << "欢迎下次使用" << endl;
				return 0;
				break;
			default:
				break;
		}
	}
	

	return 0;
}

