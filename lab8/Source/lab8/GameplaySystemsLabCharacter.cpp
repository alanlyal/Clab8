#include "GameplaySystemsLabCharacter.h"
#include "Components/CapsuleComponent.h"

// Constructor
AGameplaySystemsLabCharacter::AGameplaySystemsLabCharacter()
{
    // Set default capsule size
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

    // ?? REQUIRED FOR LAB: Set collision profile
    GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

    // Enable overlap events (needed for triggers & collectibles)
    GetCapsuleComponent()->SetGenerateOverlapEvents(true);

    // Ensure proper collision behavior
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}
