// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VirBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class FLATMANAGER_API UVirBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:
	
	virtual float SumN(float DeltaTime);
	
};
