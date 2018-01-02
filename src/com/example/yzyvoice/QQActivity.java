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
import android.widget.EditText;

public class QQActivity extends Activity {
	private EditText nameET;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		FMOD.init(this);
		setContentView(R.layout.activity_main);
		nameET = (EditText) findViewById(R.id.id_et);
		nameET.setText("海阔天空.mp3");// 根目录海阔天空.mp3
	}

	public void mFix(final View btn) {
		String nameString = nameET.getText().toString();
		final String path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + nameString;// 根目录海阔天空mp3
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
