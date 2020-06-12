//
//  AMRBanner.h
//  AMRSDK
//
//  Created by Tolga Seremet on 23/08/16.
//  Copyright © 2016 Tolga Seremet. All rights reserved.
//

#import "AMRBannerView.h"
#import "AMRTypes.h"
#import "AMRSDK.h"

@interface AMRBanner : AMRAd

/// An object conforms to <AMRBannerDelegate> protocol.
@property (weak) id<AMRBannerDelegate> delegate;
/// A UIView to add as a subview to show banner.
@property AMRBannerView *bannerView;
/// A parent UIViewController required to catch taps.
@property UIViewController *viewController;
/// Width value of banner, default is 320px for 50px, 300px for 250px, 728px for 90px.
@property (nonatomic) CGFloat bannerWidth;
/// Custom size for custom native ads
@property (nonatomic) CGSize customNativeSize;
/// Custom native ad xib name
@property NSString *customeNativeXibName;
/// Custom native ad duration in seconds
@property (nonatomic, readonly) NSInteger customNativeDuration;

/**
 * Create an instance of AMRBanner to show in your application.
 * Example usage:
 * @code
 * [AMRBanner bannerForZoneId:@"<zoneId>"];
 * @endcode
 * @see https://admost.github.io/amrios for more information.
 * @param zoneId Your banner's zone ID displayed on AMR Dashboard.
 * @return An instance of AMRBanner created by zoneId provided.
 */
+ (instancetype)bannerForZoneId:(NSString *)zoneId;

/**
 * Start asynchronous banner loading request. Delegate must be set before loading a banner ad.
 * Example usage:
 * @code
 * [banner loadBanner];
 * @endcode
 */
- (void)loadBanner;

/**
 * Start synchronous banner loading request.
 * Example usage:
 * @code
 * [_banner50 loadWithReceiveHandler:^(AMRBanner *banner) {
 *     [self.view addSubview:banner.bannerView];
 * } failHandler:^(AMRError *error) {
 *     NSLog(@"Failed with error: %@", error.description);
 * }];
 * @endcode
 */
- (void)loadWithReceiveHandler:(void (^)(AMRBanner *banner))receive
                   failHandler:(void (^)(AMRError *error))fail;

// start caching banner
- (void)cacheBanner;

/**
* Trigger click action manually for custom native banners
*/
- (void)triggerCallToActionForCustomNativeBanner;

/**
* Play video ad manually for custom native banners
*/
- (void)playForCustomNativeBanner;

/**
* Pause video ad manually for custom native banners
*/
- (void)pauseForCustomNativeBanner;

@end
