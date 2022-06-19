#pragma once
#include <Windows.h>
#include <Shlwapi.h>
#include <iostream>
#include <memory>

#include "Exceptions.h"

const BOOL FAIL_IF_EXISTS = TRUE;
const BOOL COPY_FAIL = 0;

class InstallFile
{
private:
	WCHAR mSourcePath[MAX_PATH];
	WCHAR mDestinationPath[MAX_PATH];

public:
	std::shared_ptr<BOOL> mCompleted;

	void copyFile(void);
	InstallFile(LPCWSTR sourcePath, LPCWSTR destinationPath, std::shared_ptr<BOOL> completed);
	~InstallFile(void);
};

