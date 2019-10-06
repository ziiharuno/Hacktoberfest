#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<process.h>
#include<ctype.h>
#include<fstream.h>
#include <time.h>

class admin
{
	private:
		char pass[10];
	public:
		void login();
};

class employee
{
	private:
		char name[30],address[50],phone[11],gender,m_status,designation;
		int ecode,dd,mm,yy;
		long int salary;
	public:
		employee()
		{
			ecode=0;
			salary=0;
			strcpy(name,"NULL");
		}
		void registration();
		void reg_success(int);
		int reg_code();
		void about();
		void show_employee();
		void display();
		void pay_slip();
};

admin a;

employee load,load1;

fstream fetch;

void f_page();
void menu();
void loading();
void error();
void design();
int date(int,int,int);

void main()
{
	clrscr();
	f_page();
	getch();
}

void f_page()
{
	clrscr();
	textcolor(GREEN);
	gotoxy(32,3);
	cprintf("NATIONAL UNIVERSITY");
	for(int i=1;i<=80;i++)
	{
		gotoxy(i,5);
		textcolor(RED);
		cprintf("�");
		gotoxy(i,20);
		cprintf("�");
	}
	a.login();
}

void design()
{
	textcolor(BLUE);
	for(int x=1,x1=80;x<=80;x++,x1--)
	{
		delay(3);
		gotoxy(x,2);
		cprintf("�");
		delay(3);
		gotoxy(x1,24);
		cprintf("�");
	}
	for(x=1,x1=25;x<=25;x++,x1--)
	{
		delay(4);
		gotoxy(2,x1);
		cprintf("�");
		delay(4);
		gotoxy(79,x);
		cprintf("�");
	}
}

void admin::login()
{
	char pass2[]={"getin"};
	textcolor(GREEN);
	gotoxy(35,23);
	cprintf("Esc - quit");
	gotoxy(29,9);
	cprintf("USER     : system@univ123");
	gotoxy(29,11);
	cprintf("PASSWORD : ");
	for(int i=0,x=40;i<10;i++,x++)
	{
		a:
		pass[i]=getch();
		if(pass[i]==13)
			break;
		else if(pass[i]==8&&x>40)
		{
			x--;
			i--;;
			gotoxy(x,11);
			clreol();
			goto a;

		}
		else if(pass[i]==27)
		{
			clrscr();
			gotoxy(35,13);
			cprintf("Exiting...");
			delay(2000);
			exit(0);
		}
		else if(pass[i]!=8)
			cprintf("*");
	}
	int valid=0;
	for(i=0;pass[i]!='\0';i++)
		if(pass[i]==pass2[i])
			valid++;
	if(valid==strlen(pass2))
	{
		gotoxy(31,15);
		cprintf("Access granted");
		delay(1000);
		gotoxy(31,17);
		cprintf("Loading System");
		gotoxy(37,18);
		for(i=1;i<7;i++)
		{
			cprintf(".");
			delay(600);
			if(i==3)
			{
				gotoxy(37,18);
				clreol();
			}
		}
		load.about();
	}
	else
	{
		gotoxy(31,15);
		cprintf("Access denied");
		delay(2000);
		f_page();
	}
}
void menu()
{
	clrscr();
	design();
	textcolor(GREEN);
		gotoxy(31,7);
		cprintf("1.  New Employee\n");
		gotoxy(31,9);
		cprintf("2.  Print Pay slip\n");
		gotoxy(31,11);
		cprintf("3.  Show Record\n");
		gotoxy(31,13);
		cprintf("4.  List Records\n");
		gotoxy(31,15);
		cprintf("5.  About Us\n");
		gotoxy(10,23);
		cprintf("Esc - quit ");
		gotoxy(27,23);
		cprintf("Ent\er Your Choice");
	char ch;
	b:
	ch=getch();
	switch(ch)
	{
		case 49: loading();
			 load.registration();
			 break;
		case 50: loading();
			 load.pay_slip();
			 break;
		case 51: loading();
			 load.show_employee();
			 break;
		case 52: loading();
			 load.display();
			 break;
		case 53: loading();
			 load.about();
			 break;
		case 27: clrscr();
			 gotoxy(35,13);
			 cprintf("Exiting...");
			 delay(1000);
			 exit(0);
		default: gotoxy(50,23);
			 cprintf("Processing...             ");
			 delay(200);
			 gotoxy(50,23);
			 clreol();
			 delay(200);
			 gotoxy(50,23);
			 cprintf("Wrong Input Access denied");
			 goto b;
	}
}
void loading()
{
	gotoxy(50,23);
	cprintf("Loading...                ");
	delay(300);
}
void error()
{
	gotoxy(59,21);
	textcolor(RED);
	cprintf("Incorrect detail");
	delay(500);
	gotoxy(59,21);
	clreol();
	textcolor(GREEN);
}
int date(int dd,int mm,int yy)
{
	if(yy%4==0&&mm==2&&dd<=29&&dd>0&&yy>=1980&&yy<=2020)
		return 1;
	else if(yy%4!=0&&mm==2&&dd<=28&&dd>0&&yy>=1980&&yy<=2020)
		return 1;
	else if(((mm==1)||(mm==3)||(mm==5)||(mm==7)||(mm==8)||(mm==10)||(mm==12))&&dd<=31&&dd>0&&yy>=1980&&yy<=2020)
		return 1;
	else if(((mm==4)||(mm==6)||(mm==9)||(mm==11))&&dd<=30&&dd>0&&yy>=1980&&yy<=2020)
		return 1;
	else
		return -1;
}
void employee::registration()
{
	clrscr();
	gotoxy(30,2);
	cprintf("Registration Form");
	gotoxy(5,5);
	cprintf("Name           :");
	gotoxy(5,7);
	cprintf("Address        :");
	gotoxy(5,9);
	cprintf("Gender (F/M)   :");
	gotoxy(5,11);
	cprintf("Date of Joining:-");
	gotoxy(35,11);
	cprintf("Date   :");
	gotoxy(35,12);
	cprintf("Month  :");
	gotoxy(35,13);
	cprintf("Year   :");
	gotoxy(5,15);
	cprintf("Phone No.      :");
	gotoxy(5,17);
	cprintf("Married(Y/N)   : ");
	gotoxy(5,19);
	cprintf("Designation    :-");
	gotoxy(30,22);
	cprintf("P  :  Professor");
	gotoxy(30,20);
	cprintf("A  :  Lab Assistant");
	gotoxy(30,21);
	cprintf("C  :  Clerk");
	textcolor(MAGENTA+BLINK);
	gotoxy(58,24);
	cprintf("(Main Menu : Press Esc)");
	int i,j;
	char t;
	textcolor(GREEN);
	for(i=0,j=25;i<=30&&j<=55;i++,j++)
	{
		L1:
		gotoxy(j,5);
		name[i]=getche();
		if(isspace(name[i]))
		{
			if((isspace(name[0]))||(isspace(name[i])&&isspace(name[i-1])))
			goto L1;
		}
		if(toascii(name[i])==8&&j>25)
		{
			gotoxy(j-1,5);
			clreol();
			i--;
			j--;
			goto L1;
		}
		else
		{
			if(toascii(name[i])==27)
			{
			   menu();
			}
			else
			{
				if(toascii(name[i])==13)
				{
					if(i<3)
					{
						goto L1;
					}
					else
					name[i]='\0';
					break;
				}
				else
				{
					if(isdigit(name[i]))
					{
						 gotoxy(j,5);
						 clreol();
						 goto L1;
					}
					else
					{
						if((!isalpha(name[i])&&!isdigit(name[i]))&&!isspace(name[i]))
						{
							gotoxy(j,5);
							clreol();
							goto L1;
						}
						else
						{
							if(i==0||isspace(name[i-1]))
							{
								gotoxy(j,5);
								clreol();
								name[i]=toupper(name[i]);
								gotoxy(j,5);
								cout<<name[i];

							}
							else
							{
								if(isupper(name[i-1])||islower(name[i-1]))
								{
									gotoxy(j,5);
									clreol();
									name[i]=tolower(name[i]);
									gotoxy(j,5);
									cout<<name[i];
								}
							}
						}
					}
				}
			}
		}
	}
	for(i=0,j=25;i<=50&&j<=75;i++,j++)
	{
		L2:
		gotoxy(j,7);
		address[i]=getche();
		if(isspace(address[0])||address[0]==44||address[0]==45)
		{
			gotoxy(j,7);
			clreol();
			goto L2;
		}
		if(isspace(address[i])&&isspace(address[i-1]))
			goto L2;
		if((isspace(address[i-1])&&address[i]==44)||(isspace(address[i-1])&&address[i]==45))
		{
			gotoxy(j,7);
			clreol();
			goto L2;
		}

		if((address[i]==44&&address[i-1]==45)||(address[i]==45&&address[i-1]==44))
		{
			gotoxy(j,7);
			clreol();
			goto L2;
		}
		if((address[i]==44&&address[i-1]==44)||(address[i]==45&&address[i-1]==45))
		{
			gotoxy(j,7);
			clreol();
			goto L2;
		}
		if(toascii(address[i])==8&&j>25)
		{
			gotoxy(j-1,7);
			clreol();
			i--;
			j--;
			goto L2;
		}
		else
		{
			if(toascii(address[i])==27)
			{
				menu();
			}
			else
			{
				if(toascii(address[i])==13)
				{
					if(i<9)
					{
						goto L2;
					}
					else
					{
						address[i]='\0';
						break;
					}
				}
				else
				{
					if(toascii(address[i])==44||toascii(address[i])==45)
					{
						i++,j++;
						goto L2;
					}
					else
					{
						if((!isalpha(address[i])&&!isdigit(address[i]))&&!isspace(address[i]))
						{
							gotoxy(j,7);
							clreol();
							goto L2;
						}
						else
						{
							if(i==0||isspace(address[i-1])||toascii(address[i-1])==44||toascii(address[i-1])==45)
							{
							 gotoxy(j,7);
							 clreol();
							 address[i]=toupper(address[i]);
							 gotoxy(j,7);
							 cout<<address[i];
							}
						}
					}
				}
			}
		}
	}
	L3:
	gotoxy(25,9);
	clreol();
	gotoxy(25,9);
	gender=getche();
	gender=toupper(gender) ;
	gotoxy(25,9);
	cout<<gender;
	if(gender=='F'||gender=='M')
	{
		L3_1:
		gotoxy(26,9);
		clreol();
		t=getche();
		if(toascii(t)==13)
		goto L6;
		else
		{
			if(toascii(t)==8)
			{
				goto L3;
			}
			else
			goto L3_1;
		}
	}
	else
	goto L3;

	L6:
	gotoxy(44,11);
	cin>>dd;
	gotoxy(44,12);
	cin>>mm;
	gotoxy(44,13);
	cin>>yy;
	int check=date(dd,mm,yy);
	if(check!=1)
	{
		gotoxy(44,11);
		clreol();
		gotoxy(44,12);
		clreol();
		gotoxy(44,13);
		clreol();
		error();
		goto L6;
	}


	for(i=0,j=25;i<10&&j<35;i++,j++)
	{
		L7:
		gotoxy(j,15);
		phone[i]=getche();
		if(toascii(phone[i])==8&&j>25)
		{
			gotoxy(j-1,15);
			clreol();
			i--,j--;
			goto L7;
		}
		else
		{
			if(toascii(phone[i])==27)
			{
			   menu();
			}
			else
			{
				if(toascii(phone[i])==13)
				{
					if(i<9)
					goto L7;
				}
				else
				{
					if(toascii(phone[0])!=55&&toascii(phone[0])!=56&&toascii(phone[0])!=57)
					{
						error();
						gotoxy(25,15);
						clreol();
						goto L7;
					}
					else
					{
						if(isdigit(phone[i]))
						{
							if(i==9)
							{
								phone[10]='\0';
								L7_1:
								gotoxy(35,15);
								clreol();
								t=getche();
								if(toascii(t)==13)
								break;
								else
								goto L7_1;
							}
							else
							{
								i++,j++;
								goto L7;
							}
						}
						else
						{
							gotoxy(j,15);
							clreol();
							goto L7;
						}
					}
				}
			}
		}
	}
	L8:
	gotoxy(25,17);
	clreol();
	gotoxy(25,17);
	m_status=getche();
	m_status=toupper(m_status) ;
	gotoxy(25,17);
	cout<<m_status;
	if(m_status=='Y'||m_status=='N')
	{
		L8_1:
		gotoxy(26,17);
		clreol();
		t=getche();
		if(toascii(t)==13)
		goto L9;
		else
		{
			if(toascii(t)==8)
			{
				goto L8;
			}
			else
			goto L8_1;
		}
	}
	else
	goto L8;
	L9:
	gotoxy(25,19);
	clreol();
	gotoxy(25,19);
	designation=getche();
	designation=toupper(designation) ;
	gotoxy(25,19);
	cout<<designation;
	if(designation=='P'||designation=='A'||designation=='C')
	{
		L9_1:
		gotoxy(26,19);
		clreol();
		t=getche();
		if(toascii(t)==13)
		goto L10;
		else
		{
			if(toascii(t)==8)
			{
			goto L9;
			}
			else
			goto L9_1;
		}
	}
	else
	goto L9;

	L10:
	char ch;
	int flag=0;
	gotoxy(15,23);
	cprintf("Are You Sure about the above information (Y/N) : ");
	cin>>ch;
	ch=toupper(ch);
	flag=load.reg_code();
	if(ch=='Y')
		load.reg_success(flag);
	else
		load.registration();

}

int employee::reg_code()
{
	int size=0;
	fetch.open("dBase.txt",ios::in);
	if(!fetch)
	{
		size=1;
		ecode=0;
	}
	fetch.close();
	return size;

}
void employee::reg_success(int flag)
{
	clrscr();
	int temp=0;
	if(flag!=1)
	{
		int ecode=0,pos=0;
		char ch;
			fetch.open("dBase.txt",ios::in);
			while(!fetch.eof())
			{
				cout<<flag;
				fetch.seekg(pos++);
				fetch>>ecode;
				ch=fetch.get();
				if(ch==' ')
				{
					fetch.read((char*)&load1,sizeof(load1));
					temp++;
					pos=fetch.tellg();
				}
			}
	}
	else
		ecode=0;
	fetch.close();
	temp++;
	ecode=temp;
	fetch.open("dBase.txt",ios::app);
	fetch<<ecode<<" ";
	fetch.write((char*)&load,sizeof(load));
	fetch.close();
	gotoxy(15,5);
	cprintf("Employee Name : ");
	gotoxy(30,5);
	cout<<name;
	if(designation=='P')
		salary=50000;
	else if(designation=='A')
		salary=20000;
	else if(designation=='C')
		salary=15000;
	gotoxy(15,7);
	cprintf("Employee Basic Salary : ");
	cout<<salary;
	gotoxy(15,9);
	cprintf("Employee Registration Number : ");
	cout<<ecode;
	char ch;
	gotoxy(37,23);
	cprintf("Goto Main Menu - Enter");
	ch=getch();
	if(ch==13)
		menu();
}

void employee::display()
{
	clrscr();
	design();
	textcolor(GREEN);
	gotoxy(32,2);
	cprintf("EMPLOYEE DETAILS");
	gotoxy(4,4);
	cprintf("Ecode");
	gotoxy(13,4);
	cprintf("Name");
	gotoxy(35,4);
	cprintf("Designation");
	gotoxy(53,4);
	cprintf("Salary");
	gotoxy(65,4);
	cprintf("DOJ");
	textcolor(145);
	gotoxy(55,23);
	cprintf("Backspace - Main Menu");

	int ecode=0,pos=0;
	char ch;
	fetch.open("dBase.txt",ios::in);
	while(!fetch.eof())
	{
		for(int y=6;y<22;y+=2)
		{
			fetch.seekg(pos++);
				fetch>>ecode;
			ch=fetch.get();
			if(ch==' ')
			{
				fetch.read((char*)&load,sizeof(load));
				pos=fetch.tellg();
				gotoxy(5,y);
				cout<<ecode;
				gotoxy(13,y);
				cout<<name;
				gotoxy(35,y);
				switch(designation)
				{
					case 'P': cout<<"Proffesor";
						  salary=50000;
						  break;
					case 'A': cout<<"Assistant";
						  salary=20000;
						  break;
					case 'C': cout<<"Clerk";
						  salary=15000;
						  break;
					default:  cout<<"-";
						  salary=0;
				}
				gotoxy(54,y);
				cout<<salary;
				gotoxy(65,y);
				cout<<dd<<"/"<<mm<<"/"<<yy;
			}
		}
	}
	fetch.close();
	p:
	ch=getch();
	if(ch==8)
		menu();
	else
		goto p;
}

void employee::show_employee()
{
	clrscr();
	int code=0,ecode=0,pos=0,check=0;
	char ch;
	gotoxy(10,7);
	cprintf("Employee Code : ");
	gotoxy(27,7);
	cin>>code;
	fetch.open("dBase.txt",ios::in);

	while(!fetch.eof())
	{
			fetch.seekg(pos++);
				fetch>>ecode;
			ch=fetch.get();
			if(ch==' ')
			{
				fetch.read((char*)&load,sizeof(load));
				pos=fetch.tellg();
				if(ecode==code)
				{
					check=1;
					fetch.close();
					clrscr();
					design();
					textcolor(GREEN);
					gotoxy(31,3);
					cprintf("EMPLOYEE DETAIL");
					gotoxy(10,6);
					cprintf("Employee Code :  ");
					cout<<ecode;
					gotoxy(10,8);
					cprintf("Name : ");
					cout<<name;
					gotoxy(10,10);
					cprintf("Address : ");
					cout<<address;
					gotoxy(10,12);
					cprintf("Gender : ");
					cout<<gender;
					gotoxy(10,14);
					cprintf("Date of Joining : ");
					cout<<dd<<"/"<<mm<<"/"<<yy;
					gotoxy(10,16);
					cprintf("Married : ");
					cout<<m_status;
					gotoxy(10,18);
					cprintf("Designation : ");
					switch(designation)
					{
						case 'P': cout<<"Professor";
							  salary=50000;
							  break;
						case 'A': cout<<"Assistant";
							  salary=20000;
							  break;
						case 'C': cout<<"Clerk";
							  salary=15000;
							  break;
						default:  cout<<"-";
							  salary=0;
					}
					gotoxy(10,20);
					cprintf("Salary : Rs. ");
					cout<<salary;
					textcolor(MAGENTA+BLINK);
					gotoxy(56,22);
					cprintf("Backspace - Menu");
					p:
					ch=getch();
					if(ch==8)
						menu();
					else
						goto p;
				}
			}
	}
	if(check==0)
	{
		fetch.close();
		loading();
		error();
		load.show_employee();
	}
}
void employee::pay_slip()
{
	clrscr();
	textcolor(RED);
	for(int i=2;i<77;i++)
	{
		gotoxy(i,2);
		cprintf("�");
		gotoxy(i,23);
		cprintf("�");

	}
	for(i=2;i<24;i++)
	{
		gotoxy(2,i);
		cprintf("��");
		gotoxy(77,i);
		cprintf("��");
	}
	int code=0,ecode=0,pos=0,check=0;
	float hra=0.0,ca=0.0,lta=0.0,mr=0.0,bs=0.0;
	char ch;
	gotoxy(10,7);
	cprintf("Employee Code : ");
	cin>>code;
	fetch.open("dBase.txt",ios::in);
	while(!fetch.eof())
	{
			fetch.seekg(pos++);
				fetch>>ecode;
			ch=fetch.get();
			if(ch==' ')
			{
				fetch.read((char*)&load,sizeof(load));
				pos=fetch.tellg();
				if(ecode==code)
				{
					check=1;
					fetch.close();
					clrscr();
					design();
					gotoxy(55,5) ;
					time_t t;
					time(&t);
					textcolor(YELLOW);
					cprintf(ctime(&t));
					textcolor(235);
					gotoxy(34,4) ;
					cprintf("PAY SLIP");
					textcolor(GREEN);
					gotoxy(6,7) ;
					cprintf("Employee Name : ");
					cout<<name;
					gotoxy(50,7) ;
					cprintf("Designation: ");
					switch(designation)
					{
						case 'P': cout<<"Proffesor";
							  salary=50000;
							  bs=(63*salary)/100;
							  hra=(15*salary)/100;
							  ca=(10*salary)/100;
							  lta=(5*salary)/100;
							  mr=(7*salary)/100;
							  break;
						case 'A': cout<<"Assistant";
							  salary=20000;
							  bs=(70*salary)/100;
							  hra=(12*salary)/100;
							  ca=(8*salary)/100;
							  lta=(4*salary)/100;
							  mr=(6*salary)/100;
							  break;
						case 'C': cout<<"Clerk";
							  salary=15000;
							  bs=(75*salary)/100;
							  hra=(12*salary)/100;
							  ca=(6*salary)/100;
							  lta=(3*salary)/100;
							  mr=(4*salary)/100;
							  break;
					}
					bs=(63*salary)/100;
					hra=(15*salary)/100;
					ca=(10*salary)/100;
					lta=(5*salary)/100;
					mr=(7*salary)/100;
					gotoxy(10,10) ;
					cprintf("BASIC Salary           :Rs. ");
					cout<<salary;
					gotoxy(10,12) ;
					cprintf("Mediacal Reimbursement :Rs. ");
					cout<<mr;
					gotoxy(10,14) ;
					cprintf("ALLOWANCE              :-");
					gotoxy(35,16) ;
					cprintf("House Rent Allowance  : Rs. ") ;
					cout<<hra;
					gotoxy(35,17) ;
					cprintf("Conveyance Allowance  : Rs. ") ;
					cout<<ca;
					gotoxy(35,18) ;
					cprintf("Leave Travel Allowance: Rs. ") ;
					cout<<lta;
					gotoxy(10,20) ;
					cprintf("NET Salary            : Rs. ");
					cout<<bs;
					textcolor(MAGENTA+BLINK);
					gotoxy(56,22);
					cprintf("Backspace - Menu");
					p:
					ch=getch();
					if(ch==8)
						menu();
					else
						goto p;
				}
			}
	}
	if(check==0)
	{
		fetch.close();
		loading();
		error();
		load.pay_slip();
	}
}

void employee::about()
{
	clrscr();
	design();
	textcolor(GREEN);
	gotoxy(15,5);
	cprintf("DESIGNED AND DEVELOPED BY");
	textcolor(RED);
	gotoxy(27,9);
	cprintf("Ayaan Khan");
	char ch;
	gotoxy(56,22);
	cprintf("Enter - Menu");
	p:
	ch=getch();
	if(ch==13)
		menu();
	else
		goto p;
  }
