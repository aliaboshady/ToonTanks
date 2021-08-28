#include "ProjectileBase.h"

AProjectileBase::AProjectileBase()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("Projectile Mesh");
	RootComponent = ProjectileMesh;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Movement");

	ProjectileMovement->InitialSpeed = MovementSpeed;
	ProjectileMovement->MaxSpeed = MovementSpeed;
	
}

void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(Lifespan);
}
