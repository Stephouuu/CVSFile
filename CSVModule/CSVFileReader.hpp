#pragma once

#include <string>
#include <fstream>
#include <queue>

class CSVFileReader
{
public:
	CSVFileReader(void);
	~CSVFileReader(void);

	bool open(const std::string & filepath);
	
	CSVFileReader & operator>>(char & out);
	CSVFileReader & operator>>(std::string & out);
	CSVFileReader & operator>>(int & out);
	CSVFileReader & operator>>(float & out);
	CSVFileReader & operator>>(double & out);

private:
	void initialize(void);
	void tokenize(void);

private:
	std::ifstream ifs_;
	char separator_;

	std::queue<std::string> tokens_;
};

