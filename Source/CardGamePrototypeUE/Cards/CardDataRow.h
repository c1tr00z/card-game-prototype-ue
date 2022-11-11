#pragma once
#include "Engine/DataTable.h"

#include "CardDataRow.generated.h"

USTRUCT(BlueprintType)
struct CARDGAMEPROTOTYPEUE_API FCardDataRow : public FTableRowBase {
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString JsonString;
};
