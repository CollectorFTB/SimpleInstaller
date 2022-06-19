#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include <memory>

#include "InstallFile.h"
#include "InstallDirectory.h"

class FileInstaller {
private:
    std::unique_ptr<InstallDirectory> mTargetDirectory;
    std::vector<std::unique_ptr<InstallFile>> mInstallFiles;
    void copyFiles(const std::vector<std::wstring>& sourceFiles);
    std::shared_ptr<BOOL> mCompleted;
public:
    void install(const std::vector<std::wstring>& sourceFiles);

    FileInstaller(std::wstring targetDirectory);
    ~FileInstaller(void);
};

