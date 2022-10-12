//
//  FFTPlayer0x36.h
//  FFmpegTutorial
//
//  Created by qianlongxu on 2022/7/25.
//

#import <Foundation/Foundation.h>
#import "FFTPlayerHeader.h"
#import "FFTPlatform.h"
#import "FFTVideoRendererProtocol.h"

NS_ASSUME_NONNULL_BEGIN

//videoOpened info's key
typedef NSString * const kFFTPlayer0x36InfoKey;
//视频宽；单位像素
FOUNDATION_EXPORT kFFTPlayer0x36InfoKey kFFTPlayer0x36Width;
//视频高；单位像素
FOUNDATION_EXPORT kFFTPlayer0x36InfoKey kFFTPlayer0x36Height;
//视频时长；单位秒
FOUNDATION_EXPORT kFFTPlayer0x36InfoKey kFFTPlayer0x36Duration;

typedef struct AVFrame AVFrame;

@interface FFTPlayer0x36 : NSObject

///播放地址
@property (nonatomic, copy) NSString *contentPath;
///code is FFPlayerErrorCode enum.
@property (nonatomic, strong, nullable) NSError *error;
///记录读到的视频包总数
@property (atomic, assign, readonly) int videoPktCount;
///记录读到的音频包总数
@property (atomic, assign, readonly) int audioPktCount;
///记录解码后的视频桢总数
@property (atomic, assign, readonly) int videoFrameCount;
///记录解码后的音频桢总数
@property (atomic, assign, readonly) int audioFrameCount;
///获取媒体文件时长
@property (atomic, assign, readonly) float duration;
///获取音频播放进度
@property (atomic, assign, readonly) float audioPosition;
///获取视频播放进度
@property (atomic, assign, readonly) float videoPosition;

///记录解码后还没渲染的视频桢总数
@property (assign, readonly) int videoFrameQueueSize;
@property (assign, readonly) int audioFrameQueueSize;
@property (nonatomic, copy, readonly) NSString * audioRenderName;
@property (nonatomic, copy) NSString * videoPixelInfo;
@property (nonatomic, copy) NSString * audioSamplelInfo;

///指定输出的视频像素格式
@property (nonatomic, assign) MRPixelFormat supportedPixelFormat;
///指定输出的音频采样格式
@property (nonatomic, assign) MRSampleFormat supportedSampleFormat;
///期望的音频采样率，比如 44100;不指定时使用音频的采样率
@property (nonatomic, assign) int supportedSampleRate;

@property (nonatomic, copy) void(^onStreamOpened)(NSDictionary *info);
@property (nonatomic, copy) void(^onReadPkt)(int a,int v);
@property (nonatomic, copy) void(^onEnd)(NSError *);
//lazy getter
@property (nonatomic, strong, nullable) UIView<FFTVideoRendererProtocol> *videoRender;

//读包
- (void)load;
//停止读包
- (void)asyncStop;
//播放
- (void)play;
//暂停
- (void)pause;
//
- (BOOL)isPlaying;

@end

NS_ASSUME_NONNULL_END