#include "InstallFile.h"

void InstallFile::install(void)
{
	BOOL copyFileReturnCode = CopyFile(mSourcePath.c_str(), mDestinationPath.c_str(), !FAIL_IF_EXISTS);

	if (COPY_FAIL == copyFileReturnCode)
	{
		throw CopyFileError(mSourcePath);
	}
}

InstallFile::InstallFile(std::wstring sourcePath, std::wstring destinationPath, std::shared_ptr<BOOL> completed) : mDestinationPath(destinationPath), mSourcePath(sourcePath), mCompleted(completed) {}

InstallFile::~InstallFile(void)
{
	if (!*this->mCompleted) {
		DeleteFile(mDestinationPath.c_str());
	}
}
