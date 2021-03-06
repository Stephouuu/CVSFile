#include <string>
#include <iostream>
#include <fstream>

#include "CSVFileWriter.hpp"
#include "CSVFileReader.hpp"

int testWrite(void)
{
	CSVFileWriter csvFile;

	if (!csvFile.open("test.csv", false)) {
		return 1;
	}
	csvFile << "tes1" << CSVFileWriter::endl
		<< "tes2" << "test3" << CSVFileWriter::endl
		<< 1 << 2 << 3 << CSVFileWriter::endl
		<< 3.1415f << 2.001f;
	return 0;
}

int testRead(void)
{
	CSVFileReader csvFile;

	if (!csvFile.open("test.csv")) {
		return 1;
	}
	std::string tes1, tes2, tes3;
	int n1, n2, n3;
	float f1;
	csvFile >> tes1 >> tes2 >> tes3;
	csvFile >> n1 >> n2 >> n3;
	csvFile >> f1;

	std::clog << "out: " << tes1 << " " << tes2 << " " << tes3 << std::endl;
	std::clog << "oun: " << n1 << " " << n2 << " " << n3 << std::endl;
	std::clog << "lol:" << f1 << std::endl;
	system("pause");
	return 0;
}

int main()
{
    return testRead();
}

