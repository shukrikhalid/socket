#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <iostream>
#include <pqxx/pqxx>
#include <iomanip>

using namespace std;
using namespace pqxx;

int main(int argc, char *argv[])
{	
	int sizeBuffS = 500;
	char sql[sizeBuffS];
   	char db[100]="dbname=uitm user=postgres password=root \
      		hostaddr=192.168.56.101 port=5432";
	/*Variables*/ 
	int sock;
	struct sockaddr_in server;
	int mysock;
	char buff[1024];
	int rval;
	
	/*Create socket*/
	sock = socket (AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("Failed to create socket");
		exit(1);
	}
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port =htons(1026);
	
	/*call bind*/
	if(bind(sock, (struct sockaddr *)&server, sizeof(server)))
	{
		perror("bind failed");
		exit(1);
	}
	
	/*listen*/
	 listen(sock, 5);
	 
	/*Accept*/
	
	do
	{
		char hantar[10][sizeBuffS];
		char dapat[2][sizeBuffS];
		mysock = accept(sock, (struct sockaddr *) 0, 0);
		if(mysock == -1)
		{
			perror("accept failed");
		}
		else
		{
			memset(dapat, 0, sizeof(dapat));
			if ((rval = read(mysock,dapat, sizeof(dapat)))< 0)
				perror("reading stream message error");
			else if (rval == 0)
				printf("Ending connection\n");
			else	
				{
if(strcmp(dapat[0],"sent")!=0){	
cout<<endl;
cout<<"========================================================"<<endl;
cout<<" Option        : "<< dapat[0]<<endl;
cout<<" Execute query : "<< dapat[1]<<endl;
cout<<"________________________________________________________"<<endl;
}		
if(strcmp(dapat[0],"sent")==0){					
	printf("Client site : %s\n",dapat[0]);
	printf("Client site : %s\n",dapat[1]);
	write(mysock,hantar,sizeof(hantar));
}


else if(strcmp(dapat[0],"login")==0){
	cout<<" ________________________________________________________"<<endl;
try{
	connection C(db);
      
      if (C.is_open()) {
         cout << " Opened database successfully: " << C.dbname() << endl<< endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }
      /* Create SQL statement */
      strcpy(sql ,dapat[1]);
      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
	//cout<<c[1].as<string>();
	//string as=c[1].as<string>();
	strncpy(hantar[0],c[1].as<string>().c_str(),sizeof(hantar[0]));	
	//snprintf(hantar[0],sizeBuffS,"%s",as);

      }
      cout<< endl << " Operation done successfully" << endl;
	
      C.disconnect ();
   }catch (const std::exception &e){
      cerr << e.what() << std::endl;
   }
	cout<<" ________________________________________________________"<<endl;
write(mysock,hantar,sizeof(hantar));
}
else if(strcmp(dapat[0],"1")==0){
char hantar2[30][6][30]={{{""}}};
cout<<" ________________________________________________________"<<endl;
try{
      connection C(db);
      if (C.is_open()) {
         cout << " Opened database successfully: " << C.dbname() << endl<< endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }
      /* Create SQL statement */
      strcpy(sql ,dapat[1]);
	
      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
	 cout<<" ________________________________________________________"<<endl;
	 cout<<"| ID |       Name         |Couse Code|  Tel no     | Age |"<<endl;
	 cout<<"|____|____________________|__________|_____________|_____|"<<endl;
	int x = 0;
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
	strncpy(hantar2[x][0],c[0].as<string>().c_str(),sizeof(hantar2[x][0]));	
         cout << "|"<<setw(3) << hantar2[x][0];
	strncpy(hantar2[x][1],c[1].as<string>().c_str(),sizeof(hantar2[x][1]));	
         cout << " |"<<setw(19) << hantar2[x][1];
	strncpy(hantar2[x][2],c[2].as<string>().c_str(),sizeof(hantar2[x][2]));	
         cout << " |"<<setw(9) << hantar2[x][2];
	strncpy(hantar2[x][3],c[3].as<string>().c_str(),sizeof(hantar2[x][3]));	
         cout << " |"<<setw(12) << hantar2[x][3];
	strncpy(hantar2[x][4],c[5].as<string>().c_str(),sizeof(hantar2[x][4]));	
         cout << " |"<<setw(4) << hantar2[x][4]<<" |";
	cout <<endl;
	//snprintf(hantar[0],sizeBuffS,"%s","1");
	char cc[4];
	snprintf(cc,4,"%d",x);	
	strcpy(hantar2[x][5],cc);
	x++;
      }
	for(x;x<30;x++)
	{
		strcpy(hantar2[x][0],"nnn");
		strcpy(hantar2[x][1],"nnn");
		strcpy(hantar2[x][2],"nnn");
		strcpy(hantar2[x][3],"nnn");
		strcpy(hantar2[x][4],"nnn");
		char cc[4];
		snprintf(cc,4,"%d",x);
		strcpy(hantar2[x][5],cc);
	}
	cout<<"|____|____________________|__________|_____________|_____|"<<endl;
	cout <<endl;
      cout << " Operation done successfully" << endl;
      cout << " _________________________________________________________"<<endl;
      C.disconnect ();
   }catch (const std::exception &e){
      cerr << e.what() << std::endl;
   }
write(mysock,hantar2,sizeof(hantar2));
}
else if(strcmp(dapat[0],"2")==0){
cout<<" ________________________________________________________"<<endl;
strcpy(hantar[0],"");
try{
	connection C(db);
      
      if (C.is_open()) {
         cout << " Opened database successfully: " << C.dbname() << endl<< endl;
      } else {
         cout << " Can't open database" << endl;
         return 1;
      }
      /* Create SQL statement */
      strcpy(sql ,dapat[1]);
      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
	strncpy(hantar[0],c[0].as<string>().c_str(),sizeof(hantar[0]));	
         cout << "   ID = " << hantar[0] << endl;
	strncpy(hantar[1],c[1].as<string>().c_str(),sizeof(hantar[1]));	
         cout << "   Name = " << hantar[1] << endl;
	strncpy(hantar[2],c[2].as<string>().c_str(),sizeof(hantar[2]));	
         cout << "   Couse Code = " << hantar[2] << endl;
	strncpy(hantar[3],c[3].as<string>().c_str(),sizeof(hantar[3]));	
         cout << "   Tel no = " << hantar[3] << endl;
	strncpy(hantar[4],c[5].as<string>().c_str(),sizeof(hantar[4]));	
         cout << "   Age = " << hantar[4] << endl;
      }
      cout<< endl << " Operation done successfully" << endl;
	cout<<" ________________________________________________________"<<endl;
      C.disconnect ();
   }catch (const std::exception &e){
      cerr << e.what() << std::endl;
	strcpy(hantar[0],"404");
   }
write(mysock,hantar,sizeof(hantar));
}
else if(strcmp(dapat[0],"3")==0){
cout<<" ________________________________________________________"<<endl;
strcpy(hantar[0],"");
try{
      connection C(db);
      if (C.is_open()) {
         cout << " Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }
      /* Create SQL statement */
      strcpy(sql , dapat[1]);

      /* Create a transactional object. */
      work W(C);
      
      /* Execute SQL query */
      W.exec( sql );
      W.commit();
      cout << endl<< " Records created successfully" << endl;
	strcpy(hantar[0],"success");
	cout<<" ________________________________________________________"<<endl;
      C.disconnect ();
   }catch (const std::exception &e){
      cerr << e.what() << std::endl;
	strcpy(hantar[0],"404");
   }
write(mysock,hantar,sizeof(hantar));
}
else if(strcmp(dapat[0],"4")==0){
strcpy(hantar[0],"");
cout<<" ________________________________________________________"<<endl;
try{
      connection C(db);
      if (C.is_open()) {
         cout << " Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }
      /* Create SQL statement */
      strcpy(sql , dapat[1]);
	
      /* Create a transactional object. */
      work W(C);
      
      /* Execute SQL query */
      W.exec( sql );
      W.commit();
      cout << endl << " Records deleted successfully" << endl;
	strcpy(hantar[0],"success");
	cout<<" ________________________________________________________"<<endl;
      C.disconnect ();
   }catch (const std::exception &e){
      cerr << e.what() << std::endl;
	strcpy(hantar[0],"404");
   }
write(mysock,hantar,sizeof(hantar));
}

//printf("Server site : ");
//scanf("%s",hantar);
strcpy(hantar[0],"");


				}

		}
	} while (1);
	return 0;
}
