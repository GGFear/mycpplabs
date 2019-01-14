/***********************************************************************
 * Module:  User.h
 * Author:  Duda Volodimir
 * Modified: 2 ������� 2018 �. 0:21:12
 * Purpose: Declaration of the class User
 ***********************************************************************/

#if !defined(__ClassDiagram_1_User_h)
#define __ClassDiagram_1_User_h

class Work;

class User
{
public:
	User(); //������ �����������
	User(User &nUser); //���������
	User(std::string name, int count_works, std::string works); //�������� �����������
	~User(); //����������
   virtual void show_all(void); //�������� �� �� ������
   void edit_my(void); //³����������� �� ������
   void add(void); //������ ������
   void delete_my(void); //�������� ������
   void SetName(std::string name_) { //���������� ���
	   name = name_;
   }
   void SetCountWorks(int count_works_) { //���������� ������� ����
	   count_works = count_works_;
   }
   void SetWorks(std::string works_) { //���������� ������
	   works = works_;
   }
   std::string GetName() { //����� ���
	   return name;
   }
   int GetCountWorks() { //����� ������� ����
	   return count_works;
   }
   std::string GetWorks() { //����� ������
	   return works;
   }

   friend std::istream & operator >> (std::istream &stream, User &w) { //�������������� ��������� ��� ��������
	   std::cout << "Name: ";
	   stream >> w.name;
	   std::cout << "Count of works: ";
	   stream >> w.count_works;
	   return stream;
   }

   friend std::ostream & operator << (std::ostream &stream, User &w) { //�������������� ��������� ��� ���������
	   stream << "Name: '" << w.name << "'\nCount of works - " << w.count_works << "\n";
	   return stream;
   }

   User & operator = (User &w) { //�������������� ��������� ���������
	   this->name = w.name;
	   this->count_works = w.count_works;
	   this->works = w.works;
   }

protected:
private:
   std::string name; //��� �����������
   int count_works; //ʳ������ ����
   std::string works; //������
   Work *work;
};

#endif