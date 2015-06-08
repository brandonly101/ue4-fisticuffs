// Copyright Brandon Ly and Kevin Luc 2015

#include "Fisticuffs.h"
#include "FisticuffsGameState.h"

// Constructor
AFisticuffsGameState::AFisticuffsGameState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

// Begin Play
void AFisticuffsGameState::BeginPlay()
{
	// Inherit Parent Class's BeginPlay()
	Super::BeginPlay();

	// Assign the reference variables
	GameMode = Cast<AFisticuffsGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Tick
void AFisticuffsGameState::Tick(float DeltaSeconds)
{
	// Inherit Parent Class's Tick()
	Super::Tick(DeltaSeconds);

	// Singleplayer
	if (GameMode->PlayState == EFisticuffsPlayState::EMatchStartSP)
	{   
        // If the player is dead, change the game mode to Match Over
		if (Cast<AFisticuffsPlayerState>(PlayerArray[0])->GetFighterDead())
		{
			GameMode->SetCurrentState(EFisticuffsPlayState::EMatchOver);
		}
	}
	else if (GameMode->PlayState == EFisticuffsPlayState::EMatchStartMP)
	{
        
	}
}
