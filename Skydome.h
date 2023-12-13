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
class Skydome {
private:
	WorldTransform worldTransform_;
	std::unique_ptr<Model> model_ = nullptr;


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
	void Draw3D(ViewProjection &viewProjection);




};
