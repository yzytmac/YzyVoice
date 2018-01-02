#include "com_example_yzyvoice_EffectUtils.h"
#include "fmod.hpp"
#include <stdlib.h>
#include <unistd.h>
#include <android/log.h>
#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"yzy",FORMAT,##__VA_ARGS__);
#define LOGE(FORMAT,...) __android_log_print(ANDROID_LOG_ERROR,"yzy",FORMAT,##__VA_ARGS__);

#define MODE_NORMAL 0
#define MODE_LUOLI 1
#define MODE_DASHU 2
#define MODE_JINGSONG 3
#define MODE_GAOGUAI 4
#define MODE_KONGLING 5

using namespace FMOD;

/*
 * Class:     com_example_yzyvoice_EffectUtils
 * Method:    fix
 * Signature: (Ljava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_com_example_yzyvoice_EffectUtils_fix(JNIEnv *env,
		jclass clazz, jstring path, jint type) {

	System *system;
	Sound *sound;
	Channel *channel;
	DSP *dsp;
	bool playing = true;
	float frequency = 0;

	const char* path_cstr = env->GetStringUTFChars(path, NULL);
	LOGE("%s", path_cstr);
	try {
		//初始化
		System_Create(&system);
		system->init(32, FMOD_INIT_NORMAL, NULL);

		//创建声音
		system->createSound(path_cstr, FMOD_DEFAULT, NULL, &sound);
		switch (type) {
		case MODE_NORMAL:
			//原生播放
			system->playSound(sound, 0, false, &channel);
			LOGE("%s", "fix normal");
			break;
		case MODE_LUOLI:
			//萝莉
			//DSP digital signal process
			//dsp -> 音效 创建fmod中预定义好的音效
			//FMOD_DSP_TYPE_PITCHSHIFT dsp，提升或者降低音调用的一种音效
			system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
			//设置音调的参数
			dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 2.5);

			system->playSound(sound, 0, false, &channel);
			//添加到channel
			channel->addDSP(0, dsp);
			LOGE("%s", "fix luoli");
			break;

		case MODE_JINGSONG:
			//惊悚
			system->createDSPByType(FMOD_DSP_TYPE_TREMOLO, &dsp);
			dsp->setParameterFloat(FMOD_DSP_TREMOLO_SKEW, 0.5);
			system->playSound(sound, 0, false, &channel);
			channel->addDSP(0, dsp);

			break;
		case MODE_DASHU:
			//大叔
			system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
			dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 0.8);

			system->playSound(sound, 0, false, &channel);
			//添加到channel
			channel->addDSP(0, dsp);
			LOGE("%s", "fix dashu");
			break;
		case MODE_GAOGUAI:
			//搞怪
			//提高说话的速度
			system->playSound(sound, 0, false, &channel);
			channel->getFrequency(&frequency);
			frequency = frequency * 1.6;
			channel->setFrequency(frequency);
			LOGE("%s", "fix gaoguai");
			break;
		case MODE_KONGLING:
			//空灵
			system->createDSPByType(FMOD_DSP_TYPE_ECHO, &dsp);
			dsp->setParameterFloat(FMOD_DSP_ECHO_DELAY, 300);
			dsp->setParameterFloat(FMOD_DSP_ECHO_FEEDBACK, 20);
			system->playSound(sound, 0, false, &channel);
			channel->addDSP(0, dsp);
			LOGE("%s", "fix kongling");
			break;

		default:
			break;
		}
	} catch (...) {
		LOGE("%s", "发生异常");
		goto end;
	}
	system->update();

	//释放资源
	//单位是微秒
	//每秒钟判断下是否在播放
	while (playing) {
		channel->isPlaying(&playing);
		usleep(1000 * 1000);
	}
	goto end;
	end: env->ReleaseStringUTFChars(path, path_cstr);
	sound->release();
	system->close();
	system->release();

}
;
