#pragma once
#include <memory>
#include <Windows.h>

class AbstractInstallable // FIXES 1: Create abstract class that implemenets the check for when to delete and the interface of install() and uninstall()
{
protected:
	std::shared_ptr<BOOL> mCompleted;
	BOOL mInstalled = FALSE;

public: 
	AbstractInstallable() = delete;
	AbstractInstallable(std::shared_ptr<BOOL> completed) : mCompleted(completed) {}
	
	virtual void install() = 0;
	virtual void uninstall() = 0;

	virtual BOOL isCleanupNeeded() {
		return (nullptr != mCompleted) && !*this->mCompleted && this->mInstalled; // Declared and uninstantiated shared_ptr<> is nullptr so we don't want to deref that
	}

	virtual ~AbstractInstallable() = default;
};