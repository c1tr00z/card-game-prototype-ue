#include "EffectsDeserializer.h"

#include "EffectDamageParameters.h"

FEffectParametersBase EffectsDeserializer::Deserialize(TSharedRef<FJsonObject> JsonObject) {
	auto ClassName = JsonObject->GetStringField("ClassName");
	if (ClassName == FEffectDamageParameters::StaticStruct()->GetName())
	{
		return DeserializeParameters<FEffectDamageParameters>(JsonObject, FEffectDamageParameters::StaticStruct());
	}

	return FEffectParametersBase();
}
