#pragma once

#include "IDOMParser.h"
#include <string>

class DOMParser 
{
public:
	DOMParser();
	virtual ~DOMParser();

	virtual std::string getTegName(const std::string&);

private:

};