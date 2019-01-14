/***********************************************************************
 * Module:  User.h
 * Author:  Duda Volodimir
 * Modified: 2 октября 2018 г. 0:21:12
 * Purpose: Declaration of the class User
 ***********************************************************************/

#if !defined(__ClassDiagram_1_User_h)
#define __ClassDiagram_1_User_h

class Work;

class User
{
public:
	User(); //Базова ініціалізація
	User(User &nUser); //Копіювання
	User(std::string name, int count_works, std::string works); //Звичайна ініціалізація
	~User(); //Деструктор
   virtual void show_all(void); //Показати усі мої роботи
   void edit_my(void); //Відредагувати мої роботи
   void add(void); //Додати роботу
   void delete_my(void); //Видалити роботу
   void SetName(std::string name_) { //Встановити імя
	   name = name_;
   }
   void SetCountWorks(int count_works_) { //Встановити кількість робіт
	   count_works = count_works_;
   }
   void SetWorks(std::string works_) { //Встановити роботи
	   works = works_;
   }
   std::string GetName() { //Взяти імя
	   return name;
   }
   int GetCountWorks() { //Взяти кількість робіт
	   return count_works;
   }
   std::string GetWorks() { //Взяти роботи
	   return works;
   }

   friend std::istream & operator >> (std::istream &stream, User &w) { //Перевантаження оператору для введення
	   std::cout << "Name: ";
	   stream >> w.name;
	   std::cout << "Count of works: ";
	   stream >> w.count_works;
	   return stream;
   }

   friend std::ostream & operator << (std::ostream &stream, User &w) { //Перевантаження оператору для виведення
	   stream << "Name: '" << w.name << "'\nCount of works - " << w.count_works << "\n";
	   return stream;
   }

   User & operator = (User &w) { //Перевантаження оператора присвоєння
	   this->name = w.name;
	   this->count_works = w.count_works;
	   this->works = w.works;
   }

protected:
private:
   std::string name; //Імя користувача
   int count_works; //Кількість робіт
   std::string works; //Роботи
   Work *work;
};

#endif