use sudoku;

insert into categoryOfPlays values (' ',1),(' ',1),(' ',2),(' ',2),(' ',3),(' ',3),(' ',1),(' ',1),(' ',2)(' ',2),(' ',2),(' ',3),(' ',3),(' ',1),(' ',3);

insert into indexOfPlays values (' ',1,'easy'), (' ',2,'medium'),(' ',3,'hard');

insert into plays values 
(' ',1,0,3,5),(' ',1,0,5,3),(' ',1,0,6,7),
(' ',1,1,1,6),(' ',1,1,3,9),(' ',1,1,5,2),(' ',1,1,6,1),(' ',1,1,8,8),
(' ',1,2,0,5),(' ',1,2,1,4),(' ',1,2,3,8),(' ',1,2,8,9),
(' ',1,3,1,7),(' ',1,3,2,3),(' ',1,3,4,5),(' ',1,3,5,6),(' ',1,3,6,4),
(' ',1,4,1,1),(' ',1,4,7,7),
(' ',1,5,2,5),(' ',1,5,3,7),(' ',1,5,4,3),(' ',1,5,6,2),(' ',1,5,7,9),
(' ',1,6,0,8),(' ',1,6,5,9),(' ',1,6,7,6),(' ',1,6,8,3),
(' ',1,7,0,6),(' ',1,7,2,1),(' ',1,7,3,3),(' ',1,7,5,4),(' ',1,7,7,2),
(' ',1,8,2,9),(' ',1,8,3,6),(' ',1,8,5,5);

insert into plays values 
(' ',2,0,3,3),(' ',2,0,7,1),
(' ',2,1,0,8),(' ',2,1,4,1),(' ',2,1,5,6),(' ',2,1,6,7),(' ',2,1,8,2),
(' ',2,2,0,1),(' ',2,2,5,9),(' ',2,2,6,3),
(' ',2,3,0,7),(' ',2,3,2,3),(' ',2,3,6,6),(' ',2,3,7,4),(' ',2,3,8,5),
(' ',2,4,0,5),(' ',2,4,2,6),(' ',2,4,3,8),(' ',2,4,5,4),(' ',2,4,6,9),(' ',2,4,8,7),
(' ',2,5,0,2),(' ',2,5,1,9),(' ',2,5,2,4),(' ',2,5,6,8),(' ',2,5,8,1),
(' ',2,6,2,1),(' ',2,6,3,7),(' ',2,6,8,8),
(' ',2,7,0,3),(' ',2,7,2,7),(' ',2,7,3,9),(' ',2,7,4,2),(' ',2,7,8,4),
(' ',2,8,1,6),(' ',2,8,5,1);

insert into plays values 
(' ',3,0,2,7),(' ',3,0,3,8),(' ',3,0,4,6),(' ',3,0,5,1),
(' ',3,1,2,8),(' ',3,1,5,3),
(' ',3,2,0,5),(' ',3,2,1,6),(' ',3,2,4,9),(' ',3,2,7,1),
(' ',3,3,0,1),(' ',3,3,4,7),(' ',3,3,7,8),(' ',3,3,8,5),
(' ',3,4,3,3),(' ',3,4,4,4),(' ',3,5,5,5),
(' ',3,5,0,6),(' ',3,5,1,3),(' ',3,5,4,1),(' ',3,5,8,7),
(' ',3,6,1,5),(' ',3,6,4,2),(' ',3,6,7,9),(' ',3,6,8,8),
(' ',3,7,3,6),(' ',3,7,6,5),
(' ',3,8,3,5),(' ',3,8,4,3),(' ',3,8,5,7),(' ',3,8,6,1);

insert into plays values 
(' ',4,0,1,1),(' ',4,0,4,5),(' ',4,0,6,9),(' ',4,0,7,8),
(' ',4,1,2,8),(' ',4,1,6,1),(' ',4,1,7,3),(' ',4,1,8,5),
(' ',4,2,5,8),(' ',4,2,6,4),(' ',4,2,8,6),
(' ',4,3,0,3),(' ',4,3,3,4),(' ',4,3,4,1),(' ',4,3,6,5),
(' ',4,4,3,3),(' ',4,4,5,8),
(' ',4,5,2,1),(' ',4,5,4,9),(' ',4,5,5,6),(' ',4,5,8,7),
(' ',4,6,0,1),(' ',4,6,2,7),(' ',4,6,4,6),
(' ',4,7,0,8),(' ',4,7,1,9),(' ',4,7,2,2),(' ',4,7,6,7),
(' ',4,8,1,3),(' ',4,8,2,6),(' ',4,8,4,4),(' ',4,8,7,9);

insert into plays values 
(' ',5,0,0,1),(' ',5,0,3,4),(' ',5,0,4,5),(' ',5,0,5,9),
(' ',5,1,0,8),(' ',5,1,2,3),(' ',5,1,4,7),(' ',5,1,6,9),
(' ',5,2,5,8),
(' ',5,3,0,5),(' ',5,3,2,8),(' ',5,3,5,2),(' ',5,3,6,6),
(' ',5,4,0,9),(' ',5,4,4,6),(' ',5,5,8,7),
(' ',5,5,2,7),(' ',5,5,3,9),(' ',5,5,6,1),(' ',5,5,8,5),
(' ',5,6,3,2),
(' ',5,7,2,6),(' ',5,7,4,8),(' ',5,7,6,2),(' ',5,7,8,4),
(' ',5,8,3,5),(' ',5,8,4,9),(' ',5,8,5,4),(' ',5,8,8,3);

insert into plays values 
(' ',6,0,1,5),(' ',6,0,3,7),(' ',6,0,5,2),(' ',6,0,8,3),
(' ',6,1,1,7),(' ',6,1,2,3),(' ',6,1,3,4),(' ',6,1,4,8),(' ',6,1,8,5),
(' ',6,2,4,5),(' ',6,2,6,4),
(' ',6,3,1,4),(' ',6,3,6,2),
(' ',6,4,1,2),(' ',6,4,2,7),(' ',6,4,4,9),(' ',6,4,6,3),(' ',6,4,7,5),
(' ',6,5,2,6),(' ',6,5,7,1),
(' ',6,6,2,5),(' ',6,6,4,3),
(' ',6,7,0,4),(' ',6,7,4,6),(' ',6,7,5,8),(' ',6,7,6,7),(' ',6,7,7,3),
(' ',6,8,0,7),(' ',6,8,3,1),(' ',6,8,5,9),(' ',6,8,7,6);

insert into plays values 
(' ',7,0,0,8),(' ',7,0,1,6),(' ',7,0,5,9),(' ',7,0,6,4),(' ',7,0,7,7),
(' ',7,1,3,5),(' ',7,1,4,3),(' ',7,1,5,4),
(' ',7,2,0,1),(' ',7,2,3,8),(' ',7,2,4,7),(' ',7,2,8,9),
(' ',7,3,2,1),(' ',7,3,3,9),(' ',7,3,4,8),(' ',7,3,6,7),
(' ',7,4,3,7),(' ',7,4,5,2),
(' ',7,5,2,7),(' ',7,5,4,4),(' ',7,5,5,5),(' ',7,5,6,3),
(' ',7,6,0,6),(' ',7,6,4,5),(' ',7,6,5,1),(' ',7,6,8,8),
(' ',7,7,3,4),(' ',7,7,4,9),(' ',7,7,5,8),
(' ',7,8,1,9),(' ',7,8,2,8),(' ',7,8,3,2),(' ',7,8,7,4),(' ',7,8,8,5);

insert into plays values 
(' ',8,0,4,1),(' ',8,0,8,8),
(' ',8,1,2,8),(' ',8,1,3,4),(' ',8,1,4,6),(' ',8,1,5,3),(' ',8,1,7,2),
(' ',8,2,2,3),(' ',8,2,5,2),(' ',8,2,6,5),(' ',8,2,7,4),(' ',8,2,8,7),
(' ',8,3,3,8),(' ',8,3,8,4),
(' ',8,4,0,7),(' ',8,4,2,1),(' ',8,4,4,3),(' ',8,4,6,9),(' ',8,4,8,6),
(' ',8,5,0,4),(' ',8,5,5,6),
(' ',8,6,0,1),(' ',8,6,1,2),(' ',8,6,2,7),(' ',8,6,3,3),(' ',8,6,6,6),
(' ',8,7,1,3),(' ',8,7,3,6),(' ',8,7,4,9),(' ',8,7,5,5),(' ',8,7,6,2),
(' ',8,8,0,9),(' ',8,8,4,2);

insert into plays values 
(' ',9,0,5,3),
(' ',9,1,1,4),(' ',9,1,2,8),(' ',9,1,3,5),(' ',9,1,7,9),
(' ',9,2,0,2),(' ',9,2,1,9),(' ',9,2,3,7),(' ',9,2,7,3),(' ',9,2,8,6),
(' ',9,3,0,9),(' ',9,3,2,4),(' ',9,3,3,1),(' ',9,3,5,7),(' ',9,3,7,6),(' ',9,3,8,2),
(' ',9,4,2,2),(' ',9,4,6,3),
(' ',9,5,0,8),(' ',9,5,1,1),(' ',9,5,3,3),(' ',9,5,5,2),(' ',9,5,6,7),(' ',9,5,8,9),
(' ',9,6,0,1),(' ',9,6,1,5),(' ',9,6,5,9),(' ',9,6,7,4),(' ',9,6,8,8),
(' ',9,7,1,2),(' ',9,7,5,8),(' ',9,7,6,9),(' ',9,7,7,7),
(' ',9,8,3,6);

insert into plays values 
(' ',10,0,1,9),(' ',10,0,2,5),(' ',10,0,5,1),(' ',10,0,7,6),
(' ',10,1,1,8),(' ',10,1,2,4),(' ',10,1,3,5),(' ',10,1,4,7),
(' ',10,2,2,7),(' ',10,2,5,8),(' ',10,2,7,4),
(' ',10,3,0,7),(' ',10,3,3,9),(' ',10,3,7,1),(' ',10,3,8,3),
(' ',10,4,2,2),(' ',10,4,6,7),
(' ',10,5,0,3),(' ',10,5,1,5),(' ',10,5,5,7),(' ',10,5,8,4),
(' ',10,6,1,1),(' ',10,6,3,7),(' ',10,6,6,4),
(' ',10,7,4,9),(' ',10,7,5,4),(' ',10,7,6,6),(' ',10,7,7,7),
(' ',10,8,1,7),(' ',10,8,3,2),(' ',10,8,6,3),(' ',10,8,7,5);

insert into plays values 
(' ',11,0,0,7),(' ',11,0,1,8),(' ',11,0,2,9),(' ',11,0,3,4),(' ',11,0,7,3),
(' ',11,1,0,1),(' ',11,1,1,4),(' ',11,1,2,2),(' ',11,1,4,9),
(' ',11,2,1,5),(' ',11,2,5,8),(' ',11,2,6,1),
(' ',11,3,1,7),(' ',11,3,5,6),(' ',11,3,8,3),
(' ',11,4,1,1),(' ',11,4,3,7),(' ',11,4,5,2),(' ',11,4,7,6),
(' ',11,5,0,9),(' ',11,5,3,5),(' ',11,5,7,1),
(' ',11,6,2,8),(' ',11,6,3,1),(' ',11,6,7,5),
(' ',11,7,4,5),(' ',11,7,6,3),(' ',11,7,7,4),(' ',11,7,8,1),
(' ',11,8,1,9),(' ',11,8,5,4),(' ',11,8,6,8),(' ',11,8,7,2),(' ',11,8,9,7);

insert into plays values 
(' ',12,0,0,4),(' ',12,0,3,3),
(' ',12,1,1,2),(' ',12,1,4,7),(' ',12,1,7,6),
(' ',12,2,1,7),(' ',12,2,2,8),(' ',12,2,3,5),(' ',12,2,4,6),(' ',12,2,6,4),
(' ',12,3,0,9),(' ',12,3,1,5),(' ',12,3,4,4),(' ',12,3,6,1),(' ',12,3,8,8),
(' ',12,4,0,6),(' ',12,4,2,3),(' ',12,4,6,5),(' ',12,4,8,4),
(' ',12,5,0,7),(' ',12,5,2,4),(' ',12,5,4,5),(' ',12,5,7,9),(' ',12,5,8,6),
(' ',12,6,2,5),(' ',12,6,4,3),(' ',12,6,5,7),(' ',12,6,6,6),(' ',12,6,7,4),
(' ',12,7,1,4),(' ',12,7,4,8),(' ',12,7,7,3),
(' ',12,8,5,6),(' ',12,8,8,5),

insert into plays values 
(' ',13,0,0,9),(' ',13,0,2,5),(' ',13,0,3,1),(' ',13,0,4,4),(' ',13,0,8,3),
(' ',13,1,1,8),(' ',13,1,7,5),
(' ',13,2,1,3),(' ',13,2,2,1),(' ',13,2,5,5),
(' ',13,3,0,5),(' ',13,3,1,7),(' ',13,3,3,8),(' ',13,3,6,3),
(' ',13,4,0,4),(' ',13,4,1,1),(' ',13,4,7,2),(' ',13,4,8,7),
(' ',13,5,2,3),(' ',13,5,5,2),(' ',13,5,7,1),(' ',13,5,8,9),
(' ',13,6,3,6),(' ',13,6,6,9),(' ',13,6,8,3),
(' ',13,7,1,9),(' ',13,7,7,7),
(' ',13,8,0,1),(' ',13,8,4,3),(' ',13,8,5,9),(' ',13,8,6,6),(' ',13,8,8,2);

insert into plays values 
(' ',14,0,4,3),(' ',14,0,7,2),
(' ',14,1,2,3),(' ',14,1,3,5),(' ',14,1,5,6),(' ',14,1,6,9),(' ',14,1,8,7),
(' ',14,2,2,7),(' ',14,2,3,8),(' ',14,2,5,4),(' ',14,2,6,1),(' ',14,2,8,5),
(' ',14,3,1,7),(' ',14,3,7,6),(' ',14,3,8,9),
(' ',14,4,0,2),(' ',14,4,3,3),(' ',14,4,4,7),(' ',14,4,5,8),(' ',14,4,8,1),
(' ',14,5,0,5),(' ',14,5,1,3),(' ',14,5,7,7),
(' ',14,6,0,9),(' ',14,6,2,6),(' ',14,6,3,7),(' ',14,6,5,3),(' ',14,6,6,2),
(' ',14,7,0,7),(' ',14,7,2,1),(' ',14,7,3,6),(' ',14,7,5,2),(' ',14,7,6,5),
(' ',14,8,1,5),(' ',14,8,4,9);

insert into plays values 
(' ',15,0,5,9),(' ',15,0,7,6),(' ',15,0,8,2),
(' ',15,1,0,6),(' ',15,1,2,2),(' ',15,1,4,5),(' ',15,1,5,7),(' ',15,1,6,8),(' ',15,1,8,1),
(' ',15,2,5,2),(' ',15,2,6,5),
(' ',15,3,1,8),(' ',15,3,5,1),(' ',15,3,8,5),
(' ',15,4,2,1),(' ',15,4,3,7),(' ',15,4,4,4),(' ',15,4,5,5),(' ',15,4,6,6),
(' ',15,5,0,7),(' ',15,5,3,3),(' ',15,5,7,1),
(' ',15,6,2,8),(' ',15,6,3,1),
(' ',15,7,0,1),(' ',15,7,2,4),(' ',15,7,3,5),(' ',15,7,4,2),(' ',15,7,6,7),(' ',15,7,8,3),
(' ',15,8,0,3),(' ',15,8,1,7),(' ',15,8,3,9);
