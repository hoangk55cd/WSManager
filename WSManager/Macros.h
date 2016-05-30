//
//  Macros.h
//  HocVetApp
//
//  Created by Hung on 12/15/14.
//

#ifndef Translator_Macros_h
#define Translator_Macros_h

#ifdef DEBUG_MODE
#define DLog(level, f, ...)
#else
#define DLog(level, f, ...) [Logger writeLogWithLevel:level format:f, ## __VA_ARGS__]
#endif

#ifndef SAFE_RELEASE
#define	SAFE_RELEASE(ptr)	{if(ptr!=nil){if ([ptr respondsToSelector:@selector(setDelegate:)]) {[ptr performSelector:@selector(setDelegate:) withObject:nil];}[ptr release];ptr=nil;}}
#endif

#ifndef SAFE_CF_RELEASE
#define	SAFE_CF_RELEASE(ptr)	{if(ptr!=nil){CFRelease(ptr);ptr=nil;}}
#endif


#ifndef RGB
#define RGB(r, g, b)		[UIColor colorWithRed:(CGFloat)r/255.0 green:(CGFloat)g/255.0 blue:(CGFloat)b/255.0 alpha:1.0]
#endif

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]


#define BACKGROUND_COLOR RGB(235, 235, 235)

#define APP_DELEGATE [AppDelegate sharedInstance]
#define USER_DEFAULT_STANDARD [NSUserDefaults standardUserDefaults]

#define COLOR_CYAN      [UIColor colorWithRed:64.0f/255.0f green:128.0f/255.0f blue:0 alpha:1.0f]

// -----------------------------------------------------------------------------
// Detect device
#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_4_INCH_SCREEN ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )568 ) < DBL_EPSILON )
#define IS_3_5_INCH_SCREEN (IS_IPHONE && [[UIScreen mainScreen] bounds].size.height == 480.0f)
#define IS_RETINA ([[UIScreen mainScreen] scale] == 2.0f)
#define IS_PORTRAIT ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortrait|| [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortraitUpsideDown)

#define DEVICE_IS_IPOD ([[UIDevice currentDevice].model isEqualToString:@"iPod touch"])
#define DEVICE_IS_IPPHONE ([[UIDevice currentDevice].model isEqualToString:@"iPhone"])
#define DEVICE_IS_IPAD ([[UIDevice currentDevice].model isEqualToString:@"iPad"])

#define CORRECTED_IMG_FILE_NAME(image) (IS_4_INCH_SCREEN ? [NSString stringWithFormat:@"%@-568h.%@", [image stringByDeletingPathExtension], [image pathExtension]] : image)
#define CORRECTED_IMG_NAMED(image) ([UIImage imageNamed:CORRECTED_IMG_FILE_NAME(image)])

// -----------------------------------------------------------------------------

#define CUSTOM_NAVIGATION ((CustomNavigationController*)self.navigationController)

#define MESSAGE_NOT_EMPTY(message) (message.length > 0 ? 1 : 0)
#define IS_OS_7_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)
#define IS_OS_8_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
#define IS_OS_9_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)


#define SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

#define IS_IPHONE_4_OR_LESS (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)
#define IS_IPHONE_5 (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)
#define IS_IPHONE_6 (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_6_PLUS (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)


#ifndef APP_FRAME_WIDTH
#define APP_FRAME_WIDTH (UIInterfaceOrientationIsPortrait([UIApplication sharedApplication].statusBarOrientation) ? \
CGRectGetWidth([UIScreen mainScreen].applicationFrame) : \
CGRectGetHeight([UIScreen mainScreen].applicationFrame))
#endif

#ifndef APP_FRAME_HEIGHT
#define APP_FRAME_HEIGHT (UIInterfaceOrientationIsPortrait([UIApplication sharedApplication].statusBarOrientation) ? \
CGRectGetHeight([UIScreen mainScreen].applicationFrame) : \
CGRectGetWidth([UIScreen mainScreen].applicationFrame))
#endif

#define SAFE_PERFORM_SELECTOR(target,selector) {if(target!=nil&&selector!=nil&&[target respondsToSelector:selector]){[target performSelector:selector];}}
#define SAFE_PERFORM_SELECTOR_WITH_OBJECT(target,selector,obj) {if(target!=nil&&selector!=nil&&[target respondsToSelector:selector]){[target performSelector:selector withObject:obj];}}
#define SAFE_PERFORM_SELECTOR_WITH_2OBJECT(target,selector,obj1,obj2) {if(target!=nil&&selector!=nil&&[target respondsToSelector:selector]){[target performSelector:selector withObject:obj1 withObject:obj2];}}



#endif
