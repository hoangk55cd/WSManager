//
//  APIErrorProcessor.h
//  WSManager
//
//  Created by Huy Hoang  on 5/30/16.
//  Copyright © 2016 Huy Hoang . All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APIErrorProcessor : NSObject


+ (APIErrorProcessor*)sharedInstance;

// check and process if has common errors
// Return: YES - has common error, NO = don't have common error
- (BOOL)process:(id)error;

@end
