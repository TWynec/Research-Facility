// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerateMap.h"
#include <Kismet/GameplayStatics.h>

AGenerateMap::AGenerateMap()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AGenerateMap::BuildMap(const FVector CenteredLocation, const int X, const int Y)
{
	if (MapTiles.Num() == 0) {
		MapSize.X = X;
		MapSize.Y = Y;

		for (auto OuterIndex{ 0 }; OuterIndex <= Y - 1; ++OuterIndex) {
			for (auto InnerIndex{ 0 }; InnerIndex <= X - 1; ++InnerIndex) {
				float constexpr SectorSize = 100.f;

				FVector SpawnLocation =
					FVector(static_cast<float>(InnerIndex) - static_cast<float>(X) / 2.f,
						static_cast<float>(OuterIndex) - static_cast<float>(Y) / 2.f,
						0.f)
					* SectorSize
					* 1.f
					+ CenteredLocation;

				FTransform SpawnTransform;
				SpawnTransform.SetLocation(SpawnLocation);

				if (TileClass.LoadSynchronous()) {
					AActor* TileToSpawn = UGameplayStatics::BeginDeferredActorSpawnFromClass(
						this, TileClass.LoadSynchronous(), SpawnTransform);

					AMapTile* Tile = Cast<AMapTile>(TileToSpawn);
					if (Tile) {
						Tile->SetTileInfo(FTileInfo(InnerIndex, OuterIndex, 0));
					}

					TileToSpawn->FinishSpawning(SpawnTransform);
					MapTiles.Add(TileToSpawn);
					TileToSpawn->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

				}
			}
		}
	}
}

void AGenerateMap::BeginPlay()
{
	Super::BeginPlay();
	
}
