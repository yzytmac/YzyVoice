package com.example.yzyvoice;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;

import org.fmod.FMOD;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;

public class QQActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		FMOD.init(this);
		setContentView(R.layout.activity_main);
	}

	public void mFix(final View btn) {
		final String path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "test.mp3";// 根目录海阔天空mp3
		new Thread(new Runnable() {
			@Override
			public void run() {
				// TODO Auto-generated method stub
				switch (btn.getId()) {
				case R.id.btn_normal:
					EffectUtils.fix(path, EffectUtils.MODE_NORMAL);
					break;

				case R.id.btn_luoli:
					EffectUtils.fix(path, EffectUtils.MODE_LUOLI);
					break;

				case R.id.btn_dashu:
					EffectUtils.fix(path, EffectUtils.MODE_DASHU);
					break;

				case R.id.btn_jingsong:
					EffectUtils.fix(path, EffectUtils.MODE_JINGSONG);
					break;

				case R.id.btn_gaoguai:
					EffectUtils.fix(path, EffectUtils.MODE_GAOGUAI);
					break;

				case R.id.btn_kongling:
					EffectUtils.fix(path, EffectUtils.MODE_KONGLING);
					break;

				default:
					break;
				}
			}
		}).start();
		
	}

	@Override
	protected void onDestroy() {
		super.onDestroy();
		FMOD.close();
	}

}
