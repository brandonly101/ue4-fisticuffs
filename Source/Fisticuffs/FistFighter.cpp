// Copyright Brandon Ly and Kevin Luc.

#include "Fisticuffs.h"
#include "FistFighter.h"


// Sets default values
AFistFighter::AFistFighter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set stat variables to its default values.
	StatDiscombobulation = 0.0;
	StatStamina = 1.0;
}

// Called when the game starts or when spawned
void AFistFighter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFistFighter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AFistFighter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

// Increment Functions.
void AFistFighter::IncrementDiscombobulation(float IncValue)
{
	this->StatDiscombobulation += IncValue;
}

void AFistFighter::IncrementStamina(float IncValue)
{
	this->StatStamina += IncValue;
}
