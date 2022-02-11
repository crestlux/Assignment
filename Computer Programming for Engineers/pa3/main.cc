#include "Entry.h"
#include "Directory.h"
#include "File.h"

#include <sstream>
#include <string>

//This function finds directory with the given name(2nd argument) from the given path(1st argument)
//For example below finds "world" directory from the root directory
//find_directory(&root, "world");
Entry* find_directory(Directory* root, const std::string& path)
{
    //Implement your code here.
    //Leverage find member function.
    //...
    return root->find(path);
}

std::string path_src, pathsrc[300], pathdest[300], content, tmp;
int pathcnt_src = 0, pathcnt_dest = 0;

Directory* dir(Directory* &cur, const int &depth, bool ifsrc) {
	if ((ifsrc == true && pathsrc[0] != "root") || (ifsrc == false && pathdest[0] != "root")) {
		std::cout << "no such directory\n";
		return 0;
	}
	for (int i = 1; i < depth; i++) {
		if(ifsrc == true)cur = dynamic_cast<Directory*>(find_directory(cur, pathsrc[i]));
		else cur = dynamic_cast<Directory*>(find_directory(cur, pathdest[i]));
		if (cur == 0) {
			std::cout << "no such directory\n";
			return 0;
		}
	}
	return cur;
}

void exec_cmd(Directory* root,std::string cmd)
{
  //*****Do NOT MODIFY START*****
  std::istringstream iss1(cmd),iss2(cmd);
  std::string token;
  std::getline(iss2,token,' ');
  std::getline(iss1,token,' ');
  //*****DO NOT MODIFY END*****

  //Implement your code here
  //...
	content.clear();
	tmp.clear();
  path_src.clear();
  for(int i = 0; i < 300; i++){
    pathsrc[i].clear();
    pathdest[i].clear();
  }
	pathcnt_src = 0;
	pathcnt_dest = 0;
	iss1 >> path_src;
	std::istringstream iss(path_src);
	while (std::getline(iss, pathsrc[pathcnt_src], '/')) {
		++pathcnt_src;
	}

	
	Directory* cur = root;

	if (token == "mkdir") {
		cur = dir(cur, pathcnt_src - 1, true);
		if (cur == 0) return;
		if (cur->find(pathsrc[pathcnt_src - 1])) {
			std::cout << "directory already exists\n";
			return;
		}
		cur->add(new Directory(pathsrc[pathcnt_src - 1]));
	}

	else if (token == "touch") {
		while (iss1 >> tmp) {
			content += tmp + " ";
		}
		File temp(pathsrc[pathcnt_src - 1], content);
		File* dest(&temp);
		cur = dir(cur, pathcnt_src - 1, true);
		if (cur == 0) return;
		if (find_directory(cur, pathsrc[pathcnt_src - 1]) == 0) {
			cur->add(new File(temp));
			return;
		}
		else {
			std::cout << "file already exists\n";
			return;
		}
	}

	else if (token == "echo") {
		while (iss1 >> tmp) {
			content += tmp + " ";
		}
		File temp(pathsrc[pathcnt_src - 1], content);
		File* dest(&temp);
		cur = dir(cur, pathcnt_src - 1, true);
		if (cur == 0) return;
		if (find_directory(cur, pathsrc[pathcnt_src - 1]) == 0) {
			cur->add(new File(temp));
			return;
		}
		dest = dynamic_cast<File*>(find_directory(cur, pathsrc[pathcnt_src - 1]));
		if (dest == 0) return;
		dest->content(content);
		std::cout << "Content updated!\n";
	}


	else if (token == "ls") {
		cur = dir(cur, pathcnt_src, true);
		if (cur == 0) return;
		std::cout << (cur)->content();
	}

	else if (token == "tree") {
		cur = dir(cur, pathcnt_src, true);
		if (cur == 0) return;
		std::cout << *cur << "\n";
	}

	else if (token == "cat") {
		File* dest;
		cur = dir(cur, pathcnt_src - 1, true);
		if (cur == 0) return;
		if (cur->find(pathsrc[pathcnt_src - 1]) == 0) {
			std::cout << "no such file\n";
			return;
		}
		dest = dynamic_cast<File*>(cur->find(pathsrc[pathcnt_src - 1]));
		if (dest == 0) {
			std::cout << "no such file\n";
			return;
		}
		std::cout << dynamic_cast<Entry*>(dest)->content() << "\n";
	}


	else if (token == "mv") {
		iss1 >> path_src;
		std::istringstream iss(path_src);
		while (std::getline(iss, pathdest[pathcnt_dest], '/')) {
			++pathcnt_dest;
		}
		Entry* cpsrc;
		cur = dir(cur, pathcnt_src, true);
		if (cur == 0) return;
		cpsrc = cur->clone();
		cur = root;
		cur = dir(cur, pathcnt_src-1, true);
		if (cur == 0) return;
		cur->remove(cpsrc->name());
		cur = root;
		cur = dir(cur, pathcnt_dest, false);
		if (cur == 0) return;
		cur->add(cpsrc);
	}

	else if (token == "cp") {
		iss1 >> path_src;
		std::istringstream iss(path_src);
		while (std::getline(iss, pathdest[pathcnt_dest], '/')) {
			++pathcnt_dest;
		}
		Entry* cpsrc;
		cur = dir(cur, pathcnt_src, true);
		if (cur == 0) return;
		cpsrc = cur->clone();
		cur = root;
		cur = dir(cur, pathcnt_dest, false);
		if (cur == 0) return;
		cur->add(cpsrc);
	}

	else if (token == "rmdir") {
		cur = dir(cur, pathcnt_src - 1, true);
		if (cur == 0) return;
		if (dynamic_cast<Directory*>(cur) == 0) {
			std::cout << "no such directory\n";
			return;
		}
		cur->remove(pathsrc[pathcnt_src - 1]);
	}
	else if (token == "rm") {
		cur = dir(cur, pathcnt_src - 1, true);
		if (cur == 0) return;
		if (cur->find(pathsrc[pathcnt_src - 1]) == 0) {
			std::cout << "no such file\n";
			return;
		}
		if (dynamic_cast<File*>(cur) == 0) {
			std::cout << "no such file\n";
			return;
		}
		cur->remove(pathsrc[pathcnt_src - 1]);
	}
	else {
		std::cout << "Command not found" << std::endl;
		return;
	}
}

int main()
{
  //*****Do NOT MODIFY START*****
    Directory root("root");
    root.add(new Directory("hello"));
    std::cout << root << std::endl; //this prints all the directories and files in root directory. (the result of tree command)

    std::string inputBuffer;
    while(1){
      std::getline(std::cin,inputBuffer);
      if(inputBuffer.compare("quit")==0) break;
      exec_cmd(&root,inputBuffer);
    }
  //*****DO NOT MODIFY END*****

}
