#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>
typedef struct student1
{
 float fees;
 int eno;
 char name[50];
 char course[20];
 int year;
 float per[12];
 char backs[30][30];
 float paid;
}student;
typedef struct teacher1
{
 char name[20];
 int ssn;
 int n;
 float salary;
 char designation[20];
 char subject[20][20];
}teacher;

typedef struct admin1
{
 float salary;
 float fees;
 float exp;
 float profit;
 float tax;
}admin;
void display();
void st_modify(int r);
void te_modify(int r);
void modify();
void solid(int a,int c,int b,int d,int k)
{
 int i,j;
 for(i=a;i<=b;i++)
 {
  for(j=c;j<=d;j++)
  putpixel(i,j,k);
 }
}
void sol(int a,int b)
{
 int i=0,j=0;
 setcolor(0);
 do
 {
  line(a,b-j,a+i,b);
  line(a,b-j,a-i,b);
  line(a,b+j,a+i,b);
  line(a,b+j,a-i,b);
  i++;
  j++;
  delay(10);
 }while(j<=570 || i<=570);
 setcolor(3);
}

void altersolid(int a,int b,int c,int d,int e)
{
 int i;
 i=a;
 do
 {
  solid(i,b,i+e,d,5);
  i=i+2*e;
 }while(i<=c);
}
void add(int n)
{
   int i;
   settextstyle(1,0,1);
   setcolor(2);
   outtextxy(175,160,"        STUDENT's DATA");
   outtextxy(175,190,"        TEACHER's DATA");
   if(n==0 || n==1)
   {
    outtextxy(175,220,"        ADMIN's DATA");
    if(n!=1)
    outtextxy(175,250,"EXIT");
   }
   else
   {
    if(n!=1)
    outtextxy(175,220,"EXIT");
   }
   outtextxy(160,290,"USE d -Down and s -Up and enter-confirm");
   setcolor(10);
   rectangle(150,80,580,330);
   rectangle(140,70,590,340);
   altersolid(150,71,570,79,10);
   altersolid(150,331,570,339,10);
   settextstyle(4,0,5);
   setcolor(3);
   if(n==0)
   {
    i=0;
    outtextxy(200,90," INSERT DATA ");
    setcolor(2);
    settextstyle(1,0,1);
    for(i=0;i<3;i++)
    outtextxy(175,160+30*i,"INSERT  ");
   }
   if(n==1)
   {
    i=0;
    outtextxy(200,90,"   VIEW DATA ");
    settextstyle(1,0,1);
    setcolor(2);
    for(i=0;i<3;i++)
    outtextxy(175,160+30*i,"  VIEW  ");
    outtextxy(175,250,"  EXIT");
   }
   if(n==2)
   {
    i=0;
    outtextxy(200,90," DELETE DATA ");
    settextstyle(1,0,1);
    setcolor(2);
    solid(160,165+30*2,450,190+30*2,0);
    for(i=0;i<2;i++)
    outtextxy(175,160+30*i,"DELETE ");
    outtextxy(175,220,"EXIT");
   }
   if(n==3)
   {
    i=0;
    outtextxy(200,90," MODIFY DATA ");
    settextstyle(1,0,1);
    setcolor(2);
    solid(160,165+30*2,450,190+30*2,0);
    for(i=0;i<2;i++)
    outtextxy(175,160+30*i,"MODIFY ");
    outtextxy(175,220,"EXIT");
   }
}
void new_profit()
{
 FILE *a,*temp;
 admin ad;
 a=fopen("admin.dat","ab+");
 temp=fopen("abc.dat","wb");
 fread(&ad,sizeof(ad),1,a);
 ad.profit=0;
 ad.tax=0;
 ad.profit=ad.fees-ad.salary-ad.exp;
 if(ad.profit<100000)
 {
  ad.tax=(ad.profit*0.2);
 }
 else if(ad.profit>100000 && ad.profit<200000)
 {
  ad.tax=(ad.profit*0.4);
 }
 else if(ad.profit>200000)
 {
  ad.tax=ad.profit*0.7;
 }
 fwrite(&ad,sizeof(ad),1,temp);
 remove("admin.dat");
 fcloseall();
 rename("abc.dat","admin.dat");
}
void add_admin()
{
 char ch1;
 FILE *a,*temp;
 admin ad;
 a=fopen("admin.dat","ab+");
 temp=fopen("abc.dat","wb");
 fread(&ad,sizeof(ad),1,a);
 ad.profit=0;
 ad.tax=0;
 solid(0,0,700,600,0);
 rectangle(100,50,500,420);
 rectangle(90,40,510,430);
 gotoxy(18,6);
 printf("Enter the other expenses of the university :");
 gotoxy(30,8);
 scanf("%f",&ad.exp);
 ad.profit=ad.fees-ad.salary-ad.exp;
 if(ad.profit<100000)
 {
	ad.tax=(ad.profit*0.2);
 }
 else if(ad.profit>100000 && ad.profit<200000)
 {
  ad.tax=(ad.profit*0.4);
 }
 else if(ad.profit>200000)
 {
   ad.tax=ad.profit*0.7;
 }
 clearviewport();
 rectangle(100,50,500,420);
 rectangle(90,40,510,430);
 gotoxy(18,6);
 printf("Entered details are :");
 gotoxy(18,8);
 printf("EXPENSES : %0.0f ",ad.exp);
 gotoxy(18,10);
 printf("CALCULATED PROFIT : %0.0f ",ad.profit);
 gotoxy(18,12);
 printf("CALCULATED TAX : %0.0f ",ad.tax);
 gotoxy(18,14);
 printf("WANT TO MAKE ANY CHANGE(y-yes\\n-no)");
 gotoxy(55,14);
 scanf("%s",&ch1);
 if(ch1=='n'||ch1=='N')
 {
  fwrite(&ad,sizeof(ad),1,temp);
  remove("admin.dat");
  fcloseall();
  rename("abc.dat","admin.dat");
 }
 else if(ch1=='y'|| ch1=='Y')
 {
   fcloseall();
   clearviewport();
   add_admin();
 }
}
void add_teacher()
{
 int i,n,x,p,y,k,m,b,j;
 char ch1;
 teacher t;
 admin a;
 FILE *te,*ad,*temp;
 te=fopen("teacher.dat","ab+");
 ad=fopen("admin.dat","ab+");
 temp=fopen("abc.dat","wb");
 fseek(te,0,SEEK_END);
 solid(0,0,700,600,0);
 rectangle(100,50,500,420);
 rectangle(90,40,510,430);
 gotoxy(18,6);
 printf("NAME :");
 gotoxy(18,8);
 printf("SSN : ");
 gotoxy(18,10);
 printf("DESIGNATION : ");
 gotoxy(18,12);
 printf("SALARY :");
 gotoxy(18,14);
 printf("NO. OF SUBJECT HE/SHE TEACHERS :");
 gotoxy(50,6);
 scanf("%s",&t.name);
 gotoxy(50,8);
 scanf("%d",&t.ssn);
 gotoxy(50,10);
 scanf("%s",&t.designation);
 gotoxy(50,12);
 scanf("%f",&t.salary);
 gotoxy(50,14);
 scanf("%d",&t.n);
 if(t.n>0)
 {
  gotoxy(18,16);
  printf("SUBJECT :");
 }
 k=0;
 if(t.n<=4)
  k=t.n;
 else
  k=4;
 for(i=0;i<k;i++)
 {
  if(i<4)
  {
   gotoxy(50,16+2*i);
   scanf("%s",&t.subject[i]);
  }
 }
 if(i>3)
 {
  k=t.n/4;
  for(j=0;j<k;j++)
  {
   solid(300,230,480,400,0);
   if(j==k-1)
    b=t.n%4;
   else
    b=4;
   for(m=0;m<b;m++)
   {
    gotoxy(50,16+2*(m));
    scanf("%s",&t.subject[4+4*j+m]);
   }
  }
 }
 clearviewport();
 rectangle(100,50,500,420);
 rectangle(90,40,510,430);
 gotoxy(18,6);
 printf("Entered details are :");
 gotoxy(18,8);
 printf("NAME : %s ",t.name);
 gotoxy(18,9);
 printf("SSN : %d",t.ssn);
 gotoxy(18,10);
 printf("DESIGNATION: %s ",t.designation);
 gotoxy(18,11);
 printf("SALARY : %0.1f",t.salary);
 gotoxy(18,12);
 printf("SUBJECT :");
 i=12;
 for(k=0;k<t.n;k++)
 {
  gotoxy(30,i);
  printf("%s",t.subject[k]);
  i++;
 }
 gotoxy(20,25);
 printf("WANT TO MAKE ANY CHANGE(y-yes\\n-no)");
 gotoxy(55,25);
 scanf("%s",&ch1);
  x=ftell(te);
  p=(!feof(te));
  fwrite(&t,sizeof(teacher),1,te);
  y=ftell(te);
  fread(&a,sizeof(a),1,ad);
  a.salary=a.salary+t.salary;
  fwrite(&a,sizeof(a),1,temp);
  remove("admin.dat");
  fcloseall();
  rename("abc.dat","admin.dat");
  new_profit();
  if(ch1=='y'||ch1=='Y');
 {
  te_modify(t.ssn);
 }
}
void add_student()
{
 int i,j=0,l,p,k=0;
 struct date d;
 char ch,c,ch1;
 student st;
 admin a;
 float left;
 FILE *stu,*ad,*temp;
 getdate(&d);
 a.salary=0;
 a.fees=0;
 a.profit=0;
 a.tax=0;
 a.exp=0;
 while(strcmp(st.backs[k],'\0')!=0)
 {
  strcpy(st.backs[k],'\0');
  k++;
 }

 stu = fopen("Student.dat","ab+");
 ad=fopen("admin.dat","ab+");
 temp=fopen("abc.dat","wb");
 fseek(stu,0,SEEK_END);
 solid(0,0,700,600,0);
 rectangle(100,50,500,420);
 rectangle(90,40,510,430);
 gotoxy(18,6);
 printf("NAME :");
 gotoxy(18,8);
 printf("ENO : ");
 gotoxy(18,10);
 printf("YEAR OF ADDMISSION : ");
 gotoxy(18,12);
 printf("COURSE : ");
 gotoxy(50,6);
 scanf("%s",&st.name);
 gotoxy(50,8);
 scanf("%d",&st.eno);
 gotoxy(50,10);
 scanf("%d",&st.year);
 gotoxy(50,12);
 scanf("%s",&st.course);
 if(strcmpi(st.course,"btech")==0)
 {
  gotoxy(18,14);
  printf("st.fees of b.tech is 47000/-");
  gotoxy(18,15);
  printf("How much has the student paid?");
  gotoxy(50,15);
  scanf("%f",&st.fees);
  st.paid=47000-st.fees;
  gotoxy(18,16);
  printf("fees left to be paid is %0.0f",st.paid);
 }
 if(strcmpi(st.course,"mca")==0)
 {
  gotoxy(18,14);
  printf("fees of mca is 70000/-");
  gotoxy(18,15);
  printf("How much has the student paid?");
  gotoxy(50,15);
  scanf("%f",&st.fees);
  st.paid=70000-st.fees;
  gotoxy(18,16);
  printf("fees left to be paid is %0.0f",st.paid);
 }
 if(strcmpi(st.course,"mtech")==0)
 {
  gotoxy(18,14);
  printf("fees of m.tech is 50000/-");
  gotoxy(18,15);
  printf("How much has the student paid?");
  gotoxy(50,15);
  scanf("%f",&st.fees);
  st.paid=50000-st.fees;
  gotoxy(18,16);
  printf("fees left to be paid is %f",st.paid);
 }
 if(strcmpi(st.course,"bca")==0)
 {
  gotoxy(18,14);
  printf("fees of bca is 60000/-");
  gotoxy(18,15);
  printf("How much has the student paid?");
  gotoxy(50,15);
  scanf("%f",&st.fees);
  st.paid=60000-st.fees;
  gotoxy(18,16);
  printf("fees left to be paid is ");
  gotoxy(18,16);
  printf("%0.0f",&st.paid);
 }
 l=d.da_year;
 if(l-st.year>0)
 {
  gotoxy(18,18);
  printf("Enter the performance=");
 }
 p=2*(l-st.year);
 for(i=0;i<p;i++)
 {
  solid(101,300,499,419,0);
  gotoxy(18,20);
  printf("Enter the result of semester %d=",i+1);
  gotoxy(50,20);
  scanf("%f",&st.per[i]);
  gotoxy(18,22);
  printf("Any backs in semester %d?",i+1);
  gotoxy(50,22);
  scanf("%s",&ch);
  if(ch=='y'||ch=='Y')
  {
   do
   {
    solid(101,360,499,399,0);
    gotoxy(18,24);
    printf("Enter the back :");
    gotoxy(50,24);
    scanf("%s",st.backs[j]);
    gotoxy(18,25);
    printf("More backs to enter?");
    gotoxy(50,25);
    scanf("%s",&c);
    j++;
   }while(c=='y'||c=='Y');
  }
 }
 clearviewport();
 rectangle(100,50,500,420);
 rectangle(90,40,510,430);
 gotoxy(18,6);
 printf("Entered details are :");
 gotoxy(18,8);
 printf("NAME : %s ",st.name);
 gotoxy(18,9);
 printf("ENO : %d",st.eno);
 gotoxy(18,10);
 printf("YEAR OF ADDMISSION : %d ",st.year);
 gotoxy(18,11);
 printf("COURSE : %s",st.course);
 gotoxy(18,12);
 printf("FEE PAID : %0.0f ",st.fees);
 gotoxy(18,13);
 printf("FEE BALANCE : %0.0f ",st.paid);
 gotoxy(18,14);
 printf("PERFORMANCE");
 gotoxy(45,15);
 printf("BACKS");
 gotoxy(28,15);
 printf("PERCENTAGES");
 gotoxy(18,15);
 printf("SEMESTER");
 k=0;
 for(i=16;i<p+16;i++)
 {
  j=0;
  gotoxy(20,i);
  printf("%d",k+1);
  gotoxy(32,i);
  printf("%0.1f",st.per[k]);
  k++;
 }
 k=0;
 i=16;
 while(strcmp(st.backs[k],'\0')!=0 && i<25)
 {
  gotoxy(45,i);
  printf("%s",st.backs[k]);
  i++;
  k++;
 }
 gotoxy(20,25);
 printf("WANT TO MAKE ANY CHANGE(y-yes\\n-no)");
 gotoxy(55,25);
 scanf("%s",&ch1);
  fseek(ad,0,SEEK_SET);
  fread(&a,sizeof(a),1,ad);
  a.fees=a.fees+st.fees;
  fwrite(&a,sizeof(a),1,temp);
  remove("admin.dat");
  fclose(ad);
  fclose(temp);
  rename("abc.dat","admin.dat");
  fwrite(&st,sizeof(st),1,stu);
  fclose(stu);
  new_profit();
 if(ch1=='y'||ch1=='Y')
 {
  st_modify(st.eno);
 }
}

void insert()
{
 char ch1,ch,ch2;
 int n=0;
 do
 {
 solid(160,165+30*n,450,190+30*n,8);
 add(0);
 while(1)
 {
  ch1=getch();
  if(ch1=='\r')
  {
   sound(500);
   delay(100);
   nosound();
   sol(365,205);
   if(n==0)
   {
    add_student();
    break;
   }
   if(n==1)
   {
    add_teacher();
    break;
   }
   if(n==2)
   {
    add_admin();
    break;
   }
   if(n==3)
   {
    clearviewport();
    display();
    break;
   }
  }
  else
  n=up_down(ch1,3,n,1);
  //print
 }
 settextstyle(1,0,1);
 outtextxy(110,390,"Wish to add more data..??");
 ch=getch();
 if(ch=='n')
  outtextxy(550,390,"n");
 if(ch=='N')
  outtextxy(550,390,"N");
 if(ch=='y')
  outtextxy(550,390,"y");
 if(ch=='Y')
  outtextxy(550,390,"Y");
 }while(ch=='y'||ch=='Y');
 if(ch=='n'||ch=='N')
 {
  outtextxy(110,440,"DO YOU WISH TO ADD/VIEW/DELETE/MODOIFY MORE DATA.?");
  ch2=getch();
  if(ch2=='y')
  outtextxy(550,440,"y");
  else if(ch2=='Y')
  outtextxy(550,440,"Y");
  else if(ch2=='N')
  outtextxy(550,440,"N");
  else if(ch2=='n')
  outtextxy(550,440,"n");
  if(ch2=='y'||ch2=='Y')
  display();
  else if(ch2=='n'||ch2=='N')
   exit(0);
 }
}
void te_display()
{
 int i,j,x,p,q,k=0,m=0;
 FILE *fp=fopen("teacher.dat","rb");
 teacher t;
 q=0;
 solid(0,0,700,600,0);
 for(i=2;(!feof(fp));i++)
 {
  if(i==2)
  {
   setcolor(3);
   settextstyle(1,0,2);
   outtextxy(20,0,"SSN");
   outtextxy(135,0,"NAME");
   outtextxy(250,0,"SALARY");
   outtextxy(360,0,"DESIGNATION");
   outtextxy(540,0,"SUBJECT");
  }
  else
  {
   j=0;
   x=ftell(fp);
   fread(&t,sizeof(t),1,fp);
   p=(!feof(fp));
   q=ftell(fp);
   while(strcmp(t.subject[j],'\0')!=0)
   {
    m++;
    j++;
   }
   if((i+m)>25)
   {
    getch();
    solid(0,50,630,500,0);
    i=5;
   }
   if(i==3)
   {
    i=5;
   }
   m=0;
   j=0;
   if(x!=q)
   {
   gotoxy(4,i);
   printf("%d",t.ssn);
   gotoxy(18,i);
   printf("%s",t.name);
   gotoxy(34,i);
   printf("%0.0f",t.salary);
   gotoxy(50,i);
   printf("%s",t.designation);
   while(j<t.n)
   {
    gotoxy(69,i);
    printf("%s",t.subject[j]);
    j++;
    i++;
   }
   }
  }
 }
}
void st_display()
{
 int i,j,l,k,x,q,m=0;
 student st;
 FILE *fp=fopen("student.dat","rb");
 solid(0,0,700,600,0);
 for(i=2;(!feof(fp));i++)
 {
  if(i==2)
  {
   setcolor(3);
   settextstyle(1,0,2);
   outtextxy(0,0,"ENO");
   outtextxy(55,0,"NAME");
   outtextxy(125,0,"COURSE");
   outtextxy(215,0,"YEAR");
   outtextxy(285,0,"PERCENTAGE");
   outtextxy(425,0,"BACKS");
   outtextxy(498,0,"FEE BALANCE");
  }
  else
  {
   j=0;
   x=ftell(fp);
   fread(&st,sizeof(st),1,fp);
   q=ftell(fp);
   while(strcmp(st.backs[j],'\0')!=0)
   {
    m++;
    j++;
   }
   if((i+m)>25)
   {
    getch();
    solid(0,50,630,500,0);
    i=5;
   }
   if(i==3)
   {
    i=5;
   }
   m=0;
   j=0;
   if(x!=q)
   {
    gotoxy(1,i);
    printf("%d",st.eno);
    gotoxy(8,i);
    printf("%s",st.name);
    gotoxy(20,i);
    printf("%s",st.course);
    gotoxy(30,i);
    printf("%d",st.year);
    gotoxy(72,i);
    printf("%0.0f",st.paid);
    k=i;
    while(strcmp(st.backs[j],'\0')!=0)
    {
     gotoxy(55,i);
     printf("%s",st.backs[j]);
     i++;
     j++;
    }
    for(l=0;l<2*(2013-st.year);l++)
    {
     gotoxy(43,k);
     printf("%0.1f",st.per[l]);
     k++;
    }
    if(k>i)
    i=k;
   }
  }
 }
 gotoxy(1,i);
}

void admin_display()
{
 int i,x,q;
 FILE *fp=fopen("admin.dat","rb");
 admin a;
 solid(0,0,700,600,0);
 for(i=2;i<=25 && (!feof(fp));i++)
 {
  if(i==2)
  {
   setcolor(3);
   settextstyle(1,0,2);
   outtextxy(20,0,"SALARY");
   outtextxy(135,0,"FEES");
   outtextxy(250,0,"EXPENDITURE");
   outtextxy(430,0,"PROFIT");
   outtextxy(570,0,"TAX");
  }
  else
  {
   x=ftell(fp);
   fread(&a,sizeof(a),1,fp);
   q=ftell(fp);
   if(x!=q)
   {
    gotoxy(4,i);
    printf("%0.0f",a.salary);
    gotoxy(18,i);
    printf("%0.0f",a.fees);
    gotoxy(33,i);
    printf("%0.0f",a.exp);
    gotoxy(55,i);
    printf("%0.0f",a.profit);
    gotoxy(73,i);
    printf("%0.0f",a.tax);
    i++;
   }
  }
 }
}
void st_delet()
{
  FILE *st,*temp,*ad,*temp1;
  student stu;
  admin a;
  char q;
  int flag,en,x,y;
  do
  {
   flag=0;
   st=fopen("student.dat","rb");
   temp=fopen("abc.dat","wb");
   ad=fopen("admin.dat","ab+");
   temp1=fopen("xyz.dat","wb");
   solid(0,0,700,600,0);
   rectangle(100,50,500,420);
   rectangle(90,40,510,430);
   gotoxy(18,6);
   printf("ENO  :");
   gotoxy(50,6);
   scanf("%d",&en);
   while(!feof(st))
   {
    x=ftell(st);
    fread(&stu,sizeof(student),1,st);
    y=ftell(st);
    if(x!=y)
    {
     if(stu.eno==en)
     {
      flag=1;
      fread(&a,sizeof(a),1,ad);
      a.fees=a.fees-stu.fees;
      fwrite(&a,sizeof(a),1,temp1);
      remove("admin.dat");
      fclose(ad);
      fclose(temp1);
      rename("xyz.dat","admin.dat");
     }
     else
     fwrite(&stu,sizeof(student),1,temp);
    }
   }

   if(flag==0)
   {
    gotoxy(18,9);
    printf("Invalid ENO");
   }
   else
   {
    gotoxy(18,9);
    printf("Record deleted!!");
   }
   remove("student.dat");
   fcloseall();
   rename("abc.dat","student.dat");
   gotoxy(18,12);
   printf("DELETE MORE.?");
   gotoxy(31,12);
   scanf("%s",&q);
  }while(q=='y'||q=='Y');
 new_profit();
}
void te_delet()
{
  FILE *t,*tc,*ad,*temp1;
  teacher t1;
  admin a;
  char q;
  int flag=0,en,x,y;
  t=fopen("teacher.dat","rb");
  tc=fopen("xyz.dat","wb");
  ad=fopen("admin.dat","ab+");
  temp1=fopen("abc.dat","wb");
  do
  {
  solid(0,0,700,600,0);
   rectangle(100,50,500,420);
   rectangle(90,40,510,430);
   gotoxy(18,6);
   printf("ENTER THE SSN :");
   gotoxy(50,6);
   scanf("%d",&en);
   while(!feof(t))
   {
    x=ftell(t);
    fread(&t1,sizeof(teacher),1,t);
    y=ftell(t);
    if(x!=y)
    {
     if(t1.ssn==en)
     {
       flag=1;
       fread(&a,sizeof(admin),1,ad);
       a.salary = a.salary - t1.salary;
       fwrite(&a,sizeof(a),1,temp1);
       remove("admin.dat");
       fclose(ad);
       fclose(temp1);
       rename("abc.dat","admin.dat");
     }
     else
     fwrite(&t1,sizeof(teacher),1,tc);
    }
   }
   if(flag==0)
   {
    gotoxy(18,9);
    printf("Invalid SSN");
   }
   else
   {
    gotoxy(18,9);
    printf("Record deleted!!");
   }
   remove("teacher.dat");
   fcloseall();
   rename("xyz.dat","teacher.dat");
   gotoxy(18,12);
   printf("DELETE MORE.?");
   gotoxy(50,12);
   scanf("%s",&q);
  }while(q=='y'||q=='Y');
 new_profit();
}
void delet()
{
 char ch1,n=0;
 solid(160,165+30*n,450,190+30*n,8);
 add(2);
 while(1)
 {
  ch1=getch();
  if(ch1=='\r')
  {
   sound(500);
   delay(100);
   nosound();
   if(n==0)
   {
   st_delet();
    break;
   }
   if(n==1)
   {
    te_delet();
    break;
   }
   if(n==2)
   {
    clearviewport();
    display();
    break;
   }
  }
  else
  n=up_down(ch1,2,n,3);
   //print
 }
}

void view()
{
 char ch1,n=0,ch2;
 solid(160,165+30*n,450,190+30*n,8);
 add(1);
 while(1)
 {
  ch1=getch();
  if(ch1=='\r')
  {
   sound(500);
   delay(100);
   nosound();
   if(n==0)
   {
    st_display();
    break;
   }
   if(n==1)
   {
    te_display();
    break;
   }
   if(n==2)
   {
    admin_display();
    break;
   }
   if(n==3)
   {
    clearviewport();
    display();
    break;
   }
  }
  else
  n=up_down(ch1,3,n,2);
   //print
 }
 outtextxy(110,440,"DO YOU WISH TO ADD/VIEW/DELETE/MODOIFY MORE DATA.?");
 ch2=getch();
 if(ch2=='y')
 outtextxy(550,440,"y");
 else if(ch2=='Y')
 outtextxy(550,440,"Y");
 else if(ch2=='N')
 outtextxy(550,440,"N");
 else if(ch2=='n')
 outtextxy(550,440,"n");
 if(ch2=='y'||ch2=='Y')
 display();
 else if(ch2=='n'||ch2=='N')
 exit(0);


}
int add_modify(int i)
{
   int n=0;
   char ch1;
  while(1)
  {
   solid(160,165+30*n,450,190+30*n,8);
   settextstyle(1,0,1);
   setcolor(2);
   if(i==0)
   {
    outtextxy(175,160,"NAME");
    outtextxy(175,190,"COURSE");
    outtextxy(175,220,"ENO");
    outtextxy(175,250,"YEAR");
    outtextxy(175,280,"PERCENTAGE");
    outtextxy(175,310,"BACKS");
    outtextxy(175,340,"EXIT");
   }
   else if(i==1)
   {
    outtextxy(175,160,"NAME");
    outtextxy(175,190,"SSN");
    outtextxy(175,220,"SALARY");
    outtextxy(175,250,"SUBJECT");
    outtextxy(175,280,"DESIGNATION");
    outtextxy(175,310,"EXIT");
   }
   outtextxy(160,370,"USE d -Down and s -Up and enter-confirm");
   ch1=getch();
   if(ch1=='\r')
   {
    return n;
   }
   else
   {
    if(i==0)
    n=up_down(ch1,6,n,5);
    if(i==1)
    n=up_down(ch1,5,n,6);
   }
  }
}
void st_modify(int r)
{
  struct date d1;
  FILE *s,*temp,*ad,*temp1;
  admin ab;
  student stu,stu2;
  char q,ch1,ch2,ch3,c,ch,sub[30][30],g[20];
  int flag=0,en,a=0,p,l,i=0,j=0,d=0,x,y,k,o=0,u=0,w,flag1=0;
  getdate(&d1);
  s=fopen("student.dat","rb");
  temp=fopen("abc.dat","wb");
  ad=fopen("admin.dat","ab+");
  temp1=fopen("xyz.dat","wb");

  if(r==0)
  {
  solid(0,0,700,600,0);
  rectangle(100,50,500,420);
  rectangle(90,40,510,430);
  gotoxy(18,6);
  printf("Enter the eno :");
  gotoxy(50,6);
  scanf("%d",&en);
  }
  else
   en=r;
  while(!feof(s))
  {
   x=ftell(s);
   fread(&stu,sizeof(student),1,s);
   y=ftell(s);
   if(x!=y)
   {
    if(stu.eno!=en)
    fwrite(&stu,sizeof(student),1,temp);
    else
    {
     flag=1;
     stu2=stu;
    }
   }
  }
  if(flag==0)
  {
   solid(0,0,700,600,0);
   rectangle(100,50,500,420);
   rectangle(90,40,510,430);
   gotoxy(18,9);
   printf("Invalid ENO");
  }
  else
  {
   if(r==0)
   {
    l=d1.da_year;
    p=2*(l-stu2.year);
    gotoxy(18,7);
    printf("STUDENT DETAILS ::");
    gotoxy(18,8);
    printf("NAME : %s ",stu2.name);
    gotoxy(18,9);
    printf("ENO : %d",stu2.eno);
    gotoxy(18,10);
    printf("YEAR OF ADDMISSION : %d ",stu2.year);
    gotoxy(18,11);
    printf("COURSE : %s",stu2.course);
    gotoxy(18,12);
    printf("FEE PAID : %0.0f ",stu2.fees);
    gotoxy(18,13);
    printf("FEE BALANCE : %0.0f ",stu2.paid);
    gotoxy(18,14);
    printf("PERFORMANCE");
    gotoxy(45,15);
    printf("BACKS");
    gotoxy(28,15);
    printf("PERCENTAGES");
    gotoxy(18,15);
    printf("SEMESTER");
    k=0;
    for(i=16;i<p+16;i++)
    {
     j=0;
     gotoxy(20,i);
     printf("%d",k+1);
     gotoxy(32,i);
     printf("%0.1f",stu2.per[k]);
     k++;
    }
    k=0;
   i=16;
   while(strcmp(stu2.backs[k],'\0')!=0 && i<25)
   {
    gotoxy(45,i);
    printf("%s",stu2.backs[k]);
    i++;
    k++;
   }
  }
  getch();
  solid(0,0,700,600,0);
  setcolor(3);
  settextstyle(4,0,5);
  outtextxy(200,90,"  M O D I F Y ");
  setcolor(10);
  rectangle(150,80,580,390);
  rectangle(140,70,590,400);
  a=add_modify(0);
  if(a!=6)
  {
   clearviewport();
   rectangle(100,50,500,420);
   rectangle(90,40,510,430);
  }
  switch(a+1)
  {
    case 1:gotoxy(18,6);
	   printf("NEW NAME :");
	   gotoxy(50,6);
	   scanf("%s",stu2.name);
	   break;
    case 2:gotoxy(18,6);
	   printf("is the student upgraded .?");
	   gotoxy(50,6);
	   scanf("%s",&ch1);
	   if(ch1=='n'||ch1=='N')
	   {
	    gotoxy(18,7);
	    printf("NEW COURSE");
	    gotoxy(50,7);
	    scanf("%s",stu2.course);
	   }
	   else
	   {
	    fread(&ab,sizeof(ab),1,ad);
	    ab.fees=ab.fees-stu2.fees;
	    gotoxy(18,7);
	    printf("NEW COURSE ::");
	    gotoxy(50,7);
	    scanf("%s",stu2.course);
	    gotoxy(18,8);
	    printf("NEW ENO ::");
	    gotoxy(50,8);
	    scanf("%d",&stu2.eno);
	   }
	   stu2.year=d1.da_year;
	   if(strcmpi(stu2.course,"btech")==0)
	   {
	    gotoxy(18,9);
	    printf("Fees of b.tech is 47000/-");
	    gotoxy(18,10);
	    printf("How much has the student paid?");
	    gotoxy(50,10);
	    scanf("%f",&stu2.fees);
	    stu2.paid=47000-stu2.fees;
	    gotoxy(18,12);
	    printf("Fees left to be paid is %f",stu2.paid);
	   }
	   if(strcmpi(stu2.course,"mca")==0)
	   {
	    gotoxy(18,9);
	    printf("Fees of mca is 70000/-");
	    gotoxy(18,10);
	    printf("How much has the student paid?");
	    gotoxy(50,10);
	    scanf("%f",&stu2.fees);
	    stu2.paid=70000-stu2.fees;
	    gotoxy(18,12);
	    printf("Fees left to be paid is %f",stu2.paid);
	   }
	   if(strcmpi(stu2.course,"mtech")==0)
	   {
	    gotoxy(18,9);
	    printf("Fees of m.tech is 50000/-");
	    gotoxy(18,10);
	    printf("How much has the student paid?");
	    gotoxy(50,10);
	    scanf("%f",&stu2.fees);
	    stu2.paid=50000-stu2.fees;
	    gotoxy(18,12);
	    printf("Fees left to be paid is %f",stu2.paid);
	   }
	   if(strcmpi(stu2.course,"bca")==0)
	   {
	    gotoxy(18,9);
	    printf("Fees of bca is 60000/-");
	    gotoxy(18,10);
	    printf("How much has the student paid?");
	    gotoxy(50,10);
	    scanf("%f",&stu2.fees);
	    stu2.paid=60000-stu2.fees;
	    gotoxy(18,12);
	    printf("Fees left to be paid is %f",stu2.paid);
	   }
	   for(k=0;k<30;k++)
	   strcpy(stu2.backs[k],'\0');

	   for(k=0;k<12;k++)
	   stu2.per[k]=0;

	   fread(&ab,sizeof(ab),1,ad);
	   ab.fees=ab.fees+stu2.fees;
	   fwrite(&ab,sizeof(ab),1,temp1);
	   remove("admin.dat");
	   fclose(ad);
	   fclose(temp1);
	   rename("xyz.dat","admin.dat");
	   break;
    case 3:gotoxy(18,6);
	   printf("NEW ENO.:");
	   gotoxy(50,6);
	   scanf("%d",&stu2.eno);
	   break;
    case 4:gotoxy(18,6);
	   printf("NEW YEAR :");
	   gotoxy(50,6);
	   scanf("%d",&stu2.year);
	   for(k=0;k<12;k++)
	   stu2.per[k]=0;
	   if(l-stu2.year>0)
	   {
	     gotoxy(18,8);
	     printf("Enter the correct performance...!!");
	   }
	   p=2*(l-stu2.year);
	   for(i=0;i<p;i++)
	   {
	     gotoxy(18,10);
	     printf("Enter the result of semester %d=",i+1);
	     gotoxy(50,10);
	     scanf("%f",&stu2.per[i]);
	     gotoxy(18,12);
	     printf("Any backs in semester %d?",i+1);
	     gotoxy(50,12);
	     scanf("%s",&ch);
	     if(ch=='y'||ch=='Y')
	     {
	      do
	      {
	       solid(101,200,499,399,0);
	       gotoxy(18,14);
	       printf("Enter the back :");
	       gotoxy(50,14);
	       scanf("%s",stu2.backs[j]);
	       gotoxy(18,16);
	       printf("More backs to enter?");
	       gotoxy(50,16);
	       scanf("%s",&c);
	       j++;
	      }while(c=='y'||c=='Y');
	     }
	    solid(101,130,499,419,0);
	   }
	   break;
    case 5:do
	   {
	    solid(101,51,499,419,0);
	    gotoxy(18,6);
	    printf("SEMISTER ::");
	    gotoxy(50,6);
	    scanf("%d",&p);
	    gotoxy(18,8);
	    printf("NEW PERCENTAGE ::");
	    gotoxy(50,8);
	    scanf("%f",&stu2.per[p-1]);
	    gotoxy(18,10);
	    printf("CHANGE MORE ?");
	    gotoxy(50,10);
	    scanf("%s",&ch2);
	   }while(ch2=='y'||ch2=='Y');
	   break;
    case 6:  gotoxy(18,6);
	     printf("What do you wanna do..??");
	     gotoxy(18,7);
	     printf("1.add back..");
	     gotoxy(30,7);
	     printf("2.delete back..");
	     gotoxy(50,7);
	     scanf("%d",&p);
	     switch(p)
	     {
		case 1: while(stu2.backs[o][0]!='\0')
			o++;
			do
			{
			 solid(101,150,499,419,0);
			 gotoxy(18,9);
			 printf("Enter the new subject::");
			 gotoxy(50,9);
			 scanf("%s",&stu2.backs[o++]);
			 gotoxy(18,11);
			 printf("ADD MORE BACKS ? :");
			 gotoxy(50,11);
			 scanf("%s",&ch1);
			}while(ch1=='y'||ch1=='Y');
			break;
		case 2:do
		       {
			u=0;
			strcpy(g,'\0');
			gotoxy(18,9);
			printf("Which back you want to delete::");
			gotoxy(50,9);
			scanf("%s",&g);
			while(strcmpi(stu2.backs[u],g)!=0)
			{
			 strcpy(sub[u],stu2.backs[u]);
			 u++;
			}
			u++;
			while(stu2.backs[u][0]!='\0')
			{
			 strcpy(sub[u-1],stu2.backs[u]);
			 u++;
			}
			for(w=0;w<u-1;w++)
			{
			 strcpy(stu2.backs[w],sub[w]);
			}
			strcpy(stu2.backs[w],'\0');
			if(flag1==0)
			{
			 gotoxy(18,12);
			 printf("back doesnot exists");
			}
			gotoxy(18,14);
			printf("DELETE MORE ? :");
			gotoxy(50,14);
			scanf("%s",&ch2);
			solid(101,101,499,419,0);
		       }while(ch2=='y'||ch2=='Y');
		       break;
		 default:printf("Invalid input");
		}
		break;
   case 7:if(r!=0)
	  {
	   outtextxy(110,440,"DO YOU WISH TO ADD/VIEW/DELETE/MODOIFY MORE DATA.?");
	   ch2=getch();
	   if(ch2=='y')
	   outtextxy(550,440,"y");
	   else if(ch2=='Y')
	   outtextxy(550,440,"Y");
	   else if(ch2=='N')
	   outtextxy(550,440,"N");
	   else if(ch2=='n')
	   outtextxy(550,440,"n");
	   if(ch2=='y'||ch2=='Y')
	   display();
	   else if(ch2=='n'||ch2=='N')
	   exit(0);
	  }
	  else
	   modify();
   }
   fwrite(&stu2,sizeof(student),1,temp);
   remove("student.dat");
   fcloseall();
   rename("abc.dat","student.dat");
   getch();
  }
 new_profit();
}

void te_modify(int r)
{
 FILE *t,*tc,*ad,*temp1;
 teacher t1,t2;
 admin a;
 int i;
 char q,ch1,ch2,ch3,g[20],sub[20][20];
 int flag=0,en,f,ap,p=0,k=0,u=0,x,y,l,w,s;
  t=fopen("teacher.dat","rb");
  tc=fopen("xyz.dat","wb");
  ad=fopen("admin.dat","ab+");
  temp1=fopen("abc.dat","wb");
  solid(0,0,700,600,0);
  if(r==0)
  {
   rectangle(100,50,500,420);
   rectangle(90,40,510,430);
   gotoxy(18,6);
   printf("Enter the SSN :");
   gotoxy(50,6);
   scanf("%d",&en);
  }
  else
   en=r;
  while(!feof(t))
  {
   x=ftell(t);
   fread(&t1,sizeof(teacher),1,t);
   y=ftell(t);
   if(x!=y)
   {
    if(t1.ssn!=en)
    fwrite(&t1,sizeof(teacher),1,tc);
    else
    {
     flag=1;
     t2=t1;
    }
   }
  }

  if(flag==0)
  {
   gotoxy(18,9);
   printf("Invalid SSN");
  }
  else
  {
   if(r==0)
   {
    f=0;
    gotoxy(18,7);
    printf("Existing details of the teacher  ::");
    gotoxy(18,8);
    printf("NAME : %s ",t2.name);
    gotoxy(18,9);
    printf("SSN : %d",t2.ssn);
    gotoxy(18,10);
    printf("DESIGNATION: %s ",t2.designation);
    gotoxy(18,11);
    printf("SALARY : %0.1f",t2.salary);
    gotoxy(18,12);
    printf("SUBJECT :");
    i=12;
    for(k=0;k<t2.n;k++)
    {
     gotoxy(30,i);
     printf("%s",t2.subject[k]);
     i++;
    }
   }
   getch();
   solid(0,0,700,600,0);
   setcolor(3);
   settextstyle(4,0,5);
   outtextxy(200,90,"  M O D I F Y ");
   setcolor(10);
   rectangle(150,80,580,390);
   rectangle(140,70,590,400);
   ap=add_modify(1);
   if(ap!=5)
   {
    clearviewport();
    rectangle(100,50,500,420);
    rectangle(90,40,510,430);
   }
   switch(ap+1)
   {
    case 1:gotoxy(18,6);
	   printf("Enter the new name ::");
	   gotoxy(50,6);
	   scanf("%s",&t2.name);
	   break;
    case 2:gotoxy(18,6);
	   printf("\nEnter the new ssn");
	   gotoxy(50,6);
	   scanf("%d",&t2.ssn);
	   break;
    case 3:fread(&a,sizeof(a),1,ad);
	   a.salary=a.salary-t2.salary;
	   gotoxy(18,6);
	   printf("Enter the new salary");
	   gotoxy(50,6);
	   scanf("%f",&t2.salary);
	   a.salary=a.salary+t2.salary;
	   fwrite(&a,sizeof(a),1,temp1);
	   remove("admin.dat");
	   fclose(ad);
	   fclose(temp1);
	   rename("abc.dat","admin.dat");
	   break;
    case 4:gotoxy(18,6);
	   printf("What do you wanna do..??");
	   gotoxy(18,7);
	   printf("1.add subject..");
	   gotoxy(30,7);
	   printf("2.delete subject..");
	   gotoxy(50,7);
	   scanf("%d",&p);
	   switch(p)
	   {
	    case 1:i=0;
		   do
		  {
		   gotoxy(18,10+2*i);
		   printf("\nEnter the new subject::");
		   gotoxy(50,10+2*i);
		   scanf("%s",&t2.subject[t2.n++]);
		   gotoxy(18,13+2*i);
		   printf("Do you want to enter more subject.?::");
		   gotoxy(50,13+2*i);
		   scanf("%s",&ch1);
		   i++;
		  }while(ch1=='y'||ch1=='Y');
		  break;
	    case 2:i=0;
		   do
		   {
		    gotoxy(18,10+2*i);
		    printf("Which subject you want to delete::");
		    gotoxy(50,10+2*i);
		    scanf("%s",&g);
		    for(l=0;l<t2.n;l++)
		    {
		     if(strcmpi(t2.subject[l],g)==0)
		     k=l;
		    }
		    if(k>=0 && k<(t2.n))
		    {
		     w=k;
		     do
		     {
		      s=w+1;
		      strcpy(t2.subject[w],t2.subject[s]);     //correction
		      w=s;
		     }while(w<t2.n);

		     t2.n=((t2.n)-1);
		    }
		    gotoxy(18,13+2*i);
		    printf("Do you want to delete more subjects");
		    gotoxy(50,13+2*i);
		    scanf("%s",&ch2);
		    i++;
		   }while(ch2=='y'||ch2=='Y');
		  break;
		  default:gotoxy(18,10);
			  printf("Invalid input");
		 }
		 break;
      case 5:gotoxy(18,6);
	     printf("Enter the new designation ::");
	     gotoxy(50,6);
	     scanf("%s",&t2.designation);
	     break;
      case 6:if(r!=0)
	  {
	   outtextxy(110,440,"DO YOU WISH TO ADD/VIEW/DELETE/MODOIFY MORE DATA.?");
	   ch2=getch();
	   if(ch2=='y')
	   outtextxy(550,440,"y");
	   else if(ch2=='Y')
	   outtextxy(550,440,"Y");
	   else if(ch2=='N')
	   outtextxy(550,440,"N");
	   else if(ch2=='n')
	   outtextxy(550,440,"n");
	   if(ch2=='y'||ch2=='Y')
	   display();
	   else if(ch2=='n'||ch2=='N')
	   exit(0);
	  }
	  else
	   modify();
      }
      fwrite(&t2,sizeof(teacher),1,tc);
      remove("teacher.dat");
      fcloseall();
      rename("xyz.dat","teacher.dat");
     }
 new_profit();
}

void modify()
{
 char ch1,n=0;
 solid(160,165+30*n,450,190+30*n,8);
 add(3);
 while(1)
 {
  ch1=getch();
  if(ch1=='\r')
  {
   sound(500);
   delay(100);
   nosound();
   if(n==0)
   {
    st_modify(0);
    break;
   }
   if(n==1)
   {
    te_modify(0);
    break;
   }
   if(n==2)
   {
    clearviewport();
    display();
    break;
   }
  }
  else
  n=up_down(ch1,2,n,4);
   //print
 }
}

void main()
{
   char uname[4],ch[8],ch1,ch2;
   struct date d;
   struct time t;
   int i,gd=DETECT,gm;
   initgraph(&gd,&gm,"C:\\turboc3\\bgi");
   for(i=0;i<20;i++)
   {
     clearviewport();
     gotoxy(15,8);
     settextstyle(3,0,5);
     setcolor(5);
     outtextxy(100,100," W E L C O M E  ");
     gotoxy(30-i,13);
     printf(" U N I V E R S I T Y   R E C O R D   S Y S T E M ");
     gotoxy(30-i,14);
     printf("************************************************** ");
     gotoxy(30,20);
     printf("ASR PRESENTATION ");
     delay(70);
   }
   delay(400);
   clearviewport();
   gotoxy(2,2);
   getdate(&d);
   printf("Date: ");
   printf("%d/",d.da_day);
   printf("%d/",d.da_mon);
   printf("%d",d.da_year);
   gotoxy(50,2);
   gettime(&t);
   printf("Time:- ");
   printf("%2d:%02d",t.ti_hour,t.ti_min);
   setcolor(3);
   rectangle(160,150,400,300);
   rectangle(155,145,395,295);
   gotoxy(25,11);
   printf("SIGN IN ");
   gotoxy(22,13);
   printf("USERNAME : ");
   gotoxy(22,15);
   printf("PASSWORD : ");
   setcolor(12);
   gotoxy(34,13);
   gets(uname);
   gotoxy(34,15);
   for( i=0;i<5;i++)
   { ch[i]=getch();
     printf("*");
   }ch[5]='\0';
   if(strcmpi(ch,"sudmi")==0&& strcmpi(uname,"ayush")==0)
   {
      gotoxy(36,24);
      printf("LOADING........");
      delay(200);
      display();
   }
   else
   {
	gotoxy(36,24);
	printf("wrong user id or password..!!!");
	delay(200);
	exit(0);
   }
}
void prin(int l,int f)
{
 settextstyle(5,0,1);
 if(f==0)
  solid(160,165+30*l,450,190+30*l,7);
 else if(f==1)
  solid(160,165+30*l,450,190+30*l,10);
 setcolor(5);
 if(l==0)
 outtextxy(175,160,"INSERT DATA");
 else if(l==1)
 outtextxy(175,190,"VIEW DATA");
 else if(l==2)
 outtextxy(175,220,"DELETE DATA");
 else if(l==3)
 outtextxy(175,250,"MODIFY DATA");
 else if(l==4)
 outtextxy(175,280,"EXIT");
}
void prin1(int l,int f)
{
 settextstyle(5,0,1);
 if(f==0)
  solid(160,165+30*l,450,190+30*l,7);
 else if(f==1)
  solid(160,165+30*l,450,190+30*l,10);
 setcolor(5);
 if(l==0)
 outtextxy(175,160,"INSERT STUDENT's DATA");
 else if(l==1)
 outtextxy(175,190,"INSERT TEACHER's DATA");
 else if(l==2)
 outtextxy(175,220,"INSERT ADMIN's DATA");
 else if(l==3)
 outtextxy(175,250,"EXIT");
}
void prin3(int l,int f)
{
 settextstyle(5,0,1);
 if(f==0)
  solid(160,165+30*l,450,190+30*l,7);
 else if(f==1)
  solid(160,165+30*l,450,190+30*l,10);
 setcolor(5);
 if(l==0)
 outtextxy(175,160,"DELETE STUDENT's DATA");
 else if(l==1)
 outtextxy(175,190,"DELETE TEACHER's DATA");
 else if(l==2)
 outtextxy(175,220,"EXIT");
}
void prin2(int l,int f)
{
 settextstyle(5,0,1);
 if(f==0)
  solid(160,165+30*l,450,190+30*l,7);
 else if(f==1)
  solid(160,165+30*l,450,190+30*l,10);
 setcolor(5);
 if(l==0)
 outtextxy(175,160,"  VIEW  STUDENT's DATA");
 else if(l==1)
 outtextxy(175,190,"  VIEW  TEACHER's DATA");
 else if(l==2)
 outtextxy(175,220,"  VIEW  ADMIN's DATA");
 else if(l==3)
 outtextxy(175,250," EXIT");
}
void prin4(int l,int f)
{
 settextstyle(5,0,1);
 if(f==0)
  solid(160,165+30*l,450,190+30*l,7);
 else if(f==1)
  solid(160,165+30*l,450,190+30*l,10);
 setcolor(5);
 if(l==0)
 outtextxy(175,160,"MODIFY STUDENT's DATA");
 else if(l==1)
 outtextxy(175,190,"MODIFY TEACHER's DATA");
 else if(l==2)
 outtextxy(175,220,"EXIT");
}
void menu()
{
   setcolor(3);
   settextstyle(4,0,5);
   outtextxy(200,90,"  M E N U ");
   settextstyle(1,0,1);
   setcolor(2);
   outtextxy(175,160,"INSERT DATA");
   outtextxy(175,190,"VIEW DATA");
   outtextxy(175,220,"DELETE DATA");
   outtextxy(175,250,"MODIFY DATA");
   outtextxy(175,280,"EXIT");
   outtextxy(160,310,"USE d -Down and s -Up and enter-confirm");
   setcolor(10);
   rectangle(150,80,580,350);
   rectangle(140,70,590,360);
   altersolid(150,71,570,79,10);
   altersolid(150,351,570,359,10);
}

int up_down( char ch1,int max,int n,int l )
{
 int flag=0;
 if(ch1=='d')
  {
   sound(250);
   delay(100);
   nosound();
   if(n==max)
   {
    solid(160,165+30*n,490,190+30*n,0);
    n=0;
   }
   else
   {
    n++;
    solid(160,165+30*(n-1),490,190+30*(n-1),0);
   }
  }
  else if(ch1=='s')
  {
   flag=1;
   sound(100);
   delay(100);
   nosound();
   if(n==0)
   {
    n=max;
    solid(160,165,490,190,0);
   }
   else
   {
    solid(160,165+30*(n),490,190+30*(n),0);
    n--;
   }
 }
 else
 {
  flag=2;
 }
 if(l==0 && flag!=2)
 {
  menu();
  prin(n,flag);
 }
 else if(l==1 && flag!=2)
 {
  add(0);
  prin1(n,flag);
 }
 else if(l==2 && flag!=2)
 {
  add(1);
  prin2(n,flag);
 }
 else if(l==3 && flag!=2)
 {
  add(2);
  prin3(n,flag);
 }
 else if(l==4 && flag!=2)
 {
  add(3);
  prin4(n,flag);
 }
 return n;
}
void display()
{
 int n=0,max;
 char ch1;
 clearviewport();
 solid(160,165,450,190,8);
 menu();
 while(1)
 {
  ch1=getch();
  if(ch1=='\r')
  {
   sound(500);
   delay(100);
   nosound();
   sol(365,215);
   if(n==0)
    insert();
   else if(n==1)
    view();
   else if(n==2)
    delet();
   else if(n==3)
    modify();
   if(n==4)
    exit(0);
  }
  else
  n=up_down(ch1,4,n,0);
 }

}




