/***********************************************************************
 * Module:  Editor.cpp
 * Author:  Duda Volodimir
 * Modified: 2 октября 2018 г. 0:29:58
 * Purpose: Implementation of the class Editor
 ***********************************************************************/
#include <string>
#include "Work.h"
#include "Editor.h"
#include <string>
#include <iostream>

Editor::Editor() : //Базова ініціалізація
	name(""),
	work(new Work)

{
	std::cout << "Editor was initialized (default).\n";
}

Editor::Editor(Editor &nEditor) : //Копіювання обєкту
	name(nEditor.name),
	work(new Work)
{
	std::cout << "Editor was initialized (copy).\n";
}

Editor::Editor(std::string name, int reg_day) : //Звичайна ініціалізація
	name(name),
	work(new Work)
{
	std::cout << "Editor was initialized (normal).\n";
}

Editor::~Editor() { std::cout << "Editor was destroyed.\n"; } //Деструктор

////////////////////////////////////////////////////////////////////////
// Name:       Editor::show_temp()
// Purpose:    Implementation of Editor::show_temp()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Editor::show_temp(void) //Показати тимчасові файли
{
	return "Temp text";
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Editor::edit_temp()
// Purpose:    Implementation of Editor::edit_temp()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Editor::edit_temp(void) //Редагувати тимчасові файли
{
	printf("Editing temp text");
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Editor::del_temp()
// Purpose:    Implementation of Editor::del_temp()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Editor::del_temp(void) //Видалення тимчасових файлів
{
	printf("Deleting temp work");
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Editor::send_to_user()
// Purpose:    Implementation of Editor::send_to_user()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Editor::send_to_user(void) //Відправлення користувачу
{
	printf("Sending a letter to user");
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Editor::save_from_temp()
// Purpose:    Implementation of Editor::save_from_temp()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Editor::save_from_temp(void) //Збереження з тимчасових до архіву
{
	printf("Saving from temporary storage to archive");
   // TODO : implement
}