// Copyright Brandon Ly and Kevin Luc 2015

#include "Fisticuffs.h"
#include "FisticuffsPlayerState.h"

// Constructor
AFisticuffsPlayerState::AFisticuffsPlayerState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FighterDead = false;
}

// Begin Play
void AFisticuffsPlayerState::BeginPlay()
{
	// Inherit Parent Class's BeginPlay()
	Super::BeginPlay();
}

// Tick
void AFisticuffsPlayerState::Tick(float DeltaSeconds)
{
	// Inherit Parent Class's Tick()
	Super::Tick(DeltaSeconds);

    if (MAX_DISCOMBOB <= FighterStatDiscombobCurrent)
	{
		SetFighterDead();
	}
}

bool AFisticuffsPlayerState::GetFighterDead() const
{
    return FighterDead;
}

bool AFisticuffsPlayerState::SetFighterDead()
{
    FighterDead = true;
}
