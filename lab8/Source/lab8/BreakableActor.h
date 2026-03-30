#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BreakableActor.generated.h"
UCLASS()
class LAB8_API ABreakableActor : public AActor
{
	GENERATED_BODY()
public:
	ABreakableActor();
protected:
	virtual void BeginPlay() override;
public:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse,
		const FHitResult& Hit);
};