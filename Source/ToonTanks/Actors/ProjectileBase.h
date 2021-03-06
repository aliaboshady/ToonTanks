#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProjectileBase.generated.h"

UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UParticleSystemComponent* ParticleTrail;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UProjectileMovementComponent* ProjectileMovement;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* ProjectileMesh;
	
	UPROPERTY(EditDefaultsOnly, Category="Damage")
	TSubclassOf<UDamageType> DamageType;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Move", meta=(AllowPrivateAccess="true"))
	float MovementSpeed = 1300;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage", meta=(AllowPrivateAccess="true"))
	float Damage = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Lifespan", meta=(AllowPrivateAccess="true"))
	float Lifespan = 2;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, Category="Effects")
	UParticleSystem* HitParticle;

	UPROPERTY(EditAnywhere, Category="Effects")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category="Effects")
	USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category="Effects")
	 TSubclassOf<UMatineeCameraShake> HitShake;
	
public:	
	AProjectileBase();
};
