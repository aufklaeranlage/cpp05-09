#include "Data.hpp"

Data::Data(void):
	version("default"), info("Default Data Container") {  
	
}

Data::Data(const std::string &version, const std::string &info):
	version(version), info(info) {
	
}

Data::Data(const Data &other) {
	*this = other;
}

Data::~Data(void) {

}

Data &Data::operator=(const Data &other) {
	if (this == &other)
		return (*this);
	version = other.version;
	info = other.info;
	return (*this);
}
