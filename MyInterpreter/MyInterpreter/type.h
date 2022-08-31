#ifndef TYPE_H
#define TYPE_H
#include "Helper.h"
#include <string>

class Type
{
public:
	Type();

	bool getIsTemp();
	void setIsTemp(bool temp);

	virtual void addValue(Type* type) = 0;
	virtual std::string getType() = 0;
	virtual const bool isPrintable() = 0;
	virtual const std::string toString() = 0;
private:
	bool _isTemp;
};





#endif //TYPE_H
