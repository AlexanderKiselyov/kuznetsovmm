#pragma once
#include <string>
class IComponent {
	virtual std::string GetNameFromPath() = 0;
public:
	std::string name;
	std::string path;
	virtual bool isFile() const = 0;
	
};