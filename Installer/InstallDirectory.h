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
	std::wstring mTargetDirectory;
	BOOL mExistsBeforeInstallation = FALSE;
	std::shared_ptr<BOOL> mCompleted;
	
public:
	const std::wstring getName(void) const;
	void createDirectory(void);
	InstallDirectory(std::wstring path, std::shared_ptr<BOOL> completed);
	~InstallDirectory(void);
};

