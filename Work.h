/***********************************************************************
 * Module:  Work.h
 * Author:  Duda Volodimir
 * Modified: 2 октября 2018 г. 0:36:59
 * Purpose: Declaration of the class Work
 ***********************************************************************/
#include <iostream>

#if !defined(__ClassDiagram_1_Work_h)
#define __ClassDiagram_1_Work_h

class BD;

class Work
{
public:
	Work(); //Базова ініціалізація
	Work(Work &nWork); //Копіювання
	Work(int id, std::string name, std::string content, std::string title); //Звичайна ініціалізація
	~Work(); //Деструктор
   void edit(void); //Редагування роботи
   void del(void); //Видалення роботи
   void create(void); //Створення нової роботи
   void choose(void); //Вибір роботи
   void load(void); //Завантаження роботи
   void SetId(int id_) { //Встановлення id
	   id = id_;
   }
   void SetName(std::string name_) { //Встановлення імені автора
	   name = name_;
   }
   void SetContent(std::string content_) { //Встановлення контенту
	   content = content_;
   }
   void SetTitle(int title_) { //Встановлення заголовку
	   title = title_;
   }
   int GetId() { //Взяти id роботи
	   return id;
   }
   std::string GetName() { //Взяти імя автора
	   return name;
   }
   std::string GetTitle() { //Взяти заголовок роботи
	   return name;
   }
   std::string GetContent() { //Взяти контент роботи
	   return content;
   }
   friend std::istream & operator >> (std::istream &stream, Work &w) { //Перевантаження оператора для вводу
	   std::cout << "Title: ";
	   stream >> w.title;
	   std::cout << "Author: ";
	   stream >> w.name;
	   std::cout << "Content: \n";
	   stream >> w.content;
	   return stream;
   }

   friend std::ostream & operator << (std::ostream &stream, Work &w) { //Перевантаження оперетора для вводу
	   stream << "Title: '" << w.title << "'\nAuthor: '" << w.name << "'\n" << w.content << "\n";
	   return stream;
   }
   Work & operator + (Work &w) { //Перевантаження суми для обьеднання робіт в одну
	   Work new_w(this->id + w.id, this->name + " | " + w.name, this->title + " / " + w.name, this->content + "\n" + w.content);
	   return new_w;
   }

   Work & operator = (Work &w) { //Перевантаження оператора присвоєння
	   this->id = w.id;
	   this->name = w.name;
	   this->title = w.title;
	   this->content = w.content;
   }

protected:
private:
   int id; //Номер роботи
   std::string name; //Імя автора роботи
   std::string title; //Заголовок роботи
   std::string content; //Контент(зміст) роботи
   BD* db; //Покажчик на Базу Даних
};

#endif