#pragma once
#include "stdafx.h"
#include "GlobalData.h"
#include "ArgumentsValidator.h"
#include "Directory.h"
#include "File.h"
#include "Tree.h"

using namespace std;

namespace fs = std::experimental::filesystem;



int main(size_t count, char ** args) {

	GlobalData& gb = GlobalData::getObject();
	//проверяем данные из входных аргументов и инициализируем статические переменные
	if (!ArgumentsValidator::CheckAndSetArgs(count, args)) {
		cout << "Error in input data" << endl;
		system("pause");
		return 0;
	}
	//вектор песен, содержащихся в исходной папке
	vector<shared_ptr<File>> songs;
	//заполнение вектора песен аудиофайлами с определёнными расширениями (у которых можно программно получить метаданные)
	for (const auto & entry : fs::directory_iterator(gb.SourceDirectory))
	{
		//std::cout << entry.path() << std::endl;
		string path = entry.path().string();
		string ext = entry.path().extension().string();
		if (ext == ".mp3" || 
			ext == ".wav" || 
			ext == ".aif" || 
			ext == ".mid" || 
			ext ==".flac")
			songs.push_back(shared_ptr<File>(new File(path)));
	}

	//создаём каталог, в котором будут хранится все остальные каталоги (корень дерева)
	shared_ptr<Directory> main(new Directory(gb.DistDirectory));
	
	//создаём дерево каталогов
	Tree * tree = new Tree(main, gb.numberOfParams);

	//добавление песен в дерево
	tree->AddVectorOfFilesToTheTree(songs);

	//создание дерева каталогов в файловой системе Windows
	tree->CreateTheTreeInWindows();

	system("pause");
	delete tree;
	return 0;
}