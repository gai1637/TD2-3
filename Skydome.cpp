#include "Skydome.h"

void Skydome::Initialize() { 
	worldTransform_.Initialize(); 
	model_ = std::make_unique<Model>();
	model_.reset(Model::CreateFromOBJ("skydome", true));
	
}
void Skydome::Update() {/* worldTransform_.UpdateMatrix();*/ }
void Skydome::Draw3D(ViewProjection &viewProjection) { 
	model_->Draw(worldTransform_, viewProjection);
}