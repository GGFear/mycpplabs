#include <exception>
using namespace std;

class NotEnoughSpaceInArchive : public exception //������ ���� �� ��������� ���� � �����
{
public: 
	NotEnoughSpaceInArchive() : exception(){

	}
	const char* what() const throw()
	{
		return "Delete some information to get more free space\n";
	}
};

class DatabaseError : public exception //������ �������� ������� ������� �� ��
{
public: 
	DatabaseError() : exception(){

	}
	const char* what() const throw()
	{
		return "Error with database\n";
	}
};

class CantCloseConnection : public exception //������ �������� ����������� ���������� ���������� �� ��
{
public: 
	CantCloseConnection() :exception(){

	}
	const char* what() const throw()
	{
		return "Error with closing connection\n";
	}
};
