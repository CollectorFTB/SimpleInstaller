#pragma once
#include <Windows.h>
#include <iostream>

class CopyFileError : public std::runtime_error {
public:
	std::wstring mFilePath;
	CopyFileError(std::wstring filePath) : std::runtime_error("") { mFilePath = filePath; }
};


class CreateDirectoryError : public std::runtime_error {
public:
	std::wstring mDirectoryName;
	CreateDirectoryError(std::wstring directoryName) : std::runtime_error("") { mDirectoryName = directoryName; }
};
