#include <iostream> 
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;


int main (int argc, char *argv[])
{	
	system("clear");
	char opp;
   	char login = 'a'; 
	int x = 0;
	int sock;
	struct sockaddr_in server;
	struct hostent *hp;
	char buff[1024];
	
	sock = socket (AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("socket failed");
		exit(1);
	}
	
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	if(hp == 0)
	{
		perror("gethostbyname failed");
		close(sock);
		exit(1);
	}

	char hantar[9999];
	char dapat[9999];

	
		
	//printf("Client site : ");
	//scanf("%s",hantar);
	
	memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
	server.sin_port = htons(1026);
	
	if(connect(sock, (struct sockaddr *) &server, sizeof (server))< 0)
	{
		perror("connect failed");
		close(sock);
		exit(1);
	}
	

	if(x==0)
	{
		strcpy(hantar,"Client connetion OK..");
		write(sock,hantar,sizeof(hantar));
		x=1;
	}
	else 
		if(write(sock, hantar, sizeof(hantar)) < 0)
		{
			perror("sent failed");
			close(sock);
			exit(1);
		}



	if(read(sock,dapat,sizeof(dapat))>0)
	{
		printf("Server site : %s\n",dapat);
		//printf("Client site : ");

	}	

	close(sock);
/////////////////////////////////////////////////////////////////////////////
int run = 1;
while(run == 1	){
while(login == 'a'){
	char idlog[50];
	char passlog[50];
	char logsql[500];
	system("clear");
	cout<<endl<<endl<<endl<<endl;	
	cout<<" ________________________________________________________"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<"|  LOGIN                                                 |"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<endl;	
	cout<<"  Enter ID       : ";
	cin>>ws;
	cin.getline(idlog,50);
	cout<<"  Enter Password : ";
	cin.getline(passlog,50);

	snprintf(logsql,500,"%s%s%s%s%s","SELECT * from uitm.student where stu_id = ",idlog
						," and stu_password ='",passlog,"';");
	//cout<<logsql<<endl;
	//////////////////////////////////////
	sock = socket (AF_INET, SOCK_STREAM, 0);
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
	server.sin_port = htons(1026);
	connect(sock, (struct sockaddr *) &server, sizeof (server));
	snprintf(hantar,9999,"%s",logsql);
	write(sock, hantar, sizeof(hantar));	
	read(sock,dapat,sizeof(dapat));
	printf("Server site : %s\n",dapat);
	close(sock);
	//////////////////////////////////////

	cout<<" ________________________________________________________"<<endl;

	if (strcmp(idlog,"1")==0){
	login = 'b';
	}
	if(login == 'a'){
		cout<<" Invalid ID or Password !";
	}
}
cout<<endl<<endl<<endl<<endl;
cout<<" ________________________________________________"<<endl;
cout<<"|      Option 1 : List Student                   |"<<endl;
cout<<"|      Option 2 : Search Student                 |"<<endl;
cout<<"|      Option 3 : Student Registration           |"<<endl;
cout<<"|      Option 4 : Delete Student                 |"<<endl;
cout<<"|      Option 5 : LogOut                         |"<<endl;
cout<<"|________________________________________________|"<<endl;
cout<<"  Enter option : ";
cin>>opp;
if(opp == '1'){
////////////////////////////////////////////////////////
	system("clear");
	cout<<endl<<endl<<endl<<endl;	
	cout<<" ________________________________________________________"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<"|   List Student                                         |"<<endl;
	cout<<"|________________________________________________________|"<<endl;

	 cout<<" ________________________________________________________"<<endl;
	 cout<<"| ID |       Name         |Couse Code|  Tel no     | Age |"<<endl;
	 cout<<"|____|____________________|__________|_____________|_____|"<<endl;

	//////////////////////////////////////
	sock = socket (AF_INET, SOCK_STREAM, 0);
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
	server.sin_port = htons(1026);
	connect(sock, (struct sockaddr *) &server, sizeof (server));
	snprintf(hantar,9999,"%s","SELECT * from uitm.student;");
	write(sock, hantar, sizeof(hantar));	
	read(sock,dapat,sizeof(dapat));
	printf("Server site : %s\n",dapat);
	close(sock);
	//////////////////////////////////////

	 cout<<"|____|____________________|__________|_____________|_____|"<<endl;
	 cout <<endl;
      cout << "_________________________________________________________"<<endl;
}
else if(opp == '2'){

////////////////////////////////////////////////////
	system("clear");
	char input[50];
	char in[500];
	cout<<endl<<endl<<endl<<endl;	
	cout<<" ________________________________________________________"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<"|   Search Student                                       |"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<endl;	
	cout<<"  Search by student ID = ";
	cin>> ws;
	cin.getline(input,50);
	strcpy(in,"SELECT * from uitm.student where stu_id = ");
	strcpy(in , strcat(in,input));
	//////////////////////////////////////
	sock = socket (AF_INET, SOCK_STREAM, 0);
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
	server.sin_port = htons(1026);
	connect(sock, (struct sockaddr *) &server, sizeof (server));
	snprintf(hantar,9999,"%s",in);
	write(sock, hantar, sizeof(hantar));	
	read(sock,dapat,sizeof(dapat));
	printf("Server site : %s\n",dapat);
	close(sock);
	//////////////////////////////////////
	cout<<" ________________________________________________________"<<endl;



         cout << "   ID = " <<endl;
         cout << "   Name = " <<endl;
         cout << "   Couse Code = " << endl;
         cout << "   Tel no = " << endl;
         cout << "   Age = " << endl;

	cout<<" ________________________________________________________"<<endl;

}
else if(opp == '3'){
//////////////////////////////////////////////////////////////

	char id[50];
	char name[50];
	char course[50];
	char tel[50];
	char password[50];
	char age[50];
	
	system("clear");
	cout<<endl<<endl<<endl<<endl;	
	cout<<" ________________________________________________________"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<"|   Student Registration                                 |"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<endl;
	cout<<"   Enter Student ID       : ";
	cin>> ws;
	cin.getline(id,50);
	cout<<"   Enter Student Name     : ";
	cin.getline(name,50);
	cout<<"   Enter Student Course   : ";
	cin.getline(course,50);
	cout<<"   Enter Student Tel no   : ";
	cin.getline(tel,50);
	cout<<"   Enter Student Password : ";
	cin.getline(password,50);
	cout<<"   Enter Student Age      : ";
	cin.getline(age,50);

	char addsql[500];
	snprintf(addsql,500,"%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
"INSERT INTO uitm.student (stu_id,stu_name,stu_course,stu_tel,stu_password,stu_age) ",
      	"VALUES (",id,",'",name,"','",course,"','",tel,"','",password,"','",age,"');");
	//cout<<"  "<<addsql<<endl;
//////////////////////////////////////
	sock = socket (AF_INET, SOCK_STREAM, 0);
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
	server.sin_port = htons(1026);
	connect(sock, (struct sockaddr *) &server, sizeof (server));
	snprintf(hantar,9999,"%s",addsql);
	write(sock, hantar, sizeof(hantar));	
	read(sock,dapat,sizeof(dapat));
	printf("Server site : %s\n",dapat);
	close(sock);
	//////////////////////////////////////
	cout<<"________________________________________________________"<<endl;
	cout<<endl;

}
else if(opp == '4'){
///////////////////////////////////////////////////////////////////
	system("clear");
	cout<<endl<<endl<<endl<<endl;
	cout<<" ________________________________________________________"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<"|   Delete Student                                       |"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<endl;
	char idd[50];
	cout<<"   Enter Student ID       : ";
	cin>> ws;
	cin.getline(idd,50);

	char delsql[500];
	snprintf(delsql,500,"%s%s",
		"DELETE from uitm.student where stu_id = ",idd);
	//cout<<"  "<<delsql<<endl;
	//////////////////////////////////////
	sock = socket (AF_INET, SOCK_STREAM, 0);
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
	server.sin_port = htons(1026);
	connect(sock, (struct sockaddr *) &server, sizeof (server));
	snprintf(hantar,9999,"%s",delsql);
	write(sock, hantar, sizeof(hantar));	
	read(sock,dapat,sizeof(dapat));
	printf("Server site : %s\n",dapat);
	close(sock);
	//////////////////////////////////////

	cout<<" ________________________________________________________"<<endl;
	cout<<endl;
}
else if(opp == '5'){
	login='a';
}








//snprintf(hantar,9999,"%c",opp);
}

	return 0;
}

//strcpy(hantar,opp);
//////////////////////////////////////////////////////////////////////////////		
		//scanf("%s",hantar);