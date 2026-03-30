#include "Collectible.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
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
void ACollectible::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor*
	OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* Player = Cast<ACharacter>(OtherActor);
	if (Player)
	{
		Destroy();
	}
}