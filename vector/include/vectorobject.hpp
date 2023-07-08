#ifndef VECTOR_OBJECT_H
#include <string>
#include <iostream>

class VectorObject {
	private:
		int ref;
		std::string name;
	public:
		VectorObject();
		VectorObject(int ref, std::string& name);
		VectorObject(int ref, const char *str);
		int getRef() const;
		std::string getName() const;
		friend std::ostream& operator << (std::ostream &os, const  VectorObject &);
};
#define VECTOR_OBJECT_H
#endif //VECTOR_OBJECT_H
