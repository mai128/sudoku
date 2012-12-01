#queries to table categoryOfPlays

select * from categoryOfPlays where DIFF=1
select ID from categoryOfPlays where DIFF=1

select * from categoryOfPlays where DIFF=2
select ID from categoryOfPlays where DIFF=2

select * from categoryOfPlays where DIFF=3
select ID from categoryOfPlays where DIFF=3

#queries to table indexOfPlays

select category from indexOfPlays where DIFF=1
select category from indexOfPlays where DIFF=2
select category from indexOfPlays where DIFF=3

#queries to table plays

select x,y,val from plays where ID=1
select x,y,val from plays where ID=2
select x,y,val from plays where ID=3
select x,y,val from plays where ID=4
select x,y,val from plays where ID=5
select x,y,val from plays where ID=6
select x,y,val from plays where ID=7
select x,y,val from plays where ID=8
select x,y,val from plays where ID=9
select x,y,val from plays where ID=10
select x,y,val from plays where ID=11
select x,y,val from plays where ID=12
select x,y,val from plays where ID=13
select x,y,val from plays where ID=14
select x,y,val from plays where ID=15
select x,y,val from plays where ID=16
select x,y,val from plays where ID=17
select x,y,val from plays where ID=18

#queries to table records

insert to records values (' ',ID,'name',time,numOfErrors)
