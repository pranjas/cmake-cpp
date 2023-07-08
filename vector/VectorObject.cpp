#include "vectorobject.hpp"

VectorObject::VectorObject():ref(0), name("undefined"){
}
VectorObject::VectorObject(int ref, std::string& name) {
	this->ref = ref;
	this->name = name;
}
VectorObject::VectorObject(int ref, const char *str) {
	this->ref = ref;
	this->name = std::string(str);
}

int VectorObject::getRef() const {
	return ref;
}

std::string VectorObject::getName() const {
	return name;
}

std::ostream& operator << (std::ostream& os , const VectorObject &obj) {
	os<<"Refcount = "<< obj.getRef()
	  <<" Name = "<< obj.getName()
	  <<"\n";

	return os;
}


