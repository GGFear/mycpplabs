/***********************************************************************
 * Module:  Work.cpp
 * Author:  Duda Volodimir
 * Modified: 2 ������� 2018 �. 0:36:59
 * Purpose: Implementation of the class Work
 ***********************************************************************/

#include "exceptions.h"
#include <string>
#include "BD.h"
#include "Work.h"
#include <string>
#include <iostream>
#include "sqlite3.h"

Work::Work() : //������ �����������
	id(0),
	name(""),
	content(""),
	title(""),
	db(new BD)
{
	std::cout << "Work was initialized (default).\n";
}

Work::Work(Work &nWork) : //��������� �����
	id(nWork.id),
	name(nWork.name),
	content(nWork.content),
	title(nWork.title),
	db(new BD)
{
	std::cout << "Work was initialized (copy).\n";
}

Work::Work(int id, std::string name, std::string content, std::string title) : //�������� �����������
	id(id),
	name(name),
	content(content),
	title(title),
	db(new BD)
{
	std::cout << "Work was initialized (normal).\n";
}

Work::~Work() { //����������
	delete db;
	if (db) {
		throw CantCloseConnection();
	}
	std::cout << "Work was destroyed.\n"; 
}

////////////////////////////////////////////////////////////////////////
// Name:       Work::edit()
// Purpose:    Implementation of Work::edit()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Work::edit(void) //����������� ������
{
	printf("Enter id: ");
	int id;
	std::cin >> id;
	printf("\nEnter title: ");
	std::getline(std::cin, title);
	printf("Enter content: ");
	std::getline(std::cin, content);
	db->edit_line(id, title, content);
	printf("\nSaved");
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Work::delete()
// Purpose:    Implementation of Work::delete()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Work::del(void) //��������� ������
{
	printf("Enter id: ");
	int id;
	std::cin >> id;
	db->del_line(id);
	printf("\nDeleted");
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Work::create()
// Purpose:    Implementation of Work::create()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Work::create(void) //�������� ���� ������
{
	printf("Enter title: ");
	std::getline(std::cin, title);
	printf("Enter content: ");
	std::getline(std::cin, content);
	db->add_line(name, title, content);
	printf("\nCreated");
}

////////////////////////////////////////////////////////////////////////
// Name:       Work::load()
// Purpose:    Implementation of Work::load()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Work::load(void) //������������ ����� ������
{
	printf("Enter id: ");
	int id;
	std::cin >> id;
	printf("\nResult:\n");
	db->load_line(id);
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Work::choose()
// Purpose:    Implementation of Work::choose()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Work::choose(void) //���� ������ � ������
{
	printf("My works: \n");
	db->show_by_name(name);
	// TODO : implement
}