#include "PawnTurret.h"

#include "Kismet/GameplayStatics.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!PlayerPawn || ReturnDistanceToPlayer() > FireRange) return;

	RotateTurret(PlayerPawn->GetActorLocation());
}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


void APawnTurret::CheckFireCondition()
{
	if(!PlayerPawn) return;

	if(ReturnDistanceToPlayer() <= FireRange)
	{
		Fire();
	}
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if(!PlayerPawn) return 0;

	float Distance = FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
	return Distance;
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}