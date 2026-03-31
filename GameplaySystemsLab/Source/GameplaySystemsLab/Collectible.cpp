#include "Collectible.h"
#include "Components/SphereComponent.h"
#include "GameplaySystemsLabCharacter.h"
#include "Engine/Engine.h"

ACollectible::ACollectible()
{
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	RootComponent = Sphere;

	Sphere->SetCollisionProfileName(TEXT("Trigger"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ACollectible::OnOverlap);
}

void ACollectible::BeginPlay()
{
	Super::BeginPlay();
}

void ACollectible::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	AGameplaySystemsLabCharacter* Player = Cast<AGameplaySystemsLabCharacter>(OtherActor);

	if (Player)
	{
		Player->AddHealth(20.f);

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Collected Item! +20 Health"));
		}

		Destroy();
	}
}

