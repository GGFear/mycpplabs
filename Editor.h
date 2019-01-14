/***********************************************************************
 * Module:  Editor.h
 * Author:  Duda Volodimir
 * Modified: 2 октября 2018 г. 0:29:58
 * Purpose: Declaration of the class Editor
 ***********************************************************************/

#if !defined(__ClassDiagram_1_Editor_h)
#define __ClassDiagram_1_Editor_h

class Work;

class Editor
{
public:
	Editor(); //Базова ініціалізація 
	Editor(Editor &nEditor); //Копіювання обєкту
	Editor(std::string name, int reg_day); //Звичайна ініціалізація
	~Editor(); //Деструктор
   std::string show_temp(void); //Повернути тимчасові роботи
   void edit_temp(void); //Відредагувати тимчасові роботи
   void del_temp(void); //Видалення тимчасових робіт
   void send_to_user(void); //Відправлення листа користувачу на перегляд
   void save_from_temp(void); //Збереження з тимчасової памяті до архіву
   void SetName(std::string name_) { //Встановити імя
	   name = name_;
   }
   std::string GetName() { //Взяти імя
	   return name;
   }
   friend std::istream & operator >> (std::istream &stream, Editor &w) { //Перевантаження оператору для введення
	   std::cout << "Name: ";
	   stream >> w.name;
	   return stream;
   }

   friend std::ostream & operator << (std::ostream &stream, Editor &w) { //Перевантаження оператору для виведення
	   stream << "Name: '" << w.name << "'\n";
	   return stream;
   }

   Editor & operator = (Editor &w) { //Перевантаження оператора присвоєння
	   this->name = w.name;
   }

protected:
private:
   std::string name; //Імя редактора
   Work *work;
};

#endif