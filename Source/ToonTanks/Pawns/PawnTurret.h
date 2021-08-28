#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.h"
#include "PawnTurret.generated.h"

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void HandleDestruction() override;

private:
	FTimerHandle FireRateTimerHandle;
	APawnTank* PlayerPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat", meta=(AllowPrivateAccess="true"))
	float FireRate = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat", meta=(AllowPrivateAccess="true"))
	float FireRange = 500;

	void CheckFireCondition();
	float ReturnDistanceToPlayer();
	
public:
	virtual void Tick(float DeltaTime) override;
};
