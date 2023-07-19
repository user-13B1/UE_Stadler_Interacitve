// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FmanagerBPFunctionLibrar.generated.h"


UENUM(BlueprintType)
enum Status 
{
	General  UMETA(DisplayName = "General "),
	Section  UMETA(DisplayName = "Section "),
	Flat  UMETA(DisplayName = "Flat "),
	Panorama UMETA(DisplayName = "Panorama "),
	SityMap UMETA(DisplayName = "SityMap "),
	Group UMETA(DisplayName = "Group"),

};



UCLASS()
class FLATMANAGER_API UFmanagerBPFunctionLibrar : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
		UFUNCTION(BlueprintCallable, Category = FmanagerBPLibrary, meta = (WorldContext = "WorldContextObject"))
		static int32 GetNumberOfInstances(UObject* WorldContextObject, TSubclassOf< UInterface > Interface);
	
	
	
};

