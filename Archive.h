/***********************************************************************
 * Module:  Archive.h
 * Author:  Duda Volodimir
 * Modified: 2 ������� 2018 �. 0:44:16
 * Purpose: Declaration of the class Archive
 ***********************************************************************/

#if !defined(__ClassDiagram_1_Archive_h)
#define __ClassDiagram_1_Archive_h

class Archive
{
public:
	Archive(); //������ �����������
	Archive(Archive &nArchive); //�������� �����
	Archive(int count, int max_count); //�������� �����������
	~Archive(); //�����������
    void create_part(void); //��������� ����� ������
    void check_parts(void); //�������� ����� ������
	void SetDataParts(int data_parts_) { //������������ ������� ����� ������
		data_parts = data_parts_;
	}
	void SetMaxDataParts(int max_data_parts_) { //������������ ���� ������� ����� ������
		max_data_parts = max_data_parts_;
	}
	void SetLastDateOfCheck(int last_date_of_check_) { //������������ �������� ���� ��������
		last_date_of_check = last_date_of_check_;
	}
	int GetDataParts() { //��������� ������� ����� ������
		return data_parts;
	}
	int GetMaxDataParts() { //��������� ���� ������� ����� ������
		return max_data_parts;
	}
	int GetLastDateOfCheck() { //��������� �������� ���� ��������
		return last_date_of_check;
	}
protected:
private:
   int data_parts; //ʳ������ ����� ������
   int max_data_parts; //��� ������� ����� ������
   int last_date_of_check; //������� ���� �������� ������


};

#endif