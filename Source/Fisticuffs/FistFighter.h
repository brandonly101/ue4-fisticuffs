// Copyright Brandon Ly and Kevin Luc.

#pragma once

#include "GameFramework/Character.h"
#include "FistFighter.generated.h"

UCLASS()
class FISTICUFFS_API AFistFighter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFistFighter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// Custom variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fistfighter Statistics")
	float StatDiscombobulation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fistfighter Statistics")
	float StatStamina;

	UFUNCTION(BlueprintCallable, Category = "FistFighter Functions")
	void IncrementDiscombobulation(float IncValue = 0.1);

	UFUNCTION(BlueprintCallable, Category = "FistFighter Functions")
	void IncrementStamina(float IncValue = -0.1);
};
