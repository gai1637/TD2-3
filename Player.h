#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
class Player {
private:
	WorldTransform worldTransform_;
	Model* modelHead_;
	Model* modelBody_;
	Model* modelRArm_;
	Model* modelLArm_;
	Model* modelRFoot_;
	Model* modelLFoot_;



public:
	~Player();
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



};
