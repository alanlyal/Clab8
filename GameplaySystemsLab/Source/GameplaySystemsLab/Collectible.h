#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectible.generated.h"

UCLASS()
class GAMEPLAYSYSTEMSLAB_API ACollectible : public AActor
{
	GENERATED_BODY()

public:
	ACollectible();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere)
	class USphereComponent* Sphere;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
};
