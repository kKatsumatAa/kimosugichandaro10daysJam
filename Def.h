#pragma once

class SetDef
{
private:
	// ウィンドウのタイトルに表示する文字列
	const char* TITLE = "キモスギチャン";

	// ウィンドウ横幅
	const int WIN_WIDTH = 1980;

	// ウィンドウ縦幅
	const int WIN_HEIGHT = 1080;

	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言

public:
	//set用関数
	int Set();
};