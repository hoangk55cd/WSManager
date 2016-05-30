//
//  APIErrorProcessor.m
//  WSManager
//
//  Created by Huy Hoang  on 5/30/16.
//  Copyright © 2016 Huy Hoang . All rights reserved.
//

#import "APIErrorProcessor.h"
#import "APIBaseObject.h"
#import "AFNetworkReachabilityManager.h"

@implementation APIErrorProcessor

+ (APIErrorProcessor*)sharedInstance {
    static APIErrorProcessor *processor = nil;
    static dispatch_once_t oncePredicate;
    
    dispatch_once(&oncePredicate, ^{
        processor = [APIErrorProcessor new];
    });
    
    return processor;
}

- (BOOL)process:(id)error {
    // check if it's network problems
    if ([error isKindOfClass:[NSError class]]) {
        [self networkCheckError];
        return YES;
        
    }
    // if it's request problems: wrong params, ect.
    else if ([error isKindOfClass:[APIBaseObject class]]) {
        // show message
        
    }
    
    return NO;

}
- (void)networkCheckError {
    if (([AFNetworkReachabilityManager sharedManager].reachable == NO)) {
        // show error message
    }
}
@end
