#pragma once

#include <string>
#include <fstream>

class CSVFileWriter // : public ACSVFile
{
public:
	static const char endl;
	static const char separator;

public:
	CSVFileWriter(void);
	~CSVFileWriter(void);

	bool open(const std::string & filepath, bool reset = false);

	CSVFileWriter & operator<<(char in);
	CSVFileWriter & operator<<(const std::string & in);
	CSVFileWriter & operator<<(int in);
	CSVFileWriter & operator<<(float in);
	CSVFileWriter & operator<<(double in);

private:
	void initialize(bool exist, bool reset);
	void manageNewline(void);

private:
	std::ofstream ofs_;
	bool newLine_;
};
