/***********************************************************************
 * Module:  User.cpp
 * Author:  Duda Volodimir
 * Modified: 2 октября 2018 г. 0:21:12
 * Purpose: Implementation of the class User
 ***********************************************************************/

#include <string>
#include "Work.h"
#include "User.h"
#include <string>
#include <iostream>

User::User() : //Базова ініціалізація
	name(""),
	count_works(0),
	works(""),
	work(new Work)
{
	std::cout << "User was initialized (default).\n";
}

User::User(User &nUser) : //Копіювання обєкту
	name(nUser.name),
	count_works(nUser.count_works),
	works(nUser.works),
	work(new Work)
{
	std::cout << "User was initialized (copy).\n";
}

User::User(std::string name, int count_works, std::string works) : //Звичайна ініціалізація
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

void User::show_all(void) //Показати усі роботи користувача
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

void User::edit_my(void) //Відредагувати роботу
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

void User::add(void) //Створити нову роботу
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

void User::delete_my(void) //Видалити роботу
{
	Work w;
	w.del();
   // TODO : implement
}
