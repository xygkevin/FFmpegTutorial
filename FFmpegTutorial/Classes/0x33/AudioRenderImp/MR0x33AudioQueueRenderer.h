//
//  MR0x33AudioQueueRenderer.h
//  FFmpegTutorial-macOS
//
//  Created by qianlongxu on 2021/9/26.
//  Copyright © 2021 Matt Reach's Awesome FFmpeg Tutotial. All rights reserved.
//

//Audio Queue Support packet fmt only!

#import <Foundation/Foundation.h>
#import "MR0x33AudioRendererImpProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface MR0x33AudioQueueRenderer : NSObject <MR0x33AudioRendererImpProtocol>

@end

NS_ASSUME_NONNULL_END
