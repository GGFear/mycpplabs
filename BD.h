/***********************************************************************
 * Module:  BD.h
 * Author:  Duda Volodimir
 * Modified: 2 ������� 2018 �. 0:39:39
 * Purpose: Declaration of the class BD
 ***********************************************************************/

#if !defined(__ClassDiagram_1_BD_h)
#define __ClassDiagram_1_BD_h
#include <string>
#include <iostream>

class Archive;
class sqlite3;

class BD
{
public:
	BD(); //������ �����������
	BD(BD &nBD); //��������� �����
	BD(std::string bdname); //ϳ��������� �� �� �� �� ����
	BD(sqlite3* connection); //ϳ��������� �� �� �� ���������� �� �� ����������
	~BD(); //����������
   void add_line(std::string name, std::string title, std::string content); //������ ���� ������� �� ��(������)
   void del_line(int id); //��������� ������ �� ������
   void edit_line(int id, std::string title, std::string content); //����������� ������ �� ������
   void load_line(int id); //������������ ������ �� ������
   void show_by_name(std::string name); //������������ ������ �� ������
   void publish_line(int id); //����������� ������ �� ������
   void save_to_archive(void); //��������� �� ������
   void SetDBname(std::string name) { //������������ ����� ��
	   dbname = name;
   }
   void SetConnection(sqlite3 *conn) { //ϳ��������� �� �� �� ����������
	   connection = conn;
   }
   std::string GetDBname() { //������ ����� ��
	   return dbname;
   }
   sqlite3 * GetConnection() { //������ ���������� �� ��
	   return connection;
   }
   const std::string GetDefaultName() { //������ ����� �� �����������
	   return default_name;
   }
   const int GetMaxCountLine() { //������ ����������� ������� ����
	   return max_coun_line;
   }
   bool operator== (BD &db) { //�������������� ��������� ��� ��������� ����� �� ���������
	   return (db.dbname == dbname && db.connection == connection);
   }
   friend std::ostream & operator << (std::ostream &stream, BD &db) { //�������������� ���������� ��� ���������
	   stream << "Name: '" << db.dbname << "'(Has connection)\n";
	   return stream;
   }

protected:
private:
   std::string dbname; //����� ��
   const std::string default_name = "db.sqlite"; //����� �� �� �����������
   const int max_coun_line = 100; //���� ������� ������
   sqlite3* connection; //�������� �� ���������� �� ��
   void connect_sqlite(void); //ϳ��������� �� ��(��� ���������)
   bool check_err(int, char &); //�������� �� ������� ������� �� ��
   Archive *archive; //�������� �� ���� ����� �����
};

#endif