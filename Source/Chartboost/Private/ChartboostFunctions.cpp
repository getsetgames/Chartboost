//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "ChartboostPrivatePCH.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJNI.h"
#include "AndroidApplication.h"

#define INIT_JAVA_METHOD(name, signature) \
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) { \
	name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
	check(name != NULL); \
} else { \
	check(0); \
}

#define DECLARE_JAVA_METHOD(name) \
static jmethodID name = NULL;

DECLARE_JAVA_METHOD(AndroidThunkJava_Chartboost_StartWithAppID);
DECLARE_JAVA_METHOD(AndroidThunkJava_Chartboost_HasRewardedVideo);
DECLARE_JAVA_METHOD(AndroidThunkJava_Chartboost_ShowRewardedVideo);
DECLARE_JAVA_METHOD(AndroidThunkJava_Chartboost_CacheRewardedVideo);

void UChartboostFunctions::InitJavaFunctions()
{
	INIT_JAVA_METHOD(AndroidThunkJava_Chartboost_StartWithAppID, "(Ljava/lang/String;Ljava/lang/String;)V");
	INIT_JAVA_METHOD(AndroidThunkJava_Chartboost_HasRewardedVideo, "(Ljava/lang/String;)Z");
	INIT_JAVA_METHOD(AndroidThunkJava_Chartboost_ShowRewardedVideo, "(Ljava/lang/String;)V");
	INIT_JAVA_METHOD(AndroidThunkJava_Chartboost_CacheRewardedVideo, "(Ljava/lang/String;)V");
}
#undef DECLARE_JAVA_METHOD
#undef INIT_JAVA_METHOD

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeCbWillDisplayVideo(String location);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeCbWillDisplayVideo(JNIEnv* jenv, jobject thiz, jstring locationString)
{
	const char* javaChars = jenv->GetStringUTFChars(locationString, 0);

	FString Location = FString(UTF8_TO_TCHAR(javaChars));
	//Release the string
	jenv->ReleaseStringUTFChars(locationString, javaChars);

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]() 
		{
			UChartboostComponent::WillDisplayVideoDelegate.Broadcast(Location);
		}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
	);
}

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeCbDidCloseRewardedVideo(String location);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeCbDidCloseRewardedVideo(JNIEnv* jenv, jobject thiz, jstring locationString)
{
	const char* javaChars = jenv->GetStringUTFChars(locationString, 0);

	FString Location = FString(UTF8_TO_TCHAR(javaChars));
	//Release the string
	jenv->ReleaseStringUTFChars(locationString, javaChars);

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
		{
			UChartboostComponent::DidCloseRewardedVideoDelegate.Broadcast(Location);
		}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
	);
}

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeCbDidCompleteRewardedVideo(String location, int reward);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeCbDidCompleteRewardedVideo(JNIEnv* jenv, jobject thiz, jstring locationString, jint reward)
{
	const char* javaChars = jenv->GetStringUTFChars(locationString, 0);

	FString Location = FString(UTF8_TO_TCHAR(javaChars));
	//Release the string
	jenv->ReleaseStringUTFChars(locationString, javaChars);

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
		{
			UChartboostComponent::DidCompleteRewardedVideoDelegate.Broadcast(Location, reward);
		}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
	);
}


#elif PLATFORM_IOS

@interface CBDelegate : NSObject <ChartboostDelegate>

@end

static CBDelegate *CBDelegateSingleton = [[CBDelegate alloc] init];

#endif

void UChartboostFunctions::ChartboostStart(FString AppId, FString AppSignature)
{
	const UChartboostSettings* DefaultSettings = GetDefault<UChartboostSettings>();
	
	// initialize iOS
#if PLATFORM_IOS
	
	 dispatch_async(dispatch_get_main_queue(), ^{
		  [Chartboost startWithAppId:AppId.GetNSString()
							 appSignature:AppSignature.GetNSString()
								  delegate:CBDelegateSingleton];
		  
		  [Chartboost setAutoCacheAds:DefaultSettings->AutoCacheAds];
		  [Chartboost setShouldRequestInterstitialsInFirstSession:DefaultSettings->FirstSessionInterstitials];
		  [Chartboost setShouldDisplayLoadingViewForMoreApps:DefaultSettings->MoreAppsLoadingView];
		  [Chartboost setShouldPrefetchVideoContent:DefaultSettings->PrefetchVideoContent];
		  [Chartboost setShouldPauseClickForConfirmation:DefaultSettings->PauseForAgeGate];
	 });
	
#elif PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		jstring AppIDArg = Env->NewStringUTF(TCHAR_TO_UTF8(*AppId));
		jstring AppSignatureArg = Env->NewStringUTF(TCHAR_TO_UTF8(*AppSignature));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Chartboost_StartWithAppID, AppIDArg, AppSignatureArg);

		Env->DeleteLocalRef(AppIDArg);
		Env->DeleteLocalRef(AppSignatureArg);

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method startWithAppID\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}

bool UChartboostFunctions::ChartboostAdIsVisible() {
#if PLATFORM_IOS
	return [Chartboost isAnyViewVisible];
#endif

	return false;
}

void UChartboostFunctions::ChartboostSetAgeGatePassed(bool pass) {
#if PLATFORM_IOS
	[Chartboost didPassAgeGate:pass];
#endif
}

void UChartboostFunctions::ChartboostSetCustomId(FString customId) {
#if PLATFORM_IOS
	[Chartboost setCustomId:customId.GetNSString()];
#endif
}

FString UChartboostFunctions::ChartboostGetCustomId() {
#if PLATFORM_IOS
	return FString([Chartboost getCustomId]);
#endif
	
	return FString();
}

bool UChartboostFunctions::ChartboostHasInterstitial(FString Location) {
	if (Location.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	return [Chartboost hasInterstitial:Location.GetNSString()];
#endif
	
	return false;
}

void UChartboostFunctions::ChartboostShowInterstitial(FString Location) {
	if (Location.IsEmpty()) {
		return;
	}
	
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	UE_LOG(LogChartboost, Log, TEXT("Showing interstitial for location: %s"), *Location);
#endif

	
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[Chartboost showInterstitial:Location.GetNSString()];
	});
#endif
}

void UChartboostFunctions::ChartboostCacheInterstitial(FString Location) {
	if (Location.IsEmpty()) {
		return;
	}
	
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	UE_LOG(LogChartboost, Log, TEXT("Caching interstitial for location: %s"), *Location);
#endif
	
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[Chartboost cacheInterstitial:Location.GetNSString()];
	});
#endif
}

bool UChartboostFunctions::ChartboostHasMoreApps(FString Location) {
	if (Location.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	return [Chartboost hasMoreApps:Location.GetNSString()];
#endif
	
	return false;
}

void UChartboostFunctions::ChartboostShowMoreApps(FString Location) {
	if (Location.IsEmpty())
	{
		return;
	}
	
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	UE_LOG(LogChartboost, Log, TEXT("Showing more apps for location: %s"), *Location);
#endif
	
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[Chartboost showMoreApps:Location.GetNSString()];
	});
#endif
}

void UChartboostFunctions::ChartboostCacheMoreApps(FString Location) {
	if (Location.IsEmpty()) {
		return;
	}
	
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	UE_LOG(LogChartboost, Log, TEXT("Caching more apps for location: %s"), *Location);
#endif
	
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[Chartboost cacheMoreApps:Location.GetNSString()];
	});
#endif
}

bool UChartboostFunctions::ChartboostHasRewardedVideo(FString Location) {
	if (Location.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	return [Chartboost hasRewardedVideo:Location.GetNSString()];
#elif PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		jstring LocationArg = Env->NewStringUTF(TCHAR_TO_UTF8(*Location));

		bool ret = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Chartboost_HasRewardedVideo, LocationArg);

		Env->DeleteLocalRef(LocationArg);

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method ChartboostHasRewardedVideo\n"));

		return ret;
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
	
	return false;
}

void UChartboostFunctions::ChartboostShowRewardedVideo(FString Location) {
	if (Location.IsEmpty()) return;
	
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	UE_LOG(LogChartboost, Log, TEXT("Showing rewarded video for location: %s"), *Location);
#endif
	
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[Chartboost showRewardedVideo:Location.GetNSString()];
	});
#elif PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		jstring LocationArg = Env->NewStringUTF(TCHAR_TO_UTF8(*Location));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Chartboost_ShowRewardedVideo, LocationArg);

		Env->DeleteLocalRef(LocationArg);

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method ChartboostShowRewardedVideo\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}

void UChartboostFunctions::ChartboostCacheRewardedVideo(FString Location) {
	if (Location.IsEmpty()) {
		return;
	}
	
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	UE_LOG(LogChartboost, Log, TEXT("Caching rewarded video for location: %s"), *Location);
#endif
	
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[Chartboost cacheRewardedVideo:Location.GetNSString()];
	});
#elif PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		jstring LocationArg = Env->NewStringUTF(TCHAR_TO_UTF8(*Location));

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Chartboost_CacheRewardedVideo, LocationArg);

		Env->DeleteLocalRef(LocationArg);

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method ChartboostCacheRewardedVideo\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}

#if PLATFORM_IOS
@implementation CBDelegate

// interstitials

- (void)didDisplayInterstitial:(CBLocation)location {
	UChartboostComponent::DidDisplayInterstitialDelegate.Broadcast(FString(location));
}

- (void)didCacheInterstitial:(CBLocation)location {
	UChartboostComponent::DidCacheInterstitialDelegate.Broadcast(FString(location));
}

- (void)didFailToLoadInterstitial:(CBLocation)location withError:(CBLoadError)error {
	UChartboostComponent::DidFailToLoadInterstitialDelegate.Broadcast(FString(location), (EChartboostLoadError::LoadError)error);
}

- (void)didFailToRecordClick:(CBLocation)location withError:(CBClickError)error {
	UChartboostComponent::DidFailToRecordClickDelegate.Broadcast(FString(location), (EChartboostClickError::ClickError)error);
}

- (void)didDismissInterstitial:(CBLocation)location {
	UChartboostComponent::DidDismissInterstitialDelegate.Broadcast(FString(location));
}

- (void)didCloseInterstitial:(CBLocation)location {
	UChartboostComponent::DidCloseInterstitialDelegate.Broadcast(FString(location));
}

- (void)didClickInterstitial:(CBLocation)location {
	UChartboostComponent::DidClickInterstitialDelegate.Broadcast(FString(location));
}

// more apps

- (void)didDisplayMoreApps:(CBLocation)location {
	UChartboostComponent::DidDisplayMoreAppsDelegate.Broadcast(FString(location));
}

- (void)didCacheMoreApps:(CBLocation)location {
	UChartboostComponent::DidCacheMoreAppsDelegate.Broadcast(FString(location));
}

- (void)didDismissMoreApps:(CBLocation)location {
	UChartboostComponent::DidDismissMoreAppsDelegate.Broadcast(FString(location));
}

- (void)didCloseMoreApps:(CBLocation)location {
	UChartboostComponent::DidCloseMoreAppsDelegate.Broadcast(FString(location));
}

- (void)didClickMoreApps:(CBLocation)location {
	UChartboostComponent::DidClickMoreAppsDelegate.Broadcast(FString(location));
}

- (void)didFailToLoadMoreApps:(CBLocation)location withError:(CBLoadError)error {
	UChartboostComponent::DidFailToLoadMoreAppsDelegate.Broadcast(FString(location), (EChartboostLoadError::LoadError)error);
}

// rewarded videos

- (void)didPrefetchVideos {
	UChartboostComponent::DidPrefetchVideosDelegate.Broadcast();
}

- (void)didDisplayRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidDisplayRewardedVideoDelegate.Broadcast(FString(location));
}

- (void)didCacheRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidCacheRewardedVideoDelegate.Broadcast(FString(location));
}

- (void)didFailToLoadRewardedVideo:(CBLocation)location withError:(CBLoadError)error {
	UChartboostComponent::DidFailToLoadRewardedVideoDelegate.Broadcast(FString(location), (EChartboostLoadError::LoadError)error);
}

- (void)didDismissRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidDismissRewardedVideoDelegate.Broadcast(FString(location));
}

- (void)didCloseRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidCloseRewardedVideoDelegate.Broadcast(FString(location));
}

- (void)didClickRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidClickRewardedVideoDelegate.Broadcast(FString(location));
}

- (void)didCompleteRewardedVideo:(CBLocation)location withReward:(int)reward {
	UChartboostComponent::DidCompleteRewardedVideoDelegate.Broadcast(FString(location), reward);
}

- (void)willDisplayVideo:(CBLocation)location {
	UChartboostComponent::WillDisplayVideoDelegate.Broadcast(FString(location));
}

- (void)didCompleteAppStoreSheetFlow {
	UChartboostComponent::DidCompleteAppStoreSheetFlowDelegate.Broadcast();
}

- (void)didPauseClickForConfirmation {
	UChartboostComponent::DidPauseClickForConfirmationDelegate.Broadcast();
}

@end
#endif
