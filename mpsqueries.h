#ifndef MPSQUERIES_H
#define MPSQUERIES_H
//=========================
//file queries
//=========================
const QString APPLICATION_FILE_NAME ="mpsmanager";

QString sqlStrProjectCreationQuery ="CREATE TABLE PROJECT ("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \n"
                 "NAME TEXT(16) NOT NULL, \n"
                 "MAXIMIZE INTEGER NOT NULL DEFAULT (0), \n"
                 "TITLE TEXT(60) , \n"
                 "MEMO BLOB)\n";

QString sqlStrColumnsCreationQuery =
                "CREATE TABLE COLUMNS ("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \n"
                 "NAME TEXT(16) NOT NULL, \n"
                 "TITLE TEXT(60) , \n"
                 "MEMO BLOB)\n";

QString sqlStrRowsCreationQuery =
                "CREATE TABLE ROWS ("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \n"
                 "EQUIN TEXT(2) NOT NULL, \n"
                 "NAME TEXT(16) NOT NULL, \n"
                 "TITLE TEXT(60) , \n"
                 "MEMO BLOB)\n";

QString sqlStrRHSCreationQuery =
                "CREATE TABLE RHS ("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \n"
                 "ROW_NAME TEXT(16) NOT NULL, \n"
                 "VALUE REAL NOT NULL DEFAULT (0), \n"
                 "FOREIGN KEY(ROW_NAME) REFERENCES ROWS(NAME)) \n";

QString sqlStrCellsCreationQuery =
                "CREATE TABLE CELLS ("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \n"
                 "ROW_NAME TEXT(16) NOT NULL, \n"
                 "COLUMN_NAME TEXT(16) NOT NULL, \n"
                 "VALUE REAL NOT NULL DEFAULT (0), \n"
                 "FOREIGN KEY(ROW_NAME) REFERENCES ROWS(NAME), \n"
                 "FOREIGN KEY(COLUMN_NAME) REFERENCES COLUMNS(NAME)) \n";



QString sqlIndexColumnsQuery =
        "CREATE UNIQUE INDEX COLUMNS_IX ON COLUMNS (NAME ASC)\n";

QString sqlIndexRowsQuery =
        "CREATE UNIQUE INDEX ROWS_IX ON ROWS (NAME ASC)\n";

QString sqlIndexRHSQuery =
        "CREATE UNIQUE INDEX RHS_IX ON RHS (ROW_NAME ASC)\n";

QString sqlIndexCellsQuery = "CREATE UNIQUE INDEX CELL_IX ON CELLS (ROW_NAME,COLUMN_NAME ASC)\n";

QString sqlStrSettingsCreationQuery =
                 "CREATE TABLE PROGRAMS ("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \n"
                 "TITLE TEXT(60) , \n"
                 "NAME TEXT(256) NOT NULL) \n";

QString sqlImportProjectRecord  ="INSERT INTO PROJECT(NAME, MAXIMIZE ) VALUES ('%1',%2)";

QString sqlImportColumn = "INSERT INTO COLUMNS(NAME) VALUES ('%1')";

QString sqlImportRow = "INSERT INTO ROWS(EQUIN,NAME ) VALUES ('%1','%2')";

QString sqlImportRHS = "INSERT INTO RHS(ROW_NAME,VALUE) VALUES ('%1',%2)";

QString sqlImportCell = "INSERT INTO CELLS(ROW_NAME , COLUMN_NAME, VALUE) VALUES ('%1' , '%2' , %3)";

QString sqlGetProjectRecord ="SELECT * FROM PROJECT ";
#endif // MPSQUERIES_H
