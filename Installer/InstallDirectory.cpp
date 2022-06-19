#include "InstallDirectory.h"

LPCWSTR const InstallDirectory::getName(void) const
{
	return this->mTargetDirectory;
}

InstallDirectory::InstallDirectory(LPCWSTR path, std::shared_ptr<BOOL> completed): mCompleted(completed)
{
	BOOL createDirectoryReturnCode = TRUE;
	wcscpy_s(mTargetDirectory, path);
	this->mExistsBeforeInstallation = PathFileExists(mTargetDirectory);
	
	if (!this->mExistsBeforeInstallation) {
		createDirectoryReturnCode = CreateDirectory(mTargetDirectory, INHERIT_SECURITY);
		if (CREATE_DIRECTORY_FAIL == createDirectoryReturnCode) { // If an error happenned which wasn't "File exists"
			throw CreateDirectoryError(mTargetDirectory);
		}
	}
}

InstallDirectory::~InstallDirectory(void)
{
	if (!*this->mCompleted) {
		// Delete the directory if it didnt exist before the installation and it exists right now
		if (!this->mExistsBeforeInstallation && PathFileExists(mTargetDirectory)) {
			RemoveDirectory(mTargetDirectory);
		}
	}
}
