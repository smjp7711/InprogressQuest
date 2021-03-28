#ifndef LIBRARY_H
#define LIBRARY_H


#include <string>
#include <map>
#include <memory>

class Texture;
class ObjectFactory;
class Library {
public:
	Library();
	~Library();

	std::map<std::string, std::unique_ptr<ObjectFactory>> library;
	std::map<std::string, std::shared_ptr<Texture>> artLibrary;
}; 
#endif // !LIBRARY_H