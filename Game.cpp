#include "Game.h"
//#include"Skydome.h"
void Game::Initialize() {
	skydome_ = std::make_unique<Skydome>();
	skydome_->Initialize();
	input_ = Input::GetInstance();
	viewProjection_.translation_.x = 0;
	viewProjection_.translation_.y = -11;
	viewProjection_.translation_.z = -60;
	viewProjection_.farZ = 2000;
	viewProjection_.Initialize();
}
void Game::Update() { 
	/*skydome_->Update(); */
}
void Game::Draw3D() { skydome_->Draw3D(viewProjection_); }