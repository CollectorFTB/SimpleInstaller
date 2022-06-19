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
	std::wstring mSourcePath;
	std::wstring mDestinationPath;
	std::shared_ptr<BOOL> mCompleted;

public:
	void install(void);

	InstallFile(std::wstring sourcePath, std::wstring destinationPath, std::shared_ptr<BOOL> completed);
	~InstallFile(void);
};

