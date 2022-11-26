// Fill out your copyright notice in the Description page of Project Settings.


#include "CGPCharactersFunctions.h"

#include "Modules/ModulesFunctions.h"

ACharactersModule* UCGPCharactersFunctions::GetCharactersModule(UWorld* World) {
	UModulesFunctions::GetModule<ACharactersModule>(World);
}

ACGPCharacterBase* UCGPCharactersFunctions::GetCharacterBySide(UWorld* World, TEnumAsByte<ESide> Side) {
	const auto Module = GetCharactersModule(World);

	if(Module == nullptr) {
		return nullptr;
	}

	return Module->GetCharacterBySide(Side);
}
