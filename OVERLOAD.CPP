#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class str
{
char a[40],b[40],c[40];
public:
str()
{
strcpy(a,"\0");
strcpy(b,"\0");
strcpy(c,"\0");
}
void get1();
void get2();
void get3();
void operator+(str);
void operator=(str);
int operator==(str);
};
void str::operator+(str s1)
{
str s2;
strcat(a,s1.a);
strcat(s2.a,a);
cout<<"\nThe concatenated string is:";
cout<<s2.a;
}
void str::operator=(str s1)
{
strcpy(s1.c,c);
cout<<"\nThe original string is:"<<c;
cout<<"\nThe copied string is:"<<s1.c;
}
int str::operator==(str s1)
{
if(strcmp(b,s1.b)==0)
return 1;
else
return 0;
}
void str::get1()
{
cout<<"\nEnter value:";
gets(a);
cout<<"\nThe length of the string is:"<<strlen(a);
cout<<"\n**********************************\n";
}
void str::get2()
{
cout<<"\nEnter value:";
gets(b);
cout<<"\nThe length of the string is:"<<strlen(b);
cout<<"\n**********************************\n";
}
void str::get3()
{
cout<<"\nEnter value:";
gets(c);
cout<<"\nThe length of the string is:"<<strlen(c);
cout<<"\n**********************************\n";
}
void main()
{
clrscr();
int ch;
str o1,o2;
while(1)
{
cout<<"\nString operators in the choice are:";
cout<<"\n1.concatenation\n2.Comparision\n3.Copy\n4.Exit\n";
cout<<"\nEnter your choice:";
cin>>ch;
switch(ch)
{
case 1: cout<<"\nValue for object 1:";
	o1.get1();
	cout<<"\nValue for object 2:";
	o2.get1();
	o1+o2;
	break;
case 2: cout<<"\nValue for object 1:";
	o1.get2();
	cout<<"\nValue for object 2:";
	o2.get2();
	if(o1==o2)
	cout<<"\nThe two strings are equal";
	else
	cout<<"\nThe two strings are not equal";
	break;
case 3: cout<<"\nValue for object 1:";
	o1.get3();
	o1=o2;
	break;
case 4: exit(0);
	break;
}
}
getch();
}