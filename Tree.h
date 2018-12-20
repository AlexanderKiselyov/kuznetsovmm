#pragma once
#include "stdafx.h"
#include "Directory.h"
#include "File.h"


class Tree
{
	//глубина вложенности
	int depth;
	//корень дерева
	shared_ptr<Directory> root;
	//рекурсивное добавление файла в дерево 
	void AddRecursive(shared_ptr<Directory>&, shared_ptr<File>&, size_t);
	//рекурсивное создание дерева в файловой системе Windows
	void CreateRecursive(shared_ptr<Directory>&);
public:
	
	Tree(shared_ptr<Directory>& dir, size_t depthLevel): depth(depthLevel), root(dir) {}

	//добавление файла в дерево
	void AddFileToTheTree(shared_ptr<File>& file) {
		int counter = 0;
		AddRecursive(root, file, counter);
	}
	//добавление вектора файлов в дерево 
	void AddVectorOfFilesToTheTree(vector<shared_ptr<File>>& files) {
		for (size_t i = 0; i < files.size(); i++) AddFileToTheTree(files[i]);		
	}
	//создание дерева каталогов в файловой системе Windows
	void CreateTheTreeInWindows() {
		CreateRecursive(root);
	}
	
};

