#include "InstallDirectory.h"

std::wstring const InstallDirectory::getName(void) const
{
	return this->mTargetDirectory;
}

void InstallDirectory::createDirectory(void) {
	BOOL createDirectoryReturnCode = TRUE;
	this->mExistsBeforeInstallation = PathFileExists(mTargetDirectory.c_str());

	if (!this->mExistsBeforeInstallation) {
		createDirectoryReturnCode = CreateDirectory(mTargetDirectory.c_str(), INHERIT_SECURITY);
		if (CREATE_DIRECTORY_FAIL == createDirectoryReturnCode) {
			throw CreateDirectoryError(mTargetDirectory);
		}
	}
}
InstallDirectory::InstallDirectory(std::wstring path, std::shared_ptr<BOOL> completed): mTargetDirectory(path), mCompleted(completed) {}

InstallDirectory::~InstallDirectory(void)
{
	if (!*this->mCompleted && !this->mExistsBeforeInstallation) {
		RemoveDirectory(mTargetDirectory.c_str());
	}
}
