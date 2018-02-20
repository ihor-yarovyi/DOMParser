#include "DOMParser.h"

DOMParser::DOMParser()
{

}

DOMParser::~DOMParser()
{

}

std::string DOMParser::getTegName(const std::string& str)
{
	size_t position = str.find_first_of(' ');
	
	if (position == std::string::npos)
	{
		return str;
	}
	else
	{
		return std::string(str.begin(), str.begin() + position);
	}
	return {};
}