#pragma once
#include "stdafx.h"
#include "GlobalData.h"
#include "IComponent.h"
#include <taglib/tag.h>
#include <taglib/fileref.h>
using namespace std;
class File : public IComponent
{
	
	
	string GetNameFromPath() {
		return path.substr(path.find_last_of('\\') + 1);
	}
	string GetExtensionFromPath() {	
		return path.substr(path.find_last_of('.') + 1);
	}
	void SetParams() {
		GlobalData& gb = GlobalData::getObject();
		TagLib::FileRef f(path.c_str());
		this->params = new string[gb.numberOfParams];
		for (size_t i = 0; i < gb.numberOfParams; i++)
		{
			if (gb.params[i] == "artist") {
				this->params[i] = f.tag()->artist().toCString();
				continue;
			}
			if (gb.params[i] == "album") {
				this->params[i] = f.tag()->album().toCString();
				continue;
			}
			if (gb.params[i] == "year") {
				this->params[i] = "" + f.tag()->year();
				continue;
			}
			if (gb.params[i] == "genre") {
				this->params[i] = f.tag()->genre().toCString();
				continue;
			}
		}		
	}
	string extension;
public:

	//в параметры входит имя исполнителя, название альбома
	//при необходимости можно указать больше параметров для каталогизации (например год выпуска и т.п.)
	string* params;
	
	File();

	File(string path){
		this->path = path;
		name = GetNameFromPath();
		extension = GetExtensionFromPath();		
		SetParams();
	}
	bool IComponent::isFile() const { return true; }

	
	
	string GetArtistName() { return 0; }
	string GetAlbumName() { return 0; }
	

	~File() { 
		delete[] params; 
	};
};

