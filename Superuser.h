/***********************************************************************
 * Module:  User.h
 * Author:  Duda Volodimir
 * Modified: 2 ������� 2018 �. 0:21:12
 * Purpose: Declaration of the class Superuser
 ***********************************************************************/

#if !defined(__ClassDiagram_2_User_h)
#define __ClassDiagram_2_User_h


class Work;

class User;

class Superuser: public User
{
public:
	Superuser() : User("", 0, "") //������ �����������
	{
		acces_level = 0;
	};
	Superuser(std::string name, int count_works, std::string works, int acces_lev) : //�������� �����������
		User(name, count_works, works) 
	{
		acces_level = acces_lev;
	};
	void save_from_temp(int id) { //������� �� ��������� �������
		printf("Published %d work\n", id);
	}
	void transfer_work(int id) { //��������� �� �����������
		printf("Transfered %d work\n", id);
	}
	void show_all() { //��������� ������ ��� ������ ��� ����
		printf("SHOW ALL IN SUPERUSER\n");
	}

protected:
private:
	int acces_level; //г���� �������
};

#endif
