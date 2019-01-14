/***********************************************************************
 * Module:  BD.cpp
 * Author:  Duda Volodimir
 * Modified: 2 октября 2018 г. 0:39:39
 * Purpose: Implementation of the class BD
 ***********************************************************************/

#include "exceptions.h"
#include "Archive.h"
#include "BD.h"
#include "Work.h"
#include <iostream>
#include "sqlite3.h"

int output(void * w, int argc, char **argv, char **azColName) { //Форматування виводу для БД
	printf("***********************************************************************\n");
	printf("№%s: <<%s>> (%s)\nAuthor: %s\n%s\n", argv[0], argv[2], atoi(argv[4]) ? "PUBLISHED YET" : "NOT PUBLISHED", argv[1], argv[3]);
	printf("***********************************************************************\n");
	return 0;
}

int output_short(void *NotUsed, int argc, char **argv, char **azColName) { //Скорочене форматування для БД
	printf("№%s: <<%s>>", argv[0], argv[1]);
	return 0;
}

BD::BD() : //Базова ініціалізація
	connection(NULL),
	dbname(default_name),
	archive(new Archive)
{
	dbname = default_name;
	connect_sqlite();
	std::cout << "BD was initialized (default). \n";
}

BD::BD(BD &nBD) : //Копіювання обєкту
	dbname(nBD.dbname),
	connection(nBD.connection),
	archive(new Archive)
{
	std::cout << "BD was initialized (copy). \n";
}

BD::BD(std::string bdname) : //Підключення до БД за її імям
	connection(NULL),
	dbname(bdname),
	archive(new Archive)
{
	connect_sqlite();
	std::cout << "BD was initialized (normal). \n";
}

BD::BD(sqlite3 * connection_) : //Підключення до БД за покажчиком на її підключення
	connection(connection_),
	dbname(""),
	archive(new Archive)
{
	connect_sqlite();
	std::cout << "BD was initialized (normal). \n";
}

BD::~BD() { //Деструктор
	delete archive;
	sqlite3_close(connection); 
	std::cout << "BD was destroyed. \n"; 
}

////////////////////////////////////////////////////////////////////////
// Name:       BD::add_line()
// Purpose:    Implementation of BD::add_line()
// Return:     void
////////////////////////////////////////////////////////////////////////

void BD::add_line(std::string name, std::string title, std::string content) // Додавання роботи в БД
{
	std::string sql = "INSERT INTO articles (writer, title, content, is_published) VALUES ('" + name + "', '" + title + "', '" + content + "', 0);";
	char *err = NULL;
	check_err(sqlite3_exec(connection, sql.c_str(), 0, 0, &err), *err);
	save_to_archive();
}

////////////////////////////////////////////////////////////////////////
// Name:       BD::del_line()
// Purpose:    Implementation of BD::del_line()
// Return:     void
////////////////////////////////////////////////////////////////////////

void BD::del_line(int id) //Видалення роботи за номером роботи
{
	std::string sql = "DELETE FROM articles WHERE id = " + std::to_string(id);
	char *err = NULL;
	check_err(sqlite3_exec(connection, sql.c_str(), 0, 0, &err), *err);
	save_to_archive();
}

////////////////////////////////////////////////////////////////////////
// Name:       BD::edit_line()
// Purpose:    Implementation of BD::edit_line()
// Return:     void
////////////////////////////////////////////////////////////////////////

void BD::edit_line(int id, std::string title, std::string content) //Поновлення значення роботи по номеру
{
	std::string sql = "UPDATE articles SET title = '" + title + "', content = '" + content + "' WHERE id = " + std::to_string(id);
	char *err = NULL;
	check_err(sqlite3_exec(connection, sql.c_str(), 0, 0, &err), *err);
	save_to_archive();
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       BD::save_to_archive()
// Purpose:    Implementation of BD::save_to_archive()
// Return:     void
////////////////////////////////////////////////////////////////////////

void BD::save_to_archive(void) //Збереження до архіву
{
	archive->create_part();
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       BD::show_line()
// Purpose:    Implementation of BD::show_line()
// Return:     void
////////////////////////////////////////////////////////////////////////

void BD::load_line(int id) //Завантаження роботи з БД
{
	std::string sql = "SELECT * FROM articles WHERE id = " + std::to_string(id);
	char *err = NULL;
	check_err(sqlite3_exec(connection, sql.c_str(), output, 0, &err), *err);
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       BD::show_by_name()
// Purpose:    Implementation of BD::show_by_name()
// Return:     void
////////////////////////////////////////////////////////////////////////

void BD::show_by_name(std::string name) //Завантаження за іменем автора
{
	std::string sql = "SELECT (id, title) FROM articles WHERE name = " + name;
	char *err = NULL;
	check_err(sqlite3_exec(connection, sql.c_str(), output_short, 0, &err), *err);
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       BD::publish_line()
// Purpose:    Implementation of BD::publish_line()
// Return:     void
////////////////////////////////////////////////////////////////////////

void BD::publish_line(int id) //Публікація роботи
{
	std::string sql = "UPDATE articles SET is_published = 1 WHERE id = " + std::to_string(id);
	char *err = NULL;
	check_err(sqlite3_exec(connection, sql.c_str(), 0, 0, &err), *err);
	save_to_archive();
	// TODO : implement
}

void BD::connect_sqlite(void) { //Підключення до БД
	char *err;
	const char *create_table = "CREATE TABLE IF NOT EXISTS articles (id INTEGER PRIMARY KEY AUTOINCREMENT, writer TEXT NOT NULL, title TEXT NOT NULL, content TEXT NOT NULL, is_published BOOL NOT NULL);";
	if (sqlite3_open(dbname.c_str(), &connection))
		fprintf(stderr, "Error in connecting DB: %s\n", sqlite3_errmsg(connection));
	else if (sqlite3_exec(connection, create_table, 0, 0, &err))
	{
		fprintf(stderr, "Error creating_table: %sn", err);
		sqlite3_free(err);
	}
}


bool BD::check_err(int rc, char & err_msg) { //Перевірка помилок БД
	if (rc != SQLITE_OK) {

		fprintf(stderr, "Failed to select data\n");
		fprintf(stderr, "SQL error: %s\n", err_msg);

		sqlite3_free(&err_msg);
		sqlite3_close(connection);
		return 1;
	}
	else { 
		throw DatabaseError();
		return 0; 
	}
}