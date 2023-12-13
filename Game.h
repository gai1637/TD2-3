#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include<memory>
#include"Skydome.h"
//class Skydome;
class Game {
private:
	std::unique_ptr<Skydome> skydome_;
	Input* input_ = nullptr;
	ViewProjection viewProjection_;

public:
	
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 3D描画
	/// </summary>
	void Draw3D();

	/// <summary>
	/// 2D前景描画
	/// </summary>
	void Draw2DNear();

	/// <summary>
	/// 2D背景描画
	/// </summary>
	void Draw2D();

};
