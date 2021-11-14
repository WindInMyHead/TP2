#pragma once
#include "List.h"
#include <fstream>

class FileManager :  public List{
private:
	fstream file;
public:
	FileManager();
	~FileManager();

	void Save(List&);
	List& Read(List&);
};

