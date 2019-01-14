/***********************************************************************
 * Module:  BD.h
 * Author:  Duda Volodimir
 * Modified: 2 октября 2018 г. 0:39:39
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
	BD(); //Базова ініціалізація
	BD(BD &nBD); //Копіювання обєкту
	BD(std::string bdname); //Підключення до БД за її імям
	BD(sqlite3* connection); //Підключення до БД за покажчиком на її підключення
	~BD(); //Деструктор
   void add_line(std::string name, std::string title, std::string content); //Додати нову строчку до БД(роботу)
   void del_line(int id); //Видалення роботи по номеру
   void edit_line(int id, std::string title, std::string content); //Редагування роботи по номеру
   void load_line(int id); //Завантаження роботи по номеру
   void show_by_name(std::string name); //Завантаження роботи по автору
   void publish_line(int id); //Публікування роботи по номеру
   void save_to_archive(void); //Зберігання до архіву
   void SetDBname(std::string name) { //Встановлення назви БД
	   dbname = name;
   }
   void SetConnection(sqlite3 *conn) { //Підключення до БД за покажчиком
	   connection = conn;
   }
   std::string GetDBname() { //Взяття назви БД
	   return dbname;
   }
   sqlite3 * GetConnection() { //Взяття підключення до БД
	   return connection;
   }
   const std::string GetDefaultName() { //Взяття назви за замовченням
	   return default_name;
   }
   const int GetMaxCountLine() { //Взяття максимальної кількості робіт
	   return max_coun_line;
   }
   bool operator== (BD &db) { //Перевантаження оператору для порівняння назви та підключеня
	   return (db.dbname == dbname && db.connection == connection);
   }
   friend std::ostream & operator << (std::ostream &stream, BD &db) { //Перевантаження опереатору для виведення
	   stream << "Name: '" << db.dbname << "'(Has connection)\n";
	   return stream;
   }

protected:
private:
   std::string dbname; //Назва БД
   const std::string default_name = "db.sqlite"; //Назва БД за замовченням
   const int max_coun_line = 100; //Макс кількість записів
   sqlite3* connection; //Покажчик на підключення до БД
   void connect_sqlite(void); //Підключення до БД(для спрощення)
   bool check_err(int, char &); //Перевірка на помилку доступу до БД
   Archive *archive; //Покажчик на обєкт класу Архів
};

#endif