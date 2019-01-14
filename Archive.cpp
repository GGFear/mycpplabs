/***********************************************************************
 * Module:  Archive.cpp
 * Author:  Duda Volodimir
 * Modified: 2 ������� 2018 �. 0:44:16
 * Purpose: Implementation of the class Archive
 ***********************************************************************/

#include "exceptions.h"
#include <string>
#include "Archive.h"
#include <string>
#include <iostream>

Archive::Archive() : //������ �����������
	data_parts(0),
	max_data_parts(100),
	last_date_of_check(0)
{
	std::cout << "Archive was initialized (default).\n";
}

Archive::Archive(Archive &nArchive) : //��������� �����
	data_parts(nArchive.data_parts),
	max_data_parts(nArchive.max_data_parts),
	last_date_of_check(nArchive.last_date_of_check)
{
	std::cout << "Archive was initialized (copy).\n";
}

Archive::Archive(int count, int max_count) : //�������� �����������
	data_parts(count),
	max_data_parts(max_count),
	last_date_of_check(0)
{
	std::cout << "Archive was initialized (normal).\n";
}

Archive::~Archive() { std::cout << "Archive was destroyed.\n"; } //����������

////////////////////////////////////////////////////////////////////////
// Name:       Archive::create_part()
// Purpose:    Implementation of Archive::create_part()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Archive::create_part(void) //��������� ����� ������
{
	if (data_parts + 1 < max_data_parts) {
		data_parts++;
	}
	else {
		throw NotEnoughSpaceInArchive();
	}
	check_parts();
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Archive::check_parts()
// Purpose:    Implementation of Archive::check_parts()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Archive::check_parts(void) //�������� ����� ������
{
	printf("Parts checked");
   // TODO : implement
}