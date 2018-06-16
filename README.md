# CVSFile

Light CVS file format handler wrote in C++.

## How to use it

### Read a CVS file

Assuming we are using the following .csv file ...

```csv
test1
46,3.1415
```
... Let's read these data in C++ :
```c++

CSVFileReader csvFile;

if (!csvFile.open("test.csv")) {
	// handle error here
	return;
}

std::string tes1;
int n1;
float f1;

csvFile >> tes1 >> test2;
csvFile >> tes3;

std::clog << tes1 << " " << n1 << " " << f1 << std::endl;
```

The output will be :
```
test1 46 3.1415
```

### Write a CVS file

comming soon ...
