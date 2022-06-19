#pragma once
#include <Windows.h>
#include <Shlwapi.h>
#include <memory>

#include "Exceptions.h"

const LPSECURITY_ATTRIBUTES INHERIT_SECURITY = NULL;
const BOOL CREATE_DIRECTORY_FAIL = 0;

class InstallDirectory
{
private:
	WCHAR mTargetDirectory[MAX_PATH];
	BOOL mExistsBeforeInstallation = FALSE;
	
public:
	std::shared_ptr<BOOL> mCompleted;

	LPCWSTR const getName(void) const;
	InstallDirectory(LPCWSTR path, std::shared_ptr<BOOL> completed);
	~InstallDirectory(void);
};

