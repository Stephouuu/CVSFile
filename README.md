# OpenLightCSV

A light easy-to-use CSV file format handler for C++ applications.

## Installation

Just copy/paste the class' in your project.

## How to use it

### Read a CSV file

Assuming we are using the following .csv file :

```csv
test1
46,3.1415
```
Let's read this file with our CSVFileReader class :
```c++
#include <iostream>
#include <string>
#include "CSVFileReader.hpp"

int main(void)
{
	CSVFileReader csvFile;

	if (!csvFile.open("test.csv")) {
		// handle error here
		return;
	}

	std::string test1;
	int n1;
	float f1;

	csvFile >> test1 >> n1;
	csvFile >> f1;

	std::clog << test1 << " " << n1 << " " << f1 << std::endl;
	return 0;
}
```

The program's output will be :
```
test1 46 3.1415
```

### Write a CSV file

```c++
#include <iostream>
#include <string>
#include "CSVFileWriter.hpp"

int main(void)
{
	CSVFileWriter csvFile;
	// Pass 'true' in the second argument to open() if you want to override the file.
	// If you want to app to the end of the file, omit this argument (default value is false).
	if (!csvFile.open("test.csv", true)) { 
		// handle error here
		return ;
	}
	csvFile << "tes1" << CSVFileWriter::endl
		<< "tes2" << "test3" << CSVFileWriter::endl
		<< 1 << 2 << 3 << CSVFileWriter::endl
		<< 3.1415f << 2.001f;
	return 0;
}
```
The csv file 'test.csv' now contains
```csv
tes1
tes2,tes3
1,2,3
3.1415,2.001
```


