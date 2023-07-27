#include <DxLib.h>

//ストップタイマー
int time;
//破壊ブロック
int block[10] = {};
//配列の数
int blocknum=0;
//LEFT,RIGHTキーで選択操作するときのインクリメントの奴
int selectnumx;
//UP,DOWNキーで選択操作するときのインクリメントの奴
int selectnumy;

//A,Dキーで棒を動かすときのインクリメントの奴
int idoux;
//W,Sキーで棒を動かすときのインクリメントの奴
int idouy;

//円１の中心座標ｘ
int r1x;
//円から四角にするとき使う
int r1x_2;
//円２の中心座標ｘ
int r2x;
//円１の中心座標ｙ
int r1y;
//円から四角にするとき
int r1y_2;
//円２の中心座標ｙ
int r2y;
//辺Aの二乗の値
int a;
//二乗（四角
int a_2;
//辺Bの二乗の値
int b;
//二乗（四角
int b_2;
//辺Cの二乗の値
int c;
//二乗（四角
int c_2;
//円１の半径
int radius1;
//円２の半径
int radius2;
//円１、２の合計半径、二乗を忘れずに
int sumradius;

//四角(左辺
int left[10] = {};
//四角（右辺
int right[10] = {};
//四角（上辺
int top[10] = {};
//四角（下辺
int bottom[10] = {};

//現在の棒ｘ座標（左
int ba1;
//現在の棒ｘ座標（右
int ba2;
//棒の長さを変える（左
int sumba1;
//棒の長さを変える（右
int sumba2;


//ボール初期位置ｘ
////ボール初期位置
		//fballx=400+idoux*10
		//fbally=380+idouy*10
int fballx;
//ボール初期位置ｙ
////ボール初期位置
		//fballx=400+idoux*10
		//fbally=380+idouy*10
int fbally;
//ボール現在位置ｘ
int ballx;
//ボール現在位置ｙ
int bally;
//ボールを動かす距離ｘ
int ballxidou;
//ボールを動かす距離ｙ
int ballyidou;



//±反転させる用（長さ）	
int wan;
//±反転用（棒の動き
int wan2;
//±反転させる用ｘ（ボール）
int ballwan;
//±反転させる用ｙ（ボール）
int ballwan2;

bool stop = false;

//灰色
int ash;
//白色
int white;
//黄色
int yellow;
//青色
int blue;
//色、三種
int color[3] = {};
//色三種の数字
int iro;
//色を一個ずつ変える用
int irostop;

//ページ
int Page;
//一ページずつ
int Stop;
//UP、DOWNの奴、わかってない、
int Stop2;
//エンターを止めてるときに使う
int stop2;



//ページa50から５０ページになってます。
enum {
	a0,
	a1,
	a2,
	a3,
	a4,
	a5_2,
	a5,
	a6,
	a7,
	a8,
	a9,
	a10,
	a11,
	a12,
	a13,
	a14,
	a15,
	a16,
	a17,
	a18,
	a19,
	a20,
//選択画面
	a50=50,
	a51,
	a52,
	a53,
	a54,
	a55,
	a56,
	a57,
	a58,
	a59,
	a60,
};

//円の当たり判定です。
void Circle()
{
	//当たり判定（円）
	a = r1x - r2x;
	b = r2y - r1y;
	c = a * a + b * b;
	sumradius = radius1 + radius2;

	////当たり判定テンプレ←ここは値をいれるだけ
	//r1x = ;
	//r1y = ;
	//r2x = ;
	//r2y = ;
	//radius1 = ;
	//radius2 = ;
	//Circle();
}

void square()
{
	/*left[0]=;
	right[0]=;
	top[0]=;
	bottom[0]=;
	left[1]=;
	right[1]=;
	top[1]=;
	bottom[1]=;*/
}

//（おそらく四角vs四角の当たり判定）
void Circle2()
{
	//四角と丸のつもり（たぶん四角と四角になってる）
	a = r1x - r2x;
	a_2 = r1x_2 - r2x;
	b = r2y - r1y;
	b_2 = r2y - r1y_2;
	c = a * a + b * b;
	c_2 = a_2 * a_2 + b_2 * b_2;
	sumradius = radius1 + radius2;

	////当たり判定テンプレ
	//r1x = ;
	//r1x_2 = ;
	//r1y = ;
	//r1y_2 = ;
	//r2x = ;
	//r2y = ;
	//radius1 = ;
	//radius2 = ;
	//Circle2();
	//r1x<r2x + radius2 && r1x_2>r2x - radius2 && r1y<r2y + radius2 && r1y_2>r2y - radius2
	// 
	//当たり判定テンプレ例
	/*r1x = ba1;
	r1x_2 = ba2;
	r1y = 390;
	r1y_2 = 410;
	r2x = ballx;
	r2y = bally;
	radius1 = 10;
	radius2 = 10;
	Circle2();
	r1x<r2x + radius2 && r1x_2>r2x - radius2 && r1y<r2y + radius2 && r1y_2>r2y - radius2*/
}

//移動制限（棒、ボール）
void Seigen()
{
	//バー制限
	if (ba1 < 0)
	{
		//インクリメントを止める
		wan2 = 0;
		//インクリメント復帰
		if (CheckHitKey(KEY_INPUT_D) == 1)
		{
			wan2 = 1;
		}
	}
	if (ba2 > 1024)
	{
		//インクリメントを止める
		wan2 = 0;
		//インクリメント復帰
		if (CheckHitKey(KEY_INPUT_A) == 1)
		{
			wan2 = 1;
		}
	}
	//ball制限（ifで±を反転）
	if (ballx > 1024)
	{
		ballwan = -ballwan;
	}
	if (ballx < 0)
	{
		ballwan = -ballwan;
	}
	if (bally > 768)
	{
		ballwan2 = -ballwan2;
	}
	if (bally < 0)
	{
		ballwan2 = -ballwan2;
	}
}
//位置の初期化
void Iti()
{
	if (CheckHitKey(KEY_INPUT_NUMPAD0) == 1)
	{
		idoux = 0;
		idouy = 0;
		ballxidou = 0;
		ballyidou = 0;
		fballx = 512;
		fbally = 564;
	}

	time = 240;

	idoux = 0;
	idouy = 0;
	ballxidou = 0;
	ballyidou = 0;
	fballx = 512;
	fbally = 564;
	wan2 = 1;
	for (int i = 0; i < 10; i++)
	{
		block[i] = 0;
	}
}
//最初に1回呼ばれる処理
void Start()
{
	
	wan = 1;
	wan2 = 1;

	ballwan = 1;
	ballwan2 = 1;
	


	Page = 0;//0ページ目からストーリーを進める
	Stop = 0;//0は止めない、1は止める
	Stop2 = 0;
	stop2 = 0;
	ba1 = 0;
	ba2 = 0;
	
	fballx = 0;
	fbally = 0;

	selectnumx = 0;
	selectnumy = 0;

	time = 240;



	
	// 描画する文字列のサイズを設定
	SetFontSize(24);


	ash = GetColor(200, 200, 200);//灰色
	white = GetColor(255, 255, 255);//白
	yellow = GetColor(255,255, 0);//黄
	blue = GetColor(0, 255, 255);//青
	color[0] = GetColor(100, 100, 100);//kaeru
	color[1] = GetColor(255, 0, 0);
	color[2] = GetColor(0, 255, 0);


	iro = 0;
	irostop = 0;


}


//毎フレーム呼ばれる処理
void Update()
{

	
	//キーを押してページをめくる処理
	//エンターキー(KEY_INPUT_RETURN)が押されたらページを進める
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 && Stop == 0)
	{
		Page++;
		Stop = 1;
		stop2 = 1;
	}
	//Stop、stop２有効化
	if (CheckHitKey(KEY_INPUT_RETURN) == 0&&CheckHitKey(KEY_INPUT_UP)==0 && CheckHitKey(KEY_INPUT_DOWN) == 0)
	{
		Stop = 0;
		stop2 = 0;
	}
	//Stop2有効化
	if ( CheckHitKey(KEY_INPUT_UP) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 0 && CheckHitKey(KEY_INPUT_LEFT) == 0)
	{
		Stop2 = 0;
	}
	//WASDキー有効化
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		idouy -= wan2;
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		idouy+=wan2;
	}if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		idoux-=wan2;
	}if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		idoux+=wan2;
	}
	//UP,DOWNキー有効化
	if (CheckHitKey(KEY_INPUT_UP) == 1 && Stop2 == 0)
	{
		selectnumy--;
		Stop2 = 1;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1 && Stop2 == 0)
	{
		selectnumy++;
		Stop2 = 1;
	}
	//右左キー有効化
	if (CheckHitKey(KEY_INPUT_LEFT) == 1 && Stop2 == 0)
	{
		selectnumx--;
		Stop2 = 1;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && Stop2 == 0)
	{
		selectnumx++;
		Stop2 = 1;
	}

	//1Page（タイトル
	if (Page == a0)
	{
		DrawFormatString(200, 300, GetColor(255, 255, 255), "Enterを押してStart\n");
	}
	//棒びよんびよん
	if (Page == a1)
	{
		//１ページ進めない
		Stop = 1;
		//棒長さ変更インクリメント
		ba1 -= wan;
		ba2 += wan;
		//バー初期位置x(ba1,ba2)y(390,410)
		DrawBox(sumba1=412+ba1*10, 574, sumba2 =612+ba2*10, 594, white, true);
		//文字
		DrawFormatString(200, 100, GetColor(255, 255, 255), "長さをエンターで決定！");
		
		//棒長さ変更の制限
		if (sumba1 < 312)
		{
			wan = -wan;
		}
		if (sumba1 > 412)
		{
			wan = -wan;
		}

		//ページ５０に飛ぶ
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 &&stop2==0)
		{
			Page = a50;
			stop2 = 1;
		}

	}
	//チュートリアル
	if (Page ==a2)
	{
		//文字
		DrawFormatString(200, 100, white, "A、Dキーで左右に移動できるぞ！");
		//バーの動いている初期位置
		DrawBox(ba1=sumba1 + idoux * 10, 574,ba2=sumba2 + idoux * 10, 594, white, true);
		//棒の移動制限（左
		if (ba1 < 0)
		{
			wan2 = 0;
			//復帰
			if (CheckHitKey(KEY_INPUT_D) == 1)
			{
				wan2 = 1;
			}
		}
		//棒の移動制限（右
		if (ba2 > 1024)
		{
			wan2 = 0;
			//復帰
			if (CheckHitKey(KEY_INPUT_A) == 1)
			{
				wan2 = 1;
			}
		}
	}
	//ボールあるだけ
	if (Page == a3)
	{
		DrawFormatString(200, 100, white, "移動したらスタート");
		DrawBox(ba1 = sumba1 + idoux * 10, 574, ba2 = sumba2 + idoux * 10, 594, white, true);
		//A、Dを押したら次ページへ
		if (CheckHitKey(KEY_INPUT_D) == 1 || CheckHitKey(KEY_INPUT_A) == 1)
		{
			Page++;
		}
		DrawCircle(fballx=512+idoux*10, fbally=564+idouy*10, 10, yellow, true);
		//ボール初期位置
		//fballx=512+idoux*10
		//fbally=564+idouy*10
	}
	//ボール動く
	if (Page == a4)
	{
		
		DrawFormatString(300, 100, ash, "エンターで次へ");

		//バーの動き
		DrawBox(ba1 = sumba1 + idoux * 10, 574, ba2 = sumba2 + idoux * 10, 594, white, true);

		//ボールの動き
		if (stop == false) {
			ballxidou -= ballwan;
			ballyidou -= ballwan2;
		}
		DrawCircle(ballx = fballx + ballxidou * 12, bally = fbally + ballyidou * 6, 10, yellow, true);

		//当たり判定テンプレ
		r1x = ba1;
		r1x_2 = ba2;
		r1y = 574;
		r1y_2 = 594;
		r2x = ballx;
		r2y = bally;
		radius1 = 10;
		radius2 = 10;
		Circle2();
		/*Circle2();
		if (c < sumradius * sumradius || c_2 < sumradius * sumradius)
		{
			ballwan2=- ballwan2;
			ballwan = -ballwan;
		}*/

		
		if (r1x<ballx + radius2 && r1x_2>ballx - radius2 && r1y<bally + radius2 && r1y_2>bally - radius2)
		{
			ballwan2 = -ballwan2;
			if (c < sumradius * sumradius || c_2 < sumradius * sumradius)
			{
				ballwan = -ballwan;
			}
		}


		//ここから
		if (CheckHitKey(KEY_INPUT_NUMPAD3) == 1)
		{
			stop = true;
		}
		else
		{
			stop = false;
		}
		//ここまで
		//おそらくバグの原因です
		
		

		//制限
		Seigen();
	}
	if (Page == a5_2)
	{
		Iti();
		DrawCircle(400, 50, 50, color[iro], true);
		DrawCircle(600, 50, 50, color[iro], true);
		DrawCircle(200, 50, 50, color[iro], true);
		DrawBox(ba1 = sumba1 + idoux * 10, 574, ba2 = sumba2 + idoux * 10, 594, white, true);
		DrawCircle(ballx = fballx + ballxidou * 12, bally = fbally + ballyidou * 6, 10, yellow, true);
		if (CheckHitKey(KEY_INPUT_A) == 1 || CheckHitKey(KEY_INPUT_D) == 1)
		{
			Page++;
		}
	}
	//敵あり
	if (Page == a5)
	{
		/*DrawCircle(400, 50, 50, color[iro], true);*/
		/*DrawCircle(600, 50, 50, color[iro], true);*/
		/*DrawCircle(200, 50, 50, color[iro], true);*/

		
		//バーの動き
		DrawBox(ba1 = sumba1 + idoux * 10, 574, ba2 = sumba2 + idoux * 10, 594, white, true);

		//ボールの動き
		ballxidou -= ballwan;
		ballyidou -= ballwan2;
	
		DrawCircle(ballx = fballx + ballxidou * 12, bally = fbally + ballyidou * 6, 10, yellow, true);
		//制限
		Seigen();
		if (bally > 768)
		{
			Page = a50;
		}
	
		//当たり判定
		r1x = ballx;
		r1y = bally;
		r2x = 400;
		r2y = 50;
		radius1 = 10;
		radius2 = 50;
		Circle();

		if (block[0] == 0)
		{
			DrawCircle(400, 50, 50, color[iro], true);
			if (c < sumradius * sumradius && irostop == 0)
			{
				iro++;
				ballwan2 = -ballwan2;
				ballwan = -ballwan;
				if (iro == 3)
				{
					iro = 0;
				}
				irostop = 1;
				/*Page = a6;*/
				block[0]++;
			}
		}
		//当たり判定
		r1x = ballx;
		r1y = bally;
		r2x = 600;
		r2y = 50;
		radius1 = 10;
		radius2 = 50;
		Circle();
		if (block[1] == 0)
		{
			DrawCircle(600, 50, 50, color[iro], true);
			if (c < sumradius * sumradius && irostop == 0)
			{
				iro++;
				ballwan2 = -ballwan2;
				ballwan = -ballwan;
				if (iro == 3)
				{
					iro = 0;
				}
				irostop = 1;
				block[1]++;
			}
			
		}
		
		if (c > sumradius * sumradius)
		{
			irostop = 0;
		}
		//当たり判定
		r1x = ballx;
		r1y = bally;
		r2x = 200;
		r2y = 50;
		radius1 = 10;
		radius2 = 50;
		Circle();
		if (block[2] == 0)
		{
			DrawCircle(200, 50, 50, color[iro], true);
			if (c < sumradius * sumradius && irostop == 0)
			{
				iro++;
				ballwan2 = -ballwan2;
				ballwan = -ballwan;
				if (iro == 3)
				{
					iro = 0;
				}
				irostop = 1;
				block[2]++;
			}
			
		}
		
		if (c > sumradius * sumradius)
		{
			irostop = 0;
		}
		
		r1x = ba1;
		r1x_2 = ba2;
		r1y = 574;
		r1y_2 = 594;
		r2x = ballx;
		r2y = bally;
		radius1 = 10;
		radius2 = 10;
		Circle2();
		if (c < sumradius * sumradius || c_2 < sumradius * sumradius)
		{
			ballwan2 = -ballwan2;
			ballwan = -ballwan;
		}
		if (r1x<ballx + radius2 && r1x_2>ballx - radius2 && r1y<bally + radius2 && r1y_2>bally - radius2)
		{
			ballwan2 = -ballwan2;
		}

		if (block[0] == 1 && block[1] == 1 && block[2] == 1)
		{
			Page = a10;
		}
	}

	if (Page == a6)
	{
		DrawFormatString(100, 100, white, "未完");
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 && stop2 == 0)
		{
			Page = a50;
			stop2 = 1;
		}
		Stop = 1;
	}
	if (Page == a7)
	{

	}
	
	if (Page == a10)
	{
		DrawFormatString(350, 300, white, "クリア！", true);
		time--;
		DrawFormatString(400, 400, white, "残り%d秒", time/60);
		if (time < 30|| CheckHitKey(KEY_INPUT_RETURN) == 1)
		{
			Page = a50;
			stop2 = 1;
		}
		Stop = 1;
	}

	if (Page == a50)
	{
		DrawBox(312,100,712,200,white,false);
		DrawBox(124, 568, 324, 668, white, false);
		DrawBox(724, 568, 924, 668, white , false);
		DrawFormatString(455, 140, white, "ゲーム選択");
		DrawFormatString(135, 610, white, "チュートリアル");
		DrawFormatString(775, 610, white, "ゲームへ");

		DrawBox(714+selectnumx*600, 558, 934+selectnumx*600, 678, yellow, false);
		//select制限
		if (selectnumx <= -1)
		{
			selectnumx = -1;
		}else
		if (selectnumx >= 0)
		{
			selectnumx = 0;
		}

		if (selectnumx == -1)
		{
			if (CheckHitKey(KEY_INPUT_RETURN) == 1&& stop2==0)
			{
				Page = a2;
				stop2 = 1;
			}
		}
		if (selectnumx == 0)
		{
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && stop2 == 0)
			{
				Page = a51;/*Page =a5_2;*/
				stop2 = 1;
			}
		}

		Stop = 1;
		Iti();
	}

	if (Page == a51)
	{
		DrawFormatString(400, 100, white, "ステージを選択しよう");
		DrawBox(114, 200, 227, 300, white, false);
		DrawFormatString(150, 235, white, "1-1");
		DrawBox(340, 200, 453, 300, white, false);
		DrawFormatString(376, 235, white, "1-2");
		/*113  36*/

		DrawBox(104+selectnumx*226, 190+selectnumy*200, 237+selectnumx*226, 310+selectnumy*200, yellow, false);
		
		
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 && stop2==0)
		{
			if (selectnumx == 0 && selectnumy == 0)
			{
				Page = a5_2;
				
			}
			if (selectnumx==1&&selectnumy==0)
			{
				Page = a6;
			}
			stop2 = 1;
		}
		Stop = 1;
	}
	
	
}
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);	//ウィンドウモードにする
	SetGraphMode(1024, 768, 32);	
	/*SetGraphMode(800, 600, 32);*///ウィンドウサイズを設定する

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ

	Start();//最初に１回呼ぶ
	
	//メイン処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && CheckHitKey(KEY_INPUT_DECIMAL)== 0) {

		Update();//毎回呼ぶ

		ScreenFlip();		//裏画面と表画面の入替
		ClearDrawScreen();	//裏画面の描画を全て消去
	}

	

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

