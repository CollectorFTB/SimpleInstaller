#pragma once
#include <Windows.h>
#include <iostream>

class CopyFileError : public std::runtime_error {
public:
	WCHAR mFilePath[MAX_PATH];
	CopyFileError(WCHAR filePath[MAX_PATH]) : std::runtime_error("") { wcscpy_s(mFilePath, filePath); }
};


class CreateDirectoryError : public std::runtime_error {
public:
	WCHAR mDirectoryName[MAX_PATH];
	CreateDirectoryError(WCHAR directoryName[MAX_PATH]) : std::runtime_error("") { wcscpy_s(mDirectoryName, directoryName); }
};
