#pragma once
#include <string>
//класс, который обощает понятие о файле и каталоге
class IComponent {
	//получение имени компонента по его пути в файловой системе Windows
	virtual std::string GetNameFromPath() = 0;
public:
	std::string name;
	std::string path;
	virtual bool isFile() const = 0;
	
};