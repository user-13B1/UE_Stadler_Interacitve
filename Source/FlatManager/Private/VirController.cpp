// Fill out your copyright notice in the Description page of Project Settings.
#include "VirController.h"

#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
// Sets default values
AVirController::AVirController()
{
	PrimaryActorTick.bCanEverTick = true;

	Floor = -1;
	Section = -1;
	House = -1;
	Part = 1;
	LiftingHeight = 25000;
	bMirrorBorder = false;
	
	bSelected = false;
	bIsDefaultPosition = true;
	bIsValidate = false;
	bAllowedSelect = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	Root->SetMobility(EComponentMobility::Movable);

	FlatMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Flat"));
	FlatMesh->SetupAttachment(Root);
	
	/*FlatCapMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cap"));
	FlatCapMesh->SetupAttachment(FlatMesh);*/
	
	//BorderMeshA = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BorderA"));
	//BorderMeshA->SetupAttachment(FlatMesh);
	//BorderMeshB = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BorderB"));
	//BorderMeshB->SetupAttachment(FlatMesh);
}

// ------------BeginPlay------------------ //
void AVirController::BeginPlay()
{
	Super::BeginPlay();
	DefaultActorLocation = GetActorLocation();
	TopActorLocation = GetTopFlatLoacation();

	if (ValidateData())
		bIsValidate = true;

}


// ------------Tick------------------ //
void AVirController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


bool AVirController::SuitableToLiftUp(int selectFloor, int selectSection, int partHouse ,int selectHouse)
{
	if (Floor > selectFloor && House == selectHouse && bIsDefaultPosition && bIsValidate && !bSelected && Part == partHouse)
		return true;

	return false;
}

bool AVirController::SuitableToLiftDown(int selectFloor, int selectSection, int partHouse, int selectHouse)
{
	if(bIsDefaultPosition)
		return false;
	
	if(House != selectHouse)
		return true;

	if(Part != partHouse)
		return true;


	if(Floor <= selectFloor )
		return true;


	return false;
}


bool AVirController::SuitableToSelect()
{
	if (!bAllowedSelect)
	{
		EventMessage("This apartment not allowed select.");
		return false;
	}

	if (!bIsDefaultPosition)
	{
		EventWarning("This apartment not default position.");
		return false;
	}

	if (!bIsValidate)
	{
		EventWarning("This apartment not validate.");
		return false;
	}

	if (bSelected)
	{
		EventMessage("This apartment was previously selected.");
		return false;
	}

	return true;
}

bool AVirController::SelectedFlat()
{
	if (!bAllowedSelect)
		false;

	bSelected = true;



	//if (furnitureMesh != nullptr)
	//{
	//	furnitureMesh->SetActorLocation(FlatMesh->K2_GetComponentLocation());
	//	furnitureMesh->SetActorRotation(GetActorRotation());
	//	furnitureMesh->SetActorHiddenInGame(false);
	//}
	//else
	//{
	//	EventWarning("Null furniture mesh.");
	//}

	//if (FlatCapMesh != nullptr)
	//{
	//	FlatCapMesh->SetHiddenInGame(true);
	//}
	EventMessage("Apartment is selected.");
	return true;
	//VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	//FVector Floorlocation = K2_GetActorLocation
}

bool AVirController::DeselectFlat()
{
	if (bSelected != true)
	{
		return false;
	}
	
	//EventMessage("Deselect flat.");
	bSelected = false;
	//furnitureMesh->SetActorHiddenInGame(true);

	//if (FlatCapMesh != nullptr)
	//{
	//	FlatCapMesh->SetHiddenInGame(false);
	//}

	return true; 
}

FVector AVirController::GetTopFlatLoacation()
{
	
		return FVector(DefaultActorLocation.X, DefaultActorLocation.Y, DefaultActorLocation.Z + LiftingHeight);
}

bool AVirController::ValidateData()
{
	if (Floor == -1 || Section == -1 || House == -1)
	{
		EventError("Warning! FloorPlanBlock data not set.");
		return false;
	}
	
	//if (FlatMesh == nullptr )
	//{
	//	EventError("Null flat mesh");
	//	return false;
	//}

	//if (bAllowedSelect && furnitureMesh == nullptr)
	//{
	//	EventError("Null furnitureMesh mesh");
	//	return false;
	//}

	return true;
}

void AVirController::EventWarning(FString message)
{
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Yellow, FString::Printf(TEXT("WARNING: %s"), *message));
	UE_LOG(LogTemp, Warning, TEXT("WARNING: %s"), *message);
}

void AVirController::EventError(FString message)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("Error: %s"), *message));
	UE_LOG(LogTemp, Error, TEXT("WARNING: %s"), *message);
}

void AVirController::EventMessage(FString message)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, message);
	UE_LOG(LogTemp, Log, TEXT("WARNING: %s"), *message);
}

