#pragma once
class Game {
private:




public:
	~Game();
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
