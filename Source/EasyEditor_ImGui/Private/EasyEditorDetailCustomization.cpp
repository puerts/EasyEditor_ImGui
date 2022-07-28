#ifdef UEIMGUI_API
#include "EasyEditorDetailCustomization.h"

void UEasyEditorDetailCustomization::OnEditSingleObject(UObject* InObject)
{
	auto Cls = InObject->GetClass();
	for(auto &KV : DrawCallbacks)
	{
		if (Cls->IsChildOf(KV.Key))
		{
			KV.Value(InObject);
		}
	}
}

bool UEasyEditorDetailCustomization::IsSupportClass(UClass* InClass)
{
	for(auto &KV : DrawCallbacks)
	{
		if (InClass->IsChildOf(KV.Key))
		{
			return true;
		}
	}
	return false;
}
#endif