#pragma once
#include <Windows.h>
#include <Shlwapi.h>
#include <iostream>
#include <memory>

#include "Exceptions.h"
#include "AbstractInstallable.h"

const BOOL FAIL_IF_EXISTS = TRUE;
const BOOL COPY_FAIL = 0;

class InstallFile: public AbstractInstallable
{
private:
	std::wstring mSourcePath;
	std::wstring mDestinationPath;

public:
	virtual void install(void) override;
	virtual void uninstall(void) override;

	InstallFile(std::wstring sourcePath, std::wstring destinationPath, std::shared_ptr<BOOL> completed): AbstractInstallable(completed), mDestinationPath(destinationPath), mSourcePath(sourcePath) {};
	~InstallFile(void) { if (this->isCleanupNeeded()) { this->uninstall(); } };
};

