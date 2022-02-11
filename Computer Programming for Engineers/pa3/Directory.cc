#include "Directory.h"

#include <iomanip>
#include <sstream>

//DO NOT MODIFY THIS START
Entry* Directory::clone() const
{
    return new Directory(*this);
}
//DO NOT MODIFY THIS END

//Implement constructor, destructor, member functions of the Directory class.
//...
Directory::Directory(const std::string& name)
	:name_(name), count_(0), entries_()
{}
Directory::Directory(const Directory& o)
	: name_(o.name_), count_(o.count_)
{
	for (size_t i = 0; i < o.count_; i++) {
		entries_[i] = o.entries_[i]->clone();
	}
}
Directory::~Directory() {}
const std::string& Directory::name() const {
	//this function returns the name of the directory
	return this->name_;
}
void Directory::print(std::ostream& os, size_t indent) const {
	//this function prints directories and files in the current directory.
	static bool chk_recursive = false;
	if (chk_recursive == false) {
		std::cout << "* " << this->name_ << std::endl; 
	}
	for (size_t i = 0; i < count_; i++) {
		if (dynamic_cast<Directory*>(entries_[i])) {
			indent += print_indent_;
			for (size_t j = 0; j < indent; j++) {
				std::cout << " ";
			}
			std::cout << "* " << entries_[i]->name() << "\n";
		}
		chk_recursive = true;
		entries_[i]->print(os, indent);
		if (dynamic_cast<Directory*>(entries_[i])) indent -= print_indent_;
	}
	chk_recursive = false;
}

std::string Directory::content() const {
	//this function returns the content of the current directory. this is for "ls" command.
	//dir.content() : should returns directories and files in the "dir" directory
	std::string cont;
	for (size_t i = 0; i < count_; i++) {
		cont += (entries_[i])->name() + "\n";
	}
	return cont;
}

size_t Directory::count() const {
	//this function returns number of files and directories in the current directory
	return count_;
}

Entry* Directory::find(const std::string& name) {
	//this function find directory or file with the given name in the current directory and returns it.
	for (size_t i = 0; i < count_; i++) {
		if (entries_[i]->name() == name) return entries_[i];
	}
	return 0;
}

bool Directory::add(Entry* entry) {
	//this function creates a file or directory in the current directory.
	for (size_t i = 0; i < count_; i++) {
		if (entries_[i]->name() == entry->name()) return false;
	}
	entries_[count_] = entry;
	count_++;
	return true;
}
Entry* Directory::remove(const std::string& name) {
	//this function remove a file or directory in the current directory.
	int target = -1;
	for (size_t i = 0; i < count_; i++) {
		if (entries_[i]->name() == name) { 
			target = i;
			break;
		}
	}
	if (target != -1 && dynamic_cast<Directory*>(entries_[target])) {
		size_t cnt = dynamic_cast<Directory*>(entries_[target])->count_;
		if(cnt != 0) {
			for (size_t i = 0; i < cnt;) {
				if (dynamic_cast<Directory*>(entries_[target])->entries_[i] != 0) {
					dynamic_cast<Directory*>(entries_[target])->remove(dynamic_cast<Directory*>(entries_[target])->entries_[i]->name());
					cnt = dynamic_cast<Directory*>(entries_[target])->count_;
				}
				if(cnt==0) break;
			}
		}
	}
	if (target == -1) {
		std::cout << "no such file or directory\n";
		return 0;
	}
	else {
		for (size_t i = static_cast<size_t>(target); i < count_ - 1; i++) {
			entries_[i] = entries_[i + 1];
		}
	}
	entries_[count_ - 1] = 0;
	--count_;
	return *entries_;
}