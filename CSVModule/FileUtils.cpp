#include "FileUtils.hpp"

bool FileUtils::Exist(const std::string & path)
{
	std::ifstream ifs;

	ifs.open(path, std::ios::in);
	return ifs.is_open();
}
