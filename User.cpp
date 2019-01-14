/***********************************************************************
 * Module:  User.cpp
 * Author:  Duda Volodimir
 * Modified: 2 ������� 2018 �. 0:21:12
 * Purpose: Implementation of the class User
 ***********************************************************************/

#include <string>
#include "Work.h"
#include "User.h"
#include <string>
#include <iostream>

User::User() : //������ �����������
	name(""),
	count_works(0),
	works(""),
	work(new Work)
{
	std::cout << "User was initialized (default).\n";
}

User::User(User &nUser) : //��������� �����
	name(nUser.name),
	count_works(nUser.count_works),
	works(nUser.works),
	work(new Work)
{
	std::cout << "User was initialized (copy).\n";
}

User::User(std::string name, int count_works, std::string works) : //�������� �����������
	name(name),
	count_works(count_works),
	works(works),
	work(new Work)
{
	std::cout << "User was initialized (normal).\n";
}

User::~User() { std::cout << "User was destroyed.\n"; }

////////////////////////////////////////////////////////////////////////
// Name:       User::show_all()
// Purpose:    Implementation of User::show_all()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

void User::show_all(void) //�������� �� ������ �����������
{
	Work w;
	w.choose();
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       User::edit_my()
// Purpose:    Implementation of User::edit_my()
// Return:     void
////////////////////////////////////////////////////////////////////////

void User::edit_my(void) //³����������� ������
{
	Work w;
	w.edit();
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       User::add()
// Purpose:    Implementation of User::add()
// Return:     void
////////////////////////////////////////////////////////////////////////

void User::add(void) //�������� ���� ������
{
	Work w;
	w.create();
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       User::delete_my()
// Purpose:    Implementation of User::delete_my()
// Return:     void
////////////////////////////////////////////////////////////////////////

void User::delete_my(void) //�������� ������
{
	Work w;
	w.del();
   // TODO : implement
}
