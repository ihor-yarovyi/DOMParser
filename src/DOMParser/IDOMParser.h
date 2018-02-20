#pragma once
#include <string>

class IDOMParser
{
public:
	IDOMParser() {}
	virtual ~IDOMParser() {}

	virtual std::string getTegName(const std::string&) = 0;

private:

};