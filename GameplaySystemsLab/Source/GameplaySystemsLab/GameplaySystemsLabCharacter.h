#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplaySystemsLabCharacter.generated.h"

UCLASS()
class GAMEPLAYSYSTEMSLAB_API AGameplaySystemsLabCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGameplaySystemsLabCharacter();

	// Stats for the Lab
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxHealth;

	// Combat & Health Functions
	void Attack();
	float GetHealthPercent() const;
	void AddHealth(float Amount);

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Movement
	void MoveForward(float Value);
	void MoveRight(float Value);

	// Camera Look
	void LookUp(float Value);
	void Turn(float Value);
};