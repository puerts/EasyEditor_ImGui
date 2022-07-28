#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FEasyEditor_ImGuiModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
