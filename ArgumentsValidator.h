#pragma once
#include "stdafx.h"
#include "GlobalData.h"


namespace fs = std::experimental::filesystem;

class ArgumentsValidator
{		
	ArgumentsValidator() = default;
	~ArgumentsValidator() = default;
	
	//�������� �� ������������ ��������� ���� �������� (���������� �� ������ �������)
	static bool CheckPath(string path); 

	/*�������� �� ������������ ���������
	 *(����� ��������� ��������, ����� ������������ ����� ����� 1 ���� ���� � ��� �� �������� ��� �������������)*/
	static bool Unique(string param);
public:

	//�������� �� ������������ ����������, �������� �������������
	static bool CheckAndSetArgs(size_t size, char ** args); 
};

