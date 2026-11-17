// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VitalisHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnVitalisHealthChanged,
	float, CurrentHealth,
	float, MaxHealth
);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnVitalisDeath);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VITALISHEALTH_API UVitalisHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UVitalisHealthComponent();
	
	UFUNCTION(BlueprintPure, Category = "Vitalis|Health")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintPure, Category = "Vitalis|Health")
	float GetCurrentHealth() const;
	
	UFUNCTION(BlueprintCallable, Category = "Vitalis|Health")
	void ApplyDamage(float DamageAmount);
	
	UFUNCTION(BlueprintCallable, Category = "Vitalis|Health")
	void Heal(float HealAmount);

	UFUNCTION(BlueprintPure, Category = "Vitalis|Health")
	bool IsDead() const;
	
	UFUNCTION(BlueprintPure, Category = "Vitalis|Health")
	bool IsAlive() const;
	
	UPROPERTY(BlueprintAssignable, Category = "Vitalis|Events")
	FOnVitalisHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Vitalis|Events")
	FOnVitalisDeath OnDeath;


protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,
		Category = "Vitalis|Health",
		meta = (AllowPrivateAccess = "true", ClampMin = "1.0"))
	float MaxHealth = 100.0f;
	
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly,
		Category = "Vitalis|Health",
		meta = (AllowPrivateAccess = "true"))
	float CurrentHealth = 100.0f;

};
