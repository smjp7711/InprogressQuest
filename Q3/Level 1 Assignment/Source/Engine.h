#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include "Library.h"
#include "ObjectFactory.h"
#include "Object.h"

class Engine {
public:
	Engine(std::string levelPath);
	void loadLevel(std::string levelPath);
	bool run();	
private:
	void update();
	void draw();
	void reset();
	std::unique_ptr<Library> objectLibrary{ nullptr };
	std::vector<std::unique_ptr<Object>> objects;	
};

#endif // !ENGINE_H

