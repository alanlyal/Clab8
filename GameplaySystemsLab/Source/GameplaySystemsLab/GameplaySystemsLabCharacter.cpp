#include "GameplaySystemsLabCharacter.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Enemy.h" // Ensure you have an Enemy.h file in your project

AGameplaySystemsLabCharacter::AGameplaySystemsLabCharacter()
{
	// Set collision size
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

	// Initialize Stats
	Health = 50.f;
	MaxHealth = 100.f;

	// Don't rotate character with camera
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	// Configure movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 600.f;

	// Auto-possess this character
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void AGameplaySystemsLabCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AGameplaySystemsLabCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Movement Bindings (Must match Project Settings exactly)
	PlayerInputComponent->BindAxis("MoveForward", this, &AGameplaySystemsLabCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGameplaySystemsLabCharacter::MoveRight);

	// Camera Bindings
	PlayerInputComponent->BindAxis("LookUp", this, &AGameplaySystemsLabCharacter::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &AGameplaySystemsLabCharacter::Turn);

	// Action Bindings
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AGameplaySystemsLabCharacter::Attack);
}

void AGameplaySystemsLabCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AGameplaySystemsLabCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0.f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AGameplaySystemsLabCharacter::LookUp(float Value) { AddControllerPitchInput(Value); }
void AGameplaySystemsLabCharacter::Turn(float Value) { AddControllerYawInput(Value); }

void AGameplaySystemsLabCharacter::Attack()
{
	FVector Start = GetActorLocation();
	FVector End = Start + (GetActorForwardVector() * 500.f);
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	// Draw the red line required for the lab
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.0f);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
	{
		if (AEnemy* Enemy = Cast<AEnemy>(Hit.GetActor()))
		{
			UGameplayStatics::ApplyDamage(Enemy, 25.f, GetController(), this, nullptr);
		}
	}
}

float AGameplaySystemsLabCharacter::GetHealthPercent() const { return Health / MaxHealth; }

void AGameplaySystemsLabCharacter::AddHealth(float Amount)
{
	Health = FMath::Clamp(Health + Amount, 0.f, MaxHealth);
}