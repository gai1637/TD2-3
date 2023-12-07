#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include"Title.h"
#include"Game.h"
#include"Select.h"

GameScene::GameScene() {}

GameScene::~GameScene() {}

void (GameScene::*GameScene::pFuncTable[])() = {
	&GameScene::TitleMove,
	&GameScene::SelectMove,
	&GameScene::GameMove

};
void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	game = std::make_unique<Game>();
	game->Initialize();

	title = std::make_unique<Title>();
	title->Initialize();

	select = std::make_unique<Select>();
	select->Initialize();


}
//ここには触るな、触りたいなら言ってくれ
void GameScene::Update() { 
	(this->*pFuncTable[static_cast<size_t>(scene)])(); 

}
//あまり触るな
void GameScene::TitleMove() { 
	title->Update();
}
//ここも
void GameScene::GameMove() { 
	game->Update(); 
}

void GameScene::SelectMove() { select->Update(); }

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>
	if (scene == Scene::title) {
		title->Draw2D();
	}
	if (scene == Scene::game) {
		game->Draw2D();
	}
	if (scene == Scene::select) {
		select->Draw2D();
	}

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	if (scene == Scene::title) {
		title->Draw3D();
	}
	if (scene == Scene::game) {
		game->Draw3D();
	}
	if (scene == Scene::select) {
		select->Draw3D();
	}

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>
	 if (scene == Scene::title) {
		title->Draw2DNear();
	}
	if (scene == Scene::game) {
		game->Draw2DNear();
	}
	if (scene == Scene::select) {
		select->Draw2DNear();
	}

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
