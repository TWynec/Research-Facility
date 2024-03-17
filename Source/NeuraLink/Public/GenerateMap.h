// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MapTile.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenerateMap.generated.h"

UCLASS()
class NEURALINK_API AGenerateMap : public AActor
{
	GENERATED_BODY()
	
public:	
	AGenerateMap();

	UFUNCTION(BlueprintCallable)
	void BuildMap(const FVector CenteredLocation, const int X, const int Y);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FVector2D MapSize;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<AActor>> MapTiles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<AMapTile> TileClass;
};
