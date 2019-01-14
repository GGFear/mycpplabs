/***********************************************************************
 * Module:  Editor.h
 * Author:  Duda Volodimir
 * Modified: 2 ������� 2018 �. 0:29:58
 * Purpose: Declaration of the class Editor
 ***********************************************************************/

#if !defined(__ClassDiagram_1_Editor_h)
#define __ClassDiagram_1_Editor_h

class Work;

class Editor
{
public:
	Editor(); //������ ����������� 
	Editor(Editor &nEditor); //��������� �����
	Editor(std::string name, int reg_day); //�������� �����������
	~Editor(); //����������
   std::string show_temp(void); //��������� �������� ������
   void edit_temp(void); //³����������� �������� ������
   void del_temp(void); //��������� ���������� ����
   void send_to_user(void); //³���������� ����� ����������� �� ��������
   void save_from_temp(void); //���������� � ��������� ����� �� ������
   void SetName(std::string name_) { //���������� ���
	   name = name_;
   }
   std::string GetName() { //����� ���
	   return name;
   }
   friend std::istream & operator >> (std::istream &stream, Editor &w) { //�������������� ��������� ��� ��������
	   std::cout << "Name: ";
	   stream >> w.name;
	   return stream;
   }

   friend std::ostream & operator << (std::ostream &stream, Editor &w) { //�������������� ��������� ��� ���������
	   stream << "Name: '" << w.name << "'\n";
	   return stream;
   }

   Editor & operator = (Editor &w) { //�������������� ��������� ���������
	   this->name = w.name;
   }

protected:
private:
   std::string name; //��� ���������
   Work *work;
};

#endif