// Fill out your copyright notice in the Description page of Project Settings.


#include "FmanagerBPFunctionLibrar.h"
#include "Kismet/GameplayStatics.h"



int32 UFmanagerBPFunctionLibrar::GetNumberOfInstances(UObject* WorldContextObject,  TSubclassOf< UInterface > Interface )
{
   /* TArray< AActor* > InstancesFound;
    UGameplayStatics::GetAllActorsOfClass(WorldContextObject, ActorClass, InstancesFound);*/

    
    TArray<AActor*> Actors;
 //   UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UActionable::StaticClass(), ActionableActor);
    UGameplayStatics::GetAllActorsWithInterface(GWorld, Interface, Actors);

   // TEnumAsByte<Status> status;
    return Actors.Num();

}





