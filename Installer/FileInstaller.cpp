#include "FileInstaller.h"

void FileInstaller::copyFiles(const std::vector<std::wstring>& sourceFiles)
{
    WCHAR targetFilePath[MAX_PATH];
    LPWSTR filename = nullptr;
    LPWSTR pathCombineResult = nullptr;

    for (auto it = sourceFiles.begin(); it != sourceFiles.end(); ++it) {
        // Create the path and put it into targetFilePath
        filename = PathFindFileName((*it).c_str());
        pathCombineResult = PathCombine(targetFilePath, mTargetDirectory->getName().c_str(), filename);
        if (NULL == pathCombineResult) {
            // TODO: throw if fails
        }

        auto file = std::make_unique<InstallFile>(*it, std::wstring(targetFilePath), this->mCompleted);
        file->install();
        this->mInstallFiles.push_back(std::move(file));
    }
}

void FileInstaller::install(const std::vector<std::wstring>& sourceFiles) {
    this->mTargetDirectory->install(); 
    this->copyFiles(sourceFiles);

    // If we reached here, installer finished successfully
    *this->mCompleted = TRUE;
}

FileInstaller::FileInstaller(std::wstring targetDirectory)
{
    // Shared pointer to keep track of whether the program finished successfully or not
    this->mCompleted = std::make_shared<BOOL>(FALSE);

    this->mTargetDirectory = std::make_unique<InstallDirectory>(targetDirectory, this->mCompleted);
}

FileInstaller::~FileInstaller(void)
{
    // FIXES 2: Ensure order of deletion, reverse the order of creation when uninstalling
    for (auto it = this->mInstallFiles.rbegin(); it != this->mInstallFiles.rend(); ++it) {
        if ((*it)->isCleanupNeeded())
            (*it)->uninstall();
    }

    if (mTargetDirectory->isCleanupNeeded())
        mTargetDirectory->uninstall();

}
