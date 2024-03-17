// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapTile.generated.h"

USTRUCT(BlueprintType)
struct FTileInfo
{
	GENERATED_BODY()
	
	int X{};
	int Y{};
	int Z{};

	FTileInfo() = default; 

	FTileInfo(int const NewX, int const NewY, int const NewZ)
		: X(NewX), Y(NewY), Z(NewZ)
	{
	}
};

UCLASS()
class NEURALINK_API AMapTile : public AActor
{
	GENERATED_BODY()
	
public:	
	AMapTile();

	void SetTileInfo(FTileInfo InTileInfo)
	{
		TileInfo = InTileInfo;
	}

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	FTileInfo TileInfo;

};
