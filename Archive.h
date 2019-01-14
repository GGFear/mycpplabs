/***********************************************************************
 * Module:  Archive.h
 * Author:  Duda Volodimir
 * Modified: 2 октября 2018 г. 0:44:16
 * Purpose: Declaration of the class Archive
 ***********************************************************************/

#if !defined(__ClassDiagram_1_Archive_h)
#define __ClassDiagram_1_Archive_h

class Archive
{
public:
	Archive(); //Базова ініціалізація
	Archive(Archive &nArchive); //Копіюваня обєкту
	Archive(int count, int max_count); //Звичайна ініціалізація
	~Archive(); //Конструктор
    void create_part(void); //Створення блоку архіву
    void check_parts(void); //Перевірка блоків архіву
	void SetDataParts(int data_parts_) { //Встановлення кількості блоків архіву
		data_parts = data_parts_;
	}
	void SetMaxDataParts(int max_data_parts_) { //Встановлення макс кількості блоків архіву
		max_data_parts = max_data_parts_;
	}
	void SetLastDateOfCheck(int last_date_of_check_) { //Встановлення останньої дати перевірки
		last_date_of_check = last_date_of_check_;
	}
	int GetDataParts() { //Отримання кількості блоків архіву
		return data_parts;
	}
	int GetMaxDataParts() { //Отримання макс кількості блоків архіву
		return max_data_parts;
	}
	int GetLastDateOfCheck() { //Отримання останньої дати перевірки
		return last_date_of_check;
	}
protected:
private:
   int data_parts; //Кількість блоків архіву
   int max_data_parts; //Мак кількість блоків архіву
   int last_date_of_check; //Остання дата перевірки архіву


};

#endif