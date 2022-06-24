#include "InstallFile.h"

void InstallFile::install(void)
{
	BOOL copyFileReturnCode = CopyFile(mSourcePath.c_str(), mDestinationPath.c_str(), !FAIL_IF_EXISTS);

	if (COPY_FAIL == copyFileReturnCode)
	{
		throw CopyFileError(mSourcePath);
	}
	this->mInstalled = TRUE;
}

void InstallFile::uninstall(void) {
	BOOL deleteFileReturnCode = TRUE;
	deleteFileReturnCode = DeleteFile(this->mDestinationPath.c_str());
	if (FALSE == deleteFileReturnCode) // FIXES 3
	{
		std::wcout << L"Failed deleting file " << this->mDestinationPath << std::endl;
	}
	this->mInstalled = FALSE;
}
