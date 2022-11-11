#pragma once
#include "EffectParametersBase.h"

#include "EffectDamageParameters.generated.h"

USTRUCT(BlueprintType)
struct FEffectDamageParameters : public FEffectParametersBase {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int DamageValue;
};
