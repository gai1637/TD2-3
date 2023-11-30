#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

/// <summary>
/// ゲームシーン
/// </summary>
enum class Scene {
	//タイトル
	title,
	//ゲームプレイ
	game,
};
class Title;
class Game;
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	
	/// <summary>
	/// タイトル
	/// </summary>
	void TitleMove();
	
	/// <summary>
	/// ゲーム
	/// </summary>
	void GameMove();




private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	static void (GameScene::*pFuncTable[])();
	Scene scene = Scene::title;
	std::unique_ptr<Game> game;
	std::unique_ptr<Title> title;



	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
