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
    void copyFiles(const std::vector<LPCWSTR>& sourceFiles);
public:
    std::shared_ptr<BOOL> mCompleted;

    FileInstaller(const LPCWSTR& targetDirectory, const std::vector<LPCWSTR>& sourceFiles);
    ~FileInstaller(void);
};

