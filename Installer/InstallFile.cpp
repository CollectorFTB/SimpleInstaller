#include "InstallFile.h"

void InstallFile::copyFile(void)
{
	BOOL copyFileReturnCode = CopyFile(mSourcePath, mDestinationPath, !FAIL_IF_EXISTS);

	if (COPY_FAIL == copyFileReturnCode)
	{
		throw CopyFileError(mSourcePath);
	}
}

InstallFile::InstallFile(LPCWSTR sourcePath, LPCWSTR destinationPath, std::shared_ptr<BOOL> completed): mCompleted(completed)
{
	wcscpy_s(mDestinationPath, destinationPath);
	wcscpy_s(mSourcePath, sourcePath);
	this->copyFile();
}


InstallFile::~InstallFile(void)
{
	if (!*this->mCompleted) {
		DeleteFile(mDestinationPath);
	}
}
