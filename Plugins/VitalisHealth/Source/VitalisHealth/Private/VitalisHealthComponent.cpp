// Copyright Zel Suarez


#include "VitalisHealthComponent.h"

UVitalisHealthComponent::UVitalisHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UVitalisHealthComponent::GetMaxHealth() const
{
	return MaxHealth;
}

float UVitalisHealthComponent::GetCurrentHealth() const
{
	return CurrentHealth;
}

void UVitalisHealthComponent::ApplyDamage(float DamageAmount)
{
	if (DamageAmount <= 0.0f)
	{
		return;
	}

	const float OldHealth = CurrentHealth;

	CurrentHealth = FMath::Clamp(
		CurrentHealth - DamageAmount,
		0.0f,
		MaxHealth
	);

	if (CurrentHealth != OldHealth)
	{
		OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
	}
	
	if (OldHealth > 0.0f && CurrentHealth <= 0.0f)
	{
		OnDeath.Broadcast();
	}
}

void UVitalisHealthComponent::Heal(float HealAmount)
{
	if (HealAmount <= 0.0f)
	{
		return;
	}
	
	const float OldHealth = CurrentHealth;

	CurrentHealth = FMath::Clamp(
		CurrentHealth + HealAmount,
		0.0f,
		MaxHealth
	);
	
	if (CurrentHealth != OldHealth)
	{
		OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
	}
}

bool UVitalisHealthComponent::IsDead() const
{
	return CurrentHealth <= 0.0f;
}

bool UVitalisHealthComponent::IsAlive() const
{
	return !IsDead();
}

void UVitalisHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	MaxHealth = FMath::Max(MaxHealth, 1.0f);
	CurrentHealth = MaxHealth;
}
