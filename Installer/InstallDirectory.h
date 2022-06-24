#pragma once
#include <Windows.h>
#include <Shlwapi.h>
#include <memory>

#include "Exceptions.h"
#include "AbstractInstallable.h"

const LPSECURITY_ATTRIBUTES INHERIT_SECURITY = NULL;
const BOOL CREATE_DIRECTORY_FAIL = 0;

class InstallDirectory: public AbstractInstallable
{
private:
	std::wstring mTargetDirectory;

public:
	const std::wstring getName(void) const;
	virtual void install(void) override;
	virtual void uninstall(void) override;

	InstallDirectory(std::wstring path, std::shared_ptr<BOOL> completed): AbstractInstallable(completed), mTargetDirectory(path) {};
	~InstallDirectory(void) { if (this->isCleanupNeeded()) { this->uninstall(); } };
};

