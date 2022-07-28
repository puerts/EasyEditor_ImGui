#include "EasyEditor_ImGui.h"
#include "EasyEditorPlugin.h"
#include "EasyEditorDetailCustomization.h"

#define LOCTEXT_NAMESPACE "FEasyEditor_ImGuiModule"

void FEasyEditor_ImGuiModule::StartupModule()
{
	FModuleManager::LoadModuleChecked<FEasyEditorPluginModule>("EasyEditorPlugin").OnJsEnvCleanup.AddLambda([]()
	{
		UEasyEditorDetailCustomization* CDO = Cast<UEasyEditorDetailCustomization>(UEasyEditorDetailCustomization::StaticClass()->GetDefaultObject(false));
		if (CDO)
		{
			CDO->ClearOnDetailDraw();
		}
	});
}

void FEasyEditor_ImGuiModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEasyEditor_ImGuiModule, EasyEditor_ImGui)