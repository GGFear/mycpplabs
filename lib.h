#include <iostream>
#include <string>
#include <stdlib.h>
#include "User.h"
#include "Editor.h"
#include "Work.h"
#include "BD.h"
#include "Archive.h"
#include "Superuser.h"
#include "exceptions.h"

using namespace std;

string description() {
	setlocale(LC_CTYPE, "Russian");
	string text = "Project is designed by Duda Volodimir\ngroup IS-73\nShort description:\n<<<����������� ��������� �i��i���� ���i������ �������� � ������������� �������>>>\n������� �i�� � ���������� i�������ii ��� ������������� ������������ �� ���i������� ��� �������i� �����i��.\n����� ���������� �� ����� �������������� � ��(��������� �i��i�����), ��������(����������/��������) ����\ni�������i� �� ����������� i�������i� �i� i���� ����������i�(� ���� ����i �������� ��i���). ���i ��������\n(�i��i� ��������i�) ������� ����������� �����i/������i ������ �� ���i������ �� ����i����, �� �i, �� ��������� \n�� ����������� �����������. ����� �������� �� ����� �� ��i�� ���i� ������i���. � �i��i ������ ����� ��\n����������� ������i���i� �� ���������� �� ������ ��(���� ������). �� �� �������� �����, ��� \ni�������i� ������� ����i������ � ��� ������ i�������i���� ���i���(���i��i ������� i�������i�, ��i ����������i\n�� ������ ��i��). ��� i�������i� ������� �����i������ �� �i������������ � �������\n��������� �������i.\n";
	return text;
}
