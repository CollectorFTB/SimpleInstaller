#include "FileInstaller.h"

void FileInstaller::copyFiles(const std::vector<std::wstring>& sourceFiles)
{
    WCHAR targetFilePath[MAX_PATH];
    LPWSTR filename = nullptr;

    std::wstring a;
    for (auto it = sourceFiles.begin(); it != sourceFiles.end(); ++it) {
        // Create the path and put it into targetFilePath
        filename = PathFindFileName((* it).c_str());
        PathCombine(targetFilePath, mTargetDirectory->getName().c_str(), filename);
        
        auto file = std::make_unique<InstallFile>(*it, std::wstring(targetFilePath), this->mCompleted);
        file->install();
        this->mInstallFiles.push_back(std::move(file));
    }
}

void FileInstaller::install(const std::vector<std::wstring>& sourceFiles) {
    this->mTargetDirectory->createDirectory();
    this->copyFiles(sourceFiles);

    // If we reached here, installer finished successfully
    *this->mCompleted = TRUE;
}

FileInstaller::FileInstaller(std::wstring targetDirectory)
{
    // Shared pointer to keep track of whether the program finished successfully or not
    this->mCompleted = std::make_shared<BOOL>(FALSE);

    mTargetDirectory = std::make_unique<InstallDirectory>(targetDirectory, this->mCompleted);
}

FileInstaller::~FileInstaller(void)
{
    
}
