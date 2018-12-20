#pragma once
#include "stdafx.h"
#include "GlobalData.h"


namespace fs = std::experimental::filesystem;

class ArgumentsValidator
{		
	ArgumentsValidator() = default;
	~ArgumentsValidator() = default;
	
	//проверка на корректность введённого пути каталога (существует ли данный каталог)
	static bool CheckPath(string path); 

	/*проверка на уникальность параметра
	 *(чтобы исключить ситуацию, когда пользователь введёт более 1 раза один и тот же параметр для каталогизации)*/
	static bool Unique(string param);
public:

	//проверка на корректность параметров, введённых пользователем
	static bool CheckAndSetArgs(size_t size, char ** args); 
};

