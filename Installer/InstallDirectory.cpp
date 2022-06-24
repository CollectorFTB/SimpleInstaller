#include "InstallDirectory.h"

std::wstring const InstallDirectory::getName(void) const
{
	return this->mTargetDirectory;
}

void InstallDirectory::install(void) {
	BOOL createDirectoryReturnCode = TRUE;
	BOOL existsBeforeInstallation = PathFileExists(mTargetDirectory.c_str());

	if (!existsBeforeInstallation) {
		createDirectoryReturnCode = CreateDirectory(mTargetDirectory.c_str(), INHERIT_SECURITY);
		
		if (CREATE_DIRECTORY_FAIL == createDirectoryReturnCode) {
			throw CreateDirectoryError(mTargetDirectory);
		}
		else {
			/* FIXES 4 (semi got fixed when fixing 1 and moving mCompleted there):
			When installing an AbstractInstallable, by default it wont call uninstall() on the object if it didn't finish its installation
			In the case of a directory, if the directory didn't exist before we didn't install it, so don't need to uninstall it
			Only set this to TRUE if the directory creation succeeded

			*/
			this->mInstalled = TRUE;
		}
	}
}

void InstallDirectory::uninstall(void) {
	BOOL removeDirectoryReturnCode = TRUE;
	removeDirectoryReturnCode = RemoveDirectory(this->mTargetDirectory.c_str());
	if (FALSE == removeDirectoryReturnCode) // FIXES 3
	{
		std::wcout << L"Failed removing directory " << this->mTargetDirectory << std::endl;
	}
	this->mInstalled = FALSE;
}
