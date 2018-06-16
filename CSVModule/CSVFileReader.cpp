#include "CSVFileReader.hpp"

#include <iostream>
#include <sstream>

CSVFileReader::CSVFileReader(void)
	: separator_(',')
{
}

CSVFileReader::~CSVFileReader(void)
{
}

bool CSVFileReader::open(const std::string & filepath)
{
	ifs_.open(filepath, std::ios::in);

	if (!ifs_.is_open()) {
		return false;
	}
	initialize();
	tokenize();
	return true;
}

CSVFileReader & CSVFileReader::operator>>(char & out)
{
	if (!tokens_.empty()) {
		std::istringstream iss(tokens_.front());
		iss >> out;
		tokens_.pop();
	}
	return *this;
}

CSVFileReader & CSVFileReader::operator>>(std::string & out)
{
	if (!tokens_.empty()) {
		out = tokens_.front();
		tokens_.pop();
	}
	return *this;
}

CSVFileReader & CSVFileReader::operator>>(int & out)
{
	if (!tokens_.empty()) {
		std::istringstream iss(tokens_.front());
		iss >> out;
		tokens_.pop();
	}
	return *this;
}

CSVFileReader & CSVFileReader::operator>>(float & out)
{
	if (!tokens_.empty()) {
		std::istringstream iss(tokens_.front());
		iss >> out;
		tokens_.pop();
	}
	return *this;
}

CSVFileReader & CSVFileReader::operator>>(double & out)
{
	if (!tokens_.empty()) {
		std::istringstream iss(tokens_.front());
		iss >> out;
		tokens_.pop();
	}
	return *this;
}

void CSVFileReader::initialize(void)
{
	std::string line;
	std::string sep = "sep=";
	size_t idx = std::string::npos;
	
	std::getline(ifs_, line);
	
	idx = line.find(sep);
	if (idx != std::string::npos) {
		separator_ = line.substr(idx + sep.size(), 1).at(0);
	}
}

void CSVFileReader::tokenize(void)
{
	std::string token;

	while (std::getline(ifs_, token, separator_))
	{
		std::stringstream ss(token);
		std::string buffer;
		while (std::getline(ss, buffer)) {
			tokens_.push(buffer);
		}
	}
}