#include "File.h"

#include <iomanip>

//DO NOT MODIFY START
File::~File() = default;

Entry* File::clone() const
{
    return new File(*this);
}
//DO NOT MODIFY END

//Implement constructor, member functions in File class
//write your code here
//...
File::File(const std::string & name, const std::string & content)
	:name_(name), text_(content)
{}
File::File(const File & o)
	: name_(o.name_), text_(o.text_)
{}
const std::string& File::name() const {
	//this function returns the name of the current file
	return this->name_;
}
void File::print(std::ostream & os, size_t indent) const {
	//this functions prints the name of the current file
	indent += 2;
	for (int i = 0; i < indent; i++) {
		std::cout << " ";
	}
	std::cout << "* ";
	std::cout << this->name() << std::endl;
}
std::string File::content() const {
	//this function returns the content of the current file
	return this->text_;
}

std::string File::content(const std::string & text) {
	//this function updates the content of the current file.
	//it returns the result of the content update such as "Content updated!"
	//if (text_ != "") std::cout << "Content updated!\n";
	return this->text_ = text;
}