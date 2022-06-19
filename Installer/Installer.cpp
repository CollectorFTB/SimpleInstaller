#include "FileInstaller.h"

int main()
{
    std::wstring targetDirectory = L"C:\\temp\\dest";
    std::vector<std::wstring> sourceFiles{ L"C:\\temp\\source\\New folder\\file.txt", L"C:\\temp\\source\\b.txt", L"C:\\temp\\source\\a.txt" };
    
    try {
        FileInstaller installer(targetDirectory);
        installer.install(sourceFiles);
    }
    catch (const CreateDirectoryError& err) {
        std::wcout << L"An exception occured while creating directory" << err.mDirectoryName << std::endl;
        return -1;
    }
    catch (const CopyFileError& err) {
        std::wcout << L"An exception occured while copying " << err.mFilePath << std::endl;
        return -1;
    }
    return 0;
}
