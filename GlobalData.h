#pragma once
#include <string>
using namespace std;

class GlobalData {
	
	GlobalData() = default;
	~GlobalData() = default;

	GlobalData& operator=(const GlobalData&) = delete;
	GlobalData(const GlobalData&) = delete;

public:
	//максимальное количество параметров для каталогизации
	const size_t MAX_NUMBER_OF_PARAMS = 4;
	//строковое представление параметров, введённых пользователем (PARAMETERS_IN_ORDER[0] - "artist")
	const string* PARAMETERS_IN_ORDER = new string[MAX_NUMBER_OF_PARAMS]{ "artist", "album", "year", "genre" };
	//количество параметров для каталогизации, введённых пользователем
	size_t numberOfParams;
	//массив параметров, введённых пользователем
	string* params;
	//путь к папке, где лежат аудиофайлы для каталогизации
	string SourceDirectory;
	//путь к папке, где необходимо создать дерево каталогов 
	string DistDirectory;

	static GlobalData& getObject() {
		static GlobalData a;
		return a;
	}
};
