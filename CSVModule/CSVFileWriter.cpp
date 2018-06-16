#include "CSVFileWriter.hpp"

#include <iostream>

#include "FileUtils.hpp"

const char CSVFileWriter::endl = '\n';
const char CSVFileWriter::separator = ',';

CSVFileWriter::CSVFileWriter(void)
	: newLine_(false)
{
}

CSVFileWriter::~CSVFileWriter(void)
{
}

bool CSVFileWriter::open(const std::string & filepath, bool reset)
{
	bool exist = FileUtils::Exist(filepath);
	
	if (reset) {
		ofs_.open(filepath, std::ios::out);
	}
	else {
		ofs_.open(filepath, std::ios::out | std::ios::app);
	}

	if (!ofs_.is_open()) {
		return false;
	}

	initialize(exist, reset);
	return true;
}

CSVFileWriter & CSVFileWriter::operator<<(char in)
{
	if (in == CSVFileWriter::endl) {
		newLine_ = true;
	}
	else if (in != CSVFileWriter::separator) {
		manageNewline();
	}

	ofs_ << in << std::flush;
	return *this;
}

CSVFileWriter & CSVFileWriter::operator<<(const std::string & in)
{
	manageNewline();
	ofs_ << in << std::flush;
	return *this;
}

CSVFileWriter & CSVFileWriter::operator<<(int in)
{
	manageNewline();
	ofs_ << in << std::flush;
	return *this;
}

CSVFileWriter & CSVFileWriter::operator<<(float in)
{
	manageNewline();
	ofs_ << in << std::flush;
	return *this;
}

CSVFileWriter & CSVFileWriter::operator<<(double in)
{
	manageNewline();
	ofs_ << in << std::flush;
	return *this;
}

void CSVFileWriter::initialize(bool exist, bool reset)
{
	newLine_ = true;
	if (!exist || reset) {
		*this << "sep=" << CSVFileWriter::separator;
	}
	*this << CSVFileWriter::endl;
}

void CSVFileWriter::manageNewline(void)
{
	if (!newLine_) {
		ofs_ << CSVFileWriter::separator;
	}
	newLine_ = false;
}