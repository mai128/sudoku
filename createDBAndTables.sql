create DATABASE sudoku;

use sudoku;

create table categoryOfPlays(
	ID int NOT NULL AUTO_INCREMENT,
	DIFF int NOT NULL,

	primary key (ID)
);

use sudoku;

create table plays(
	AA int NOT NULL AUTO_INCREMENT,
	ID int NOT NULL,
	x int NOT NULL,
	y int NOT NULL,
	val int NOT NULL,

	primary key (AA),
	foreign key (ID) references categoryOfPlays(ID)
);

use sudoku;

create table records(
	AA int NOT NULL AUTO_INCREMENT,
	ID int NOT NULL,
	name varchar(20) NOT NULL,
	time int NOT NULL,
	numOfErrors int NOT NULL,

	primary key (AA),
	foreign key (ID) references categoryOfPlays(ID)
);

use sudoku;

create table indexOfPlays(
	AA int NOT NULL AUTO_INCREMENT,
	DIFF int not NULL,
	category varchar(20) NOT NULL,

	primary key (AA)
);
