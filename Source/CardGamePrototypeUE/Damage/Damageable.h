#pragma once
#include "LifeComponent.h"

#include "Damageable.generated.h"

UINTERFACE()
class UDamageable : public UInterface {
public:
	GENERATED_BODY()
};

class CARDGAMEPROTOTYPEUE_API IDamageable {
	GENERATED_BODY()
public:
	virtual ULifeComponent* GetLife();
};
