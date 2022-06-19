#include "FileInstaller.h"

void FileInstaller::copyFiles(const std::vector<LPCWSTR>& sourceFiles)
{
    WCHAR targetFilePath[MAX_PATH] = L"";
    LPWSTR filename = nullptr;

    for (auto it = sourceFiles.begin(); it != sourceFiles.end(); ++it) {
        // Create the path and put it into targetFilePath
        filename = PathFindFileName(*it);
        PathCombine(targetFilePath, mTargetDirectory->getName(), filename);
        
        this->mInstallFiles.push_back(std::make_unique<InstallFile>(*it, targetFilePath, this->mCompleted));
    }
    
    // If we reached here, all files were copied successfully
    *this->mCompleted = TRUE;
}


FileInstaller::FileInstaller(const LPCWSTR& targetDirectory, const std::vector<LPCWSTR>& sourceFiles)
{
    // Shared pointer to keep track of whether the program finished successfully or not
    this->mCompleted = std::make_shared<BOOL>(FALSE);

    mTargetDirectory = std::make_unique<InstallDirectory>(targetDirectory, this->mCompleted);
    this->copyFiles(sourceFiles);
}

FileInstaller::~FileInstaller(void)
{
    
}
