// Copyright Brandon Ly and Kevin Luc.

#include "Fisticuffs.h"
#include "FisticuffsPlayerCameraManager.h"

// Constructor
AFisticuffsPlayerCameraManager::AFisticuffsPlayerCameraManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Have init variables for the player camera manager and stuff here
	PrimaryActorTick.bCanEverTick = true;
}


void AFisticuffsPlayerCameraManager::BeginPlay()
{
	// Find the FighterCharacter in the map
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		if (ActorItr->ActorHasTag("EnemyFighter"))
			TargetActor = *ActorItr;
}

void AFisticuffsPlayerCameraManager::Tick(float DeltaSeconds)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TargetActor->GetName());

}
