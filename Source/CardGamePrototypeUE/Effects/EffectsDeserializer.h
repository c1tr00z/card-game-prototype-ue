#pragma once
#include "EffectParametersBase.h"
#include "JsonObjectConverter.h"
#include "Common/ReflectionFunctions.h"

class CARDGAMEPROTOTYPEUE_API EffectsDeserializer {
public:
	static FEffectParametersBase Deserialize(TSharedRef<FJsonObject> JsonObject);

	template <typename T>
	static T DeserializeParameters(TSharedRef<FJsonObject> JsonObject, UStruct* UStruct);
};

template <typename T>
T EffectsDeserializer::DeserializeParameters(TSharedRef<FJsonObject> JsonObject, UStruct* UStruct) {
	auto Instance = UReflectionFunctions::InstantiateStructByUStruct<T>(UStruct);
	FJsonObjectConverter::JsonObjectToUStruct(JsonObject, &Instance);
	return Instance;
}
