# project

shukri khalid

project network programming (freeBsd,Debian,postgreSQL)

This program is simple database connection using socket programming.
My task to 
	-create server 1, database by using postgreSQL database, only to store data
	-create server 2, to recive instruction from client, run sql to get data from server 1 and store in char array then sent to client.
	-create client, presentation for user view, request data to server 2 and view the information.
	-apply basic CRUD

postgres sql + client + server

database postgres <-> server   <-> client
Debian64 GNOME    <-> Debian64 <-> freeBsd64

testing program
	chatc.c	client	
	chats.c	server	
	connectdb.cpp

projectClientPg.cpp use in Debian 8.2.0

projectServerPg.cpp use in FreeBSD-10.2-amd64
_______________________________________________________________________________________
DATABASE
database software pgAdmin III
Debian 8.2.0-amd64 GNOME
	apt -get install postgresql postgresql-client pgadmin3 // for postgres software
	apt -get install libpqxx-dev // for postgres library

	su postgres
	psql -d postgres
	\postgres password   (root)

IP adress for os 192.168.56.101
set pg_hba.conf

	cd /etc/postgresql/9.4/main
	
	pico pg_hba.conf
		host	all	all	127.0.0.1/32	md5
	to
		host	all	all	192.168.56.1/24	md5

	service postgresql restart

create database using pgAdmmin III
	database = uitm
	table = student

	CREATE TABLE uitm.student
	(
		stu_id serial NOT NULL,
		stu_name text,
		stu_course text,
		stu_tel text,
		stu_password text,
		stu_age integer,
		CONSTRAINT pk_student PRIMARY KEY (stu_id)
	)
	WITH (
		OIDS=FALSE
	);
	ALTER TABLE uitm.student
		OWNER To postgres;
	COMMENT ON COLUMN uitm.student.stu_id IS ' ';
	
_______________________________________________________________________________________
SERVER

Debian 8.2.0-amd64

	apt -get install g++ //c++ ide
	apt -get install libpqxx-dev // for postgres library

compile

	g++ projectServerPg.cpp -lpqxx -lpq

run

	./a.out
_______________________________________________________________________________________
ClIENT

FreeBSD-10.2-amd64

	pkg install cpp //c++ ide
	
compile

	cpp projectClientPg.cc -o c   

////note projectClientPg.cpp change to projectClientPg.cc

run

	./c


////note. compile projectServerPg.cpp -lpqxx -lpq it error because 
library for pqxx it not install in freeBsd.
For debian 8.2 use libpqxx-dev
