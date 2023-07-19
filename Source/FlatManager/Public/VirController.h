// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VirController.generated.h"




UCLASS()
class FLATMANAGER_API AVirController : public AActor
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int32 Floor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int32 Section;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int32 Part;
	//House number
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int32 House;
	
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	//AActor* furnitureMesh;

	UPROPERTY(AdvancedDisplay, VisibleAnywhere, BlueprintReadWrite, Category = "Settings")
	bool bSelected;

	UPROPERTY(AdvancedDisplay, VisibleAnywhere, BlueprintReadWrite, Category = "Settings")
	bool bIsTouch;

	UPROPERTY(AdvancedDisplay, VisibleAnywhere, BlueprintReadWrite, Category = "Settings")
	bool bIsDefaultPosition;
	
	UPROPERTY(AdvancedDisplay, EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool bAllowedSelect;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Border")
		bool bMirrorBorder;




	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsValidate;

	UPROPERTY(BlueprintReadOnly)
	FVector DefaultActorLocation;

	UPROPERTY(BlueprintReadOnly)
	FVector TopActorLocation;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
		USceneComponent* Root;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Settings")
		UStaticMeshComponent* FlatMesh;

	//UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Border")
	//	UStaticMeshComponent* BorderMeshA;

	//UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Border")
	//	UStaticMeshComponent* BorderMeshB;


	//UWorld* FloorPlan;

	//UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Settings")
	//	UStaticMeshComponent* FlatCapMesh;

protected:
	
	UPROPERTY(VisibleDefaultsOnly)
		int32 LiftingHeight;
public:	
	// Sets default values for this actor's properties
	AVirController();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool ValidateData();
	void EventWarning(FString message);
	void EventError(FString message);
	void EventMessage(FString message);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "VirFlatControl")
	bool SuitableToLiftUp(int selectFloor,int selectSection, int partHouse , int selectHouse);
	
	UFUNCTION(BlueprintCallable, Category = "VirFlatControl")
		bool SuitableToLiftDown(int selectFloor, int selectSection, int partHouse, int selectHouse);

	UFUNCTION(BlueprintCallable, Category = "VirFlatControl")
	bool SuitableToSelect();

	UFUNCTION(BlueprintCallable, Category = "VirFlatControl")
		bool SelectedFlat();

	UFUNCTION(BlueprintCallable, Category = "VirFlatControl")
		bool DeselectFlat();

	UFUNCTION(BlueprintCallable, Category = "VirFlatControl")
		FVector GetTopFlatLoacation();

};
