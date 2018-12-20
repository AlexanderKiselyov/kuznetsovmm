#include "Tree.h"


void Tree::AddRecursive(shared_ptr<Directory>& currentFolder, shared_ptr<File>& file, size_t counter) {
	//если дошли до последнего уровня вложенности
	if (counter == this->depth|| file->params[counter] == "") {
		//создаём файл в текущей папке 		
		currentFolder->Add(file);
		return;
	}
	for (size_t i = 0; i < currentFolder->dirs.size(); i++) {
		//проверяем, есть ли папка с таким названием
		if ((*file).params[counter] == currentFolder->dirs[i]->name) {
			//переходим внутрь папки, если нашли папку с необходимым названием
			AddRecursive(currentFolder->dirs[i],file, counter + 1);
			return;
		}
	}
	//если папка с необходимым нзванием не найдена, то создаём папку
	shared_ptr<Directory> newDir(new Directory(currentFolder->path + '\\' +(*file).params[counter]));
	//добавляем её в вектор папок текущей директории
	currentFolder->Add(newDir);
	//переходим в только что созданную папку 
	AddRecursive(currentFolder->dirs[currentFolder->dirs.size() - 1],file, counter + 1);

	return;

}
void Tree::CreateRecursive(shared_ptr<Directory>& currentDir) {
	//создаём папку currentDir в файлововй системе Windows
	CreateDirectory(currentDir->path.c_str(), NULL);
	
	//создаём файлы, которые содержаться в currentDir
	for (size_t i = 0; i < currentDir->files.size(); i++)
		rename((currentDir->files[i]->path).c_str(), (currentDir->path +'\\'+ currentDir->files[i]->name).c_str());
	
	//рекурсивно создаём папки, содержащиеся в currentDir
	for (size_t i = 0; i < currentDir->dirs.size(); i++)
		CreateRecursive(currentDir->dirs[i]);
		
	
	return;
}

