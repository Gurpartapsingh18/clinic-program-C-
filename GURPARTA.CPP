#include<fstream>
#include<stdio.h>
#include<string.h>
#include<process.h>
void box();
void clear();
void human();
void heading();
void border();
void clear1();
void doctor();

class clinic
{
		char name[20];
		char gender[20];
		char symname[20];
		char doctorname[20];
		char medname[20];

	public:
		void input();
		void show()
		{
		       gotoxy(8,10);cout<<"NAME "<<name;
		       gotoxy(8,11);cout<<"GENDER "<<gender;
		       gotoxy(8,12);cout<<"SYMPTOM "<<symname;
		       gotoxy(8,13);cout<<"DOCTORNAME "<<doctorname;
		       gotoxy(8,14);cout<<"MEDICINE "<<medname;
		}
		char *retsymname()
		{
			return symname;
		}
		char *retdoctorname()
		{
			return doctorname;
		}
		char *retmedname()
		{
			return medname;
		}
};


void clinic::input()       // transferring to file
{
	gotoxy(8,9);cout<<"ENTER YOUR NAME"<<endl;
	gotoxy(8,10);cin>>name;
	gotoxy(8,11);cout<<"ENTER YOUR GENDER"<<endl;
	gotoxy(8,12);cin>>gender;
	clear();
}
int  fbp() //selecct while modifying
{
	gotoxy(40,11);cout<<"SELECT A BODY PART "<<endl;
	getch();
	human();
	gotoxy(3,12);cout<<"²²²²²²²";delay(70);
	gotoxy(3,14);cout<<"²²²²²²²";delay(70);
	gotoxy(3,13);cout<<"²TORSO²-------->";delay(70);
	gotoxy(49,4);cout<<"²²²²²²";delay(70);
	gotoxy(49,6);cout<<"²²²²²²";delay(70);
	gotoxy(40,5);cout<<"<--------²HEAD²";delay(70);
	gotoxy(49,17);cout<<"²²²²²²²²²²²²";delay(70);
	gotoxy(49,19);cout<<"²²²²²²²²²²²²";delay(70);
	gotoxy(40,18);cout<<"<--------²LOWER BODY²";delay(70);
	int bp;
	int i;
	for(i=67;i>=39;i--)
	{
		gotoxy(i,10);cout<<"±"<<endl;delay(10);
	}
	for(i=39;i<=67;i++)
	{
		gotoxy(i,15);cout<<"±"<<endl;delay(10);
	}
	for(i=10;i<=15;i++)
	{
		gotoxy(67,i);cout<<"±"<<endl;delay(10);
	}
	for(i=15;i>=10;i--)
	{
		gotoxy(39,i);cout<<"±"<<endl;delay(10);
	}
	gotoxy(40,12);cout<<"1>HEAD 2>TORSO 3>LOWER BODY"<<endl;delay(20);
	gotoxy(40,13);cout<<"ENTER BODY PART"<<endl;delay(20);
	gotoxy(40,14);cin>>bp;delay(20);
	clear1();
	return bp;
}
void  symptom(char symp[10])           // seperated into two functions
{
	int tbp;
	tbp=fbp();
	box();
	switch(tbp)
	{
	case 1:gotoxy(8, 9);cout<<"A1. HEADACHE";delay(10);
	       gotoxy(8,10);cout<<endl;
	       gotoxy(8,11);cout<<"A2. DEPRESSION";delay(10);
	       gotoxy(8,12);cout<<endl;
	       gotoxy(8,13);cout<<"A3. BALD SPOTS ";delay(10);
	       gotoxy(8,14);cout<<endl;
	       gotoxy(8,15);cout<<"ENTER SYMPTOMS ";delay(10);
	       gotoxy(8,16);cin>>symp;
	       break;
	 case 2:gotoxy(8,9); cout<<"B1. CHEST PAIN";delay(10);
		gotoxy(8,10);cout<<endl;
		gotoxy(8,11);cout<<"B2. INFECTION";delay(10);
		gotoxy(8,12);cout<<endl;
		gotoxy(8,13);cout<<"B3. KIDNEY PAIN";delay(10);
		gotoxy(8,14);cout<<endl;
		gotoxy(8,15);cout<<"ENTER SYPMTOMS";delay(10);
		gotoxy(8,16);cin>>symp;
		break;
	 case 3:gotoxy(8,9); cout<<"C1. STOMACH PAIN";delay(10);
		gotoxy(8,10);cout<<endl;
		gotoxy(8,11);cout<<"C2. INFECTION";delay(10);
		gotoxy(8,12);cout<<endl;
		gotoxy(8,13);cout<<"C3. APPENDIX";delay(10);
		gotoxy(8,14);cout<<endl;
		gotoxy(8,15);cout<<"ENTER SYMPTOMS";delay(10);
		gotoxy(8,16);cin>>symp;
		break;
	  }
	  clear();
}
void main()
{
    clinic c;
    clrscr();
    border();
    int ch;
    box();
    do{
    gotoxy(8,10);cout<<"WELCOME TO OUR CLINIC"<<endl;
    gotoxy(8,11);cout<<"1. ENTER DETAILS"<<endl;
    gotoxy(8,12);cout<<"2. DISPLAY RESULTS "<<endl;
    gotoxy(8,13);cout<<"3. ADMIN MENU ";
    gotoxy(8,14);cout<<"4. EXIT ";
    gotoxy(8,15);cout<<" ";cin>>ch;
    switch(ch)
    {
      case 1 :
		clear();
		c.input();
		clear();
		border();
		clear1();
		heading();
		clear1();
		getch();
		char symp1[10];
		symptom(symp1);
		ofstream file1;
		file1.open("clinic.dat",ios::binary|ios::out|ios::trunc);
		if(strcmpi(symp1,"A1")==0)
		{
			strcpy(c.retsymname(),"Head - Headache");
			strcpy(c.retdoctorname(),"Dr. Babita");
		}
		if(strcmpi(symp1,"A2")==0)
		{
			strcpy(c.retsymname(),"Head - Depression");
			strcpy(c.retdoctorname(),"Dr. Raghav");
		}
		if(strcmpi(symp1,"A3")==0)
		{
			strcpy(c.retsymname(),"Head - Bald Spots");
			strcpy(c.retdoctorname(),"Dr. Savita");
		}
		if(strcmpi(symp1,"B1")==0)
		{
			strcpy(c.retsymname(),"Torso - Chest pain");
			strcpy(c.retdoctorname(),"Dr. Savita");
		}
		if(strcmpi(symp1,"B2")==0)
		{
			strcpy(c.retsymname(),"Torso - Infection");
			strcpy(c.retdoctorname(),"Dr. Raghav");
		}
		if(strcmpi(symp1,"B3")==0)
		{
			strcpy(c.retsymname(),"Torso - Kidney Pain");
			strcpy(c.retdoctorname(),"Dr. Savita");
		}
		if(strcmpi(symp1,"C1")==0)
		{
			strcpy(c.retsymname(),"Lower Body - Stomach pain");
			strcpy(c.retdoctorname(),"Dr. Savita");
		}
		if(strcmpi(symp1,"B2")==0)
		{
			strcpy(c.retsymname(),"Lower body - Infection");
			strcpy(c.retdoctorname(),"Dr. Raghav");
		}
		if(strcmpi(symp1,"B3")==0)
		{
			strcpy(c.retsymname(),"Lower body - Appenix");
			strcpy(c.retdoctorname(),"Dr. Savita");
		}
		if(strcmp(symp1,"A1")==0)
		{
		 strcpy(c.retmedname(),"PARACITAMOL");
		}
		if(strcmp(symp1,"A2")==0)
		{
		 strcpy(c.retmedname(),"PASEEN PILLS");
		}
		if(strcmp(symp1,"A3")==0)
		{
		 strcpy(c.retmedname(),"CLINICAL SHAMPOO");
		}
		if(strcmp(symp1,"B1")==0)
		{
		 strcpy(c.retmedname(),"PAIN KILLER");
		}
		if(strcmp(symp1,"B2")==0)
		{
		 strcpy(c.retmedname(),"DISINFECTANT");
		}
		if(strcmp(symp1,"B3")==0)
		{
		 strcpy(c.retmedname(),"TESLA MG4");
		}
		if(strcmp(symp1,"C1")==0)
		{
		 strcpy(c.retmedname(),"PAIN  KILLER 2");
		}
		if(strcmp(symp1,"C2")==0)
		{
		 strcpy(c.retmedname(),"DISINFECTANT 2");
		}
		if(strcmp(symp1,"C3")==0)
		{
		 strcpy(c.retmedname(),"TESLA MG7 c5");
		}
		file1.write((char*)&c,sizeof(c));
		file1.close();
		break;

      case 2 :  clear();
		gotoxy(8,10);cout<<"MEDICINE SELECTED"<<endl;
		gotoxy(8,11);cout<<c.retmedname();
		gotoxy(8,12);cout<<"DOCTOR ASSIGNED "<<endl;
		gotoxy(8,13);cout<<c.retdoctorname();
		gotoxy(8,14);cout<<"SYMPTOM/BODY PART SELECTED"<<endl;
		gotoxy(8,15);cout<<c.retsymname();
		getch();
		clear();
		break;
      case 3 :
		clear();
		int ch;
		do{
		box();
		gotoxy(8,10);cout<<"WELCOME TO ADMIN MENU"<<endl;
		gotoxy(8,11);cout<<"1. READ RECORD"<<endl;
		gotoxy(8,12);cout<<"2. MODIFY RECORD "<<endl;
		gotoxy(8,13);cout<<"3. RETURN TO MAIN SCREEN"<<endl;
		gotoxy(8,14);cout<<" ";cin>>ch;
		clinic c1;
		switch(ch)
			{
			case 1 : clear();
				 ifstream fin("clinic.dat",ios::binary|ios::in);
				 fin.read((char*)&c1,sizeof(c1));
				 c1.show();
				 fin.close();
				 getch();
				 clear();
				 break;
			case 2 : clear();
				gotoxy(8,10);cout<<"ENTER DATA";
				getch();
				clear();
				clear();
				clinic c3;
				c3.input();
				clear();
				border();
				clear1();
				heading();
				clear1();
				getch();
				char symp1[10];
				symptom(symp1);
				ofstream file1;
				file1.open("clinic.dat",ios::binary|ios::out|ios::trunc);
		if(strcmpi(symp1,"A1")==0)
		{
			strcpy(c3.retsymname(),"Head - Headache");
			strcpy(c3.retdoctorname(),"Dr. Babita");
		}
		if(strcmpi(symp1,"A2")==0)
		{
			strcpy(c3.retsymname(),"Head - Depression");
			strcpy(c3.retdoctorname(),"Dr. Raghav");
		}
		if(strcmpi(symp1,"A3")==0)
		{
			strcpy(c3.retsymname(),"Head - Bald Spots");
			strcpy(c3.retdoctorname(),"Dr. Savita");
		}
		if(strcmpi(symp1,"B1")==0)
		{
			strcpy(c3.retsymname(),"Torso - Chest pain");
			strcpy(c3.retdoctorname(),"Dr. Savita");
		}
		if(strcmpi(symp1,"B2")==0)
		{
			strcpy(c3.retsymname(),"Torso - Infection");
			strcpy(c3.retdoctorname(),"Dr. Raghav");
		}
		if(strcmpi(symp1,"B3")==0)
		{
			strcpy(c3.retsymname(),"Torso - Kidney Pain");
			strcpy(c3.retdoctorname(),"Dr. Savita");
		}
		if(strcmpi(symp1,"C1")==0)
		{
			strcpy(c3.retsymname(),"Lower Body - Stomach pain");
			strcpy(c3.retdoctorname(),"Dr. Savita");
		}
		if(strcmpi(symp1,"B2")==0)
		{
			strcpy(c3.retsymname(),"Lower body - Infection");
			strcpy(c3.retdoctorname(),"Dr. Raghav");
		}
		if(strcmpi(symp1,"B3")==0)
		{
			strcpy(c3.retsymname(),"Lower body - Appenix");
			strcpy(c3.retdoctorname(),"Dr. Savita");
		}
		if(strcmp(symp1,"A1")==0)
		{
		 strcpy(c3.retmedname(),"PARACITAMOL");
		}
		if(strcmp(symp1,"A2")==0)
		{
		 strcpy(c3.retmedname(),"PASEEN PILLS");
		}
		if(strcmp(symp1,"A3")==0)
		{
		 strcpy(c3.retmedname(),"CLINICAL SHAMPOO");
		}
		if(strcmp(symp1,"B1")==0)
		{
		 strcpy(c3.retmedname(),"PAIN KILLER");
		}
		if(strcmp(symp1,"B2")==0)
		{
		 strcpy(c3.retmedname(),"DISINFECTANT");
		}
		if(strcmp(symp1,"B3")==0)
		{
		 strcpy(c3.retmedname(),"TESLA MG4");
		}
		if(strcmp(symp1,"C1")==0)
		{
		 strcpy(c3.retmedname(),"PAIN  KILLER 2");
		}
		if(strcmp(symp1,"C2")==0)
		{
		 strcpy(c3.retmedname(),"DISINFECTANT 2");
		}
		if(strcmp(symp1,"C3")==0)
		{
		 strcpy(c3.retmedname(),"TESLA MG7 c5");
		}
		file1.write((char*)&c3,sizeof(c3));
		file1.close();



			gotoxy(8,13);cout<<"MODIFICATION SUCCESSFULLY"<<endl;
			getch();

			clear();
			break;
			case 3 :  clear();
				  gotoxy(8,10);cout<<"THANK YOU :D ";
				  getch();
				  break;
			default :gotoxy(8,15);cout<<"Invalid Option...";
				  getch();
				  break;
			}
	  }
			while(ch!=3);

			break;
      case 4 : clear();gotoxy(8,10);cout<<"THANK YOU :D ";
	       break;
      default :gotoxy(8,15);cout<<"Invalid Option...";
	       break;
    }
  }
   while(ch!=4);
   clear();
}
void border()
{
	int i;
	for(i=1;i<=23;i++)
	{
		gotoxy(1,i);cout<<"°"<<endl;
	}
	for(i=1;i<=80;i++)
	{
		gotoxy(i,1);cout<<"°"<<endl;
	}
	for(i=1;i<=23;i++)
	{
		gotoxy(80,i);cout<<"°"<<endl;

	}
	for(i=1;i<=80;i++)
	{
		gotoxy(i,23);cout<<"°"<<endl;
	}
}
void clear1()
{
	int i,j;
	for(i=2;i<80;i++)
	{
	   for(j=2;j<23;j++)
	   {
		gotoxy(i,j);cout<<" ";
	   }

	}
}
void box()
{
	int i;
	gotoxy(23,6);cout<<"±±±±±±±±±±";
	gotoxy(23,7);cout<<"±-CLINIC-±";
	for(i=47;i>=7;i--)
	{
		gotoxy(i,8);cout<<"±"<<endl;delay(10);
	}
	for(i=7;i<=47;i++)
	{
		gotoxy(i,19);cout<<"±"<<endl;delay(10);
	}
	for(i=8;i<=18;i++)
	{
		gotoxy(47,i);cout<<"±"<<endl;delay(10);
	}
	for(i=18;i>=8;i--)
	{
		gotoxy(7,i);cout<<"±"<<endl;delay(10);
	}
	getch();
}
void clear()
{       int i,j;
	for(i=8;i<47;i++)
	{
	   for(j=9;j<19;j++)
	   {
		gotoxy(i,j);cout<<" ";
	   }
	   delay(10);
	}
}


void human()
{
gotoxy(8,5);cout<<	"                ±±±±	       "<<endl;
gotoxy(8,6);cout<<	"     ±±         é  é 	   ±±"<<endl;
gotoxy(8,7);cout<<	"     ±±         \\ÄÄ/       ±±	"<<endl;
gotoxy(8,8);cout<<	"       ±±        ±± 	 ±±	"<<endl;
gotoxy(8,9);cout<<	"         ±±±±±±±±±±±±±±±±±"<<endl;
gotoxy(8,10);cout<<	"            ±±±±±±±±±±±±	"<<endl;
gotoxy(8,11);cout<<	"             ±±±±±±±±±±	"<<endl;
gotoxy(8,12);cout<<	"              ±±±±±±±±		"<<endl;
gotoxy(8,13);cout<<	"             ±±±±±±±±±±	"<<endl;
gotoxy(8,14);cout<<	"              ±±±±±±±± 	 "<<endl;
gotoxy(8,15);cout<<	"             ±±±    ±±±   	 "<<endl;
gotoxy(8,16);cout<<	"            ±±±      ±±±        "<<endl;
gotoxy(8,17);cout<<	"           ±±±        ±±±       "<<endl;
gotoxy(8,18);cout<<	"          ±±±          ±±±      "<<endl;
gotoxy(8,19);cout<<	"         ±±±            ±±±     "<<endl;
gotoxy(8,20);cout<<	"        ±±±              ±±±     "<<endl;
}

void heading()
{

gotoxy(15,10);cout<<"    ______  __       __  .__   __.  __    ______ "<<endl;delay(100);
gotoxy(15,11);cout<<"   /      ||  |     |  | |  \\ |  | |  |  /      |"<<endl;delay(100);
gotoxy(15,12);cout<<"  |  ,----'|  |     |  | |   \\|  | |  | |  ,----'"<<endl;delay(100);
gotoxy(15,13);cout<<"  |  |     |  |     |  | |  . `  | |  | |  |     "<<endl;delay(100);
gotoxy(15,14);cout<<"  |  `----.|  `----.|  | |  |\\   | |  | |  `----."<<endl;delay(100);
gotoxy(15,15);cout<<"  |_______||_______||__| |__| \\__| |__| |_______|"<<endl;delay(100);
getch();
clear1();
gotoxy(15,4);cout<<"                MMM       MMM"<<endl;delay(100);
gotoxy(15,5);cout<<"                MM  ß   ß  MM"<<endl;delay(100);
gotoxy(15,6);cout<<"                MM  ßßßßß  MM"<<endl;delay(100);
gotoxy(15,7);cout<<"                MM  ß   ß  MM"<<endl;delay(100);
gotoxy(15,8);cout<<"                MM         MM"<<endl;delay(100);
gotoxy(15,9);cout<<"    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;delay(100);
gotoxy(15,10);cout<<"       MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;delay(100);
gotoxy(15,11);cout<<"       MMMM                  MM    MMM"<<endl;delay(100);
gotoxy(15,12);cout<<"       MMMM                  MM    MMM"<<endl;delay(100);
gotoxy(15,13);cout<<"       MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;delay(100);
gotoxy(15,14);cout<<"    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM."<<endl;delay(100);
gotoxy(15,15);cout<<"       MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;delay(100);
gotoxy(15,16);cout<<"       MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;delay(100);
gotoxy(15,17);cout<<"       MMMM    MMM         MMMM    MMM"<<endl;delay(100);
gotoxy(15,18);cout<<"       MMMM    MMM         MMMM    MMM"<<endl;delay(100);
gotoxy(15,19);cout<<"       MMMMMMMMMMM         MMMMMMMMMMM"<<endl;delay(100);
gotoxy(15,20);cout<<"       MMMMMMMMMMM         MMMMMMMMMMM"<<endl;delay(100);
gotoxy(15,21);cout<<"       MMMMMMMMMMM         MMMMMMMMMMM"<<endl;delay(100);
gotoxy(15,22);cout<<"        MMMMMMMMMM         MMMMMMMMMM"<<endl;delay(100);
}

