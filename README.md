# Project Vitalis

**A lightweight, reusable health management plugin for Unreal Engine 5.8, developed in C++.**

Unreal Engine 5.8向けにC++で開発した、軽量で再利用可能なヘルス管理プラグインです。

## Overview / 概要

Project Vitalis provides a modular health management system that can be attached to Actors through an `ActorComponent`.

It supports damage, healing, health-state queries, and event-driven communication with Blueprints.

Project Vitalisは、`ActorComponent`を利用したモジュール型のヘルス管理システムです。

Actorにコンポーネントを追加することで、ダメージ処理、回復処理、生存・死亡判定、Blueprintへのイベント通知を利用できます。

## Features / 主な機能

- **Configurable Maximum Health / 最大HPの設定**  
  Set the maximum health value through Blueprint defaults.  
  Blueprintのデフォルト設定から最大HPを変更できます。

- **Damage Processing / ダメージ処理**  
  Apply damage while preventing health from falling below zero.  
  HPが0未満にならないようにダメージを処理します。

- **Healing / 回復処理**  
  Restore health without exceeding the maximum value.  
  最大HPを超えない範囲で回復処理を行います。

- **Health State Queries / 生存・死亡判定**  
  Check current health, maximum health, and whether an Actor is alive or dead.  
  現在HP、最大HP、生存状態、死亡状態を取得できます。

- **Blueprint Event Delegates / Blueprintイベント通知**  
  Notify other systems when health changes or an Actor dies.  
  HPの変化や死亡時に、Blueprintへイベントを通知できます。

- **Reusable Component Architecture / 再利用可能なコンポーネント設計**  
  Attach the component to different Actors without modifying the plugin's source code.  
  プラグインのソースコードを変更せず、さまざまなActorに追加して使用できます。

## Requirements / 動作環境

- Unreal Engine 5.8
- C++ project with a supported development toolchain
- Windows development environment used for validation

## Installation / インストール方法

1. Download or clone this repository.
2. Copy the `VitalisHealth` plugin folder into your Unreal project's `Plugins` directory.
3. Open the Unreal project.
4. Rebuild the C++ modules if prompted.
5. Verify that `VitalisHealth` is enabled under **Edit → Plugins**.

### 日本語

1. リポジトリをダウンロード、またはクローンします。
2. `VitalisHealth`フォルダをUnrealプロジェクトの`Plugins`フォルダにコピーします。
3. Unrealプロジェクトを開きます。
4. モジュールの再ビルドを求められた場合は実行します。
5. **Edit → Plugins**から`VitalisHealth`が有効になっていることを確認します。

## Usage / 使用方法

1. Create or open an Actor Blueprint.
2. Click **Add Component**.
3. Search for and add `VitalisHealth`.
4. Configure `MaxHealth` as needed.
5. Call `ApplyDamage()` or `Heal()` from Blueprint.
6. Bind events to `OnHealthChanged` and `OnDeath` to react to health updates.

### 日本語

1. ActorのBlueprintを作成、または開きます。
2. **Add Component**をクリックします。
3. `VitalisHealth`を検索して追加します。
4. 必要に応じて`MaxHealth`を設定します。
5. Blueprintから`ApplyDamage()`や`Heal()`を呼び出します。
6. `OnHealthChanged`や`OnDeath`にイベントをバインドし、HPの変化に応じた処理を実装します。

## C++ API / C++関数一覧

| Function | Description / 説明 |
|---|---|
| `GetMaxHealth()` | Returns maximum health / 最大HPを取得 |
| `GetCurrentHealth()` | Returns current health / 現在HPを取得 |
| `ApplyDamage(float)` | Applies damage / ダメージを適用 |
| `Heal(float)` | Restores health / HPを回復 |
| `IsDead()` | Checks whether health is zero / 死亡状態を判定 |
| `IsAlive()` | Checks whether the Actor is alive / 生存状態を判定 |

### Event Delegates / イベントデリゲート

| Event | Description / 説明 |
|---|---|
| `OnHealthChanged` | Broadcasts current and maximum health when HP changes / HP変更時に現在HPと最大HPを通知 |
| `OnDeath` | Broadcasts when HP transitions from above zero to zero / HPが0になり、死亡状態へ移行した際に通知 |

## Health Behavior / HPの処理仕様

- Health is initialized to `MaxHealth` at `BeginPlay`.
- Damage and healing amounts of zero or less are ignored.
- Health is clamped between `0` and `MaxHealth`.
- `OnHealthChanged` broadcasts only when HP actually changes.
- `OnDeath` broadcasts only when an Actor transitions from alive to dead.
- Healing from zero HP is supported, allowing revival.

### 日本語

- `BeginPlay`時に現在HPを最大HPで初期化します。
- 0以下のダメージ量・回復量は無視します。
- HPは0から最大HPの範囲に制限されます。
- `OnHealthChanged`はHPが実際に変化した場合のみ通知します。
- `OnDeath`は生存状態から死亡状態に変化した場合のみ通知します。
- HPが0の状態から回復することも可能です。

## Testing / 動作確認

The plugin was tested in Unreal Engine 5.8 using Blueprint-based runtime tests.

Validated behaviors include:

- Health initialization
- Damage and healing
- Maximum and minimum health clamping
- Health-change event broadcasting
- Death event broadcasting
- Prevention of repeated death events
- Installation and execution in a separate Unreal Engine project

A portability test confirmed that the plugin could be copied into another C++ project, rebuilt, enabled, attached to an Actor, and used to process damage successfully.

### 日本語

Unreal Engine 5.8でBlueprintを使用した動作確認を実施しました。

HPの初期化、ダメージ、回復、HPの上限・下限処理、イベント通知、重複した死亡イベントの防止を確認しています。

また、別のC++プロジェクトにプラグインをコピーして再ビルドし、Actorに追加した状態でダメージ処理が正常に動作することを確認しました。

## Scope / 対応範囲

Version 1.0 focuses on a simple, standalone health management component.

Multiplayer replication, Gameplay Ability System integration, shields, armor, and automatic regeneration are outside the current scope.

バージョン1.0では、単独で利用できるシンプルなヘルス管理コンポーネントの実装を目的としています。

マルチプレイヤー同期、Gameplay Ability Systemとの連携、シールド、防御力、自動回復などは現時点では実装していません。

## Author / 開発者

**Ramzel Suarez**

Unreal Engine C++ / Gameplay Systems Development

GitHub: https://github.com/ramzelsuarez/ProjectVitalis
