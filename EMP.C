#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
struct Emp
{
   int empno;
   char name[40];
   int sal;
   char dob[16];
   char mobile[14];
   char post[20];
};
struct Emp e;
FILE  *f,*t;
void wel();
void signIn();
void addEmp();
void updEmp();
void disp();
void delEmp();
void main()
{
 /*
   char c;
   wel();
   signIn();
   while(1)
   {
       clrscr();
       printf("\n\n\t E M P L O Y E E  M A N A G E M E N T  S Y S T E M ");
       printf("\n\n\t\t1. Add New Employee.");
       printf("\n\n\t\t2. List of All Employees.");
       printf("\n\n\t\t3. Update Existing Employee.");
       printf("\n\n\t\t4. Delete Existing Employee.");
       printf("\n\n\t\t5. Search existing Employee.");
       printf("\n\n\t\t6. Sort Employee Records by Name.");
       printf("\n\n\t\t7. Sort Employee Records by Salary");
       printf("\n\n\t\t8. Employee Salary Slip");
       printf("\n\n\t\t0. for Exit");
       printf("\n\n\t Plz Enter ur Choice : ");
       c = getche();
       if(c=='1')
	 addEmp();
       if(c=='2')
	 disp();
       if(c=='4')
	 delEmp();
       if(c=='3')
	 updEmp();
       if(c=='0')
	 break;
       getch();
    }
  */
  updEmp();
}
void addEmp()
{
    clrscr();
    gotoxy(17,5);
    printf("E M P L O Y E E  R E G I S T A R T I O N   F O R M .");
    gotoxy(10,8);
    printf("EMPNO  : ");
    gotoxy(40,8);
    printf("ENAME  : ");
    gotoxy(10,10);
    printf("SALARY : ");
    gotoxy(40,10);
    printf("D.O.B. : ");
    gotoxy(10,12);
    printf("MOBILE : ");
    gotoxy(40,12);
    printf("POST   : ");
    gotoxy(20,8);
    scanf("%d",&e.empno);
    gotoxy(50,8);
    fflush(stdin); // clear the input buffer.
    gets(e.name);
    gotoxy(20,10);
    scanf("%d",&e.sal);
    gotoxy(50,10);
    fflush(stdin); // clear the input buffer.
    gets(e.dob);
    gotoxy(20,12);
    fflush(stdin); // clear the input buffer.
    gets(e.mobile);
    gotoxy(50,12);
    fflush(stdin); // clear the input buffer.
    gets(e.post);
    f = fopen("empdata.dat","ab");
    fwrite((char *)&e,sizeof(e),1,f);
    fclose(f);
    gotoxy(5,20);
    printf("Employee Record Successfully Inserted...");
    getch();
}
void disp()
{
    int ctr=0;
    f = fopen("empdata.dat","rb");
    clrscr();
    printf("\n ���������������������������������������������������������������������������ͻ");
    printf("\n � EMPNO � EMPLOYEE NAME. � SALARY � DATE OF BIRTH �MOBILE NUMBER� POST / JOB�");
    printf("\n ���������������������������������������������������������������������������Ķ");
    while(1)
    {
       fread((char *)&e,sizeof(e),1,f);
       if(feof(f))
	  break;
       printf("\n � %05d � %-15s� %05u  � %-14s� 0%-10s � %-9s �",e.empno,e.name,e.sal,e.dob,e.mobile,e.post);
       ctr++;
    }
    fclose(f);
    printf("\n ���������������������������������������������������������������������������ͼ");
    printf("\n %d. Rows Selected.",ctr);

}
void delEmp()
{
    int eno,ctr=0;
    f = fopen("empdata.dat","rb");
    t = fopen("tmp.dat","wb");
    clrscr();
    printf("\n\n\n\n\t\t Plz Enter empno for delete : ");
    scanf("%d",&eno);
    while(1)
    {
       fread((char *)&e,sizeof(e),1,f);
       if(feof(f))
	  break;
       if(eno==e.empno) // agar empno exist hai to
	   ctr = 1;
       else
	  fwrite((char *)&e,sizeof(e),1,t);
    }
    fclose(f);
    fclose(t);
    if(ctr==1)
    {
       printf("\n\n\n\t Employee Record Successfully Deleted.");
       remove("empdata.dat");
       rename("tmp.dat","empdata.dat");
    }
    else
    {
	printf("\n\n\n\t Sorry Employee Record not fount.");
	remove("tmp.dat");
    }
}
void updEmp()
{
    char c;
    int eno,ctr=0;
    f = fopen("empdata.dat","rb");
    t = fopen("tmp.dat","wb");
    clrscr();
    printf("\n\n\t\t Plz Enter empno for Update : ");
    scanf("%d",&eno);
    while(1)
    {
       fread((char *)&e,sizeof(e),1,f);
       if(feof(f))
	  break;
       if(eno==e.empno) // agar empno exist hai to
       {
	   ctr = 1;
	   gotoxy(5,6);
	   printf("Employee Record exists with following details : ");
    gotoxy(10,9);
    printf("EMPNO  : %d",e.empno);
    gotoxy(40,9);
    printf("ENAME  : %s",e.name);
    gotoxy(10,11);
    printf("SALARY : %d",e.sal);
    gotoxy(40,11);
    printf("D.O.B. : %s",e.dob);
    gotoxy(10,13);
    printf("MOBILE : %s",e.mobile);
    gotoxy(40,13);
    printf("POST   : %s",e.post);
    gotoxy(10,15);
    printf("Update Menu : ");
    gotoxy(15,16);
    printf(" E - Update Name     S - Update Salary    D - Update DOB");
    gotoxy(15,17);
    printf(" M - Update Mobile   P - Update JOB       S - Save & Exit");
    gotoxy(15,18);
    printf(" X - Exit without Save");
    gotoxy(10,19);
    printf("Plz Enter ur Choice : ");
    c = getche();


       fwrite((char *)&e,sizeof(e),1,t);

       }
       else
	  fwrite((char *)&e,sizeof(e),1,t);
    }
    fclose(f);
    fclose(t);
    if(ctr==1)
    {
       printf("\n\n\n\t Employee Record Successfully Deleted.");
       remove("empdata.dat");
       rename("tmp.dat","empdata.dat");
    }
    else
    {
	printf("\n\n\n\t Sorry Employee Record not fount.");
	remove("tmp.dat");
    }
    getch();
}

void wel()
{
   clrscr();
   gotoxy(15,9);
   printf("E M P L O Y E E   M A N A G E M E N T  S Y S T E M ");
   gotoxy(50,15);
   printf("DESIGNED BY : ");
   gotoxy(50,17);
   printf("PRAFUL DAKSH");
   gotoxy(50,18);
   printf("MOHIT KASHYAP");
   gotoxy(50,19);
   printf("DANISH QURESHI");
   gotoxy(5,22);
   printf("Press any key to contd....");
   getch();
}
void signIn()
{
     char uid[20];
     char c, pass[20];
     int i,ctr,counter=0;
     struct date d;
   while(counter<3)
   {
     clrscr();
     getdate(&d);
     gotoxy(60,2);
     printf("Date : %02d / %02d /%04d",d.da_day,d.da_mon,d.da_year);
     ctr = 0;
     gotoxy(20,10);
     printf("Plz Enter User Id : ");
     gotoxy(20,12);
     printf("Plz Enter Password: ");
     gotoxy(40,10);
     scanf("%s",uid);
     gotoxy(40,12);
     while(1)
     {
	 c = getch(); // get any char from keyboard
	 if(c==13) // enter key code
	   break;
	 pass[ctr++] = c;
	 printf("$");
     }
     pass[ctr] = 0; // null char for password terminate.
     gotoxy(22,16);
     printf("PLEASE WAIT ");
     for(i=0;i<=20;i++)
     {
	printf(".");
	delay(150);
     }
     if(strcmpi(uid,"kunal")==0 && strcmp(pass,"kumar@")==0) // admin
     {
	break;
     }
     else if(strcmpi(uid,"lalit")==0 && strcmp(pass,"rajput@")==0) // employee
     {
	break;
     }
     else
     {
	  gotoxy(32,5) ;
	  printf("Sorry Invalid Login Id & Password, try again..");
	  gotoxy(5,20);
	  printf("Press any key to contd...");
	  getch();
     }
     counter++;
  }
  if(counter==3)
  {
     clrscr();
     gotoxy(15,12);
     printf("Sorry U can't open this project, contact ur Administrator");
     gotoxy(5,20);
     printf("Press any key to contd...");
     getch();
     exit(0);
  }

}

