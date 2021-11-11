#pragma once
#include "List.h"
#include <fstream>

class FileManager :  public List{
private:
	fstream file;
public:
	FileManager();
	~FileManager();

	void SaveToFile(List&);
	List& ReadFromFile(List&);
};

