/***********************************************************************
 * Module:  Work.h
 * Author:  Duda Volodimir
 * Modified: 2 ������� 2018 �. 0:36:59
 * Purpose: Declaration of the class Work
 ***********************************************************************/
#include <iostream>

#if !defined(__ClassDiagram_1_Work_h)
#define __ClassDiagram_1_Work_h

class BD;

class Work
{
public:
	Work(); //������ �����������
	Work(Work &nWork); //���������
	Work(int id, std::string name, std::string content, std::string title); //�������� �����������
	~Work(); //����������
   void edit(void); //����������� ������
   void del(void); //��������� ������
   void create(void); //��������� ���� ������
   void choose(void); //���� ������
   void load(void); //������������ ������
   void SetId(int id_) { //������������ id
	   id = id_;
   }
   void SetName(std::string name_) { //������������ ���� ������
	   name = name_;
   }
   void SetContent(std::string content_) { //������������ ��������
	   content = content_;
   }
   void SetTitle(int title_) { //������������ ���������
	   title = title_;
   }
   int GetId() { //����� id ������
	   return id;
   }
   std::string GetName() { //����� ��� ������
	   return name;
   }
   std::string GetTitle() { //����� ��������� ������
	   return name;
   }
   std::string GetContent() { //����� ������� ������
	   return content;
   }
   friend std::istream & operator >> (std::istream &stream, Work &w) { //�������������� ��������� ��� �����
	   std::cout << "Title: ";
	   stream >> w.title;
	   std::cout << "Author: ";
	   stream >> w.name;
	   std::cout << "Content: \n";
	   stream >> w.content;
	   return stream;
   }

   friend std::ostream & operator << (std::ostream &stream, Work &w) { //�������������� ��������� ��� �����
	   stream << "Title: '" << w.title << "'\nAuthor: '" << w.name << "'\n" << w.content << "\n";
	   return stream;
   }
   Work & operator + (Work &w) { //�������������� ���� ��� ���������� ���� � ����
	   Work new_w(this->id + w.id, this->name + " | " + w.name, this->title + " / " + w.name, this->content + "\n" + w.content);
	   return new_w;
   }

   Work & operator = (Work &w) { //�������������� ��������� ���������
	   this->id = w.id;
	   this->name = w.name;
	   this->title = w.title;
	   this->content = w.content;
   }

protected:
private:
   int id; //����� ������
   std::string name; //��� ������ ������
   std::string title; //��������� ������
   std::string content; //�������(����) ������
   BD* db; //�������� �� ���� �����
};

#endif