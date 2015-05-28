// Copyright Brandon Ly and Kevin Luc.

#include "Fisticuffs.h"
#include "FisticuffsGameMode.h"

AFisticuffsGameMode::AFisticuffsGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Have init variables for the player camera manager and stuff here
	PrimaryActorTick.bCanEverTick = true;
	//GEngine->DeferredCommands.Add(TEXT("hmd sp 50"));
	//GetWorld()->Exec(GetWorld(), TEXT("hmd sp 50"));
}

void AFisticuffsGameMode::BeginPlay()
{

}

void AFisticuffsGameMode::Tick(float DeltaSeconds)
{

}
