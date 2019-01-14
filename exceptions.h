#include <exception>
using namespace std;

class NotEnoughSpaceInArchive : public exception //Виникає якщо не достатньо місця в архіві
{
public: 
	NotEnoughSpaceInArchive() : exception(){

	}
	const char* what() const throw()
	{
		return "Delete some information to get more free space\n";
	}
};

class DatabaseError : public exception //Виникає внаслідок помилки доступу до БД
{
public: 
	DatabaseError() : exception(){

	}
	const char* what() const throw()
	{
		return "Error with database\n";
	}
};

class CantCloseConnection : public exception //Виникає внаслідок неможливості скасування підключення до БД
{
public: 
	CantCloseConnection() :exception(){

	}
	const char* what() const throw()
	{
		return "Error with closing connection\n";
	}
};
